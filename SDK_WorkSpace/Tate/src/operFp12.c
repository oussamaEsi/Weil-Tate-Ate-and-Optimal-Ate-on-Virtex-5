#include "headers.h"
#include<time.h>

void initNulFp12 (elemFp12 *a){
    initNulFp6(&((*a).w0));
    initNulFp6(&((*a).w1));
}

void affectFp12(elemFp12 a, elemFp12 *b){
    affectFp6(a.w0,&((*b).w0));
    affectFp6(a.w1,&((*b).w1));
}

void addFp12 (elemFp12 a, elemFp12 b, elemFp12 *res){
    addFp6(a.w0,b.w0,&((*res).w0));
    addFp6(a.w1,b.w1,&((*res).w1));
}

void oppFp12 (elemFp12 a, elemFp12 *oa){
    oppFp6(a.w0,&((*oa).w0));
    oppFp6(a.w1,&((*oa).w1));
}

void subFp12(elemFp12 a, elemFp12 b, elemFp12 *res){
    subFp6(a.w0,b.w0,&((*res).w0));
    subFp6(a.w1,b.w1,&((*res).w1));
}

void conjugFp12 (elemFp12 a, elemFp12 *res){
    affectFp6(a.w0,&((*res).w0));
    oppFp6(a.w1,&((*res).w1));
}

void mulFp12 (elemFp12 a, elemFp12 b, elemFp12 *res){
    elemFp6 t0,t1;
    mulFp6(a.w0,b.w0,&t0);
    mulFp6(a.w1,b.w1,&t1);


    elemFp6 temp1,temp2;
    mulXFp6(t1,&temp1);
    addFp6(t0,temp1,&temp1);

    addFp6(a.w0,a.w1,&temp2);
    addFp6(b.w0,b.w1,&((*res).w1));
    mulFp6(temp2,(*res).w1,&((*res).w1));
    subFp6((*res).w1,t0,&((*res).w1));
    subFp6((*res).w1,t1,&((*res).w1));

    affectFp6(temp1,&((*res).w0));
}

void doubFp12 (elemFp12 a, elemFp12 *res){
    elemFp6 t0,tmp;
    mulFp6(a.w0,a.w1,&t0);
    mulXFp6(a.w1,&tmp);

    subFp6(a.w0,tmp,&tmp);
    subFp6(a.w0,a.w1,&((*res).w0));
    mulFp6((*res).w0,tmp,&((*res).w0));

    addFp6(t0,t0,&((*res).w1));

    mulXFp6(t0,&tmp);
    addFp6((*res).w0,t0,&((*res).w0));
    addFp6((*res).w0,tmp,&((*res).w0));
}

void invFp12 (elemFp12 a, elemFp12 *invA){
    elemFp6 t0,t1,tmp;
    doubFp6(a.w0,&t0);
    doubFp6(a.w1,&t1);
    mulXFp6(t1,&tmp);
    subFp6(t0,tmp,&t0);
    invFp6(t0,&t1);
    mulFp6(a.w0,t1,&((*invA).w0));
    mulFp6(a.w1,t1,&((*invA).w1));
    oppFp6((*invA).w1,&((*invA).w1));
}

// Exponontiaion 't' in Fp12
void expTFp12(elemFp12 a, elemFp12 *res){

    int j=0;
    elemFp12 ca;
    ///******************* INit *******************
    affectFp12(a,res);

    ///************* exponitiation  ***************
    for(j=61;j>=0;j--){
    	doubFp12(*res,res);
    	if(j==54) {
    		conjugFp12(a,&ca);
    		mulFp12(ca,(*res),res);
    	}
    	if(j==44) {
    		mulFp12(a,(*res),res);
    	}
    }
}

void expoFp12(elemFp12 a, unsigned long exposant[9] ,elemFp12 *res){
    unsigned long i,j;
    elemFp12 puis2;
    ///******************* INit *******************
    affectFp12(a,&puis2);
    initNulFp12(res);
    for(i=0;i<8;i++) (*res).w0.v0[0][i] = R[i];
    ///************* exponitiation  ***************
    for(i=0;i<8;i++){
        for(j=0;j<32;j++){
            if(getBitIndex(exposant[i],j) == 1) mulFp12(*res,puis2,res);
            doubFp12(puis2,&puis2);
        }
    }
}




void transfMongFp12 (elemFp12 *P){
    transfMongPol((*P).w0.v0,2);
    transfMongPol((*P).w0.v1,2);
    transfMongPol((*P).w0.v2,2);
    transfMongPol((*P).w1.v0,2);
    transfMongPol((*P).w1.v1,2);
    transfMongPol((*P).w1.v2,2);
}

void invTransMongFp12(elemFp12 l, elemFp12 *n){
    invTransMongPol(l.w0.v0,(*n).w0.v0,2);
    invTransMongPol(l.w0.v1,(*n).w0.v1,2);
    invTransMongPol(l.w0.v2,(*n).w0.v2,2);
    invTransMongPol(l.w1.v0,(*n).w1.v0,2);
    invTransMongPol(l.w1.v1,(*n).w1.v1,2);
    invTransMongPol(l.w1.v2,(*n).w1.v2,2);
}


void printHexFp12(elemFp12 l){
    printf("Resultat : \n");
    PRINTHex2D(l.w0.v0,2);
    PRINTHex2D(l.w0.v1,2);
    PRINTHex2D(l.w0.v2,2);
    PRINTHex2D(l.w1.v0,2);
    PRINTHex2D(l.w1.v1,2);
    PRINTHex2D(l.w1.v2,2);
}
