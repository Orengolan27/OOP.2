

#ifndef OOP_PROJ2_MATRIXCONTAINER_H
#include <iostream>
#include "Matrix.h"

using std::string;
using std::cout;
using std::endl;
using std::ostream;

template<int row, int col, typename T = int >
class MatrixContainer {
private:
    int conLimit;
    int conSize;
    Matrix<row, col, T>* data;


public:
    ///--------------C'tors--------------///
    MatrixContainer() : conLimit(1), conSize(0), data(new Matrix<row, col, T>[1]){
    }
    ~MatrixContainer() = default;

    MatrixContainer(const MatrixContainer<row, col, T>& container){
        conLimit = container.conLimit;
        conSize = container.conSize;
        for (int i = 0; i < conSize; ++i) {
            data[i] = container[i];
        }
    }

    ///--------------erase function--------------///
    void erase(){
        delete[] data;
    }

    ///--------------size getter--------------///
    int size(){
        return conSize;
    }
    int limit(){
        return conLimit;
    }


    ///-------------conSize and conLimit printer--------------///
    void printconSizeconLimit(){
        cout<<"The metrics conSize in the container is: >> "<<conSize<<endl;
        cout<<"The container conLimit is: >> "<<conLimit<<endl;
    }

    ///--------------[] operator--------------///
    MatrixContainer<row, col, T> operator[](int index){
        if (index < 0 || index >= conLimit){
            return "ERROR";
        }
        return data[index];
    }

    ///--------------<< operator--------------///
    friend std::ostream& operator<<(std::ostream& out, const MatrixContainer<row, col, T>& container) {
        cout<<"There are "<<container.conSize<<" matrices in the container. The matrices:"<<endl;
        for(int i=0;i<container.conSize;i++){
            out << container.data[i] << std::endl;
        }
        return out;
    }

    ///--------------resize container--------------///
    void resizeBigger(){
        Matrix<row, col>* newData{ new Matrix<row, col>[(conLimit*2)] };
        for(int index=0;index<conSize;index++){
            newData[index] = data[index];
        }
        this->erase();
        data = newData;
        conLimit *= 2;
    }

    void resizeSmaller(){
        Matrix<row, col>* newData{ new Matrix<row, col>[(conLimit/2)] };
        for(int index=0;index<(conSize-1);index++){
            newData[index] = data[index];
        }
        this->erase();
        data = newData;
        conLimit /= 2;
    }

    ///--------------add matrix to the list--------------///
    void addMatrix(Matrix<row, col, T>& matrix) {
        if(conSize == conLimit){
            this->resizeBigger();
        }
        data[conSize] = matrix;
        conSize++;
    }

    ///--------------remove last matrix from list--------------///
    void removeLastMatrix() {
        if(conLimit !=1 && conSize-1 == conLimit/2){
            this->resizeSmaller();
        }
        else{
            Matrix<row, col>* newData{ new Matrix<row, col>[conLimit] };
            for(int index{0};index<conSize-1;index++){
                newData[index] = data[index];
            }
            this->erase();
            data = newData;
        }
        conSize--;
    }

    ///--------------index functions - summary and multiply--------------///
    Matrix<row, col, T> addMatricesAtIndexes(int i1, int i2){
        return (data[i1] + data[i2]);

    }
    Matrix<row, col, T> mulMatAtIndexByScalar(int index, int scalar){
        return (data[index] * scalar);

    }
};


#endif
