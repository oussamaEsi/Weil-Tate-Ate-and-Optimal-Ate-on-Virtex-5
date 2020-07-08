#include "headers.h"
#include <time.h>

#include "xtmrctr.h"
#include "xtmrctr_i.h"

int cpt; //Timer

void pointDoubLineEvalT (PointFp Q, PointFp2 P, elemFp12 *l, PointFp *T){
    ///***********     1          ***********///
    unsigned long tmp0[9];
    montgomery1024Base32(Q.x,Q.x,p,m,tmp0);///1

    ///***********     2          ***********///
    unsigned long tmp1[9];
    montgomery1024Base32(Q.y,Q.y,p,m,tmp1);///2

    ///***********     3          ***********///
    unsigned long tmp2[9];
    montgomery1024Base32(tmp1,tmp1,p,m,tmp2);///3

    ///***********     4          ***********///
    unsigned long tmp3[9];
    add(tmp1,Q.x,p,tmp3);
    montgomery1024Base32(tmp3,tmp3,p,m,tmp3);
    sub(tmp3,tmp0,p,tmp3);
    sub(tmp3,tmp2,p,tmp3);

    ///***********     5          ***********///
    add(tmp3,tmp3,p,tmp3);

    ///***********     6          ***********///
    unsigned long tmp4[9];
    add(tmp0,tmp0,p,tmp4);
    add(tmp4,tmp0,p,tmp4);

    ///***********     7          ***********///
    unsigned long tmp6[9];
    add(tmp4,Q.x,p,tmp6);

    ///***********     8          ***********///
    unsigned long tmp5[9];
    montgomery1024Base32(tmp4,tmp4,p,m,tmp5);

    ///***********     9          ***********///
    sub(tmp5,tmp3,p,(*T).x);
    sub((*T).x,tmp3,p,(*T).x);

    ///***********     10          ***********///
    unsigned long Zq2[9];
    add(Q.y,Q.z,p,(*T).z);
    montgomery1024Base32((*T).z,(*T).z,p,m,(*T).z);
    sub((*T).z,tmp1,p,(*T).z);
    montgomery1024Base32(Q.z,Q.z,p,m,Zq2);
    sub((*T).z,Zq2,p,(*T).z);

    ///***********     11          ***********///
    add(tmp2,tmp2,p,tmp2);
    add(tmp2,tmp2,p,tmp2);
    add(tmp2,tmp2,p,tmp2);
    sub(tmp3,(*T).x,p,(*T).y);
    montgomery1024Base32((*T).y,tmp4,p,m,(*T).y);
    sub((*T).y,tmp2,p,(*T).y);

    ///***********     12          ***********///
    montgomery1024Base32(tmp4,Zq2,p,m,tmp3);
    add(tmp3,tmp3,p,tmp3);
    opp(tmp3,p,tmp3);

    ///***********     13          ***********///
    /// !!!!!!!!  affectation l10  !!!!!!!!!!
    scalarMulFp2(P.x,tmp3,(*l).w0.v1);

    ///***********     14          ***********///
    montgomery1024Base32(tmp6,tmp6,p,m,tmp6);
    sub(tmp6,tmp0,p,tmp6);
    sub(tmp6,tmp5,p,tmp6);
    add(tmp1,tmp1,p,tmp1);
    add(tmp1,tmp1,p,tmp1);
    ///!!!!!!!!   affectation l11 !!!!!!!!!!!!
    sub(tmp6,tmp1,p,(*l).w0.v0[0]);

    ///***********     15          ***********///
    montgomery1024Base32((*T).z,Zq2,p,m,tmp0);
    add(tmp0,tmp0,p,tmp0);

    ///***********     16          ***********///
    ///!!!!!!!!! affectation l00  !!!!!!!!
    scalarMulFp2(P.y,tmp0,(*l).w1.v1);

    ///***********     17          ***********///
    /// a0 six numbers , a1 six numbers

    ///***********     18          ***********///
    unsigned long i,j;

    for(i=0;i<9;i++) (*l).w0.v0[1][i]=0;

    for(j=0;j<2;j++) for(i=0;i<9;i++) (*l).w0.v2[j][i]=0;

    ///***********     19          ***********///
    for(j=0;j<2;j++) for(i=0;i<9;i++) (*l).w1.v0[j][i]=0;
    for(j=0;j<2;j++) for(i=0;i<9;i++) (*l).w1.v2[j][i]=0;
}


