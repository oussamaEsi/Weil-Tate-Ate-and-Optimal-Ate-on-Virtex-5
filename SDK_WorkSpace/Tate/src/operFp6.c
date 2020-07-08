#include "headers.h"

void initNulFp6 (elemFp6 *a){
    initNulFp2((*a).v0);
    initNulFp2((*a).v1);
    initNulFp2((*a).v2);
}

void affectFp6 (elemFp6 a, elemFp6 *b){
    affectFp2(a.v0,(*b).v0);
    affectFp2(a.v1,(*b).v1);
    affectFp2(a.v2,(*b).v2);
}

void addFp6 (elemFp6 a, elemFp6 b, elemFp6 *res){
    addModFp2(a.v0,b.v0,(*res).v0);
    addModFp2(a.v1,b.v1,(*res).v1);
    addModFp2(a.v2,b.v2,(*res).v2);
}

void subFp6 (elemFp6 a, elemFp6 b, elemFp6 *res){
    subModFp2(a.v0,b.v0,(*res).v0);
    subModFp2(a.v1,b.v1,(*res).v1);
    subModFp2(a.v2,b.v2,(*res).v2);
}

void oppFp6(elemFp6 a, elemFp6 *oa){
    oppModFp2(a.v0,(*oa).v0);
    oppModFp2(a.v1,(*oa).v1);
    oppModFp2(a.v2,(*oa).v2);
}

void mulXFp6(elemFp6 a , elemFp6 *res){
    unsigned long c0[2][9];
    //karatsubaFp2(a.v2,redFp2,c0);
    mulXFp2(a.v2,c0);
    affectFp2(a.v1,(*res).v2);
    affectFp2(a.v0,(*res).v1);
    affectFp2(c0,(*res).v0);
}

void mulFp6 (elemFp6 a, elemFp6 b, elemFp6 *res){

    ///**** ************* 1 2 3 *****************
    unsigned long t0[2][9],t1[2][9],t2[2][9];
    karatsubaFp2(a.v0,b.v0,t0);
    karatsubaFp2(a.v1,b.v1,t1);
    karatsubaFp2(a.v2,b.v2,t2);

    unsigned long temp[2][9],temp0[2][9];
    ///***************** 4 *****************
    addModFp2(b.v1,b.v2,temp);
    addModFp2(a.v1,a.v2,temp0);
    karatsubaFp2(temp0,temp,temp0);
    subModFp2(temp0,t1,temp0);
    subModFp2(temp0,t2,temp0);
    //karatsubaFp2(temp0,redFp2,temp0);
    mulXFp2(temp0,temp0);
    addModFp2(temp0,t0,temp0);

    ///***************** 5 *****************
    addModFp2( b.v0,b.v1,temp);
    addModFp2(a.v0,a.v1,(*res).v1);
    karatsubaFp2((*res).v1,temp,(*res).v1);
    subModFp2((*res).v1,t0,(*res).v1);
    subModFp2((*res).v1,t1,(*res).v1);
    //karatsubaFp2(t2,redFp2,temp);
    mulXFp2(t2,temp);
    addModFp2((*res).v1,temp,(*res).v1);

    ///***************** 6 *****************
    addModFp2(b.v0,b.v2,temp);
    addModFp2(a.v0,a.v2,(*res).v2);
    karatsubaFp2((*res).v2,temp,(*res).v2);
    subModFp2((*res).v2,t0,(*res).v2);
    subModFp2((*res).v2,t2,(*res).v2);
    addModFp2((*res).v2,t1,(*res).v2);

    ///******************7****************
    affectFp2(temp0,(*res).v0);
}

void doubFp6 (elemFp6 a, elemFp6 *res){
    unsigned long t0[2][9],t1[2][9],t2[2][9],t3[2][9];
    doubFp2(a.v0,t0);
    doubFp2(a.v2,t1);
    karatsubaFp2(a.v0,a.v1,t2);
    addModFp2(t2,t2,t2);
    karatsubaFp2(a.v1,a.v2,t3);
    addModFp2(t3,t3,t3);

    addModFp2(a.v0,a.v2,(*res).v2);
    subModFp2((*res).v2,a.v1,(*res).v2);
    doubFp2((*res).v2,(*res).v2);

    mulXFp2(t3,(*res).v0);
    addModFp2((*res).v0,t0,(*res).v0);

    mulXFp2(t1,(*res).v1);
    addModFp2((*res).v1,t2,(*res).v1);

    subModFp2((*res).v2,t0,(*res).v2);
    subModFp2((*res).v2,t1,(*res).v2);
    addModFp2((*res).v2,t2,(*res).v2);
    addModFp2((*res).v2,t3,(*res).v2);
}

void invFp6(elemFp6 a, elemFp6 *invA){
    ///**************** 1 **********************
    unsigned long t0[2][9];
    doubFp2(a.v0,t0);

    ///**************** 2 **********************
    unsigned long t1[2][9];
    doubFp2(a.v1,t1);

    ///**************** 3 **********************
    unsigned long t2[2][9];
    doubFp2(a.v2,t2);

    ///**************** 4 **********************
    unsigned long t3[2][9];
    karatsubaFp2(a.v0,a.v1,t3);

    ///**************** 5 **********************
    unsigned long t4[2][9];
    karatsubaFp2(a.v0,a.v2,t4);

    ///**************** 6 **********************
    unsigned long t5[2][9];///!!!!!!!!!!!!! ERROOOOORRRR !!!!!!!!!!!!!
    karatsubaFp2(a.v2,a.v1,t5);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    ///**************** 7 **********************
    ///   !!!!    c0 == t5 !!!!
    mulXFp2(t5,t5);
    subModFp2(t0,t5,t5);

    ///**************** 8 **********************
    ///   !!!!!   c1 == t2!!!!!!
    mulXFp2(t2,t2);
    subModFp2(t2,t3,t2);

    ///**************** 9 **********************
    ///   !!!!!    c2 == t1 !!!!!!!!!
    subModFp2(t1,t4,t1);

    ///**************** 10 **********************
    unsigned long t6[2][9];
    karatsubaFp2(a.v0,t5,t6);///  a0*c0

    ///**************** 11 **********************
    /// !!!   t0 == temporary variable !!!
    karatsubaFp2(a.v2,t2,t0);/// t0 = a2*c1
    mulXFp2(t0,t0);
    addModFp2(t6,t0,t6);

    ///**************** 12 **********************
    /// !!!   t0 == temporary variable !!!
    karatsubaFp2(a.v1,t1,t0);
    mulXFp2(t0,t0);
    addModFp2(t6,t0,t6);

    ///**************** 13 **********************
    invFp2(t6,t6);

    ///**************** 14  15 16 **********************
    karatsubaFp2(t5,t6,(*invA).v0);
    karatsubaFp2(t2,t6,(*invA).v1);
    karatsubaFp2(t1,t6,(*invA).v2);
}
