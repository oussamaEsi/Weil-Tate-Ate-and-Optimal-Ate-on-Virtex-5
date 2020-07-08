#include "headers.h"
#include <stdio.h>

void lineLite (PointFp P,PointFp2 S, unsigned long lam[9], elemFp12 *l){
    /// w^0
    montgomery1024Base32(lam,P.x,p,m,(*l).w0.v0[0]);
    sub((*l).w0.v0[0],P.y,p,(*l).w0.v0[0]);
    initNul((*l).w0.v0[1]);
    /// w^1
    initNulFp2((*l).w1.v0);
    /// w^2
    scalarMulFp2(S.x,lam,(*l).w0.v1);
    oppModFp2((*l).w0.v1,(*l).w0.v1);
    /// w^3
    affectFp2(S.y,(*l).w1.v1);
    /// w^4
    initNulFp2((*l).w0.v2);
    /// w^5
    initNulFp2((*l).w1.v2);
}

void vLite (PointFp2 S, PointFp T, elemFp12 *v){
    /// w^0
    opp(T.x,p,(*v).w0.v0[0]);
    initNul((*v).w0.v0[1]);
    /// w^1
    initNulFp2((*v).w1.v0);
    /// w^2
    affectFp2(S.x,(*v).w0.v1);
    /// w^3
    initNulFp2((*v).w1.v1);
    /// w^4
    initNulFp2((*v).w0.v2);
    /// w^5
    initNulFp2((*v).w1.v2);
}



void lineFull (PointFp2 P,PointFp S, unsigned long lam[2][9], elemFp12 *l){
    ///  w^0
    setIN(S.y,(*l).w0.v0[0]);
    opp((*l).w0.v0[0],p,(*l).w0.v0[0]);
    initNul((*l).w0.v0[1]);
    /// w^1
    scalarMulFp2(lam,S.x,(*l).w1.v0);
    //oppModFp2((*l).w1.v0,(*l).w1.v0);
    /// w^2
    initNulFp2((*l).w0.v1);
    /// w^3
    karatsubaFp2(lam,P.x,(*l).w1.v1);
    subModFp2(P.y,(*l).w1.v1,(*l).w1.v1);
    /// w^4
    initNulFp2((*l).w0.v2);
    /// w^5
    initNulFp2((*l).w1.v2);
}


void vFull (PointFp S, PointFp2 T, elemFp12 *v){
    /// w^0
    setIN(S.x,(*v).w0.v0[0]);
    initNul((*v).w0.v0[1]);
    /// w^1
    initNulFp2((*v).w1.v0);
    /// w^2
    oppModFp2(T.x,(*v).w0.v1);
    /// w^3
    initNulFp2((*v).w1.v1);
    /// w^4
    initNulFp2((*v).w0.v2);
    /// w^5
    initNulFp2((*v).w1.v2);
}