void pointAddLineEvalT (PointFp Q, PointFp R, PointFp2 P, elemFp12 *l, PointFp *T){
    ///***********     1          ***********///
    unsigned long t0[9], zr2[9];
    montgomery1024Base32(R.z,R.z,p,m,zr2);
    montgomery1024Base32(Q.x,zr2,p,m,t0);

    ///***********     2          ***********///
    unsigned long t1[9], yq2[9];
    montgomery1024Base32(Q.y,Q.y,p,m,yq2);
    add(Q.y,R.z,p,t1);
    montgomery1024Base32(t1,t1,p,m,t1);
    sub(t1,yq2,p,t1);
    sub(t1,zr2,p,t1);

    ///***********     3          ***********///
    montgomery1024Base32(t1,zr2,p,m,t1);

    ///***********     4          ***********///
    unsigned long t2[9];
    sub(t0,R.x,p,t2);

    ///***********     5          ***********///
    unsigned long t3[9];
    montgomery1024Base32(t2,t2,p,m,t3);

    ///***********     6          ***********///
    unsigned long t4[9];
    add(t3,t3,p,t4);
    add(t4,t4,p,t4);

    ///***********     7          ***********///
    unsigned long t5[9];
    montgomery1024Base32(t4,t2,p,m,t5);

    ///***********     8          ***********///
    unsigned long t6[9];
    sub(t1,R.y,p,t6);
    sub(t6,R.y,p,t6);

    ///***********     9          ***********///
    unsigned long t9[9];
    montgomery1024Base32(t6,Q.x,p,m,t9);

    ///***********     10          ***********///
    unsigned long t7[9];
    montgomery1024Base32(t4,R.x,p,m,t7);

    ///***********     11          ***********///
    montgomery1024Base32(t6,t6,p,m,(*T).x);
    sub((*T).x,t5,p,(*T).x);
    sub((*T).x,t7,p,(*T).x);
    sub((*T).x,t7,p,(*T).x);

    ///***********     12          ***********///
    add(R.z,t2,p,(*T).z);
    montgomery1024Base32((*T).z,(*T).z,p,m,(*T).z);
    sub((*T).z,zr2,p,(*T).z);
    sub((*T).z,t3,p,(*T).z);

    ///***********     13          ***********///
    unsigned long t10[9];
    add(Q.y,(*T).z,p,t10);

    ///***********     14          ***********///
    unsigned long t8[9];
    sub(t7,(*T).x,p,t8);
    montgomery1024Base32(t8,t6,p,m,t8);

    ///***********     15          ***********///
    montgomery1024Base32(R.y,t5,p,m,t0);
    add(t0,t0,p,t0);

    ///***********     16          ***********///
    sub(t8,t0,p,(*T).y);


    ///***********     17          ***********///
    ///!!!!!!!!!!!!!!! zt2 == t2 !!!!!!!!!!!!!!!!!!!
    montgomery1024Base32((*T).z,(*T).z,p,m,t2);
    montgomery1024Base32(t10,t10,p,m,t10);
    sub(t10,yq2,p,t10);
    sub(t10,t2,p,t10);

    ///***********     18          ***********///
    add(t9,t9,p,t9);
    ///!!!!!!!!!  affection  l11   !!!!!!!!!
    sub(t9,t10,p,(*l).w0.v0[0]);

    ///***********     19          ***********///
    scalarMulFp2(P.y, (*T).z,(*l).w1.v1);
    ///!!!!!!!!    affectation  l00  !!!!!!!
    addModFp2((*l).w1.v1,(*l).w1.v1,(*l).w1.v1);

    ///***********     20          ***********///
    opp(t6,p,t6);

    ///***********     21          ***********///
    scalarMulFp2(P.x,t6,(*l).w0.v1);
    ///!!!!!!!   affectation l10  !!!!!!!!
    addModFp2((*l).w0.v1,(*l).w0.v1,(*l).w0.v1);

    ///***********     22          ***********///

    ///***********     23          ***********///
    int i,j;

    for(i=0;i<9;i++) (*l).w0.v0[1][i]=0;

    for(j=0;j<2;j++) for(i=0;i<9;i++) (*l).w0.v2[j][i]=0;

    ///***********     23          ***********///
    for(j=0;j<2;j++) for(i=0;i<9;i++) (*l).w1.v0[j][i]=0;
    for(j=0;j<2;j++) for(i=0;i<9;i++) (*l).w1.v2[j][i]=0;
}


