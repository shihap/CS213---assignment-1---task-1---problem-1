// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 1
// Program: CS213-2018-A1-T1-P1
// Purpose: create matrices and do operations on them
// Author:  shihap ahmed mohamed(20170129),tarek alaa metwaliy(20170134),abd elrahmaan shaker(20170152)
// Date:    17 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int* data;       // Pointer to 1-D array that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 4) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);//
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose


int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8};
  int data2 [] = {1,2,3,4,5,6};
  int data3 [] = {10,100,10,100,10,100,10,100};
  int data4 [] = {1,2};
  int data5 [] = {3,4,5,6};
  int data6 [] = {1,0,0,0,1,0,0,0,1};
  matrix mat1, mat2, mat3, mat4, mat5, mat6;
  createMatrix (4, 2, data1, mat1);
  createMatrix (2, 3, data2, mat2);
  createMatrix (4, 2, data3, mat3);
  createMatrix (1, 2, data4, mat4);
  createMatrix (2, 2, data5, mat5);
  createMatrix (3, 3, data6, mat6);

  return 0;
}

void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int [row * col];
  for (int i = 0; i < row * col; i++)
    mat.data [i] = num [i];
}

matrix operator+  (matrix mat1, matrix mat2){
  assert((mat1.row==mat2.row)&&(mat1.col==mat2.col));
  matrix mat0 ;
  mat0.row = mat1.row ;
  mat0.col = mat1.col ;
  mat0.data = new int [mat1.row * mat1.col];
  for (int i = 0; i < mat1.row * mat1.col; i++)
    mat0.data[i] = mat1.data[i]+mat2.data[i];
  return mat0 ;
}

matrix operator-  (matrix mat1, matrix mat2){
  assert((mat1.row==mat2.row)&&(mat1.col==mat2.col));
  matrix mat0 ;
  mat0.row = mat1.row ;
  mat0.col = mat1.col ;
  mat0.data = new int [mat1.row * mat1.col];
  for (int i = 0; i < mat1.row * mat1.col; i++)
    mat0.data[i] = mat1.data[i]-mat2.data[i];
  return mat0 ;
}

matrix operator*  (matrix mat1, matrix mat2){
  assert(mat1.col == mat2.row);
  matrix mat0 ;
  mat0.row = mat1.row ;
  mat0.col = mat2.col ;
  mat0.data = new int [mat1.row * mat2.col];
  int x = -1 ;
  for (int i = 0; i < mat0.row * mat0.col; i++)
  {
        if (i%mat0.col==0)
            x++;
        int sum = 0;
        for (int j = 0 ; j < mat1.col ; j++)
        {
          sum+=(mat1.data[(x*mat1.col)+j])*(mat2.data[(j*mat2.col)+(i%mat0.col)]);
        }
        mat0.data[(x*mat0.col)+(i%mat0.col)]=sum;
  }
  return mat0 ;


} // Multi if col1 == row2

matrix operator+  (matrix mat1, int scalar){
matrix mat0 ;
mat0.row = mat1.row ;
mat0.col = mat1.col ;
mat0.data = new int [mat1.row *mat1.col] ;
for (int i = 0; i < mat1.row * mat1.col; i++)
    mat0.data[i] = mat1.data[i]+scalar ;
return mat0 ;
}

matrix operator-  (matrix mat1, int scalar){
matrix mat0 ;
mat0.row = mat1.row ;
mat0.col = mat1.col ;
mat0.data = new int [mat1.row *mat1.col];
for (int i = 0; i < mat1.row * mat1.col; i++)
    mat0.data[i] = mat1.data[i]-scalar ;
return mat0 ;
}

matrix operator*  (matrix mat1, int scalar){
matrix mat0 ;
mat0.row = mat1.row ;
mat0.col = mat1.col ;
mat0.data = new int [mat1.row *mat1.col];
for (int i = 0; i < mat1.row * mat1.col; i++)
    mat0.data[i] = mat1.data[i]*scalar ;
return mat0 ;
}

