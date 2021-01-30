/*main.cpp*/

#include <iostream>

#include "mymatrix.h"

using namespace std;

int main()
{
  mymatrix<int>  M;
  
  // testing T& operator()(int r, int c)
  M(0, 0) = 123;
  M(1, 1) = 456;
  M(2, 2) = 789;
  M(3, 3) = -99;
    
  // testing output function 
  cout << "testing output: matrix M" << endl;
  M._output();
  cout << endl;
  
  // testing copy constructor
  cout << "testing copy constructor: M1 = M" << endl;
  mymatrix<int>  M1 = M;  // copy matrix
  M1._output();
    
  // testing numrows function
  cout << "total num of rows: " << M.numrows() << endl;
  
  // testing numcols function
  cout << "num of cols in row r: " << M.numcols(1) << endl;  
    
  // testing size function
  cout << "total elements: " << M.size() << endl;
    
  // testing growcols function
  for (int i = 0; i < M.numrows(); i++) {
      cout << "testing grow cols " << i << " by 1 more"  << endl;
      M.growcols(i, M.numcols(i)+i); 
      M._output();
      cout << endl;
  }
  

    
  //Test Scalar Multiplication
  for (int i = 1; i < 4; i++){
      cout << "testing scalar multiplication by " << 2*i << endl;
      M = M * (2*i);
      M._output();      
      cout << endl;
  }


    
  //testing grow function
  for (int i = 1; i < 4; i++){
    cout << "grow row " << (i*2)+M.numrows() << " by " << (i*3)+M.numcols(i) << endl;
    M.grow((i*2)+M.numrows(), (i*3)+M.numcols(i));
    M._output();    
    cout << endl;
  }


  // testing matrix multiplication
  mymatrix<int>  M2;// 4x4 matrix, initialized to 0
  for (int i = 0; i < M2.numrows(); i++){
      for (int j = 0; j < M2.numcols(i); j++){
          M1(i, j) = j+10+i;   
      }
      cout << "matrix M1: " << endl;
      M1._output();
      cout << endl;
      cout << "testing matrix M1 * M1" << endl; 
      M2 = M1 * M1;// copy matrix
      M2._output();        
      cout << endl;
  }

  return 0;
}