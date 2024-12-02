#include "mex.h"

// Function where operation happens
void sumofTwoNos(double z[],double x[],double y[]){
  z[0] = x[0]+ y[0];
}

// Main function
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
  double *x,*y,*z;

  plhs[0] = mxCreateDoubleMatrix(1,1, mxREAL); // iniitializing pointer to output

  x = mxGetPr(prhs[0]); // pointer to first number
  y = mxGetPr(prhs[1]); // pointer to second number

  z = mxGetPr(plhs[0]); // pointer to output

  sumofTwoNos(z,x,y);
}
