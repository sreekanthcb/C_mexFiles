#include "mex.h"

void sumofArray(double z[],double x[],int cols){
 z[0] = 0;
 for(int i=0;i<cols;i++){
  z[0] = z[0] + x[i];
 }
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
  double *x,*z;
  int ncols;

  ncols = mxGetN(prhs[0]);

  plhs[0] = mxCreateDoubleMatrix(1,1, mxREAL);

  x = mxGetPr(prhs[0]);

  z = mxGetPr(plhs[0]);

  sumofArray(z,x,ncols);
}
