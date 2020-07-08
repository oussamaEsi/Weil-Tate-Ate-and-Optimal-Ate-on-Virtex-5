#include "headers.h"
#include "xtmrctr.h"
#include "xtmrctr_i.h"

int cpt; //Timer

///*********************************  TATE *****************************************///

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

void finalExpo (elemFp12 *f){

    ///************* 1 *********************
    elemFp12 f1;
    conjugFp12(*f,&f1);
    ///************* 2 *********************
    elemFp12 f2;
    invFp12(*f,&f2);
    ///************* 3 *********************
    mulFp12(f1,f2,f);
    ///************* 4 *********************
    elemFp12 ft1;/// Use in 5!!!!!!!!!!!!!!
    frobp2(*f,&ft1);
    mulFp12(ft1,*f,f);
    ///************* 5 *********************
    expTFp12(*f,&ft1);
    ///************* 6 *********************
    elemFp12 ft2;
    expTFp12(ft1,&ft2);
    ///************* 7 *********************
    elemFp12 ft3;
    expTFp12(ft2,&ft3);
    ///************* 8 *********************
    elemFp12 fp1;
    frobp(*f,&fp1);
    ///************* 9 *********************
    elemFp12 fp2;
    frobp(fp1,&fp2);
    ///************* 10 *********************
    elemFp12 fp3;
    frobp(fp2,&fp3);
    ///************* 11 *********************
    elemFp12 y0;
    mulFp12(fp1,fp2,&y0);
    mulFp12(y0,fp3,&y0);
    ///************* 12 *********************
    /// !!!!!!!!!!!!!!!!!!!!!! aatttentionnnnnnn !!!!!!!!!!!!
    elemFp12 y1;
    conjugFp12(*f,&y1);  /// y1 == inv(f)
    ///************* 13 *********************
    elemFp12 y2;
    frobp2(ft2,&y2);
    ///************* 14 *********************
    elemFp12 y3;
    frobp(ft1,&y3);
    ///************* 15 *********************
    conjugFp12(y3,&y3);
    ///************* 16 *********************
    elemFp12 y4;
    frobp(ft2,&y4);
    mulFp12(y4,ft1,&y4);
    ///************* 17 *********************
    conjugFp12(y4,&y4);
    ///************* 18 *********************
    elemFp12 y5;
    conjugFp12(ft2,&y5);
    ///************* 19 *********************
    elemFp12 y6;
    frobp(ft3,&y6);
    mulFp12(y6,ft3,&y6);
    ///************* 20 *********************
    conjugFp12(y6,&y6);
    ///************* 21 *********************
    elemFp12 t0;
    doubFp12(y6,&t0);
    mulFp12(t0,y4,&t0);
    mulFp12(t0,y5,&t0);
    ///************* 22 *********************
    elemFp12 t1;
    mulFp12(y3,y5,&t1);
    mulFp12(t1,t0,&t1);
    ///************* 23 *********************
    mulFp12(t0,y2,&t0);
    ///************* 24 *********************
    doubFp12(t1,&t1);
    mulFp12(t1,t0,&t1);
    doubFp12(t1,&t1);
    ///************* 25 *********************
    mulFp12(t1,y1,&t0); /// y1 == inv(f)
    ///************* 26 *********************
    mulFp12(t1,y0,&t1);
    ///************* 27 *********************
    doubFp12(t0,&t0);
    ///************* 28 *********************
    mulFp12(t1,t0,f);

}


void tate (PointFp P, PointFp2 Q, elemFp12 *f) {

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

    for(i=6;i>=0;i--){
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


    XTmrCtr_Stop(&deley,1);
    cpt=XTmrCtr_GetValue(&deley,1);
    xil_printf(" point : %d\n\r",cpt);


    finalExpo(f);



}
