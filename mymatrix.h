/*mymatrix.h*/

// 
// Vincent Weaver
// U. of Illinois, Chicago
// CS 251: Spring 2020
// Project #02
//

//
// mymatrix
//
// The mymatrix class provides a matrix (2D array) abstraction.
// The size can grow dynamically in both directions (rows and 
// cols).  Also, rows can be "jagged" --- i.e. rows can have 
// different column sizes, and thus the matrix is not necessarily 
// rectangular.  All elements are initialized to the default value
// for the given type T.  Example:
//
//   mymatrix<int>  M;  // 4x4 matrix, initialized to 0
//   
//   M(0, 0) = 123;
//   M(1, 1) = 456;
//   M(2, 2) = 789;
//   M(3, 3) = -99;
//
//   M.growcols(1, 8);  // increase # of cols in row 1 to 8
//
//   for (int r = 0; r < M.numrows(); ++r)
//   {
//      for (int c = 0; c < M.numcols(r); ++c)
//         cout << M(r, c) << " ";
//      cout << endl;
//   }
//
// Output:
//   123 0 0 0
//   0 456 0 0 0 0 0 0
//   0 0 789 0
//   0 0 0 -99
//

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

template<typename T>
class mymatrix
{
private:
  struct ROW
  {
    T*  Cols;     // dynamic array of column elements
    int NumCols;  // total # of columns (0..NumCols-1)
  };

  ROW* Rows;     // dynamic array of ROWs
  int  NumRows;  // total # of rows (0..NumRows-1)

public:
  //
  // default constructor:
  //
  // Called automatically by C++ to construct a 4x4 matrix.  All 
  // elements are initialized to the default value of T.
  //
  mymatrix()
  {
    Rows = new ROW[4];  // an array with 4 ROW structs:
    NumRows = 4;

    // initialize each row to have 4 columns:
    for (int r = 0; r < NumRows; ++r)
    {
      Rows[r].Cols = new T[4];  // an array with 4 elements of type T:
      Rows[r].NumCols = 4;

      // initialize the elements to their default value:
      for (int c = 0; c < Rows[r].NumCols; ++c)
      {
        Rows[r].Cols[c] = T{};  // default value for type T:
      }
    }
  } // end of default constructor

  //
  // parameterized constructor:
  //
  // Called automatically by C++ to construct a matrix with R rows, 
  // where each row has C columns. All elements are initialized to 
  // the default value of T.
  //
  mymatrix(int R, int C)
  {
    if (R < 1)
      throw invalid_argument("mymatrix::constructor: # of rows");
    if (C < 1)
      throw invalid_argument("mymatrix::constructor: # of cols");

    //
    // TODO
    //
    Rows = new ROW[R];  // an array with 4 ROW structs:
    NumRows = R;

    // initialize each row to have 4 columns:
    for (int r = 0; r < NumRows; ++r)
    {
      Rows[r].Cols = new T[C];  // an array with C elements of type T:
      Rows[r].NumCols = C;

      // initialize the elements to their default value:
      for (int c = 0; c < Rows[r].NumCols; ++c)
      {
        Rows[r].Cols[c] = T{};  // default value for type T:
      }
    }
  } // end of my matrix parameterized constructor


  //
  // copy constructor:
  //
  // Called automatically by C++ to construct a matrix that contains a 
  // copy of an existing matrix.  Example: this occurs when passing 
  // mymatrix as a parameter by value
  //
  //   void somefunction(mymatrix<int> M2)  <--- M2 is a copy:
  //   { ... }
  //
  mymatrix(const mymatrix<T>& other)
  {
    //
    // TODO
    //
    // -------------------
     this->Rows = new ROW[other.NumRows];  // an array with 4 ROW structs:
     this->NumRows = other.NumRows;

    // initialize each row to have 4 columns:
    for (int r = 0; r < other.NumRows; ++r)
    {
      this->Rows[r].Cols =  new T[other.Rows[r].NumCols];  // an array with 4 elements of type T:
      this->Rows[r].NumCols = other.Rows[r].NumCols;

      // initialize the elements to their default value:
      for (int c = 0; c < other.Rows[r].NumCols; ++c)
      {
        this->Rows[r].Cols[c] = other.Rows[r].Cols[c];  // default value for type T:
      }
    }
  } // end of mymatrix copy constructor


  //
  // numrows
  //
  // Returns the # of rows in the matrix.  The indices for these rows
  // are 0..numrows-1.
  //
  int numrows() const
  {
    //
    // TODO
    //
//     int total = 0;
//     for (total = 0; total < NumRows; total++) {
//         ;
//     }
    return NumRows;
  } // end of num rows function
  

