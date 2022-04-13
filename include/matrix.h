#include <string>
#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H
#define DBL_EPSILON 0.001



using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::min;


template <int row, int col, typename T = int> //class template get row,col,and T default as int//
class Matrix {
private:

    int newRow;    // new rows of the matrixptr//
    int newCol;    // new cols of the matrixptr//
    T** matrixptr; //pointer to matrix with T type//


public:
    ///////////////// constructor /////////////////
    explicit Matrix(T value = 0) : newRow(row), newCol(col) {

        matrixptr = new T*[newRow]; //allocate the new matrix//
        for (int i = 0; i < newRow; ++i)
            matrixptr[i] = new T[newCol];

        for (int i = 0; i < newRow; ++i) {
            for (int j = 0; j < newCol; ++j)
                matrixptr[i][j] = value; // initial the value of the matrix//
        }
    }
    ///////////////// copy constructor /////////////////
    Matrix(const Matrix<row, col, T>& other) : newRow(row), newCol(col) {

        matrixptr = new T*[newRow];		// allocating the new matrix//
        for (int i = 0; i < newRow; ++i)
            matrixptr[i] = new T[newCol];

        for (int i = 0; i < newRow; ++i) {
            for (int j = 0; j < newCol; ++j)
                this->matrixptr[i][j] = other.matrixptr[i][j];
        }
    }

    ///////////////// distructor /////////////////
    ~Matrix() {

        for (int i = 0; i < newRow; ++i)
            delete[]matrixptr[i];
        delete[]matrixptr;
    }

    ///////////////// operator + /////////////////
    //operator matrix + matrix//
    Matrix<row, col, T> operator+(const Matrix<row, col, T>& matrix) const {

        Matrix<row, col, T> result=*this;
        for (int i = 0; i < newRow; ++i)
            for (int j = 0; j < newCol; ++j)
                result.matrixptr[i][j] = this->matrixptr[i][j] + matrix.matrixptr[i][j];
        return result;
    }
    //operator matrix + scalar//
    Matrix<row, col, T>  operator+(T scalar) const {

        Matrix<row, col, T> result=*this;
        for (int i = 0; i < newRow; ++i)
            for (int j = 0; j < newCol; ++j)
                result.matrixptr[i][j] += scalar;
        return result;
    }
    //operator scalar + matrix//
    friend Matrix<row, col, T> operator+(T scalar, const Matrix<row, col, T>& matrix) {

        return matrix+scalar;
    }

    ///////////////// operator - /////////////////
    //operator matrix - matrix//
    Matrix<row, col, T> operator-(const Matrix<row, col, T>& matrix) const {
        Matrix<row, col, T> result=*this;
        for (int i = 0; i < newRow; ++i)
            for (int j = 0; j < newCol; ++j)
                result.matrixptr[i][j] -= matrix.matrixptr[i][j];
        return result;
    }
    //operator matrix - scalar//
    Matrix<row, col, T> operator-(T scalar) const {
        Matrix<row, col, T> result=*this;
        for (int i = 0; i < newRow; ++i)
            for (int j = 0; j < newCol; ++j)
                result.matrixptr[i][j] -= scalar;
        return result;
    }
    //operator scalar - matrix//
    friend Matrix<row, col, T> operator-(T scalar, const Matrix<row, col, T>& matrix) {
        return (matrix - scalar)*(-1);
    }
    //operator matrix = - matrix //
    friend Matrix<row, col, T> operator-(const Matrix<row, col, T>& matrix) {

        return matrix * (-1);
    }

    ///////////////// operator * /////////////////
    //operator matrix * scalar//
    Matrix<row, col, T> operator*(T scalar) const {
        Matrix<row, col, T> result=*this;
        for (int i = 0; i < newRow; ++i)
            for (int j = 0; j < newCol; ++j)
                result.matrixptr[i][j] *= scalar;
        return result;
    }
    //operator scalar * matrix//
    friend Matrix<row,col,T> operator*(T scalar , Matrix<row,col,T> matrix) {
        return matrix*scalar;
    }

