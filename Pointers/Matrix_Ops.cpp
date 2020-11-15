#include <iostream>
#include <cmath>
using namespace std;

int** InputMatrix(int** Matrix, int rows, int cols, char name){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<"Enter Element "<<name<<"["<<i<<"]["<<j<<"]: ";
            cin>>Matrix[i][j];
        }
    }
    cout<<"\n"<<endl;
    return Matrix;
}

void OutputMatrix(int** Matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<Matrix[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n"<<endl;
}

void OutputFloatMatrix(float** Matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<Matrix[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n"<<endl;
}

int** CreateMatrix(int rows, int cols){
    //Creating Array of pointers
    int** Matrix = new int *[rows];
    //Creating columns in Dynamoc memmory i.e assigning each column to each pointer
    for(int i=0; i<rows; i++){
        Matrix[i] = new int[cols];
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            Matrix[i][j] = 0;
        }
    }
    return Matrix;
}

float** CreateFloatMatrix(int rows, int cols){
    //Creating Array of pointers
    float** Matrix = new float *[rows];
    //Creating columns in Dynamoc memmory i.e assigning each column to each pointer
    for(int i=0; i<rows; i++){
        Matrix[i] = new float[cols];
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            Matrix[i][j] = 0;
        }
    }
    return Matrix;
}

//Problem 3.1: Matrix Multiplication
int** MatrixMul(int** MatrixA, int rowsA, int colsA, int** MatrixB, int rowsB, int colsB){
    if(colsA!=rowsB){
        cout<<"\nCannot perform Matrix multiplication, Invalid shape of given matrcies!"<<endl;
        cout<<"For matrix multiplication number of columns in 1st Matrix must be equal to number of rows in 2nd Matrix."<<endl;
        cout<<"Exit!!!\n"<<endl;
        exit(0);
    }
    int** product = CreateMatrix(rowsA, colsB);
    for(int i=0; i<rowsA; i++){
        for(int j=0; j<colsB; j++){
            for(int k=0; k<colsA; k++){
                product[i][j] += MatrixA[i][k]*MatrixB[k][j];
            }
        }

    }
    return product;
}

//Problem 3.2: Matrix Addition
int** MatrixAdd(int** MatrixA, int rowsA, int colsA, int** MatrixB, int rowsB, int colsB){
    if(rowsA!=rowsB || colsA!=colsB){
        cout<<"\nCannot perform Matrix Addition, Invalid shape of given matrcies!"<<endl;
        cout<<"For matrix addition the dimensions of both matrcies must be same."<<endl;
        cout<<"Exit!!!\n"<<endl;
        exit(0);
    }
    int** sum = CreateMatrix(rowsA, colsA);
    for(int i=0; i<rowsA; i++){
        for(int j=0; j<colsB; j++){
            sum[i][j] = MatrixA[i][j] + MatrixB[i][j];  
        }
    }
    return sum;
}

//Problem 3.3: Matrix Subtraction
int** MatrixSub(int** MatrixA, int rowsA, int colsA, int** MatrixB, int rowsB, int colsB){
    if(rowsA!=rowsB || colsA!=colsB){
        cout<<"\nCannot perform Matrix Subtraction, Invalid shape of given matrcies!"<<endl;
        cout<<"For matrix subtraction the dimensions of both matrcies must be same."<<endl;
        cout<<"Exit!!!\n"<<endl;
        exit(0);
    }
    int** sub = CreateMatrix(rowsA, colsA);
    for(int i=0; i<rowsA; i++){
        for(int j=0; j<colsB; j++){
            sub[i][j] = MatrixA[i][j] - MatrixB[i][j];  
        }
    }
    return sub;
}

//Problem 3.4: Matrix Transpose
int** MatrixTranspose(int** Matrix, int rows, int cols){
    int** t = CreateMatrix(cols, rows);
    for(int i=0; i<cols; i++){
        for(int j=0; j<rows; j++){
            t[i][j] = Matrix[j][i];
        }
    }
    return t;
}

//Problem 3.5: Matrix Rotate 90 degree.
int** MatrixRotate(int** Matrix, int rows, int cols){
    int** rot = CreateMatrix(cols, rows);
    int k = cols-1;
    for(int i=0; i<cols; i++){
        for(int j=0; j<rows; j++){
            rot[i][j] = Matrix[k-j][i];
        }
    }
    return rot;
}