matrix operator+= (matrix& mat1, matrix mat2){
  for (int i = 0; i < mat1.row * mat1.col; i++)
  {
    mat1.data[i] = mat1.data[i] + mat2.data[i];
  }
  return mat1 ;
}

matrix operator-= (matrix& mat1, matrix mat2){

  for (int i = 0; i < mat1.row * mat1.col; i++)
  {
    mat1.data[i] = mat1.data[i] - mat2.data[i];
  }
  return mat1 ;
}

matrix operator+= (matrix& mat, int scalar){
  for (int i = 0; i < mat.row * mat.col; i++)
  {
    mat.data[i] = mat.data[i] + scalar;
  }
  return mat ;
}

matrix operator-= (matrix& mat, int scalar){
   for (int i = 0; i < mat.row * mat.col; i++)
  {
    mat.data[i] = mat.data[i] - scalar;
  }
  return mat ;
}

void   operator++ (matrix& mat){
  for (int i = 0; i < mat.row * mat.col; i++)
  {
    mat.data[i] = mat.data[i] + 1 ;
  }
}

void   operator-- (matrix& mat){
  for (int i = 0; i < mat.row * mat.col; i++)
  {
    mat.data[i] = mat.data[i] - 1 ;
  }
}

ostream& operator<< (ostream& out, matrix mat){
int w = 0 ;
for (int i = 0; i < mat.col * mat.row ; i++)
{
    out << mat.data[i] << "\t" ;
    w++;
    if (w==mat.col)
    {
        cout << "\n" ;
        w=0;
    }
}

}

istream& operator>> (istream& in, matrix& mat){
    for (int i = 0; i < mat.col * mat.row ; i++)
    {
        in >> mat.data[i] ;
    }
}

bool operator== (matrix mat1, matrix mat2){
 bool w = true ;
 for (int i = 0 ; i < mat1.col *mat1.row ; i++)
 {
     if (mat1.data[i]!=mat2.data[i])
     {
         w = false ;
         break;
     }
 }
 return w ;
}

bool operator!= (matrix mat1, matrix mat2){
 bool w = false ;
 for (int i = 0 ; i < mat1.col *mat1.row ; i++)
 {
     if (mat1.data[i]!=mat2.data[i])
     {
         w = true ;
         break;
     }
 }
 return w ;
}

bool isSquare (matrix mat){
 bool w ;
 if (mat.row == mat.col)
    w=true;
 else
    w=false;
 return w ;
}

bool isSymetric (matrix mat){
 assert(mat.col == mat.row);
 bool w = true ;
 int x = -1 ;
 for (int i = 0 ; i < mat.col *mat.row ; i++)
 {
     if (i%mat.col==0)
        x++;
     if (mat.data[(x*mat.col)+(i%mat.col)]!=mat.data[((i%mat.col)*(mat.col))+x])
     {
         w = false ;
         break;
     }
 }
 return w ;
}

bool isIdentity(matrix mat){
 assert(mat.col == mat.row);
 bool w = true ;
 int x = -1 ;
 for (int i = 0 ; i < mat.col *mat.row ; i++)
 {
     if (i%mat.col==0)
        x++;
     if (((((x*mat.col)+(i%mat.col))==(((i%mat.col)*(mat.col))+x))&&(mat.data[((x*mat.col)+(i%mat.col))]!=1))||((((x*mat.col)+(i%mat.col))!=(((i%mat.col)*(mat.col))+x))&&(mat.data[((x*mat.col)+(i%mat.col))]!=0)))
     {
         w = false ;
         break;
     }
 }
 return w ;

}

matrix transpose(matrix mat){
  matrix mat0 ;
  mat0.row = mat.col ;
  mat0.col = mat.row ;
  mat0.data = new int [mat0.row * mat0.col];
  int x = -1 ;
  for (int i = 0; i < mat0.row * mat0.col; i++){
    if (i%mat0.col==0)
        x++;
    mat0.data[(x*mat0.col)+(i%mat0.col)]=mat.data[((i%mat0.col)*(mat.col))+x];
  }
  return mat0 ;
}








