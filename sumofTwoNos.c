#include "mex.h"

void sumofTwoNos(double z[],double x[],double y[]){
  z[0] = x[0]+ y[0];
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
  double *x,*y,*z;
  int mrows, ncols;

  mrows = mxGetM(prhs[0]);
  ncols = mxGetN(prhs[0]);

  plhs[0] = mxCreateDoubleMatrix(mrows,ncols, mxREAL);

  x = mxGetPr(prhs[0]);
  y = mxGetPr(prhs[1]);

  z = mxGetPr(plhs[0]);

  sumofTwoNos(z,x,y);
}