//Problem 3.6: Matrix Determinant
int MatrixDet(int** Matrix, int rows, int cols, int itr){
    /*int prod = 0;
    //The following loop will calculate how many DynamicArrays will be created during recursion
    for(int i=3; i<=rows; i++)
        prod *= i;
    //This triple pointer array will store double pointer arrays generated during recursion, so that we can delete them after.
    int*** t_pointer = new int** [prod];
    //creating array pointer that will keep count of number of rows for each generated double pointer during recursion.
    int* n_rows = new int [prod]; */

    int det = 0;
    if(rows!=cols){
        cout<<"\nCannot compute Determinant of non-square matrix!"<<endl;
        cout<<"Exit!!!\n"<<endl;
        exit(0);
    }
    else{
        if(rows==2){
            det = Matrix[0][0]*Matrix[1][1] - Matrix[1][0]*Matrix[0][1];
            return det;
        }
        else{
            for(int i=0; i<cols; i++){
                int** arr = CreateMatrix(rows-1, cols-1);
                //t_pointer[]
                //cout<<itr;
                //itr = itr+1;
                
                for(int j=1; j<rows; j++){
                    int l=0;
                    for(int k=0; k<rows; k++){
                        if(k==i){
                            continue;
                        }
                        else{
                            arr[j-1][l] = Matrix[j][k];
                            l++;
                        }
                    }
                }
                //OutputMatrix(arr, rows-1, cols-1);
                det += pow(-1, i)*Matrix[0][i]*MatrixDet(arr, rows-1, cols-1, itr);
            }
        }
    }
    return det;
}

//Problem 3.7: Matrix Inverse
float** MatrixInverse(int** Matrix, int rows, int cols){
    float** inv = CreateFloatMatrix(rows, cols);
    int** cofactor_mat = CreateMatrix(rows, cols);
    int det = MatrixDet(Matrix, rows, cols, 0);
    cout<<"\nDeterminant of Given Matrix: "<<det<<endl;
    if(rows!=cols || det==0){
        cout<<"\nCannot compute Inverse of non-square matrix or the matrix which has 0 Determinant!"<<endl;
        cout<<"Exit!!!\n"<<endl;
        exit(0);
    }
    else{
        //The following 3 loops extract the cofactor matrixes i.e a11, a12 a13, a21, a22, a23, a31, a32, a33. 
        for(int h=0; h<rows; h++){
            for(int i=0; i<cols; i++){
                int** arr = CreateMatrix(rows-1, cols-1);
                int m=0;
                for(int j=0; j<rows; j++){
                    int l=0;
                    if(j==h){
                        continue;
                    }
                    else{
                        for(int k=0; k<rows; k++){
                            if(k==i){
                                continue;
                            }
                            else{
                                arr[m][l] = Matrix[j][k];
                                l++;
                            }
                        }
                        m++;
                    }
                }
                //computing cofactors
                int cofactor = pow(-1, (h+1)+(i+1))*MatrixDet(arr, rows-1, cols-1, 0);
                //converting integer to float
                float cofactor1 = (float) cofactor;
                //computing cofactor matrix i.e the matrix that have the value of cofactors.
                cofactor_mat[h][i] = cofactor1;
                //computing inverse by dividing each cofactor by the detereminant of matrix. Column index has been given to Row index & Row index 
                //has been given to Columns because Inverse is computed by taking Transpose of Cofactor Matrix and then dividing ny Determinant.
                inv[i][h] = cofactor1/det;
            }
        }
    }
    int** adjoint = MatrixTranspose(cofactor_mat, rows, cols);
    cout<<"Adjoint of Given Matrix: "<<endl;
    OutputMatrix(adjoint, rows, cols);
    delete adjoint;
    delete cofactor_mat;
    return inv;
}

int* get_inputs(char ch){
    int* arr = new int[4];
    if(ch=='A' || ch=='a'){
        cout<<"Enter the rows of Matrix A:";
        cin>>arr[0];
        cout<<"Enter the colums of matrix A: ";
        cin>>arr[1];
        cout<<"\n"<<endl;
    }
    else if(ch=='B' || ch=='b'){
        cout<<"Enter the rows of Matrix A:";
        cin>>arr[0];
        cout<<"Enter the colums of matrix A: ";
        cin>>arr[1];
        cout<<"Enter the rows of Matrix B: ";
        cin>>arr[2];
        cout<<"Enter the colums of Matrix B: ";
        cin>>arr[3];
        cout<<"\n"<<endl;
    }
    return arr;
}

