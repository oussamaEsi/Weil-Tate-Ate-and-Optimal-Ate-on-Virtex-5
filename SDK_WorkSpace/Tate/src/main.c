#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "headers.h"



void initNul (unsigned long a[9]){
    unsigned long i;
    for(i=0;i<9;i++) a[i]=0;
}

void initNul2D(unsigned long a[][9] , unsigned long nbL , unsigned long nbC){
    unsigned long i,j;
    for(i=0;i<nbL;i++)
        for(j=0;j<nbC;j++) a[i][j]=0;
}

void PRINT(unsigned long *c){
    unsigned long i;
    printf("aff: \n");
    for(i=0;i<9;i++){
            printf("%lu ",c[i]);
    }
    printf("\n");
}

void PRINTHex(unsigned long *c){
    unsigned long i;
    printf("aff: \n");
    for(i=0;i<9;i++){
            printf("%08lx ",c[8-i]);
    }
    printf("\n");
}

void PRINT2D(unsigned long c[][9],unsigned long k){
    unsigned long i,j;
    printf("Pol: \n");
    fflush(stdout);
    for(i=0;i<k;i++){
            for(j=0;j<9;j++){
                    printf("%lu ",c[i][8-j]);//printf("%08x ",c[i][j]);
                    fflush(stdout);
            }
    printf("\n");
    }
    printf("\n");
}

void PRINTHex2D(unsigned long c[][9],unsigned long k){
    unsigned long i,j;
    printf("Pol: \n");
    fflush(stdout);
    for(i=0;i<k;i++){

            for(j=0;j<9;j++){
                    printf("%08lx ",c[i][8-j]);//printf("%08x ",c[i][j]);
                    fflush(stdout);
            }
    printf("\n");
    }
    printf("\n");
}


void transfMongPol (unsigned long A[][9],unsigned long k){
    int i;
    for(i=0;i<k;i++) montgomery1024Base32( A[i], R2, p, m, A[i]);
}

void invTransMongPol (unsigned long A[][9] ,unsigned long B[][9], unsigned long k){
    unsigned long i;
    for(i=0;i<k;i++) montgomery1024Base32( A[i], UN, p, m, B[i]);
}

void invMontgm (unsigned long A[9], unsigned long B[9]){
    montgomery1024Base32(A,UN,p,m,B);
}

int indLastBit (unsigned long a[], unsigned long L, unsigned long lastBit[2]){
    int i,j;
    for(i=L-1;i>=0;i--){
            for(j=31;j>=0;j--){
            if(getBitIndex(a[i],j)==1) goto finish;
        }
    }
    finish:
    lastBit[0]=i; lastBit[1]=j;
    return(i*32+j);
}

