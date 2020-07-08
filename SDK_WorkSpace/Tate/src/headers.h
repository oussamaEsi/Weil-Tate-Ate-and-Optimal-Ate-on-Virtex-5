#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED


  unsigned long UN[9];
  unsigned long m;//N(-1)
  unsigned long p[9];
  unsigned long or[9];//ordre
  unsigned long tr_1[9];//T=tr - 1
  unsigned long p_2[9];
  unsigned long p_1d12[9];
  unsigned long R[9];
  unsigned long R2[9];
  //unsigned long InvR[9];
  unsigned long redFp[9];///!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  //unsigned long redFp2[2][9];///!!!!!!!!!!!!!!!!!!!!!!!!!!!
  unsigned long t[2];
  unsigned long s[2];
  unsigned long L;

  unsigned long sig1[9],sig2[9],sig3[9],sig4[9],sig5[9];
  unsigned long sig11[9],sig22[9],sig33[9],sig44[9],sig55[9];



typedef struct PointFp2{
    unsigned long x[2][9];
    unsigned long y[2][9];
    unsigned long z[2][9];
} PointFp2;

typedef struct PointFp{
    unsigned long x[9];
    unsigned long y[9];
    unsigned long z[9];
    int isInfinity;
} PointFp;

typedef struct elemFp6{
    unsigned long v0[2][9];
    unsigned long v1[2][9];
    unsigned long v2[2][9];
}elemFp6;

typedef struct elemFp12{
    elemFp6 w0;
    elemFp6 w1;
}elemFp12;

typedef struct PointFp12{
    elemFp12 x;
    elemFp12 y;
    int isInfinity;
}PointFp12;


elemFp12 w_2,w_3;

#endif // HEADERS_H_INCLUDED
