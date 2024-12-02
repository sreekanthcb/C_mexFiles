#include "mex.h"

// Function where operation happens
// program expects a row array
void sumofArray(double z[],double x[],int cols){
 z[0] = 0;
 for(int i=0;i<cols;i++){
  z[0] = z[0] + x[i];
 }
}

// Main function
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
  double *x,*z;
  int ncols;

  ncols = mxGetN(prhs[0]); // getting number of elements in array: here its no of colomns

  plhs[0] = mxCreateDoubleMatrix(1,1, mxREAL); // initializing ouput

  x = mxGetPr(prhs[0]); // pointer to input array

  z = mxGetPr(plhs[0]); // pointer to ouput sum which is scalar

  sumofArray(z,x,ncols);
}
