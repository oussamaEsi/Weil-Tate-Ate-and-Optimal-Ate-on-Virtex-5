#include <stdio.h>
#include "headers.h"


int main() {

	nbA=0; nbS=0; nbMC=0; nbR=0; nbM=0; nbSq=0; nbInv=0;
    nbExpT=0; nbFrob_p=0; nbFrob_p2=0; nbDB=0; nbAD=0;
    nbSq_b0=0; nbSq_b0b1=0;


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
	subFp(p,redFp,p,redFp); //redFp = -5

	subFp(p,UN,p,p_2);
	subFp(p_2,UN,p,p_2); // p-2

	/// 3fc01000 00000000
	t[0] = 0;
	t[1] = 0x3fc01000;

	/// 1 7e806000 00000002
	s[0] = 2;
	s[1] = 0x7e806000;
	/// s[2]=1;

	/// y1i
	/// bf9d596 17679d84 765b517a e4e5f422 9a8932f9 b1b3e4ff 3cae1133 5a6abeb2
	y11[0]=0x5a6abeb2;
	y11[1]=0x3cae1133;
	y11[2]=0xb1b3e4ff;
	y11[3]=0x9a8932f9;
	y11[4]=0xe4e5f422;
	y11[5]=0x765b517a;
	y11[6]=0x17679d84;
	y11[7]=0xbf9d596;
	y11[8]=0;

	/// 2370fb04 9d410fbe 074d0d4c 43728120 5f408fd0 05ffffff 40bfd000 00000000
	y12[0]=0;
	y12[1]=0x40bfd000;
	y12[2]=0x5ffffff;
	y12[3]=0x5f408fd0;
	y12[4]=0x43728120;
	y12[5]=0x74d0d4c;
	y12[6]=0x9d410fbe;
	y12[7]=0x2370fb04;
	y12[8]=0;

	///a6a1689 91bf611a 1a4dba88 bb5c4b1a 96e9f833 6a4488b4 64d5aa9b 1e46a58e
	y13[0]=0x1e46a58e;
	y13[1]=0x64d5aa9b;
	y13[2]=0x6a4488b4;
	y13[3]=0x96e9f833;
	y13[4]=0xbb5c4b1a;
	y13[5]=0x1a4dba88;
	y13[6]=0x91bf611a;
	y13[7]=0xa6a1689;
	y13[8]=0;

	/// 2370fb04 9d410fbe 074d0d4c 43728120 5f408fd0 05ffffff 40bfcfff ffffffff
	y14[0]=0xffffffff;
	y14[1]=0x40bfcfff;
	y14[2]=0x5ffffff;
	y14[3]=0x5f408fd0;
	y14[4]=0x43728120;
	y14[5]=0x74d0d4c;
	y14[6]=0x9d410fbe;
	y14[7]=0x2370fb04;
	y14[8]=0;

	/// 21e13bf8 1798d353 f26883a6 5d5b5939 79630479 d090a3b6 a6a7f967 c3dbe6dd
	y15[0]=0xc3dbe6dd;
	y15[1]=0xa6a7f967;
	y15[2]=0xd090a3b6;
	y15[3]=0x79630479;
	y15[4]=0x5d5b5939;
	y15[5]=0xf26883a6;
	y15[6]=0x1798d353;
	y15[7]=0x21e13bf8;
	y15[8]=0;

	/// y2i
	/// 2370fb04 9d410fbe 074d0d4c 43728120 5f408fd0 05ffffff 40bfd000 00000000
	y21[0]=0;
	y21[1]=0x40bfd000;
	y21[2]=0x5ffffff;
	y21[3]=0x5f408fd0;
	y21[4]=0x43728120;
	y21[5]=0x74d0d4c;
	y21[6]=0x9d410fbe;
	y21[7]=0x2370fb04;
	y21[8]=0;

	/// 2370fb04 9d410fbe 074d0d4c 43728120 5f408fd0 05ffffff 40bfcfff ffffffff
	y22[0]=0xffffffff;
	y22[1]=0x40bfcfff;
	y22[2]=0x5ffffff;
	y22[3]=0x5f408fd0;
	y22[4]=0x43728120;
	y22[5]=0x74d0d4c;
	y22[6]=0x9d410fbe;
	y22[7]=0x2370fb04;
	y22[8]=0;

	/// 2370fb04 9d410fbe 4e761a98 86e50241 7d023f40 18000001 7e806000 00000000
	y23[0]=0;
	y23[1]=0x7e806000;
	y23[2]=0x18000001;
	y23[3]=0x7d023f40;
	y23[4]=0x86e50241;
	y23[5]=0x4e761a98;
	y23[6]=0x9d410fbe;
	y23[7]=0x2370fb04;
	y23[8]=0;

	/// 47290d4c 43728121 1dc1af70 12000002 3dc09000 00000001
	y24[0]=0x1;
	y24[1]=0x3dc09000;
	y24[2]=0x12000002;
	y24[3]=0x1dc1af70;
	y24[4]=0x43728121;
	y24[5]=0x47290d4c;
	y24[6]=0;
	y24[7]=0;
	y24[8]=0;

	/// 47290d4c 43728121 1dc1af70 12000002 3dc09000 00000002
	y25[0]=0x2;
	y25[1]=0x3dc09000;
	y25[2]=0x12000002;
	y25[3]=0x1dc1af70;
	y25[4]=0x43728121;
	y25[5]=0x47290d4c;
	y25[6]=0;
	y25[7]=0;
	y25[8]=0;



	// Entrer les parametres dans le domaine Montgomery
	montgomery(redFp,R2,p,m,redFp);

	montgomery(y11,R2,p,m,y11);
	montgomery(y12,R2,p,m,y12);
	montgomery(y13,R2,p,m,y13);
	montgomery(y14,R2,p,m,y14);
	montgomery(y15,R2,p,m,y15);

	montgomery(y21,R2,p,m,y21);
	montgomery(y22,R2,p,m,y22);
	montgomery(y23,R2,p,m,y23);
	montgomery(y24,R2,p,m,y24);
	montgomery(y25,R2,p,m,y25);



    /// **************************  Q  ****************
    PointFp2 Q;
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


    ///**********************  P ******************
    PointFp P;
    ///********************* P.x = 1  ***********************
    initNul(P.x);
    P.x[0]=1;

    ///********************* P.y = racine(6)  **********************
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

    P.isInfinity = 0;


    elemFp12 f;
    transfMongPointFp2(&Q);
    transfMongPointFp(&P);

    optAte(Q,P,&f);

    invTransMongFp12(f,&f);
    printHexFp12(f);


    printf(" nbA = : %d\n\r",nbA);
    printf(" nbS = : %d\n\r",nbS);
    printf(" nbMC = : %d\n\r",nbMC);
    printf(" nbR = : %d\n\r",nbR);
    printf(" nbM = : %d\n\r",nbM);
    printf(" nbSq = : %d\n\r",nbSq);
    printf(" nbInv = : %d\n\r",nbInv);

    printf(" nbSq_b0 = : %d\n\r",nbSq_b0);
    printf(" nbSq_b0b1 = : %d\n\r",nbSq_b0b1);

    printf(" nbExpT = : %d\n\r",nbExpT);
    printf(" nbFrob_p = : %d\n\r",nbFrob_p);
    printf(" nbFrob_p2 = : %d\n\r",nbFrob_p2);
    printf(" nbDB = : %d\n\r",nbDB);
    printf(" nbAD = : %d\n\r",nbAD);


    return 0;
}

