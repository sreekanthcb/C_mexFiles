#include "mex.h"

// self explanatory, challenge is multidimentional array
// program expects a row array
void sumofTwoComplexArray(double *output_arrayReal,double *output_arrayImag,double *real_array1,double *imag_array1,double *real_array2,double *imag_array2,int len){
  for(int i=0;i<len;i++){
      output_arrayReal[i] = real_array1[i] + real_array2[i];
      output_arrayImag[i] = imag_array1[i] + imag_array2[i];
    }
  }


void mexFunction(int nlhs, mxArray *plhs[],int nrhs, const mxArray *prhs[]){

  double *real_array1,*imag_array1,*real_array2,*imag_array2;
  double *output_arrayReal, *output_arrayImag;
  int len;

  // getting length of elements in array 1
  len = mxGetN(prhs[0]);


  real_array1 = mxGetPr(prhs[0]); // pointer to real part of array 1
  imag_array1 = mxGetPi(prhs[0]); // pointer to imag part of array 1
  real_array2 = mxGetPr(prhs[1]); // pointer to real part of array 2
  imag_array2 = mxGetPi(prhs[1]); // pointer to imag part of array 2

  // initialioutput_arrayImagng output array as same as input arrays
  plhs[0] = mxCreateDoubleMatrix(1, len, mxCOMPLEX);
  output_arrayReal = mxGetPr(plhs[0]); // creating pointer to real part of output array
  output_arrayImag = mxGetPi(plhs[0]); // creating pointer to imag part of output array

  // calling the function
  sumofTwoComplexArray(output_arrayReal,output_arrayImag,real_array1,imag_array1,real_array2,imag_array2,len);

}