  //
  // numcols
  //
  // Returns the # of columns in row r.  The indices for these columns
  // are 0..numcols-1.  Note that the # of columns can be different 
  // row-by-row since "jagged" rows are supported --- matrices are not
  // necessarily rectangular.
  //
  int numcols(int r) const
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::numcols: row");

    //
    // TODO
    //
//     int total = 0;
//     for (total = 0; total < Rows[r].NumCols; ++total)
//     {
//       //this-> Rows[r].Cols[c] = other.Rows[r].Cols[c];  // default value for type T:
//       ;
//     }
    return Rows[r].NumCols;
  }// end of numcols function


  //
  // growcols
  //
  // Grows the # of columns in row r to at least C.  If row r contains 
  // fewer than C columns, then columns are added; the existing elements
  // are retained and new locations are initialized to the default value 
  // for T.  If row r has C or more columns, then all existing columns
  // are retained -- we never reduce the # of columns.
  //
  // Jagged rows are supported, i.e. different rows may have different
  // column capacities -- matrices are not necessarily rectangular.
  //
  void growcols(int r, int C)
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::growcols: row");
    if (C < 1)
      throw invalid_argument("mymatrix::growcols: columns");

    //
    // TODO:
    //
 
    if(C<= Rows[r].NumCols) 
        return; 
    
    int current = Rows[r].NumCols;

    T* newRow = new T[C];

    for (int j = 0 ; j < C; ++j) {
        newRow[j] = T{};
    }   

    for (int i = 0; i < current; ++i) {
        newRow[i] = Rows[r].Cols[i];
    }

    delete[] Rows[r].Cols;

    Rows[r].Cols = newRow;
    Rows[r].NumCols = C;  
  }


  //
  // grow
  //
  // Grows the size of the matrix so that it contains at least R rows,
  // and every row contains at least C columns.
  // 
  // If the matrix contains fewer than R rows, then rows are added
  // to the matrix; each new row will have C columns initialized to 
  // the default value of T.  If R <= numrows(), then all existing
  // rows are retained -- we never reduce the # of rows.
  //
  // If any row contains fewer than C columns, then columns are added
  // to increase the # of columns to C; existing values are retained
  // and additional columns are initialized to the default value of T.
  // If C <= numcols(r) for any row r, then all existing columns are
  // retained -- we never reduce the # of columns.
  // 
  void grow(int R, int C)
  {
    if (R < 1)
      throw invalid_argument("mymatrix::grow: # of rows");
    if (C < 1)
      throw invalid_argument("mymatrix::grow: # of cols");

    //
    // TODO:
    //
    for (int r = 0; r < NumRows; r++){ // loop through each row
        if (C <= Rows[r].NumCols){ // if true, do nothing
            ;
        }
        else { // same as grow cols
            int current = Rows[r].NumCols;

            T* newRow = new T[C];
            
            for (int j = 0 ; j < C; ++j) {
                newRow[j] = T{};
            }   
            
            for (int i = 0; i < current; ++i) {
                newRow[i] = Rows[r].Cols[i];
            }
            
            delete[] Rows[r].Cols;

            Rows[r].Cols = newRow;
            Rows[r].NumCols = C;
        }// end of else statement
    } // end of loop    
    if (R <= numrows()){
        // retain # of rows
        ;
    }
    else {
        // add rows
        //NumRows = R; // change NumRows value throughout program
        // scale cols to each row
        ROW* growRows = new ROW[R];
        for (int r = 0; r < NumRows; r++) { // increment through new rows
        
            growRows[r].Cols = Rows[r].Cols; // sets old row into new row
            growRows[r].NumCols = C; // set number of cols to new amount of cols
             
        } // end inner loop
        for (int r = NumRows; r < R; r++){
            growRows[r].Cols = new T[C]; // create a new array of columns
            growRows[r].NumCols = C; // sets number of cols to each row
            for (int c = 0; c < C; c++){
                growRows[r].Cols[c] = T{}; // defaults value to zero
            } // end of inner loop
        }// end of outer loop
        delete[] Rows; // delete the old rows
        Rows = growRows; // 
        NumRows = R; 
    } // end of else statement
  } // end of grow function


  //
  // size
  //
  // Returns the total # of elements in the matrix.
  //
  int size() const
  {
    //
    // TODO
    //
    int total = 0;
    for (int i = 0; i < NumRows; i++){
        for (int j = 0; j < Rows[i].NumCols; j++){
            total++;
        }
    }
    return total;
  } // end of size function


  //
  // at
  //
  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //
  //    M.at(r, c) = ...
  //    cout << M.at(r, c) << endl;
  //
  T& at(int r, int c)
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::at: row");
    if (c < 0 || c >= Rows[r].NumCols)
      throw invalid_argument("mymatrix::at: col");

    //
    // TODO
    //

    //T temp = {};  // we need to return something, so a temp for now:

    return Rows[r].Cols[c];
  }


  //
  // ()
  //
  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //
  //    M(r, c) = ...
  //    cout << M(r, c) << endl;
  //
  T& operator()(int r, int c) // puts values into a point
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::(): row");
    if (c < 0 || c >= Rows[r].NumCols)
      throw invalid_argument("mymatrix::(): col");

    //
    // TODO
    //

    //T temp = {};  // we need to return something, so a temp for now:
    //cout << M(r, c) << endl;
    //return temp;
    return Rows[r].Cols[c];
  } // end of operator function

  //
  // scalar multiplication
  //
  // Multiplies every element of this matrix by the given scalar value,
  // producing a new matrix that is returned.  "This" matrix is not
  // changed.
  //
  // Example:  M2 = M1 * 2;
  //
  mymatrix<T> operator*(T scalar)
  {
    // initialize result 
    mymatrix<T> result(*this);
    //mymatrix<T> result;
    //
    // TODO
    //
    for (int r = 0; r < NumRows; r++){ // go through all rows
        for (int c = 0; c < Rows[r].NumCols; c++){ // go through all cols
            
            result.Rows[r].Cols[c] = (scalar * Rows[r].Cols[c]);
        }
    }

    return result;
  }


  //
  // matrix multiplication
  //
  // Performs matrix multiplication M1 * M2, where M1 is "this" matrix and
  // M2 is the "other" matrix.  This produces a new matrix, which is returned.
  // "This" matrix is not changed, and neither is the "other" matrix.
  //
  // Example:  M3 = M1 * M2;
  //
  // NOTE: M1 and M2 must be rectangular, if not an exception is thrown.  In
  // addition, the sizes of M1 and M2 must be compatible in the following sense:
  // M1 must be of size RxN and M2 must be of size NxC.  In this case, matrix
  // multiplication can be performed, and the resulting matrix is of size RxC.
  //
  mymatrix<T> operator*(const mymatrix<T>& other)
  {
    
    
    //
    // both matrices must be rectangular for this to work:
    //

    //
    // TODO
    //
    // check if rows are rectangular
    for(int i =0; i < NumRows; ++i){ 
        // check columns in each row and compare with the first num of cols in the row
        if(Rows[i].NumCols != this->Rows[0].NumCols){ 
            throw runtime_error("mymatrix::*: this not rectangular");
        }
    }

    for(int j = 0; j < other.NumRows; ++j){ // check rows on other matrix to be rectangular
        // check the colums in each row and compare with original row[0] size
        if(other.Rows[j].NumCols != other.Rows[0].NumCols){
            throw runtime_error("mymatrix::*: other not rectangular");
        }
    }
    // compare RxN with NxC 
    if(this->Rows[0].NumCols != other.NumRows){
        throw runtime_error("mymatrix::*: size mismatch");
    }

    //
    // Okay, both matrices are rectangular.  Can we multiply?  Only
    // if M1 is R1xN and M2 is NxC2.  This yields a result that is
    // R1xC2.
    // 
    // Example: 3x4 * 4x2 => 3x2
    //


    //
    // TODO
    //

    //
    // Okay, we can multiply:
    //
    // initialize result to be a matrix at R1xC2
    // this-> NumRows = R1
    // other.Rows[i].NumCols = C2
    mymatrix<T> result(this->NumRows, other.Rows[0].NumCols); 
    
    //
    // TODO
    //    
    for(int n = 0; n < this->NumRows; n++){ // loop through first matrix rows
        for(int m = 0; m < other.Rows[0].NumCols; m++){ // loop through other matrix columns
            for(int j = 0; j < this->Rows[0].NumCols; j++){ // loop through first matrix columns
               // increment the result with each columns in each rows

               result.Rows[n].Cols[m] = result.Rows[n].Cols[m] + (Rows[n].Cols[j] * other.Rows[j].Cols[m]);
            } // end of inner loop
        } // end of mid loop
    } // end of outer loop

    return result;
  } // end of matrix multiplication


  //
  // _output
  //
  // Outputs the contents of the matrix; for debugging purposes.
  //
  void _output()
  {
    for (int r = 0; r < this->NumRows; ++r)
    {
      for (int c = 0; c < this->Rows[r].NumCols; ++c)
      {
        cout << this->Rows[r].Cols[c] << " ";
      }
      cout << endl;
    }
  } // end out output

};