/*
    elemFp6 f;
    f.v0[0][0]=0xc74240f4;
    f.v0[0][1]=0xb27617a6;
    f.v0[0][2]=0x76a85a41;
    f.v0[0][3]=0x8425499f;
    f.v0[0][4]=0xb2de700b;
    f.v0[0][5]=0x7d4a6a47;
    f.v0[0][6]=0x1c559aef;
    f.v0[0][7]=0x1787ec56;
    f.v0[0][8]=0;

    f.v0[1][0]=0x6dd05ab9;
    f.v0[1][1]=0x1020bead;
    f.v0[1][2]=0xe4a86986;
    f.v0[1][3]=0xc68249e1;
    f.v0[1][4]=0xa8c23baf;
    f.v0[1][5]=0x5b1b6581;
    f.v0[1][6]=0xc99f87fa;
    f.v0[1][7]=0x3f8b3f4;
    f.v0[1][8]=0;

    f.v1[0][0]=0x3e08cd66;
    f.v1[0][1]=0x62ca4f34;
    f.v1[0][2]=0xb7de31;
    f.v1[0][3]=0xb9d2555a;
    f.v1[0][4]=0x9bdbfed2;
    f.v1[0][5]=0x4b057470;
    f.v1[0][6]=0x42f10a5a;
    f.v1[0][7]=0x9ccf2b6;
    f.v1[0][8]=0;

    f.v1[1][0]=0x6bfe3f99;
    f.v1[1][1]=0x94663226;
    f.v1[1][2]=0xc19562ab;
    f.v1[1][3]=0x466a64cb;
    f.v1[1][4]=0xa7a14591;
    f.v1[1][5]=0x84976f58;
    f.v1[1][6]=0x262e12ba;
    f.v1[1][7]=0x1786b8cb;
    f.v1[1][8]=0;

    f.v2[0][0]=0x6f2eb591;
    f.v2[0][1]=0xea0d90ed;
    f.v2[0][2]=0xbec4f266;
    f.v2[0][3]=0xcba7de8d;
    f.v2[0][4]=0x4f51ff12;
    f.v2[0][5]=0xb88fa26;
    f.v2[0][6]=0x3fcc9f58;
    f.v2[0][7]=0x19ec8610;
    f.v2[0][8]=0;

    f.v2[1][0]=0xd204d702;
    f.v2[1][1]=0xa58f39f;
    f.v2[1][2]=0x9e6a83d0;
    f.v2[1][3]=0x55502206;
    f.v2[1][4]=0x2d952946;
    f.v2[1][5]=0x3023689e;
    f.v2[1][6]=0x4246f3d5;
    f.v2[1][7]=0x17ab027;
    f.v2[1][8]=0;

    unsigned long b0[2][9];

    b0[0][0]=0xbb026f2d;
    b0[0][1]=0x7bcad0cb;
    b0[0][2]=0xf6ccbdf2;
    b0[0][3]=0x56225b13;
    b0[0][4]=0x24d6ab27;
    b0[0][5]=0xe5159a7e;
    b0[0][6]=0xc3171f89;
    b0[0][7]=0x20a99bfb;
    b0[0][8]=0;

    b0[1][0]=0xba691ffa;
    b0[1][1]=0xc8e73436;
    b0[1][2]=0xf65caf44;
    b0[1][3]=0xa09e23f7;
    b0[1][4]=0xb0b75dfa;
    b0[1][5]=0xb5ba3d35;
    b0[1][6]=0x7786559f;
    b0[1][7]=0xe9087c3;
    b0[1][8]=0;

    unsigned long b1[2][9];

    b1[0][0]=0x3b895762;
    b1[0][1]=0x9d6bb902;
    b1[0][2]=0x6586ce02;
    b1[0][3]=0x1047f994;
    b1[0][4]=0x16322ffd;
    b1[0][5]=0x702068e7;
    b1[0][6]=0x4e53db19;
    b1[0][7]=0x776c240;
    b1[0][8]=0;

    b1[1][0]=0x76dd1070;
    b1[1][1]=0xeb2675ba;
    b1[1][2]=0x5c2400d7;
    b1[1][3]=0xf72603c0;
    b1[1][4]=0xc2e95f76;
    b1[1][5]=0x3d69f644;
    b1[1][6]=0x25815a57;
    b1[1][7]=0xc4e3f54;
    b1[1][8]=0;
*/

