#include "mex.h"

// Pointer based matrix addition (only real valued matrix)
void sumofMatrices(double *z,double *x,double *y,int nrows,int ncols){
  for(int ii=0;ii<nrows;ii++){
    for(int jj=0;jj<ncols;jj++){
        *((z+ii*ncols) + jj) = *((x+ii*ncols) + jj) + *((y+ii*ncols) + jj) ; // need to study this more
    }
  }
}

// Main function
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
  double *x,*y,*z;
  int mrows0, ncols0, mrows1, ncols1;

  // getting dimenstions of matrix 1
  mrows0 = mxGetM(prhs[0]);
  ncols0 = mxGetN(prhs[0]);

  // getting dimenstions of matrix 2
  mrows1 = mxGetM(prhs[1]);
  ncols1 = mxGetN(prhs[1]);

  // Error msg if matrix size dont match
  if (mrows0 != mrows1 || ncols0 != ncols1){
     mexErrMsgTxt("Dimensions of matrices not matching");
  }

  plhs[0] = mxCreateDoubleMatrix(mrows1,ncols1, mxREAL); // initializing ouput matrix

  // pointer to input matrices
  x = mxGetPr(prhs[0]);
  y = mxGetPr(prhs[1]);

  // pointer to ouput matrix
  z = mxGetPr(plhs[0]);

  sumofMatrices(z,x,y,mrows1,ncols1);
}