    ///operator matrix * matrix - bonus ///
    friend Matrix<row,col,T> operator*(const Matrix<row,col,T>& matrix1,const Matrix<row,col,T>& matrix2 )
    {
        Matrix<row, col, T> result;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                for(int k=0;k<col;k++)
                {
                    result.matrixptr[i][j]+= matrix1.matrixptr[i][k] * matrix2.matrixptr[k][j];
                }
            }
        }
        return result;
    }

    Matrix<row,col,T> getIdentityMatrix() // get the identity of T type matrix //
    {
        int num = min(row,col);
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
            {
                i==j? this->matrixptr[i][j]=1 : this->matrixptr[i][j]=0;
            }
        }
        return *this;
    }

    ///////////////// operator ++ /////////////////
    //operator ++ postfix -> T++//
    const Matrix<row, col, T> operator++(int) {

        Matrix<row, col, T> result=*this;
        (*this) = (*this) + 1;
        return result;
    }

    //operator ++ prefix -> ++T//
    Matrix<row, col, T>& operator++() {

        (*this) = (*this) + 1;
        return (*this);
    }
    ///////////////// operator -- /////////////////

    //operator -- postfix -> T--//
    const Matrix<row, col, T> operator--(int) {

        Matrix<row, col, T> result=*this;
        (*this) = (*this) - 1;
        return result;
    }

    //operator -- prefix -> --T//
    const Matrix<row, col, T>& operator--() {

        (*this) = (*this) - 1;
        return (*this);
    }

    T* getDiag(int& num) { // get array of the matrix diag //

        num = min(row,col);
        T* diag = new T[num];
        for (int i = 0; i < num; ++i)
            diag[i] = matrixptr[i][i];
        return diag;
    }
    ///////////////// operator == /////////////////
    bool operator ==(const Matrix<row,col,T>& matrix)
    {
        if((newRow!= row) || (newCol!= col))
        {
            return false;
        }
        for(int i=0;i<newRow;i++)
        {
            for(int j=0;j<newCol;j++)
            {
                if(this->matrixptr[i][j] >= matrix.matrixptr[i][j])
                {
                    if((this->matrixptr[i][j] - matrix.matrixptr[i][j]) >= DBL_EPSILON)
                    {
                        return false;
                    }
                }
                else
                {
                    if((matrix.matrixptr[i][j] - this->matrixptr[i][j]) >= DBL_EPSILON)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    ///////////////// operator != /////////////////
    bool operator !=(const Matrix<row,col,T>& matrix)
    {
        return !(*this == matrix);
    }

    explicit operator T() const //type conversion for the trace of the matrix//
    {
        int num=min(row,col);
        T sum=0;
        for(int i=0;i<num;i++)
        {
            sum+=matrixptr[i][i];
        }
        return sum;
    }

    //operator = //
    Matrix<row, col, T>& operator = (const Matrix<row, col, T>& matrix) {

        for (int i = 0; i < newRow; ++i)
            for (int j = 0; j < newCol; ++j)
                this->matrixptr[i][j] = matrix.matrixptr[i][j];
        return *this;
    }

    //__attribute__((unused)) T trace() {
    //
    //    int number;
    //    T sum = 0;
    //    T* diag = this->getDiag(number);
    //    for (int i = 0; i < number; ++i) {
    //        sum += diag[i];
    //    }
    //    delete[] diag;
    //    return sum;
    //}

    // operator << for print //
    friend ostream& operator<<(ostream& output, const Matrix<row, col, T>& matrix) {

        for (int i = 0; i < matrix.newRow; ++i) {
            for (int j = 0; j < matrix.newCol; ++j)
                cout << matrix.matrixptr[i][j] << " ";
            cout << endl;
        }
        return output;
    }

    //operator () - return reference to cell [i][j]//
    T& operator()(int i, int j) {

        return this->matrixptr[i][j];
    }

};

#endif //MATRIX_H