int main() {


  /// 2370fb04 9d410fbe 4e761a98 86e50241 7d023f40 18000001 7e806000 00000001
  p[0]=1;
  p[1]=0x7e806000;
  p[2]=0x18000001;
  p[3]=0x7d023f40;
  p[4]=0x86e50241;
  p[5]=0x4e761a98;
  p[6]=0x9d410fbe;
  p[7]=0x2370fb04;
  p[8]=0;

  m=0xffffffff;

  /// 20586450 8ffae3b9 ac8ae3e2 c465f114 9e563912 251d0a57 b373bff8 c6dc068a
  R[0]=0xc6dc068a;
  R[1]=0xb373bff8;
  R[2]=0x251d0a57;
  R[3]=0x9e563912;
  R[4]=0xc465f114;
  R[5]=0xac8ae3e2;
  R[6]=0x8ffae3b9;
  R[7]=0x20586450;
  R[8]=0;

  /// 205ebc6 14cbee97 27941620 596d1c6b 2d6bf940 7035bb4b 4c7fb319 27a43416
  R2[0]=0x27a43416;
  R2[1]=0x4c7fb319;
  R2[2]=0x7035bb4b;
  R2[3]=0x2d6bf940;
  R2[4]=0x596d1c6b;
  R2[5]=0x27941620;
  R2[6]=0x14cbee97;
  R2[7]=0x205ebc6;
  R2[8]=0;

  initNul(UN);
  UN[0]=1;

  initNul(redFp);
  redFp[0]=5;
  sub(p,redFp,p,redFp);


  sub(p,UN,p,p_2);
  sub(p_2,UN,p,p_2);

  /// 2370fb04 9d410fbe 4e761a98 86e50241 1dc1af70 12000001 7e806000 00000001
  or[0]=0x00000001;
  or[1]=0x7e806000;
  or[2]=0x12000001;
  or[3]=0x1dc1af70;
  or[4]=0x86e50241;
  or[5]=0x4e761a98;
  or[6]=0x9d410fbe;
  or[7]=0x2370fb04;
  or[8]=0;

  /// 2f414eb 0d1ac14f dbdf2ce2 0b3dc030 1fc02ff0 02000000 1fe00800 00000000

  p_1d12[0]=0x00000000;
  p_1d12[1]=0x1fe00800;
  p_1d12[2]=0x02000000;
  p_1d12[3]=0x1fc02ff0;
  p_1d12[4]=0x0b3dc030;
  p_1d12[5]=0xdbdf2ce2;
  p_1d12[6]=0x0d1ac14f;
  p_1d12[7]=0x2f414eb;
  p_1d12[8]=0;

  /// 3fc01000 00000000
  t[0] = 0;
  t[1] = 0x3fc01000;

  /// 1 7e806000 00000002
  s[0]=2;
  s[1]=0x7e806000;
  /// s[2]=1;

  /// 5f408fd0 06000000 00000000 00000000
  tr_1[0]=0x00000000;
  tr_1[1]=0x00000000;
  tr_1[2]=0x06000000;
  tr_1[3]=0x5f408fd0;

    PointFp P;
    PointFp2 Q,S;
    /// **************************  Q  ****************
    /// **************************   Q.x  ********************
    /// 19B0BEA4 AFE4C330 DA93CC35 33DA38A9 F430B471 C6F8A536 E81962ED 967909B5
    Q.x[0][8]=0;
    Q.x[0][7]=0x19B0BEA4;
    Q.x[0][6]=0xAFE4C330;
    Q.x[0][5]=0xDA93CC35;
    Q.x[0][4]=0x33DA38A9;
    Q.x[0][3]=0xF430B471;
    Q.x[0][2]=0xC6F8A536;
    Q.x[0][1]=0xE81962ED;
    Q.x[0][0]=0x967909B5;

    /// A1CF585 585A61C6 E9880B1F 2A5C539F 7D906FFF 238FA634 1E1DE1A2 E45C3F72
    Q.x[1][8]=0;
    Q.x[1][7]=0xA1CF585;
    Q.x[1][6]=0x585A61C6;
    Q.x[1][5]=0xE9880B1F;
    Q.x[1][4]=0x2A5C539F;
    Q.x[1][3]=0x7D906FFF;
    Q.x[1][2]=0x238FA634;
    Q.x[1][1]=0x1E1DE1A2;
    Q.x[1][0]=0xE45C3F72;

    /// ************************  Q.y   ********************
    /// 17ABD366 EBBD6533 3E49C711 A80A0CF6 D24ADF1B 9B3990EE DCC91731 384D2627
    Q.y[0][8]=0;
    Q.y[0][7]=0x17ABD366;
    Q.y[0][6]=0xEBBD6533;
    Q.y[0][5]=0x3E49C711;
    Q.y[0][4]=0xA80A0CF6;
    Q.y[0][3]=0xD24ADF1B;
    Q.y[0][2]=0x9B3990EE;
    Q.y[0][1]=0xDCC91731;
    Q.y[0][0]=0x384D2627;

    ///  EE97D6D E9902A27 D00E9522 32A78700 863BC9AA 9BE960C3 2F5BF9FD 0A32D345
    Q.y[1][8]=0;
    Q.y[1][7]=0xEE97D6D;
    Q.y[1][6]=0xE9902A27;
    Q.y[1][5]=0xD00E9522;
    Q.y[1][4]=0x32A78700;
    Q.y[1][3]=0x863BC9AA;
    Q.y[1][2]=0x9BE960C3;
    Q.y[1][1]=0x2F5BF9FD;
    Q.y[1][0]=0x0A32D345;

    /// ***********************  Q.z   ***********************
    initNul2D(Q.z,2,9);
    Q.z[0][0]=1;


    ///*************************   S   ***************************
    ///************************   S.x  ***************************
    ///  42b372c aea10d58 9d770610 4375146e 516c81e0 635a81de 07d68681 bbcf3e47
    S.x[0][8]=0;
    S.x[0][7]=0x42b372c;
    S.x[0][6]=0xaea10d58;
    S.x[0][5]=0x9d770610;
    S.x[0][4]=0x4375146e;
    S.x[0][3]=0x516c81e0;
    S.x[0][2]=0x635a81de;
    S.x[0][1]=0x07d68681;
    S.x[0][0]=0xbbcf3e47;

    /// 1764493a 1277fb89 bdfd9bff 3a1cb9b4 030ddf45 0c939ddc 6c1d3bdd 656cad66
    S.x[1][8]=0;
    S.x[1][7]=0x1764493a;
    S.x[1][6]=0x1277fb89;
    S.x[1][5]=0xbdfd9bff;
    S.x[1][4]=0x3a1cb9b4;
    S.x[1][3]=0x030ddf45;
    S.x[1][2]=0x0c939ddc;
    S.x[1][1]=0x6c1d3bdd;
    S.x[1][0]=0x656cad66;

    ///*************************  S.y  *************************
    /// 1debae11 b1fd080b a5f8442c fe5fc305 76763fc6 22a0d3e2 1418d141 d0a4d913
    S.y[0][8]=0;
    S.y[0][7]=0x1debae11;
    S.y[0][6]=0xb1fd080b;
    S.y[0][5]=0xa5f8442c;
    S.y[0][4]=0xfe5fc305;
    S.y[0][3]=0x76763fc6;
    S.y[0][2]=0x22a0d3e2;
    S.y[0][1]=0x1418d141;
    S.y[0][0]=0xd0a4d913;

    ///  6067889 0b52d64d 69fa00bd d617a6fb 5b599beb 2b14d458 7c3bab64 0dd05731
    S.y[1][8]=0;
    S.y[1][7]=0x6067889;
    S.y[1][6]=0x0b52d64d;
    S.y[1][5]=0x69fa00bd;
    S.y[1][4]=0xd617a6fb;
    S.y[1][3]=0x5b599beb;
    S.y[1][2]=0x2b14d458;
    S.y[1][1]=0x7c3bab64;
    S.y[1][0]=0x0dd05731;

    /// ************************ S.z   ********************************
    /// 197873ba d41eb318 c84b1bc3 bb24898b d6fd2889 eb591121 ed66b68c d3718353
    S.z[0][8]=0;
    S.z[0][7]=0x197873ba;
    S.z[0][6]=0xd41eb318;
    S.z[0][5]=0xc84b1bc3;
    S.z[0][4]=0xbb24898b;
    S.z[0][3]=0xd6fd2889;
    S.z[0][2]=0xeb591121;
    S.z[0][1]=0xed66b68c;
    S.z[0][0]=0xd3718353;

    /// 1cb1c93f 9fefc51c d9a31e77 4b8f2e03 f2aeceac ca73323f c1bdfb95 2b3c175b
    S.z[1][8]=0;
    S.z[1][7]=0x1cb1c93f;
    S.z[1][6]=0x9fefc51c;
    S.z[1][5]=0xd9a31e77;
    S.z[1][4]=0x4b8f2e03;
    S.z[1][3]=0xf2aeceac;
    S.z[1][2]=0xca73323f;
    S.z[1][1]=0xc1bdfb95;
    S.z[1][0]=0x2b3c175b;


    ///**********************  P ******************
    ///********************* P.x  ***********************
    initNul(P.x);
    P.x[0]=1;

    ///********************* P.y  ***********************
    ///  d45589b 158faaf6 ab0e4ad3 8d998e99 82e7ff63 964ee146 0342a592 677cccb0
    P.y[8]=0;
    P.y[7]=0xd45589b;
    P.y[6]=0x158faaf6;
    P.y[5]=0xab0e4ad3;
    P.y[4]=0x8d998e99;
    P.y[3]=0x82e7ff63;
    P.y[2]=0x964ee146;
    P.y[1]=0x0342a592;
    P.y[0]=0x677cccb0;

    initNul(P.z);
    P.z[0]=1;

    P.isInfinity = 0;

    montgomery1024Base32(redFp,R2,p,m,redFp);

    elemFp12 w;
    initNulFp12(&w);
    setIN(R,w.w1.v0[0]);
    invFp12(w,&w);
    doubFp12(w,&w_2);
    mulFp12(w_2,w,&w_3);

    expoFp(redFp,p_1d12,sig1);
    montgomery1024Base32(sig1,sig1,p,m,sig2);
    montgomery1024Base32(sig2,sig1,p,m,sig3);
    montgomery1024Base32(sig3,sig1,p,m,sig4);
    montgomery1024Base32(sig4,sig1,p,m,sig5);

    montgomery1024Base32(sig1,sig1,p,m,sig11);
    montgomery1024Base32(sig2,sig2,p,m,sig22);
    montgomery1024Base32(sig3,sig3,p,m,sig33);
    montgomery1024Base32(sig4,sig4,p,m,sig44);
    montgomery1024Base32(sig5,sig5,p,m,sig55);

    unsigned long coeff[9]={0};
    coeff[0]=0x12456987;
    coeff[1]=0xa2456987;
    coeff[2]=0x12b5641d;
    coeff[3]=0x9342a592;
    elemFp12 f,f2,f3;
    PointFp P1,P2;
    PointFp2 T;

    transfMongPointFp2(&Q);
    transfMongPointFp2(&S);
    transfMongPointFp(&P);


    //tateAfine(P,Q,&f);
    tate(Q,P,&f);

    invTransMongFp12(f,&f);
    //invTransMongFp12(f2,&f2);
    //invTransMongFp12(f3,&f3);

    printHexFp12(f);
    //printHexFp12(f2);
    //printHexFp12(f3);*/

    return 0;
}