/*
    elemFp12 f;
    f.w0.v0[0][0]=0xc74240f4;
    f.w0.v0[0][1]=0xb27617a6;
    f.w0.v0[0][2]=0x76a85a41;
    f.w0.v0[0][3]=0x8425499f;
    f.w0.v0[0][4]=0xb2de700b;
    f.w0.v0[0][5]=0x7d4a6a47;
    f.w0.v0[0][6]=0x1c559aef;
    f.w0.v0[0][7]=0x1787ec56;
    f.w0.v0[0][8]=0;

    f.w0.v0[1][0]=0x6dd05ab9;
    f.w0.v0[1][1]=0x1020bead;
    f.w0.v0[1][2]=0xe4a86986;
    f.w0.v0[1][3]=0xc68249e1;
    f.w0.v0[1][4]=0xa8c23baf;
    f.w0.v0[1][5]=0x5b1b6581;
    f.w0.v0[1][6]=0xc99f87fa;
    f.w0.v0[1][7]=0x3f8b3f4;
    f.w0.v0[1][8]=0;

    f.w0.v1[0][0]=0x3e08cd66;
    f.w0.v1[0][1]=0x62ca4f34;
    f.w0.v1[0][2]=0xb7de31;
    f.w0.v1[0][3]=0xb9d2555a;
    f.w0.v1[0][4]=0x9bdbfed2;
    f.w0.v1[0][5]=0x4b057470;
    f.w0.v1[0][6]=0x42f10a5a;
    f.w0.v1[0][7]=0x9ccf2b6;
    f.w0.v1[0][8]=0;

    f.w0.v1[1][0]=0x6bfe3f99;
    f.w0.v1[1][1]=0x94663226;
    f.w0.v1[1][2]=0xc19562ab;
    f.w0.v1[1][3]=0x466a64cb;
    f.w0.v1[1][4]=0xa7a14591;
    f.w0.v1[1][5]=0x84976f58;
    f.w0.v1[1][6]=0x262e12ba;
    f.w0.v1[1][7]=0x1786b8cb;
    f.w0.v1[1][8]=0;

    f.w0.v2[0][0]=0x6f2eb591;
    f.w0.v2[0][1]=0xea0d90ed;
    f.w0.v2[0][2]=0xbec4f266;
    f.w0.v2[0][3]=0xcba7de8d;
    f.w0.v2[0][4]=0x4f51ff12;
    f.w0.v2[0][5]=0xb88fa26;
    f.w0.v2[0][6]=0x3fcc9f58;
    f.w0.v2[0][7]=0x19ec8610;
    f.w0.v2[0][8]=0;

    f.w0.v2[1][0]=0xd204d702;
    f.w0.v2[1][1]=0xa58f39f;
    f.w0.v2[1][2]=0x9e6a83d0;
    f.w0.v2[1][3]=0x55502206;
    f.w0.v2[1][4]=0x2d952946;
    f.w0.v2[1][5]=0x3023689e;
    f.w0.v2[1][6]=0x4246f3d5;
    f.w0.v2[1][7]=0x17ab027;
    f.w0.v2[1][8]=0;


    f.w1.v0[0][0]=0xbb026f2d;
    f.w1.v0[0][1]=0x7bcad0cb;
    f.w1.v0[0][2]=0xf6ccbdf2;
    f.w1.v0[0][3]=0x56225b13;
    f.w1.v0[0][4]=0x24d6ab27;
    f.w1.v0[0][5]=0xe5159a7e;
    f.w1.v0[0][6]=0xc3171f89;
    f.w1.v0[0][7]=0x20a99bfb;
    f.w1.v0[0][8]=0;

    f.w1.v0[1][0]=0xba691ffa;
    f.w1.v0[1][1]=0xc8e73436;
    f.w1.v0[1][2]=0xf65caf44;
    f.w1.v0[1][3]=0xa09e23f7;
    f.w1.v0[1][4]=0xb0b75dfa;
    f.w1.v0[1][5]=0xb5ba3d35;
    f.w1.v0[1][6]=0x7786559f;
    f.w1.v0[1][7]=0xe9087c3;
    f.w1.v0[1][8]=0;

    f.w1.v1[0][0]=0x3b895762;
    f.w1.v1[0][1]=0x9d6bb902;
    f.w1.v1[0][2]=0x6586ce02;
    f.w1.v1[0][3]=0x1047f994;
    f.w1.v1[0][4]=0x16322ffd;
    f.w1.v1[0][5]=0x702068e7;
    f.w1.v1[0][6]=0x4e53db19;
    f.w1.v1[0][7]=0x776c240;
    f.w1.v1[0][8]=0;

    f.w1.v1[1][0]=0x76dd1070;
    f.w1.v1[1][1]=0xeb2675ba;
    f.w1.v1[1][2]=0x5c2400d7;
    f.w1.v1[1][3]=0xf72603c0;
    f.w1.v1[1][4]=0xc2e95f76;
    f.w1.v1[1][5]=0x3d69f644;
    f.w1.v1[1][6]=0x25815a57;
    f.w1.v1[1][7]=0xc4e3f54;
    f.w1.v1[1][8]=0;

    f.w1.v2[0][0]=0xd63040c8;
    f.w1.v2[0][1]=0x5bca9944;
    f.w1.v2[0][2]=0x6a8d0b33;
    f.w1.v2[0][3]=0xe176566d;
    f.w1.v2[0][4]=0xcf9801d7;
    f.w1.v2[0][5]=0x17d49043;
    f.w1.v2[0][6]=0xe3ed68ad;
    f.w1.v2[0][7]=0x218cc71b;
    f.w1.v2[0][8]=0;

    f.w1.v2[1][0]=0x33b7d2f1;
    f.w1.v2[1][1]=0x24063353;
    f.w1.v2[1][2]=0x3cd97a0f;
    f.w1.v2[1][3]=0x4a6d6512;
    f.w1.v2[1][4]=0x3b0e08b0;
    f.w1.v2[1][5]=0x16cf0059;
    f.w1.v2[1][6]=0xc6c343b4;
    f.w1.v2[1][7]=0x10ead7ea;
    f.w1.v2[1][8]=0;
*/