void pointDoubLineEval (PointFp2 Q, PointFp P, elemFp12 *l, PointFp2 *T){
    ///***********     1          ***********///
    unsigned long tmp0[2][9];
    doubFp2 (Q.x, tmp0);///1

    ///***********     2          ***********///
    unsigned long tmp1[2][9];
    doubFp2(Q.y, tmp1);///2

    ///***********     3          ***********///
    unsigned long tmp2[2][9];
    doubFp2(tmp1, tmp2);///3

    ///***********     4          ***********///
    unsigned long tmp3[2][9];
    addModFp2(tmp1,Q.x,tmp3);
    doubFp2(tmp3, tmp3);
    subModFp2(tmp3,tmp0,tmp3);
    subModFp2(tmp3,tmp2,tmp3);

    ///***********     5          ***********///
    addModFp2(tmp3,tmp3,tmp3);

    ///***********     6          ***********///
    unsigned long tmp4[2][9];
    addModFp2(tmp0,tmp0,tmp4);
    addModFp2(tmp4,tmp0,tmp4);

    ///***********     7          ***********///
    unsigned long tmp6[2][9];
    addModFp2(tmp4,Q.x, tmp6);

    ///***********     8          ***********///
    unsigned long tmp5[2][9];
    doubFp2(tmp4, tmp5);

    ///***********     9          ***********///
    subModFp2(tmp5,tmp3,(*T).x);
    subModFp2((*T).x,tmp3,(*T).x);

    ///***********     10          ***********///
    unsigned long Zq2[2][9];
    addModFp2(Q.y,Q.z,(*T).z);
    doubFp2((*T).z,(*T).z);
    subModFp2((*T).z,tmp1,(*T).z);
    doubFp2(Q.z,Zq2);
    subModFp2((*T).z,Zq2,(*T).z);

    ///***********     11          ***********///
    addModFp2(tmp2,tmp2,tmp2);
    addModFp2(tmp2,tmp2,tmp2);
    addModFp2(tmp2,tmp2,tmp2);
    subModFp2(tmp3,(*T).x,(*T).y);
    karatsubaFp2((*T).y,tmp4,(*T).y);
    subModFp2((*T).y,tmp2,(*T).y);

    ///***********     12          ***********///
    karatsubaFp2(tmp4,Zq2,tmp3);
    addModFp2(tmp3,tmp3,tmp3);
    oppModFp2(tmp3,tmp3);

    ///***********     13          ***********///
    /// !!!!!!!!  affectation l10  !!!!!!!!!!
    scalarMulFp2(tmp3,P.x,(*l).w1.v0);

    ///***********     14          ***********///
    doubFp2(tmp6,tmp6);
    subModFp2(tmp6,tmp0,tmp6);
    subModFp2(tmp6,tmp5,tmp6);
    addModFp2(tmp1,tmp1,tmp1);
    addModFp2(tmp1,tmp1,tmp1);
    ///!!!!!!!!   affectation l11 !!!!!!!!!!!!
    subModFp2(tmp6,tmp1,(*l).w1.v1);

    ///***********     15          ***********///
    karatsubaFp2((*T).z,Zq2,tmp0);
    addModFp2(tmp0,tmp0,tmp0);

    ///***********     16          ***********///
    ///!!!!!!!!! affectation l00  !!!!!!!!
    scalarMulFp2(tmp0,P.y,(*l).w0.v0);

    ///***********     17          ***********///
    /// a0 six numbers , a1 six numbers

    ///***********     18          ***********///
    unsigned long i,j;
    for(j=0;j<2;j++) for(i=0;i<9;i++) (*l).w0.v1[j][i]=0;
    for(j=0;j<2;j++) for(i=0;i<9;i++) (*l).w0.v2[j][i]=0;

    ///***********     19          ***********///
    for(j=0;j<2;j++) for(i=0;i<9;i++) (*l).w1.v2[j][i]=0;
}