void DelDoublePtrI(int** arr, int rows){
    //This function deletes the integer type double pointer.
    for(int i=0; i<rows; i++){
        delete[] arr[i];
        //Specifying Null value to the pointer because delete, only deltes the memory to which the pointer points.
        //Assign NULL will remove the address from the pointer variable as well;
        arr[i] = NULL;
    }
    arr = NULL;
}

void DelDoublePtrF(float** arr, int rows){
    //This function deletes the float type double pointer.
    for(int i=0; i<rows; i++){
        delete[] arr[i];
        //Specifying Null value to the pointer because delete, only deltes the memory to which the pointer points.
        //Assign NULL will remove the address from the pointer variable as well;
        arr[i] = NULL;
    }
    arr = NULL;
}

int main(){
    int ch;
    int rowsA, colsA, rowsB, colsB;
    int* arr;
    while(1){
        
        cout<<"\t\n1. Matrix Multiplication."<<endl;
        cout<<"\t2. Matrix Addition."<<endl;
        cout<<"\t3. Matrix Subtraction."<<endl;
        cout<<"\t4. Matrix Transpose."<<endl;
        cout<<"\t5. Matrix Rotation."<<endl;
        cout<<"\t6. Matrix Determinant."<<endl;
        cout<<"\t7. Matrix Inverse."<<endl;
        cout<<"\t0. To Exit"<<endl;
        cout<<"\nEnter Your Choice: ";
        cin>>ch;
        cout<<"__________________________________________________________\n"<<endl;
        //Matrix Multiplication
        if(ch==1){
            //Getting input for number of rows and columns.
            arr = get_inputs('B');
            rowsA=*(arr+0); colsA=*(arr+1); rowsB=*(arr+2); colsB=*(arr+3);
            //Creating Matrix A in Heap i.e DMA
            int** MatrixA = CreateMatrix(rowsA, colsA);
            MatrixA = InputMatrix(MatrixA, rowsA, colsA, 'A');
            //Creating Matrix B in Heap i.e DMA
            int** MatrixB = CreateMatrix(rowsA, colsA);
            MatrixB = InputMatrix(MatrixB, rowsB, colsB, 'B');
            //Matrix Multiplication
            int** product = MatrixMul(MatrixA, rowsA, colsA, MatrixB, rowsB, colsB);
            cout<<"\nMatrix Multiplication!"<<endl;
            //Displaying Results
            OutputMatrix(product, rowsA, colsB);
            //Deleting the pointers, to free up the memory.
            delete[] arr;
            DelDoublePtrI(MatrixA, rowsA);
            DelDoublePtrI(MatrixB, rowsB);
            DelDoublePtrI(product, rowsA);
        }
        //Matrix Addition
        else if (ch==2)
        {
            //Getting input for number of rows and columns.
            arr = get_inputs('B');
            rowsA=*(arr+0); colsA=*(arr+1); rowsB=*(arr+2); colsB=*(arr+3);
            //Creating Matrix A in Heap i.e DMA
            int** MatrixA = CreateMatrix(rowsA, colsA);
            MatrixA = InputMatrix(MatrixA, rowsA, colsA, 'A');
            //Creating Matrix B in Heap i.e DMA
            int** MatrixB = CreateMatrix(rowsA, colsA);
            MatrixB = InputMatrix(MatrixB, rowsB, colsB, 'B');
            //Matrix Addition
            int** sum = MatrixAdd(MatrixA, rowsA, colsA, MatrixB, rowsB, colsB);
            cout<<"\nMatrix Addition!"<<endl;
            //Displaying Results
            OutputMatrix(sum, rowsA, colsA);
            //Deleting the pointers, to free up the memory.
            delete[] arr;
            DelDoublePtrI(MatrixA, rowsA);
            DelDoublePtrI(MatrixB, rowsB);
            DelDoublePtrI(sum, rowsA);
        }
        //Matrix Subtraction
        else if (ch==3)
        {
            //Getting input for number of rows and columns.
            arr = get_inputs('B');
            rowsA=*(arr+0); colsA=*(arr+1); rowsB=*(arr+2); colsB=*(arr+3);
            //Creating Matrix A in Heap i.e DMA
            int** MatrixA = CreateMatrix(rowsA, colsA);
            MatrixA = InputMatrix(MatrixA, rowsA, colsA, 'A');
            //Creating Matrix B in Heap i.e DMA
            int** MatrixB = CreateMatrix(rowsA, colsA);
            MatrixB = InputMatrix(MatrixB, rowsB, colsB, 'B');
            //Matrix Subtraction
            int** sub = MatrixSub(MatrixA, rowsA, colsA, MatrixB, rowsB, colsB);
            cout<<"\nMatrix Subtraction!"<<endl;
            OutputMatrix(sub, rowsA, colsA);
            //Deleting the pointers, to free up the memory.
            delete[] arr;
            DelDoublePtrI(MatrixA, rowsA);
            DelDoublePtrI(MatrixB, rowsB);
            DelDoublePtrI(sub, rowsA);
        }
        //Matrix Transpose
        else if (ch==4)
        {
            //Getting input for number of rows and columns.
            arr = get_inputs('A');
            rowsA=*(arr+0); colsA=*(arr+1);
            //Creating Matrix A in Heap i.e DMA
            int** MatrixA = CreateMatrix(rowsA, colsA);
            MatrixA = InputMatrix(MatrixA, rowsA, colsA, 'A');
            //Matrix Transpose
            int** t = MatrixTranspose(MatrixA, rowsA, colsA);
            cout<<"\nMatrix Transpose!"<<endl;
            OutputMatrix(t, colsA, rowsA);
            //Deleting the pointers, to free up the memory.
            delete[] arr;
            DelDoublePtrI(MatrixA, rowsA);
            DelDoublePtrI(t, rowsA);
        }
        //Matrix Rotate
        else if (ch==5)
        {
            //Getting input for number of rows and columns.
            arr = get_inputs('A');
            rowsA=*(arr+0); colsA=*(arr+1);
            //Creating Matrix A in Heap i.e DMA
            int** MatrixA = CreateMatrix(rowsA, colsA);
            MatrixA = InputMatrix(MatrixA, rowsA, colsA, 'A');
            //Matrix Rotate
            int** rot = MatrixRotate(MatrixA, rowsA, colsA);
            cout<<"\nMatrix Rotate!"<<endl;
            OutputMatrix(rot, rowsA, colsA);
            //Deleting the pointers, to free up the memory.
            delete[] arr;
            DelDoublePtrI(MatrixA, rowsA);
            DelDoublePtrI(rot, rowsA);
        }
        else if (ch==6)
        {
            //Getting input for number of rows and columns.
            arr = get_inputs('A');
            rowsA=*(arr+0); colsA=*(arr+1);
            //Creating Matrix A in Heap i.e DMA
            int** MatrixA = CreateMatrix(rowsA, colsA);
            MatrixA = InputMatrix(MatrixA, rowsA, colsA, 'A');
            //Determinant of NxN matrix 
            int det = MatrixDet(MatrixA, rowsA, colsA, 0);
            cout<<"\nDeterminant of Given Matrix"<<endl;
            OutputMatrix(MatrixA, rowsA, colsA);
            cout<<"\nDeterminant: "<<det<<endl;
            //Deleting the pointers, to free up the memory.
            delete[] arr;
            DelDoublePtrI(MatrixA, rowsA);
        }
        //Inverse of NxN matrix
        else if (ch==7)
        {
            //Getting input for number of rows and columns.
            arr = get_inputs('A');
            rowsA=*(arr+0); colsA=*(arr+1);
            //Creating Matrix A in Heap i.e DMA
            int** MatrixA = CreateMatrix(rowsA, colsA);
            MatrixA = InputMatrix(MatrixA, rowsA, colsA, 'A');
            //Inverse of NxN matrix
            cout<<"Inverse of Given Matrix"<<endl;
            OutputMatrix(MatrixA, rowsA, colsA);
            float** inv = MatrixInverse(MatrixA, rowsA, colsA);
            cout<<"Inverse: "<<endl;
            OutputFloatMatrix(inv, rowsA, colsA);
            //Deleting the pointers, to free up the memory.
            delete[] arr;
            DelDoublePtrI(MatrixA, rowsA);
            DelDoublePtrF(inv, rowsA);
        }
        
        else if (ch==0)
        {
            exit(0);
        }
        else{
            int ret = main();
        }
        cout<<"__________________________________________________________\n"<<endl;
        
    }
    return 0;
}