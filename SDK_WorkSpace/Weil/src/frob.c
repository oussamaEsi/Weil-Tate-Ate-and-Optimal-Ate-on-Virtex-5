#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "headers.h"


void frobp (elemFp12 a, elemFp12 *res){
    ///*************** Conjug ***********************
    conjugFp2(a.w1.v0,(*res).w1.v0);
    conjugFp2(a.w0.v1,(*res).w0.v1);
    conjugFp2(a.w1.v1,(*res).w1.v1);
    conjugFp2(a.w0.v2,(*res).w0.v2);
    conjugFp2(a.w1.v2,(*res).w1.v2);

    ///************** Calculs **********************
    conjugFp2(a.w0.v0,(*res).w0.v0);
    scalarMulFp2((*res).w1.v0,sig1,(*res).w1.v0);
    scalarMulFp2((*res).w0.v1,sig2,(*res).w0.v1);
    scalarMulFp2((*res).w1.v1,sig3,(*res).w1.v1);
    scalarMulFp2((*res).w0.v2,sig4,(*res).w0.v2);
    scalarMulFp2((*res).w1.v2,sig5,(*res).w1.v2);
}

void frobp2 (elemFp12 a, elemFp12 *res){
    affectFp2(a.w0.v0,(*res).w0.v0);
    scalarMulFp2(a.w1.v0,sig11,(*res).w1.v0);
    scalarMulFp2(a.w0.v1,sig22,(*res).w0.v1);
    scalarMulFp2(a.w1.v1,sig33,(*res).w1.v1);
    scalarMulFp2(a.w0.v2,sig44,(*res).w0.v2);
    scalarMulFp2(a.w1.v2,sig55,(*res).w1.v2);
}
