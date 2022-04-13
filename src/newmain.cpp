#include "MatrixContainer.h"

template <int row, int col, typename T>
void printDiag(Matrix<row, col, T>& mat) {
    int number;
    T* diag = mat.getDiag(number);
    for (int i = 0; i < number; i++)
    {
        std::cout << diag[i] << " ";
    }
    std::cout << std::endl;
    delete[] diag;
}

int main(){
    //freopen("MY_OUTPUT_matrix.txt", "w", stdout);

    //operators : + ,- ,* (in the left and in the right) , trace
    Matrix<3,3> mat1;
    mat1 = mat1.getIdentityMatrix()+2;
    Matrix<3,3> mat2 = -mat1 + 3*int(mat1) - mat1 +3* ( mat1 - int(mat1) )* 2 + mat1(1,1) * mat1;
    std::cout << mat2 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    //  postfix / prefix
    mat1 = mat1.getIdentityMatrix();
    Matrix<3,3> mat3 = ++mat1;
    std::cout << mat3 << std::endl;
    mat3 = mat1++;
    std::cout << mat1 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    //operators "==" and "!="
    if (mat2 != mat1)
        std::cout << "perfect !!" << std::endl;
    else
        std::cout << "there are a error any were" << std::endl;

    if (mat1 == mat2)
        std::cout << "there are a error any were" << std::endl;
    else
        std::cout << "perfect!!" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    //print the diag
    std::cout <<"the mat1 :" <<"\n" <<  mat1;
    std::cout << "the diag of mat1 :" << std::endl;
    printDiag(mat1);
    std::cout << "\n";

    mat2(1,1)= 100;
    std::cout <<"the mat2 :" <<"\n" <<  mat2;
    std::cout << "the diag of mat2 :" << std::endl;
    printDiag(mat2);
    std::cout << "\n";

    std::cout <<"the mat3 :" <<"\n" <<  mat3 ;
    std::cout << "the diag of mat3 :" << std::endl;
    printDiag(mat3);
    std::cout << "\n";
/**********************************************************************************************************************/

    MatrixContainer<3,3> my_container;
    std::cout << "empty container" << std::endl;
    std::cout << "the amount of the container is : " << my_container.size() << " , and the size is : " <<  my_container.limit() << std::endl << std::endl;
    std::cout << "We Adding .." << std::endl;
    my_container.addMatrix(mat1);
    std::cout << "the amount of the container is : " << my_container.size() << " , and the size is : " <<  my_container.limit() << std::endl << std::endl;
    std::cout << "We Adding .." << std::endl;
    my_container.addMatrix(mat2);
    std::cout << "the amount of the container is : " << my_container.size() << " , and the size is : " <<  my_container.limit() << std::endl << std::endl;
    std::cout << "We Remove .." << std::endl;
    my_container.removeLastMatrix();
    std::cout << "the amount of the container is : " << my_container.size() << " , and the size is : " <<  my_container.limit() << std::endl << std::endl;
    std::cout << "We Remove .." << std::endl;
    my_container.removeLastMatrix();
    std::cout << "the amount of the container is : " << my_container.size() << " , and the size is : " <<  my_container.limit() << std::endl << std::endl;
    std::cout << std::endl <<std::endl;

    ///////////////////////////////
    my_container.addMatrix(mat1);
    my_container.addMatrix(mat2);
    my_container.addMatrix(mat3);

    Matrix<3,3> mat4(1);
    Matrix<3,3> mat5 = my_container.mulMatAtIndexByScalar(0,2) * 3 + mat4;
    my_container.addMatrix(mat5);
    my_container.addMatrix(mat4);
    my_container.addMatrix(mat1);
    my_container.addMatrix(mat2);
    my_container.addMatrix(mat3);
    std::cout << "the amount of the container is : " << my_container.size() << " , and the size is : " <<  my_container.limit() << std::endl;
    std::cout << my_container << std::endl;

    Matrix<3,3> mat6 = my_container.addMatricesAtIndexes(3,6);
    my_container.removeLastMatrix();
    my_container.removeLastMatrix();
    my_container.removeLastMatrix();
    my_container.removeLastMatrix();
    my_container.removeLastMatrix();

    my_container.addMatrix(mat6);

    std::cout << "the amount of the container is : " << my_container.size() << " , and the size is : " <<  my_container.limit() << std::endl;
    std::cout << my_container << std::endl;


/************************************************ - BONUS 5 POINTS -***************************************************/
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout<< "BONUS 5 POINTS " << std::endl;

    mat1(0,0) = 1;
    mat1(0,1) = 2;
    mat1(0,2) = 3;
    mat1(1,0) = 4;
    mat1(1,1) = 2;
    mat1(1,2) = 1;
    mat1(2,0) = 7;
    mat1(2,1) = 1;
    mat1(2,2) = 2;

    mat2(0,0) = 1;
    mat2(0,1) = 5;
    mat2(0,2) = 6;
    mat2(1,0) = 3;
    mat2(1,1) = 2;
    mat2(1,2) = 1;
    mat2(2,0) = 4;
    mat2(2,1) = 4;
    mat2(2,2) = 1;

    std::cout << "matrix 1 : " << "\n" << mat1 << " * " << "\n" << "matrix 2 : " << "\n" << mat2 << "\n" << "equal to :" << std::endl;
    mat3 = mat1 * mat2;
    std::cout << mat3 <<std::endl;
}