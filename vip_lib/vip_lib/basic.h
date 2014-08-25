// VISION IMAGE PROCESSING LAB. ( V.I.P. LAB. )
// AUTHOR : DO-YOUNG PARK
// LAST MODIFIED : 24 / 08 / 2014 
// COPYRIGHT(C) 2014
// ALL RIGHTS RESERVED BY DO-YOUNG PARK
// FUNCTIONS FOR IMAGE PROCESSING

// FUNCTION : DFT, DCT 


#ifndef _DOYOUNG_LIB_
#define _DOYOUNG_LIB_

#include	<fstream>
#include	<iostream>
#include	<cmath>
#if _MSC_VER > 1020   //VC++ version is > 4.2
#if _MSC_VER > 1600
#pragma warning ( disable :4996 )
#endif
using namespace std; 
#endif

#define PI 3.14159265359
#define BYTE_MAX 255
#define FORWARD 1
#define BACKWARD -1

void __stdcall DY_DFT_1D(double* real, double* imagine, const int length, const int direction = FORWARD);
void __stdcall DY_DCT_1D(double* dst, double*  src, const int length, const int direction = FORWARD);

#endif

