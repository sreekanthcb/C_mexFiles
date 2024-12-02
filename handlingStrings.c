#include "mex.h"

//Program reverses a string
void handlingStrings(char* outStr,char* inpStr,int lenStr){
  int k = 0;
  for (int i = lenStr; i > 0; i--){
    *(outStr+k) = *(inpStr+i-2);
    k = k+1;
  }

}

// Main function
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){

  char *inpStr, *outStr; // input and outpur strings
  int   lenStr;

  lenStr = (mxGetM(prhs[0]) * mxGetN(prhs[0])) + 1; // getting length of input string

  inpStr = mxCalloc(lenStr, sizeof(char)); // memory allocation for input string
  outStr = mxCalloc(lenStr, sizeof(char)); // memory allocation for output string

  mxGetString(prhs[0], inpStr, lenStr); // getting string from prhs[0] to input string variable

  handlingStrings(outStr,inpStr,lenStr); // calling function

  plhs[0] = mxCreateString(outStr); // copying output string from its variable to plhs[0]

}