void pointAddLineEval (PointFp2 Q, PointFp2 R, PointFp P, elemFp12 *l, PointFp2 *T){
    ///***********     1          ***********///
    unsigned long t0[2][9], zr2[2][9];
    doubFp2(R.z,zr2);
    karatsubaFp2(Q.x,zr2,t0);

    ///***********     2          ***********///
    unsigned long t1[2][9], yq2[2][9];
    doubFp2(Q.y,yq2);
    addModFp2(Q.y,R.z,t1);
    doubFp2(t1,t1);
    subModFp2(t1,yq2,t1);
    subModFp2(t1,zr2,t1);

    ///***********     3          ***********///
    karatsubaFp2(t1,zr2,t1);

    ///***********     4          ***********///
    unsigned long t2[2][9];
    subModFp2(t0,R.x,t2);

    ///***********     5          ***********///
    unsigned long t3[2][9];
    doubFp2(t2,t3);

    ///***********     6          ***********///
    unsigned long t4[2][9];
    addModFp2(t3,t3,t4);
    addModFp2(t4,t4,t4);

    ///***********     7          ***********///
    unsigned long t5[2][9];
    karatsubaFp2(t4,t2,t5);

    ///***********     8          ***********///
    unsigned long t6[2][9];
    subModFp2(t1,R.y,t6);
    subModFp2(t6,R.y,t6);

    ///***********     9          ***********///
    unsigned long t9[2][9];
    karatsubaFp2(t6,Q.x,t9);

    ///***********     10          ***********///
    unsigned long t7[2][9];
    karatsubaFp2(t4,R.x,t7);

    ///***********     11          ***********///
    doubFp2(t6,(*T).x);
    subModFp2((*T).x,t5,(*T).x);
    subModFp2((*T).x,t7,(*T).x);
    subModFp2((*T).x,t7,(*T).x);

    ///***********     12          ***********///
    addModFp2(R.z,t2,(*T).z);
    doubFp2((*T).z,(*T).z);
    subModFp2((*T).z,zr2,(*T).z);
    subModFp2((*T).z,t3,(*T).z);

    ///***********     13          ***********///
    unsigned long t10[2][9];
    addModFp2(Q.y,(*T).z,t10);

    ///***********     14          ***********///
    unsigned long t8[2][9];
    subModFp2(t7,(*T).x,t8);
    karatsubaFp2(t8,t6,t8);

    ///***********     15          ***********///
    karatsubaFp2(R.y,t5,t0);
    addModFp2(t0,t0,t0);

    ///***********     16          ***********///
    subModFp2(t8,t0,(*T).y);

    ///***********     17          ***********///
    ///!!!!!!!!!!!!!!! zt2 == t2 !!!!!!!!!!!!!!!!!!!
    doubFp2((*T).z,t2);
    doubFp2(t10,t10);
    subModFp2(t10,yq2,t10);
    subModFp2(t10,t2,t10);

    ///***********     18          ***********///
    addModFp2(t9,t9,t9);
    ///!!!!!!!!!  affection  l11   !!!!!!!!!
    subModFp2(t9,t10,(*l).w1.v1);

    ///***********     19          ***********///
    scalarMulFp2((*T).z,P.y,t10);
    ///!!!!!!!!    affectation  l00  !!!!!!!
    addModFp2(t10,t10,(*l).w0.v0);

    ///***********     20          ***********///
    oppModFp2(t6,t6);

    ///***********     21          ***********///
    scalarMulFp2(t6,P.x,t1);
    ///!!!!!!!   affectation l10  !!!!!!!!
    addModFp2(t1,t1,(*l).w1.v0);

    ///***********     22          ***********///

    ///***********     23          ***********///
    int i,j;
    for(j=0;j<2;j++) for(i=0;i<9;i++) (*l).w0.v1[j][i]=0;
    for(j=0;j<2;j++) for(i=0;i<9;i++) (*l).w0.v2[j][i]=0;

    ///***********     23          ***********///
    for(j=0;j<2;j++) for(i=0;i<9;i++) (*l).w1.v2[j][i]=0;
}





