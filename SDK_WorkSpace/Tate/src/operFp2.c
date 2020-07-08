#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "headers.h"

void initNulFp2 (unsigned long a[2][9]){
    int i;
    for(i=0;i<9;i++) a[0][i]=0;
    for(i=0;i<9;i++) a[1][i]=0;
}

void affectFp2(unsigned long a[2][9], unsigned long b[2][9]){
    setIN(a[0],b[0]);
    setIN(a[1],b[1]);
}

int equalsFp2 (unsigned long a[2][9], unsigned long b[2][9]){
    int i,j;
    for(i=0;i<2;i++)
        for(j=0;j<8;j++) if(a[i][j]!=b[i][j]) return 0;
    return 1;
}

void addModFp2 (unsigned long a[2][9] , unsigned long b[2][9] , unsigned long res[2][9]){
    add(a[0],b[0],p,res[0]);
    add(a[1],b[1],p,res[1]);
}

void subModFp2 (unsigned long a[2][9] , unsigned long b[2][9] , unsigned long res[2][9]){
    sub(a[0],b[0],p,res[0]);
    sub(a[1],b[1],p,res[1]);
}

void oppModFp2 (unsigned long a[2][9] , unsigned long oa[2][9]){
    if(isNul(a[0])==0) sub(p,a[0],p,oa[0]);
    else initNul(oa[0]);
    if(isNul(a[1])==0) sub(p,a[1],p,oa[1]);
    else initNul(oa[1]);
}

void conjugFp2 (unsigned long a[2][9] , unsigned long aa[2][9]){
    setIN(a[0],aa[0]);
    if(isNul(a[1])==0)sub(p,a[1],p,aa[1]);
    else initNul(aa[1]) ;
}

void scalarMulFp2 (unsigned long a[2][9], unsigned long coeff[9], unsigned long b[2][9]){
    montgomery1024Base32(a[0], coeff,p,m,b[0]);
    montgomery1024Base32(a[1], coeff,p,m,b[1]);
}

void mulXFp2(unsigned long a[2][9], unsigned long aX[2][9]){
    unsigned long tmp[9]={0};
    montgomery1024Base32(a[1],redFp,p,m,tmp);
    setIN(a[0],aX[1]);
    setIN(tmp,aX[0]);
}

void karatsubaFp2 (unsigned long a[2][9] , unsigned long b[2][9] , unsigned long res[2][9]){
        unsigned long t0[9],t1[9],temp[9];
        montgomery1024Base32(a[0],b[0],p,m,t0);
        montgomery1024Base32(a[1],b[1],p,m,t1);

        add(b[0],b[1],p,temp);
        add(a[0],a[1],p,res[1]);
        montgomery1024Base32(res[1],temp,p,m,res[1]);
        sub(res[1],t0,p,res[1]);
        sub(res[1],t1,p,res[1]);

        montgomery1024Base32(t1,redFp,p,m,res[0]);
        add(res[0],t0,p,res[0]);
}

void doubFp2 (unsigned long a[2][9], unsigned long c[2][9]){
    unsigned long t0[9],tmp[9];
    montgomery1024Base32(a[0],a[1],p,m,t0);
    montgomery1024Base32(redFp,a[1],p,m,tmp);

    sub(a[0],tmp,p,tmp);
    sub(a[0],a[1],p,c[0]);
    montgomery1024Base32(c[0],tmp,p,m,c[0]);

    add(t0,t0,p,c[1]);

    montgomery1024Base32(redFp,t0,p,m,tmp);
    add(c[0],t0,p,c[0]);
    add(c[0],tmp,p,c[0]);
}

void invFp2 (unsigned long a[2][9], unsigned long invA[2][9]){
    unsigned long coeff[9],tmp[9];
    ///******************* calcul coeff******************
    montgomery1024Base32(a[0],a[0],p,m,coeff);
    montgomery1024Base32(a[1],a[1],p,m,tmp);
    montgomery1024Base32(redFp,tmp,p,m,tmp);
    sub(coeff,tmp,p,coeff);

    invFp(coeff,coeff);

    ///**************   Affectations ***************
    montgomery1024Base32(a[0],coeff,p,m,invA[0]);

    montgomery1024Base32(a[1],coeff,p,m,invA[1]);
    sub(p,invA[1],p,invA[1]);
}

/// proelem faut voir unite montgomery!!!!!!!!!!!!!!!!!!!
/*void expoFp2 (unsigned long a[2][9], unsigned long exposant[9] ,unsigned long res[2][9]){
    unsigned long i,j,puis2[2][9];
    ///******************* INit
    setIN(a[0],puis2[0]);
    setIN(a[1],puis2[1]);
    for(i=0;i<2;i++) for(j=0;j<9;j++) res[i][j]=0;
    setIN(R,res[0]);
    ///************* exponitiation
    for(i=0;i<8;i++){
        for(j=0;j<32;j++){
            if(getBitIndex(exposant[i],j) == 1) karatsubaFp2(res,puis2,res);
            karatsubaFp2(puis2,puis2,puis2);
        }
    }
}*/
