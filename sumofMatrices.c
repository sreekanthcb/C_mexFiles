#include "mex.h"

void sumofMatrices(double z,double x,double y,int nrows,int ncols){
  for(int ii=0;ii<nrows;ii++){
    for(int jj=0;jj<ncols;jj++){
        z[ii][jj] = x[ii][jj] + y[ii][jj];
    }
  }
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
  double *x,*y,*z;
  int mrows0, ncols0, mrows1, ncols1;

  mrows0 = mxGetM(prhs[0]);
  ncols0 = mxGetN(prhs[0]);

  mrows1 = mxGetM(prhs[1]);
  ncols1 = mxGetN(prhs[1]);

  if (mrows0 != mrows1 || ncols0 != ncols1){
     mexErrMsgTxt("Dimensions of matrices not matching");
  }

  plhs[0] = mxCreateDoubleMatrix(mrows1,ncols1, mxREAL);

  x = mxGetPr(prhs[0]);
  y = mxGetPr(prhs[1]);

  z = mxGetPr(plhs[0]);

  sumofMatrices(z,x,y,mrows1,ncols1);
}