void weilE (PointFp P, PointFp2 Q, elemFp12 *f){

    XTmrCtr deley;
    Xuint32 satus=XTmrCtr_Initialize(&deley,0x83c00000); //declaration de l'adresse du timer
    cpt=0;

    XTmrCtr_SetResetValue(&deley,1,0);
    XTmrCtr_Start(&deley,1);

    int i,j;
    elemFp12 l;
    PointFp T;
    affPointFp(P,&T);
    initNulFp12(f);
    setIN(R,(*f).w0.v0[0]);

    for(j=28;j>=0;j--){
    	doubFp12(*f,f);
        pointDoubLineEvalT(T,Q,&l,&T);
        mulFp12(*f,l,f);
        if(getBitIndex(or[7],j)==1){
            pointAddLineEvalT(P,T,Q,&l,&T);
            mulFp12(*f,l,f);
        }
    }
    for(i=6;i>=1;i--){
        for(j=31;j>=0;j--){
        	doubFp12(*f,f);
            pointDoubLineEvalT(T,Q,&l,&T);
            mulFp12(*f,l,f);
            if(getBitIndex(or[i],j)==1){
                pointAddLineEvalT(P,T,Q,&l,&T);
                mulFp12(*f,l,f);
            }
        }
    }
    for(j=31;j>=1;j--){
    	doubFp12(*f,f);
        pointDoubLineEvalT(T,Q,&l,&T);
        mulFp12(*f,l,f);
        if(getBitIndex(or[0],j)==1){
            pointAddLineEvalT(P,T,Q,&l,&T);
            mulFp12(*f,l,f);
        }
    }
    doubFp12(*f,f);
    pointDoubLineEvalT(T,Q,&l,&T);
    mulFp12(*f,l,f);


    elemFp12 f2;
    PointFp2 T2;
    affPointFp2(Q,&T2);
    initNulFp12(&f2);
    setIN(R,f2.w0.v0[0]);

    for(j=28;j>=0;j--){
    	doubFp12(f2,&f2);
        pointDoubLineEval(T2,P,&l,&T2);
        mulFp12(f2,l,&f2);
        if(getBitIndex(or[7],j)==1){
            pointAddLineEval(Q,T2,P,&l,&T2);
            mulFp12(f2,l,&f2);
        }
    }
    for(i=6;i>=1;i--){
        for(j=31;j>=0;j--){
        	doubFp12(f2,&f2);
            pointDoubLineEval(T2,P,&l,&T2);
            mulFp12(f2,l,&f2);
            if(getBitIndex(or[i],j)==1){
                pointAddLineEval(Q,T2,P,&l,&T2);
                mulFp12(f2,l,&f2);
            }
        }
    }
    for(j=31;j>=1;j--){
    	doubFp12(f2,&f2);
        pointDoubLineEval(T2,P,&l,&T2);
        mulFp12(f2,l,&f2);
        if(getBitIndex(or[0],j)==1){
            pointAddLineEval(Q,T2,P,&l,&T2);
            mulFp12(f2,l,&f2);
        }
    }
    doubFp12(f2,&f2);
    pointDoubLineEval(T2,P,&l,&T2);
    mulFp12(f2,l,&f2);

    invFp12(f2,&f2);
    mulFp12(*f,f2,f);

    invFp12(*f,&f2);
    conjugFp12(*f,f);
    mulFp12(*f,f2,f);



    XTmrCtr_Stop(&deley,1);
    cpt=XTmrCtr_GetValue(&deley,1);
    xil_printf(" point : %d\n\r",cpt);

}


