#include "headers.h"
#include <stdio.h>

void affPointFp2(PointFp2 P, PointFp2 *Q){
    affectFp2(P.x,(*Q).x);
    affectFp2(P.y,(*Q).y);
    affectFp2(P.z,(*Q).z);
}

void oppPointFp2 (PointFp2 P, PointFp2 *Q){
    affectFp2(P.x,(*Q).x);
    oppModFp2(P.y,(*Q).y);
    affectFp2(P.z,(*Q).z);
}

void frobeniuspFp2 (PointFp2 Q, PointFp2 *frob){
    conjugFp2(Q.x,(*frob).x);
    scalarMulFp2((*frob).x,sig2,(*frob).x);

    conjugFp2(Q.y,(*frob).y);
    scalarMulFp2((*frob).y,sig3,(*frob).y);

    /// PEUT ETRE ENLEVE MAIS FAIS ATTENTION !!!
    setIN(R,(*frob).z[0]);
    initNul((*frob).z[1]);
    //conjugFp2(Q.z,(*frob).z);
}

void affPointFp(PointFp P, PointFp *Q){
    setIN(P.x,(*Q).x);
    setIN(P.y,(*Q).y);
    setIN(P.z,(*Q).z);
    (*Q).isInfinity = P.isInfinity;
}

/*void frobeniusp (PointFp2 Q, PointFp2 *frob){
    frobp(Q.x,&((*frob).x));
    frobp(Q.y,&((*frob).y));
    frobp(Q.z,&((*frob).z));
}*/


void transfMongPointFp2(PointFp2 *P){
    transfMongPol((*P).x,2);
    transfMongPol((*P).y,2);
    transfMongPol((*P).z,2);
}

void invTransMongPointFp2(PointFp2 P, PointFp2 *Q){
    invTransMongPol(P.x,(*Q).x,2);
    invTransMongPol(P.y,(*Q).y,2);
    invTransMongPol(P.z,(*Q).z,2);
}

void afficherPointFp2 (PointFp2 P){
    PRINTHex2D(P.x,2);
    PRINTHex2D(P.y,2);
    PRINTHex2D(P.z,2);
}

void transfMongPointFp (PointFp *P){
    montgomery1024Base32((*P).x,R2,p,m,(*P).x);
    montgomery1024Base32((*P).y,R2,p,m,(*P).y);
    montgomery1024Base32((*P).z,R2,p,m,(*P).z);
}

void invTransMongPointFp(PointFp P, PointFp *Q){
    montgomery1024Base32(P.x,UN,p,m,(*Q).x);
    montgomery1024Base32(P.y,UN,p,m,(*Q).y);
    montgomery1024Base32(P.z,UN,p,m,(*Q).z);
}

void afficherPointFp (PointFp P){
    PRINTHex(P.x);
    PRINTHex(P.y);
    PRINTHex(P.z);
}

int isInfinityFp2(PointFp2 P){
    int i,j;
    for(i=0;i<2;i++)
        for(j=0;j<8;j++) if(P.z[i][j]!=0) return 0;
    return 1;
}

void toAffineFp2(PointFp P, PointFp2 *Q){
    setIN(P.x,(*Q).x[0]);
    initNul((*Q).x[1]);
    setIN(P.y,(*Q).y[0]);
    initNul((*Q).y[1]);
    setIN(P.z,(*Q).z[0]);
    initNul((*Q).z[1]);
}

void jactoaff (PointFp2 A, PointFp2 *B){
    unsigned int z2[2][9] , z3[2][9];
    doubFp2(A.z,z2);
    karatsubaFp2(A.z,z2,z3);
    invFp2(z2,z2);
    invFp2(z3,z3);
    karatsubaFp2(A.x,z2,(*B).x);
    karatsubaFp2(A.y,z3,(*B).y);
    setIN(R,(*B).z[0]); initNul((*B).z[1]);
}

void toAffineFp (PointFp2 P, PointFp *Q){
    setIN(P.x[0],(*Q).x);
    setIN(P.y[0],(*Q).y);
    setIN(P.z[0],(*Q).z);
}

int equalPointFp2 (PointFp2 P, PointFp2 Q){
    return (equalsFp2(P.x,Q.x) &&
            equalsFp2(P.y,Q.y) &&
            equalsFp2(P.z,Q.z));
}

int equalPointFp(PointFp P, PointFp Q){
    if (P.isInfinity==1 && Q.isInfinity==1) return 1;
    else if (P.isInfinity!=1 && Q.isInfinity!=1)
         return (equalsFp(P.x,Q.x) && equalsFp(P.y,Q.y));
    else return 0;
}

int areOppFp2 (PointFp2 P1, PointFp2 P2){
    unsigned long oy2[2][9];
    oppModFp2(P2.y,oy2);
    return (equalsFp2(P1.x, P2.x) && equalsFp2(P1.y, oy2));
}

int areOppFp (PointFp P1, PointFp P2){
    unsigned long oy2[9];
    sub(p,P2.y,p,oy2);
    return (equalsFp(P1.x, P2.x) && equalsFp(P1.y, oy2));
}

void addAfineFp2 (PointFp2 P1, PointFp2 P2, PointFp2 *T, unsigned long lam[2][9]){
        PointFp2 E;
        unsigned long P1x2[2][9],denom[2][9];

        if(equalPointFp2(P1,P2)){
            doubFp2(P1.x,P1x2);
            addModFp2(P1x2,P1x2,lam); addModFp2(lam,P1x2,lam);

            addModFp2(P1.y,P1.y,denom);
            invFp2(denom,denom);

            karatsubaFp2(lam,denom,lam);
        }else{
            subModFp2(P2.y,P1.y,lam);

            subModFp2(P2.x,P1.x,denom);
            invFp2(denom,denom);

            karatsubaFp2(lam,denom,lam);
        }

        doubFp2(lam,E.x);
        subModFp2(E.x,P1.x,E.x);
        subModFp2(E.x,P2.x,E.x);

        subModFp2(P1.x,E.x,E.y);
        karatsubaFp2(E.y,lam,E.y);
        subModFp2(E.y,P1.y,E.y);

        setIN(R,E.z[0]); initNul(E.z[1]);

        affPointFp2(E,T);
}

void addAfineGFp2 (PointFp2 P1, PointFp2 P2, PointFp2 *T, unsigned long lambda[2][9]){
    if (isInfinityFp2(P1)) {
        affPointFp2(P2, T);
    }
    else if (isInfinityFp2(P2)){
        affPointFp2(P1, T);
    }
    else if(areOppFp2(P1,P2)){
        setIN(R,(*T).x[0]); initNul((*T).x[1]);
        setIN(R,(*T).y[0]); initNul((*T).y[1]);
        initNulFp2((*T).z);
        printf("infini");
    }else{
        unsigned long lam[2][9];
        addAfineFp2 (P1,P2,T,lam);
        if (lambda != NULL) affectFp2(lam,lambda);
    }
}

void addAfineFp (PointFp P1, PointFp P2, PointFp *T, unsigned long lam[9]){
        PointFp E;
        unsigned long P1x2[9],denom[9];

        if(equalPointFp(P1,P2)){
            montgomery1024Base32(P1.x,P1.x,p,m,P1x2);
            add(P1x2,P1x2,p,lam); add(lam,P1x2,p,lam);

            add(P1.y,P1.y,p,denom);
            invFp(denom,denom);

            montgomery1024Base32(lam,denom,p,m,lam);
        }else{
            sub(P2.y,P1.y,p,lam);

            sub(P2.x,P1.x,p,denom);
            invFp(denom,denom);

            montgomery1024Base32(lam,denom,p,m,lam);
        }

        montgomery1024Base32(lam,lam,p,m,E.x);
        sub(E.x,P1.x,p,E.x);
        sub(E.x,P2.x,p,E.x);

        sub(P1.x,E.x,p,E.y);
        montgomery1024Base32(E.y,lam,p,m,E.y);
        sub(E.y,P1.y,p,E.y);

        E.isInfinity = 0;

        affPointFp(E,T);
}

void addAfineGFp (PointFp P1, PointFp P2, PointFp *T, unsigned long lambda[9]){
    if (P1.isInfinity==1) {
        affPointFp(P2, T);
    }
    else if (P2.isInfinity==1){
        affPointFp(P1, T);
    }
    else if(areOppFp(P1,P2)){
        setIN(R,(*T).x);
        setIN(R,(*T).y);
        (*T).isInfinity = 1;
        printf("infini\n");
    }else{
        unsigned long lam[9];
        addAfineFp (P1,P2,T,lam);
        if(lambda!=NULL) setIN(lam,lambda);
    }
}

void mulPointFp2 (PointFp2 P, unsigned long a[], unsigned long L,PointFp2 *T){
    int i,j,lastBit[9];
    indLastBit(a,L,lastBit);
    PointFp2 R;
    affPointFp2(P,&R);
    for(j=lastBit[1]-1;j>=0;j--){
        addAfineGFp2(R,R,&R,NULL);
        if(getBitIndex(a[lastBit[0]],j)==1) addAfineGFp2(R,P,&R,NULL);
    }
    for(i=lastBit[0]-1;i>=0;i--){
        for(j=31;j>=0;j--){

            addAfineGFp2(R,R,&R,NULL);
            if(getBitIndex(a[i],j)==1) addAfineGFp2(R,P,&R,NULL);
        }
    }
    affPointFp2(R,T);
}

void mulPointFp (PointFp Q, unsigned long a[], unsigned long L,PointFp *T){
    PointFp2 P,R;
    toAffineFp2(Q,&P);
    mulPointFp2(P,a,L,&R);
    toAffineFp(R,T);
}


///**************************************** PointFP12 ********************************************************///


void toPointFp12(PointFp2 P, PointFp12 *Q){
    initNulFp12(&((*Q).x));
    initNulFp12(&((*Q).y));
    affectFp2(P.x,(*Q).x.w0.v1);
    affectFp2(P.y,(*Q).y.w1.v1);
    (*Q).isInfinity=0;
    //if(isInfinityFp2(P)) (*Q).isInfinity = 1;
}

void toPointFp2 (PointFp12 P, PointFp2 *Q){
    elemFp12 x,y;
    mulFp12(P.x,w_2,&x);
    mulFp12(P.y,w_3,&y);
    affectFp2(x.w0.v0,(*Q).x);
    affectFp2(y.w0.v0,(*Q).y);
    setIN(R,(*Q).z[0]);
    initNul((*Q).z[1]);
    //if(P.isInfinity==1) initNul((*Q).z[0]);
}

void frobpPointFp12 (PointFp12 P, PointFp12 *Q){
    frobp(P.x,&((*Q).x));
    frobp(P.y,&((*Q).y));
    (*Q).isInfinity = P.isInfinity;
}

void invTransMongPointFp12(PointFp12 P, PointFp12 *Q){
    invTransMongFp12(P.x,&((*Q).x));
    invTransMongFp12(P.y,&((*Q).y));
    (*Q).isInfinity=P.isInfinity;
}

void afficherPointfFp12(PointFp12 P){
    printHexFp12(P.x);
    printHexFp12(P.y);
}
