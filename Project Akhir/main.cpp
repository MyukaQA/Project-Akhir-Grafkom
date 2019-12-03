#include <windows.h>
#include <GL/glut.h>
#include <iostream>
float gerak = 0;
float xx    = 0;
float yy    = 0;
int ver     = 2;
float marka[]               ={0.0f,2.0f,4.0f,6.0f,8.0f,10.0f};
float fireball_all_x[]      ={7.0f,10.0f};
float fireball_all_y[]      ={0.0f,-1.2f};
int fireballStatus_bar      =0;
int heartStatus_bar         =3;
///Start lvl 1
float rumputlvl1[]      ={0.0f,2.0f,4.0f,6.0f,8.0f,10.0f};
float stonelvl1[]        ={40.0f, 105.0f};
float treelvl1[]        ={-4.0f,-2.0f,0.0f,2.0f,4.0f,6.0f};
float cloudlvl1[]       ={0.0f,2.0f,6.0f,5.0f};
///End lvl 1
///Start lvl 2
float   lamplvl2[]        ={0.0f,1.5f,3.0f,6.0f,9.0f,12.0f,15.0f};
float   gotlvl2[]         ={9.0f,5.0f};
double  buildlvl2         = -2;
float roadlinelvl2[]      ={-2.5f,-1.5f,-0.5f,1.5f,2.5f,3.5f,4.5f};
///End lvl 2
///Start lvl 3
double piramidlvl3      =0;
float   kaktuslvl3[]    ={5.0f,12.0f,2.0f,10.0f,7.0f};
float moven[]   = {0.15f,  1.05f,  1.5f,  1.7f,  0.0f,  1.0f  ,0.0f,0.0f};
///x1,x2,y1,y2,transx,locationy,relativex1,relativex2
bool scene[]    = {true, false, false, false, false, false, false};
float panah[]   = {0.0f, 0.5f};

void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *font2 = GLUT_BITMAP_HELVETICA_12;

///HELVETICA
void hastag(int x, int y, char *string ) {
    glRasterPos2f(4.5,3.5);

    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font2, string[i]);
    }
}
///Times New Roman
void textPlay(int x, int y, char *string ) {
    glRasterPos2f(4.5,3.5);

    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

///Times New Roman
void textAbout(int x, int y, char *string ) {
    glRasterPos2f(4.47,3);

    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

///Times New Roman
void isiAbout(int x, int y, char *string ) {
    glRasterPos2f(4.47,3);

    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

///Times New Roman
void textExit(int x, int y, char *string ) {
    glRasterPos2f(4.47,2.5);

    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

void nilai(int x, int y, char *string ) {
    glRasterPos2f(4.47,2.5);

    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

void quads(){
    glPushMatrix();
    glTranslated(-0.85,-1.5,0);
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
        glVertex2f(1  ,2);
        glVertex2f(1.9,2);
        glVertex2f(1.9,2.2);
        glVertex2f(1  ,2.2);
    glEnd();
    glPopMatrix();
}

//Background Awal
void backgroundTrans () {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        glColor4f(32,12,43,0.5);
        glVertex2f(0,0);
        glVertex2f(10,0);
        glVertex2f(10,10);
        glVertex2f(0,10);
    glEnd();
}

void background(){
    glPushMatrix();
    glColor4f(1/.0,0.0,0.0,0.5);
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(10,0);
        glColor3ub(109,238,247);
        glVertex2f(10,10);
        glVertex2f(0,10);
    glEnd();
    glPopMatrix();
}

void mountain (){
    glPushMatrix();
    glTranslated(0,1,0);
    glPushMatrix();         //gunung di depan 3
    glColor3ub(140,226,8);
    glBegin(GL_POLYGON);
        glVertex2f(0, 4.1140712766305);
        glVertex2f(0.2925239179715, 4.231828289833);
        glVertex2f(0.645794957579, 4.3348656763852);
        glVertex2f(0.945094032802, 4.4329965207206);
        glVertex2f(1.308178156843, 4.5065946539722);
        glVertex2f(1.627103400933, 4.5556600761399);
        glVertex2f(1.9067763072889, 4.5752862450069);
        glVertex2f(2.2306080935958, 4.5703797027902);
        glVertex2f(2.5593464221194, 4.5605666183566);
        glVertex2f(2.8733651239927, 4.5262208228392);
        glVertex2f(3.2168230791666, 4.4428096051541);
        glVertex2f(3.5357483232566, 4.3593983874691);
        glVertex2f(3.9135520739479, 4.2465479164833);
        glColor3ub(71,181,20);
        glVertex2f(4.2471969446883, 4.1189778188473);
        glVertex2f(4.5170567666107, 3.9914077212113);
        glVertex2f(4.7385123177421, 3.8536422586861);
        glVertex2f(4.940335967967, 3.7230504850111);
        glVertex2f(5.1619462505669, 3.5449707936362);
        glVertex2f(4.9996958650919, 3.4697815906112);
        glVertex2f(4.825573500192, 3.3827204081613);
        glVertex2f(4.7187256853671, 3.3233605110363);
        glVertex2f(2.5008784881111, 1.6695012343873);
        glVertex2f(0, 3.8);
        glVertex2f(0, 3.9486064528871);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //gunung didepan 2
    glColor3ub(140,226,8);
    glBegin(GL_POLYGON);
        glVertex2f(10.0111883001553, 4.0867361609745);
        glVertex2f(9.6279215409075, 4.1743399916597);
        glVertex2f(9.2446547816597, 4.2071914281666);
        glVertex2f(8.8121108676514, 4.2400428646736);
        glVertex2f(8.2864878835401, 4.2455181040914);
        glVertex2f(7.788241096518, 4.2071914281666);
        glVertex2f(7.0874104510362, 4.1141123580636);
        glVertex2f(6.5, 4);
        glVertex2f(6.0176807663966, 3.8488381434086);
        glVertex2f(5.6816366497709, 3.7394284310189);
        glVertex2f(5.3065176358632, 3.6378336980856);
        glVertex2f(5, 3.5);
        glVertex2f(4.7907289917401, 3.379939376024);
        glVertex2f(4.6656893204376, 3.2861596225471);
        glColor3ub(71,181,20);
        glVertex2f(4.5857322309761, 1.6755953919651);
        glVertex2f(7.6469465132169, 1.6870178333168);
        glVertex2f(9.9999694316557, 1.6641729506135);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //Gunung yang didepan 1
    glColor3ub(140,226,8);
    glBegin(GL_POLYGON);
        glVertex2f(0, 3.968243900075);
        glVertex2f(0.2441221922892, 3.9551161071511);
        glVertex2f(0.4541668790721, 3.9518341589201);
        glVertex2f(0.7790797539393, 3.9419883142272);
        glVertex2f(1.1565038005022, 3.9255785730723);
        glVertex2f(1.5404917435271, 3.9124507801483);
        glVertex2f(1.8096114984676, 3.8861951943005);
        glVertex2f(2.101704891025, 3.8468118155287);
        glVertex2f(2.4, 3.8);
        glVertex2f(2.6629180385229, 3.7516353168302);
        glVertex2f(3.0021651258944, 3.691222716875);
        glVertex2f(3.5062763058623, 3.5981560374963);
        glVertex2f(4, 3.5);
        glVertex2f(4.4602097694937, 3.3499782258198);
        glVertex2f(4.9565653928467, 3.2336448765965);
        glColor3ub(71,181,20);
        glVertex2f(5.5, 3);
        glVertex2f(6.0044430625399, 2.7989425108421);
        glVertex2f(6.5, 2.5);
        glVertex2f(6.8753615068068, 2.2692086117519);
        glVertex2f(7.3422456212592, 1.9370026072377);
        glVertex2f(7.6578675529674, 1.674098834334);
        glVertex2f(6.3126567719567, 1.6687817956739);
        glVertex2f(0.7245532880408, 1.671715684084);
        glVertex2f(0, 1.6602113165243);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void road (){
    glPushMatrix();                         //DIV jalan
    glColor3ub(130,130,130);
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(100, 0);
        glVertex2f(100, 3.1734195044442);
        glVertex2f(0, 3.1734195044442);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis atas jalan warna hitam
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(100, 3.1734195044442);
        glVertex2f(0, 3.1734195044442);
        glVertex2f(0, 3.0734195044442);
        glVertex2f(100, 3.0734195044442);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis tengah jalan warna putih
    glTranslated(marka[0],1.2,0);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
        glVertex2f(0.111809588206, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.7078144679268);
        glVertex2f(0.111809588206, 0.7078144679268);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis tengah jalan warna putih
    glTranslated(marka[1],1.2,0);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
        glVertex2f(0.111809588206, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.7078144679268);
        glVertex2f(0.111809588206, 0.7078144679268);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis tengah jalan warna putih
    glTranslated(marka[2],1.2,0);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
        glVertex2f(0.111809588206, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.7078144679268);
        glVertex2f(0.111809588206, 0.7078144679268);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis tengah jalan warna putih
    glTranslated(marka[3],1.2,0);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
        glVertex2f(0.111809588206, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.7078144679268);
        glVertex2f(0.111809588206, 0.7078144679268);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis tengah jalan warna putih
    glTranslated(marka[4],1.2,0);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
        glVertex2f(0.111809588206, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.7078144679268);
        glVertex2f(0.111809588206, 0.7078144679268);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis tengah jalan warna putih
    glTranslated(marka[5],1.2,0);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
        glVertex2f(0.111809588206, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.7078144679268);
        glVertex2f(0.111809588206, 0.7078144679268);
    glEnd();
    glPopMatrix();
}

void cloud (){

    glPushMatrix();                 //Awan Warna kebiruan
    glTranslated(cloudlvl1[0],9,0);
    glScaled(-0.12,-0.12,0);
    glColor3ub(135, 203, 204);
    glBegin(GL_POLYGON);
        glVertex2f(0.37, 2.98);
        glVertex2f(0.31, 2.68);
        glVertex2f(0.25, 2.38);
        glVertex2f(0.29, 2.04);
        glVertex2f(0.37, 1.72);
        glVertex2f(0.55, 1.42);
        glVertex2f(0.81, 1.1);
        glVertex2f(1.15, 0.84);
        glVertex2f(1.53, 0.68);
        glVertex2f(1.89, 0.58);
        glVertex2f(2.31, 0.56);
        glVertex2f(2.69, 0.64);
        glVertex2f(3.07, 0.82);
        glVertex2f(3.33, 1.1);
        glVertex2f(3.45, 0.78);
        glVertex2f(3.69, 0.48);
        glVertex2f(3.99, 0.28);
        glVertex2f(4.33, 0.14);
        glVertex2f(4.71, 0.14);
        glVertex2f(5.13, 0.2);
        glVertex2f(5.53, 0.38);
        glVertex2f(5.81, 0.64);
        glVertex2f(6, 1);
        glVertex2f(6.15, 0.7);
        glVertex2f(6.43, 0.52);
        glVertex2f(6.79, 0.4);
        glVertex2f(7.17, 0.36);
        glVertex2f(7.51, 0.4);
        glVertex2f(7.83, 0.54);
        glVertex2f(8.17, 0.62);
        glVertex2f(8.39, 0.86);
        glVertex2f(8.61, 1.16);
        glVertex2f(8.73, 1.56);
        glVertex2f(9.03, 1.36);
        glVertex2f(9.35, 1.26);
        glVertex2f(9.69, 1.22);
        glVertex2f(10.03, 1.32);
        glVertex2f(10.37, 1.46);
        glVertex2f(10.61, 1.78);
        glVertex2f(10.81, 2.12);
        glVertex2f(10.77, 2.54);
        glVertex2f(10.57, 2.9);
        glVertex2f(10.33, 3.14);
        glVertex2f(10.03, 3.26);
        glVertex2f(9.63, 3.3);
        glVertex2f(9.27, 3.2);
        glVertex2f(9.23, 3.48);
        glVertex2f(9.05, 3.76);
        glVertex2f(8.83, 4.14);
        glVertex2f(8.49, 4.48);
        glVertex2f(8.01, 4.76);
        glVertex2f(7.51, 4.94);
        glVertex2f(7.19, 4.94);
        glVertex2f(6.85, 4.88);
        glVertex2f(6.51, 4.82);
        glVertex2f(6.13, 4.6);
        glVertex2f(6.07, 4.84);
        glVertex2f(6.03, 5.24);
        glVertex2f(5.85, 5.52);
        glVertex2f(5.57, 5.8);
        glVertex2f(5.25, 5.98);
        glVertex2f(4.85, 6.12);
        glVertex2f(4.41, 6.14);
        glVertex2f(4.03, 6.14);
        glVertex2f(3.67, 5.92);
        glVertex2f(3.39, 5.74);
        glVertex2f(3.15, 5.48);
        glVertex2f(3.03, 5.18);
        glVertex2f(2.97, 4.86);
        glVertex2f(2.95, 4.46);
        glVertex2f(2.61, 4.48);
        glVertex2f(2.29, 4.6);
        glVertex2f(1.89, 4.64);
        glVertex2f(1.49, 4.52);
        glVertex2f(1.17, 4.3);
        glVertex2f(0.83, 4.1);
        glVertex2f(0.55, 3.9);
        glVertex2f(0.45, 3.62);
        glVertex2f(0.63, 3.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(cloudlvl1[1],8,0);
    glScaled(-0.12,-0.12,0);
    glColor3ub(135, 203, 204);
    glBegin(GL_POLYGON);
        glVertex2f(0.37, 2.98);
        glVertex2f(0.31, 2.68);
        glVertex2f(0.25, 2.38);
        glVertex2f(0.29, 2.04);
        glVertex2f(0.37, 1.72);
        glVertex2f(0.55, 1.42);
        glVertex2f(0.81, 1.1);
        glVertex2f(1.15, 0.84);
        glVertex2f(1.53, 0.68);
        glVertex2f(1.89, 0.58);
        glVertex2f(2.31, 0.56);
        glVertex2f(2.69, 0.64);
        glVertex2f(3.07, 0.82);
        glVertex2f(3.33, 1.1);
        glVertex2f(3.45, 0.78);
        glVertex2f(3.69, 0.48);
        glVertex2f(3.99, 0.28);
        glVertex2f(4.33, 0.14);
        glVertex2f(4.71, 0.14);
        glVertex2f(5.13, 0.2);
        glVertex2f(5.53, 0.38);
        glVertex2f(5.81, 0.64);
        glVertex2f(6, 1);
        glVertex2f(6.15, 0.7);
        glVertex2f(6.43, 0.52);
        glVertex2f(6.79, 0.4);
        glVertex2f(7.17, 0.36);
        glVertex2f(7.51, 0.4);
        glVertex2f(7.83, 0.54);
        glVertex2f(8.17, 0.62);
        glVertex2f(8.39, 0.86);
        glVertex2f(8.61, 1.16);
        glVertex2f(8.73, 1.56);
        glVertex2f(9.03, 1.36);
        glVertex2f(9.35, 1.26);
        glVertex2f(9.69, 1.22);
        glVertex2f(10.03, 1.32);
        glVertex2f(10.37, 1.46);
        glVertex2f(10.61, 1.78);
        glVertex2f(10.81, 2.12);
        glVertex2f(10.77, 2.54);
        glVertex2f(10.57, 2.9);
        glVertex2f(10.33, 3.14);
        glVertex2f(10.03, 3.26);
        glVertex2f(9.63, 3.3);
        glVertex2f(9.27, 3.2);
        glVertex2f(9.23, 3.48);
        glVertex2f(9.05, 3.76);
        glVertex2f(8.83, 4.14);
        glVertex2f(8.49, 4.48);
        glVertex2f(8.01, 4.76);
        glVertex2f(7.51, 4.94);
        glVertex2f(7.19, 4.94);
        glVertex2f(6.85, 4.88);
        glVertex2f(6.51, 4.82);
        glVertex2f(6.13, 4.6);
        glVertex2f(6.07, 4.84);
        glVertex2f(6.03, 5.24);
        glVertex2f(5.85, 5.52);
        glVertex2f(5.57, 5.8);
        glVertex2f(5.25, 5.98);
        glVertex2f(4.85, 6.12);
        glVertex2f(4.41, 6.14);
        glVertex2f(4.03, 6.14);
        glVertex2f(3.67, 5.92);
        glVertex2f(3.39, 5.74);
        glVertex2f(3.15, 5.48);
        glVertex2f(3.03, 5.18);
        glVertex2f(2.97, 4.86);
        glVertex2f(2.95, 4.46);
        glVertex2f(2.61, 4.48);
        glVertex2f(2.29, 4.6);
        glVertex2f(1.89, 4.64);
        glVertex2f(1.49, 4.52);
        glVertex2f(1.17, 4.3);
        glVertex2f(0.83, 4.1);
        glVertex2f(0.55, 3.9);
        glVertex2f(0.45, 3.62);
        glVertex2f(0.63, 3.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(cloudlvl1[2],9,0);
    glScaled(-0.12,-0.12,0);
    glColor3ub(135, 203, 204);
    glBegin(GL_POLYGON);
        glVertex2f(0.37, 2.98);
        glVertex2f(0.31, 2.68);
        glVertex2f(0.25, 2.38);
        glVertex2f(0.29, 2.04);
        glVertex2f(0.37, 1.72);
        glVertex2f(0.55, 1.42);
        glVertex2f(0.81, 1.1);
        glVertex2f(1.15, 0.84);
        glVertex2f(1.53, 0.68);
        glVertex2f(1.89, 0.58);
        glVertex2f(2.31, 0.56);
        glVertex2f(2.69, 0.64);
        glVertex2f(3.07, 0.82);
        glVertex2f(3.33, 1.1);
        glVertex2f(3.45, 0.78);
        glVertex2f(3.69, 0.48);
        glVertex2f(3.99, 0.28);
        glVertex2f(4.33, 0.14);
        glVertex2f(4.71, 0.14);
        glVertex2f(5.13, 0.2);
        glVertex2f(5.53, 0.38);
        glVertex2f(5.81, 0.64);
        glVertex2f(6, 1);
        glVertex2f(6.15, 0.7);
        glVertex2f(6.43, 0.52);
        glVertex2f(6.79, 0.4);
        glVertex2f(7.17, 0.36);
        glVertex2f(7.51, 0.4);
        glVertex2f(7.83, 0.54);
        glVertex2f(8.17, 0.62);
        glVertex2f(8.39, 0.86);
        glVertex2f(8.61, 1.16);
        glVertex2f(8.73, 1.56);
        glVertex2f(9.03, 1.36);
        glVertex2f(9.35, 1.26);
        glVertex2f(9.69, 1.22);
        glVertex2f(10.03, 1.32);
        glVertex2f(10.37, 1.46);
        glVertex2f(10.61, 1.78);
        glVertex2f(10.81, 2.12);
        glVertex2f(10.77, 2.54);
        glVertex2f(10.57, 2.9);
        glVertex2f(10.33, 3.14);
        glVertex2f(10.03, 3.26);
        glVertex2f(9.63, 3.3);
        glVertex2f(9.27, 3.2);
        glVertex2f(9.23, 3.48);
        glVertex2f(9.05, 3.76);
        glVertex2f(8.83, 4.14);
        glVertex2f(8.49, 4.48);
        glVertex2f(8.01, 4.76);
        glVertex2f(7.51, 4.94);
        glVertex2f(7.19, 4.94);
        glVertex2f(6.85, 4.88);
        glVertex2f(6.51, 4.82);
        glVertex2f(6.13, 4.6);
        glVertex2f(6.07, 4.84);
        glVertex2f(6.03, 5.24);
        glVertex2f(5.85, 5.52);
        glVertex2f(5.57, 5.8);
        glVertex2f(5.25, 5.98);
        glVertex2f(4.85, 6.12);
        glVertex2f(4.41, 6.14);
        glVertex2f(4.03, 6.14);
        glVertex2f(3.67, 5.92);
        glVertex2f(3.39, 5.74);
        glVertex2f(3.15, 5.48);
        glVertex2f(3.03, 5.18);
        glVertex2f(2.97, 4.86);
        glVertex2f(2.95, 4.46);
        glVertex2f(2.61, 4.48);
        glVertex2f(2.29, 4.6);
        glVertex2f(1.89, 4.64);
        glVertex2f(1.49, 4.52);
        glVertex2f(1.17, 4.3);
        glVertex2f(0.83, 4.1);
        glVertex2f(0.55, 3.9);
        glVertex2f(0.45, 3.62);
        glVertex2f(0.63, 3.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(cloudlvl1[3],7.6,0);
    glScaled(-0.12,-0.12,0);
    glColor3ub(135, 203, 204);
    glBegin(GL_POLYGON);
        glVertex2f(0.37, 2.98);
        glVertex2f(0.31, 2.68);
        glVertex2f(0.25, 2.38);
        glVertex2f(0.29, 2.04);
        glVertex2f(0.37, 1.72);
        glVertex2f(0.55, 1.42);
        glVertex2f(0.81, 1.1);
        glVertex2f(1.15, 0.84);
        glVertex2f(1.53, 0.68);
        glVertex2f(1.89, 0.58);
        glVertex2f(2.31, 0.56);
        glVertex2f(2.69, 0.64);
        glVertex2f(3.07, 0.82);
        glVertex2f(3.33, 1.1);
        glVertex2f(3.45, 0.78);
        glVertex2f(3.69, 0.48);
        glVertex2f(3.99, 0.28);
        glVertex2f(4.33, 0.14);
        glVertex2f(4.71, 0.14);
        glVertex2f(5.13, 0.2);
        glVertex2f(5.53, 0.38);
        glVertex2f(5.81, 0.64);
        glVertex2f(6, 1);
        glVertex2f(6.15, 0.7);
        glVertex2f(6.43, 0.52);
        glVertex2f(6.79, 0.4);
        glVertex2f(7.17, 0.36);
        glVertex2f(7.51, 0.4);
        glVertex2f(7.83, 0.54);
        glVertex2f(8.17, 0.62);
        glVertex2f(8.39, 0.86);
        glVertex2f(8.61, 1.16);
        glVertex2f(8.73, 1.56);
        glVertex2f(9.03, 1.36);
        glVertex2f(9.35, 1.26);
        glVertex2f(9.69, 1.22);
        glVertex2f(10.03, 1.32);
        glVertex2f(10.37, 1.46);
        glVertex2f(10.61, 1.78);
        glVertex2f(10.81, 2.12);
        glVertex2f(10.77, 2.54);
        glVertex2f(10.57, 2.9);
        glVertex2f(10.33, 3.14);
        glVertex2f(10.03, 3.26);
        glVertex2f(9.63, 3.3);
        glVertex2f(9.27, 3.2);
        glVertex2f(9.23, 3.48);
        glVertex2f(9.05, 3.76);
        glVertex2f(8.83, 4.14);
        glVertex2f(8.49, 4.48);
        glVertex2f(8.01, 4.76);
        glVertex2f(7.51, 4.94);
        glVertex2f(7.19, 4.94);
        glVertex2f(6.85, 4.88);
        glVertex2f(6.51, 4.82);
        glVertex2f(6.13, 4.6);
        glVertex2f(6.07, 4.84);
        glVertex2f(6.03, 5.24);
        glVertex2f(5.85, 5.52);
        glVertex2f(5.57, 5.8);
        glVertex2f(5.25, 5.98);
        glVertex2f(4.85, 6.12);
        glVertex2f(4.41, 6.14);
        glVertex2f(4.03, 6.14);
        glVertex2f(3.67, 5.92);
        glVertex2f(3.39, 5.74);
        glVertex2f(3.15, 5.48);
        glVertex2f(3.03, 5.18);
        glVertex2f(2.97, 4.86);
        glVertex2f(2.95, 4.46);
        glVertex2f(2.61, 4.48);
        glVertex2f(2.29, 4.6);
        glVertex2f(1.89, 4.64);
        glVertex2f(1.49, 4.52);
        glVertex2f(1.17, 4.3);
        glVertex2f(0.83, 4.1);
        glVertex2f(0.55, 3.9);
        glVertex2f(0.45, 3.62);
        glVertex2f(0.63, 3.3);
    glEnd();
    glPopMatrix();
}

void text(){
                        glPushMatrix();//untuk seluruh vertex
                        glTranslated(0,2,0);
//awal L
glPushMatrix();
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(0.7370767330995, 2.6114249960925);
    glVertex2f(0.5334967522909, 1.849707651326);
    glVertex2f(0.502138813535, 1.6178047554105);
    glVertex2f(0.1419784632276, 1.6178047554105);
    glVertex2f(0.1355179633116, 1.6184829454275);
    glVertex2f(0.1284555015608, 1.6202133313883);
    glVertex2f(0.1223249958281, 1.6233533465197);
    glVertex2f(0.1148487693247, 1.6270914597713);
    glVertex2f(0.1085687390619, 1.6321752937936);
    glVertex2f(0.1022714468793, 1.6370161829877);
    glVertex2f(0.0966032631535, 1.6433512118577);
    glVertex2f(0.0919633195543, 1.6499885151188);
    glVertex2f(0.088642962722, 1.6567675769847);
    glVertex2f(0.0854115991422, 1.6631993091947);
    glVertex2f(0.0835240792723, 1.6712941381258);
    glVertex2f(0.0832473828696, 1.6802867712132);
    glVertex2f(0.0843541684804, 1.6885876632938);
    glVertex2f(0.0877714574971, 1.6993346530647);
    glVertex2f(0.0929180667968, 1.7090305108982);
    glVertex2f(0.3194309277405, 2.5507368085718);
    glVertex2f(0.3230007877948, 2.56041687573);
    glVertex2f(0.3269187463348, 2.5682527928101);
    glVertex2f(0.332946374858, 2.5772942355948);
    glVertex2f(0.3392753848073, 2.5839246269702);
    glVertex2f(0.3480154461658, 2.5923633069026);
    glVertex2f(0.3552486003936, 2.5974867911473);
    glVertex2f(0.3648928060306, 2.6023088939658);
    glVertex2f(0.3736328673891, 2.6062268525058);
    glVertex2f(0.3838988329776, 2.609427470961);
    glVertex2f(0.3960837362792, 2.6114249960925);
glEnd();


//L kedua

glBegin(GL_POLYGON);
    glVertex2f(0.5334967522909, 1.849707651326);
    glVertex2f(0.502138813535, 1.6178047554105);
    glVertex2f(0.9336379809721, 1.6178047554105);
    glVertex2f(0.9410835497062, 1.6182608728334);
    glVertex2f(0.9479270595129, 1.6198942836154);
    glVertex2f(0.9535019668619, 1.6217525860651);
    glVertex2f(0.959434961285, 1.6236974045801);
    glVertex2f(0.9650228698634, 1.6261689795282);
    glVertex2f(0.9707006214991, 1.6292371277042);
    glVertex2f(0.9761272827883, 1.6323214830069);
    glVertex2f(0.9810443831524, 1.6363708597773);
    glVertex2f(0.9862507247144, 1.6405648571467);
    glVertex2f(0.9923247898701, 1.6457711987087);
    glVertex2f(0.9983988550258, 1.6506882990728);
    glVertex2f(1.0034605759888, 1.6570516054264);
    glVertex2f(1.0072207115614, 1.6626918087852);
    glVertex2f(1.0099366011017, 1.6685318959005);
    glVertex2f(1.0135866423805, 1.6743387797532);
    glVertex2f(1.0164698833055, 1.6807530933422);
    glVertex2f(1.0622514602416, 1.849707651326);
glEnd();
glPopMatrix();


//bayangan L
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(0.8828379996335,2.6091492385237);
    glVertex2f(0.7958174172252,2.6091492385237);
    glVertex2f(0.6091362563031,1.8941766415183);
    glVertex2f(0.6957101140185,1.8941766415183);
glEnd();
glPopMatrix();

//bayangan kedua
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(1.1208653041496, 1.8451266424889);
    glVertex2f(1.2052182011897, 1.8451266424889);
    glVertex2f(1.1624756391272, 1.6770268113391);
    glVertex2f(1.143782898558, 1.648268748925);
    glVertex2f(1.1040009122184, 1.6334104166777);
    glVertex2f(1.0340229603439, 1.6267002021144);
    glVertex2f(1.0785979570859, 1.674630306138);
glEnd();
glPopMatrix();
glPopMatrix();

//awal A
glPushMatrix();
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(1.9621645802428, 2.1835222133522);
    glVertex2f(1.5087381214781, 1.6098143630591);
    glVertex2f(1.1404979760868, 1.6098143630591);
    glVertex2f(1.852379288109, 2.4784928148988);
    glVertex2f(1.8670139602148, 2.4931274870046);
    glVertex2f(1.8804218587037, 2.5057959759494);
    glVertex2f(1.8954236848525, 2.5139551479206);
    glVertex2f(1.9144725047888, 2.5188616621466);
    glVertex2f(1.9361932351512, 2.5204435456742);
    glVertex2f(2.0140699427988, 2.5204435456742);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.9621645802428, 2.1835222133522);
    glVertex2f(2.1158980821291, 1.61533181888);
    glVertex2f(2.4805969911431, 1.61533181888);
    glVertex2f(2.234287377119, 2.4642917703841);
    glVertex2f(2.2294420360193, 2.4804793844599);
    glVertex2f(2.2215175543086, 2.4928415759285);
    glVertex2f(2.210740259182, 2.5007660576392);
    glVertex2f(2.2002799433239, 2.5083735600815);
    glVertex2f(2.1891856689289, 2.5143961661816);
    glVertex2f(2.1761895189234, 2.5185168966712);
    glVertex2f(2.1641443067232, 2.5201017930133);
    glVertex2f(2.1492462811071, 2.5197848137449);
    glVertex2f(2.0140699427988, 2.5204435456742);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.7926492195341,1.9882400405703);
    glVertex2f(2.0333387017254,1.9882400405703);
    glVertex2f(2.1161358835992, 1.7889491493159);
    glVertex2f(1.6020231496385,1.7889491493159);
glEnd();
glPopMatrix();//pop untuk semua A

//baynagn A pertama
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(2.2737078103396, 2.5170870713101);
    glVertex2f(2.346106268898, 2.502045045505);
    glVertex2f(2.3565480778919, 2.4972848212211);
    glVertex2f(2.3642510250711, 2.4925163301102);
    glVertex2f(2.3704867442162, 2.484813382931);
    glVertex2f(2.3741637204336, 2.4760367260369);
    glVertex2f(2.6285959775602, 1.6107660379072);
    glVertex2f(2.5470927462879, 1.6107660379072);
glEnd();
glPopMatrix();

//bayangan A dalam
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(1.9436881261876, 2.0990715217855);
    glVertex2f(1.8866342720717, 2.0304855056675);
    glVertex2f(1.9552202881898, 2.0304855056675);
glEnd();
glPopMatrix();

//bayangan A bawah
glPushMatrix();
glColor3ub(38, 102, 222);
    glBegin(GL_POLYGON);
    glVertex2f(1.675081166356, 1.74);
    glVertex2f(1.74, 1.74);
    glVertex2f(1.6479385884535, 1.6127604213941);
    glVertex2f(1.5795025496087, 1.6127604213941);
glEnd();
glPopMatrix();
glPopMatrix();

//awal R
glPushMatrix();
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(2.6458488255288, 1.6265276336839);
    glVertex2f(2.8591845309588, 2.4369883556376);
    glVertex2f(2.8644042113367, 2.4487499386729);
    glVertex2f(2.8713201150748, 2.4585998621786);
    glVertex2f(2.8780264459723, 2.4676114943222);
    glVertex2f(2.8851519225509, 2.4747369709008);
    glVertex2f(2.8929061176512, 2.4801858647551);
    glVertex2f(2.9019177497948, 2.4860539042904);
    glVertex2f(2.909671944895, 2.490874079623);
    glVertex2f(2.9178452856764, 2.4956942549556);
    glVertex2f(2.9266473449794, 2.4992569932449);
    glVertex2f(2.9354494042824, 2.5028197315342);
    glVertex2f(2.9457184734693, 2.5055441784614);
    glVertex2f(2.9564066883372, 2.5070111883452);
    glVertex2f(2.9694674244456, 2.5078849311717);
    glVertex2f(3.2190461952251, 2.5078849311717);
    glVertex2f(3.1788760197042, 2.3031720375298);
    glVertex2f(3.1232557766753, 2.089961105919);
    glVertex2f(3.0151929330069, 1.676559649739);
    glVertex2f(3.0126891875189, 1.6685937425244);
    glVertex2f(3.0090424036994, 1.6618759828569);
    glVertex2f(3.0055875558704, 1.6555420951705);
    glVertex2f(3.0013649640795, 1.649975951446);
    glVertex2f(2.995031076393, 1.6444098077216);
    glVertex2f(2.99, 1.64);
    glVertex2f(2.9844291747929, 1.6360027953822);
    glVertex2f(2.9773217612007, 1.6329184460874);
    glVertex2f(2.97, 1.63);
    glVertex2f(2.9633751383026, 1.6282248710737);
    glVertex2f(2.9547170836808, 1.6265276336839);
glEnd();

//R kotak atas
glBegin(GL_POLYGON);
    glVertex2f(3.791945307009, 2.5078849311717);
    glVertex2f(3.8052325896113, 2.5052920143501);
    glVertex2f(3.8183823186558, 2.5009867159752);
    glVertex2f(3.8318466735437, 2.4926169818558);
    glVertex2f(3.842844947166, 2.4803450425026);
    glVertex2f(3.8535913350387, 2.469214855063);
    glVertex2f(3.8604997272426, 2.452711473687);
    glVertex2f(3.859348328542, 2.4339052949097);
    glVertex2f(3.8559253107132, 2.4174958148593);
    glVertex2f(3.737653669978, 1.9658612543854);
    glVertex2f(3.7299400991387, 1.9493413335551);
    glVertex2f(3.724624369679, 1.9380408699866);
    glVertex2f(3.7180725049674, 1.9261656151968);
    glVertex2f(3.7070162332665, 1.9155188350405);
    glVertex2f(3.6963694531102, 1.9048720548841);
    glVertex2f(3.6869511475873, 1.8970917155391);
    glVertex2f(3.6738474181641, 1.890949342372);
    glVertex2f(3.6566487732961, 1.8868544269273);
    glVertex2f(3.6393974611613, 1.8860859471983);
    glVertex2f(3.6209098134671, 1.8832847884567);
    glVertex2f(3.6001812387797, 1.8821643249601);
    glVertex2f(3.5514410766767, 1.8844052519533);
    glVertex2f(3.4126380677392, 2.089961105919);
    glVertex2f(3.4663030891002, 2.3031720375298);
    glVertex2f(3.5, 2.5078849311717);
glEnd();
//penghubung
glBegin(GL_POLYGON);
    glVertex2f(3.2190461952251, 2.5078849311717);
    glVertex2f(3.5, 2.5078849311717);
    glVertex2f(3.4663030891002, 2.3031720375298);
    glVertex2f(3.1788760197042, 2.3031720375298);
glEnd();

//R bagian bawah
glBegin(GL_POLYGON);
    glVertex2f(3.5514410766767, 1.8844052519533);
    glVertex2f(3.6725059031291, 1.6265276336839);
    glVertex2f(3.354789326424, 1.6265276336839);
    glVertex2f(3.345623256988, 1.625983524057);
    glVertex2f(3.3362262644466, 1.625983524057);
    glVertex2f(3.3269037878231, 1.6278656586643);
    glVertex2f(3.3187489758593, 1.6316294180322);
    glVertex2f(3.3116396526088, 1.6353931774001);
    glVertex2f(3.3049485248437, 1.6406206209666);
    glVertex2f(3.2988846903065, 1.6466844555038);
    glVertex2f(3.2935017793452, 1.6534106330943);
    glVertex2f(3.2885149637679, 1.6609300413667);
    glVertex2f(3.1983834191331, 1.8523704708127);
    glVertex2f(3.1730237619811, 1.8730204773508);
    glVertex2f(3.00086057174, 1.8730204773508);
    glVertex2f(3.1232557766753, 2.089961105919);
    glVertex2f(3.4126380677392, 2.089961105919);
glEnd();
glPopMatrix();

//bayangan R pertama
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(3.8817650771712, 2.5031510377038);
    glVertex2f(3.9324772969299, 2.5037256388971);
    glVertex2f(3.95, 2.5);
    glVertex2f(3.9647338360177, 2.4896845571765);
    glVertex2f(3.9768774742625, 2.4771614302365);
    glVertex2f(3.9863646916413, 2.4623613711256);
    glVertex2f(3.9897800898977, 2.4452843798438);
    glVertex2f(3.9876650219343, 2.425007110181);
    glVertex2f(3.9837082707753, 2.4065765329384);
    glVertex2f(3.9111195384829, 2.4158501073091);
    glVertex2f(3.915313032956, 2.4486356095534);
    glVertex2f(3.9168379400372, 2.4600724126619);
    glVertex2f(3.9145505794155, 2.4692218551487);
    glVertex2f(3.9080697243207, 2.4757027102435);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(3.9111195384829, 2.4158501073091);
    glVertex2f(3.9837082707753, 2.4065765329384);
    glVertex2f(3.8604506900418, 1.9480664072166);
    glVertex2f(3.8509518376885, 1.9306203920099);
    glVertex2f(3.8358186349262, 1.9168629349533);
    glVertex2f(3.8156349684108, 1.9053351377545);
    glVertex2f(3.7880531575053, 1.9264423894698);
glEnd();
glPopMatrix();

//bayangan r bawah kanan
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(3.6896388936166,1.8553005009077);
    glVertex2f(3.6255399992371,1.8415650235407);
    glVertex2f(3.7326211643634,1.6224478837532);
    glVertex2f(3.8041012050085,1.6229420087821);
glEnd();
glPopMatrix();

//bayangan R tengah
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(3.2961592847234, 2.2620506368075);
    glVertex2f(3.2267618070983, 2.2620506368075);
    glVertex2f(3.1868582574639, 2.1232556815573);
    glVertex2f(3.2605930774406, 2.1232556815573);
glEnd();
glPopMatrix();

//bayangan r kiri bawah
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(3.1209798004703, 1.8319782041618);
    glVertex2f(3.1718791758208, 1.8319782041618);
    glVertex2f(3.1386965635926, 1.6634802817327);
    glVertex2f(3.0997196847235, 1.632771225654);
    glVertex2f(3.0347582199416, 1.6256845204051);
    glVertex2f(3.0690106286447, 1.6729292220646);
glEnd();
glPopMatrix();
glPopMatrix();

//awal i
glPushMatrix();
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(4.5524780501768, 2.5135281326399);
    glVertex2f(4.2907899838794, 2.5135281326399);
    glVertex2f(4.2789308145986, 2.5114088517959);
    glVertex2f(4.2655916996552, 2.5097770443837);
    glVertex2f(4.2537075703422, 2.507290771101);
    glVertex2f(4.2432851100152, 2.5033554503964);
    glVertex2f(4.2307799006716, 2.497609813671);
    glVertex2f(4.2179367126971, 2.490174283791);
    glVertex2f(4.2050935247225, 2.4807108821256);
    glVertex2f(4.1960544406133, 2.4702280448467);
    glVertex2f(4.1873035191366, 2.4635361637174);
    glVertex2f(4.1790673577467, 2.4542704821539);
    glVertex2f(4.1698016761832, 2.4419162400691);
    glVertex2f(4.1610507547065, 2.4254439172894);
    glVertex2f(4.1538441134903, 2.4100011146835);
    glVertex2f(4.147666992448, 2.3894107112089);
    glVertex2f(3.9410798599561, 1.605329328956);
    glVertex2f(4.2710074007769, 1.605329328956);
    glVertex2f(4.2814851372214, 1.6073189518871);
    glVertex2f(4.2922429713794, 1.6092973218582);
    glVertex2f(4.3031721905707, 1.6127127028555);
    glVertex2f(4.3127352573632, 1.6174942362517);
    glVertex2f(4.3224351711798, 1.6258617676341);
    glVertex2f(4.3275102533549, 1.6345619085057);
    glVertex2f(4.3340353590086, 1.6437453905368);
    glVertex2f(4.3380522213181, 1.6554611511183);
glEnd();
glPopMatrix();

//bayangan i
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(4.6958548402508, 2.5168748337103);
    glVertex2f(4.6190264799031, 2.5198297706467);
    glVertex2f(4.3873796161126, 1.6377228220615);
    glVertex2f(4.3586749817483, 1.6048013178221);
    glVertex2f(4.3880846640902, 1.595419943403);
    glVertex2f(4.4064159115089, 1.5982401353135);
    glVertex2f(4.4233370629723, 1.6017653752017);
    glVertex2f(4.4395531664581, 1.6074057590229);
    glVertex2f(4.4543591739885, 1.6165713827322);
    glVertex2f(4.4614096537649, 1.6320824382403);
glEnd();
glPopMatrix();
glPopMatrix();

//awal D
glPushMatrix();
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(5.3, 2.5);
    glVertex2f(5.0599433071293, 1.6167855314673);
    glVertex2f(5.4127002923709, 1.6167855314673);
    glVertex2f(5.4740639920962, 1.8205489911416);
    glVertex2f(5.6013642833026, 2.2932125208565);
    glVertex2f(5.65, 2.5);

glEnd();

glBegin(GL_POLYGON);
    glVertex2f(6.1864852569705, 2.5010283395892);
    glVertex2f(6.2013420519972, 2.4970494914763);
    glVertex2f(6.2117537063101, 2.4920915608511);
    glVertex2f(6.2196863953105, 2.4876294232884);
    glVertex2f(6.2286106704358, 2.4826714926632);
    glVertex2f(6.238278635155, 2.4747388036629);
    glVertex2f(6.2467071172178, 2.4645750458812);
    glVertex2f(6.2529045304993, 2.4558986672871);
    glVertex2f(6.2586061507183, 2.4459828060367);
    glVertex2f(6.260647343909, 2.4352362105027);
    glVertex2f(6.2596290377964, 2.4244421657084);
    glVertex2f(6.2559631357907, 2.4116115086887);
    glVertex2f(6.0720486423528, 1.7153143899151);
    glVertex2f(6.0686746633869, 1.7036405841778);
    glVertex2f(6.0663442658868, 1.6930478682681);
    glVertex2f(6.0597767820228, 1.683090715313);
    glVertex2f(6.052361880886, 1.6739809796307);
    glVertex2f(6.0462181056584, 1.6657186612211);
    glVertex2f(6.0371083699761, 1.657880051448);
    glVertex2f(6.0292697602029, 1.6508888589476);
    glVertex2f(6.0186770442932, 1.6445332294018);
    glVertex2f(6.0097791629291, 1.638177599856);
    glVertex2f(6.0002457186104, 1.6318219703102);
    glVertex2f(5.9888055854279, 1.6265256123553);
    glVertex2f(5.9773654522455, 1.6227122346278);
    glVertex2f(5.9652897561085, 1.6195344198549);
    glVertex2f(5.9525784970168, 1.6176277309912);
    glVertex2f(5.9381379177176, 1.6167855314673);
    glVertex2f(5.6892302208912, 1.6167855314673);
    glVertex2f(5.7431762478166, 1.8205489911416);
    glVertex2f(5.8594779441104, 2.2932125208565);
    glVertex2f(5.9, 2.5);
glEnd();

//penghubung atas

glBegin(GL_POLYGON);
    glVertex2f(5.65,2.5);
    glVertex2f(5.9, 2.5);
    glVertex2f(5.8594779441104, 2.2932125208565);
    glVertex2f(5.6013642833026, 2.2932125208565);
glEnd();

//penghubung bawah
glBegin(GL_POLYGON);
    glVertex2f(5.4740639920962, 1.8205489911416);
    glVertex2f(5.7431762478166, 1.8205489911416);
    glVertex2f(5.6892302208912, 1.6167855314673);
    glVertex2f(5.4127002923709, 1.6167855314673);
glEnd();
glPopMatrix();

//bayangan D kanan
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(6.2768034278786, 2.497041543244);
    glVertex2f(6.3176289986997, 2.4511127760703);
    glVertex2f(6.3219525086356, 2.4279527472906);
    glVertex2f(6.3886876176596, 2.4238835333257);
    glVertex2f(6.3903153032455, 2.4401603891852);
    glVertex2f(6.3862460892807, 2.4539957166658);
    glVertex2f(6.3813630325228, 2.4702725725253);
    glVertex2f(6.3667138622492, 2.480038686041);
    glVertex2f(6.3512508491827, 2.4889909567637);
    glVertex2f(6.3317186221513, 2.4963155419005);
glEnd();

//bayangan D kanan lnjt
glBegin(GL_POLYGON);
    glVertex2f(6.2, 1.7);
    glVertex2f(6.1963680781634, 1.6830714477004);
    glVertex2f(6.1884496739655, 1.6684223999343);
    glVertex2f(6.1773639080884, 1.6557529532177);
    glVertex2f(6.1631107805323, 1.6450631075505);
    glVertex2f(6.1430717701407, 1.6358934957008);
    glVertex2f(6.1215129844446, 1.6278089510648);
    glVertex2f(6.0622263237802, 1.6197244064287);
    glVertex2f(6.1188181362325, 1.670926522457);
    glVertex2f(6.3219525086356, 2.4279527472906);
    glVertex2f(6.3886876176596, 2.4238835333257);
glEnd();
glPopMatrix();

//bayangan D dalam
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(5.7189883108463, 2.2522274642944);
    glVertex2f(5.6473949483208, 2.2522274642944);
    glVertex2f(5.5426762986567, 1.8664781527767);
    glVertex2f(5.6142696611822, 1.8664781527767);
glEnd();
glPopMatrix();
glPopMatrix();//pop perhuruf

//awal A
glPushMatrix();
glTranslated(5.1,0,0);
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(1.9621645802428, 2.1835222133522);
    glVertex2f(1.5087381214781, 1.6098143630591);
    glVertex2f(1.1404979760868, 1.6098143630591);
    glVertex2f(1.852379288109, 2.4784928148988);
    glVertex2f(1.8670139602148, 2.4931274870046);
    glVertex2f(1.8804218587037, 2.5057959759494);
    glVertex2f(1.8954236848525, 2.5139551479206);
    glVertex2f(1.9144725047888, 2.5188616621466);
    glVertex2f(1.9361932351512, 2.5204435456742);
    glVertex2f(2.0140699427988, 2.5204435456742);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.9621645802428, 2.1835222133522);
    glVertex2f(2.1158980821291, 1.61533181888);
    glVertex2f(2.4805969911431, 1.61533181888);
    glVertex2f(2.234287377119, 2.4642917703841);
    glVertex2f(2.2294420360193, 2.4804793844599);
    glVertex2f(2.2215175543086, 2.4928415759285);
    glVertex2f(2.210740259182, 2.5007660576392);
    glVertex2f(2.2002799433239, 2.5083735600815);
    glVertex2f(2.1891856689289, 2.5143961661816);
    glVertex2f(2.1761895189234, 2.5185168966712);
    glVertex2f(2.1641443067232, 2.5201017930133);
    glVertex2f(2.1492462811071, 2.5197848137449);
    glVertex2f(2.0140699427988, 2.5204435456742);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.7926492195341,1.9882400405703);
    glVertex2f(2.0333387017254,1.9882400405703);
    glVertex2f(2.1161358835992, 1.7889491493159);
    glVertex2f(1.6020231496385,1.7889491493159);
glEnd();
glPopMatrix();//pop untuk semua A

//baynagn A pertama
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(2.2737078103396, 2.5170870713101);
    glVertex2f(2.346106268898, 2.502045045505);
    glVertex2f(2.3565480778919, 2.4972848212211);
    glVertex2f(2.3642510250711, 2.4925163301102);
    glVertex2f(2.3704867442162, 2.484813382931);
    glVertex2f(2.3741637204336, 2.4760367260369);
    glVertex2f(2.6285959775602, 1.6107660379072);
    glVertex2f(2.5470927462879, 1.6107660379072);
glEnd();
glPopMatrix();

//bayangan A dalam
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(1.9436881261876, 2.0990715217855);
    glVertex2f(1.8866342720717, 2.0304855056675);
    glVertex2f(1.9552202881898, 2.0304855056675);
glEnd();
glPopMatrix();

//bayangan A bawah
glPushMatrix();
glColor3ub(38, 102, 222);
    glBegin(GL_POLYGON);
    glVertex2f(1.675081166356, 1.74);
    glVertex2f(1.74, 1.74);
    glVertex2f(1.6479385884535, 1.6127604213941);
    glVertex2f(1.5795025496087, 1.6127604213941);
glEnd();
glPopMatrix();
glPopMatrix();

//awal R
glPushMatrix();
glTranslated(5.1,0,0);
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(2.6458488255288, 1.6265276336839);
    glVertex2f(2.8591845309588, 2.4369883556376);
    glVertex2f(2.8644042113367, 2.4487499386729);
    glVertex2f(2.8713201150748, 2.4585998621786);
    glVertex2f(2.8780264459723, 2.4676114943222);
    glVertex2f(2.8851519225509, 2.4747369709008);
    glVertex2f(2.8929061176512, 2.4801858647551);
    glVertex2f(2.9019177497948, 2.4860539042904);
    glVertex2f(2.909671944895, 2.490874079623);
    glVertex2f(2.9178452856764, 2.4956942549556);
    glVertex2f(2.9266473449794, 2.4992569932449);
    glVertex2f(2.9354494042824, 2.5028197315342);
    glVertex2f(2.9457184734693, 2.5055441784614);
    glVertex2f(2.9564066883372, 2.5070111883452);
    glVertex2f(2.9694674244456, 2.5078849311717);
    glVertex2f(3.2190461952251, 2.5078849311717);
    glVertex2f(3.1788760197042, 2.3031720375298);
    glVertex2f(3.1232557766753, 2.089961105919);
    glVertex2f(3.0151929330069, 1.676559649739);
    glVertex2f(3.0126891875189, 1.6685937425244);
    glVertex2f(3.0090424036994, 1.6618759828569);
    glVertex2f(3.0055875558704, 1.6555420951705);
    glVertex2f(3.0013649640795, 1.649975951446);
    glVertex2f(2.995031076393, 1.6444098077216);
    glVertex2f(2.99, 1.64);
    glVertex2f(2.9844291747929, 1.6360027953822);
    glVertex2f(2.9773217612007, 1.6329184460874);
    glVertex2f(2.97, 1.63);
    glVertex2f(2.9633751383026, 1.6282248710737);
    glVertex2f(2.9547170836808, 1.6265276336839);
glEnd();

//R kotak atas
glBegin(GL_POLYGON);
    glVertex2f(3.791945307009, 2.5078849311717);
    glVertex2f(3.8052325896113, 2.5052920143501);
    glVertex2f(3.8183823186558, 2.5009867159752);
    glVertex2f(3.8318466735437, 2.4926169818558);
    glVertex2f(3.842844947166, 2.4803450425026);
    glVertex2f(3.8535913350387, 2.469214855063);
    glVertex2f(3.8604997272426, 2.452711473687);
    glVertex2f(3.859348328542, 2.4339052949097);
    glVertex2f(3.8559253107132, 2.4174958148593);
    glVertex2f(3.737653669978, 1.9658612543854);
    glVertex2f(3.7299400991387, 1.9493413335551);
    glVertex2f(3.724624369679, 1.9380408699866);
    glVertex2f(3.7180725049674, 1.9261656151968);
    glVertex2f(3.7070162332665, 1.9155188350405);
    glVertex2f(3.6963694531102, 1.9048720548841);
    glVertex2f(3.6869511475873, 1.8970917155391);
    glVertex2f(3.6738474181641, 1.890949342372);
    glVertex2f(3.6566487732961, 1.8868544269273);
    glVertex2f(3.6393974611613, 1.8860859471983);
    glVertex2f(3.6209098134671, 1.8832847884567);
    glVertex2f(3.6001812387797, 1.8821643249601);
    glVertex2f(3.5514410766767, 1.8844052519533);
    glVertex2f(3.4126380677392, 2.089961105919);
    glVertex2f(3.4663030891002, 2.3031720375298);
    glVertex2f(3.5, 2.5078849311717);
glEnd();
//penghubung
glBegin(GL_POLYGON);
    glVertex2f(3.2190461952251, 2.5078849311717);
    glVertex2f(3.5, 2.5078849311717);
    glVertex2f(3.4663030891002, 2.3031720375298);
    glVertex2f(3.1788760197042, 2.3031720375298);
glEnd();

//R bagian bawah
glBegin(GL_POLYGON);
    glVertex2f(3.5514410766767, 1.8844052519533);
    glVertex2f(3.6725059031291, 1.6265276336839);
    glVertex2f(3.354789326424, 1.6265276336839);
    glVertex2f(3.345623256988, 1.625983524057);
    glVertex2f(3.3362262644466, 1.625983524057);
    glVertex2f(3.3269037878231, 1.6278656586643);
    glVertex2f(3.3187489758593, 1.6316294180322);
    glVertex2f(3.3116396526088, 1.6353931774001);
    glVertex2f(3.3049485248437, 1.6406206209666);
    glVertex2f(3.2988846903065, 1.6466844555038);
    glVertex2f(3.2935017793452, 1.6534106330943);
    glVertex2f(3.2885149637679, 1.6609300413667);
    glVertex2f(3.1983834191331, 1.8523704708127);
    glVertex2f(3.1730237619811, 1.8730204773508);
    glVertex2f(3.00086057174, 1.8730204773508);
    glVertex2f(3.1232557766753, 2.089961105919);
    glVertex2f(3.4126380677392, 2.089961105919);
glEnd();
glPopMatrix();

//bayangan R pertama
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(3.8817650771712, 2.5031510377038);
    glVertex2f(3.9324772969299, 2.5037256388971);
    glVertex2f(3.95, 2.5);
    glVertex2f(3.9647338360177, 2.4896845571765);
    glVertex2f(3.9768774742625, 2.4771614302365);
    glVertex2f(3.9863646916413, 2.4623613711256);
    glVertex2f(3.9897800898977, 2.4452843798438);
    glVertex2f(3.9876650219343, 2.425007110181);
    glVertex2f(3.9837082707753, 2.4065765329384);
    glVertex2f(3.9111195384829, 2.4158501073091);
    glVertex2f(3.915313032956, 2.4486356095534);
    glVertex2f(3.9168379400372, 2.4600724126619);
    glVertex2f(3.9145505794155, 2.4692218551487);
    glVertex2f(3.9080697243207, 2.4757027102435);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(3.9111195384829, 2.4158501073091);
    glVertex2f(3.9837082707753, 2.4065765329384);
    glVertex2f(3.8604506900418, 1.9480664072166);
    glVertex2f(3.8509518376885, 1.9306203920099);
    glVertex2f(3.8358186349262, 1.9168629349533);
    glVertex2f(3.8156349684108, 1.9053351377545);
    glVertex2f(3.7880531575053, 1.9264423894698);
glEnd();
glPopMatrix();

//bayangan r bawah kanan
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(3.6896388936166,1.8553005009077);
    glVertex2f(3.6255399992371,1.8415650235407);
    glVertex2f(3.7326211643634,1.6224478837532);
    glVertex2f(3.8041012050085,1.6229420087821);
glEnd();
glPopMatrix();

//bayangan R tengah
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(3.2961592847234, 2.2620506368075);
    glVertex2f(3.2267618070983, 2.2620506368075);
    glVertex2f(3.1868582574639, 2.1232556815573);
    glVertex2f(3.2605930774406, 2.1232556815573);
glEnd();
glPopMatrix();

//bayangan r kiri bawah
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(3.1209798004703, 1.8319782041618);
    glVertex2f(3.1718791758208, 1.8319782041618);
    glVertex2f(3.1386965635926, 1.6634802817327);
    glVertex2f(3.0997196847235, 1.632771225654);
    glVertex2f(3.0347582199416, 1.6256845204051);
    glVertex2f(3.0690106286447, 1.6729292220646);
glEnd();
glPopMatrix();
glPopMatrix();

//awal i
glPushMatrix();
glTranslated(5.1,0,0);
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(4.5524780501768, 2.5135281326399);
    glVertex2f(4.2907899838794, 2.5135281326399);
    glVertex2f(4.2789308145986, 2.5114088517959);
    glVertex2f(4.2655916996552, 2.5097770443837);
    glVertex2f(4.2537075703422, 2.507290771101);
    glVertex2f(4.2432851100152, 2.5033554503964);
    glVertex2f(4.2307799006716, 2.497609813671);
    glVertex2f(4.2179367126971, 2.490174283791);
    glVertex2f(4.2050935247225, 2.4807108821256);
    glVertex2f(4.1960544406133, 2.4702280448467);
    glVertex2f(4.1873035191366, 2.4635361637174);
    glVertex2f(4.1790673577467, 2.4542704821539);
    glVertex2f(4.1698016761832, 2.4419162400691);
    glVertex2f(4.1610507547065, 2.4254439172894);
    glVertex2f(4.1538441134903, 2.4100011146835);
    glVertex2f(4.147666992448, 2.3894107112089);
    glVertex2f(3.9410798599561, 1.605329328956);
    glVertex2f(4.2710074007769, 1.605329328956);
    glVertex2f(4.2814851372214, 1.6073189518871);
    glVertex2f(4.2922429713794, 1.6092973218582);
    glVertex2f(4.3031721905707, 1.6127127028555);
    glVertex2f(4.3127352573632, 1.6174942362517);
    glVertex2f(4.3224351711798, 1.6258617676341);
    glVertex2f(4.3275102533549, 1.6345619085057);
    glVertex2f(4.3340353590086, 1.6437453905368);
    glVertex2f(4.3380522213181, 1.6554611511183);
glEnd();
glPopMatrix();

//bayangan i
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(4.6958548402508, 2.5168748337103);
    glVertex2f(4.6190264799031, 2.5198297706467);
    glVertex2f(4.3873796161126, 1.6377228220615);
    glVertex2f(4.3586749817483, 1.6048013178221);
    glVertex2f(4.3880846640902, 1.595419943403);
    glVertex2f(4.4064159115089, 1.5982401353135);
    glVertex2f(4.4233370629723, 1.6017653752017);
    glVertex2f(4.4395531664581, 1.6074057590229);
    glVertex2f(4.4543591739885, 1.6165713827322);
    glVertex2f(4.4614096537649, 1.6320824382403);
glEnd();
glPopMatrix();
glPopMatrix();


//awal K
glPushMatrix();
glTranslated(-0.05,0,0);
glPushMatrix();
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(0.6014716233321, 1.06367026714);
    glVertex2f(0.3301624182099, 1.0669722047277);
    glVertex2f(0.3241297108807, 1.0668918649772);
    glVertex2f(0.3182885363907, 1.0659446474923);
    glVertex2f(0.3127631010623, 1.0646816908458);
    glVertex2f(0.3064483178299, 1.0624715167144);
    glVertex2f(0.3018700999864, 1.0601034730023);
    glVertex2f(0.2965025342388, 1.0577354292901);
    glVertex2f(0.2909770989104, 1.0539465593507);
    glVertex2f(0.2862410114861, 1.0504734285728);
    glVertex2f(0.2808734457385, 1.0465266890525);
    glVertex2f(0.2769267062182, 1.0428956886939);
    glVertex2f(0.2727793144607, 1.0385937426168);
    glVertex2f(0.2673160797472, 1.0333406323153);
    glVertex2f(0.2633237159181, 1.0285077708379);
    glVertex2f(0.259541476501, 1.0247255314209);
    glVertex2f(0.2560809402433, 1.0200276143432);
    glVertex2f(0.2543414823909, 1.0139395118599);
    glVertex2f(0.0605054833844, 0.2552146280838);
    glVertex2f(0.3350040804979, 0.2552146280838);
    glVertex2f(0.3444300571133, 0.2565343072314);
    glVertex2f(0.3530801977588, 0.2584147725891);
    glVertex2f(0.3613542453327, 0.2608593775542);
    glVertex2f(0.3692521998351, 0.2651844478769);
    glVertex2f(0.3765860147302, 0.2700736578069);
    glVertex2f(0.384107876161, 0.274962867737);
    glVertex2f(0.39, 0.28);
    glVertex2f(0.3953950052799, 0.2856399070229);
    glVertex2f(0.4012055581647, 0.2932383223338);
    glVertex2f(0.40567521423, 0.3008367376448);
    glVertex2f(0.4101448702953, 0.3111169465949);
glEnd();
//cabang kanan atas
glBegin(GL_POLYGON);
    glVertex2f(0.0605054833844, 0.2552146280838);
    glVertex2f(0.5091909252192, 0.7220773621279);
    glVertex2f(0.8139346826974, 1.02519451687);
    glVertex2f(0.8217639203241, 1.0347404921073);
    glVertex2f(0.8291711769886, 1.0415990630929);
    glVertex2f(0.8387731763685, 1.0490063197574);
    glVertex2f(0.8494725471061, 1.0553162050642);
    glVertex2f(0.86, 1.06);
    glVertex2f(0.8703226029025, 1.0629978045681);
    glVertex2f(0.8817073627633, 1.0648817521538);
    glVertex2f(0.8950666192919, 1.0653955697126);
    glVertex2f(1.1763265054587, 1.0653955697126);
    glVertex2f(0.7809166100186, 0.6554891866943);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(0.5091909252192, 0.7220773621279);
    glVertex2f(0.7809166100186, 0.6554891866943);
    glVertex2f(0.976820368018, 0.2552146280838);
    glVertex2f(0.7, 0.25);
    glVertex2f(0.6867410566955, 0.2505843395899);
    glVertex2f(0.6740676652021, 0.2526010285215);
    glVertex2f(0.6607760372154, 0.2572921913403);
    glVertex2f(0.6490481301683, 0.2661532766648);
    glVertex2f(0.6405735145021, 0.275490513668);
    glVertex2f(0.444981864183, 0.6966910489487);
glEnd();
glPopMatrix();

//bayangan atas
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(0.7198238344682, 1.063886767645);
    glVertex2f(0.6502248760637, 1.063886767645);
    glVertex2f(0.6038255704608,0.8802228496332);
    glVertex2f(0.6975908338668, 0.9652882432387);
glEnd();
glPopMatrix();

//bayangan kanan atas
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(1.3022882782989, 1.0651776813511);
    glVertex2f(1.2366128854383, 1.0651776813511);
    glVertex2f(0.8402701664164, 0.6570401719712);
    glVertex2f(0.9072166258456, 0.6561103600347);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1.1008379785892, 0.2558999919079);
glVertex2f(1.0299943645031,0.2558999919079);
glVertex2f(0.8402701664164, 0.6570401719712);
glVertex2f(0.9072166258456, 0.6561103600347);
glEnd();
glPopMatrix();
//bayangan k bawah
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(0.4294584974043, 0.2602595989285);
    glVertex2f(0.4872232904283, 0.2657091077044);
    glVertex2f(0.499711240479, 0.2673024656929);
    glVertex2f(0.5088221557832, 0.2720559867212);
    glVertex2f(0.5151601838208, 0.2799785217683);
    glVertex2f(0.5369471552003, 0.362372886258);
    glVertex2f(0.492977085689, 0.4404098564718);
glEnd();
glPopMatrix();
glPopMatrix();//untuk perhuruf

//awal E
glPushMatrix();
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(1.4141361155539, 1.0429085815876);
    glVertex2f(1.3997439271269, 1.0406361307833);
    glVertex2f(1.3861693982765, 1.0362168298865);
    glVertex2f(1.3741161525527, 1.0300273253256);
    glVertex2f(1.3623886702268, 1.0235120573668);
    glVertex2f(1.3496838977071, 1.0147164456223);
    glVertex2f(1.3369791251873, 1.0046177802862);
    glVertex2f(1.3246001160656, 0.994193351552);
    glVertex2f(1.3145014507294, 0.9811628156344);
    glVertex2f(1.3058159605502, 0.9671602214451);
    glVertex2f(1.1514569473688, 0.3613198651423);
    glVertex2f(1.1490594662523, 0.3491991567914);
    glVertex2f(1.1474095146019, 0.3392994468888);
    glVertex2f(1.1474095146019, 0.3277497853357);
    glVertex2f(1.1474095146019, 0.3186750512583);
    glVertex2f(1.1490594662523, 0.3075378776178);
    glVertex2f(1.1523593695532, 0.2972256798026);
    glVertex2f(1.1577217124171, 0.2865009940747);
    glVertex2f(1.163084055281, 0.2786637237351);
    glVertex2f(1.1700963497954, 0.2712389413082);
    glVertex2f(1.1787585959602, 0.262989183056);
    glVertex2f(1.1865958662998, 0.2563893764542);
    glVertex2f(1.1960830882898, 0.2522644973281);
    glVertex2f(1.2068077740177, 0.2493770819398);
    glVertex2f(1.2197758932616, 0.2468669623662);
    glVertex2f(1.45, 0.2468669623662);
    glVertex2f(1.599898931141, 1.0429085815876);
glEnd();
glBegin(GL_POLYGON);
    glVertex2f(1.599898931141, 1.0429085815876);
    glVertex2f(2.1661681886142, 1.0429085815876);
    glVertex2f(2.137719519134, 0.9282030661677);
    glVertex2f(2.1343726168422, 0.9192779933896);
    glVertex2f(2.1298677880135, 0.9110040857604);
    glVertex2f(2.1249246951895, 0.9026008279596);
    glVertex2f(2.1197344477242, 0.8941975701587);
    glVertex2f(2.1140498909766, 0.8877715494875);
    glVertex2f(2.1063880970994, 0.8813455288163);
    glVertex2f(2.0979848392985, 0.8756609720687);
    glVertex2f(2.0909235359956, 0.8706833351943);
    glVertex2f(2.0812466695651, 0.8664987443055);
    glVertex2f(2.0720928769956, 0.8628372272777);
    glVertex2f(2.0607407664228, 0.8595915691859);
    glVertex2f(2.0501422424988, 0.85791811804);
    glVertex2f(1.4711841006895, 0.85791811804);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.6053633320831, 0.8535488775697);
    glVertex2f(1.4944506234642, 0.4378598981266);
    glVertex2f(1.3644706938264, 0.7076667217688);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.5678281129647, 0.7459202482864);
    glVertex2f(1.9831008324213, 0.7459202482864);
    glVertex2f(1.9440161219694, 0.6158514577661);
    glVertex2f(1.9422908418467, 0.6102155315729);
    glVertex2f(1.9394862877191, 0.6037950324851);
    glVertex2f(1.9363837635411, 0.5977838918902);
    glVertex2f(1.9319238850352, 0.5911910280119);
    glVertex2f(1.9274074722863, 0.5867105992223);
    glVertex2f(1.922688937618, 0.5817060927559);
    glVertex2f(1.917128517009, 0.5781878566584);
    glVertex2f(1.9106325254457, 0.573640662564);
    glVertex2f(1.9025125359915, 0.569743067626);
    glVertex2f(1.8940677469591, 0.5651958735317);
    glVertex2f(1.8852981583485, 0.5616230781718);
    glVertex2f(1.8755541710035, 0.558050282812);
    glVertex2f(1.8622373882986, 0.5554518861866);
    glVertex2f(1.5055480261976, 0.5554518861866);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.6053633320831, 0.8535488775697);
    glVertex2f(1.5678281129647, 0.7459202482864);
    glVertex2f(1.4926239428177, 0.7514804834146);
    glVertex2f(1.5017362123609, 0.8681175335681);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.1906949963177, 0.438079180306);
    glVertex2f(2.011913420326, 0.438079180306);
    glVertex2f(1.9787108856049, 0.3187996450024);
    glVertex2f(1.9750637481199, 0.3083136409088);
    glVertex2f(1.9704149779398, 0.2987255524123);
    glVertex2f(1.9643134670783, 0.2914618490059);
    glVertex2f(1.9570497636719, 0.2827454049181);
    glVertex2f(1.9480427714479, 0.2743195089667);
    glVertex2f(1.9381543140374, 0.2653464062914);
    glVertex2f(1.9274812937461, 0.2586447423875);
    glVertex2f(1.9158154343578, 0.2531841273547);
    glVertex2f(1.9025443990318, 0.2491492982117);
    glVertex2f(1.8881898553789, 0.2468669623662);
    glVertex2f(1.45, 0.2468669623662);
glEnd();
glPopMatrix();

//bayangan pertama
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(2.2846627167242, 1.0325060130046);
    glVertex2f(2.221521272478, 1.0379181367971);
    glVertex2f(2.1926566122512, 0.9206554546258);
    glVertex2f(2.1331232505335, 0.861122092908);
    glVertex2f(2.1599177115864, 0.8615157660196);
    glVertex2f(2.1801231946026, 0.8670263522967);
    glVertex2f(2.1994102465725, 0.8734553696201);
    glVertex2f(2.2177788674963, 0.8835581111281);
    glVertex2f(2.2352290573739, 0.9000898699595);
    glVertex2f(2.2508423851591, 0.922132215068);
glEnd();
glPopMatrix();

//bayangan 2
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(1.7070897421691, 0.8214962954639);
    glVertex2f(1.6393781031071, 0.8214962954639);
    glVertex2f(1.6268876065811, 0.7748212821299);
    glVertex2f(1.6978862184131, 0.7748212821299);
glEnd();
glPopMatrix();


//bayangan 3
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(2.0934974563451, 0.7387713135869);
    glVertex2f(2.0269500145666, 0.7395190376518);
    glVertex2f(1.9984414435166, 0.6057065805911);
    glVertex2f(1.9402140230352, 0.5570743658098);
    glVertex2f(1.984528185836, 0.5578286056313);
    glVertex2f(2.0179773257875, 0.5682902267837);
    glVertex2f(2.0404090477353, 0.586235604342);
    glVertex2f(2.0613453215533, 0.6124059466144);
glEnd();
glPopMatrix();

//bayangan ketiga
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(1.6344421794258, 0.5194067693207);
    glVertex2f(1.5650381329417, 0.5208231784326);
    glVertex2f(1.5522904509344, 0.4726652686273);
    glVertex2f(1.6202780883066, 0.4684160412915);
glEnd();
glPopMatrix();

//bayangan terakhir
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(2.1330112854566, 0.4330699592993);
    glVertex2f(2.0592942128176, 0.4330699592993);
    glVertex2f(2.026165001029, 0.3064993809275);
    glVertex2f(1.9751969828927, 0.258079763698);
    glVertex2f(2.0312618028426, 0.2640260324806);
    glVertex2f(2.0493475314966, 0.2661411651201);
    glVertex2f(2.0641980595265, 0.2712460341304);
    glVertex2f(2.0762641135508, 0.2786712981454);
    glVertex2f(2.0860097725704, 0.288416957165);
    glVertex2f(2.0933280611487, 0.3023943714902);
glEnd();
glPopMatrix();
glPopMatrix();//untuk perhuruf

//awal N
glPushMatrix();
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(2.6099568483078, 0.6923453776542);
    glVertex2f(2.6591277302314, 1.0597505164993);
    glVertex2f(2.4643674999768, 1.0597505164993);
    glVertex2f(2.456332938035, 1.0581426576858);
    glVertex2f(2.4493752346393, 1.0560175691797);
    glVertex2f(2.443557230223, 1.0537359988203);
    glVertex2f(2.4378533043247, 1.0509981143892);
    glVertex2f(2.4322634569444, 1.0479179944041);
    glVertex2f(2.426673609564, 1.0443815603471);
    glVertex2f(2.4215400762556, 1.0392480270386);
    glVertex2f(2.4163095502863, 1.0348497712987);
    glVertex2f(2.4113993308068, 1.0292699764357);
    glVertex2f(2.4071586867109, 1.0225742226001);
    glVertex2f(2.1968719495552, 0.2335868721963);
    glVertex2f(2.4437305767249, 0.2335868721963);
    glVertex2f(2.452260531877, 0.2357090225237);
    glVertex2f(2.4588586055775, 0.2378043219789);
    glVertex2f(2.4652217912047, 0.240889502889);
    glVertex2f(2.4715655337501, 0.2435020567663);
    glVertex2f(2.4771264285855, 0.2468038380748);
    glVertex2f(2.4832086573118, 0.2495842854926);
    glVertex2f(2.4892908860381, 0.2534074006919);
    glVertex2f(2.4939828910555, 0.2593158514546);
    glVertex2f(2.498580309796, 0.2653781263636);
    glVertex2f(2.5030152573544, 0.2711628405701);
    glVertex2f(2.5068717334921, 0.2769475547767);
    glVertex2f(2.5097640905954, 0.2835035642109);
    glVertex2f(2.5118851524712, 0.2894811022243);
    glVertex2f(2.5134277429263, 0.2962299354653);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(3, 0.6);
    glVertex2f(3.1068311723757, 0.9897625330761);
    glVertex2f(3.1115732493086, 1.0006015660656);
    glVertex2f(3.1154730790675, 1.0109069072168);
    glVertex2f(3.124664659597, 1.0192874659348);
    glVertex2f(3.1333155589188, 1.0276680246528);
    glVertex2f(3.142777480052, 1.0341561991442);
    glVertex2f(3.1530504229967, 1.0406443736355);
    glVertex2f(3.1633939658269, 1.0469547929091);
    glVertex2f(3.1746776713013, 1.0514579977878);
    glVertex2f(3.1868429984726, 1.0547020850335);
    glVertex2f(3.4082295181079, 1.0547020850335);
    glVertex2f(3.2095320899307, 0.280399456811);
    glVertex2f(3.15009739849, 0.2335868721963);
    glVertex2f(2.8242575691306, 0.2335868721963);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(2.6591277302314, 1.0597505164993);
    glVertex2f(2.8369397399308, 1.0597505164993);
    glVertex2f(3, 0.6);
    glVertex2f(2.8242575691306, 0.2335868721963);
    glVertex2f(2.8118380327743, 0.2349559725431);
    glVertex2f(2.8019980191726, 0.2371084755185);
    glVertex2f(2.7930805068461, 0.2404909801941);
    glVertex2f(2.7853929962198, 0.24571848742);
    glVertex2f(2.7792429877187, 0.2527909971962);
    glVertex2f(2.7744430186422, 0.260576728979);
    glVertex2f(2.6099568483078, 0.6923453776542);
glEnd();
glPopMatrix();


//bayangan 1
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(2.8905746219682, 1.0562902786363);
    glVertex2f(2.9583721549204, 1.0591151758427);
    glVertex2f(3.0304070336822, 0.8825591004463);
    glVertex2f(2.9922709213965, 0.7829814739227);
glEnd();
glPopMatrix();

//bayangan 2
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(3.5367521573185, 1.0467237601063);
    glVertex2f(3.4561245632876, 1.0467237601063);
    glVertex2f(3.2706810970166, 0.2834492032809);
    glVertex2f(3.2276797135335, 0.2431354062654);
    glVertex2f(3.2548171082978, 0.2413051053142);
    glVertex2f(3.2827505116501, 0.2390402347721);
    glVertex2f(3.3076640876129, 0.2443249327036);
    glVertex2f(3.3270867167245, 0.2598701365654);
glEnd();
glPopMatrix();
//terakhir
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(2.6162515519117, 0.5086194112428);
    glVertex2f(2.6555943734842, 0.4160480663663);
    glVertex2f(2.6208801191555, 0.2841338999173);
    glVertex2f(2.5931087156925, 0.2424767947229);
    glVertex2f(2.5278642994259, 0.2409543632764);
    glVertex2f(2.5583944613639, 0.2663961648913);
glEnd();
glPopMatrix();
glPopMatrix();//untuk perhuruf

//awal Y
glPushMatrix();
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(3.9400775378873, 1.0374862747794);
    glVertex2f(3.5882006850779, 1.0374862747794);
    glVertex2f(3.8277735877903, 0.6291466051945);
    glVertex2f(4.0528357581855, 0.8601706873882);
glEnd();


//Y kedua
glBegin(GL_POLYGON);
    glVertex2f(4.0528357581855, 0.8601706873882);//c
    glVertex2f(4.2375315681022, 1.0224107160664);//d
    glVertex2f(4.2375315681022, 1.0224107160664);
    glVertex2f(4.2424178739286, 1.0275841055796);
    glVertex2f(4.2477052788833, 1.0315853850048);
    glVertex2f(4.2532784895111, 1.0354437615933);
    glVertex2f(4.2580448740031, 1.0387873448551);
    glVertex2f(4.2634353096455, 1.0414825626763);
    glVertex2f(4.2691407043752, 1.0431605147704);
    glVertex2f(4.2751426235129, 1.0445895431365);
    glVertex2f(4.2822258741715, 1.0457318430931);
    glVertex2f(4.2893570611639, 1.0461775422802);
    glVertex2f(4.6016433590676, 1.0461775422802);//f
    glVertex2f(4.1468654304783, 0.6192736360224);//g
glEnd();
//Y bawah
glBegin(GL_POLYGON);
    glVertex2f(4.0520727586852, 0.8624737611564);
    glVertex2f(3.8277735877903, 0.6291466051945);
    glVertex2f(3.7266906633178, 0.2526304026756);
    glVertex2f(3.9981622827601, 0.2526304026756);
    glVertex2f(4.0487629953059, 0.2836477883207);
    glVertex2f(4.1468654304783, 0.6192736360224);
glEnd();
glPopMatrix();

//bayangan
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(4.0617984318377,1.0408712640904);
    glVertex2f(4.0010020045617,1.0378595166734);
    glVertex2f(4.0716372349471,0.9332147309173);
    glVertex2f(4.1082629099617,0.9667010623593);
glEnd();
glPopMatrix();

//bayangan 2
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(4.7267806439563,1.0386031105178);
    glVertex2f(4.6749106433647,1.0386031105178);
    glVertex2f(4.1967849616048,0.6138706271799);
    glVertex2f(4.2603220640102,0.6095187708508);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(4.078373613695, 0.2530026627863);
    glVertex2f(4.1124766709315, 0.28840782968);
    glVertex2f(4.1967849616048, 0.6138706271799);
    glVertex2f(4.2603220640102, 0.6095187708508);
    glVertex2f(4.1708633526363, 0.2922012540942);
    glVertex2f(4.1610400851479, 0.2745446384328);
    glVertex2f(4.1458354854569, 0.2633221958038);
    glVertex2f(4.1190464288586, 0.2549958674016);
glEnd();
glPopMatrix();
glPopMatrix();//untuk perhuruf

//Awal a
glPushMatrix();
glTranslated(3.25,-1.1,0);
glScaled(0.85,0.85,0);
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(1.9621645802428, 2.1835222133522);
    glVertex2f(1.5087381214781, 1.6098143630591);
    glVertex2f(1.1404979760868, 1.6098143630591);
    glVertex2f(1.852379288109, 2.4784928148988);
    glVertex2f(1.8670139602148, 2.4931274870046);
    glVertex2f(1.8804218587037, 2.5057959759494);
    glVertex2f(1.8954236848525, 2.5139551479206);
    glVertex2f(1.9144725047888, 2.5188616621466);
    glVertex2f(1.9361932351512, 2.5204435456742);
    glVertex2f(2.0140699427988, 2.5204435456742);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.9621645802428, 2.1835222133522);
    glVertex2f(2.1158980821291, 1.61533181888);
    glVertex2f(2.4805969911431, 1.61533181888);
    glVertex2f(2.234287377119, 2.4642917703841);
    glVertex2f(2.2294420360193, 2.4804793844599);
    glVertex2f(2.2215175543086, 2.4928415759285);
    glVertex2f(2.210740259182, 2.5007660576392);
    glVertex2f(2.2002799433239, 2.5083735600815);
    glVertex2f(2.1891856689289, 2.5143961661816);
    glVertex2f(2.1761895189234, 2.5185168966712);
    glVertex2f(2.1641443067232, 2.5201017930133);
    glVertex2f(2.1492462811071, 2.5197848137449);
    glVertex2f(2.0140699427988, 2.5204435456742);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.7926492195341,1.9882400405703);
    glVertex2f(2.0333387017254,1.9882400405703);
    glVertex2f(2.1161358835992, 1.7889491493159);
    glVertex2f(1.6020231496385,1.7889491493159);
glEnd();
glPopMatrix();

//baynagn A pertama
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(2.2737078103396, 2.5170870713101);
    glVertex2f(2.346106268898, 2.502045045505);
    glVertex2f(2.3565480778919, 2.4972848212211);
    glVertex2f(2.3642510250711, 2.4925163301102);
    glVertex2f(2.3704867442162, 2.484813382931);
    glVertex2f(2.3741637204336, 2.4760367260369);
    glVertex2f(2.6285959775602, 1.6107660379072);
    glVertex2f(2.5470927462879, 1.6107660379072);
glEnd();
glPopMatrix();

//bayangan A dalam
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(1.9436881261876, 2.0990715217855);
    glVertex2f(1.8866342720717, 2.0304855056675);
    glVertex2f(1.9552202881898, 2.0304855056675);
glEnd();
glPopMatrix();

//bayangan A bawah
glPushMatrix();
glColor3ub(38, 102, 222);
    glBegin(GL_POLYGON);
    glVertex2f(1.675081166356, 1.74);
    glVertex2f(1.74, 1.74);
    glVertex2f(1.6479385884535, 1.6127604213941);
    glVertex2f(1.5795025496087, 1.6127604213941);
glEnd();
glPopMatrix();
glPopMatrix();//pop untuk semua A


//awal T
glPushMatrix();
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(6.3629269937646, 1.0556134646215);
    glVertex2f(5.5174382464632, 1.0556134646215);
    glVertex2f(5.508440321821, 1.0537655787358);
    glVertex2f(5.500257448647, 1.0519204586707);
    glVertex2f(5.4915933438237, 1.0479494106267);
    glVertex2f(5.4829292390005, 1.0428953494798);
    glVertex2f(5.4763130592132, 1.0365207980714);
    glVertex2f(5.4694623929218, 1.0299063616521);
    glVertex2f(5.4645015656074, 1.0242368447213);
    glVertex2f(5.4607218876535, 1.01738617843);
    glVertex2f(5.422715507383, 0.8734333521093);
    glVertex2f(6.2295336190868, 0.8734333521093);
    glVertex2f(6.2435088922156, 0.8760827550086);
    glVertex2f(6.26, 0.88);
    glVertex2f(6.2711373781544, 0.8848876846999);
    glVertex2f(6.2827477682137, 0.8894524766839);
    glVertex2f(6.2930420972252, 0.8953590589036);
    glVertex2f(6.3031722117992, 0.9041597233842);
    glVertex2f(6.3119021504921, 0.911434672295);
    glVertex2f(6.32, 0.92);
    glVertex2f(6.3251468797049, 0.931835870659);
glEnd();
//T bawah
glBegin(GL_POLYGON);
    glVertex2f(5.7055524455462, 0.8734333521093);
    glVertex2f(5.543109398381, 0.2509662870819);
    glVertex2f(5.8247756565096, 0.2509662870819);
    glVertex2f(5.8354082036691, 0.2540193825738);
    glVertex2f(5.8443654116249, 0.2574671591666);
    glVertex2f(5.8517612551453, 0.2611650809268);
    glVertex2f(5.857924458079, 0.264863002687);
    glVertex2f(5.8644985412082, 0.2685609244472);
    glVertex2f(5.8700454238485, 0.2736969268919);
    glVertex2f(5.8743736569128, 0.2784629375989);
    glVertex2f(5.8792325505782, 0.2840159589308);
    glVertex2f(5.8828273757267, 0.2901150532118);
    glVertex2f(5.8852610334124, 0.296806528887);
    glVertex2f(6.0324861160736, 0.8734333521093);
glEnd();
glPopMatrix();

//bayangan pertama
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(6.4859682105319, 1.057466981433);
    glVertex2f(6.4150757572558, 1.0567128063981);
    glVertex2f(6.383400405792, 0.9420782011005);
    glVertex2f(6.3215580529341, 0.8749566229987);
    glVertex2f(6.3600209797115, 0.8764649730684);
    glVertex2f(6.3827348758701, 0.8827731914623);
    glVertex2f(6.3999411195066, 0.8889787219541);
    glVertex2f(6.4150645992518, 0.8982427361899);
    glVertex2f(6.4266207576543, 0.9093544269616);
    glVertex2f(6.4377010083014, 0.9262405253686);
    glVertex2f(6.4459969336847, 0.9405698510308);
glEnd();
glPopMatrix();

//bayangan kedua
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(6.1446431235621, 0.8223561110949);
    glVertex2f(6.0734866707407, 0.8223561110949);
    glVertex2f(5.935962548241, 0.2869836132087);
    glVertex2f(5.9063981550734, 0.2519443324175);
    glVertex2f(5.9274035323396, 0.2518645306182);
    glVertex2f(5.9446418237647, 0.2557006224189);
    glVertex2f(5.96, 0.26);
    glVertex2f(5.9740540710291, 0.2693092741383);
    glVertex2f(5.9859067676879, 0.2798450045016);
    glVertex2f(5.9933695766952, 0.2916977011604);
glEnd();
glPopMatrix();
glPopMatrix();//pop untuk semua T

//Awal a
glPushMatrix();
glTranslated(6.35,-1.1,0);
glScaled(0.85,0.85,0);
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(1.9621645802428, 2.1835222133522);
    glVertex2f(1.5087381214781, 1.6098143630591);
    glVertex2f(1.1404979760868, 1.6098143630591);
    glVertex2f(1.852379288109, 2.4784928148988);
    glVertex2f(1.8670139602148, 2.4931274870046);
    glVertex2f(1.8804218587037, 2.5057959759494);
    glVertex2f(1.8954236848525, 2.5139551479206);
    glVertex2f(1.9144725047888, 2.5188616621466);
    glVertex2f(1.9361932351512, 2.5204435456742);
    glVertex2f(2.0140699427988, 2.5204435456742);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.9621645802428, 2.1835222133522);
    glVertex2f(2.1158980821291, 1.61533181888);
    glVertex2f(2.4805969911431, 1.61533181888);
    glVertex2f(2.234287377119, 2.4642917703841);
    glVertex2f(2.2294420360193, 2.4804793844599);
    glVertex2f(2.2215175543086, 2.4928415759285);
    glVertex2f(2.210740259182, 2.5007660576392);
    glVertex2f(2.2002799433239, 2.5083735600815);
    glVertex2f(2.1891856689289, 2.5143961661816);
    glVertex2f(2.1761895189234, 2.5185168966712);
    glVertex2f(2.1641443067232, 2.5201017930133);
    glVertex2f(2.1492462811071, 2.5197848137449);
    glVertex2f(2.0140699427988, 2.5204435456742);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.7926492195341,1.9882400405703);
    glVertex2f(2.0333387017254,1.9882400405703);
    glVertex2f(2.1161358835992, 1.7889491493159);
    glVertex2f(1.6020231496385,1.7889491493159);
glEnd();
glPopMatrix();

//baynagn A pertama
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(2.2737078103396, 2.5170870713101);
    glVertex2f(2.346106268898, 2.502045045505);
    glVertex2f(2.3565480778919, 2.4972848212211);
    glVertex2f(2.3642510250711, 2.4925163301102);
    glVertex2f(2.3704867442162, 2.484813382931);
    glVertex2f(2.3741637204336, 2.4760367260369);
    glVertex2f(2.6285959775602, 1.6107660379072);
    glVertex2f(2.5470927462879, 1.6107660379072);
glEnd();
glPopMatrix();

//bayangan A dalam
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(1.9436881261876, 2.0990715217855);
    glVertex2f(1.8866342720717, 2.0304855056675);
    glVertex2f(1.9552202881898, 2.0304855056675);
glEnd();
glPopMatrix();

//bayangan A bawah
glPushMatrix();
glColor3ub(38, 102, 222);
    glBegin(GL_POLYGON);
    glVertex2f(1.675081166356, 1.74);
    glVertex2f(1.74, 1.74);
    glVertex2f(1.6479385884535, 1.6127604213941);
    glVertex2f(1.5795025496087, 1.6127604213941);
glEnd();
glPopMatrix();
glPopMatrix();//pop untuk semua A

//Awal a
glPushMatrix();
glTranslated(5.1,-1.1,0);
glScaled(0.85,0.85,0);
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(1.9621645802428, 2.1835222133522);
    glVertex2f(1.5087381214781, 1.6098143630591);
    glVertex2f(1.1404979760868, 1.6098143630591);
    glVertex2f(1.852379288109, 2.4784928148988);
    glVertex2f(1.8670139602148, 2.4931274870046);
    glVertex2f(1.8804218587037, 2.5057959759494);
    glVertex2f(1.8954236848525, 2.5139551479206);
    glVertex2f(1.9144725047888, 2.5188616621466);
    glVertex2f(1.9361932351512, 2.5204435456742);
    glVertex2f(2.0140699427988, 2.5204435456742);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.9621645802428, 2.1835222133522);
    glVertex2f(2.1158980821291, 1.61533181888);
    glVertex2f(2.4805969911431, 1.61533181888);
    glVertex2f(2.234287377119, 2.4642917703841);
    glVertex2f(2.2294420360193, 2.4804793844599);
    glVertex2f(2.2215175543086, 2.4928415759285);
    glVertex2f(2.210740259182, 2.5007660576392);
    glVertex2f(2.2002799433239, 2.5083735600815);
    glVertex2f(2.1891856689289, 2.5143961661816);
    glVertex2f(2.1761895189234, 2.5185168966712);
    glVertex2f(2.1641443067232, 2.5201017930133);
    glVertex2f(2.1492462811071, 2.5197848137449);
    glVertex2f(2.0140699427988, 2.5204435456742);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.7926492195341,1.9882400405703);
    glVertex2f(2.0333387017254,1.9882400405703);
    glVertex2f(2.1161358835992, 1.7889491493159);
    glVertex2f(1.6020231496385,1.7889491493159);
glEnd();
glPopMatrix();

//baynagn A pertama
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(2.2737078103396, 2.5170870713101);
    glVertex2f(2.346106268898, 2.502045045505);
    glVertex2f(2.3565480778919, 2.4972848212211);
    glVertex2f(2.3642510250711, 2.4925163301102);
    glVertex2f(2.3704867442162, 2.484813382931);
    glVertex2f(2.3741637204336, 2.4760367260369);
    glVertex2f(2.6285959775602, 1.6107660379072);
    glVertex2f(2.5470927462879, 1.6107660379072);
glEnd();
glPopMatrix();

//bayangan A dalam
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(1.9436881261876, 2.0990715217855);
    glVertex2f(1.8866342720717, 2.0304855056675);
    glVertex2f(1.9552202881898, 2.0304855056675);
glEnd();
glPopMatrix();

//bayangan A bawah
glPushMatrix();
glColor3ub(38, 102, 222);
    glBegin(GL_POLYGON);
    glVertex2f(1.675081166356, 1.74);
    glVertex2f(1.74, 1.74);
    glVertex2f(1.6479385884535, 1.6127604213941);
    glVertex2f(1.5795025496087, 1.6127604213941);
glEnd();
glPopMatrix();
glPopMatrix();//pop untuk semua A

//awal N
glPushMatrix();
glTranslated(6.4,0,0);
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(2.6099568483078, 0.6923453776542);
    glVertex2f(2.6591277302314, 1.0597505164993);
    glVertex2f(2.4643674999768, 1.0597505164993);
    glVertex2f(2.456332938035, 1.0581426576858);
    glVertex2f(2.4493752346393, 1.0560175691797);
    glVertex2f(2.443557230223, 1.0537359988203);
    glVertex2f(2.4378533043247, 1.0509981143892);
    glVertex2f(2.4322634569444, 1.0479179944041);
    glVertex2f(2.426673609564, 1.0443815603471);
    glVertex2f(2.4215400762556, 1.0392480270386);
    glVertex2f(2.4163095502863, 1.0348497712987);
    glVertex2f(2.4113993308068, 1.0292699764357);
    glVertex2f(2.4071586867109, 1.0225742226001);
    glVertex2f(2.1968719495552, 0.2335868721963);
    glVertex2f(2.4437305767249, 0.2335868721963);
    glVertex2f(2.452260531877, 0.2357090225237);
    glVertex2f(2.4588586055775, 0.2378043219789);
    glVertex2f(2.4652217912047, 0.240889502889);
    glVertex2f(2.4715655337501, 0.2435020567663);
    glVertex2f(2.4771264285855, 0.2468038380748);
    glVertex2f(2.4832086573118, 0.2495842854926);
    glVertex2f(2.4892908860381, 0.2534074006919);
    glVertex2f(2.4939828910555, 0.2593158514546);
    glVertex2f(2.498580309796, 0.2653781263636);
    glVertex2f(2.5030152573544, 0.2711628405701);
    glVertex2f(2.5068717334921, 0.2769475547767);
    glVertex2f(2.5097640905954, 0.2835035642109);
    glVertex2f(2.5118851524712, 0.2894811022243);
    glVertex2f(2.5134277429263, 0.2962299354653);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(3, 0.6);
    glVertex2f(3.1068311723757, 0.9897625330761);
    glVertex2f(3.1115732493086, 1.0006015660656);
    glVertex2f(3.1154730790675, 1.0109069072168);
    glVertex2f(3.124664659597, 1.0192874659348);
    glVertex2f(3.1333155589188, 1.0276680246528);
    glVertex2f(3.142777480052, 1.0341561991442);
    glVertex2f(3.1530504229967, 1.0406443736355);
    glVertex2f(3.1633939658269, 1.0469547929091);
    glVertex2f(3.1746776713013, 1.0514579977878);
    glVertex2f(3.1868429984726, 1.0547020850335);
    glVertex2f(3.4082295181079, 1.0547020850335);
    glVertex2f(3.2095320899307, 0.280399456811);
    glVertex2f(3.15009739849, 0.2335868721963);
    glVertex2f(2.8242575691306, 0.2335868721963);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(2.6591277302314, 1.0597505164993);
    glVertex2f(2.8369397399308, 1.0597505164993);
    glVertex2f(3, 0.6);
    glVertex2f(2.8242575691306, 0.2335868721963);
    glVertex2f(2.8118380327743, 0.2349559725431);
    glVertex2f(2.8019980191726, 0.2371084755185);
    glVertex2f(2.7930805068461, 0.2404909801941);
    glVertex2f(2.7853929962198, 0.24571848742);
    glVertex2f(2.7792429877187, 0.2527909971962);
    glVertex2f(2.7744430186422, 0.260576728979);
    glVertex2f(2.6099568483078, 0.6923453776542);
glEnd();
glPopMatrix();


//bayangan 1
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(2.8905746219682, 1.0562902786363);
    glVertex2f(2.9583721549204, 1.0591151758427);
    glVertex2f(3.0304070336822, 0.8825591004463);
    glVertex2f(2.9922709213965, 0.7829814739227);
glEnd();
glPopMatrix();

//bayangan 2
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(3.5367521573185, 1.0467237601063);
    glVertex2f(3.4561245632876, 1.0467237601063);
    glVertex2f(3.2706810970166, 0.2834492032809);
    glVertex2f(3.2276797135335, 0.2431354062654);
    glVertex2f(3.2548171082978, 0.2413051053142);
    glVertex2f(3.2827505116501, 0.2390402347721);
    glVertex2f(3.3076640876129, 0.2443249327036);
    glVertex2f(3.3270867167245, 0.2598701365654);
glEnd();
glPopMatrix();
//terakhir
glPushMatrix();
glColor3ub(38, 102, 222);
glBegin(GL_POLYGON);
    glVertex2f(2.6162515519117, 0.5086194112428);
    glVertex2f(2.6555943734842, 0.4160480663663);
    glVertex2f(2.6208801191555, 0.2841338999173);
    glVertex2f(2.5931087156925, 0.2424767947229);
    glVertex2f(2.5278642994259, 0.2409543632764);
    glVertex2f(2.5583944613639, 0.2663961648913);
glEnd();
glPopMatrix();
glPopMatrix();
glPopMatrix();//untuk perhuruf


////////////////////////
glPopMatrix();//untuk seluruh vertex
}

void aboutDisplay(){
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPushMatrix();
    glScaled(2,2,0);
    glColor3ub(147, 168, 212);
    glBegin(GL_QUADS);
        glVertex2f(1, 4);
        glVertex2f(1, 2);
        glColor3ub(81, 103, 39);
        glVertex2f(4, 2);
        glVertex2f(4, 4);
    glEnd();
    glPopMatrix();
}

void blackScreen(){
    glPushMatrix();
    glBegin(GL_QUADS);
        glColor3ub(0,0,0);
        glVertex2f(0,0);
        glVertex2f(10,0);
        glVertex2f(10,10);
        glVertex2f(0,10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    textPlay(0,0,"Again");
    textAbout(0,0,"About");
    textExit(0,0,"End");
    glPopMatrix();
}

void arahPanah (){
    glPushMatrix();
    glTranslated(3.3,2.9,0);
    glScaled(0.3,0.3,0);
    glColor3ub(148, 143, 143);
    glBegin(GL_POLYGON);
        glVertex2f(1.467732861856, 3.0644273083918);
        glVertex2f(3.0971178154019, 2.3904011585437);
        glVertex2f(2.1065924299729, 2.3904011585437);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(2.1065924299729, 2.3904011585437);
        glVertex2f(3.0971178154019, 2.3904011585437);
        glVertex2f(1.4735939588112, 1.7456804934716);
    glEnd();

    glLineWidth(3);
    glColor3ub(48, 48, 48);
    glBegin(GL_LINE_LOOP);
        glVertex2f(1.467732861856, 3.0644273083918);
        glVertex2f(3.0971178154019, 2.3904011585437);
        glVertex2f(1.4735939588112, 1.7456804934716);
        glVertex2f(2.1065924299729, 2.3904011585437);
    glEnd();
    glPopMatrix();
}

//Void untuk di DisplayFunc
void backgroundawal(){

    glPushMatrix();
    background();
    glPopMatrix();

    glPushMatrix();
    mountain();
    glPopMatrix();

    road();

    cloud();

    backgroundTrans();

    glPushMatrix();
    glTranslated(0,2,0);
    text();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,0,0);
    textPlay(0,0,"Play");
    textAbout(0,0,"About");
    textExit(0,0,"Exit");
    glPopMatrix();
}

void backgroundawalAboutDisplay(){
    glPushMatrix();
    background();
    glPopMatrix();

    glPushMatrix();
    mountain();
    glPopMatrix();

    road();

    cloud();

    backgroundTrans();

    glPushMatrix();
    glTranslated(0,2,0);
    text();
    glPopMatrix();

    textPlay(0,0,"Play");
    textAbout(0,0,"About");
    textExit(0,0,"Exit");

    aboutDisplay();
}

//Level 1
void backgroundlevel1(){
    glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(10,0);
        glColor3ub(109,238,247);
        glVertex2f(10,10);
        glVertex2f(0,10);
    glEnd();
    glPopMatrix();
}

void rumput (){
    glPushMatrix();
    glTranslated(rumputlvl1[0],-0.8,0);                                 //FUngsi Untuk Gerak
    //Bayangan rumput
    glPushMatrix();
    glTranslated(-1.88,2.78,0);
    glScaled(0.5,0.84,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(3.7190552063643, 0.5268542867645);
        glVertex2f(3.7551366921135, 0.6872164456502);
        glVertex2f(3.8393268255285, 0.8435695505637);
        glVertex2f(3.9315350668877, 0.9518140078115);
        glVertex2f(4.0437885781077, 1.0400131951986);
        glVertex2f(4.1520330353555, 1.1041580587528);
        glVertex2f(4.2923499243805, 1.1602848143628);
        glVertex2f(4.4446939753218, 1.19235724614);
        glVertex2f(4.564965594486, 1.2003753540842);
        glVertex2f(4.677219105706, 1.2003753540842);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7493452870858, 1.399897994033);
        glVertex2f(4.8, 1.6);
        glVertex2f(4.8398509404064, 1.7809744290672);
        glVertex2f(4.8922489502236, 1.923878092205);
        glVertex2f(4.9779911481063, 2.0620182999049);
        glVertex2f(5.058969890551, 2.1668143195393);
        glVertex2f(5.1590024547475, 2.2430296065461);
        glVertex2f(5.2733253852578, 2.3240083489909);
        glVertex2f(5.4448097810231, 2.381169814246);
        glVertex2f(5.5638961669713, 2.4240409131873);
        glVertex2f(5.7306171072987, 2.4383312795011);
        glVertex2f(5.8735207704366, 2.443094734939);
        glVertex2f(6.0259513444502, 2.4145140023115);
        glVertex2f(6.1307473640846, 2.3716429033701);
        glVertex2f(6.2545972054707, 2.3097179826771);
        glVertex2f(6.3451028587913, 2.2382661511082);
        glVertex2f(6.4356085121119, 2.1477604977876);
        glVertex2f(6.5118237991188, 2.0810721216566);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6075659970015, 0.5189491043303);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6618807259707, 2.0346881340904);
        glVertex2f(6.7086119328102, 2.0751885133513);
        glVertex2f(6.7833818637534, 2.1468430305052);
        glVertex2f(6.8581517946967, 2.2216129614485);
        glVertex2f(6.9298063118506, 2.2839212372345);
        glVertex2f(6.9921145876366, 2.3337678578633);
        glVertex2f(7.0793461737371, 2.3867298922815);
        glVertex2f(7.1291927943659, 2.4147686163852);
        glVertex2f(7.1946164839413, 2.4365765129103);
        glVertex2f(7.2631555873059, 2.4552689956461);
        glVertex2f(7.3285792768812, 2.4677306508033);
        glVertex2f(7.3971183802459, 2.4739614783819);
        glVertex2f(7.4563112422426, 2.4708460645926);
        glVertex2f(7.543542828343, 2.4583844094354);
        glVertex2f(7.6370052420221, 2.4365765129103);
        glVertex2f(7.7211214143332, 2.4147686163852);
        glVertex2f(7.8052375866444, 2.3742682371243);
        glVertex2f(7.8862383451662, 2.3244216164954);
        glVertex2f(7.9578928623202, 2.2745749958666);
        glVertex2f(8.0357782070527, 2.1904588235555);
        glVertex2f(8.0887402414708, 2.1188043064015);
        glVertex2f(8.1354714483104, 2.0378035478797);
        glVertex2f(8.1759718275713, 1.9443411342006);
        glVertex2f(8.2164722068322, 1.8384170653644);
        glVertex2f(8.2382801033573, 1.741839237896);
        glVertex2f(8.2538571723038, 1.6452614104277);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.2752293601814, 0.5227100407116);
        glVertex2f(6.5975659970015, 0.5229491043303);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.3511270930914, 1.559140812539);
        glVertex2f(8.4384847462886, 1.5658606320157);
        glVertex2f(8.5359221287009, 1.5725804514924);
        glVertex2f(8.6434392403282, 1.5625007222774);
        glVertex2f(8.7475964422172, 1.5423412638472);
        glVertex2f(8.8517536441062, 1.5121020762021);
        glVertex2f(8.9458311167801, 1.4617034301267);
        glVertex2f(9.0499883186691, 1.3777056866679);
        glVertex2f(9.1407058816046, 1.2601088458255);
        glVertex2f(9.2179838055868, 1.1492318244598);
        glVertex2f(9.2986216393073, 1.018195344664);
        glVertex2f(9.3591000145977, 0.8636394966997);
        glVertex2f(9.4061387509346, 0.7158034682121);
        glVertex2f(9.4262982093647, 0.5242886131259);
        glVertex2f(8.2752293601814, 0.5247100407116);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.87,2.70,0);
    glScaled(0.5,0.84,0);
    glColor3ub(57, 124, 11);
    glBegin(GL_POLYGON);
        glColor3ub(88, 189, 66);
        glVertex2f(3.7190552063643, 0.5268542867645);
        glVertex2f(3.7551366921135, 0.6872164456502);
        glVertex2f(3.8393268255285, 0.8435695505637);
        glVertex2f(3.9315350668877, 0.9518140078115);
        glVertex2f(4.0437885781077, 1.0400131951986);
        glVertex2f(4.1520330353555, 1.1041580587528);
        glVertex2f(4.2923499243805, 1.1602848143628);
        glVertex2f(4.4446939753218, 1.19235724614);
        glVertex2f(4.564965594486, 1.2003753540842);
        glVertex2f(4.677219105706, 1.2003753540842);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7493452870858, 1.399897994033);
        glVertex2f(4.8, 1.6);
        glVertex2f(4.8398509404064, 1.7809744290672);
        glVertex2f(4.8922489502236, 1.923878092205);
        glVertex2f(4.9779911481063, 2.0620182999049);
        glVertex2f(5.058969890551, 2.1668143195393);
        glVertex2f(5.1590024547475, 2.2430296065461);
        glVertex2f(5.2733253852578, 2.3240083489909);
        glVertex2f(5.4448097810231, 2.381169814246);
        glVertex2f(5.5638961669713, 2.4240409131873);
        glVertex2f(5.7306171072987, 2.4383312795011);
        glVertex2f(5.8735207704366, 2.443094734939);
        glVertex2f(6.0259513444502, 2.4145140023115);
        glVertex2f(6.1307473640846, 2.3716429033701);
        glVertex2f(6.2545972054707, 2.3097179826771);
        glVertex2f(6.3451028587913, 2.2382661511082);
        glVertex2f(6.4356085121119, 2.1477604977876);
        glVertex2f(6.5118237991188, 2.0810721216566);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6075659970015, 0.5189491043303);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6618807259707, 2.0346881340904);
        glVertex2f(6.7086119328102, 2.0751885133513);
        glVertex2f(6.7833818637534, 2.1468430305052);
        glVertex2f(6.8581517946967, 2.2216129614485);
        glVertex2f(6.9298063118506, 2.2839212372345);
        glVertex2f(6.9921145876366, 2.3337678578633);
        glVertex2f(7.0793461737371, 2.3867298922815);
        glVertex2f(7.1291927943659, 2.4147686163852);
        glVertex2f(7.1946164839413, 2.4365765129103);
        glVertex2f(7.2631555873059, 2.4552689956461);
        glVertex2f(7.3285792768812, 2.4677306508033);
        glVertex2f(7.3971183802459, 2.4739614783819);
        glVertex2f(7.4563112422426, 2.4708460645926);
        glVertex2f(7.543542828343, 2.4583844094354);
        glVertex2f(7.6370052420221, 2.4365765129103);
        glVertex2f(7.7211214143332, 2.4147686163852);
        glVertex2f(7.8052375866444, 2.3742682371243);
        glVertex2f(7.8862383451662, 2.3244216164954);
        glVertex2f(7.9578928623202, 2.2745749958666);
        glVertex2f(8.0357782070527, 2.1904588235555);
        glVertex2f(8.0887402414708, 2.1188043064015);
        glVertex2f(8.1354714483104, 2.0378035478797);
        glVertex2f(8.1759718275713, 1.9443411342006);
        glVertex2f(8.2164722068322, 1.8384170653644);
        glVertex2f(8.2382801033573, 1.741839237896);
        glVertex2f(8.2538571723038, 1.6452614104277);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.2752293601814, 0.5227100407116);
        glVertex2f(6.5975659970015, 0.5229491043303);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.3511270930914, 1.559140812539);
        glVertex2f(8.4384847462886, 1.5658606320157);
        glVertex2f(8.5359221287009, 1.5725804514924);
        glVertex2f(8.6434392403282, 1.5625007222774);
        glVertex2f(8.7475964422172, 1.5423412638472);
        glVertex2f(8.8517536441062, 1.5121020762021);
        glVertex2f(8.9458311167801, 1.4617034301267);
        glVertex2f(9.0499883186691, 1.3777056866679);
        glVertex2f(9.1407058816046, 1.2601088458255);
        glVertex2f(9.2179838055868, 1.1492318244598);
        glVertex2f(9.2986216393073, 1.018195344664);
        glVertex2f(9.3591000145977, 0.8636394966997);
        glVertex2f(9.4061387509346, 0.7158034682121);
        glVertex2f(9.4262982093647, 0.5242886131259);
        glVertex2f(8.2752293601814, 0.5247100407116);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(rumputlvl1[1],-0.8,0);                                 //Fungsi Untuk Gerak
    //Bayangan rumput
    glPushMatrix();
    glTranslated(-1.88,2.78,0);
    glScaled(0.5,0.84,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(3.7190552063643, 0.5268542867645);
        glVertex2f(3.7551366921135, 0.6872164456502);
        glVertex2f(3.8393268255285, 0.8435695505637);
        glVertex2f(3.9315350668877, 0.9518140078115);
        glVertex2f(4.0437885781077, 1.0400131951986);
        glVertex2f(4.1520330353555, 1.1041580587528);
        glVertex2f(4.2923499243805, 1.1602848143628);
        glVertex2f(4.4446939753218, 1.19235724614);
        glVertex2f(4.564965594486, 1.2003753540842);
        glVertex2f(4.677219105706, 1.2003753540842);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7493452870858, 1.399897994033);
        glVertex2f(4.8, 1.6);
        glVertex2f(4.8398509404064, 1.7809744290672);
        glVertex2f(4.8922489502236, 1.923878092205);
        glVertex2f(4.9779911481063, 2.0620182999049);
        glVertex2f(5.058969890551, 2.1668143195393);
        glVertex2f(5.1590024547475, 2.2430296065461);
        glVertex2f(5.2733253852578, 2.3240083489909);
        glVertex2f(5.4448097810231, 2.381169814246);
        glVertex2f(5.5638961669713, 2.4240409131873);
        glVertex2f(5.7306171072987, 2.4383312795011);
        glVertex2f(5.8735207704366, 2.443094734939);
        glVertex2f(6.0259513444502, 2.4145140023115);
        glVertex2f(6.1307473640846, 2.3716429033701);
        glVertex2f(6.2545972054707, 2.3097179826771);
        glVertex2f(6.3451028587913, 2.2382661511082);
        glVertex2f(6.4356085121119, 2.1477604977876);
        glVertex2f(6.5118237991188, 2.0810721216566);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6075659970015, 0.5189491043303);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6618807259707, 2.0346881340904);
        glVertex2f(6.7086119328102, 2.0751885133513);
        glVertex2f(6.7833818637534, 2.1468430305052);
        glVertex2f(6.8581517946967, 2.2216129614485);
        glVertex2f(6.9298063118506, 2.2839212372345);
        glVertex2f(6.9921145876366, 2.3337678578633);
        glVertex2f(7.0793461737371, 2.3867298922815);
        glVertex2f(7.1291927943659, 2.4147686163852);
        glVertex2f(7.1946164839413, 2.4365765129103);
        glVertex2f(7.2631555873059, 2.4552689956461);
        glVertex2f(7.3285792768812, 2.4677306508033);
        glVertex2f(7.3971183802459, 2.4739614783819);
        glVertex2f(7.4563112422426, 2.4708460645926);
        glVertex2f(7.543542828343, 2.4583844094354);
        glVertex2f(7.6370052420221, 2.4365765129103);
        glVertex2f(7.7211214143332, 2.4147686163852);
        glVertex2f(7.8052375866444, 2.3742682371243);
        glVertex2f(7.8862383451662, 2.3244216164954);
        glVertex2f(7.9578928623202, 2.2745749958666);
        glVertex2f(8.0357782070527, 2.1904588235555);
        glVertex2f(8.0887402414708, 2.1188043064015);
        glVertex2f(8.1354714483104, 2.0378035478797);
        glVertex2f(8.1759718275713, 1.9443411342006);
        glVertex2f(8.2164722068322, 1.8384170653644);
        glVertex2f(8.2382801033573, 1.741839237896);
        glVertex2f(8.2538571723038, 1.6452614104277);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.2752293601814, 0.5227100407116);
        glVertex2f(6.5975659970015, 0.5229491043303);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.3511270930914, 1.559140812539);
        glVertex2f(8.4384847462886, 1.5658606320157);
        glVertex2f(8.5359221287009, 1.5725804514924);
        glVertex2f(8.6434392403282, 1.5625007222774);
        glVertex2f(8.7475964422172, 1.5423412638472);
        glVertex2f(8.8517536441062, 1.5121020762021);
        glVertex2f(8.9458311167801, 1.4617034301267);
        glVertex2f(9.0499883186691, 1.3777056866679);
        glVertex2f(9.1407058816046, 1.2601088458255);
        glVertex2f(9.2179838055868, 1.1492318244598);
        glVertex2f(9.2986216393073, 1.018195344664);
        glVertex2f(9.3591000145977, 0.8636394966997);
        glVertex2f(9.4061387509346, 0.7158034682121);
        glVertex2f(9.4262982093647, 0.5242886131259);
        glVertex2f(8.2752293601814, 0.5247100407116);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.87,2.70,0);
    glScaled(0.5,0.84,0);
    glColor3ub(57, 124, 11);
    glBegin(GL_POLYGON);
        glColor3ub(88, 189, 66);
        glVertex2f(3.7190552063643, 0.5268542867645);
        glVertex2f(3.7551366921135, 0.6872164456502);
        glVertex2f(3.8393268255285, 0.8435695505637);
        glVertex2f(3.9315350668877, 0.9518140078115);
        glVertex2f(4.0437885781077, 1.0400131951986);
        glVertex2f(4.1520330353555, 1.1041580587528);
        glVertex2f(4.2923499243805, 1.1602848143628);
        glVertex2f(4.4446939753218, 1.19235724614);
        glVertex2f(4.564965594486, 1.2003753540842);
        glVertex2f(4.677219105706, 1.2003753540842);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7493452870858, 1.399897994033);
        glVertex2f(4.8, 1.6);
        glVertex2f(4.8398509404064, 1.7809744290672);
        glVertex2f(4.8922489502236, 1.923878092205);
        glVertex2f(4.9779911481063, 2.0620182999049);
        glVertex2f(5.058969890551, 2.1668143195393);
        glVertex2f(5.1590024547475, 2.2430296065461);
        glVertex2f(5.2733253852578, 2.3240083489909);
        glVertex2f(5.4448097810231, 2.381169814246);
        glVertex2f(5.5638961669713, 2.4240409131873);
        glVertex2f(5.7306171072987, 2.4383312795011);
        glVertex2f(5.8735207704366, 2.443094734939);
        glVertex2f(6.0259513444502, 2.4145140023115);
        glVertex2f(6.1307473640846, 2.3716429033701);
        glVertex2f(6.2545972054707, 2.3097179826771);
        glVertex2f(6.3451028587913, 2.2382661511082);
        glVertex2f(6.4356085121119, 2.1477604977876);
        glVertex2f(6.5118237991188, 2.0810721216566);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6075659970015, 0.5189491043303);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6618807259707, 2.0346881340904);
        glVertex2f(6.7086119328102, 2.0751885133513);
        glVertex2f(6.7833818637534, 2.1468430305052);
        glVertex2f(6.8581517946967, 2.2216129614485);
        glVertex2f(6.9298063118506, 2.2839212372345);
        glVertex2f(6.9921145876366, 2.3337678578633);
        glVertex2f(7.0793461737371, 2.3867298922815);
        glVertex2f(7.1291927943659, 2.4147686163852);
        glVertex2f(7.1946164839413, 2.4365765129103);
        glVertex2f(7.2631555873059, 2.4552689956461);
        glVertex2f(7.3285792768812, 2.4677306508033);
        glVertex2f(7.3971183802459, 2.4739614783819);
        glVertex2f(7.4563112422426, 2.4708460645926);
        glVertex2f(7.543542828343, 2.4583844094354);
        glVertex2f(7.6370052420221, 2.4365765129103);
        glVertex2f(7.7211214143332, 2.4147686163852);
        glVertex2f(7.8052375866444, 2.3742682371243);
        glVertex2f(7.8862383451662, 2.3244216164954);
        glVertex2f(7.9578928623202, 2.2745749958666);
        glVertex2f(8.0357782070527, 2.1904588235555);
        glVertex2f(8.0887402414708, 2.1188043064015);
        glVertex2f(8.1354714483104, 2.0378035478797);
        glVertex2f(8.1759718275713, 1.9443411342006);
        glVertex2f(8.2164722068322, 1.8384170653644);
        glVertex2f(8.2382801033573, 1.741839237896);
        glVertex2f(8.2538571723038, 1.6452614104277);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.2752293601814, 0.5227100407116);
        glVertex2f(6.5975659970015, 0.5229491043303);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.3511270930914, 1.559140812539);
        glVertex2f(8.4384847462886, 1.5658606320157);
        glVertex2f(8.5359221287009, 1.5725804514924);
        glVertex2f(8.6434392403282, 1.5625007222774);
        glVertex2f(8.7475964422172, 1.5423412638472);
        glVertex2f(8.8517536441062, 1.5121020762021);
        glVertex2f(8.9458311167801, 1.4617034301267);
        glVertex2f(9.0499883186691, 1.3777056866679);
        glVertex2f(9.1407058816046, 1.2601088458255);
        glVertex2f(9.2179838055868, 1.1492318244598);
        glVertex2f(9.2986216393073, 1.018195344664);
        glVertex2f(9.3591000145977, 0.8636394966997);
        glVertex2f(9.4061387509346, 0.7158034682121);
        glVertex2f(9.4262982093647, 0.5242886131259);
        glVertex2f(8.2752293601814, 0.5247100407116);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(rumputlvl1[2],-0.8,0);                             //FUngsi untuk gerak
    //Bayangan rumput
    glPushMatrix();
    glTranslated(-1.88,2.78,0);
    glScaled(0.5,0.84,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(3.7190552063643, 0.5268542867645);
        glVertex2f(3.7551366921135, 0.6872164456502);
        glVertex2f(3.8393268255285, 0.8435695505637);
        glVertex2f(3.9315350668877, 0.9518140078115);
        glVertex2f(4.0437885781077, 1.0400131951986);
        glVertex2f(4.1520330353555, 1.1041580587528);
        glVertex2f(4.2923499243805, 1.1602848143628);
        glVertex2f(4.4446939753218, 1.19235724614);
        glVertex2f(4.564965594486, 1.2003753540842);
        glVertex2f(4.677219105706, 1.2003753540842);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7493452870858, 1.399897994033);
        glVertex2f(4.8, 1.6);
        glVertex2f(4.8398509404064, 1.7809744290672);
        glVertex2f(4.8922489502236, 1.923878092205);
        glVertex2f(4.9779911481063, 2.0620182999049);
        glVertex2f(5.058969890551, 2.1668143195393);
        glVertex2f(5.1590024547475, 2.2430296065461);
        glVertex2f(5.2733253852578, 2.3240083489909);
        glVertex2f(5.4448097810231, 2.381169814246);
        glVertex2f(5.5638961669713, 2.4240409131873);
        glVertex2f(5.7306171072987, 2.4383312795011);
        glVertex2f(5.8735207704366, 2.443094734939);
        glVertex2f(6.0259513444502, 2.4145140023115);
        glVertex2f(6.1307473640846, 2.3716429033701);
        glVertex2f(6.2545972054707, 2.3097179826771);
        glVertex2f(6.3451028587913, 2.2382661511082);
        glVertex2f(6.4356085121119, 2.1477604977876);
        glVertex2f(6.5118237991188, 2.0810721216566);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6075659970015, 0.5189491043303);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6618807259707, 2.0346881340904);
        glVertex2f(6.7086119328102, 2.0751885133513);
        glVertex2f(6.7833818637534, 2.1468430305052);
        glVertex2f(6.8581517946967, 2.2216129614485);
        glVertex2f(6.9298063118506, 2.2839212372345);
        glVertex2f(6.9921145876366, 2.3337678578633);
        glVertex2f(7.0793461737371, 2.3867298922815);
        glVertex2f(7.1291927943659, 2.4147686163852);
        glVertex2f(7.1946164839413, 2.4365765129103);
        glVertex2f(7.2631555873059, 2.4552689956461);
        glVertex2f(7.3285792768812, 2.4677306508033);
        glVertex2f(7.3971183802459, 2.4739614783819);
        glVertex2f(7.4563112422426, 2.4708460645926);
        glVertex2f(7.543542828343, 2.4583844094354);
        glVertex2f(7.6370052420221, 2.4365765129103);
        glVertex2f(7.7211214143332, 2.4147686163852);
        glVertex2f(7.8052375866444, 2.3742682371243);
        glVertex2f(7.8862383451662, 2.3244216164954);
        glVertex2f(7.9578928623202, 2.2745749958666);
        glVertex2f(8.0357782070527, 2.1904588235555);
        glVertex2f(8.0887402414708, 2.1188043064015);
        glVertex2f(8.1354714483104, 2.0378035478797);
        glVertex2f(8.1759718275713, 1.9443411342006);
        glVertex2f(8.2164722068322, 1.8384170653644);
        glVertex2f(8.2382801033573, 1.741839237896);
        glVertex2f(8.2538571723038, 1.6452614104277);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.2752293601814, 0.5227100407116);
        glVertex2f(6.5975659970015, 0.5229491043303);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.3511270930914, 1.559140812539);
        glVertex2f(8.4384847462886, 1.5658606320157);
        glVertex2f(8.5359221287009, 1.5725804514924);
        glVertex2f(8.6434392403282, 1.5625007222774);
        glVertex2f(8.7475964422172, 1.5423412638472);
        glVertex2f(8.8517536441062, 1.5121020762021);
        glVertex2f(8.9458311167801, 1.4617034301267);
        glVertex2f(9.0499883186691, 1.3777056866679);
        glVertex2f(9.1407058816046, 1.2601088458255);
        glVertex2f(9.2179838055868, 1.1492318244598);
        glVertex2f(9.2986216393073, 1.018195344664);
        glVertex2f(9.3591000145977, 0.8636394966997);
        glVertex2f(9.4061387509346, 0.7158034682121);
        glVertex2f(9.4262982093647, 0.5242886131259);
        glVertex2f(8.2752293601814, 0.5247100407116);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.87,2.70,0);
    glScaled(0.5,0.84,0);
    glColor3ub(57, 124, 11);
    glBegin(GL_POLYGON);
        glColor3ub(88, 189, 66);
        glVertex2f(3.7190552063643, 0.5268542867645);
        glVertex2f(3.7551366921135, 0.6872164456502);
        glVertex2f(3.8393268255285, 0.8435695505637);
        glVertex2f(3.9315350668877, 0.9518140078115);
        glVertex2f(4.0437885781077, 1.0400131951986);
        glVertex2f(4.1520330353555, 1.1041580587528);
        glVertex2f(4.2923499243805, 1.1602848143628);
        glVertex2f(4.4446939753218, 1.19235724614);
        glVertex2f(4.564965594486, 1.2003753540842);
        glVertex2f(4.677219105706, 1.2003753540842);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7493452870858, 1.399897994033);
        glVertex2f(4.8, 1.6);
        glVertex2f(4.8398509404064, 1.7809744290672);
        glVertex2f(4.8922489502236, 1.923878092205);
        glVertex2f(4.9779911481063, 2.0620182999049);
        glVertex2f(5.058969890551, 2.1668143195393);
        glVertex2f(5.1590024547475, 2.2430296065461);
        glVertex2f(5.2733253852578, 2.3240083489909);
        glVertex2f(5.4448097810231, 2.381169814246);
        glVertex2f(5.5638961669713, 2.4240409131873);
        glVertex2f(5.7306171072987, 2.4383312795011);
        glVertex2f(5.8735207704366, 2.443094734939);
        glVertex2f(6.0259513444502, 2.4145140023115);
        glVertex2f(6.1307473640846, 2.3716429033701);
        glVertex2f(6.2545972054707, 2.3097179826771);
        glVertex2f(6.3451028587913, 2.2382661511082);
        glVertex2f(6.4356085121119, 2.1477604977876);
        glVertex2f(6.5118237991188, 2.0810721216566);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6075659970015, 0.5189491043303);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6618807259707, 2.0346881340904);
        glVertex2f(6.7086119328102, 2.0751885133513);
        glVertex2f(6.7833818637534, 2.1468430305052);
        glVertex2f(6.8581517946967, 2.2216129614485);
        glVertex2f(6.9298063118506, 2.2839212372345);
        glVertex2f(6.9921145876366, 2.3337678578633);
        glVertex2f(7.0793461737371, 2.3867298922815);
        glVertex2f(7.1291927943659, 2.4147686163852);
        glVertex2f(7.1946164839413, 2.4365765129103);
        glVertex2f(7.2631555873059, 2.4552689956461);
        glVertex2f(7.3285792768812, 2.4677306508033);
        glVertex2f(7.3971183802459, 2.4739614783819);
        glVertex2f(7.4563112422426, 2.4708460645926);
        glVertex2f(7.543542828343, 2.4583844094354);
        glVertex2f(7.6370052420221, 2.4365765129103);
        glVertex2f(7.7211214143332, 2.4147686163852);
        glVertex2f(7.8052375866444, 2.3742682371243);
        glVertex2f(7.8862383451662, 2.3244216164954);
        glVertex2f(7.9578928623202, 2.2745749958666);
        glVertex2f(8.0357782070527, 2.1904588235555);
        glVertex2f(8.0887402414708, 2.1188043064015);
        glVertex2f(8.1354714483104, 2.0378035478797);
        glVertex2f(8.1759718275713, 1.9443411342006);
        glVertex2f(8.2164722068322, 1.8384170653644);
        glVertex2f(8.2382801033573, 1.741839237896);
        glVertex2f(8.2538571723038, 1.6452614104277);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.2752293601814, 0.5227100407116);
        glVertex2f(6.5975659970015, 0.5229491043303);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.3511270930914, 1.559140812539);
        glVertex2f(8.4384847462886, 1.5658606320157);
        glVertex2f(8.5359221287009, 1.5725804514924);
        glVertex2f(8.6434392403282, 1.5625007222774);
        glVertex2f(8.7475964422172, 1.5423412638472);
        glVertex2f(8.8517536441062, 1.5121020762021);
        glVertex2f(8.9458311167801, 1.4617034301267);
        glVertex2f(9.0499883186691, 1.3777056866679);
        glVertex2f(9.1407058816046, 1.2601088458255);
        glVertex2f(9.2179838055868, 1.1492318244598);
        glVertex2f(9.2986216393073, 1.018195344664);
        glVertex2f(9.3591000145977, 0.8636394966997);
        glVertex2f(9.4061387509346, 0.7158034682121);
        glVertex2f(9.4262982093647, 0.5242886131259);
        glVertex2f(8.2752293601814, 0.5247100407116);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(rumputlvl1[3],-0.8,0);                             //Fungsi Untuk gerak
    //Bayangan rumput
    glPushMatrix();
    glTranslated(-1.88,2.78,0);
    glScaled(0.5,0.84,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(3.7190552063643, 0.5268542867645);
        glVertex2f(3.7551366921135, 0.6872164456502);
        glVertex2f(3.8393268255285, 0.8435695505637);
        glVertex2f(3.9315350668877, 0.9518140078115);
        glVertex2f(4.0437885781077, 1.0400131951986);
        glVertex2f(4.1520330353555, 1.1041580587528);
        glVertex2f(4.2923499243805, 1.1602848143628);
        glVertex2f(4.4446939753218, 1.19235724614);
        glVertex2f(4.564965594486, 1.2003753540842);
        glVertex2f(4.677219105706, 1.2003753540842);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7493452870858, 1.399897994033);
        glVertex2f(4.8, 1.6);
        glVertex2f(4.8398509404064, 1.7809744290672);
        glVertex2f(4.8922489502236, 1.923878092205);
        glVertex2f(4.9779911481063, 2.0620182999049);
        glVertex2f(5.058969890551, 2.1668143195393);
        glVertex2f(5.1590024547475, 2.2430296065461);
        glVertex2f(5.2733253852578, 2.3240083489909);
        glVertex2f(5.4448097810231, 2.381169814246);
        glVertex2f(5.5638961669713, 2.4240409131873);
        glVertex2f(5.7306171072987, 2.4383312795011);
        glVertex2f(5.8735207704366, 2.443094734939);
        glVertex2f(6.0259513444502, 2.4145140023115);
        glVertex2f(6.1307473640846, 2.3716429033701);
        glVertex2f(6.2545972054707, 2.3097179826771);
        glVertex2f(6.3451028587913, 2.2382661511082);
        glVertex2f(6.4356085121119, 2.1477604977876);
        glVertex2f(6.5118237991188, 2.0810721216566);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6075659970015, 0.5189491043303);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6618807259707, 2.0346881340904);
        glVertex2f(6.7086119328102, 2.0751885133513);
        glVertex2f(6.7833818637534, 2.1468430305052);
        glVertex2f(6.8581517946967, 2.2216129614485);
        glVertex2f(6.9298063118506, 2.2839212372345);
        glVertex2f(6.9921145876366, 2.3337678578633);
        glVertex2f(7.0793461737371, 2.3867298922815);
        glVertex2f(7.1291927943659, 2.4147686163852);
        glVertex2f(7.1946164839413, 2.4365765129103);
        glVertex2f(7.2631555873059, 2.4552689956461);
        glVertex2f(7.3285792768812, 2.4677306508033);
        glVertex2f(7.3971183802459, 2.4739614783819);
        glVertex2f(7.4563112422426, 2.4708460645926);
        glVertex2f(7.543542828343, 2.4583844094354);
        glVertex2f(7.6370052420221, 2.4365765129103);
        glVertex2f(7.7211214143332, 2.4147686163852);
        glVertex2f(7.8052375866444, 2.3742682371243);
        glVertex2f(7.8862383451662, 2.3244216164954);
        glVertex2f(7.9578928623202, 2.2745749958666);
        glVertex2f(8.0357782070527, 2.1904588235555);
        glVertex2f(8.0887402414708, 2.1188043064015);
        glVertex2f(8.1354714483104, 2.0378035478797);
        glVertex2f(8.1759718275713, 1.9443411342006);
        glVertex2f(8.2164722068322, 1.8384170653644);
        glVertex2f(8.2382801033573, 1.741839237896);
        glVertex2f(8.2538571723038, 1.6452614104277);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.2752293601814, 0.5227100407116);
        glVertex2f(6.5975659970015, 0.5229491043303);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.3511270930914, 1.559140812539);
        glVertex2f(8.4384847462886, 1.5658606320157);
        glVertex2f(8.5359221287009, 1.5725804514924);
        glVertex2f(8.6434392403282, 1.5625007222774);
        glVertex2f(8.7475964422172, 1.5423412638472);
        glVertex2f(8.8517536441062, 1.5121020762021);
        glVertex2f(8.9458311167801, 1.4617034301267);
        glVertex2f(9.0499883186691, 1.3777056866679);
        glVertex2f(9.1407058816046, 1.2601088458255);
        glVertex2f(9.2179838055868, 1.1492318244598);
        glVertex2f(9.2986216393073, 1.018195344664);
        glVertex2f(9.3591000145977, 0.8636394966997);
        glVertex2f(9.4061387509346, 0.7158034682121);
        glVertex2f(9.4262982093647, 0.5242886131259);
        glVertex2f(8.2752293601814, 0.5247100407116);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.87,2.70,0);
    glScaled(0.5,0.84,0);
    glColor3ub(57, 124, 11);
    glBegin(GL_POLYGON);
        glColor3ub(88, 189, 66);
        glVertex2f(3.7190552063643, 0.5268542867645);
        glVertex2f(3.7551366921135, 0.6872164456502);
        glVertex2f(3.8393268255285, 0.8435695505637);
        glVertex2f(3.9315350668877, 0.9518140078115);
        glVertex2f(4.0437885781077, 1.0400131951986);
        glVertex2f(4.1520330353555, 1.1041580587528);
        glVertex2f(4.2923499243805, 1.1602848143628);
        glVertex2f(4.4446939753218, 1.19235724614);
        glVertex2f(4.564965594486, 1.2003753540842);
        glVertex2f(4.677219105706, 1.2003753540842);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7493452870858, 1.399897994033);
        glVertex2f(4.8, 1.6);
        glVertex2f(4.8398509404064, 1.7809744290672);
        glVertex2f(4.8922489502236, 1.923878092205);
        glVertex2f(4.9779911481063, 2.0620182999049);
        glVertex2f(5.058969890551, 2.1668143195393);
        glVertex2f(5.1590024547475, 2.2430296065461);
        glVertex2f(5.2733253852578, 2.3240083489909);
        glVertex2f(5.4448097810231, 2.381169814246);
        glVertex2f(5.5638961669713, 2.4240409131873);
        glVertex2f(5.7306171072987, 2.4383312795011);
        glVertex2f(5.8735207704366, 2.443094734939);
        glVertex2f(6.0259513444502, 2.4145140023115);
        glVertex2f(6.1307473640846, 2.3716429033701);
        glVertex2f(6.2545972054707, 2.3097179826771);
        glVertex2f(6.3451028587913, 2.2382661511082);
        glVertex2f(6.4356085121119, 2.1477604977876);
        glVertex2f(6.5118237991188, 2.0810721216566);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6075659970015, 0.5189491043303);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6618807259707, 2.0346881340904);
        glVertex2f(6.7086119328102, 2.0751885133513);
        glVertex2f(6.7833818637534, 2.1468430305052);
        glVertex2f(6.8581517946967, 2.2216129614485);
        glVertex2f(6.9298063118506, 2.2839212372345);
        glVertex2f(6.9921145876366, 2.3337678578633);
        glVertex2f(7.0793461737371, 2.3867298922815);
        glVertex2f(7.1291927943659, 2.4147686163852);
        glVertex2f(7.1946164839413, 2.4365765129103);
        glVertex2f(7.2631555873059, 2.4552689956461);
        glVertex2f(7.3285792768812, 2.4677306508033);
        glVertex2f(7.3971183802459, 2.4739614783819);
        glVertex2f(7.4563112422426, 2.4708460645926);
        glVertex2f(7.543542828343, 2.4583844094354);
        glVertex2f(7.6370052420221, 2.4365765129103);
        glVertex2f(7.7211214143332, 2.4147686163852);
        glVertex2f(7.8052375866444, 2.3742682371243);
        glVertex2f(7.8862383451662, 2.3244216164954);
        glVertex2f(7.9578928623202, 2.2745749958666);
        glVertex2f(8.0357782070527, 2.1904588235555);
        glVertex2f(8.0887402414708, 2.1188043064015);
        glVertex2f(8.1354714483104, 2.0378035478797);
        glVertex2f(8.1759718275713, 1.9443411342006);
        glVertex2f(8.2164722068322, 1.8384170653644);
        glVertex2f(8.2382801033573, 1.741839237896);
        glVertex2f(8.2538571723038, 1.6452614104277);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.2752293601814, 0.5227100407116);
        glVertex2f(6.5975659970015, 0.5229491043303);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.3511270930914, 1.559140812539);
        glVertex2f(8.4384847462886, 1.5658606320157);
        glVertex2f(8.5359221287009, 1.5725804514924);
        glVertex2f(8.6434392403282, 1.5625007222774);
        glVertex2f(8.7475964422172, 1.5423412638472);
        glVertex2f(8.8517536441062, 1.5121020762021);
        glVertex2f(8.9458311167801, 1.4617034301267);
        glVertex2f(9.0499883186691, 1.3777056866679);
        glVertex2f(9.1407058816046, 1.2601088458255);
        glVertex2f(9.2179838055868, 1.1492318244598);
        glVertex2f(9.2986216393073, 1.018195344664);
        glVertex2f(9.3591000145977, 0.8636394966997);
        glVertex2f(9.4061387509346, 0.7158034682121);
        glVertex2f(9.4262982093647, 0.5242886131259);
        glVertex2f(8.2752293601814, 0.5247100407116);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(rumputlvl1[4],-0.8,0);                             //Fungsi Untuk Gerak
    //Bayangan rumput
    glPushMatrix();
    glTranslated(-1.88,2.78,0);
    glScaled(0.5,0.84,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(3.7190552063643, 0.5268542867645);
        glVertex2f(3.7551366921135, 0.6872164456502);
        glVertex2f(3.8393268255285, 0.8435695505637);
        glVertex2f(3.9315350668877, 0.9518140078115);
        glVertex2f(4.0437885781077, 1.0400131951986);
        glVertex2f(4.1520330353555, 1.1041580587528);
        glVertex2f(4.2923499243805, 1.1602848143628);
        glVertex2f(4.4446939753218, 1.19235724614);
        glVertex2f(4.564965594486, 1.2003753540842);
        glVertex2f(4.677219105706, 1.2003753540842);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7493452870858, 1.399897994033);
        glVertex2f(4.8, 1.6);
        glVertex2f(4.8398509404064, 1.7809744290672);
        glVertex2f(4.8922489502236, 1.923878092205);
        glVertex2f(4.9779911481063, 2.0620182999049);
        glVertex2f(5.058969890551, 2.1668143195393);
        glVertex2f(5.1590024547475, 2.2430296065461);
        glVertex2f(5.2733253852578, 2.3240083489909);
        glVertex2f(5.4448097810231, 2.381169814246);
        glVertex2f(5.5638961669713, 2.4240409131873);
        glVertex2f(5.7306171072987, 2.4383312795011);
        glVertex2f(5.8735207704366, 2.443094734939);
        glVertex2f(6.0259513444502, 2.4145140023115);
        glVertex2f(6.1307473640846, 2.3716429033701);
        glVertex2f(6.2545972054707, 2.3097179826771);
        glVertex2f(6.3451028587913, 2.2382661511082);
        glVertex2f(6.4356085121119, 2.1477604977876);
        glVertex2f(6.5118237991188, 2.0810721216566);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6075659970015, 0.5189491043303);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6618807259707, 2.0346881340904);
        glVertex2f(6.7086119328102, 2.0751885133513);
        glVertex2f(6.7833818637534, 2.1468430305052);
        glVertex2f(6.8581517946967, 2.2216129614485);
        glVertex2f(6.9298063118506, 2.2839212372345);
        glVertex2f(6.9921145876366, 2.3337678578633);
        glVertex2f(7.0793461737371, 2.3867298922815);
        glVertex2f(7.1291927943659, 2.4147686163852);
        glVertex2f(7.1946164839413, 2.4365765129103);
        glVertex2f(7.2631555873059, 2.4552689956461);
        glVertex2f(7.3285792768812, 2.4677306508033);
        glVertex2f(7.3971183802459, 2.4739614783819);
        glVertex2f(7.4563112422426, 2.4708460645926);
        glVertex2f(7.543542828343, 2.4583844094354);
        glVertex2f(7.6370052420221, 2.4365765129103);
        glVertex2f(7.7211214143332, 2.4147686163852);
        glVertex2f(7.8052375866444, 2.3742682371243);
        glVertex2f(7.8862383451662, 2.3244216164954);
        glVertex2f(7.9578928623202, 2.2745749958666);
        glVertex2f(8.0357782070527, 2.1904588235555);
        glVertex2f(8.0887402414708, 2.1188043064015);
        glVertex2f(8.1354714483104, 2.0378035478797);
        glVertex2f(8.1759718275713, 1.9443411342006);
        glVertex2f(8.2164722068322, 1.8384170653644);
        glVertex2f(8.2382801033573, 1.741839237896);
        glVertex2f(8.2538571723038, 1.6452614104277);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.2752293601814, 0.5227100407116);
        glVertex2f(6.5975659970015, 0.5229491043303);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.3511270930914, 1.559140812539);
        glVertex2f(8.4384847462886, 1.5658606320157);
        glVertex2f(8.5359221287009, 1.5725804514924);
        glVertex2f(8.6434392403282, 1.5625007222774);
        glVertex2f(8.7475964422172, 1.5423412638472);
        glVertex2f(8.8517536441062, 1.5121020762021);
        glVertex2f(8.9458311167801, 1.4617034301267);
        glVertex2f(9.0499883186691, 1.3777056866679);
        glVertex2f(9.1407058816046, 1.2601088458255);
        glVertex2f(9.2179838055868, 1.1492318244598);
        glVertex2f(9.2986216393073, 1.018195344664);
        glVertex2f(9.3591000145977, 0.8636394966997);
        glVertex2f(9.4061387509346, 0.7158034682121);
        glVertex2f(9.4262982093647, 0.5242886131259);
        glVertex2f(8.2752293601814, 0.5247100407116);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.87,2.70,0);
    glScaled(0.5,0.84,0);
    glColor3ub(57, 124, 11);
    glBegin(GL_POLYGON);
        glColor3ub(88, 189, 66);
        glVertex2f(3.7190552063643, 0.5268542867645);
        glVertex2f(3.7551366921135, 0.6872164456502);
        glVertex2f(3.8393268255285, 0.8435695505637);
        glVertex2f(3.9315350668877, 0.9518140078115);
        glVertex2f(4.0437885781077, 1.0400131951986);
        glVertex2f(4.1520330353555, 1.1041580587528);
        glVertex2f(4.2923499243805, 1.1602848143628);
        glVertex2f(4.4446939753218, 1.19235724614);
        glVertex2f(4.564965594486, 1.2003753540842);
        glVertex2f(4.677219105706, 1.2003753540842);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7493452870858, 1.399897994033);
        glVertex2f(4.8, 1.6);
        glVertex2f(4.8398509404064, 1.7809744290672);
        glVertex2f(4.8922489502236, 1.923878092205);
        glVertex2f(4.9779911481063, 2.0620182999049);
        glVertex2f(5.058969890551, 2.1668143195393);
        glVertex2f(5.1590024547475, 2.2430296065461);
        glVertex2f(5.2733253852578, 2.3240083489909);
        glVertex2f(5.4448097810231, 2.381169814246);
        glVertex2f(5.5638961669713, 2.4240409131873);
        glVertex2f(5.7306171072987, 2.4383312795011);
        glVertex2f(5.8735207704366, 2.443094734939);
        glVertex2f(6.0259513444502, 2.4145140023115);
        glVertex2f(6.1307473640846, 2.3716429033701);
        glVertex2f(6.2545972054707, 2.3097179826771);
        glVertex2f(6.3451028587913, 2.2382661511082);
        glVertex2f(6.4356085121119, 2.1477604977876);
        glVertex2f(6.5118237991188, 2.0810721216566);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6075659970015, 0.5189491043303);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6618807259707, 2.0346881340904);
        glVertex2f(6.7086119328102, 2.0751885133513);
        glVertex2f(6.7833818637534, 2.1468430305052);
        glVertex2f(6.8581517946967, 2.2216129614485);
        glVertex2f(6.9298063118506, 2.2839212372345);
        glVertex2f(6.9921145876366, 2.3337678578633);
        glVertex2f(7.0793461737371, 2.3867298922815);
        glVertex2f(7.1291927943659, 2.4147686163852);
        glVertex2f(7.1946164839413, 2.4365765129103);
        glVertex2f(7.2631555873059, 2.4552689956461);
        glVertex2f(7.3285792768812, 2.4677306508033);
        glVertex2f(7.3971183802459, 2.4739614783819);
        glVertex2f(7.4563112422426, 2.4708460645926);
        glVertex2f(7.543542828343, 2.4583844094354);
        glVertex2f(7.6370052420221, 2.4365765129103);
        glVertex2f(7.7211214143332, 2.4147686163852);
        glVertex2f(7.8052375866444, 2.3742682371243);
        glVertex2f(7.8862383451662, 2.3244216164954);
        glVertex2f(7.9578928623202, 2.2745749958666);
        glVertex2f(8.0357782070527, 2.1904588235555);
        glVertex2f(8.0887402414708, 2.1188043064015);
        glVertex2f(8.1354714483104, 2.0378035478797);
        glVertex2f(8.1759718275713, 1.9443411342006);
        glVertex2f(8.2164722068322, 1.8384170653644);
        glVertex2f(8.2382801033573, 1.741839237896);
        glVertex2f(8.2538571723038, 1.6452614104277);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.2752293601814, 0.5227100407116);
        glVertex2f(6.5975659970015, 0.5229491043303);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.3511270930914, 1.559140812539);
        glVertex2f(8.4384847462886, 1.5658606320157);
        glVertex2f(8.5359221287009, 1.5725804514924);
        glVertex2f(8.6434392403282, 1.5625007222774);
        glVertex2f(8.7475964422172, 1.5423412638472);
        glVertex2f(8.8517536441062, 1.5121020762021);
        glVertex2f(8.9458311167801, 1.4617034301267);
        glVertex2f(9.0499883186691, 1.3777056866679);
        glVertex2f(9.1407058816046, 1.2601088458255);
        glVertex2f(9.2179838055868, 1.1492318244598);
        glVertex2f(9.2986216393073, 1.018195344664);
        glVertex2f(9.3591000145977, 0.8636394966997);
        glVertex2f(9.4061387509346, 0.7158034682121);
        glVertex2f(9.4262982093647, 0.5242886131259);
        glVertex2f(8.2752293601814, 0.5247100407116);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(rumputlvl1[5],-0.8,0);                             //Fungsi Untuk Gerak
    //Bayangan rumput
    glPushMatrix();
    glTranslated(-1.88,2.78,0);
    glScaled(0.5,0.84,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(3.7190552063643, 0.5268542867645);
        glVertex2f(3.7551366921135, 0.6872164456502);
        glVertex2f(3.8393268255285, 0.8435695505637);
        glVertex2f(3.9315350668877, 0.9518140078115);
        glVertex2f(4.0437885781077, 1.0400131951986);
        glVertex2f(4.1520330353555, 1.1041580587528);
        glVertex2f(4.2923499243805, 1.1602848143628);
        glVertex2f(4.4446939753218, 1.19235724614);
        glVertex2f(4.564965594486, 1.2003753540842);
        glVertex2f(4.677219105706, 1.2003753540842);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7493452870858, 1.399897994033);
        glVertex2f(4.8, 1.6);
        glVertex2f(4.8398509404064, 1.7809744290672);
        glVertex2f(4.8922489502236, 1.923878092205);
        glVertex2f(4.9779911481063, 2.0620182999049);
        glVertex2f(5.058969890551, 2.1668143195393);
        glVertex2f(5.1590024547475, 2.2430296065461);
        glVertex2f(5.2733253852578, 2.3240083489909);
        glVertex2f(5.4448097810231, 2.381169814246);
        glVertex2f(5.5638961669713, 2.4240409131873);
        glVertex2f(5.7306171072987, 2.4383312795011);
        glVertex2f(5.8735207704366, 2.443094734939);
        glVertex2f(6.0259513444502, 2.4145140023115);
        glVertex2f(6.1307473640846, 2.3716429033701);
        glVertex2f(6.2545972054707, 2.3097179826771);
        glVertex2f(6.3451028587913, 2.2382661511082);
        glVertex2f(6.4356085121119, 2.1477604977876);
        glVertex2f(6.5118237991188, 2.0810721216566);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6075659970015, 0.5189491043303);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6618807259707, 2.0346881340904);
        glVertex2f(6.7086119328102, 2.0751885133513);
        glVertex2f(6.7833818637534, 2.1468430305052);
        glVertex2f(6.8581517946967, 2.2216129614485);
        glVertex2f(6.9298063118506, 2.2839212372345);
        glVertex2f(6.9921145876366, 2.3337678578633);
        glVertex2f(7.0793461737371, 2.3867298922815);
        glVertex2f(7.1291927943659, 2.4147686163852);
        glVertex2f(7.1946164839413, 2.4365765129103);
        glVertex2f(7.2631555873059, 2.4552689956461);
        glVertex2f(7.3285792768812, 2.4677306508033);
        glVertex2f(7.3971183802459, 2.4739614783819);
        glVertex2f(7.4563112422426, 2.4708460645926);
        glVertex2f(7.543542828343, 2.4583844094354);
        glVertex2f(7.6370052420221, 2.4365765129103);
        glVertex2f(7.7211214143332, 2.4147686163852);
        glVertex2f(7.8052375866444, 2.3742682371243);
        glVertex2f(7.8862383451662, 2.3244216164954);
        glVertex2f(7.9578928623202, 2.2745749958666);
        glVertex2f(8.0357782070527, 2.1904588235555);
        glVertex2f(8.0887402414708, 2.1188043064015);
        glVertex2f(8.1354714483104, 2.0378035478797);
        glVertex2f(8.1759718275713, 1.9443411342006);
        glVertex2f(8.2164722068322, 1.8384170653644);
        glVertex2f(8.2382801033573, 1.741839237896);
        glVertex2f(8.2538571723038, 1.6452614104277);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.2752293601814, 0.5227100407116);
        glVertex2f(6.5975659970015, 0.5229491043303);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.3511270930914, 1.559140812539);
        glVertex2f(8.4384847462886, 1.5658606320157);
        glVertex2f(8.5359221287009, 1.5725804514924);
        glVertex2f(8.6434392403282, 1.5625007222774);
        glVertex2f(8.7475964422172, 1.5423412638472);
        glVertex2f(8.8517536441062, 1.5121020762021);
        glVertex2f(8.9458311167801, 1.4617034301267);
        glVertex2f(9.0499883186691, 1.3777056866679);
        glVertex2f(9.1407058816046, 1.2601088458255);
        glVertex2f(9.2179838055868, 1.1492318244598);
        glVertex2f(9.2986216393073, 1.018195344664);
        glVertex2f(9.3591000145977, 0.8636394966997);
        glVertex2f(9.4061387509346, 0.7158034682121);
        glVertex2f(9.4262982093647, 0.5242886131259);
        glVertex2f(8.2752293601814, 0.5247100407116);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.87,2.70,0);
    glScaled(0.5,0.84,0);
    glColor3ub(57, 124, 11);
    glBegin(GL_POLYGON);
        glColor3ub(88, 189, 66);
        glVertex2f(3.7190552063643, 0.5268542867645);
        glVertex2f(3.7551366921135, 0.6872164456502);
        glVertex2f(3.8393268255285, 0.8435695505637);
        glVertex2f(3.9315350668877, 0.9518140078115);
        glVertex2f(4.0437885781077, 1.0400131951986);
        glVertex2f(4.1520330353555, 1.1041580587528);
        glVertex2f(4.2923499243805, 1.1602848143628);
        glVertex2f(4.4446939753218, 1.19235724614);
        glVertex2f(4.564965594486, 1.2003753540842);
        glVertex2f(4.677219105706, 1.2003753540842);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.7574001851488, 1.1883481921678);
        glVertex2f(4.7493452870858, 1.399897994033);
        glVertex2f(4.8, 1.6);
        glVertex2f(4.8398509404064, 1.7809744290672);
        glVertex2f(4.8922489502236, 1.923878092205);
        glVertex2f(4.9779911481063, 2.0620182999049);
        glVertex2f(5.058969890551, 2.1668143195393);
        glVertex2f(5.1590024547475, 2.2430296065461);
        glVertex2f(5.2733253852578, 2.3240083489909);
        glVertex2f(5.4448097810231, 2.381169814246);
        glVertex2f(5.5638961669713, 2.4240409131873);
        glVertex2f(5.7306171072987, 2.4383312795011);
        glVertex2f(5.8735207704366, 2.443094734939);
        glVertex2f(6.0259513444502, 2.4145140023115);
        glVertex2f(6.1307473640846, 2.3716429033701);
        glVertex2f(6.2545972054707, 2.3097179826771);
        glVertex2f(6.3451028587913, 2.2382661511082);
        glVertex2f(6.4356085121119, 2.1477604977876);
        glVertex2f(6.5118237991188, 2.0810721216566);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6075659970015, 0.5189491043303);
        glVertex2f(4.7984136415519, 0.5184801084376);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6.6070929078773, 2.0286741118394);
        glVertex2f(6.6618807259707, 2.0346881340904);
        glVertex2f(6.7086119328102, 2.0751885133513);
        glVertex2f(6.7833818637534, 2.1468430305052);
        glVertex2f(6.8581517946967, 2.2216129614485);
        glVertex2f(6.9298063118506, 2.2839212372345);
        glVertex2f(6.9921145876366, 2.3337678578633);
        glVertex2f(7.0793461737371, 2.3867298922815);
        glVertex2f(7.1291927943659, 2.4147686163852);
        glVertex2f(7.1946164839413, 2.4365765129103);
        glVertex2f(7.2631555873059, 2.4552689956461);
        glVertex2f(7.3285792768812, 2.4677306508033);
        glVertex2f(7.3971183802459, 2.4739614783819);
        glVertex2f(7.4563112422426, 2.4708460645926);
        glVertex2f(7.543542828343, 2.4583844094354);
        glVertex2f(7.6370052420221, 2.4365765129103);
        glVertex2f(7.7211214143332, 2.4147686163852);
        glVertex2f(7.8052375866444, 2.3742682371243);
        glVertex2f(7.8862383451662, 2.3244216164954);
        glVertex2f(7.9578928623202, 2.2745749958666);
        glVertex2f(8.0357782070527, 2.1904588235555);
        glVertex2f(8.0887402414708, 2.1188043064015);
        glVertex2f(8.1354714483104, 2.0378035478797);
        glVertex2f(8.1759718275713, 1.9443411342006);
        glVertex2f(8.2164722068322, 1.8384170653644);
        glVertex2f(8.2382801033573, 1.741839237896);
        glVertex2f(8.2538571723038, 1.6452614104277);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.2752293601814, 0.5227100407116);
        glVertex2f(6.5975659970015, 0.5229491043303);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.2632034136717, 1.5486835829593);
        glVertex2f(8.3511270930914, 1.559140812539);
        glVertex2f(8.4384847462886, 1.5658606320157);
        glVertex2f(8.5359221287009, 1.5725804514924);
        glVertex2f(8.6434392403282, 1.5625007222774);
        glVertex2f(8.7475964422172, 1.5423412638472);
        glVertex2f(8.8517536441062, 1.5121020762021);
        glVertex2f(8.9458311167801, 1.4617034301267);
        glVertex2f(9.0499883186691, 1.3777056866679);
        glVertex2f(9.1407058816046, 1.2601088458255);
        glVertex2f(9.2179838055868, 1.1492318244598);
        glVertex2f(9.2986216393073, 1.018195344664);
        glVertex2f(9.3591000145977, 0.8636394966997);
        glVertex2f(9.4061387509346, 0.7158034682121);
        glVertex2f(9.4262982093647, 0.5242886131259);
        glVertex2f(8.2752293601814, 0.5247100407116);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void tree() {
    glPushMatrix();
    glTranslated(treelvl1[0],1.1,0);                             //Fungsi untuk gerak
    glPushMatrix();
    glTranslated(0.045,-0.09,0);
    glScaled(1,1.5,0);
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(3.6154593394793,2.0559120871745);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0559120871745);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0709120871745);
        glVertex2f(4.46601270721627,2.0709045946805);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(4.2363497122109,2.0529487015985);
        glVertex2f(4.2359062416316,1.0131331870454);
        glVertex2f(4.7647887345752,1.0139533985118);
        glVertex2f(4.7646089460416,2.0605385958653);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glScaled(1,1.5,0);
    glColor3ub(57, 124, 11);
    glBegin(GL_POLYGON);
        glVertex2f(3.6154593394793,2.0559120871745);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0559120871745);
    glEnd();

    glColor3ub(88, 189, 66);
    glBegin(GL_POLYGON);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0709120871745);
        glVertex2f(4.46601270721627,2.0709045946805);
    glEnd();

    glColor3ub(92, 58, 10);
    glBegin(GL_QUADS);
        glVertex2f(4.2363497122109,2.0529487015985);
        glVertex2f(4.2359062416316,1.0131331870454);
        glVertex2f(4.7647887345752,1.0139533985118);
        glVertex2f(4.7646089460416,2.0605385958653);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(treelvl1[1],1.1,0);                             //Fungsi untuk gerak
    glPushMatrix();
    glTranslated(0.045,-0.09,0);
    glScaled(1,1.5,0);
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(3.6154593394793,2.0559120871745);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0559120871745);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0709120871745);
        glVertex2f(4.46601270721627,2.0709045946805);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(4.2363497122109,2.0529487015985);
        glVertex2f(4.2359062416316,1.0131331870454);
        glVertex2f(4.7647887345752,1.0139533985118);
        glVertex2f(4.7646089460416,2.0605385958653);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glScaled(1,1.5,0);
    glColor3ub(57, 124, 11);
    glBegin(GL_POLYGON);
        glVertex2f(3.6154593394793,2.0559120871745);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0559120871745);
    glEnd();

    glColor3ub(88, 189, 66);
    glBegin(GL_POLYGON);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0709120871745);
        glVertex2f(4.46601270721627,2.0709045946805);
    glEnd();

    glColor3ub(92, 58, 10);
    glBegin(GL_QUADS);
        glVertex2f(4.2363497122109,2.0529487015985);
        glVertex2f(4.2359062416316,1.0131331870454);
        glVertex2f(4.7647887345752,1.0139533985118);
        glVertex2f(4.7646089460416,2.0605385958653);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(treelvl1[2],1.1,0);                             //Fungsi untuk gerak
    glPushMatrix();
    glTranslated(0.045,-0.09,0);
    glScaled(1,1.5,0);
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(3.6154593394793,2.0559120871745);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0559120871745);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0709120871745);
        glVertex2f(4.46601270721627,2.0709045946805);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(4.2363497122109,2.0529487015985);
        glVertex2f(4.2359062416316,1.0131331870454);
        glVertex2f(4.7647887345752,1.0139533985118);
        glVertex2f(4.7646089460416,2.0605385958653);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glScaled(1,1.5,0);
    glColor3ub(57, 124, 11);
    glBegin(GL_POLYGON);
        glVertex2f(3.6154593394793,2.0559120871745);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0559120871745);
    glEnd();

    glColor3ub(88, 189, 66);
    glBegin(GL_POLYGON);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0709120871745);
        glVertex2f(4.46601270721627,2.0709045946805);
    glEnd();

    glColor3ub(92, 58, 10);
    glBegin(GL_QUADS);
        glVertex2f(4.2363497122109,2.0529487015985);
        glVertex2f(4.2359062416316,1.0131331870454);
        glVertex2f(4.7647887345752,1.0139533985118);
        glVertex2f(4.7646089460416,2.0605385958653);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(treelvl1[3],1.1,0);                             //Fungsi untuk gerak
    glPushMatrix();
    glTranslated(0.045,-0.09,0);
    glScaled(1,1.5,0);
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(3.6154593394793,2.0559120871745);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0559120871745);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0709120871745);
        glVertex2f(4.46601270721627,2.0709045946805);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(4.2363497122109,2.0529487015985);
        glVertex2f(4.2359062416316,1.0131331870454);
        glVertex2f(4.7647887345752,1.0139533985118);
        glVertex2f(4.7646089460416,2.0605385958653);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glScaled(1,1.5,0);
    glColor3ub(57, 124, 11);
    glBegin(GL_POLYGON);
        glVertex2f(3.6154593394793,2.0559120871745);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0559120871745);
    glEnd();

    glColor3ub(88, 189, 66);
    glBegin(GL_POLYGON);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0709120871745);
        glVertex2f(4.46601270721627,2.0709045946805);
    glEnd();

    glColor3ub(92, 58, 10);
    glBegin(GL_QUADS);
        glVertex2f(4.2363497122109,2.0529487015985);
        glVertex2f(4.2359062416316,1.0131331870454);
        glVertex2f(4.7647887345752,1.0139533985118);
        glVertex2f(4.7646089460416,2.0605385958653);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(treelvl1[4],1.1,0);                             //Fungsi untuk gerak
    glPushMatrix();
    glTranslated(0.045,-0.09,0);
    glScaled(1,1.5,0);
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(3.6154593394793,2.0559120871745);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0559120871745);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0709120871745);
        glVertex2f(4.46601270721627,2.0709045946805);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(4.2363497122109,2.0529487015985);
        glVertex2f(4.2359062416316,1.0131331870454);
        glVertex2f(4.7647887345752,1.0139533985118);
        glVertex2f(4.7646089460416,2.0605385958653);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glScaled(1,1.5,0);
    glColor3ub(57, 124, 11);
    glBegin(GL_POLYGON);
        glVertex2f(3.6154593394793,2.0559120871745);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0559120871745);
    glEnd();

    glColor3ub(88, 189, 66);
    glBegin(GL_POLYGON);
        glVertex2f(4.4661808184098,4.928840360284);
        glVertex2f(5.3726873123521,2.0709120871745);
        glVertex2f(4.46601270721627,2.0709045946805);
    glEnd();

    glColor3ub(92, 58, 10);
    glBegin(GL_QUADS);
        glVertex2f(4.2363497122109,2.0529487015985);
        glVertex2f(4.2359062416316,1.0131331870454);
        glVertex2f(4.7647887345752,1.0139533985118);
        glVertex2f(4.7646089460416,2.0605385958653);
    glEnd();
    glPopMatrix();
    glPopMatrix();

}

void blackBird (){
    glPushMatrix();
    glTranslated(xx,0,0);
    glScaled(0.6,1,0);
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(4.1854085678641, 7.498111024205);
        glVertex2f(4.2230074490635, 7.4402665915905);
        glVertex2f(4.2461452221093, 7.3939910454989);
        glVertex2f(4.2461452221093, 7.3245777263615);
        glVertex2f(4.2188472436702, 7.2258098515305);
        glVertex2f(4.2389680565845, 7.1778294515041);
        glVertex2f(4.2544456049802, 7.139135580515);
        glVertex2f(4.2575411146593, 7.0756776320929);
        glVertex2f(4.237420301745, 7.0060286643125);
        glVertex2f(4.2188472436702, 6.9735258126817);
        glVertex2f(4.1894399017185, 6.9255454126553);
        glVertex2f(4.2296815275471, 6.8868515416662);
        glVertex2f(4.2544456049802, 6.8388711416397);
        glVertex2f(4.2327770372263, 6.7583878899824);
        glVertex2f(4.2, 6.7);
        glVertex2f(4.1600325597668, 6.6221854641008);
        glVertex2f(4.1863443920394, 6.5803960834326);
        glVertex2f(4.1942866786348, 6.5390361591411);
        glVertex2f(4.1900692571871, 6.469448705254);
        glVertex2f(4.1647647285009, 6.4019699620908);
        glVertex2f(4.1384058444528, 6.3355455742894);
        glVertex2f(4.0877506543496, 6.2640497789122);
        glVertex2f(4.1236162000052, 6.2134775338519);
        glVertex2f(4.1051597497066, 6.1488799578065);
        glVertex2f(3.9682744099913, 5.9720056424441);
        glVertex2f(3.9944210479145, 5.9197123665978);
        glVertex2f(3.9498179596926, 5.8412724528284);
        glVertex2f(3.8458547931422, 5.7280282347733);
        glVertex2f(3.8893685111308, 5.656665737272);
        glVertex2f(3.8737035726549, 5.6183736654421);
        glVertex2f(3.9236557793681, 5.5727130921381);
        glVertex2f(3.9487195492106, 5.4975217826107);
        glVertex2f(4, 5.4);
        glVertex2f(4.0521075998108, 5.3158094512527);
        glVertex2f(4.0677724559624, 5.2218203143435);
        glVertex2f(4.0771713696533, 5.0808366089795);
        glVertex2f(4.0803043408836, 4.9649166734581);
        glVertex2f(4.0682289404477, 4.8621136989953);
        glVertex2f(3.7012148220162, 4.8301989105548);
        glVertex2f(3.2014266899873, 4.8820193874192);
        glVertex2f(2.9969409816324, 5.330802180977);
        glVertex2f(2.9697968610543, 5.4267114070196);
        glVertex2f(3.1410949531459, 5.8629245804679);
        glVertex2f(3.4621214469152, 6.4110507817685);
        glVertex2f(3.7270487195836, 6.8445681370441);
        glVertex2f(3.914906240203, 7.15284714524);
        glVertex2f(4.0920174277169, 7.3869767577663);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2f(4.0412806356552, 1.5811057647863);
        glVertex2f(4.0825095405145, 1.6921066624846);
        glVertex2f(4.1031555488173, 1.7680322285251);
        glVertex2f(4.1257975105798, 1.8683037734735);
        glVertex2f(4.1403530574272, 1.9572543375407);
        glVertex2f(4.132266642512, 2.0219456568623);
        glVertex2f(4.1, 2.1);
        glVertex2f(4.1549086042746, 2.1707356913019);
        glVertex2f(4.1371184914611, 2.2774763681825);
        glVertex2f(4.1160938126816, 2.3551059513684);
        glVertex2f(4.0853654360039, 2.4052417238426);
        glVertex2f(4.1225629446138, 2.4731676091302);
        glVertex2f(4.1192602562765, 2.5715680407472);
        glVertex2f(4.0980224923829, 2.652979469006);
        glVertex2f(4.0449280826489, 2.7556286611583);
        glVertex2f(4.0570541966915, 2.846905355316);
        glVertex2f(4.0152640276762, 2.9332717046143);
        glVertex2f(3.9874039149993, 3.0335681102512);
        glVertex2f(4.0041199826055, 3.1282924933526);
        glVertex2f(3.9265981993488, 3.2461348855156);
        glVertex2f(3.832505456682, 3.3418499168491);
        glVertex2f(3.8693314094154, 3.503105410316);
        glVertex2f(3.9261115127488, 3.6328885036495);
        glVertex2f(3.966399343703, 3.7818652091233);
        glVertex2f(4.0120757926662, 3.8660060361608);
        glVertex2f(4.0649643125183, 3.9645710049761);
        glVertex2f(3.6803205317756, 4.1040043754953);
        glVertex2f(3.161051427773, 4.0294796429764);
        glVertex2f(3.0095979391056, 3.7097445002341);
        glVertex2f(2.9759416082906, 3.6328157440855);
        glVertex2f(2.9927697736981, 3.5630990588259);
        glVertex2f(3.2459696348958, 3.0649249059603);
        glVertex2f(3.542251531013, 2.472361113726);
        glVertex2f(3.9141106985355, 1.767482018388);
        glVertex2f(3.9898674128588, 1.6470482674124);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2f(2.2394320792998, 4.4665615886366);
        glVertex2f(2.3789963037155, 4.5650775117536);
        glVertex2f(2.3778773468729, 4.6660183384564);
        glVertex2f(2.4366538979944, 4.7527837234452);
        glVertex2f(2.4982293325026, 4.8171580413402);
        glVertex2f(2.5821958341047, 4.8703368256882);
        glVertex2f(2.696950052961, 4.8927278927821);
        glVertex2f(2.8340953389111, 4.8843312426219);
        glVertex2f(2.9376540242204, 4.8703368256882);
        glVertex2f(3.027218292596, 4.8591412921413);
        glVertex2f(3.1139836775849, 4.8675379423015);
        glVertex2f(3.2007490625738, 4.9039234263291);
        glVertex2f(4.0851962127829, 4.8703368256882);
        glVertex2f(4.2651557831396, 4.852730010797);
        glVertex2f(4.3839652702502, 4.841232318496);
        glVertex2f(4.5449329624645, 4.829734626195);
        glVertex2f(4.6484121931737, 4.8373997543957);
        glVertex2f(4.8132124494884, 4.8833905235998);
        glVertex2f(5.0968221929137, 4.986869754309);
        glVertex2f(5.2939976133325, 5.0761768846446);
        glVertex2f(5.4869672723937, 5.1572241414503);
        glVertex2f(5.679936931455, 5.238271398256);
        glVertex2f(5.869047197335, 5.3231780482429);
        glVertex2f(6.5174252517806, 5.6743828277343);
        glVertex2f(6.5946131154051, 5.6666640413719);
        glVertex2f(6.5251440381431, 5.5701792118413);
        glVertex2f(5.9307974882345, 5.1610835346315);
        glVertex2f(5.5294205973872, 4.8677696528584);
        glVertex2f(5.2399661087954, 4.6632218142536);
        glVertex2f(5.4831078792125, 4.5281430529107);
        glVertex2f(5.6374836064615, 4.447095796105);
        glVertex2f(5.8420314450664, 4.3506109665744);
        glVertex2f(6.0234229245839, 4.2850012824936);
        glVertex2f(6.2, 4.2);
        glVertex2f(6.5174252517806, 4.1306255552446);
        glVertex2f(6.7181136972043, 4.0534376916201);
        glVertex2f(6.7103949108418, 3.9878280075393);
        glVertex2f(6.2974398404509, 4.0650158711638);
        glVertex2f(5.7995781200729, 4.1422037347883);
        glVertex2f(5.4290763746754, 4.2116728120503);
        glVertex2f(5.1048873474525, 4.2657043165875);
        glVertex2f(4.8810425429415, 4.2811418893124);
        glVertex2f(4.7421043884175, 4.2464073506813);
        glVertex2f(4.5761504816248, 4.1499225211507);
        glVertex2f(4.3137117453016, 4.0457189052577);
        glVertex2f(4.0754389791879, 3.9430916136486);
        glVertex2f(3.1474077191211, 4.0362051180031);
        glVertex2f(2.9518693599767, 4.1044883545298);
        glVertex2f(2.7780574851815, 4.1665640240995);
        glVertex2f(2.6787364138701, 4.2348472606261);
        glVertex2f(2.5670002086446, 4.3186494145452);
        glVertex2f(2.4614715703762, 4.4024515684642);
        glVertex2f(2.3679250524372, 4.4331546567599);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glPointSize(2);
    glBegin(GL_POINTS);
        glVertex2f(2.5633015912153,4.6700170696016);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}

void stone (){
    //gelombang1
    glPushMatrix(); //awal bayangan batu pertama
    glTranslated(stonelvl1[0],0,0);
    glPushMatrix();
    glColor3ub(149, 137, 123);
    glBegin(GL_POLYGON);
        glVertex2f(4.738026756087, 4.4928689496625);
        glVertex2f(4.7099701792914, 4.4033982385563);
        glVertex2f(4.682801607065, 4.3169527814724);
        glVertex2f(4.6556330348386, 4.2206278435788);
        glVertex2f(4.6136452413978, 4.1168932950781);
        glVertex2f(4.5691875777547, 4.0156286167798);
        glVertex2f(4.5370792651235, 3.936592770303);
        glVertex2f(4.4827421206707, 3.8303883515999);
        glVertex2f(4.4259351060155, 3.7439428945159);
        glVertex2f(4.3617184807532, 3.6550275672295);
        glVertex2f(4.304911466098, 3.571051980348);
        glVertex2f(4.230815360026, 3.4697873020496);
        glVertex2f(4.1419000327397, 3.3685226237513);
        glVertex2f(4.0480449650485, 3.2894867772745);
        glVertex2f(3.9665392483694, 3.2277400222146);
        glVertex2f(3.8924431422974, 3.1610535267498);
        glVertex2f(3.7600295172382, 3.0891982390034);
        glVertex2f(3.6170341969792, 3.0534494089386);
        glVertex2f(3.4094426563349, 5.5446596590355);
        glVertex2f(3.5816992440288, 5.4413057064192);
        glVertex2f(3.8271648814925, 5.2819683628023);
        glVertex2f(4.081243348341, 5.0924861163391);
    glEnd();
    glPopMatrix();

    //gelombang2
    glPushMatrix();
    glColor3ub(149, 137, 123);
    glBegin(GL_POLYGON);
        glVertex2f(3.6170341969792, 3.0534494089386);
        glVertex2f(3.4299489556579, 3.0112192593042);
        glVertex2f(3.2435762857043, 2.9706812526928);
        glVertex2f(3.0327360697258, 2.9744931768916);
        glVertex2f(2.7675580397181, 2.9744931768916);
        glVertex2f(2.5798935877126, 2.9744931768916);
        glVertex2f(2.4493444037088, 2.9785728388917);
        glVertex2f(2.3106358957047, 2.9581745288911);
        glVertex2f(1.7799926078952, 5.261794769256);
        glVertex2f(1.8411743125291, 5.3135639039462);
        glVertex2f(1.9070623021348, 5.3676861811223);
        glVertex2f(1.9894222891419, 5.4288678857561);
        glVertex2f(2.0741354186349, 5.4924027328759);
        glVertex2f(2.1682611180716, 5.5559375799957);
        glVertex2f(2.2402775935525, 5.6032293484427);
        glVertex2f(2.3237045468987, 5.6466113641827);
        glVertex2f(2.4104685783787, 5.6866563017889);
        glVertex2f(2.4888899145241, 5.7233641612612);
        glVertex2f(2.5673112506695, 5.750060786332);
        glVertex2f(2.6574123602834, 5.7734203332689);
        glVertex2f(2.7232071859268, 5.7880250781958);
        glVertex2f(2.7892113582412, 5.7825247305029);
        glVertex2f(2.8552155305556, 5.7687738612707);
        glVertex2f(2.9569719628735, 5.7412721228064);
        glVertex2f(3.0436024390361, 5.7137703843421);
        glVertex2f(3.1329830890452, 5.6780181243385);
        glVertex2f(3.2058626959756, 5.6505163858742);
        glVertex2f(3.3, 5.6);
        glVertex2f(3.4094426563349, 5.5446596590355);
    glEnd();
    glPopMatrix();

    //gelombang3
    glPushMatrix();
    glColor3ub(149, 137, 123);
    glBegin(GL_POLYGON);
        glVertex2f(2.3106358957047, 2.9581745288911);
        glVertex2f(2.2111473837105, 2.9457144238163);
        glVertex2f(2.0854934536604, 2.9186125957663);
        glVertex2f(1.9352014981103, 2.8816555575163);
        glVertex2f(1.8021561604102, 2.8373071116163);
        glVertex2f(1.6962126507601, 2.7904948631662);
        glVertex2f(1.57055872071, 2.7535378249162);
        glVertex2f(1.48678943401, 2.7288997994162);
        glVertex2f(1.3882373320099, 2.7141169841162);
        glVertex2f(1.305073047168, 2.6980732898434);
        glVertex2f(1.1805998080475, 2.6798576938746);
        glVertex2f(1.0561265689271, 2.6707498958902);
        glVertex2f(0.9529048584369, 2.6768217612131);
        glVertex2f(0.8314675519779, 2.6874576317399);
        glVertex2f(0.7087851469016, 2.7101765956429);
        glVertex2f(0.5770151562641, 2.7397112487168);
        glVertex2f(0.4429732692362, 2.778333487352);
        glVertex2f(0.1561076683682, 2.8877869964524);
        glVertex2f(0.2178071285191, 3.1389919413526);
        glVertex2f(0.3015421101525, 3.3946039905493);
        glVertex2f(0.4, 3.6);
        glVertex2f(0.5218973249772, 3.8132788987163);
        glVertex2f(0.5968180980176, 3.9675275490936);
        glVertex2f(0.6182121531459, 4.0211323659089);
        glVertex2f(0.9118423147879, 4.3763532443831);
        glVertex2f(1.7799926078952, 5.261794769256);
    glEnd();
    glPopMatrix(); //akhir bayangan batu pertama

    //batu paling belakang//
    glPushMatrix();
    glScaled(3,3,0);
    glColor3ub(99, 92, 84);
    glBegin(GL_POLYGON);
        glVertex2f(0, 2);
        glVertex2f(2.7970309581327, 0.9589302424881);
        glVertex2f(3.7166551415385, 1.292519778856);
        glVertex2f(5.2196974003926, 2.7653501330095);
        glVertex2f(4.788796765762, 4.4702274891024);
        glVertex2f(2.7249075038004, 5.7700625385591);
        glVertex2f(2.8010680928808, 5.7700625385591);
        glVertex2f(2.8657303207158, 5.7609692510813);
        glVertex2f(2.9092536319106, 5.7515392003224);
        glVertex2f(2.9542277201453, 5.7413837610436);
        glVertex2f(3.0050049165394, 5.7283267676851);
        glVertex2f(3.0572328899732, 5.7101920546872);
        glVertex2f(3.1065593093274, 5.6906065646495);
        glVertex2f(3.1450049008829, 5.6768241827712);
        glVertex2f(3.1751647931456, 5.6612063177873);
        glVertex2f(3.2106661925986, 5.6462168380182);
        glVertex2f(3.2501121919908, 5.6304384382613);
        glVertex2f(3.2824579114924, 5.6130821985288);
        glVertex2f(3.3179593109454, 5.596514878784);
        glVertex2f(3.3479382704835, 5.5775807990758);
        glVertex2f(3.3810729099729, 5.5602245593432);
        glVertex2f(3.4149964694502, 5.541290479635);
        glVertex2f(3.4871801020532, 5.5049332316904);
        glVertex2f(3.641708360558, 5.4035602729888);
        glVertex2f(3.7707624085591, 5.3200547125175);
        glVertex2f(3.8517374975011, 5.259323395811);
        glVertex2f(3.9187949930311, 5.2150401440459);
        glVertex2f(4.0134696219567, 5.1457447064906);
        glVertex2f(4.1316939150287, 5.0523093780949);
        glVertex2f(4.2823345465237, 4.9302713981496);
        glVertex2f(4.4081862133423, 4.8196744788242);
        glVertex2f(4.6077234992707, 4.6461684760757);
        glVertex2f(2.6524327692281, 5.7670175359923);
        glVertex2f(2.6142523432932, 5.7559087457364);
        glVertex2f(2.5623822794297, 5.7404580884154);
        glVertex2f(2.5138230707065, 5.7250074310943);
        glVertex2f(2.4663674803632, 5.7062459186331);
        glVertex2f(2.4233263635403, 5.6874844061718);
        glVertex2f(2.3626273526362, 5.6598939466699);
        glVertex2f(2.2930993946915, 5.6245781585076);
        glVertex2f(2.2413296597717, 5.5979909884421);
        glVertex2f(2.1801290041493, 5.5608692792942);
        glVertex2f(2.1239447957092, 5.5257541490191);
        glVertex2f(2.0802333931197, 5.497859696411);
        glVertex2f(2.0350437055718, 5.4677332380458);
        glVertex2f(2.0013791991049, 5.4373563860324);
        glVertex2f(1.9561102909678, 5.4034047049295);
        glVertex2f(1.9179146497271, 5.3765262907231);
        glVertex2f(1.8825483152449, 5.3468185697581);
        glVertex2f(1.7446125423668, 5.2319072667468);
        glVertex2f(1.5924263548127, 5.0886732078725);
        glVertex2f(1.4312880385791, 4.9454391489981);
        glVertex2f(1.2791018510251, 4.7932529614441);
        glVertex2f(1.126915663471, 4.6142103878511);
        glVertex2f(0.6076922000514, 4.0144177663147);
        glVertex2f(0.5054800359743, 3.8169035577273);
        glVertex2f(0.4306607439754, 3.6672649737296);
        glVertex2f(0.3734459912704, 3.5704400076134);
        glVertex2f(0.3250335082123, 3.4780161763207);
        glVertex2f(0.2810221599777, 3.3503832664403);
        glVertex2f(0.2414119465665, 3.2491571655006);
        glVertex2f(0.188598328685, 3.081914042209);
        glVertex2f(0.1445869804503, 2.9058686492705);
        glVertex2f(0.1137790366861, 2.8046425483309);
        glVertex2f(0.0537370270969, 2.4689041894516);
    glEnd();
    glPopMatrix();

    //gelombang2.1
    glPushMatrix();
    glColor3ub(120, 111, 102);
    glBegin(GL_POLYGON);
        glVertex2f(5.1259907182453, 3.1331779311995);
        glVertex2f(4.9567473601459, 2.8202461615901);
        glVertex2f(5.0206347266191, 2.9224659479471);
        glVertex2f(4.8724160364014, 2.7052489019384);
        glVertex2f(4.7983066912926, 2.6439170301242);
        glVertex2f(4.7267528408427, 2.5365862544494);
        glVertex2f(4.5989781078964, 2.4266999841156);
        glVertex2f(4.5299797521054, 2.2912587671925);
        glVertex2f(4.4507594176787, 2.1864834861766);
        glVertex2f(4.374094577911, 2.0970411731142);
        glVertex2f(4.2795412755307, 2.0178208386875);
        glVertex2f(4.1747659945148, 1.9462669882376);
        glVertex2f(4.064879724181, 1.8798241271055);
        glVertex2f(3.9575489485061, 1.8542691805163);
        glVertex2f(3.8690194258291, 1.8178100359076);
        glVertex2f(3.7808609209194, 1.787798629981);
        glVertex2f(3.6908267031394, 1.7596629369247);
        glVertex2f(3.5895382081369, 1.7484086597022);
        glVertex2f(3.5051311289681, 1.7390300953501);
        glVertex2f(3.415096911188, 1.7334029567388);
        glVertex2f(3.28942414887, 1.7427815210909);
        glVertex2f(3.2050170697012, 1.7634143626655);
        glVertex2f(3.1393671192366, 1.7802957784993);
        glVertex2f(3.0643386044199, 1.8065557586851);
        glVertex2f(2.9727840136691, 1.8462971209928);
        glVertex2f(2.8787634728229, 1.9168125266274);
        glVertex2f(2.8056363854982, 1.9742695238111);
        glVertex2f(2.7403443432439, 2.0317265209949);
        glVertex2f(2.6541588474683, 2.1596989238132);
        glVertex2f(2.5758083967632, 2.2589428280397);
        glVertex2f(2.4008257235218, 2.5279460421272);
        glVertex2f(2.3287687808607, 2.6292468409997);
        glVertex2f(2.2895732739477, 2.6829592023248);
        glVertex2f(2.2169890018867, 2.7613502161508);
        glVertex2f(2.1197260773249, 2.8440962863003);
        glVertex2f(2.0660137159997, 2.8949052767431);
        glVertex2f(1.9744685384962, 3.5684106342475);
        glVertex2f(4.7421153153178, 4.5058029810992);
        glVertex2f(4.7979939454576, 4.4592374559827);
    glEnd();
    glPopMatrix();

    //gelombang2.2
    glPushMatrix();
    glColor3ub(120, 111, 102);
    glBegin(GL_POLYGON);
        glVertex2f(2.0660137159997, 2.8949052767431);
        glVertex2f(2.0355667305675, 2.8893334325315);
        glVertex2f(2.0695393753836, 2.8044018204914);
        glVertex2f(2.0940751744174, 2.6873849327918);
        glVertex2f(2.1261604500769, 2.4873238022085);
        glVertex2f(2.1280478192334, 2.2985868865639);
        glVertex2f(2.1072867585125, 2.1268362933273);
        glVertex2f(2.0669875650295, 1.9664956863123);
        glVertex2f(2.0277560656591, 1.8578546111327);
        glVertex2f(2.0005957968642, 1.823149823228);
        glVertex2f(1.9673999127815, 1.7869361315015);
        glVertex2f(1.931186221055, 1.7522313435969);
        glVertex2f(1.8859191063968, 1.7220532671581);
        glVertex2f(1.8391430879167, 1.6948929983632);
        glVertex2f(1.7878403579708, 1.6813128639658);
        glVertex2f(1.7410643394906, 1.6782950563219);
        glVertex2f(1.6867438019008, 1.675277248678);
        glVertex2f(1.6158253222697, 1.6782950563219);
        glVertex2f(1.3396959228548, 1.7024375174729);
        glVertex2f(1.1830820700626, 1.7277417435043);
        glVertex2f(0.9973623742528, 1.7693685718755);
        glVertex2f(0.8420622837911, 1.8190005595488);
        glVertex2f(0.6147157596102, 1.9006531844307);
        glVertex2f(0.4337991593816, 1.9967150960565);
        glVertex2f(0.289706291943, 2.0783677209384);
        glVertex2f(0.0335411942743, 2.2640874167482);
        glVertex2f(0.0464540031948, 2.4062873723379);
        glVertex2f(0.0830774060369, 2.6040537476856);
        glVertex2f(0.138744978357, 2.8809266731724);
        glVertex2f(1.8867920012269, 3.2858141462174);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //gelombang1 dan BATU KE 2
    glPushMatrix(); //awal bayangan batu pertama
    glTranslated(stonelvl1[1],11,0);
    glPushMatrix();
    glColor3ub(149, 137, 123);
    glBegin(GL_POLYGON);
        glVertex2f(4.738026756087, 4.4928689496625);
        glVertex2f(4.7099701792914, 4.4033982385563);
        glVertex2f(4.682801607065, 4.3169527814724);
        glVertex2f(4.6556330348386, 4.2206278435788);
        glVertex2f(4.6136452413978, 4.1168932950781);
        glVertex2f(4.5691875777547, 4.0156286167798);
        glVertex2f(4.5370792651235, 3.936592770303);
        glVertex2f(4.4827421206707, 3.8303883515999);
        glVertex2f(4.4259351060155, 3.7439428945159);
        glVertex2f(4.3617184807532, 3.6550275672295);
        glVertex2f(4.304911466098, 3.571051980348);
        glVertex2f(4.230815360026, 3.4697873020496);
        glVertex2f(4.1419000327397, 3.3685226237513);
        glVertex2f(4.0480449650485, 3.2894867772745);
        glVertex2f(3.9665392483694, 3.2277400222146);
        glVertex2f(3.8924431422974, 3.1610535267498);
        glVertex2f(3.7600295172382, 3.0891982390034);
        glVertex2f(3.6170341969792, 3.0534494089386);
        glVertex2f(3.4094426563349, 5.5446596590355);
        glVertex2f(3.5816992440288, 5.4413057064192);
        glVertex2f(3.8271648814925, 5.2819683628023);
        glVertex2f(4.081243348341, 5.0924861163391);
    glEnd();
    glPopMatrix();

    //gelombang2
    glPushMatrix();
    glColor3ub(149, 137, 123);
    glBegin(GL_POLYGON);
        glVertex2f(3.6170341969792, 3.0534494089386);
        glVertex2f(3.4299489556579, 3.0112192593042);
        glVertex2f(3.2435762857043, 2.9706812526928);
        glVertex2f(3.0327360697258, 2.9744931768916);
        glVertex2f(2.7675580397181, 2.9744931768916);
        glVertex2f(2.5798935877126, 2.9744931768916);
        glVertex2f(2.4493444037088, 2.9785728388917);
        glVertex2f(2.3106358957047, 2.9581745288911);
        glVertex2f(1.7799926078952, 5.261794769256);
        glVertex2f(1.8411743125291, 5.3135639039462);
        glVertex2f(1.9070623021348, 5.3676861811223);
        glVertex2f(1.9894222891419, 5.4288678857561);
        glVertex2f(2.0741354186349, 5.4924027328759);
        glVertex2f(2.1682611180716, 5.5559375799957);
        glVertex2f(2.2402775935525, 5.6032293484427);
        glVertex2f(2.3237045468987, 5.6466113641827);
        glVertex2f(2.4104685783787, 5.6866563017889);
        glVertex2f(2.4888899145241, 5.7233641612612);
        glVertex2f(2.5673112506695, 5.750060786332);
        glVertex2f(2.6574123602834, 5.7734203332689);
        glVertex2f(2.7232071859268, 5.7880250781958);
        glVertex2f(2.7892113582412, 5.7825247305029);
        glVertex2f(2.8552155305556, 5.7687738612707);
        glVertex2f(2.9569719628735, 5.7412721228064);
        glVertex2f(3.0436024390361, 5.7137703843421);
        glVertex2f(3.1329830890452, 5.6780181243385);
        glVertex2f(3.2058626959756, 5.6505163858742);
        glVertex2f(3.3, 5.6);
        glVertex2f(3.4094426563349, 5.5446596590355);
    glEnd();
    glPopMatrix();

    //gelombang3
    glPushMatrix();
    glColor3ub(149, 137, 123);
    glBegin(GL_POLYGON);
        glVertex2f(2.3106358957047, 2.9581745288911);
        glVertex2f(2.2111473837105, 2.9457144238163);
        glVertex2f(2.0854934536604, 2.9186125957663);
        glVertex2f(1.9352014981103, 2.8816555575163);
        glVertex2f(1.8021561604102, 2.8373071116163);
        glVertex2f(1.6962126507601, 2.7904948631662);
        glVertex2f(1.57055872071, 2.7535378249162);
        glVertex2f(1.48678943401, 2.7288997994162);
        glVertex2f(1.3882373320099, 2.7141169841162);
        glVertex2f(1.305073047168, 2.6980732898434);
        glVertex2f(1.1805998080475, 2.6798576938746);
        glVertex2f(1.0561265689271, 2.6707498958902);
        glVertex2f(0.9529048584369, 2.6768217612131);
        glVertex2f(0.8314675519779, 2.6874576317399);
        glVertex2f(0.7087851469016, 2.7101765956429);
        glVertex2f(0.5770151562641, 2.7397112487168);
        glVertex2f(0.4429732692362, 2.778333487352);
        glVertex2f(0.1561076683682, 2.8877869964524);
        glVertex2f(0.2178071285191, 3.1389919413526);
        glVertex2f(0.3015421101525, 3.3946039905493);
        glVertex2f(0.4, 3.6);
        glVertex2f(0.5218973249772, 3.8132788987163);
        glVertex2f(0.5968180980176, 3.9675275490936);
        glVertex2f(0.6182121531459, 4.0211323659089);
        glVertex2f(0.9118423147879, 4.3763532443831);
        glVertex2f(1.7799926078952, 5.261794769256);
    glEnd();
    glPopMatrix(); //akhir bayangan batu pertama

    //batu paling belakang//
    glPushMatrix();
    glScaled(3,3,0);
    glColor3ub(99, 92, 84);
    glBegin(GL_POLYGON);
        glVertex2f(0, 2);
        glVertex2f(2.7970309581327, 0.9589302424881);
        glVertex2f(3.7166551415385, 1.292519778856);
        glVertex2f(5.2196974003926, 2.7653501330095);
        glVertex2f(4.788796765762, 4.4702274891024);
        glVertex2f(2.7249075038004, 5.7700625385591);
        glVertex2f(2.8010680928808, 5.7700625385591);
        glVertex2f(2.8657303207158, 5.7609692510813);
        glVertex2f(2.9092536319106, 5.7515392003224);
        glVertex2f(2.9542277201453, 5.7413837610436);
        glVertex2f(3.0050049165394, 5.7283267676851);
        glVertex2f(3.0572328899732, 5.7101920546872);
        glVertex2f(3.1065593093274, 5.6906065646495);
        glVertex2f(3.1450049008829, 5.6768241827712);
        glVertex2f(3.1751647931456, 5.6612063177873);
        glVertex2f(3.2106661925986, 5.6462168380182);
        glVertex2f(3.2501121919908, 5.6304384382613);
        glVertex2f(3.2824579114924, 5.6130821985288);
        glVertex2f(3.3179593109454, 5.596514878784);
        glVertex2f(3.3479382704835, 5.5775807990758);
        glVertex2f(3.3810729099729, 5.5602245593432);
        glVertex2f(3.4149964694502, 5.541290479635);
        glVertex2f(3.4871801020532, 5.5049332316904);
        glVertex2f(3.641708360558, 5.4035602729888);
        glVertex2f(3.7707624085591, 5.3200547125175);
        glVertex2f(3.8517374975011, 5.259323395811);
        glVertex2f(3.9187949930311, 5.2150401440459);
        glVertex2f(4.0134696219567, 5.1457447064906);
        glVertex2f(4.1316939150287, 5.0523093780949);
        glVertex2f(4.2823345465237, 4.9302713981496);
        glVertex2f(4.4081862133423, 4.8196744788242);
        glVertex2f(4.6077234992707, 4.6461684760757);
        glVertex2f(2.6524327692281, 5.7670175359923);
        glVertex2f(2.6142523432932, 5.7559087457364);
        glVertex2f(2.5623822794297, 5.7404580884154);
        glVertex2f(2.5138230707065, 5.7250074310943);
        glVertex2f(2.4663674803632, 5.7062459186331);
        glVertex2f(2.4233263635403, 5.6874844061718);
        glVertex2f(2.3626273526362, 5.6598939466699);
        glVertex2f(2.2930993946915, 5.6245781585076);
        glVertex2f(2.2413296597717, 5.5979909884421);
        glVertex2f(2.1801290041493, 5.5608692792942);
        glVertex2f(2.1239447957092, 5.5257541490191);
        glVertex2f(2.0802333931197, 5.497859696411);
        glVertex2f(2.0350437055718, 5.4677332380458);
        glVertex2f(2.0013791991049, 5.4373563860324);
        glVertex2f(1.9561102909678, 5.4034047049295);
        glVertex2f(1.9179146497271, 5.3765262907231);
        glVertex2f(1.8825483152449, 5.3468185697581);
        glVertex2f(1.7446125423668, 5.2319072667468);
        glVertex2f(1.5924263548127, 5.0886732078725);
        glVertex2f(1.4312880385791, 4.9454391489981);
        glVertex2f(1.2791018510251, 4.7932529614441);
        glVertex2f(1.126915663471, 4.6142103878511);
        glVertex2f(0.6076922000514, 4.0144177663147);
        glVertex2f(0.5054800359743, 3.8169035577273);
        glVertex2f(0.4306607439754, 3.6672649737296);
        glVertex2f(0.3734459912704, 3.5704400076134);
        glVertex2f(0.3250335082123, 3.4780161763207);
        glVertex2f(0.2810221599777, 3.3503832664403);
        glVertex2f(0.2414119465665, 3.2491571655006);
        glVertex2f(0.188598328685, 3.081914042209);
        glVertex2f(0.1445869804503, 2.9058686492705);
        glVertex2f(0.1137790366861, 2.8046425483309);
        glVertex2f(0.0537370270969, 2.4689041894516);
    glEnd();
    glPopMatrix();

    //gelombang2.1
    glPushMatrix();
    glColor3ub(120, 111, 102);
    glBegin(GL_POLYGON);
        glVertex2f(5.1259907182453, 3.1331779311995);
        glVertex2f(4.9567473601459, 2.8202461615901);
        glVertex2f(5.0206347266191, 2.9224659479471);
        glVertex2f(4.8724160364014, 2.7052489019384);
        glVertex2f(4.7983066912926, 2.6439170301242);
        glVertex2f(4.7267528408427, 2.5365862544494);
        glVertex2f(4.5989781078964, 2.4266999841156);
        glVertex2f(4.5299797521054, 2.2912587671925);
        glVertex2f(4.4507594176787, 2.1864834861766);
        glVertex2f(4.374094577911, 2.0970411731142);
        glVertex2f(4.2795412755307, 2.0178208386875);
        glVertex2f(4.1747659945148, 1.9462669882376);
        glVertex2f(4.064879724181, 1.8798241271055);
        glVertex2f(3.9575489485061, 1.8542691805163);
        glVertex2f(3.8690194258291, 1.8178100359076);
        glVertex2f(3.7808609209194, 1.787798629981);
        glVertex2f(3.6908267031394, 1.7596629369247);
        glVertex2f(3.5895382081369, 1.7484086597022);
        glVertex2f(3.5051311289681, 1.7390300953501);
        glVertex2f(3.415096911188, 1.7334029567388);
        glVertex2f(3.28942414887, 1.7427815210909);
        glVertex2f(3.2050170697012, 1.7634143626655);
        glVertex2f(3.1393671192366, 1.7802957784993);
        glVertex2f(3.0643386044199, 1.8065557586851);
        glVertex2f(2.9727840136691, 1.8462971209928);
        glVertex2f(2.8787634728229, 1.9168125266274);
        glVertex2f(2.8056363854982, 1.9742695238111);
        glVertex2f(2.7403443432439, 2.0317265209949);
        glVertex2f(2.6541588474683, 2.1596989238132);
        glVertex2f(2.5758083967632, 2.2589428280397);
        glVertex2f(2.4008257235218, 2.5279460421272);
        glVertex2f(2.3287687808607, 2.6292468409997);
        glVertex2f(2.2895732739477, 2.6829592023248);
        glVertex2f(2.2169890018867, 2.7613502161508);
        glVertex2f(2.1197260773249, 2.8440962863003);
        glVertex2f(2.0660137159997, 2.8949052767431);
        glVertex2f(1.9744685384962, 3.5684106342475);
        glVertex2f(4.7421153153178, 4.5058029810992);
        glVertex2f(4.7979939454576, 4.4592374559827);
    glEnd();
    glPopMatrix();

    //gelombang2.2
    glPushMatrix();
    glColor3ub(120, 111, 102);
    glBegin(GL_POLYGON);
        glVertex2f(2.0660137159997, 2.8949052767431);
        glVertex2f(2.0355667305675, 2.8893334325315);
        glVertex2f(2.0695393753836, 2.8044018204914);
        glVertex2f(2.0940751744174, 2.6873849327918);
        glVertex2f(2.1261604500769, 2.4873238022085);
        glVertex2f(2.1280478192334, 2.2985868865639);
        glVertex2f(2.1072867585125, 2.1268362933273);
        glVertex2f(2.0669875650295, 1.9664956863123);
        glVertex2f(2.0277560656591, 1.8578546111327);
        glVertex2f(2.0005957968642, 1.823149823228);
        glVertex2f(1.9673999127815, 1.7869361315015);
        glVertex2f(1.931186221055, 1.7522313435969);
        glVertex2f(1.8859191063968, 1.7220532671581);
        glVertex2f(1.8391430879167, 1.6948929983632);
        glVertex2f(1.7878403579708, 1.6813128639658);
        glVertex2f(1.7410643394906, 1.6782950563219);
        glVertex2f(1.6867438019008, 1.675277248678);
        glVertex2f(1.6158253222697, 1.6782950563219);
        glVertex2f(1.3396959228548, 1.7024375174729);
        glVertex2f(1.1830820700626, 1.7277417435043);
        glVertex2f(0.9973623742528, 1.7693685718755);
        glVertex2f(0.8420622837911, 1.8190005595488);
        glVertex2f(0.6147157596102, 1.9006531844307);
        glVertex2f(0.4337991593816, 1.9967150960565);
        glVertex2f(0.289706291943, 2.0783677209384);
        glVertex2f(0.0335411942743, 2.2640874167482);
        glVertex2f(0.0464540031948, 2.4062873723379);
        glVertex2f(0.0830774060369, 2.6040537476856);
        glVertex2f(0.138744978357, 2.8809266731724);
        glVertex2f(1.8867920012269, 3.2858141462174);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void fireball(){
    glPushMatrix();
    glTranslated(fireball_all_x[0],fireball_all_y[0],0);
    glScaled(0.4,0.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(240, 10, 10);
        glVertex2f(6.4634376685768, 4.7762096405723);
        glVertex2f(6.5243717815612, 4.8057534529284);
        glVertex2f(6.5705339883676, 4.83160428874);
        glVertex2f(6.6277751248075, 4.8519156597348);
        glVertex2f(6.6831697729752, 4.8703805424573);
        glVertex2f(6.7607222804099, 4.8869989369076);
        glVertex2f(6.8290423464834, 4.8943848899967);
        glVertex2f(6.8807440181066, 4.8943848899967);
        glVertex2f(6.9582965255413, 4.8999243548134);
        glVertex2f(7.021077126798, 4.8906919134521);
        glVertex2f(7.0801647515102, 4.8925384017244);
        glVertex2f(7.1540242824004, 4.8888454251799);
        glVertex2f(7.2094189305681, 4.8869989369076);
        glVertex2f(7.2574276256467, 4.8777664955464);
        glVertex2f(7.3146687620867, 4.8722270307296);
        glVertex2f(7.353445015804, 4.8629945893683);
        glVertex2f(7.4014537108827, 4.853762148007);
        glVertex2f(7.4346904997833, 4.8408367301012);
        glVertex2f(7.4605413355949, 4.8279113121955);
        glVertex2f(7.4919316362232, 4.8168323825619);
        glVertex2f(7.5140894954903, 4.7965210115671);
        glVertex2f(7.5436333078464, 4.7928280350226);
        glVertex2f(7.5953349794695, 4.7762096405723);
        glVertex2f(7.656269092454, 4.759591246122);
        glVertex2f(7.7338215998887, 4.7263544572214);
        glVertex2f(7.8021416659622, 4.680192250415);
        glVertex2f(7.8556898258576, 4.680192250415);
        glVertex2f(7.9480142394704, 4.665420344237);
        glVertex2f(8.0181807938161, 4.6469554615144);
        glVertex2f(8.0975797895231, 4.6266440905196);
        glVertex2f(8.1714393204133, 4.58602134853);
        glVertex2f(8.2231409920365, 4.5453986065403);
        glVertex2f(8.2436247702168, 4.5202005881592);
        glVertex2f(8.2701243898812, 4.5074415120245);
        glVertex2f(8.2877908029909, 4.4986083054697);
        glVertex2f(8.325086564, 4.4789789575701);
        glVertex2f(8.371215531564, 4.4632754792505);
        glVertex2f(8.4094927599682, 4.4524793379057);
        glVertex2f(8.4605290645071, 4.437757326981);
        glVertex2f(8.5007692277012, 4.4269611856363);
        glVertex2f(8.55573140182, 4.4102762399216);
        glVertex2f(8.6, 4.4);
        glVertex2f(8.6457337793313, 4.3877756455438);
        glVertex2f(8.6919192098964, 4.381854436497);
        glVertex2f(8.7262622223678, 4.368827776594);
        glVertex2f(8.779553103789, 4.3581696003098);
        glVertex2f(8.8233700507353, 4.352248391263);
        glVertex2f(8.8754766903471, 4.3404059731694);
        glVertex2f(8.9571893751929, 4.3202738624103);
        glVertex2f(9.0673238634633, 4.3072472025073);
        glVertex2f(9.1774583517338, 4.2918520589857);
        glVertex2f(9.4587305866192, 4.2807297245546);
        glVertex2f(9.5641646996472, 4.2628595359058);
        glVertex2f(9.6374324731072, 4.2494568944192);
        glVertex2f(9.6946170767834, 4.2378412717974);
        glVertex2f(9.7321444729459, 4.2253321397433);
        glVertex2f(9.7464406238649, 4.214610026554);
        glVertex2f(9.75, 4.2);
        glVertex2f(9.7375055295405, 4.192272290743);
        glVertex2f(9.7249963974863, 4.1860177247159);
        glVertex2f(9.6830014541617, 4.1788696492564);
        glVertex2f(9.6016920958096, 4.1752956115266);
        glVertex2f(9.5275308129171, 4.169934554932);
        glVertex2f(9.4515825111597, 4.169934554932);
        glVertex2f(9.3541899830238, 4.1735085926618);
        glVertex2f(9.2425013039688, 4.1609994606076);
        glVertex2f(9.1692335305087, 4.1663605172022);
        glVertex2f(9.076308549535, 4.1609994606076);
        glVertex2f(9.0119758703993, 4.1529578757156);
        glVertex2f(8.95, 4.15);
        glVertex2f(8.9065417573714, 4.1431292719588);
        glVertex2f(8.86959969805, 4.1357641505815);
        glVertex2f(8.8280436711758, 4.1310418748004);
        glVertex2f(8.7666540860207, 4.1197084129256);
        glVertex2f(8.7184868730529, 4.1093194062071);
        glVertex2f(8.649541646648, 4.0904303030824);
        glVertex2f(8.584374240868, 4.0734301102702);
        glVertex2f(8.54376266915, 4.0592632829268);
        glVertex2f(8.4993732768071, 4.0432075452708);
        glVertex2f(8.47859526337, 4.0328185385523);
        glVertex2f(8.4389281468083, 4.0148738905839);
        glVertex2f(8.3983165750903, 3.9903180565219);
        glVertex2f(8.352038272435, 3.95820658121);
        glVertex2f(8.3227601625918, 3.9317618368355);
        glVertex2f(8.2594816671243, 3.9119282785546);
        glVertex2f(8.1895919855631, 3.8939836305862);
        glVertex2f(8.1395358622828, 3.8845390790239);
        glVertex2f(8.0800351874402, 3.864705520743);
        glVertex2f(8.0101455058791, 3.8495942382433);
        glVertex2f(7.9544226516614, 3.8316495902749);
        glVertex2f(7.9080857655849, 3.8159624415127);
        glVertex2f(7.8583242638705, 3.7946360836351);
        glVertex2f(7.8192259410949, 3.7816033093766);
        glVertex2f(7.7884212019384, 3.7496137725602);
        glVertex2f(7.7528772721425, 3.7211786287234);
        glVertex2f(7.7, 3.7);
        glVertex2f(7.6616478523328, 3.6856346989275);
        glVertex2f(7.6024079693395, 3.6690475316893);
        glVertex2f(7.5230265261285, 3.6500907691315);
        glVertex2f(7.4554930595162, 3.6406123878526);
        glVertex2f(7.3998075695025, 3.6346883995532);
        glVertex2f(7.3026541613935, 3.6311340065736);
        glVertex2f(7.1960223720056, 3.627579613594);
        glVertex2f(7.0988689638967, 3.6263948159342);
        glVertex2f(6.9946067698285, 3.6477211738118);
        glVertex2f(6.9081165406583, 3.6571995550907);
        glVertex2f(6.8571702412841, 3.6785259129683);
        glVertex2f(6.8, 3.7);
        glVertex2f(6.7363208799778, 3.7211786287234);
        glVertex2f(6.6865593782634, 3.7342114029819);
        glVertex2f(6.6474610554879, 3.7448745819207);
        glVertex2f(6.6, 3.75);
        glVertex2f(6.55836383421, 3.7606213355901);
        glVertex2f(6.5061054650271, 3.7672724007589);
        glVertex2f(6.4538470958441, 3.7862754440981);
        glVertex2f(6.3920872049916, 3.8043283352704);
        glVertex2f(6.3350780749739, 3.8318827481123);
        glVertex2f(6.3, 3.85);
        glVertex2f(6.2666671189526, 3.8765398999595);
        glVertex2f(6.2372124017768, 3.9116955301372);
        glVertex2f(6.2115582932688, 3.9468511603148);
        glVertex2f(6.1897047934286, 3.9839070948263);
        glVertex2f(6.1726020544233, 4.0181125728369);
        glVertex2f(6.1592999240858, 4.0494675943467);
        glVertex2f(6.1488482502493, 4.0846232245243);
        glVertex2f(6.1374464242457, 4.1264299198706);
        glVertex2f(6.1285481030112, 4.1722211522442);
        glVertex2f(6.1233559895393, 4.2220654415741);
        glVertex2f(6.1233559895393, 4.2615255039602);
        glVertex2f(6.1285481030112, 4.308254525207);
        glVertex2f(6.1358170618718, 4.3508298556762);
        glVertex2f(6.1441244434268, 4.3965204542286);
        glVertex2f(6.166969742703, 4.4619410839741);
        glVertex2f(6.1960455781454, 4.5159390640814);
        glVertex2f(6.2271982589766, 4.5605912399394);
        glVertex2f(6.2521204036415, 4.6031665704087);
        glVertex2f(6.284311507167, 4.6384729420174);
        glVertex2f(6.3331173738025, 4.6810482724866);
        glVertex2f(6.3725774361887, 4.718431489484);
        glVertex2f(6.4317675297679, 4.7558147064815);
    glEnd();

    glColor3ub(235, 73, 61);
    glBegin(GL_POLYGON);
        glVertex2f(6.2345837659191, 4.3966645362263);
        glVertex2f(6.2399087231574, 4.4326079975847);
        glVertex2f(6.2519049619244, 4.4592478687571);
        glVertex2f(6.2621991249268, 4.4825451850256);
        glVertex2f(6.2730350859819, 4.5020499149248);
        glVertex2f(6.286038239248, 4.521554644824);
        glVertex2f(6.2979577964086, 4.5399757786177);
        glVertex2f(6.312586343833, 4.5556879221476);
        glVertex2f(6.3245059009936, 4.5730254598358);
        glVertex2f(6.3407598425763, 4.5909047955767);
        glVertex2f(6.3624317646865, 4.6131185157397);
        glVertex2f(6.3819364945857, 4.6342486397971);
        glVertex2f(6.4211261010826, 4.6686628765816);
        glVertex2f(6.4478140223845, 4.6901433986051);
        glVertex2f(6.4849167422432, 4.720085944456);
        glVertex2f(6.5233213119216, 4.7435192412089);
        glVertex2f(6.5643295812391, 4.766301613052);
        glVertex2f(6.6020832260077, 4.785829360346);
        glVertex2f(6.65, 4.8);
        glVertex2f(6.6958164130192, 4.8092626570989);
        glVertex2f(6.7403890573123, 4.8114280613032);
        glVertex2f(6.7651384825053, 4.8158910724036);
        glVertex2f(6.7854248965979, 4.8231941814769);
        glVertex2f(6.8268091813468, 4.8414519541603);
        glVertex2f(6.8450669540301, 4.8515951612065);
        glVertex2f(6.8637304549953, 4.8515951612065);
        glVertex2f(6.8933486195705, 4.850377976361);
        glVertex2f(6.9262126104005, 4.8491607915154);
        glVertex2f(6.9546135901301, 4.8459149652606);
        glVertex2f(6.9866661243964, 4.8353660299325);
        glVertex2f(7.0221394394512, 4.8269970969557);
        glVertex2f(7.0507630213981, 4.8168403420713);
        glVertex2f(7.0830799687575, 4.8020668804213);
        glVertex2f(7.13109371912, 4.7891401014775);
        glVertex2f(7.1791074694826, 4.7872934187713);
        glVertex2f(7.2154926307847, 4.7840559851689);
        glVertex2f(7.255065965071, 4.7889016995713);
        glVertex2f(7.2954469184244, 4.7929397949067);
        glVertex2f(7.3245212048388, 4.7856712233031);
        glVertex2f(7.3697478725945, 4.7695188419617);
        glVertex2f(7.4077059687467, 4.7525588415533);
        glVertex2f(7.4400107314293, 4.7323683648767);
        glVertex2f(7.4739307322462, 4.7146007454012);
        glVertex2f(7.5030050186606, 4.6927950305904);
        glVertex2f(7.5401554957457, 4.6742197920478);
        glVertex2f(7.5797288300319, 4.6411074102981);
        glVertex2f(7.6104183545805, 4.6241474098897);
        glVertex2f(7.6346469265925, 4.6104178857495);
        glVertex2f(7.7024869282261, 4.5886121709387);
        glVertex2f(7.7598628842032, 4.5697902714593);
        glVertex2f(7.8292530283309, 4.5573991742936);
        glVertex2f(7.8720023135524, 4.5443885222696);
        glVertex2f(7.9141320439157, 4.5338560896788);
        glVertex2f(7.9599791034287, 4.51898677308);
        glVertex2f(7.9915764012011, 4.5090738953475);
        glVertex2f(8.0361843509975, 4.4911068044573);
        glVertex2f(8.0814118556522, 4.4681832747008);
        glVertex2f(8.1099113791332, 4.4526944032437);
        glVertex2f(8.137791347756, 4.4260535443375);
        glVertex2f(8.1658490199979, 4.3884686034595);
        glVertex2f(8.2084623604124, 4.3575530427666);
        glVertex2f(8.2385423654108, 4.3433485959618);
        glVertex2f(8.2936890412413, 4.324966370685);
        glVertex2f(8.3663823866542, 4.3141041466577);
        glVertex2f(8.4290490637343, 4.3082552567969);
        glVertex2f(8.5, 4.3);
        glVertex2f(8.55, 4.3);
        glVertex2f(8.6103646494194, 4.2940508099921);
        glVertex2f(8.6571557683059, 4.2856952530481);
        glVertex2f(8.7039468871924, 4.2748330290209);
        glVertex2f(8.7423824491349, 4.256450803744);
        glVertex2f(8.7674491199669, 4.239739689856);
        glVertex2f(8.7674491199669, 4.2238641316624);
        glVertex2f(8.7565868959397, 4.2130019076352);
        glVertex2f(8.7290135580244, 4.2088241291632);
        glVertex2f(8.6830579948324, 4.210495240552);
        glVertex2f(8.6488002113619, 4.2121663519408);
        glVertex2f(8.5978313140034, 4.2221930202736);
        glVertex2f(8.5451913052561, 4.218850797496);
        glVertex2f(8.4984001863697, 4.2096596848576);
        glVertex2f(8.461635735816, 4.1962907937471);
        glVertex2f(8.4206935067903, 4.1779085684703);
        glVertex2f(8.3889423904031, 4.1578552318047);
        glVertex2f(8.3730668322095, 4.133624116667);
        glVertex2f(8.3329601588782, 4.1152418913902);
        glVertex2f(8.2886757070749, 4.0926818876414);
        glVertex2f(8.2417553680689, 4.0791420173743);
        glVertex2f(8.1771054853547, 4.0584052625415);
        glVertex2f(8.1100159844249, 4.0388883168165);
        glVertex2f(8.0465859108186, 4.0205911801992);
        glVertex2f(8, 4);
        glVertex2f(7.9282644273606, 3.982777097857);
        glVertex2f(7.8562956899996, 3.9559412974851);
        glVertex2f(7.7916458072854, 3.930325306221);
        glVertex2f(7.7355345883259, 3.9034895058491);
        glVertex2f(7.6830827966899, 3.8729942781537);
        glVertex2f(7.6416092870242, 3.851037714213);
        glVertex2f(7.617213104868, 3.8242019138411);
        glVertex2f(7.6, 3.8);
        glVertex2f(7.5672009314476, 3.7961463043614);
        glVertex2f(7.5281670399975, 3.7912670679301);
        glVertex2f(7.4671765846068, 3.7863878314989);
        glVertex2f(7.4318021204802, 3.7741897404207);
        glVertex2f(7.4086257474317, 3.746134130941);
        glVertex2f(7.4049663201083, 3.7180785214613);
        glVertex2f(7.4, 3.7);
        glVertex2f(7.3732512833051, 3.7010011939519);
        glVertex2f(7.3403164373941, 3.6985615757363);
        glVertex2f(7.2683477000331, 3.6900229119816);
        glVertex2f(7.1988185808877, 3.6863634846581);
        glVertex2f(7.1170913706641, 3.6851436755503);
        glVertex2f(7.0609801517046, 3.6888031028737);
        glVertex2f(6.9821268954708, 3.6963403985768);
        glVertex2f(6.9239029382566, 3.7010933746759);
        glVertex2f(6.8526082967698, 3.7129758149237);
        glVertex2f(6.7896313634565, 3.727234743221);
        glVertex2f(6.7230896980689, 3.7486231356671);
        glVertex2f(6.6791246691521, 3.7605055759149);
        glVertex2f(6.6351596402352, 3.7747645042122);
        glVertex2f(6.592839493773, 3.7937924768567);
        glVertex2f(6.5344461666351, 3.8127086250844);
        glVertex2f(6.4785201631792, 3.8390267443578);
        glVertex2f(6.4398654254964, 3.8513633627672);
        glVertex2f(6.399565805359, 3.8743917171314);
        glVertex2f(6.35, 3.9);
        glVertex2f(6.3025177405384, 3.9294952793601);
        glVertex2f(6.2729098563559, 3.9500563100424);
        glVertex2f(6.250348218262, 3.9724532780191);
        glVertex2f(6.2291375756217, 3.9966940124652);
        glVertex2f(6.2147446395443, 4.0277524534743);
        glVertex2f(6.2003517034669, 4.0656286010463);
        glVertex2f(6.1859587673896, 4.1133525469871);
        glVertex2f(6.1806561067295, 4.164864107685);
        glVertex2f(6.1768684919723, 4.2201632831402);
        glVertex2f(6.1852012444381, 4.2762199815468);
        glVertex2f(6.2003593753743, 4.330698103064);
        glVertex2f(6.227394257272, 4.3759295400851);
    glEnd();

    glColor3ub(255, 251, 5);
    glBegin(GL_POLYGON);
        glVertex2f(6.3246158517887, 4.2703895203691);
        glVertex2f(6.3204566391891, 4.2885860754926);
        glVertex2f(6.3168173281644, 4.3130214495155);
        glVertex2f(6.3157775250145, 4.3312180046389);
        glVertex2f(6.3168173281644, 4.3514941660622);
        glVertex2f(6.3308546706882, 4.3738499337853);
        glVertex2f(6.3516507336864, 4.389446981034);
        glVertex2f(6.3589293557358, 4.4071236345824);
        glVertex2f(6.3511308321114, 4.4258400912808);
        glVertex2f(6.3401993701067, 4.4391666712231);
        glVertex2f(6.3408312992751, 4.4549649004313);
        glVertex2f(6.3490463784633, 4.4770824213228);
        glVertex2f(6.3661741077888, 4.4845739915898);
        glVertex2f(6.3781838050211, 4.4910077579642);
        glVertex2f(6.3773259695045, 4.5047331262296);
        glVertex2f(6.3713211208884, 4.515456070187);
        glVertex2f(6.3773259695045, 4.5248922608694);
        glVertex2f(6.3949115975945, 4.5334706160353);
        glVertex2f(6.411639390168, 4.5420489712012);
        glVertex2f(6.4296539360163, 4.5493405730922);
        glVertex2f(6.4390901266987, 4.5557743394666);
        glVertex2f(6.4360877023907, 4.5690707899737);
        glVertex2f(6.44, 4.58);
        glVertex2f(6.4553890015139, 4.5909455956466);
        glVertex2f(6.4725457118456, 4.5999528685708);
        glVertex2f(6.4918470109688, 4.6033842106371);
        glVertex2f(6.4944205175186, 4.6213987564855);
        glVertex2f(6.4957072707935, 4.636839795784);
        glVertex2f(6.5041959424018, 4.6514331472041);
        glVertex2f(6.5164447151321, 4.6598805766733);
        glVertex2f(6.5333395740704, 4.6738188352974);
        glVertex2f(6.552346290376, 4.6784649215054);
        glVertex2f(6.5692411493142, 4.68268863624);
        glVertex2f(6.5802228076241, 4.6898689512887);
        glVertex2f(6.5734648640488, 4.7012729810721);
        glVertex2f(6.5730424925754, 4.7118322679085);
        glVertex2f(6.5924715803544, 4.7164783541166);
        glVertex2f(6.6233046979168, 4.7143664967493);
        glVertex2f(6.6401995568551, 4.7118322679085);
        glVertex2f(6.6613181305279, 4.7257705265326);
        glVertex2f(6.6946854769311, 4.7308389842141);
        glVertex2f(6.7115803358694, 4.7240810406388);
        glVertex2f(6.7234067371262, 4.7177454685369);
        glVertex2f(6.7322765380688, 4.7118322679085);
        glVertex2f(6.7588859408966, 4.7135217538024);
        glVertex2f(6.7960546305608, 4.7152112396962);
        glVertex2f(6.8125271180257, 4.7130993823289);
        glVertex2f(6.8311114628578, 4.7118322679085);
        glVertex2f(6.8701785450094, 4.7031810466801);
        glVertex2f(6.897948166545, 4.6886019953739);
        glVertex2f(6.9125272178512, 4.68165958999);
        glVertex2f(6.929883231311, 4.7004040845265);
        glVertex2f(6.95, 4.7);
        glVertex2f(6.9632067771537, 4.6969328818346);
        glVertex2f(6.97778582846, 4.6858250332203);
        glVertex2f(6.9916706392278, 4.6823538305283);
        glVertex2f(7.0090266526876, 4.6761056656828);
        glVertex2f(7.0263826661473, 4.662220854915);
        glVertex2f(7.05, 4.65);
        glVertex2f(7.079144947065, 4.6344512333794);
        glVertex2f(7.1083030496775, 4.6108470550741);
        glVertex2f(7.1388496333667, 4.5990449659214);
        glVertex2f(7.1638422927487, 4.5844659146152);
        glVertex2f(7.1853637494389, 4.5796062308465);
        glVertex2f(7.2041082439754, 4.5789119903081);
        glVertex2f(7.2270181817423, 4.5865486362304);
        glVertex2f(7.25, 4.6);
        glVertex2f(7.2652014113538, 4.5990449659214);
        glVertex2f(7.2860286275056, 4.5962680037679);
        glVertex2f(7.3169201734456, 4.5900327560501);
        glVertex2f(7.34, 4.58);
        glVertex2f(7.3664885537148, 4.5700455059416);
        glVertex2f(7.3712854937408, 4.5624503509003);
        glVertex2f(7.3696865137321, 4.5544554508569);
        glVertex2f(7.3564949286605, 4.552456725846);
        glVertex2f(7.3353084435455, 4.5508577458374);
        glVertex2f(7.3121232334196, 4.5484592758243);
        glVertex2f(7.2969329233371, 4.5460608058113);
        glVertex2f(7.28, 4.54);
        glVertex2f(7.2665523031721, 4.5316699857332);
        glVertex2f(7.2501627580831, 4.528871770718);
        glVertex2f(7.2349724480006, 4.5296712607223);
        glVertex2f(7.224179332942, 4.531270240731);
        glVertex2f(7.2157846878964, 4.531270240731);
        glVertex2f(7.2045918278356, 4.5224758506832);
        glVertex2f(7.191400242764, 4.5112829906225);
        glVertex2f(7.18, 4.5);
        glVertex2f(7.1746109526728, 4.4932944655248);
        glVertex2f(7.1778089126902, 4.4837005854727);
        glVertex2f(7.1830055977184, 4.4765051754336);
        glVertex2f(7.1945982027814, 4.4669112953815);
        glVertex2f(7.2025931028248, 4.4537197103099);
        glVertex2f(7.2129864728812, 4.4421271052469);
        glVertex2f(7.2173836679051, 4.4313339901883);
        glVertex2f(7.2289762729681, 4.421340365134);
        glVertex2f(7.2565586781178, 4.4153441901015);
        glVertex2f(7.2833415932633, 4.4097477600711);
        glVertex2f(7.2993313933501, 4.4053505650472);
        glVertex2f(7.3169201734456, 4.3961564299973);
        glVertex2f(7.3383230244607, 4.3830916415287);
        glVertex2f(7.3518817578228, 4.3708450436533);
        glVertex2f(7.3706890331316, 4.3568489317956);
        glVertex2f(7.3755001965827, 4.347663983389);
        glVertex2f(7.4008681493247, 4.3454770909112);
        glVertex2f(7.4244865880846, 4.3459144694068);
        glVertex2f(7.4502919193222, 4.3371668994957);
        glVertex2f(7.4717234656043, 4.3275445725936);
        glVertex2f(7.5080258807351, 4.3122363252492);
        glVertex2f(7.5255210205573, 4.3043635123293);
        glVertex2f(7.5543880012637, 4.2934290499404);
        glVertex2f(7.5631355711748, 4.2838067230383);
        glVertex2f(7.5561375152459, 4.2728722606495);
        glVertex2f(7.5307695625039, 4.269373232685);
        glVertex2f(7.5089006377263, 4.2615004197651);
        glVertex2f(7.4791589000287, 4.2461921724207);
        glVertex2f(7.4629758956932, 4.2387567379964);
        glVertex2f(7.4411069709156, 4.2356950885275);
        glVertex2f(7.407428826758, 4.2339455745453);
        glVertex2f(7.3789992245471, 4.231321303572);
        glVertex2f(7.3483827298584, 4.2326334390586);
        glVertex2f(7.3142672072053, 4.2317586820675);
        glVertex2f(7.2915235254366, 4.231321303572);
        glVertex2f(7.2744612785151, 4.2257932675683);
        glVertex2f(7.2605520937304, 4.2145589260114);
        glVertex2f(7.25, 4.2);
        glVertex2f(7.2354085673889, 4.1851356505053);
        glVertex2f(7.2380834106167, 4.1771111208219);
        glVertex2f(7.2589471877937, 4.162131998746);
        glVertex2f(7.3317029235906, 4.1300338800121);
        glVertex2f(7.3563114812866, 4.1193345071008);
        glVertex2f(7.3777102271092, 4.1198694757464);
        glVertex2f(7.4039236907419, 4.1252191622021);
        glVertex2f(7.4396547597232, 4.1186912754292);
        glVertex2f(7.4788220803602, 4.1085367848937);
        glVertex2f(7.5375730613158, 4.095481011348);
        glVertex2f(7.5890708347459, 4.0773479925346);
        glVertex2f(7.6101051365695, 4.0693694642566);
        glVertex2f(7.6101051365695, 4.0555883699584);
        glVertex2f(7.6, 4.05);
        glVertex2f(7.5856993709643, 4.054009775704);
        glVertex2f(7.5510520267825, 4.0623729277478);
        glVertex2f(7.5032625865317, 4.0653597677635);
        glVertex2f(7.4614468263123, 4.0695413437855);
        glVertex2f(7.4190336980897, 4.0725281838011);
        glVertex2f(7.3879705619267, 4.0653597677635);
        glVertex2f(7.376023201864, 4.0581913517259);
        glVertex2f(7.371244257839, 4.0420624156413);
        glVertex2f(7.3539205857481, 4.0331018955942);
        glVertex2f(7.3061311454973, 4.0295176875754);
        glVertex2f(7.2553548652309, 4.0336992635974);
        glVertex2f(7.2278759370867, 4.0360887356099);
        glVertex2f(7.2111496329989, 4.031907159588);
        glVertex2f(7.2111496329989, 4.0217519035347);
        glVertex2f(7.2057733209707, 4.0068177034563);
        glVertex2f(7.1932285929049, 4.0068177034563);
        glVertex2f(7.1669444007669, 4.0038308634407);
        glVertex2f(7.15, 4);
        glVertex2f(7.131699688582, 3.9978571834093);
        glVertex2f(7.1203496965224, 3.9912861353748);
        glVertex2f(7.1239339045412, 3.9823256153278);
        glVertex2f(7.1424523126384, 3.9775466713027);
        glVertex2f(7.1633601927481, 3.9727677272777);
        glVertex2f(7.1890470168829, 3.96559931124);
        glVertex2f(7.2153312090208, 3.9626124712244);
        glVertex2f(7.25, 3.95);
        glVertex2f(7.2756653773374, 3.9470809031429);
        glVertex2f(7.3037416734848, 3.9357309110833);
        glVertex2f(7.309117985513, 3.9267703910363);
        glVertex2f(7.3019495694753, 3.9148230309736);
        glVertex2f(7.2876127374001, 3.9142256629705);
        glVertex2f(7.2631206492716, 3.9130309269642);
        glVertex2f(7.220707521049, 3.9136282949673);
        glVertex2f(7.1651522967575, 3.9136282949673);
        glVertex2f(7.1251286405475, 3.9142256629705);
        glVertex2f(7.0935938557144, 3.9119864227739);
        glVertex2f(7.0684696116599, 3.8973981520326);
        glVertex2f(7.0465872055479, 3.8892935571763);
        glVertex2f(7.0058209206595, 3.8732541341467);
        glVertex2f(6.9839114800356, 3.8690809073612);
        glVertex2f(6.9620020394117, 3.8774273609322);
        glVertex2f(6.9233996916459, 3.8857738145032);
        glVertex2f(6.8837540371836, 3.8878604278959);
        glVertex2f(6.8461949961141, 3.8857738145032);
        glVertex2f(6.8190690220083, 3.882643894414);
        glVertex2f(6.7794233675461, 3.8701242140575);
        glVertex2f(6.7575139269222, 3.8555179203083);
        glVertex2f(6.71786827246, 3.8596911470938);
        glVertex2f(6.680190054244, 3.8656986811799);
        glVertex2f(6.6325397453533, 3.8820562499036);
        glVertex2f(6.5834670391823, 3.9026810104682);
        glVertex2f(6.5215927574884, 3.9297065587943);
        glVertex2f(6.4789208390789, 3.9503313193589);
        glVertex2f(6.434826523389, 3.9802016622456);
        glVertex2f(6.400715360075, 4.0065775598724);
        glVertex2f(6.3661856674174, 4.0322740753384);
        glVertex2f(6.342095184168, 4.064394719671);
        glVertex2f(6.3388831197347, 4.1037425089785);
        glVertex2f(6.3356710553014, 4.1679837976437);
        glVertex2f(6.3308529586515, 4.2201798446842);
        glVertex2f(6.3292469264349, 4.2547095373417);
    glEnd();

    glColor3ub(255, 209, 125);
    glBegin(GL_POLYGON);
        glVertex2f(6.4753201016554, 4.5434306602696);
        glVertex2f(6.5076025361996, 4.5709305119184);
        glVertex2f(6.5362980335723, 4.5948434263956);
        glVertex2f(6.5550175006339, 4.6066503169608);
        glVertex2f(6.5690282804732, 4.6144963536708);
        glVertex2f(6.5858412162805, 4.6262654087359);
        glVertex2f(6.6004124273134, 4.6307488582845);
        glVertex2f(6.6144232071528, 4.6363531702203);
        glVertex2f(6.6402030420573, 4.645880500511);
        glVertex2f(6.668224601736, 4.6520452436404);
        glVertex2f(6.6923231430597, 4.6554078308018);
        glVertex2f(6.7153008219963, 4.6559682619954);
        glVertex2f(6.7309928954164, 4.6559682619954);
        glVertex2f(6.7517288495787, 4.656528693189);
        glVertex2f(6.7663000606116, 4.6554078308018);
        glVertex2f(6.7797504092574, 4.6537265372211);
        glVertex2f(6.8, 4.65);
        glVertex2f(6.8184201616141, 4.6470013628982);
        glVertex2f(6.8346726662278, 4.6447596381239);
        glVertex2f(6.8498043084543, 4.6402761885753);
        glVertex2f(6.8666172442616, 4.6363531702203);
        glVertex2f(6.8828697488752, 4.6301884270909);
        glVertex2f(6.8985618222953, 4.6217819591873);
        glVertex2f(6.9176164828769, 4.611694197703);
        glVertex2f(6.9338689874906, 4.6027272986058);
        glVertex2f(6.951802785685, 4.58927694996);
        glVertex2f(6.9652531343308, 4.5814309132499);
        glVertex2f(6.974220033428, 4.5741453077334);
        glVertex2f(6.9837473637187, 4.5651784086362);
        glVertex2f(7, 4.55);
        glVertex2f(7.0112084922039, 4.5382777113446);
        glVertex2f(7.0207358224947, 4.5231460691181);
        glVertex2f(7.0381091894955, 4.5029705461494);
        glVertex2f(7.0487573821734, 4.4878389039229);
        glVertex2f(7.0622077308192, 4.4699051057285);
        glVertex2f(7.0669642419219, 4.458312095008);
        glVertex2f(7.0728426383963, 4.4461879022794);
        glVertex2f(7.0772514357522, 4.4377377073474);
        glVertex2f(7.0801906339894, 4.4252461148391);
        glVertex2f(7.0849668311249, 4.4120197227716);
        glVertex2f(7.0897430282604, 4.398793330704);
        glVertex2f(7.0937844258366, 4.3789537426027);
        glVertex2f(7.1, 4.36);
        glVertex2f(7.1033368201076, 4.3381723670611);
        glVertex2f(7.1040716196669, 4.3142913813836);
        glVertex2f(7.1037042198873, 4.2992279904178);
        glVertex2f(7.1033368201076, 4.2790210025368);
        glVertex2f(7.1033368201076, 4.2595488142151);
        glVertex2f(7.0999284399254, 4.2313729254375);
        glVertex2f(7.0948346260788, 4.2124530454358);
        glVertex2f(7.0919238753093, 4.1906224146647);
        glVertex2f(7.0824639353084, 4.1709748469706);
        glVertex2f(7.073731683, 4.1505995915842);
        glVertex2f(7.0635440553068, 4.1214920838893);
        glVertex2f(7.05, 4.1);
        glVertex2f(7.0344365476118, 4.0785585100393);
        glVertex2f(7.019155106072, 4.0567278792681);
        glVertex2f(6.9973244753008, 4.0327141854198);
        glVertex2f(6.9718554060678, 4.0094281792639);
        glVertex2f(6.94493096145, 3.9934190500317);
        glVertex2f(6.9121850152932, 3.9730437946452);
        glVertex2f(6.8816221322136, 3.957034665413);
        glVertex2f(6.8510592491339, 3.9424809115656);
        glVertex2f(6.8117641137458, 3.9352040346419);
        glVertex2f(6.7790181675891, 3.93156559618);
        glVertex2f(6.7513660352789, 3.9301102207952);
        glVertex2f(6.7186200891221, 3.9293825331029);
        glVertex2f(6.6997002091204, 3.93156559618);
        glVertex2f(6.6660989262452, 3.934148385664);
        glVertex2f(6.640563287455, 3.9421738721409);
        glVertex2f(6.6157572383445, 3.9487401792584);
        glVertex2f(6.5916807789137, 3.9611432038137);
        glVertex2f(6.5683339091627, 3.97062786965);
        glVertex2f(6.5427982703725, 3.9866788426039);
        glVertex2f(6.5172626315823, 4.0041889949171);
        glVertex2f(6.499752479269, 4.0216991472304);
        glVertex2f(6.4785943785571, 4.038479709864);
        glVertex2f(6.4567066881655, 4.0589082208961);
        glVertex2f(6.4406557152117, 4.0829846803269);
        glVertex2f(6.426793511297, 4.1041427810388);
        glVertex2f(6.4180384351404, 4.1274896507898);
        glVertex2f(6.4070945899446, 4.1493773411814);
        glVertex2f(6.3939619757096, 4.1792905180499);
        glVertex2f(6.3881252582719, 4.2048261568401);
        glVertex2f(6.3822885408341, 4.2296322059506);
        glVertex2f(6.3793701821152, 4.2595453828191);
        glVertex2f(6.3779110027558, 4.2872697906485);
        glVertex2f(6.3771814130761, 4.3106166603995);
        glVertex2f(6.3793701821152, 4.3361522991897);
        glVertex2f(6.3807879173079, 4.3583142917039);
        glVertex2f(6.3870756674499, 4.3787494796655);
        glVertex2f(6.3912675008779, 4.3970887509131);
        glVertex2f(6.3959833134844, 4.4169999596962);
        glVertex2f(6.405938917876, 4.4342912725868);
        glVertex2f(6.4169424806245, 4.4536785021913);
        glVertex2f(6.4268980850161, 4.4714937942604);
        glVertex2f(6.4368536894076, 4.492976940579);
        glVertex2f(6.4489052105132, 4.5128881493621);
        glVertex2f(6.4583368357262, 4.5280835455387);
    glEnd();
    glPopMatrix();
}

void fireball_status(){
    glPushMatrix();
    glTranslated(9.5,8,0);
    glScaled(0.2,0.2,0);
    glRotated(90,0,0,1);
    glBegin(GL_POLYGON);
    glColor3ub(240, 10, 10);
        glVertex2f(6.4634376685768, 4.7762096405723);
        glVertex2f(6.5243717815612, 4.8057534529284);
        glVertex2f(6.5705339883676, 4.83160428874);
        glVertex2f(6.6277751248075, 4.8519156597348);
        glVertex2f(6.6831697729752, 4.8703805424573);
        glVertex2f(6.7607222804099, 4.8869989369076);
        glVertex2f(6.8290423464834, 4.8943848899967);
        glVertex2f(6.8807440181066, 4.8943848899967);
        glVertex2f(6.9582965255413, 4.8999243548134);
        glVertex2f(7.021077126798, 4.8906919134521);
        glVertex2f(7.0801647515102, 4.8925384017244);
        glVertex2f(7.1540242824004, 4.8888454251799);
        glVertex2f(7.2094189305681, 4.8869989369076);
        glVertex2f(7.2574276256467, 4.8777664955464);
        glVertex2f(7.3146687620867, 4.8722270307296);
        glVertex2f(7.353445015804, 4.8629945893683);
        glVertex2f(7.4014537108827, 4.853762148007);
        glVertex2f(7.4346904997833, 4.8408367301012);
        glVertex2f(7.4605413355949, 4.8279113121955);
        glVertex2f(7.4919316362232, 4.8168323825619);
        glVertex2f(7.5140894954903, 4.7965210115671);
        glVertex2f(7.5436333078464, 4.7928280350226);
        glVertex2f(7.5953349794695, 4.7762096405723);
        glVertex2f(7.656269092454, 4.759591246122);
        glVertex2f(7.7338215998887, 4.7263544572214);
        glVertex2f(7.8021416659622, 4.680192250415);
        glVertex2f(7.8556898258576, 4.680192250415);
        glVertex2f(7.9480142394704, 4.665420344237);
        glVertex2f(8.0181807938161, 4.6469554615144);
        glVertex2f(8.0975797895231, 4.6266440905196);
        glVertex2f(8.1714393204133, 4.58602134853);
        glVertex2f(8.2231409920365, 4.5453986065403);
        glVertex2f(8.2436247702168, 4.5202005881592);
        glVertex2f(8.2701243898812, 4.5074415120245);
        glVertex2f(8.2877908029909, 4.4986083054697);
        glVertex2f(8.325086564, 4.4789789575701);
        glVertex2f(8.371215531564, 4.4632754792505);
        glVertex2f(8.4094927599682, 4.4524793379057);
        glVertex2f(8.4605290645071, 4.437757326981);
        glVertex2f(8.5007692277012, 4.4269611856363);
        glVertex2f(8.55573140182, 4.4102762399216);
        glVertex2f(8.6, 4.4);
        glVertex2f(8.6457337793313, 4.3877756455438);
        glVertex2f(8.6919192098964, 4.381854436497);
        glVertex2f(8.7262622223678, 4.368827776594);
        glVertex2f(8.779553103789, 4.3581696003098);
        glVertex2f(8.8233700507353, 4.352248391263);
        glVertex2f(8.8754766903471, 4.3404059731694);
        glVertex2f(8.9571893751929, 4.3202738624103);
        glVertex2f(9.0673238634633, 4.3072472025073);
        glVertex2f(9.1774583517338, 4.2918520589857);
        glVertex2f(9.4587305866192, 4.2807297245546);
        glVertex2f(9.5641646996472, 4.2628595359058);
        glVertex2f(9.6374324731072, 4.2494568944192);
        glVertex2f(9.6946170767834, 4.2378412717974);
        glVertex2f(9.7321444729459, 4.2253321397433);
        glVertex2f(9.7464406238649, 4.214610026554);
        glVertex2f(9.75, 4.2);
        glVertex2f(9.7375055295405, 4.192272290743);
        glVertex2f(9.7249963974863, 4.1860177247159);
        glVertex2f(9.6830014541617, 4.1788696492564);
        glVertex2f(9.6016920958096, 4.1752956115266);
        glVertex2f(9.5275308129171, 4.169934554932);
        glVertex2f(9.4515825111597, 4.169934554932);
        glVertex2f(9.3541899830238, 4.1735085926618);
        glVertex2f(9.2425013039688, 4.1609994606076);
        glVertex2f(9.1692335305087, 4.1663605172022);
        glVertex2f(9.076308549535, 4.1609994606076);
        glVertex2f(9.0119758703993, 4.1529578757156);
        glVertex2f(8.95, 4.15);
        glVertex2f(8.9065417573714, 4.1431292719588);
        glVertex2f(8.86959969805, 4.1357641505815);
        glVertex2f(8.8280436711758, 4.1310418748004);
        glVertex2f(8.7666540860207, 4.1197084129256);
        glVertex2f(8.7184868730529, 4.1093194062071);
        glVertex2f(8.649541646648, 4.0904303030824);
        glVertex2f(8.584374240868, 4.0734301102702);
        glVertex2f(8.54376266915, 4.0592632829268);
        glVertex2f(8.4993732768071, 4.0432075452708);
        glVertex2f(8.47859526337, 4.0328185385523);
        glVertex2f(8.4389281468083, 4.0148738905839);
        glVertex2f(8.3983165750903, 3.9903180565219);
        glVertex2f(8.352038272435, 3.95820658121);
        glVertex2f(8.3227601625918, 3.9317618368355);
        glVertex2f(8.2594816671243, 3.9119282785546);
        glVertex2f(8.1895919855631, 3.8939836305862);
        glVertex2f(8.1395358622828, 3.8845390790239);
        glVertex2f(8.0800351874402, 3.864705520743);
        glVertex2f(8.0101455058791, 3.8495942382433);
        glVertex2f(7.9544226516614, 3.8316495902749);
        glVertex2f(7.9080857655849, 3.8159624415127);
        glVertex2f(7.8583242638705, 3.7946360836351);
        glVertex2f(7.8192259410949, 3.7816033093766);
        glVertex2f(7.7884212019384, 3.7496137725602);
        glVertex2f(7.7528772721425, 3.7211786287234);
        glVertex2f(7.7, 3.7);
        glVertex2f(7.6616478523328, 3.6856346989275);
        glVertex2f(7.6024079693395, 3.6690475316893);
        glVertex2f(7.5230265261285, 3.6500907691315);
        glVertex2f(7.4554930595162, 3.6406123878526);
        glVertex2f(7.3998075695025, 3.6346883995532);
        glVertex2f(7.3026541613935, 3.6311340065736);
        glVertex2f(7.1960223720056, 3.627579613594);
        glVertex2f(7.0988689638967, 3.6263948159342);
        glVertex2f(6.9946067698285, 3.6477211738118);
        glVertex2f(6.9081165406583, 3.6571995550907);
        glVertex2f(6.8571702412841, 3.6785259129683);
        glVertex2f(6.8, 3.7);
        glVertex2f(6.7363208799778, 3.7211786287234);
        glVertex2f(6.6865593782634, 3.7342114029819);
        glVertex2f(6.6474610554879, 3.7448745819207);
        glVertex2f(6.6, 3.75);
        glVertex2f(6.55836383421, 3.7606213355901);
        glVertex2f(6.5061054650271, 3.7672724007589);
        glVertex2f(6.4538470958441, 3.7862754440981);
        glVertex2f(6.3920872049916, 3.8043283352704);
        glVertex2f(6.3350780749739, 3.8318827481123);
        glVertex2f(6.3, 3.85);
        glVertex2f(6.2666671189526, 3.8765398999595);
        glVertex2f(6.2372124017768, 3.9116955301372);
        glVertex2f(6.2115582932688, 3.9468511603148);
        glVertex2f(6.1897047934286, 3.9839070948263);
        glVertex2f(6.1726020544233, 4.0181125728369);
        glVertex2f(6.1592999240858, 4.0494675943467);
        glVertex2f(6.1488482502493, 4.0846232245243);
        glVertex2f(6.1374464242457, 4.1264299198706);
        glVertex2f(6.1285481030112, 4.1722211522442);
        glVertex2f(6.1233559895393, 4.2220654415741);
        glVertex2f(6.1233559895393, 4.2615255039602);
        glVertex2f(6.1285481030112, 4.308254525207);
        glVertex2f(6.1358170618718, 4.3508298556762);
        glVertex2f(6.1441244434268, 4.3965204542286);
        glVertex2f(6.166969742703, 4.4619410839741);
        glVertex2f(6.1960455781454, 4.5159390640814);
        glVertex2f(6.2271982589766, 4.5605912399394);
        glVertex2f(6.2521204036415, 4.6031665704087);
        glVertex2f(6.284311507167, 4.6384729420174);
        glVertex2f(6.3331173738025, 4.6810482724866);
        glVertex2f(6.3725774361887, 4.718431489484);
        glVertex2f(6.4317675297679, 4.7558147064815);
    glEnd();

    glColor3ub(235, 73, 61);
    glBegin(GL_POLYGON);
        glVertex2f(6.2345837659191, 4.3966645362263);
        glVertex2f(6.2399087231574, 4.4326079975847);
        glVertex2f(6.2519049619244, 4.4592478687571);
        glVertex2f(6.2621991249268, 4.4825451850256);
        glVertex2f(6.2730350859819, 4.5020499149248);
        glVertex2f(6.286038239248, 4.521554644824);
        glVertex2f(6.2979577964086, 4.5399757786177);
        glVertex2f(6.312586343833, 4.5556879221476);
        glVertex2f(6.3245059009936, 4.5730254598358);
        glVertex2f(6.3407598425763, 4.5909047955767);
        glVertex2f(6.3624317646865, 4.6131185157397);
        glVertex2f(6.3819364945857, 4.6342486397971);
        glVertex2f(6.4211261010826, 4.6686628765816);
        glVertex2f(6.4478140223845, 4.6901433986051);
        glVertex2f(6.4849167422432, 4.720085944456);
        glVertex2f(6.5233213119216, 4.7435192412089);
        glVertex2f(6.5643295812391, 4.766301613052);
        glVertex2f(6.6020832260077, 4.785829360346);
        glVertex2f(6.65, 4.8);
        glVertex2f(6.6958164130192, 4.8092626570989);
        glVertex2f(6.7403890573123, 4.8114280613032);
        glVertex2f(6.7651384825053, 4.8158910724036);
        glVertex2f(6.7854248965979, 4.8231941814769);
        glVertex2f(6.8268091813468, 4.8414519541603);
        glVertex2f(6.8450669540301, 4.8515951612065);
        glVertex2f(6.8637304549953, 4.8515951612065);
        glVertex2f(6.8933486195705, 4.850377976361);
        glVertex2f(6.9262126104005, 4.8491607915154);
        glVertex2f(6.9546135901301, 4.8459149652606);
        glVertex2f(6.9866661243964, 4.8353660299325);
        glVertex2f(7.0221394394512, 4.8269970969557);
        glVertex2f(7.0507630213981, 4.8168403420713);
        glVertex2f(7.0830799687575, 4.8020668804213);
        glVertex2f(7.13109371912, 4.7891401014775);
        glVertex2f(7.1791074694826, 4.7872934187713);
        glVertex2f(7.2154926307847, 4.7840559851689);
        glVertex2f(7.255065965071, 4.7889016995713);
        glVertex2f(7.2954469184244, 4.7929397949067);
        glVertex2f(7.3245212048388, 4.7856712233031);
        glVertex2f(7.3697478725945, 4.7695188419617);
        glVertex2f(7.4077059687467, 4.7525588415533);
        glVertex2f(7.4400107314293, 4.7323683648767);
        glVertex2f(7.4739307322462, 4.7146007454012);
        glVertex2f(7.5030050186606, 4.6927950305904);
        glVertex2f(7.5401554957457, 4.6742197920478);
        glVertex2f(7.5797288300319, 4.6411074102981);
        glVertex2f(7.6104183545805, 4.6241474098897);
        glVertex2f(7.6346469265925, 4.6104178857495);
        glVertex2f(7.7024869282261, 4.5886121709387);
        glVertex2f(7.7598628842032, 4.5697902714593);
        glVertex2f(7.8292530283309, 4.5573991742936);
        glVertex2f(7.8720023135524, 4.5443885222696);
        glVertex2f(7.9141320439157, 4.5338560896788);
        glVertex2f(7.9599791034287, 4.51898677308);
        glVertex2f(7.9915764012011, 4.5090738953475);
        glVertex2f(8.0361843509975, 4.4911068044573);
        glVertex2f(8.0814118556522, 4.4681832747008);
        glVertex2f(8.1099113791332, 4.4526944032437);
        glVertex2f(8.137791347756, 4.4260535443375);
        glVertex2f(8.1658490199979, 4.3884686034595);
        glVertex2f(8.2084623604124, 4.3575530427666);
        glVertex2f(8.2385423654108, 4.3433485959618);
        glVertex2f(8.2936890412413, 4.324966370685);
        glVertex2f(8.3663823866542, 4.3141041466577);
        glVertex2f(8.4290490637343, 4.3082552567969);
        glVertex2f(8.5, 4.3);
        glVertex2f(8.55, 4.3);
        glVertex2f(8.6103646494194, 4.2940508099921);
        glVertex2f(8.6571557683059, 4.2856952530481);
        glVertex2f(8.7039468871924, 4.2748330290209);
        glVertex2f(8.7423824491349, 4.256450803744);
        glVertex2f(8.7674491199669, 4.239739689856);
        glVertex2f(8.7674491199669, 4.2238641316624);
        glVertex2f(8.7565868959397, 4.2130019076352);
        glVertex2f(8.7290135580244, 4.2088241291632);
        glVertex2f(8.6830579948324, 4.210495240552);
        glVertex2f(8.6488002113619, 4.2121663519408);
        glVertex2f(8.5978313140034, 4.2221930202736);
        glVertex2f(8.5451913052561, 4.218850797496);
        glVertex2f(8.4984001863697, 4.2096596848576);
        glVertex2f(8.461635735816, 4.1962907937471);
        glVertex2f(8.4206935067903, 4.1779085684703);
        glVertex2f(8.3889423904031, 4.1578552318047);
        glVertex2f(8.3730668322095, 4.133624116667);
        glVertex2f(8.3329601588782, 4.1152418913902);
        glVertex2f(8.2886757070749, 4.0926818876414);
        glVertex2f(8.2417553680689, 4.0791420173743);
        glVertex2f(8.1771054853547, 4.0584052625415);
        glVertex2f(8.1100159844249, 4.0388883168165);
        glVertex2f(8.0465859108186, 4.0205911801992);
        glVertex2f(8, 4);
        glVertex2f(7.9282644273606, 3.982777097857);
        glVertex2f(7.8562956899996, 3.9559412974851);
        glVertex2f(7.7916458072854, 3.930325306221);
        glVertex2f(7.7355345883259, 3.9034895058491);
        glVertex2f(7.6830827966899, 3.8729942781537);
        glVertex2f(7.6416092870242, 3.851037714213);
        glVertex2f(7.617213104868, 3.8242019138411);
        glVertex2f(7.6, 3.8);
        glVertex2f(7.5672009314476, 3.7961463043614);
        glVertex2f(7.5281670399975, 3.7912670679301);
        glVertex2f(7.4671765846068, 3.7863878314989);
        glVertex2f(7.4318021204802, 3.7741897404207);
        glVertex2f(7.4086257474317, 3.746134130941);
        glVertex2f(7.4049663201083, 3.7180785214613);
        glVertex2f(7.4, 3.7);
        glVertex2f(7.3732512833051, 3.7010011939519);
        glVertex2f(7.3403164373941, 3.6985615757363);
        glVertex2f(7.2683477000331, 3.6900229119816);
        glVertex2f(7.1988185808877, 3.6863634846581);
        glVertex2f(7.1170913706641, 3.6851436755503);
        glVertex2f(7.0609801517046, 3.6888031028737);
        glVertex2f(6.9821268954708, 3.6963403985768);
        glVertex2f(6.9239029382566, 3.7010933746759);
        glVertex2f(6.8526082967698, 3.7129758149237);
        glVertex2f(6.7896313634565, 3.727234743221);
        glVertex2f(6.7230896980689, 3.7486231356671);
        glVertex2f(6.6791246691521, 3.7605055759149);
        glVertex2f(6.6351596402352, 3.7747645042122);
        glVertex2f(6.592839493773, 3.7937924768567);
        glVertex2f(6.5344461666351, 3.8127086250844);
        glVertex2f(6.4785201631792, 3.8390267443578);
        glVertex2f(6.4398654254964, 3.8513633627672);
        glVertex2f(6.399565805359, 3.8743917171314);
        glVertex2f(6.35, 3.9);
        glVertex2f(6.3025177405384, 3.9294952793601);
        glVertex2f(6.2729098563559, 3.9500563100424);
        glVertex2f(6.250348218262, 3.9724532780191);
        glVertex2f(6.2291375756217, 3.9966940124652);
        glVertex2f(6.2147446395443, 4.0277524534743);
        glVertex2f(6.2003517034669, 4.0656286010463);
        glVertex2f(6.1859587673896, 4.1133525469871);
        glVertex2f(6.1806561067295, 4.164864107685);
        glVertex2f(6.1768684919723, 4.2201632831402);
        glVertex2f(6.1852012444381, 4.2762199815468);
        glVertex2f(6.2003593753743, 4.330698103064);
        glVertex2f(6.227394257272, 4.3759295400851);
    glEnd();

    glColor3ub(255, 251, 5);
    glBegin(GL_POLYGON);
        glVertex2f(6.3246158517887, 4.2703895203691);
        glVertex2f(6.3204566391891, 4.2885860754926);
        glVertex2f(6.3168173281644, 4.3130214495155);
        glVertex2f(6.3157775250145, 4.3312180046389);
        glVertex2f(6.3168173281644, 4.3514941660622);
        glVertex2f(6.3308546706882, 4.3738499337853);
        glVertex2f(6.3516507336864, 4.389446981034);
        glVertex2f(6.3589293557358, 4.4071236345824);
        glVertex2f(6.3511308321114, 4.4258400912808);
        glVertex2f(6.3401993701067, 4.4391666712231);
        glVertex2f(6.3408312992751, 4.4549649004313);
        glVertex2f(6.3490463784633, 4.4770824213228);
        glVertex2f(6.3661741077888, 4.4845739915898);
        glVertex2f(6.3781838050211, 4.4910077579642);
        glVertex2f(6.3773259695045, 4.5047331262296);
        glVertex2f(6.3713211208884, 4.515456070187);
        glVertex2f(6.3773259695045, 4.5248922608694);
        glVertex2f(6.3949115975945, 4.5334706160353);
        glVertex2f(6.411639390168, 4.5420489712012);
        glVertex2f(6.4296539360163, 4.5493405730922);
        glVertex2f(6.4390901266987, 4.5557743394666);
        glVertex2f(6.4360877023907, 4.5690707899737);
        glVertex2f(6.44, 4.58);
        glVertex2f(6.4553890015139, 4.5909455956466);
        glVertex2f(6.4725457118456, 4.5999528685708);
        glVertex2f(6.4918470109688, 4.6033842106371);
        glVertex2f(6.4944205175186, 4.6213987564855);
        glVertex2f(6.4957072707935, 4.636839795784);
        glVertex2f(6.5041959424018, 4.6514331472041);
        glVertex2f(6.5164447151321, 4.6598805766733);
        glVertex2f(6.5333395740704, 4.6738188352974);
        glVertex2f(6.552346290376, 4.6784649215054);
        glVertex2f(6.5692411493142, 4.68268863624);
        glVertex2f(6.5802228076241, 4.6898689512887);
        glVertex2f(6.5734648640488, 4.7012729810721);
        glVertex2f(6.5730424925754, 4.7118322679085);
        glVertex2f(6.5924715803544, 4.7164783541166);
        glVertex2f(6.6233046979168, 4.7143664967493);
        glVertex2f(6.6401995568551, 4.7118322679085);
        glVertex2f(6.6613181305279, 4.7257705265326);
        glVertex2f(6.6946854769311, 4.7308389842141);
        glVertex2f(6.7115803358694, 4.7240810406388);
        glVertex2f(6.7234067371262, 4.7177454685369);
        glVertex2f(6.7322765380688, 4.7118322679085);
        glVertex2f(6.7588859408966, 4.7135217538024);
        glVertex2f(6.7960546305608, 4.7152112396962);
        glVertex2f(6.8125271180257, 4.7130993823289);
        glVertex2f(6.8311114628578, 4.7118322679085);
        glVertex2f(6.8701785450094, 4.7031810466801);
        glVertex2f(6.897948166545, 4.6886019953739);
        glVertex2f(6.9125272178512, 4.68165958999);
        glVertex2f(6.929883231311, 4.7004040845265);
        glVertex2f(6.95, 4.7);
        glVertex2f(6.9632067771537, 4.6969328818346);
        glVertex2f(6.97778582846, 4.6858250332203);
        glVertex2f(6.9916706392278, 4.6823538305283);
        glVertex2f(7.0090266526876, 4.6761056656828);
        glVertex2f(7.0263826661473, 4.662220854915);
        glVertex2f(7.05, 4.65);
        glVertex2f(7.079144947065, 4.6344512333794);
        glVertex2f(7.1083030496775, 4.6108470550741);
        glVertex2f(7.1388496333667, 4.5990449659214);
        glVertex2f(7.1638422927487, 4.5844659146152);
        glVertex2f(7.1853637494389, 4.5796062308465);
        glVertex2f(7.2041082439754, 4.5789119903081);
        glVertex2f(7.2270181817423, 4.5865486362304);
        glVertex2f(7.25, 4.6);
        glVertex2f(7.2652014113538, 4.5990449659214);
        glVertex2f(7.2860286275056, 4.5962680037679);
        glVertex2f(7.3169201734456, 4.5900327560501);
        glVertex2f(7.34, 4.58);
        glVertex2f(7.3664885537148, 4.5700455059416);
        glVertex2f(7.3712854937408, 4.5624503509003);
        glVertex2f(7.3696865137321, 4.5544554508569);
        glVertex2f(7.3564949286605, 4.552456725846);
        glVertex2f(7.3353084435455, 4.5508577458374);
        glVertex2f(7.3121232334196, 4.5484592758243);
        glVertex2f(7.2969329233371, 4.5460608058113);
        glVertex2f(7.28, 4.54);
        glVertex2f(7.2665523031721, 4.5316699857332);
        glVertex2f(7.2501627580831, 4.528871770718);
        glVertex2f(7.2349724480006, 4.5296712607223);
        glVertex2f(7.224179332942, 4.531270240731);
        glVertex2f(7.2157846878964, 4.531270240731);
        glVertex2f(7.2045918278356, 4.5224758506832);
        glVertex2f(7.191400242764, 4.5112829906225);
        glVertex2f(7.18, 4.5);
        glVertex2f(7.1746109526728, 4.4932944655248);
        glVertex2f(7.1778089126902, 4.4837005854727);
        glVertex2f(7.1830055977184, 4.4765051754336);
        glVertex2f(7.1945982027814, 4.4669112953815);
        glVertex2f(7.2025931028248, 4.4537197103099);
        glVertex2f(7.2129864728812, 4.4421271052469);
        glVertex2f(7.2173836679051, 4.4313339901883);
        glVertex2f(7.2289762729681, 4.421340365134);
        glVertex2f(7.2565586781178, 4.4153441901015);
        glVertex2f(7.2833415932633, 4.4097477600711);
        glVertex2f(7.2993313933501, 4.4053505650472);
        glVertex2f(7.3169201734456, 4.3961564299973);
        glVertex2f(7.3383230244607, 4.3830916415287);
        glVertex2f(7.3518817578228, 4.3708450436533);
        glVertex2f(7.3706890331316, 4.3568489317956);
        glVertex2f(7.3755001965827, 4.347663983389);
        glVertex2f(7.4008681493247, 4.3454770909112);
        glVertex2f(7.4244865880846, 4.3459144694068);
        glVertex2f(7.4502919193222, 4.3371668994957);
        glVertex2f(7.4717234656043, 4.3275445725936);
        glVertex2f(7.5080258807351, 4.3122363252492);
        glVertex2f(7.5255210205573, 4.3043635123293);
        glVertex2f(7.5543880012637, 4.2934290499404);
        glVertex2f(7.5631355711748, 4.2838067230383);
        glVertex2f(7.5561375152459, 4.2728722606495);
        glVertex2f(7.5307695625039, 4.269373232685);
        glVertex2f(7.5089006377263, 4.2615004197651);
        glVertex2f(7.4791589000287, 4.2461921724207);
        glVertex2f(7.4629758956932, 4.2387567379964);
        glVertex2f(7.4411069709156, 4.2356950885275);
        glVertex2f(7.407428826758, 4.2339455745453);
        glVertex2f(7.3789992245471, 4.231321303572);
        glVertex2f(7.3483827298584, 4.2326334390586);
        glVertex2f(7.3142672072053, 4.2317586820675);
        glVertex2f(7.2915235254366, 4.231321303572);
        glVertex2f(7.2744612785151, 4.2257932675683);
        glVertex2f(7.2605520937304, 4.2145589260114);
        glVertex2f(7.25, 4.2);
        glVertex2f(7.2354085673889, 4.1851356505053);
        glVertex2f(7.2380834106167, 4.1771111208219);
        glVertex2f(7.2589471877937, 4.162131998746);
        glVertex2f(7.3317029235906, 4.1300338800121);
        glVertex2f(7.3563114812866, 4.1193345071008);
        glVertex2f(7.3777102271092, 4.1198694757464);
        glVertex2f(7.4039236907419, 4.1252191622021);
        glVertex2f(7.4396547597232, 4.1186912754292);
        glVertex2f(7.4788220803602, 4.1085367848937);
        glVertex2f(7.5375730613158, 4.095481011348);
        glVertex2f(7.5890708347459, 4.0773479925346);
        glVertex2f(7.6101051365695, 4.0693694642566);
        glVertex2f(7.6101051365695, 4.0555883699584);
        glVertex2f(7.6, 4.05);
        glVertex2f(7.5856993709643, 4.054009775704);
        glVertex2f(7.5510520267825, 4.0623729277478);
        glVertex2f(7.5032625865317, 4.0653597677635);
        glVertex2f(7.4614468263123, 4.0695413437855);
        glVertex2f(7.4190336980897, 4.0725281838011);
        glVertex2f(7.3879705619267, 4.0653597677635);
        glVertex2f(7.376023201864, 4.0581913517259);
        glVertex2f(7.371244257839, 4.0420624156413);
        glVertex2f(7.3539205857481, 4.0331018955942);
        glVertex2f(7.3061311454973, 4.0295176875754);
        glVertex2f(7.2553548652309, 4.0336992635974);
        glVertex2f(7.2278759370867, 4.0360887356099);
        glVertex2f(7.2111496329989, 4.031907159588);
        glVertex2f(7.2111496329989, 4.0217519035347);
        glVertex2f(7.2057733209707, 4.0068177034563);
        glVertex2f(7.1932285929049, 4.0068177034563);
        glVertex2f(7.1669444007669, 4.0038308634407);
        glVertex2f(7.15, 4);
        glVertex2f(7.131699688582, 3.9978571834093);
        glVertex2f(7.1203496965224, 3.9912861353748);
        glVertex2f(7.1239339045412, 3.9823256153278);
        glVertex2f(7.1424523126384, 3.9775466713027);
        glVertex2f(7.1633601927481, 3.9727677272777);
        glVertex2f(7.1890470168829, 3.96559931124);
        glVertex2f(7.2153312090208, 3.9626124712244);
        glVertex2f(7.25, 3.95);
        glVertex2f(7.2756653773374, 3.9470809031429);
        glVertex2f(7.3037416734848, 3.9357309110833);
        glVertex2f(7.309117985513, 3.9267703910363);
        glVertex2f(7.3019495694753, 3.9148230309736);
        glVertex2f(7.2876127374001, 3.9142256629705);
        glVertex2f(7.2631206492716, 3.9130309269642);
        glVertex2f(7.220707521049, 3.9136282949673);
        glVertex2f(7.1651522967575, 3.9136282949673);
        glVertex2f(7.1251286405475, 3.9142256629705);
        glVertex2f(7.0935938557144, 3.9119864227739);
        glVertex2f(7.0684696116599, 3.8973981520326);
        glVertex2f(7.0465872055479, 3.8892935571763);
        glVertex2f(7.0058209206595, 3.8732541341467);
        glVertex2f(6.9839114800356, 3.8690809073612);
        glVertex2f(6.9620020394117, 3.8774273609322);
        glVertex2f(6.9233996916459, 3.8857738145032);
        glVertex2f(6.8837540371836, 3.8878604278959);
        glVertex2f(6.8461949961141, 3.8857738145032);
        glVertex2f(6.8190690220083, 3.882643894414);
        glVertex2f(6.7794233675461, 3.8701242140575);
        glVertex2f(6.7575139269222, 3.8555179203083);
        glVertex2f(6.71786827246, 3.8596911470938);
        glVertex2f(6.680190054244, 3.8656986811799);
        glVertex2f(6.6325397453533, 3.8820562499036);
        glVertex2f(6.5834670391823, 3.9026810104682);
        glVertex2f(6.5215927574884, 3.9297065587943);
        glVertex2f(6.4789208390789, 3.9503313193589);
        glVertex2f(6.434826523389, 3.9802016622456);
        glVertex2f(6.400715360075, 4.0065775598724);
        glVertex2f(6.3661856674174, 4.0322740753384);
        glVertex2f(6.342095184168, 4.064394719671);
        glVertex2f(6.3388831197347, 4.1037425089785);
        glVertex2f(6.3356710553014, 4.1679837976437);
        glVertex2f(6.3308529586515, 4.2201798446842);
        glVertex2f(6.3292469264349, 4.2547095373417);
    glEnd();

    glColor3ub(255, 209, 125);
    glBegin(GL_POLYGON);
        glVertex2f(6.4753201016554, 4.5434306602696);
        glVertex2f(6.5076025361996, 4.5709305119184);
        glVertex2f(6.5362980335723, 4.5948434263956);
        glVertex2f(6.5550175006339, 4.6066503169608);
        glVertex2f(6.5690282804732, 4.6144963536708);
        glVertex2f(6.5858412162805, 4.6262654087359);
        glVertex2f(6.6004124273134, 4.6307488582845);
        glVertex2f(6.6144232071528, 4.6363531702203);
        glVertex2f(6.6402030420573, 4.645880500511);
        glVertex2f(6.668224601736, 4.6520452436404);
        glVertex2f(6.6923231430597, 4.6554078308018);
        glVertex2f(6.7153008219963, 4.6559682619954);
        glVertex2f(6.7309928954164, 4.6559682619954);
        glVertex2f(6.7517288495787, 4.656528693189);
        glVertex2f(6.7663000606116, 4.6554078308018);
        glVertex2f(6.7797504092574, 4.6537265372211);
        glVertex2f(6.8, 4.65);
        glVertex2f(6.8184201616141, 4.6470013628982);
        glVertex2f(6.8346726662278, 4.6447596381239);
        glVertex2f(6.8498043084543, 4.6402761885753);
        glVertex2f(6.8666172442616, 4.6363531702203);
        glVertex2f(6.8828697488752, 4.6301884270909);
        glVertex2f(6.8985618222953, 4.6217819591873);
        glVertex2f(6.9176164828769, 4.611694197703);
        glVertex2f(6.9338689874906, 4.6027272986058);
        glVertex2f(6.951802785685, 4.58927694996);
        glVertex2f(6.9652531343308, 4.5814309132499);
        glVertex2f(6.974220033428, 4.5741453077334);
        glVertex2f(6.9837473637187, 4.5651784086362);
        glVertex2f(7, 4.55);
        glVertex2f(7.0112084922039, 4.5382777113446);
        glVertex2f(7.0207358224947, 4.5231460691181);
        glVertex2f(7.0381091894955, 4.5029705461494);
        glVertex2f(7.0487573821734, 4.4878389039229);
        glVertex2f(7.0622077308192, 4.4699051057285);
        glVertex2f(7.0669642419219, 4.458312095008);
        glVertex2f(7.0728426383963, 4.4461879022794);
        glVertex2f(7.0772514357522, 4.4377377073474);
        glVertex2f(7.0801906339894, 4.4252461148391);
        glVertex2f(7.0849668311249, 4.4120197227716);
        glVertex2f(7.0897430282604, 4.398793330704);
        glVertex2f(7.0937844258366, 4.3789537426027);
        glVertex2f(7.1, 4.36);
        glVertex2f(7.1033368201076, 4.3381723670611);
        glVertex2f(7.1040716196669, 4.3142913813836);
        glVertex2f(7.1037042198873, 4.2992279904178);
        glVertex2f(7.1033368201076, 4.2790210025368);
        glVertex2f(7.1033368201076, 4.2595488142151);
        glVertex2f(7.0999284399254, 4.2313729254375);
        glVertex2f(7.0948346260788, 4.2124530454358);
        glVertex2f(7.0919238753093, 4.1906224146647);
        glVertex2f(7.0824639353084, 4.1709748469706);
        glVertex2f(7.073731683, 4.1505995915842);
        glVertex2f(7.0635440553068, 4.1214920838893);
        glVertex2f(7.05, 4.1);
        glVertex2f(7.0344365476118, 4.0785585100393);
        glVertex2f(7.019155106072, 4.0567278792681);
        glVertex2f(6.9973244753008, 4.0327141854198);
        glVertex2f(6.9718554060678, 4.0094281792639);
        glVertex2f(6.94493096145, 3.9934190500317);
        glVertex2f(6.9121850152932, 3.9730437946452);
        glVertex2f(6.8816221322136, 3.957034665413);
        glVertex2f(6.8510592491339, 3.9424809115656);
        glVertex2f(6.8117641137458, 3.9352040346419);
        glVertex2f(6.7790181675891, 3.93156559618);
        glVertex2f(6.7513660352789, 3.9301102207952);
        glVertex2f(6.7186200891221, 3.9293825331029);
        glVertex2f(6.6997002091204, 3.93156559618);
        glVertex2f(6.6660989262452, 3.934148385664);
        glVertex2f(6.640563287455, 3.9421738721409);
        glVertex2f(6.6157572383445, 3.9487401792584);
        glVertex2f(6.5916807789137, 3.9611432038137);
        glVertex2f(6.5683339091627, 3.97062786965);
        glVertex2f(6.5427982703725, 3.9866788426039);
        glVertex2f(6.5172626315823, 4.0041889949171);
        glVertex2f(6.499752479269, 4.0216991472304);
        glVertex2f(6.4785943785571, 4.038479709864);
        glVertex2f(6.4567066881655, 4.0589082208961);
        glVertex2f(6.4406557152117, 4.0829846803269);
        glVertex2f(6.426793511297, 4.1041427810388);
        glVertex2f(6.4180384351404, 4.1274896507898);
        glVertex2f(6.4070945899446, 4.1493773411814);
        glVertex2f(6.3939619757096, 4.1792905180499);
        glVertex2f(6.3881252582719, 4.2048261568401);
        glVertex2f(6.3822885408341, 4.2296322059506);
        glVertex2f(6.3793701821152, 4.2595453828191);
        glVertex2f(6.3779110027558, 4.2872697906485);
        glVertex2f(6.3771814130761, 4.3106166603995);
        glVertex2f(6.3793701821152, 4.3361522991897);
        glVertex2f(6.3807879173079, 4.3583142917039);
        glVertex2f(6.3870756674499, 4.3787494796655);
        glVertex2f(6.3912675008779, 4.3970887509131);
        glVertex2f(6.3959833134844, 4.4169999596962);
        glVertex2f(6.405938917876, 4.4342912725868);
        glVertex2f(6.4169424806245, 4.4536785021913);
        glVertex2f(6.4268980850161, 4.4714937942604);
        glVertex2f(6.4368536894076, 4.492976940579);
        glVertex2f(6.4489052105132, 4.5128881493621);
        glVertex2f(6.4583368357262, 4.5280835455387);
    glEnd();
    glPopMatrix();
}

void heart(){
    glPushMatrix();
    glTranslated(-0.5,8.7,0);
    glScaled(0.25,0.25,0);
    glRotated(-2,0,0,1);
    glColor3ub(240, 10, 10);
    glBegin(GL_POLYGON);
        glVertex2f(3.967908792444, 3.527012661619);
        glVertex2f(4.0241132998109, 2.0621826883709);
        glVertex2f(3.99768714084, 2.0848068989057);
        glVertex2f(3.9702302971955, 2.1159020645604);
        glVertex2f(3.9157807969595, 2.1712297825421);
        glVertex2f(3.8736263451638, 2.2089931456091);
        glVertex2f(3.8305936756224, 2.2555386861334);
        glVertex2f(3.7691184334205, 2.3117446218609);
        glVertex2f(3.6988610137611, 2.3679505575884);
        glVertex2f(3.6391422070506, 2.4197654045872);
        glVertex2f(3.6022570617294, 2.4584069853999);
        glVertex2f(3.55, 2.5);
        glVertex2f(3.5205828113754, 2.5312990582965);
        glVertex2f(3.4828194483084, 2.5708188568549);
        glVertex2f(3.4255868603386, 2.6240178029291);
        glVertex2f(3.3657005176965, 2.6806376177907);
        glVertex2f(3.3145249158024, 2.7361685900588);
        glVertex2f(3.2611716287213, 2.7818999789855);
        glVertex2f(3.22959519351, 2.8167429419772);
        glVertex2f(3.2012852860792, 2.8461416920015);
        glVertex2f(3.1773307490224, 2.8777181272128);
        glVertex2f(3.1490208415916, 2.9103834050175);
        glVertex2f(3.1217997767543, 2.9506705809767);
        glVertex2f(3.0804237582016, 3.0116457662123);
        glVertex2f(3.0553803785513, 3.050844099578);
        glVertex2f(3.0336035266815, 3.0900424329437);
        glVertex2f(3.0150932025921, 3.1292407663094);
        glVertex2f(2.9911386655353, 3.185860581171);
        glVertex2f(2.968272971072, 3.2348584978782);
        glVertex2f(2.9530291747631, 3.2947448405202);
        glVertex2f(2.9474240830428, 3.3396795246429);
        glVertex2f(2.9409201958247, 3.3982145096057);
        glVertex2f(2.9370178634939, 3.4502456073504);
        glVertex2f(2.9409201958247, 3.5048782599824);
        glVertex2f(2.95002563793, 3.5491046930654);
        glVertex2f(2.9565295251481, 3.594631903592);
        glVertex2f(2.9643341898098, 3.6375575592314);
        glVertex2f(2.9851466289077, 3.6960925441942);
        glVertex2f(3.0098614003365, 3.7468228644953);
        glVertex2f(3.0306738394344, 3.7884477426911);
        glVertex2f(3.0631932755248, 3.8352757306613);
        glVertex2f(3.0996150439461, 3.8664943893082);
        glVertex2f(3.1347360349238, 3.8990138253986);
        glVertex2f(3.1656990969683, 3.9183111178374);
        glVertex2f(3.206269924511, 3.9394785061206);
        glVertex2f(3.2494866755891, 3.9579999708683);
        glVertex2f(3.2838836815493, 3.9721115630571);
        glVertex2f(3.3218085855566, 3.9826952571987);
        glVertex2f(3.3667892856583, 3.9862231552459);
        glVertex2f(3.4020682661302, 3.9906330278048);
        glVertex2f(3.45, 4);
        glVertex2f(3.5, 4);
        glVertex2f(3.5511219586241, 3.9906330278048);
        glVertex2f(3.6181520215207, 3.9712295885453);
        glVertex2f(3.6613687725988, 3.9553540473329);
        glVertex2f(3.6904739314882, 3.9394785061206);
        glVertex2f(3.7213430394011, 3.9209570413728);
        glVertex2f(3.75, 3.9);
        glVertex2f(3.7805532734248, 3.8702356780609);
        glVertex2f(3.8, 3.85);
        glVertex2f(3.8259670488371, 3.8229682791623);
        glVertex2f(3.85, 3.8);
        glVertex2f(3.8686003890201, 3.7747740685206);
        glVertex2f(3.8834293769099, 3.7497501514567);
        glVertex2f(3.8973315530565, 3.7200921756772);
        glVertex2f(3.9130873526894, 3.6765320237511);
        glVertex2f(3.9306967758085, 3.6376059305405);
        glVertex2f(3.9464525754413, 3.5773631672384);
        glVertex2f(3.9575743163586, 3.548632003202);
        glVertex2f(3.9688533883573, 3.4274391057248);
        glVertex2f(3.9726635137896, 3.3398062207805);
        glVertex2f(3.9726635137896, 3.2991648828354);
    glEnd();

    glColor3ub(240, 10, 10);
    glBegin(GL_POLYGON);
        glVertex2f(4.0241132998109, 2.0621826883709);
        glVertex2f(4.0858860417347, 2.119051750284);
        glVertex2f(4.1170340657559, 2.1501997743052);
        glVertex2f(4.152244875519, 2.1975989412939);
        glVertex2f(4.1982897805938, 2.2463523701966);
        glVertex2f(4.2497517333244, 2.307294156325);
        glVertex2f(4.2985051622271, 2.3641731567115);
        glVertex2f(4.3540299006996, 2.4237606809259);
        glVertex2f(4.4014290676884, 2.4765768955705);
        glVertex2f(4.4447654489352, 2.5239760625593);
        glVertex2f(4.5016444493217, 2.5781465391178);
        glVertex2f(4.5368552590848, 2.6241914441926);
        glVertex2f(4.5736392716099, 2.6664233703779);
        glVertex2f(4.6, 2.7);
        glVertex2f(4.6326859313588, 2.7408644555518);
        glVertex2f(4.6657768373218, 2.7794705125087);
        glVertex2f(4.7126556207694, 2.8318644469501);
        glVertex2f(4.7512616777262, 2.8815008058946);
        glVertex2f(4.7912465224315, 2.9352735280845);
        glVertex2f(4.8298525793884, 2.9918038257712);
        glVertex2f(4.8712162118421, 3.0607432131942);
        glVertex2f(4.9029283300566, 3.1186522986294);
        glVertex2f(4.9346404482712, 3.1862128983039);
        glVertex2f(4.9594586277434, 3.2537734979783);
        glVertex2f(4.972527375317, 3.3104887773246);
        glVertex2f(4.9902157076658, 3.373201955652);
        glVertex2f(5.0014719191605, 3.4391311944065);
        glVertex2f(5, 3.5);
        glVertex2f(4.9950397983064, 3.575813762556);
        glVertex2f(4.9773514659576, 3.6401349710969);
        glVertex2f(4.9562519489316, 3.6985914603833);
        glVertex2f(4.9313255776025, 3.7484442030413);
        glVertex2f(4.8961354063145, 3.8129595170694);
        glVertex2f(4.8682765207115, 3.8510822026314);
        glVertex2f(4.8360188636975, 3.8950699167414);
        glVertex2f(4.7890986353135, 3.9478551736734);
        glVertex2f(4.7392458926554, 3.9801128306875);
        glVertex2f(4.7, 4);
        glVertex2f(4.6336753787914, 4.0270330590715);
        glVertex2f(4.5823563789964, 4.0446281447155);
        glVertex2f(4.5295711220643, 4.0504931732635);
        glVertex2f(4.4650558080363, 4.0563582018115);
        glVertex2f(4.3961417225973, 4.0504931732635);
        glVertex2f(4.3697490941313, 4.0416956304415);
        glVertex2f(4.3067000372402, 4.0255668019345);
        glVertex2f(4.2671110945412, 4.0123704877015);
        glVertex2f(4.2172583518832, 3.9830453449615);
        glVertex2f(4.1806019234582, 3.9625177450435);
        glVertex2f(4.1322154379371, 3.9185300309334);
        glVertex2f(4.0999577809231, 3.8848061167824);
        glVertex2f(4.0677001239091, 3.8466834312204);
        glVertex2f(4.0486387811281, 3.8041619742474);
        glVertex2f(4.0237124097991, 3.7587080030004);
        glVertex2f(4.0105160955661, 3.7279166031233);
        glVertex2f(4, 3.7);
        glVertex2f(3.9885222385111, 3.6604687748213);
        glVertex2f(3.9841234671001, 3.6267448606703);
        glVertex2f(3.9826572099631, 3.6047510036153);
        glVertex2f(3.9754823430535, 3.5810708832996);
        glVertex2f(3.9712864061316, 3.5483425753084);
        glVertex2f(3.963733719672, 3.5198102042392);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
        glVertex2f(4.3033798778309, 3.8800125077411);
        glVertex2f(4.3148727640309, 3.8897372576026);
        glVertex2f(4.3303439569923, 3.8985779392948);
        glVertex2f(4.3449310817846, 3.9091867573255);
        glVertex2f(4.3555398998153, 3.9171433708486);
        glVertex2f(4.3705690586921, 3.9237738821178);
        glVertex2f(4.3860402516536, 3.9321725297254);
        glVertex2f(4.4037216150381, 3.9392450750792);
        glVertex2f(4.4165406034919, 3.9418972795869);
        glVertex2f(4.4306856941995, 3.946317620433);
        glVertex2f(4.451903330261, 3.9516220294484);
        glVertex2f(4.4767812574171, 3.9553913299673);
        glVertex2f(4.5037570137803, 3.9583341397524);
        glVertex2f(4.5258280871683, 3.9583341397524);
        glVertex2f(4.5581989948041, 3.9558817982648);
        glVertex2f(4.5787986632996, 3.9524485201822);
        glVertex2f(4.6038125464727, 3.9460724323146);
        glVertex2f(4.6253931515633, 3.9387154078519);
        glVertex2f(4.6420690736787, 3.9328297882817);
        glVertex2f(4.6528593762239, 3.9279251053066);
        glVertex2f(4.6626687421742, 3.922529954034);
        glVertex2f(4.6783637276946, 3.9141919929763);
        glVertex2f(4.6906254351324, 3.9078159051086);
        glVertex2f(4.7, 3.9);
        glVertex2f(4.5588653182321, 3.7925504088063);
        glVertex2f(4.5322610526681, 3.8169376522399);
        glVertex2f(4.5092040225127, 3.8320134027261);
        glVertex2f(4.4879206100616, 3.844428726656);
        glVertex2f(4.463533366628, 3.8568440505858);
        glVertex2f(4.4413631453247, 3.864825330255);
        glVertex2f(4.4183061151693, 3.8728066099241);
        glVertex2f(4.3854941876405, 3.8776840586109);
        glVertex2f(4.36, 3.88);
        glVertex2f(4.334946083069, 3.8816746984454);
        glVertex2f(4.3163230971743, 3.8816746984454);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
        glVertex2f(4.7, 3.9);
        glVertex2f(4.7126965085204, 3.8916304512907);
        glVertex2f(4.7254486842557, 3.8808401487454);
        glVertex2f(4.734277113611, 3.8720117193902);
        glVertex2f(4.7474147094034, 3.8607588275739);
        glVertex2f(4.7561224649985, 3.8503095208599);
        glVertex2f(4.7670071594923, 3.8376832752471);
        glVertex2f(4.7761503028671, 3.8259278051938);
        glVertex2f(4.7857288340216, 3.8137369473607);
        glVertex2f(4.7931304262774, 3.7989337628491);
        glVertex2f(4.802708957432, 3.7854367416768);
        glVertex2f(4.8092397741283, 3.7723751082842);
        glVertex2f(4.8162059786043, 3.7597488626714);
        glVertex2f(4.8201244686221, 3.7449456781598);
        glVertex2f(4.8254235121415, 3.7304502849023);
        glVertex2f(4.8290428105789, 3.7190753469565);
        glVertex2f(4.8316280237484, 3.7014958974038);
        glVertex2f(4.8352473221857, 3.6818482773155);
        glVertex2f(4.8393836632569, 3.6554791029864);
        glVertex2f(4.8419688764264, 3.631178099193);
        glVertex2f(4.8404177485247, 3.6063600527657);
        glVertex2f(4.6635567317134, 3.5685316979226);
        glVertex2f(4.6626364907881, 3.5942984438322);
        glVertex2f(4.6534340815346, 3.6311080808459);
        glVertex2f(4.6442316722812, 3.6651569950836);
        glVertex2f(4.6285875765504, 3.6982856683959);
        glVertex2f(4.6147839626703, 3.7249726552308);
        glVertex2f(4.5908576986114, 3.7562608466924);
        glVertex2f(4.5742933619552, 3.7765061470499);
        glVertex2f(4.5588653182321, 3.7925504088063);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
        glVertex2f(4.8404177485247, 3.6063600527657);
        glVertex2f(4.8399007058908, 3.5841272195079);
        glVertex2f(4.8378325353552, 3.5613773436161);
        glVertex2f(4.8347302795518, 3.5319059134837);
        glVertex2f(4.828525767945, 3.5127753360293);
        glVertex2f(4.819585641898, 3.4780771863786);
        glVertex2f(4.8037107992939, 3.43541354688);
        glVertex2f(4.7858516013642, 3.4006873286835);
        glVertex2f(4.7650158704463, 3.3619923998359);
        glVertex2f(4.7412036065401, 3.3282583593021);
        glVertex2f(4.7163991649711, 3.2945243187683);
        glVertex2f(4.6876260127511, 3.2578137452463);
        glVertex2f(4.6598450381939, 3.2250718823752);
        glVertex2f(4.6320640636367, 3.193322197167);
        glVertex2f(4.6022987337539, 3.1615725119587);
        glVertex2f(4.5685646932201, 3.1258541160994);
        glVertex2f(4.5407837186629, 3.0970809638794);
        glVertex2f(4.5141187525412, 3.0699382960731);
        glVertex2f(4.4866309918769, 3.0344702177967);
        glVertex2f(4.45, 3);
        glVertex2f(4.4715570586094, 3.0442239393227);
        glVertex2f(4.5008182231875, 3.0921058449959);
        glVertex2f(4.5220990701534, 3.1284606252293);
        glVertex2f(4.5442666190762, 3.1727957230749);
        glVertex2f(4.5682075719128, 3.2162441189636);
        glVertex2f(4.5859416110511, 3.2534856011539);
        glVertex2f(4.6010155443186, 3.2836334676889);
        glVertex2f(4.6143160736723, 3.3173281420515);
        glVertex2f(4.6285033049828, 3.3536829222849);
        glVertex2f(4.6387102267292, 3.3872442356303);
        glVertex2f(4.651593599684, 3.4341765228227);
        glVertex2f(4.6580352861614, 3.4765076053884);
        glVertex2f(4.6644769726388, 3.5280410972076);
        glVertex2f(4.6635567317134, 3.5685316979226);
    glEnd();
    glPopMatrix();
}

//Void untuk di DisplayFunc
void level1 (){
    backgroundlevel1();

    tree();

    rumput();

    glPushMatrix();
    glTranslated(0,-0.8,0);
    road();
    glPopMatrix();

    cloud();

    glPushMatrix();
    glTranslated(8,7,0);
    glScaled(0.25,0.25,0);
    blackBird();
    glPopMatrix();

    glPushMatrix();
    glTranslated(8,0,0);
    glScaled(0.04,0.08,0);
    stone();
    glPopMatrix();

    fireball();

    if (heartStatus_bar==3){
        glPushMatrix();
        heart();
        glTranslated(0.5,0,0);
        heart();
        glTranslated(0.5,0,0);
        heart();
        glPopMatrix();
    }if (heartStatus_bar==2){
        glPushMatrix();
        heart();
        glTranslated(0.5,0,0);
        heart();
        glPopMatrix();
    }if (heartStatus_bar==1){
        glPushMatrix();
        heart();
        glPopMatrix();
    }

    glPushMatrix();
    if (fireballStatus_bar==1){
        fireball_status();
    }
    glPopMatrix();

    glPushMatrix();
    if (fireballStatus_bar==2){
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
    }
    glPopMatrix();

    glPushMatrix();
    if (fireballStatus_bar==3){
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
    }
    glPopMatrix();

    glPushMatrix();
    if (fireballStatus_bar==4){
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
    }
    glPopMatrix();

    glPushMatrix();
    if (fireballStatus_bar==5){
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
    }
    glPopMatrix();

}

//Level 2

void backgroundlevel2(){
    glPushMatrix();
    glColor3ub(16, 17, 30);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(10,0);
        glColor3ub(25, 38, 88);
        glVertex2f(10,10);
        glVertex2f(0,10);
    glEnd();
    glPopMatrix();
}

void star (){
    glPushMatrix();
    glTranslated(-1,1,0);
    glPointSize(3);
    glColor3ub(239, 172, 21);
    glBegin(GL_POINTS);
        glVertex2f(2,8);
        glVertex2f(2.02,8.03);
        glVertex2f(2.03,8);
        glVertex2f(2.02,7.98);
    glEnd();
    glPopMatrix();
}

void stars (){
    glPushMatrix();
    star();
    glTranslated(1,0.4,0);
    star();
    glTranslated(1,0.1,0);
    star();
    glTranslated(1,0.6,0);
    star();
    glTranslated(1,0.2,0);
    star();
    glTranslated(1,-0.5,0);
    star();
    glTranslated(1,-0.6,0);
    star();
    glTranslated(1,0.1,0);
    star();
    glTranslated(1,0.3,0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6,-1,0);
    star();
    glTranslated(1.1,0,0);
    star();
    glTranslated(1.3,0.4,0);
    star();
    glTranslated(1.5,0.2,0);
    star();
    glTranslated(1.5,0.1,0);
    star();
    glTranslated(1.5,0.6,0);
    star();
    glTranslated(1.5,0.4,0);
    star();
    glTranslated(1.6,0.4,0);
    star();
    glTranslated(1.3,0.1,0);
    star();
    glTranslated(1.2,0.7,0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.4,-2,0);
    star();
    glTranslated(1,-0.4,0);
    star();
    glTranslated(1,0.1,0);
    star();
    glTranslated(1.4,0.2,0);
    star();
    glTranslated(1.1,-0.5,0);
    star();
    glTranslated(1,0.5,0);
    star();
    glTranslated(1,-0.1,0);
    star();
    glTranslated(1.5,-0.4,0);
    star();
    glTranslated(1,-0.6,0);
    star();
    glPopMatrix();

}

void road2 (){
    glPushMatrix();
    glTranslated(0,-0.8,0);
    glColor3ub(179, 179, 179);
    glBegin(GL_QUADS);
        glVertex2f(0, 3);
        glVertex2f(10, 3);
        glVertex2f(10, 4.5);
        glVertex2f(0, 4.5);
    glEnd();
    glPopMatrix();
}

void roadline(){
    //roadline 1 yang di pinggir jalan
    glPushMatrix();
    glLineWidth(4);
    glTranslated(roadlinelvl2[0],1.55,0);
    glColor3ub(99, 99, 99);
    glBegin(GL_LINES);
        glVertex2f(2,1);
        glVertex2f(3,2);
    glEnd();
    glPopMatrix();

    //roadline 2 yang di pinggir jalan
    glPushMatrix();
    glLineWidth(4);
    glTranslated(roadlinelvl2[1],1.55,0);
    glColor3ub(99, 99, 99);
    glBegin(GL_LINES);
        glVertex2f(2,1);
        glVertex2f(3,2);
    glEnd();
    glPopMatrix();

    //roadline 3 yang di pinggir jalan
    glPushMatrix();
    glLineWidth(4);
    glTranslated(roadlinelvl2[2],1.55,0);
    glColor3ub(99, 99, 99);
    glBegin(GL_LINES);
        glVertex2f(2,1);
        glVertex2f(3,2);
    glEnd();
    glPopMatrix();

    //roadline 4 yang di pinggir jalan
    glPushMatrix();
    glLineWidth(4);
    glTranslated(roadlinelvl2[3],1.55,0);
    glColor3ub(99, 99, 99);
    glBegin(GL_LINES);
        glVertex2f(2,1);
        glVertex2f(3,2);
    glEnd();
    glPopMatrix();

    //roadline 5 yang di pinggir jalan
    glPushMatrix();
    glLineWidth(4);
    glTranslated(roadlinelvl2[4],1.55,0);
    glColor3ub(99, 99, 99);
    glBegin(GL_LINES);
        glVertex2f(2,1);
        glVertex2f(3,2);
    glEnd();
    glPopMatrix();

    //roadline 6 yang di pinggir jalan
    glPushMatrix();
    glLineWidth(4);
    glTranslated(roadlinelvl2[5],1.55,0);
    glColor3ub(99, 99, 99);
    glBegin(GL_LINES);
        glVertex2f(2,1);
        glVertex2f(3,2);
    glEnd();
    glPopMatrix();

    //roadline 7 yang di pinggir jalan
    glPushMatrix();
    glLineWidth(4);
    glTranslated(roadlinelvl2[6],1.55,0);
    glColor3ub(99, 99, 99);
    glBegin(GL_LINES);
        glVertex2f(2,1);
        glVertex2f(3,2);
    glEnd();
    glPopMatrix();
}

void lamp(){
    //Lampu 1
    glPushMatrix();
    glTranslated(lamplvl2[2],2,0);
    glScaled(0.4,0.4,0);
    glPushMatrix();                                     //Bagian bawah tiang
    glColor3ub(112, 76, 52);
    glBegin(GL_QUADS);
        glVertex2f(2.5500573391679, 2.444603574832);
        glVertex2f(2.8189440783599, 2.4433031537679);
        glVertex2f(3.1389820874064, 1.3556678955842);
        glVertex2f(2.2068069454137, 1.3494948414238);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //Tiang
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex2f(2.6843234615626,2.4833156986779);
        glVertex2f(2.6843173416322,5.9471450826595);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //wadah lampu
    glColor3ub(83, 49, 21);
    glBegin(GL_POLYGON);
        glVertex2f(2.3185247708212, 6.9092669253057);
        glVertex2f(2.392021640114, 5.9798329698799);
        glVertex2f(2.4260321685875, 5.9516528177161);
        glVertex2f(2.4668448027557, 5.9225009361674);
        glVertex2f(2.506, 5.9);
        glVertex2f(2.5611308237116, 5.8739144669195);
        glVertex2f(2.6155193986542, 5.8603102555301);
        glVertex2f(2.666049326672, 5.8564233379903);
        glVertex2f(2.7165792546898, 5.8535081498354);
        glVertex2f(2.7729395590173, 5.863225443685);
        glVertex2f(2.8234694870351, 5.8846034901541);
        glVertex2f(2.8817732501326, 5.9137553717028);
        glVertex2f(2.9274445312256, 5.9448507120214);
        glVertex2f(2.9595116009292, 5.9817764286498);
        glVertex2f(3.0397832903166, 6.9095286433506);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //objek lampu
    glColor3ub(239, 172, 21);
    glTranslated(0.006,0,0);
    glBegin(GL_QUADS);
        glVertex2f(2.4428276813169, 6.0511150529822);   //kiri
        glVertex2f(2.3791945456307, 6.8049307737665);
        glVertex2f(2.640874003513, 6.8014240958057);
        glVertex2f(2.640874003513, 6.0511150529822);

        glVertex2f(2.7136013877242, 6.052172598303);    //kanan
        glVertex2f(2.9142668746947, 6.0511967634231);
        glVertex2f(2.9702847412456, 6.8006932745462);
        glVertex2f(2.7136666950167, 6.8021585985759);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //Garis bawah tiang
    glLineWidth(4);
    glColor3ub(83, 49, 21);
    glBegin(GL_LINES);
        glVertex2f(2.1477215158338, 1.3021233538741);
        glVertex2f(3.2017807536256, 1.3028979528192);

        glVertex2f(2.5552056695422, 2.4779478633133);
        glVertex2f(2.8150567058827, 2.4779478633133);

        glVertex2f(2.2978374929653,6.8503477828281);
        glVertex2f(3.0614974005328,6.8503477828281);

        glVertex2f(2.6938011759811,7.4893286517007);
        glVertex2f(2.6938011759811,7.0393171985038);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //tutup wadah lampu
    glColor3ub(112, 76, 52);
    glTranslated(0.01,0.2,0);
    glBegin(GL_POLYGON);
        glVertex2f(2.2699710987605, 6.686215568036);
        glVertex2f(2.3025279888684, 6.7129587277674);
        glVertex2f(2.3315966407504, 6.7513293482517);
        glVertex2f(2.362990784783, 6.7943509530371);
        glVertex2f(2.3978731670415, 6.8478372725001);
        glVertex2f(2.4339182953752, 6.901323591963);
        glVertex2f(2.4711261697842, 6.9489961810495);
        glVertex2f(2.5048458059674, 6.9862040554585);
        glVertex2f(2.5420536803764, 7.0222491837923);
        glVertex2f(2.5723175081348, 7.0410119263117);
        glVertex2f(2.7787756454743, 7.0434504082488);
        glVertex2f(2.8075680976481, 7.0269606340181);
        glVertex2f(2.838448317393, 6.9990688226356);
        glVertex2f(2.8683324010171, 6.9671924667698);
        glVertex2f(2.8982164846413, 6.9233624774544);
        glVertex2f(2.9330812488694, 6.8725595352934);
        glVertex2f(2.9669498769768, 6.8197643208907);
        glVertex2f(2.9938455522385, 6.7759343315753);
        glVertex2f(3.0237296358627, 6.737085022864);
        glVertex2f(3.0585944000908, 6.6952473057902);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //Lampu 2
    glPushMatrix();
    glTranslated(lamplvl2[3],2,0);
    glScaled(0.4,0.4,0);
    glPushMatrix();                                     //Bagian bawah tiang
    glColor3ub(112, 76, 52);
    glBegin(GL_QUADS);
        glVertex2f(2.5500573391679, 2.444603574832);
        glVertex2f(2.8189440783599, 2.4433031537679);
        glVertex2f(3.1389820874064, 1.3556678955842);
        glVertex2f(2.2068069454137, 1.3494948414238);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //Tiang
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex2f(2.6843234615626,2.4833156986779);
        glVertex2f(2.6843173416322,5.9471450826595);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //wadah lampu
    glColor3ub(83, 49, 21);
    glBegin(GL_POLYGON);
        glVertex2f(2.3185247708212, 6.9092669253057);
        glVertex2f(2.392021640114, 5.9798329698799);
        glVertex2f(2.4260321685875, 5.9516528177161);
        glVertex2f(2.4668448027557, 5.9225009361674);
        glVertex2f(2.506, 5.9);
        glVertex2f(2.5611308237116, 5.8739144669195);
        glVertex2f(2.6155193986542, 5.8603102555301);
        glVertex2f(2.666049326672, 5.8564233379903);
        glVertex2f(2.7165792546898, 5.8535081498354);
        glVertex2f(2.7729395590173, 5.863225443685);
        glVertex2f(2.8234694870351, 5.8846034901541);
        glVertex2f(2.8817732501326, 5.9137553717028);
        glVertex2f(2.9274445312256, 5.9448507120214);
        glVertex2f(2.9595116009292, 5.9817764286498);
        glVertex2f(3.0397832903166, 6.9095286433506);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //objek lampu
    glColor3ub(239, 172, 21);
    glTranslated(0.006,0,0);
    glBegin(GL_QUADS);
        glVertex2f(2.4428276813169, 6.0511150529822);   //kiri
        glVertex2f(2.3791945456307, 6.8049307737665);
        glVertex2f(2.640874003513, 6.8014240958057);
        glVertex2f(2.640874003513, 6.0511150529822);

        glVertex2f(2.7136013877242, 6.052172598303);    //kanan
        glVertex2f(2.9142668746947, 6.0511967634231);
        glVertex2f(2.9702847412456, 6.8006932745462);
        glVertex2f(2.7136666950167, 6.8021585985759);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //Garis bawah tiang
    glLineWidth(4);
    glColor3ub(83, 49, 21);
    glBegin(GL_LINES);
        glVertex2f(2.1477215158338, 1.3021233538741);
        glVertex2f(3.2017807536256, 1.3028979528192);

        glVertex2f(2.5552056695422, 2.4779478633133);
        glVertex2f(2.8150567058827, 2.4779478633133);

        glVertex2f(2.2978374929653,6.8503477828281);
        glVertex2f(3.0614974005328,6.8503477828281);

        glVertex2f(2.6938011759811,7.4893286517007);
        glVertex2f(2.6938011759811,7.0393171985038);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //tutup wadah lampu
    glColor3ub(112, 76, 52);
    glTranslated(0.01,0.2,0);
    glBegin(GL_POLYGON);
        glVertex2f(2.2699710987605, 6.686215568036);
        glVertex2f(2.3025279888684, 6.7129587277674);
        glVertex2f(2.3315966407504, 6.7513293482517);
        glVertex2f(2.362990784783, 6.7943509530371);
        glVertex2f(2.3978731670415, 6.8478372725001);
        glVertex2f(2.4339182953752, 6.901323591963);
        glVertex2f(2.4711261697842, 6.9489961810495);
        glVertex2f(2.5048458059674, 6.9862040554585);
        glVertex2f(2.5420536803764, 7.0222491837923);
        glVertex2f(2.5723175081348, 7.0410119263117);
        glVertex2f(2.7787756454743, 7.0434504082488);
        glVertex2f(2.8075680976481, 7.0269606340181);
        glVertex2f(2.838448317393, 6.9990688226356);
        glVertex2f(2.8683324010171, 6.9671924667698);
        glVertex2f(2.8982164846413, 6.9233624774544);
        glVertex2f(2.9330812488694, 6.8725595352934);
        glVertex2f(2.9669498769768, 6.8197643208907);
        glVertex2f(2.9938455522385, 6.7759343315753);
        glVertex2f(3.0237296358627, 6.737085022864);
        glVertex2f(3.0585944000908, 6.6952473057902);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //Lampu 3
    glPushMatrix();
    glTranslated(lamplvl2[4],2,0);
    glScaled(0.4,0.4,0);
    glPushMatrix();                                     //Bagian bawah tiang
    glColor3ub(112, 76, 52);
    glBegin(GL_QUADS);
        glVertex2f(2.5500573391679, 2.444603574832);
        glVertex2f(2.8189440783599, 2.4433031537679);
        glVertex2f(3.1389820874064, 1.3556678955842);
        glVertex2f(2.2068069454137, 1.3494948414238);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //Tiang
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex2f(2.6843234615626,2.4833156986779);
        glVertex2f(2.6843173416322,5.9471450826595);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //wadah lampu
    glColor3ub(83, 49, 21);
    glBegin(GL_POLYGON);
        glVertex2f(2.3185247708212, 6.9092669253057);
        glVertex2f(2.392021640114, 5.9798329698799);
        glVertex2f(2.4260321685875, 5.9516528177161);
        glVertex2f(2.4668448027557, 5.9225009361674);
        glVertex2f(2.506, 5.9);
        glVertex2f(2.5611308237116, 5.8739144669195);
        glVertex2f(2.6155193986542, 5.8603102555301);
        glVertex2f(2.666049326672, 5.8564233379903);
        glVertex2f(2.7165792546898, 5.8535081498354);
        glVertex2f(2.7729395590173, 5.863225443685);
        glVertex2f(2.8234694870351, 5.8846034901541);
        glVertex2f(2.8817732501326, 5.9137553717028);
        glVertex2f(2.9274445312256, 5.9448507120214);
        glVertex2f(2.9595116009292, 5.9817764286498);
        glVertex2f(3.0397832903166, 6.9095286433506);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //objek lampu
    glColor3ub(239, 172, 21);
    glTranslated(0.006,0,0);
    glBegin(GL_QUADS);
        glVertex2f(2.4428276813169, 6.0511150529822);   //kiri
        glVertex2f(2.3791945456307, 6.8049307737665);
        glVertex2f(2.640874003513, 6.8014240958057);
        glVertex2f(2.640874003513, 6.0511150529822);

        glVertex2f(2.7136013877242, 6.052172598303);    //kanan
        glVertex2f(2.9142668746947, 6.0511967634231);
        glVertex2f(2.9702847412456, 6.8006932745462);
        glVertex2f(2.7136666950167, 6.8021585985759);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //Garis bawah tiang
    glLineWidth(4);
    glColor3ub(83, 49, 21);
    glBegin(GL_LINES);
        glVertex2f(2.1477215158338, 1.3021233538741);
        glVertex2f(3.2017807536256, 1.3028979528192);

        glVertex2f(2.5552056695422, 2.4779478633133);
        glVertex2f(2.8150567058827, 2.4779478633133);

        glVertex2f(2.2978374929653,6.8503477828281);
        glVertex2f(3.0614974005328,6.8503477828281);

        glVertex2f(2.6938011759811,7.4893286517007);
        glVertex2f(2.6938011759811,7.0393171985038);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //tutup wadah lampu
    glColor3ub(112, 76, 52);
    glTranslated(0.01,0.2,0);
    glBegin(GL_POLYGON);
        glVertex2f(2.2699710987605, 6.686215568036);
        glVertex2f(2.3025279888684, 6.7129587277674);
        glVertex2f(2.3315966407504, 6.7513293482517);
        glVertex2f(2.362990784783, 6.7943509530371);
        glVertex2f(2.3978731670415, 6.8478372725001);
        glVertex2f(2.4339182953752, 6.901323591963);
        glVertex2f(2.4711261697842, 6.9489961810495);
        glVertex2f(2.5048458059674, 6.9862040554585);
        glVertex2f(2.5420536803764, 7.0222491837923);
        glVertex2f(2.5723175081348, 7.0410119263117);
        glVertex2f(2.7787756454743, 7.0434504082488);
        glVertex2f(2.8075680976481, 7.0269606340181);
        glVertex2f(2.838448317393, 6.9990688226356);
        glVertex2f(2.8683324010171, 6.9671924667698);
        glVertex2f(2.8982164846413, 6.9233624774544);
        glVertex2f(2.9330812488694, 6.8725595352934);
        glVertex2f(2.9669498769768, 6.8197643208907);
        glVertex2f(2.9938455522385, 6.7759343315753);
        glVertex2f(3.0237296358627, 6.737085022864);
        glVertex2f(3.0585944000908, 6.6952473057902);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //Lampu 4
    glPushMatrix();
    glTranslated(lamplvl2[5],2,0);
    glScaled(0.4,0.4,0);
    glPushMatrix();                                     //Bagian bawah tiang
    glColor3ub(112, 76, 52);
    glBegin(GL_QUADS);
        glVertex2f(2.5500573391679, 2.444603574832);
        glVertex2f(2.8189440783599, 2.4433031537679);
        glVertex2f(3.1389820874064, 1.3556678955842);
        glVertex2f(2.2068069454137, 1.3494948414238);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //Tiang
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex2f(2.6843234615626,2.4833156986779);
        glVertex2f(2.6843173416322,5.9471450826595);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //wadah lampu
    glColor3ub(83, 49, 21);
    glBegin(GL_POLYGON);
        glVertex2f(2.3185247708212, 6.9092669253057);
        glVertex2f(2.392021640114, 5.9798329698799);
        glVertex2f(2.4260321685875, 5.9516528177161);
        glVertex2f(2.4668448027557, 5.9225009361674);
        glVertex2f(2.506, 5.9);
        glVertex2f(2.5611308237116, 5.8739144669195);
        glVertex2f(2.6155193986542, 5.8603102555301);
        glVertex2f(2.666049326672, 5.8564233379903);
        glVertex2f(2.7165792546898, 5.8535081498354);
        glVertex2f(2.7729395590173, 5.863225443685);
        glVertex2f(2.8234694870351, 5.8846034901541);
        glVertex2f(2.8817732501326, 5.9137553717028);
        glVertex2f(2.9274445312256, 5.9448507120214);
        glVertex2f(2.9595116009292, 5.9817764286498);
        glVertex2f(3.0397832903166, 6.9095286433506);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //objek lampu
    glColor3ub(239, 172, 21);
    glTranslated(0.006,0,0);
    glBegin(GL_QUADS);
        glVertex2f(2.4428276813169, 6.0511150529822);   //kiri
        glVertex2f(2.3791945456307, 6.8049307737665);
        glVertex2f(2.640874003513, 6.8014240958057);
        glVertex2f(2.640874003513, 6.0511150529822);

        glVertex2f(2.7136013877242, 6.052172598303);    //kanan
        glVertex2f(2.9142668746947, 6.0511967634231);
        glVertex2f(2.9702847412456, 6.8006932745462);
        glVertex2f(2.7136666950167, 6.8021585985759);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //Garis bawah tiang
    glLineWidth(4);
    glColor3ub(83, 49, 21);
    glBegin(GL_LINES);
        glVertex2f(2.1477215158338, 1.3021233538741);
        glVertex2f(3.2017807536256, 1.3028979528192);

        glVertex2f(2.5552056695422, 2.4779478633133);
        glVertex2f(2.8150567058827, 2.4779478633133);

        glVertex2f(2.2978374929653,6.8503477828281);
        glVertex2f(3.0614974005328,6.8503477828281);

        glVertex2f(2.6938011759811,7.4893286517007);
        glVertex2f(2.6938011759811,7.0393171985038);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //tutup wadah lampu
    glColor3ub(112, 76, 52);
    glTranslated(0.01,0.2,0);
    glBegin(GL_POLYGON);
        glVertex2f(2.2699710987605, 6.686215568036);
        glVertex2f(2.3025279888684, 6.7129587277674);
        glVertex2f(2.3315966407504, 6.7513293482517);
        glVertex2f(2.362990784783, 6.7943509530371);
        glVertex2f(2.3978731670415, 6.8478372725001);
        glVertex2f(2.4339182953752, 6.901323591963);
        glVertex2f(2.4711261697842, 6.9489961810495);
        glVertex2f(2.5048458059674, 6.9862040554585);
        glVertex2f(2.5420536803764, 7.0222491837923);
        glVertex2f(2.5723175081348, 7.0410119263117);
        glVertex2f(2.7787756454743, 7.0434504082488);
        glVertex2f(2.8075680976481, 7.0269606340181);
        glVertex2f(2.838448317393, 6.9990688226356);
        glVertex2f(2.8683324010171, 6.9671924667698);
        glVertex2f(2.8982164846413, 6.9233624774544);
        glVertex2f(2.9330812488694, 6.8725595352934);
        glVertex2f(2.9669498769768, 6.8197643208907);
        glVertex2f(2.9938455522385, 6.7759343315753);
        glVertex2f(3.0237296358627, 6.737085022864);
        glVertex2f(3.0585944000908, 6.6952473057902);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //Lampu 5
    glPushMatrix();
    glTranslated(lamplvl2[6],2,0);
    glScaled(0.4,0.4,0);
    glPushMatrix();                                     //Bagian bawah tiang
    glColor3ub(112, 76, 52);
    glBegin(GL_QUADS);
        glVertex2f(2.5500573391679, 2.444603574832);
        glVertex2f(2.8189440783599, 2.4433031537679);
        glVertex2f(3.1389820874064, 1.3556678955842);
        glVertex2f(2.2068069454137, 1.3494948414238);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //Tiang
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex2f(2.6843234615626,2.4833156986779);
        glVertex2f(2.6843173416322,5.9471450826595);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //wadah lampu
    glColor3ub(83, 49, 21);
    glBegin(GL_POLYGON);
        glVertex2f(2.3185247708212, 6.9092669253057);
        glVertex2f(2.392021640114, 5.9798329698799);
        glVertex2f(2.4260321685875, 5.9516528177161);
        glVertex2f(2.4668448027557, 5.9225009361674);
        glVertex2f(2.506, 5.9);
        glVertex2f(2.5611308237116, 5.8739144669195);
        glVertex2f(2.6155193986542, 5.8603102555301);
        glVertex2f(2.666049326672, 5.8564233379903);
        glVertex2f(2.7165792546898, 5.8535081498354);
        glVertex2f(2.7729395590173, 5.863225443685);
        glVertex2f(2.8234694870351, 5.8846034901541);
        glVertex2f(2.8817732501326, 5.9137553717028);
        glVertex2f(2.9274445312256, 5.9448507120214);
        glVertex2f(2.9595116009292, 5.9817764286498);
        glVertex2f(3.0397832903166, 6.9095286433506);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //objek lampu
    glColor3ub(239, 172, 21);
    glTranslated(0.006,0,0);
    glBegin(GL_QUADS);
        glVertex2f(2.4428276813169, 6.0511150529822);   //kiri
        glVertex2f(2.3791945456307, 6.8049307737665);
        glVertex2f(2.640874003513, 6.8014240958057);
        glVertex2f(2.640874003513, 6.0511150529822);

        glVertex2f(2.7136013877242, 6.052172598303);    //kanan
        glVertex2f(2.9142668746947, 6.0511967634231);
        glVertex2f(2.9702847412456, 6.8006932745462);
        glVertex2f(2.7136666950167, 6.8021585985759);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //Garis bawah tiang
    glLineWidth(4);
    glColor3ub(83, 49, 21);
    glBegin(GL_LINES);
        glVertex2f(2.1477215158338, 1.3021233538741);
        glVertex2f(3.2017807536256, 1.3028979528192);

        glVertex2f(2.5552056695422, 2.4779478633133);
        glVertex2f(2.8150567058827, 2.4779478633133);

        glVertex2f(2.2978374929653,6.8503477828281);
        glVertex2f(3.0614974005328,6.8503477828281);

        glVertex2f(2.6938011759811,7.4893286517007);
        glVertex2f(2.6938011759811,7.0393171985038);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //tutup wadah lampu
    glColor3ub(112, 76, 52);
    glTranslated(0.01,0.2,0);
    glBegin(GL_POLYGON);
        glVertex2f(2.2699710987605, 6.686215568036);
        glVertex2f(2.3025279888684, 6.7129587277674);
        glVertex2f(2.3315966407504, 6.7513293482517);
        glVertex2f(2.362990784783, 6.7943509530371);
        glVertex2f(2.3978731670415, 6.8478372725001);
        glVertex2f(2.4339182953752, 6.901323591963);
        glVertex2f(2.4711261697842, 6.9489961810495);
        glVertex2f(2.5048458059674, 6.9862040554585);
        glVertex2f(2.5420536803764, 7.0222491837923);
        glVertex2f(2.5723175081348, 7.0410119263117);
        glVertex2f(2.7787756454743, 7.0434504082488);
        glVertex2f(2.8075680976481, 7.0269606340181);
        glVertex2f(2.838448317393, 6.9990688226356);
        glVertex2f(2.8683324010171, 6.9671924667698);
        glVertex2f(2.8982164846413, 6.9233624774544);
        glVertex2f(2.9330812488694, 6.8725595352934);
        glVertex2f(2.9669498769768, 6.8197643208907);
        glVertex2f(2.9938455522385, 6.7759343315753);
        glVertex2f(3.0237296358627, 6.737085022864);
        glVertex2f(3.0585944000908, 6.6952473057902);
    glEnd();
    glPopMatrix();
    glPopMatrix();

}

void got() {
    //Got 1
    glPushMatrix();
    glTranslated(gotlvl2[0],0.75,0);
    glScaled(0.2,0.4,0);
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(5.2597674418605, 2.8622621564482);
        glVertex2f(5.5472938689218, 3.1497885835095);
        glVertex2f(5.9363002114165, 3.3696617336152);
        glVertex2f(6.2914799154334, 3.4542283298097);
        glVertex2f(6.6466596194503, 3.5218816067653);
        glVertex2f(7.1033192389006, 3.6064482029598);
        glVertex2f(7.5768921775898, 3.5557082452431);
        glVertex2f(7.9658985200846, 3.4880549682875);
        glVertex2f(8.3210782241015, 3.403488372093);
        glVertex2f(8.6011103545677, 3.3271692261648);
        glVertex2f(8.777821527293, 3.2598506841742);
        glVertex2f(8.9124586112743, 3.1841173244348);
        glVertex2f(9.0891697839996, 3.1083839646954);
        glVertex2f(9.2490513212273, 3.0242357872071);
        glVertex2f(9.3752735874597, 2.9400876097189);
        glVertex2f(9.5603995779338, 2.7297171659982);
        glVertex2f(9.6782070264174, 2.5866652642682);
        glVertex2f(9.7791848394033, 2.4267837270405);
        glVertex2f(9.7960144749009, 2.2837318253105);
        glVertex2f(9.7791848394033, 2.1238502880828);
        glVertex2f(9.7623552039056, 1.9134798443622);
        glVertex2f(9.6361329376732, 1.7620131248833);
        glVertex2f(9.4678365826967, 1.5937167699068);
        glVertex2f(9.3416143164644, 1.4759093214232);
        glVertex2f(9.2069772324831, 1.391761143935);
        glVertex2f(9.0723401485019, 1.2907833309491);
        glVertex2f(8.9292882467719, 1.1898055179632);
        glVertex2f(8.7609918917954, 1.1140721582238);
        glVertex2f(8.5674510835724, 1.0215091629867);
        glVertex2f(8.3570806398518, 0.9710202564937);
        glVertex2f(8.2297290076282, 0.9562267543717);
        glVertex2f(8.0484123302027, 0.9268240499243);
        glVertex2f(7.9210006109308, 0.9219235991831);
        glVertex2f(7.7298830320229, 0.9170231484418);
        glVertex2f(7.4897609457028, 0.9464258528892);
        glVertex2f(7.3378469727247, 0.9611272051129);
        glVertex2f(7.1467293938168, 0.9758285573366);
        glVertex2f(6.9409104626853, 1.0199326140076);
        glVertex2f(6.8085982926721, 1.049335318455);
        glVertex2f(6.6419829674704, 1.0836384736436);
        glVertex2f(6.44106448708, 1.1375434317971);
        glVertex2f(6.289150514102, 1.201249291433);
        glVertex2f(6.0882320337116, 1.2845569540339);
        glVertex2f(5.8775126518388, 1.3874664195997);
        glVertex2f(5.7157977773783, 1.4952763359067);
        glVertex2f(5.6, 1.6);
        glVertex2f(5.4756756910582, 1.6912943655558);
        glVertex2f(5.3531644225275, 1.7942038311216);
        glVertex2f(5.2796576614091, 1.9167150996523);
        glVertex2f(5.1767481958433, 2.0735295233716);
        glVertex2f(5.1130423362073, 2.2401448485733);
        glVertex2f(5.0885400825012, 2.3871583708101);
        glVertex2f(5.1179427869485, 2.5390723437882);
        glVertex2f(5.1816486465845, 2.686085866025);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(66, 65, 64);
    glBegin(GL_POLYGON);
        glVertex2f(6.3923454873985, 2.5098998642797);
        glVertex2f(6.3743134597757, 2.3859597800331);
        glVertex2f(6.3907393661254, 2.2655031334685);
        glVertex2f(6.4126405745917, 2.1669476953703);
        glVertex2f(6.434541783058, 2.0629169551554);
        glVertex2f(6.4947701063403, 1.9096084958914);
        glVertex2f(6.5356394997439, 1.8477665223745);
        glVertex2f(6.5738194760898, 1.7714065696827);
        glVertex2f(6.6362958010194, 1.6950466169909);
        glVertex2f(6.691830312068, 1.6152157573585);
        glVertex2f(6.7577775439382, 1.5388558046667);
        glVertex2f(6.8167829619274, 1.4763794797371);
        glVertex2f(6.9000847285003, 1.3965486201047);
        glVertex2f(6.9833864950732, 1.334072295175);
        glVertex2f(7.0875137032893, 1.2646541563643);
        glVertex2f(7.2, 1.2);
        glVertex2f(7.3061808405431, 1.1501142273266);
        glVertex2f(7.4065524448906, 1.1130644596005);
        glVertex2f(7.5131729454104, 1.0804859733306);
        glVertex2f(7.6257168070702, 1.0360607647806);
        glVertex2f(7.73826066873, 1.0212523619307);
        glVertex2f(7.8478428498198, 0.9886738756607);
        glVertex2f(7.9603867114796, 0.9590570699608);
        glVertex2f(8.0847772954194, 0.9501720282508);
        glVertex2f(8.1825127542292, 0.9472103476808);
        glVertex2f(8.298018296459, 0.9412869865408);
        glVertex2f(8.4016771164088, 0.9501720282508);
        glVertex2f(8.5053359363586, 0.9590570699608);
        glVertex2f(8.6208414785884, 0.9679421116707);
        glVertex2f(8.7511554236682, 0.9916355562307);
        glVertex2f(8.896277771598, 1.0212523619307);
        glVertex2f(9.0117833138278, 1.0390224453506);
        glVertex2f(9.1272888560576, 1.0952943761805);
        glVertex2f(9.2546411205673, 1.1515663070104);
        glVertex2f(9.4, 1.2);
        glVertex2f(9.4915755661669, 1.2670718492402);
        glVertex2f(9.5715409415568, 1.3292671412101);
        glVertex2f(9.6692764003666, 1.40034747489);
        glVertex2f(9.7551651368964, 1.4891978919898);
        glVertex2f(9.8558622762763, 1.5869333507997);
        glVertex2f(9.9328659710961, 1.6994772124595);
        glVertex2f(10, 1.8);
        glVertex2f(10.0454098327559, 1.9186415746391);
        glVertex2f(10.0839116801659, 2.0341471168689);
        glVertex2f(10.0988614374116, 2.1079333979821);
        glVertex2f(10.1091685207787, 2.1826597523934);
        glVertex2f(10.116898833304, 2.2676931901718);
        glVertex2f(10.1091685207787, 2.3707640238425);
        glVertex2f(10.0937078957281, 2.4532206907791);
        glVertex2f(10.0808240415192, 2.5382541285575);
        glVertex2f(10.0576331039433, 2.6207107954941);
        glVertex2f(10.0189815413168, 2.7083210041143);
        glVertex2f(9.9571390411143, 2.8062382961015);
        glVertex2f(9.9107571659625, 2.878387879671);
        glVertex2f(9.8540682074435, 2.9659980882912);
        glVertex2f(9.8025327906082, 3.0252638176518);
        glVertex2f(9.75046078766, 3.0783178726647);
        glVertex2f(9.6938241066652, 3.1319736757124);
        glVertex2f(9.5894933785169, 3.2392852818078);
        glVertex2f(9.431506847321, 3.3495777658502);
        glVertex2f(9.3092908514901, 3.4121762027392);
        glVertex2f(9.1840939777122, 3.4747746396282);
        glVertex2f(9.0618779818814, 3.5314113206229);
        glVertex2f(8.8949488168441, 3.5820862457235);
        glVertex2f(8.7399431635953, 3.6327611708241);
        glVertex2f(8.6564785810767, 3.6506464385067);
        glVertex2f(8.5789757544522, 3.6566081944009);
        glVertex2f(8.507434683722, 3.6655508282421);
        glVertex2f(8.4239701012034, 3.6744934620834);
        glVertex2f(8.316658495108, 3.6804552179776);
        glVertex2f(8.1705954757004, 3.6834360959247);
        glVertex2f(8.0483794798696, 3.6834360959247);
        glVertex2f(7.932125239933, 3.6804552179776);
        glVertex2f(7.8248136338376, 3.6655508282421);
        glVertex2f(7.7264446615835, 3.6446846826125);
        glVertex2f(7.6429800790649, 3.6357420487712);
        glVertex2f(7.550572862705, 3.6059332693003);
        glVertex2f(7.4790317919747, 3.5850671236706);
        glVertex2f(7.4194142330329, 3.564200978041);
        glVertex2f(7.3577611986883, 3.5494223836412);
        glVertex2f(7.2910234040898, 3.5197611415974);
        glVertex2f(7.2440597708538, 3.4950434398943);
        glVertex2f(7.1773219762553, 3.4653821978505);
        glVertex2f(7.127886572849, 3.4431362663176);
        glVertex2f(7.0710358589318, 3.4060597137629);
        glVertex2f(6.9993545239927, 3.3615678506973);
        glVertex2f(6.9326167293942, 3.3244912981425);
        glVertex2f(6.8782377856472, 3.2775276649066);
        glVertex2f(6.8189153015597, 3.2330358018409);
        glVertex2f(6.7694798981534, 3.1934874791158);
        glVertex2f(6.7151009544065, 3.1366367651986);
        glVertex2f(6.6607220106595, 3.0773142811111);
        glVertex2f(6.6088148370829, 3.0254071075344);
        glVertex2f(6.5717382845282, 2.9685563936172);
        glVertex2f(6.5321899618032, 2.8968750586781);
        glVertex2f(6.4926416390781, 2.8251937237389);
        glVertex2f(6.4629803970343, 2.7535123887998);
        glVertex2f(6.4333191549906, 2.6818310538607);
        glVertex2f(6.4, 2.6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
       glVertex2f(8.0034428411906,2.8977740246846);
        glVertex2f(8.0054563257554,2.9649717671241);
        glVertex2f(8.6264452599998,2.9598601763873);
        glVertex2f(8.5459192966993,2.8928517270482);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(8.5459192966993,2.8928517270482);
        glVertex2f(8.6264452599998,2.9598601763873);
        glVertex2f(8.6290833778238,1.9887088963616);
        glVertex2f(8.5416544720263,2.0590785034669);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(8.0000217385489,2.0654757404765);
        glVertex2f(8,2);
        glVertex2f(8.5416544720263,2.0590785034669);
        glVertex2f(8.6290833778238,1.9887088963616);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(6.3923454873985, 2.5098998642797);
        glVertex2f(6.3743134597757, 2.3859597800331);
        glVertex2f(6.3907393661254, 2.2655031334685);
        glVertex2f(6.4126405745917, 2.1669476953703);
        glVertex2f(6.434541783058, 2.0629169551554);
        glVertex2f(6.4947701063403, 1.9096084958914);
        glVertex2f(6.5356394997439, 1.8477665223745);
        glVertex2f(6.5738194760898, 1.7714065696827);
        glVertex2f(6.6362958010194, 1.6950466169909);
        glVertex2f(6.691830312068, 1.6152157573585);
        glVertex2f(6.7577775439382, 1.5388558046667);
        glVertex2f(6.8167829619274, 1.4763794797371);
        glVertex2f(6.9000847285003, 1.3965486201047);
        glVertex2f(6.9833864950732, 1.334072295175);
        glVertex2f(7.0875137032893, 1.2646541563643);
        glVertex2f(7.2, 1.2);
        glVertex2f(7.3061808405431, 1.1501142273266);
        glVertex2f(7.4065524448906, 1.1130644596005);
        glVertex2f(7.5131729454104, 1.0804859733306);
        glVertex2f(7.6257168070702, 1.0360607647806);
        glVertex2f(7.73826066873, 1.0212523619307);
        glVertex2f(7.8478428498198, 0.9886738756607);
        glVertex2f(7.9603867114796, 0.9590570699608);
        glVertex2f(8.0847772954194, 0.9501720282508);
        glVertex2f(8.1825127542292, 0.9472103476808);
        glVertex2f(8.298018296459, 0.9412869865408);
        glVertex2f(8.4016771164088, 0.9501720282508);
        glVertex2f(8.5053359363586, 0.9590570699608);
        glVertex2f(8.6208414785884, 0.9679421116707);
        glVertex2f(8.7511554236682, 0.9916355562307);
        glVertex2f(8.896277771598, 1.0212523619307);
        glVertex2f(9.0117833138278, 1.0390224453506);
        glVertex2f(9.1272888560576, 1.0952943761805);
        glVertex2f(9.2546411205673, 1.1515663070104);
        glVertex2f(9.4, 1.2);
        glVertex2f(9.4915755661669, 1.2670718492402);
        glVertex2f(9.5715409415568, 1.3292671412101);
        glVertex2f(9.6692764003666, 1.40034747489);
        glVertex2f(9.7551651368964, 1.4891978919898);
        glVertex2f(9.8558622762763, 1.5869333507997);
        glVertex2f(9.9328659710961, 1.6994772124595);
        glVertex2f(10, 1.8);
        glVertex2f(10.0454098327559, 1.9186415746391);
        glVertex2f(10.0839116801659, 2.0341471168689);
        glVertex2f(10.0988614374116, 2.1079333979821);
        glVertex2f(10.1091685207787, 2.1826597523934);
        glVertex2f(10.116898833304, 2.2676931901718);
        glVertex2f(10.1091685207787, 2.3707640238425);
        glVertex2f(10.0937078957281, 2.4532206907791);
        glVertex2f(10.0808240415192, 2.5382541285575);
        glVertex2f(10.0576331039433, 2.6207107954941);
        glVertex2f(10.0189815413168, 2.7083210041143);
        glVertex2f(9.9571390411143, 2.8062382961015);
        glVertex2f(9.9107571659625, 2.878387879671);
        glVertex2f(9.8540682074435, 2.9659980882912);
        glVertex2f(9.8025327906082, 3.0252638176518);
        glVertex2f(9.75046078766, 3.0783178726647);
        glVertex2f(9.6938241066652, 3.1319736757124);
        glVertex2f(9.5894933785169, 3.2392852818078);
        glVertex2f(9.431506847321, 3.3495777658502);
        glVertex2f(9.3092908514901, 3.4121762027392);
        glVertex2f(9.1840939777122, 3.4747746396282);
        glVertex2f(9.0618779818814, 3.5314113206229);
        glVertex2f(8.8949488168441, 3.5820862457235);
        glVertex2f(8.7399431635953, 3.6327611708241);
        glVertex2f(8.6564785810767, 3.6506464385067);
        glVertex2f(8.5789757544522, 3.6566081944009);
        glVertex2f(8.507434683722, 3.6655508282421);
        glVertex2f(8.4239701012034, 3.6744934620834);
        glVertex2f(8.316658495108, 3.6804552179776);
        glVertex2f(8.1705954757004, 3.6834360959247);
        glVertex2f(8.0483794798696, 3.6834360959247);
        glVertex2f(7.932125239933, 3.6804552179776);
        glVertex2f(7.8248136338376, 3.6655508282421);
        glVertex2f(7.7264446615835, 3.6446846826125);
        glVertex2f(7.6429800790649, 3.6357420487712);
        glVertex2f(7.550572862705, 3.6059332693003);
        glVertex2f(7.4790317919747, 3.5850671236706);
        glVertex2f(7.4194142330329, 3.564200978041);
        glVertex2f(7.3577611986883, 3.5494223836412);
        glVertex2f(7.2910234040898, 3.5197611415974);
        glVertex2f(7.2440597708538, 3.4950434398943);
        glVertex2f(7.1773219762553, 3.4653821978505);
        glVertex2f(7.127886572849, 3.4431362663176);
        glVertex2f(7.0710358589318, 3.4060597137629);
        glVertex2f(6.9993545239927, 3.3615678506973);
        glVertex2f(6.9326167293942, 3.3244912981425);
        glVertex2f(6.8782377856472, 3.2775276649066);
        glVertex2f(6.8189153015597, 3.2330358018409);
        glVertex2f(6.7694798981534, 3.1934874791158);
        glVertex2f(6.7151009544065, 3.1366367651986);
        glVertex2f(6.6607220106595, 3.0773142811111);
        glVertex2f(6.6088148370829, 3.0254071075344);
        glVertex2f(6.5717382845282, 2.9685563936172);
        glVertex2f(6.5321899618032, 2.8968750586781);
        glVertex2f(6.4926416390781, 2.8251937237389);
        glVertex2f(6.4629803970343, 2.7535123887998);
        glVertex2f(6.4333191549906, 2.6818310538607);
        glVertex2f(6.4, 2.6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(8.0034428411906,2.8977740246846);
        glVertex2f(8.0054563257554,2.9649717671241);
        glVertex2f(8.6264452599998,2.9598601763873);
        glVertex2f(8.5459192966993,2.8928517270482);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(8.5459192966993,2.8928517270482);
        glVertex2f(8.6264452599998,2.9598601763873);
        glVertex2f(8.6290833778238,1.9887088963616);
        glVertex2f(8.5416544720263,2.0590785034669);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(8.0000217385489,2.0654757404765);
        glVertex2f(8,2);
        glVertex2f(8.5416544720263,2.0590785034669);
        glVertex2f(8.6290833778238,1.9887088963616);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //Got 2
    glPushMatrix();
    glTranslated(gotlvl2[1],-0.3,0);
    glScaled(0.2,0.4,0);
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(5.2597674418605, 2.8622621564482);
        glVertex2f(5.5472938689218, 3.1497885835095);
        glVertex2f(5.9363002114165, 3.3696617336152);
        glVertex2f(6.2914799154334, 3.4542283298097);
        glVertex2f(6.6466596194503, 3.5218816067653);
        glVertex2f(7.1033192389006, 3.6064482029598);
        glVertex2f(7.5768921775898, 3.5557082452431);
        glVertex2f(7.9658985200846, 3.4880549682875);
        glVertex2f(8.3210782241015, 3.403488372093);
        glVertex2f(8.6011103545677, 3.3271692261648);
        glVertex2f(8.777821527293, 3.2598506841742);
        glVertex2f(8.9124586112743, 3.1841173244348);
        glVertex2f(9.0891697839996, 3.1083839646954);
        glVertex2f(9.2490513212273, 3.0242357872071);
        glVertex2f(9.3752735874597, 2.9400876097189);
        glVertex2f(9.5603995779338, 2.7297171659982);
        glVertex2f(9.6782070264174, 2.5866652642682);
        glVertex2f(9.7791848394033, 2.4267837270405);
        glVertex2f(9.7960144749009, 2.2837318253105);
        glVertex2f(9.7791848394033, 2.1238502880828);
        glVertex2f(9.7623552039056, 1.9134798443622);
        glVertex2f(9.6361329376732, 1.7620131248833);
        glVertex2f(9.4678365826967, 1.5937167699068);
        glVertex2f(9.3416143164644, 1.4759093214232);
        glVertex2f(9.2069772324831, 1.391761143935);
        glVertex2f(9.0723401485019, 1.2907833309491);
        glVertex2f(8.9292882467719, 1.1898055179632);
        glVertex2f(8.7609918917954, 1.1140721582238);
        glVertex2f(8.5674510835724, 1.0215091629867);
        glVertex2f(8.3570806398518, 0.9710202564937);
        glVertex2f(8.2297290076282, 0.9562267543717);
        glVertex2f(8.0484123302027, 0.9268240499243);
        glVertex2f(7.9210006109308, 0.9219235991831);
        glVertex2f(7.7298830320229, 0.9170231484418);
        glVertex2f(7.4897609457028, 0.9464258528892);
        glVertex2f(7.3378469727247, 0.9611272051129);
        glVertex2f(7.1467293938168, 0.9758285573366);
        glVertex2f(6.9409104626853, 1.0199326140076);
        glVertex2f(6.8085982926721, 1.049335318455);
        glVertex2f(6.6419829674704, 1.0836384736436);
        glVertex2f(6.44106448708, 1.1375434317971);
        glVertex2f(6.289150514102, 1.201249291433);
        glVertex2f(6.0882320337116, 1.2845569540339);
        glVertex2f(5.8775126518388, 1.3874664195997);
        glVertex2f(5.7157977773783, 1.4952763359067);
        glVertex2f(5.6, 1.6);
        glVertex2f(5.4756756910582, 1.6912943655558);
        glVertex2f(5.3531644225275, 1.7942038311216);
        glVertex2f(5.2796576614091, 1.9167150996523);
        glVertex2f(5.1767481958433, 2.0735295233716);
        glVertex2f(5.1130423362073, 2.2401448485733);
        glVertex2f(5.0885400825012, 2.3871583708101);
        glVertex2f(5.1179427869485, 2.5390723437882);
        glVertex2f(5.1816486465845, 2.686085866025);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(66, 65, 64);
    glBegin(GL_POLYGON);
        glVertex2f(6.3923454873985, 2.5098998642797);
        glVertex2f(6.3743134597757, 2.3859597800331);
        glVertex2f(6.3907393661254, 2.2655031334685);
        glVertex2f(6.4126405745917, 2.1669476953703);
        glVertex2f(6.434541783058, 2.0629169551554);
        glVertex2f(6.4947701063403, 1.9096084958914);
        glVertex2f(6.5356394997439, 1.8477665223745);
        glVertex2f(6.5738194760898, 1.7714065696827);
        glVertex2f(6.6362958010194, 1.6950466169909);
        glVertex2f(6.691830312068, 1.6152157573585);
        glVertex2f(6.7577775439382, 1.5388558046667);
        glVertex2f(6.8167829619274, 1.4763794797371);
        glVertex2f(6.9000847285003, 1.3965486201047);
        glVertex2f(6.9833864950732, 1.334072295175);
        glVertex2f(7.0875137032893, 1.2646541563643);
        glVertex2f(7.2, 1.2);
        glVertex2f(7.3061808405431, 1.1501142273266);
        glVertex2f(7.4065524448906, 1.1130644596005);
        glVertex2f(7.5131729454104, 1.0804859733306);
        glVertex2f(7.6257168070702, 1.0360607647806);
        glVertex2f(7.73826066873, 1.0212523619307);
        glVertex2f(7.8478428498198, 0.9886738756607);
        glVertex2f(7.9603867114796, 0.9590570699608);
        glVertex2f(8.0847772954194, 0.9501720282508);
        glVertex2f(8.1825127542292, 0.9472103476808);
        glVertex2f(8.298018296459, 0.9412869865408);
        glVertex2f(8.4016771164088, 0.9501720282508);
        glVertex2f(8.5053359363586, 0.9590570699608);
        glVertex2f(8.6208414785884, 0.9679421116707);
        glVertex2f(8.7511554236682, 0.9916355562307);
        glVertex2f(8.896277771598, 1.0212523619307);
        glVertex2f(9.0117833138278, 1.0390224453506);
        glVertex2f(9.1272888560576, 1.0952943761805);
        glVertex2f(9.2546411205673, 1.1515663070104);
        glVertex2f(9.4, 1.2);
        glVertex2f(9.4915755661669, 1.2670718492402);
        glVertex2f(9.5715409415568, 1.3292671412101);
        glVertex2f(9.6692764003666, 1.40034747489);
        glVertex2f(9.7551651368964, 1.4891978919898);
        glVertex2f(9.8558622762763, 1.5869333507997);
        glVertex2f(9.9328659710961, 1.6994772124595);
        glVertex2f(10, 1.8);
        glVertex2f(10.0454098327559, 1.9186415746391);
        glVertex2f(10.0839116801659, 2.0341471168689);
        glVertex2f(10.0988614374116, 2.1079333979821);
        glVertex2f(10.1091685207787, 2.1826597523934);
        glVertex2f(10.116898833304, 2.2676931901718);
        glVertex2f(10.1091685207787, 2.3707640238425);
        glVertex2f(10.0937078957281, 2.4532206907791);
        glVertex2f(10.0808240415192, 2.5382541285575);
        glVertex2f(10.0576331039433, 2.6207107954941);
        glVertex2f(10.0189815413168, 2.7083210041143);
        glVertex2f(9.9571390411143, 2.8062382961015);
        glVertex2f(9.9107571659625, 2.878387879671);
        glVertex2f(9.8540682074435, 2.9659980882912);
        glVertex2f(9.8025327906082, 3.0252638176518);
        glVertex2f(9.75046078766, 3.0783178726647);
        glVertex2f(9.6938241066652, 3.1319736757124);
        glVertex2f(9.5894933785169, 3.2392852818078);
        glVertex2f(9.431506847321, 3.3495777658502);
        glVertex2f(9.3092908514901, 3.4121762027392);
        glVertex2f(9.1840939777122, 3.4747746396282);
        glVertex2f(9.0618779818814, 3.5314113206229);
        glVertex2f(8.8949488168441, 3.5820862457235);
        glVertex2f(8.7399431635953, 3.6327611708241);
        glVertex2f(8.6564785810767, 3.6506464385067);
        glVertex2f(8.5789757544522, 3.6566081944009);
        glVertex2f(8.507434683722, 3.6655508282421);
        glVertex2f(8.4239701012034, 3.6744934620834);
        glVertex2f(8.316658495108, 3.6804552179776);
        glVertex2f(8.1705954757004, 3.6834360959247);
        glVertex2f(8.0483794798696, 3.6834360959247);
        glVertex2f(7.932125239933, 3.6804552179776);
        glVertex2f(7.8248136338376, 3.6655508282421);
        glVertex2f(7.7264446615835, 3.6446846826125);
        glVertex2f(7.6429800790649, 3.6357420487712);
        glVertex2f(7.550572862705, 3.6059332693003);
        glVertex2f(7.4790317919747, 3.5850671236706);
        glVertex2f(7.4194142330329, 3.564200978041);
        glVertex2f(7.3577611986883, 3.5494223836412);
        glVertex2f(7.2910234040898, 3.5197611415974);
        glVertex2f(7.2440597708538, 3.4950434398943);
        glVertex2f(7.1773219762553, 3.4653821978505);
        glVertex2f(7.127886572849, 3.4431362663176);
        glVertex2f(7.0710358589318, 3.4060597137629);
        glVertex2f(6.9993545239927, 3.3615678506973);
        glVertex2f(6.9326167293942, 3.3244912981425);
        glVertex2f(6.8782377856472, 3.2775276649066);
        glVertex2f(6.8189153015597, 3.2330358018409);
        glVertex2f(6.7694798981534, 3.1934874791158);
        glVertex2f(6.7151009544065, 3.1366367651986);
        glVertex2f(6.6607220106595, 3.0773142811111);
        glVertex2f(6.6088148370829, 3.0254071075344);
        glVertex2f(6.5717382845282, 2.9685563936172);
        glVertex2f(6.5321899618032, 2.8968750586781);
        glVertex2f(6.4926416390781, 2.8251937237389);
        glVertex2f(6.4629803970343, 2.7535123887998);
        glVertex2f(6.4333191549906, 2.6818310538607);
        glVertex2f(6.4, 2.6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
       glVertex2f(8.0034428411906,2.8977740246846);
        glVertex2f(8.0054563257554,2.9649717671241);
        glVertex2f(8.6264452599998,2.9598601763873);
        glVertex2f(8.5459192966993,2.8928517270482);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(8.5459192966993,2.8928517270482);
        glVertex2f(8.6264452599998,2.9598601763873);
        glVertex2f(8.6290833778238,1.9887088963616);
        glVertex2f(8.5416544720263,2.0590785034669);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(8.0000217385489,2.0654757404765);
        glVertex2f(8,2);
        glVertex2f(8.5416544720263,2.0590785034669);
        glVertex2f(8.6290833778238,1.9887088963616);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(6.3923454873985, 2.5098998642797);
        glVertex2f(6.3743134597757, 2.3859597800331);
        glVertex2f(6.3907393661254, 2.2655031334685);
        glVertex2f(6.4126405745917, 2.1669476953703);
        glVertex2f(6.434541783058, 2.0629169551554);
        glVertex2f(6.4947701063403, 1.9096084958914);
        glVertex2f(6.5356394997439, 1.8477665223745);
        glVertex2f(6.5738194760898, 1.7714065696827);
        glVertex2f(6.6362958010194, 1.6950466169909);
        glVertex2f(6.691830312068, 1.6152157573585);
        glVertex2f(6.7577775439382, 1.5388558046667);
        glVertex2f(6.8167829619274, 1.4763794797371);
        glVertex2f(6.9000847285003, 1.3965486201047);
        glVertex2f(6.9833864950732, 1.334072295175);
        glVertex2f(7.0875137032893, 1.2646541563643);
        glVertex2f(7.2, 1.2);
        glVertex2f(7.3061808405431, 1.1501142273266);
        glVertex2f(7.4065524448906, 1.1130644596005);
        glVertex2f(7.5131729454104, 1.0804859733306);
        glVertex2f(7.6257168070702, 1.0360607647806);
        glVertex2f(7.73826066873, 1.0212523619307);
        glVertex2f(7.8478428498198, 0.9886738756607);
        glVertex2f(7.9603867114796, 0.9590570699608);
        glVertex2f(8.0847772954194, 0.9501720282508);
        glVertex2f(8.1825127542292, 0.9472103476808);
        glVertex2f(8.298018296459, 0.9412869865408);
        glVertex2f(8.4016771164088, 0.9501720282508);
        glVertex2f(8.5053359363586, 0.9590570699608);
        glVertex2f(8.6208414785884, 0.9679421116707);
        glVertex2f(8.7511554236682, 0.9916355562307);
        glVertex2f(8.896277771598, 1.0212523619307);
        glVertex2f(9.0117833138278, 1.0390224453506);
        glVertex2f(9.1272888560576, 1.0952943761805);
        glVertex2f(9.2546411205673, 1.1515663070104);
        glVertex2f(9.4, 1.2);
        glVertex2f(9.4915755661669, 1.2670718492402);
        glVertex2f(9.5715409415568, 1.3292671412101);
        glVertex2f(9.6692764003666, 1.40034747489);
        glVertex2f(9.7551651368964, 1.4891978919898);
        glVertex2f(9.8558622762763, 1.5869333507997);
        glVertex2f(9.9328659710961, 1.6994772124595);
        glVertex2f(10, 1.8);
        glVertex2f(10.0454098327559, 1.9186415746391);
        glVertex2f(10.0839116801659, 2.0341471168689);
        glVertex2f(10.0988614374116, 2.1079333979821);
        glVertex2f(10.1091685207787, 2.1826597523934);
        glVertex2f(10.116898833304, 2.2676931901718);
        glVertex2f(10.1091685207787, 2.3707640238425);
        glVertex2f(10.0937078957281, 2.4532206907791);
        glVertex2f(10.0808240415192, 2.5382541285575);
        glVertex2f(10.0576331039433, 2.6207107954941);
        glVertex2f(10.0189815413168, 2.7083210041143);
        glVertex2f(9.9571390411143, 2.8062382961015);
        glVertex2f(9.9107571659625, 2.878387879671);
        glVertex2f(9.8540682074435, 2.9659980882912);
        glVertex2f(9.8025327906082, 3.0252638176518);
        glVertex2f(9.75046078766, 3.0783178726647);
        glVertex2f(9.6938241066652, 3.1319736757124);
        glVertex2f(9.5894933785169, 3.2392852818078);
        glVertex2f(9.431506847321, 3.3495777658502);
        glVertex2f(9.3092908514901, 3.4121762027392);
        glVertex2f(9.1840939777122, 3.4747746396282);
        glVertex2f(9.0618779818814, 3.5314113206229);
        glVertex2f(8.8949488168441, 3.5820862457235);
        glVertex2f(8.7399431635953, 3.6327611708241);
        glVertex2f(8.6564785810767, 3.6506464385067);
        glVertex2f(8.5789757544522, 3.6566081944009);
        glVertex2f(8.507434683722, 3.6655508282421);
        glVertex2f(8.4239701012034, 3.6744934620834);
        glVertex2f(8.316658495108, 3.6804552179776);
        glVertex2f(8.1705954757004, 3.6834360959247);
        glVertex2f(8.0483794798696, 3.6834360959247);
        glVertex2f(7.932125239933, 3.6804552179776);
        glVertex2f(7.8248136338376, 3.6655508282421);
        glVertex2f(7.7264446615835, 3.6446846826125);
        glVertex2f(7.6429800790649, 3.6357420487712);
        glVertex2f(7.550572862705, 3.6059332693003);
        glVertex2f(7.4790317919747, 3.5850671236706);
        glVertex2f(7.4194142330329, 3.564200978041);
        glVertex2f(7.3577611986883, 3.5494223836412);
        glVertex2f(7.2910234040898, 3.5197611415974);
        glVertex2f(7.2440597708538, 3.4950434398943);
        glVertex2f(7.1773219762553, 3.4653821978505);
        glVertex2f(7.127886572849, 3.4431362663176);
        glVertex2f(7.0710358589318, 3.4060597137629);
        glVertex2f(6.9993545239927, 3.3615678506973);
        glVertex2f(6.9326167293942, 3.3244912981425);
        glVertex2f(6.8782377856472, 3.2775276649066);
        glVertex2f(6.8189153015597, 3.2330358018409);
        glVertex2f(6.7694798981534, 3.1934874791158);
        glVertex2f(6.7151009544065, 3.1366367651986);
        glVertex2f(6.6607220106595, 3.0773142811111);
        glVertex2f(6.6088148370829, 3.0254071075344);
        glVertex2f(6.5717382845282, 2.9685563936172);
        glVertex2f(6.5321899618032, 2.8968750586781);
        glVertex2f(6.4926416390781, 2.8251937237389);
        glVertex2f(6.4629803970343, 2.7535123887998);
        glVertex2f(6.4333191549906, 2.6818310538607);
        glVertex2f(6.4, 2.6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(8.0034428411906,2.8977740246846);
        glVertex2f(8.0054563257554,2.9649717671241);
        glVertex2f(8.6264452599998,2.9598601763873);
        glVertex2f(8.5459192966993,2.8928517270482);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(8.5459192966993,2.8928517270482);
        glVertex2f(8.6264452599998,2.9598601763873);
        glVertex2f(8.6290833778238,1.9887088963616);
        glVertex2f(8.5416544720263,2.0590785034669);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(8.0000217385489,2.0654757404765);
        glVertex2f(8,2);
        glVertex2f(8.5416544720263,2.0590785034669);
        glVertex2f(8.6290833778238,1.9887088963616);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void build (){
    glPushMatrix();
    glScaled(1.4,1.4,0);
    glTranslated(buildlvl2,3,0);
    glPushMatrix();                                     //gedung 1
    glColor3ub(69, 125, 237);
    glBegin(GL_QUADS);
        glVertex2f(5.2098282036149,1.0602095754578);
        glVertex2f(5.9633021999187,1.0639212700208);
        glVertex2f(5.9594437483963,2.4439437689042);
        glVertex2f(5.2134426541948,2.4479845633042);
        glVertex2f(5.3749005310316,2.3573489565);
        glVertex2f(5.7589720378031,2.3584995882821);
        glVertex2f(5.7600558089205,2.6404555640209);
        glVertex2f(5.3758036480908,2.6412141444875);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //buat semua jendela
    glPushMatrix();                                     //jendela gedung 1
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.11,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.24,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.37,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.5,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();                                     //jendela 2
    glTranslated(0,-0.3,0);
    glPushMatrix();
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.11,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.24,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.37,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.5,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();                                     //jendela 3
    glTranslated(0,-0.60,0);
    glPushMatrix();
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.11,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.24,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.37,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.5,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();                                     //jendela 4
    glTranslated(0,-0.9,0);
    glPushMatrix();
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.11,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.24,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.37,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.5,0,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.2830683730236,2.336822931058);
        glVertex2f(5.3519685545277,2.336822931058);
        glVertex2f(5.35,2.2);
        glVertex2f(5.2847908775612,2.1990225680497);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-0.9,0);
    glPushMatrix();                                     //gedung 2
    glTranslated(0,0.89,0);
    glColor3ub(35, 45, 130);
    glBegin(GL_POLYGON);
        glVertex2f(5.9634623528866,1.0719181265453);
        glVertex2f(6.4404847963934,1.0700517459928);
        glVertex2f(6.4404847963934,2.7981092499286);
        glVertex2f(5.9634623528866,2.7981092499286);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //jendela
    glTranslated(0.04,1.2,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.9786976028362,1.1173522231178);
        glVertex2f(6.0673945810773,1.1173522231178);
        glVertex2f(6.0673945810773,2.0415599995885);
        glVertex2f(5.9786976028362,2.0415599995885);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //jendela
    glTranslated(0.18,1.2,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.9786976028362,1.1173522231178);
        glVertex2f(6.0673945810773,1.1173522231178);
        glVertex2f(6.0673945810773,2.0415599995885);
        glVertex2f(5.9786976028362,2.0415599995885);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //jendela
    glTranslated(0.32,1.2,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(5.9786976028362,1.1173522231178);
        glVertex2f(6.0673945810773,1.1173522231178);
        glVertex2f(6.0673945810773,2.0415599995885);
        glVertex2f(5.9786976028362,2.0415599995885);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-0.9,0);
    glPushMatrix();                                     //gedung 3
    glTranslated(0.010,0.89,0);
    glColor3ub(125, 134, 212);
    glBegin(GL_POLYGON);
        glVertex2f(6.4331832434100,1.0719181265453);
        glVertex2f(7.2566727162352,1.0719181265453);
        glVertex2f(7.2566727162352,2.0415599995885);
        glVertex2f(6.4331832434100,2.0415599995885);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //jendela
    glTranslated(-0.04,0.85,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(6.6054912044279,1.6560317561836);
        glVertex2f(6.8359829056338,1.6560317561836);
        glVertex2f(6.8359829056338,2.0289994277525);
        glVertex2f(6.6054912044279,2.0289994277525);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.04,0.85,0);
    glColor3ub(0,0,0);
     glBegin(GL_LINE_LOOP);
        glVertex2f(6.6054912044279,1.6560317561836);
        glVertex2f(6.8359829056338,1.6560317561836);
        glVertex2f(6.8359829056338,2.0289994277525);
        glVertex2f(6.6054912044279,2.0289994277525);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //jendela
    glTranslated(0.30,0.85,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(6.6054912044279,1.6560317561836);
        glVertex2f(6.8359829056338,1.6560317561836);
        glVertex2f(6.8359829056338,2.0289994277525);
        glVertex2f(6.6054912044279,2.0289994277525);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.30,0.85,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(6.6054912044279,1.6560317561836);
        glVertex2f(6.8359829056338,1.6560317561836);
        glVertex2f(6.8359829056338,2.0289994277525);
        glVertex2f(6.6054912044279,2.0289994277525);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //jendela
    glTranslated(-0.04,0.39,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(6.6054912044279,1.6560317561836);
        glVertex2f(6.8359829056338,1.6560317561836);
        glVertex2f(6.8359829056338,2.0289994277525);
        glVertex2f(6.6054912044279,2.0289994277525);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.04,0.39,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(6.6054912044279,1.6560317561836);
        glVertex2f(6.8359829056338,1.6560317561836);
        glVertex2f(6.8359829056338,2.0289994277525);
        glVertex2f(6.6054912044279,2.0289994277525);
    glEnd();
    glPopMatrix();

    glPushMatrix();                                     //jendela
    glTranslated(0.3,0.39,0);
    glColor3ub(235, 202, 38);
    glBegin(GL_POLYGON);
        glVertex2f(6.6054912044279,1.6560317561836);
        glVertex2f(6.8359829056338,1.6560317561836);
        glVertex2f(6.8359829056338,2.0289994277525);
        glVertex2f(6.6054912044279,2.0289994277525);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.3,0.39,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(6.6054912044279,1.6560317561836);
        glVertex2f(6.8359829056338,1.6560317561836);
        glVertex2f(6.8359829056338,2.0289994277525);
        glVertex2f(6.6054912044279,2.0289994277525);
    glEnd();
    glPopMatrix();


//garis pembatas jendela1
//garis tegak
    glPushMatrix();
    glTranslated(-0.04,0.85,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(6.720603321615,1.6563551553269);
        glVertex2f(6.720603321615,2.0230196820663);
    glEnd();
    glPopMatrix();

    //garis melintang
    glPushMatrix();
    glTranslated(-0.04,0.86,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(6.5999675012166,1.8934159933251);
        glVertex2f(6.8406893383167,1.8934159933251);
    glEnd();
    glPopMatrix();

    //garis melintang
    glPushMatrix();
    glTranslated(-0.04,0.73,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(6.5999675012166,1.8934159933251);
        glVertex2f(6.8406893383167,1.8934159933251);
    glEnd();
    glPopMatrix();

    //jendela2
    //garis tegak
    glPushMatrix();
    glTranslated(0.29,0.85,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(6.720603321615,1.6563551553269);
        glVertex2f(6.720603321615,2.0230196820663);
    glEnd();
    glPopMatrix();

    //garis melintang
    glPushMatrix();
    glTranslated(0.3,0.86,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(6.5999675012166,1.8934159933251);
    glVertex2f(6.8406893383167,1.8934159933251);
    glEnd();
    glPopMatrix();

    //garis melintang
    glPushMatrix();
    glTranslated(0.3,0.73,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(6.5999675012166,1.8934159933251);
    glVertex2f(6.8406893383167,1.8934159933251);
    glEnd();
    glPopMatrix();

    //jendela3
    //garis tegak
    glPushMatrix();
    glTranslated(-0.04,0.4,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(6.720603321615,1.6563551553269);
        glVertex2f(6.720603321615,2.0230196820663);
    glEnd();
    glPopMatrix();

    //garis melintang
    glPushMatrix();
    glTranslated(-0.03,0.4,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(6.5999675012166,1.8934159933251);
        glVertex2f(6.8406893383167,1.8934159933251);
    glEnd();
    glPopMatrix();

    //garis melintang
    glPushMatrix();
    glTranslated(-0.03,0.26,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(6.5999675012166,1.8934159933251);
        glVertex2f(6.8406893383167,1.8934159933251);
    glEnd();
    glPopMatrix();

    //jendela4
    //garis tegak
    glPushMatrix();
    glTranslated(0.29,0.4,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(6.720603321615,1.6563551553269);
        glVertex2f(6.720603321615,2.0230196820663);
    glEnd();
    glPopMatrix();

    //garis melintang
    glPushMatrix();
    glTranslated(0.3,0.4,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(6.5999675012166,1.8934159933251);
        glVertex2f(6.8406893383167,1.8934159933251);
    glEnd();
    glPopMatrix();

    //garis melintang
    glPushMatrix();
    glTranslated(0.3,0.27,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(6.5999675012166,1.8934159933251);
        glVertex2f(6.8406893383167,1.8934159933251);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

//Void untuk di DisplayFunc
void level2(){
    backgroundlevel2();

    glPushMatrix();
    stars();
    glTranslated(0,-2,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    road2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-0.8,0);
    road();
    glPopMatrix();

    roadline();

    glPushMatrix();
    got();
    glPopMatrix();

    glPushMatrix();
    glTranslated(8,7,0);
    glScaled(0.25,0.25,0);
    blackBird();
    glPopMatrix();

    glPushMatrix();
    glScaled(1,1.4,0);
    glTranslated(-2,-3.05,0);
    build();
    glPopMatrix();

    glPushMatrix();
    lamp();
    glPopMatrix();

    fireball();

    if (heartStatus_bar==3){
        glPushMatrix();
        heart();
        glTranslated(0.5,0,0);
        heart();
        glTranslated(0.5,0,0);
        heart();
        glPopMatrix();
    }if (heartStatus_bar==2){
        glPushMatrix();
        heart();
        glTranslated(0.5,0,0);
        heart();
        glPopMatrix();
    }if (heartStatus_bar==1){
        glPushMatrix();
        heart();
        glPopMatrix();
    }


    glPushMatrix();
    if (fireballStatus_bar==1){
        fireball_status();
    }
    glPopMatrix();

    glPushMatrix();
    if (fireballStatus_bar==2){
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
    }
    glPopMatrix();

    glPushMatrix();
    if (fireballStatus_bar==3){
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
    }
    glPopMatrix();

    glPushMatrix();
    if (fireballStatus_bar==4){
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
    }
    glPopMatrix();

    glPushMatrix();
    if (fireballStatus_bar==5){
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
    }
    glPopMatrix();



}

//Level 3
void backgroundlevel3(){
    glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(10,0);
        glColor3ub(249, 188, 46);
        glVertex2f(10,10);
        glVertex2f(0,10);
    glEnd();
    glPopMatrix();
}

void roadlevel3 (){
    glPushMatrix();                         //DIV jalan
    glColor3ub(94, 80, 71);
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(100, 0);
        glVertex2f(100, 3.1734195044442);
        glVertex2f(0, 3.1734195044442);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis atas jalan warna hitam
    glColor3ub(126, 113, 80);
    glBegin(GL_POLYGON);
        glVertex2f(100, 3.1734195044442);
        glVertex2f(0, 3.1734195044442);
        glVertex2f(0, 3.0734195044442);
        glVertex2f(100, 3.0734195044442);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis tengah jalan warna putih
    glTranslated(marka[0],1.2,0);
    glColor3ub(185, 125, 72);
    glBegin(GL_POLYGON);
        glVertex2f(0.111809588206, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.7078144679268);
        glVertex2f(0.111809588206, 0.7078144679268);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis tengah jalan warna putih
    glTranslated(marka[1],1.2,0);
    glColor3ub(185, 125, 72);
    glBegin(GL_POLYGON);
        glVertex2f(0.111809588206, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.7078144679268);
        glVertex2f(0.111809588206, 0.7078144679268);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis tengah jalan warna putih
    glTranslated(marka[2],1.2,0);
    glColor3ub(185, 125, 72);
    glBegin(GL_POLYGON);
        glVertex2f(0.111809588206, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.7078144679268);
        glVertex2f(0.111809588206, 0.7078144679268);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis tengah jalan warna putih
    glTranslated(marka[3],1.2,0);
    glColor3ub(185, 125, 72);
    glBegin(GL_POLYGON);
        glVertex2f(0.111809588206, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.7078144679268);
        glVertex2f(0.111809588206, 0.7078144679268);
    glEnd();
    glPopMatrix();

    glPushMatrix();                   //Garis tengah jalan warna putih
    glTranslated(marka[4],1.2,0);
    glColor3ub(185, 125, 72);
    glBegin(GL_POLYGON);
        glVertex2f(0.111809588206, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.7078144679268);
        glVertex2f(0.111809588206, 0.7078144679268);
    glEnd();
    glPopMatrix();

    glPushMatrix();                         //Garis tengah jalan warna putih
    glTranslated(marka[5],1.2,0);
    glColor3ub(185, 125, 72);
    glBegin(GL_POLYGON);
        glVertex2f(0.111809588206, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.5969561258988);
        glVertex2f(1.1095346664577, 0.7078144679268);
        glVertex2f(0.111809588206, 0.7078144679268);
    glEnd();
    glPopMatrix();

}

void kaktus() {
    glPushMatrix();
    glScaled(0.25,0.25,0);
    glPushMatrix();
    glTranslated(0.05,-0.05,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(4.5857688892885, 3.5537631653282);
        glVertex2f(4.5696784188243, 6.2140542820836);
        glVertex2f(4.7144926530025, 6.2194177722384);
        glVertex2f(4.7198561431573, 6.3695954965713);
        glVertex2f(4.8528216296048, 6.3684737291502);
        glVertex2f(4.8490796808459, 6.4994419357137);
        glVertex2f(5, 6.5);
        glVertex2f(4.9987576312042, 6.3609898316323);
        glVertex2f(5.1259838890088, 6.3460220365964);
        glVertex2f(5.1297258377678, 6.2187957787918);
        glVertex2f(5.2681779418492, 6.2150538300329);
        glVertex2f(5.2580689988387,3.5561721748859);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(4.6045812093472, 4.9611140030737);
        glVertex2f(4.0249188603411, 4.9599748858868);
        glVertex2f(4.0176770306045, 5.1023975373719);
        glVertex2f(3.8782661429533, 5.0955108854379);
        glVertex2f(3.8811256510887, 5.7932308704777);
        glVertex2f(4, 5.8);
        glVertex2f(4.005607314377, 5.9327940138274);
        glVertex2f(4.1552717955986, 5.9327940138274);
        glVertex2f(4.1504439091076, 5.8000271353244);
        glVertex2f(4.2904526173472, 5.7927853055878);
        glVertex2f(4.2904526173472, 5.3703452376236);
        glVertex2f(4.5897815797905, 5.363103407887);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(5.2558439663356, 4.6826260060134);
        glVertex2f(5.832363901875, 4.6914278370903);
        glVertex2f(5.8301634441057, 4.8168539299367);
        glVertex2f(5.9667175662422, 4.8155336552751);
        glVertex2f(5.9667175662422, 5.510333435096);
        glVertex2f(5.8297862227738, 5.5154049663356);
        glVertex2f(5.8348577540134, 5.6472647785643);
        glVertex2f(5.6903191136857, 5.6498005441841);
        glVertex2f(5.6903191136857, 5.510333435096);
        glVertex2f(5.5609950670767, 5.5128692007158);
        glVertex2f(5.5609950670767, 5.0995394046909);
        glVertex2f(5.2567031927026, 5.0893963422118);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(11, 128, 39);
    glBegin(GL_POLYGON);
        glVertex2f(4.5857688892885, 3.5537631653282);
        glVertex2f(4.5696784188243, 6.2140542820836);
        glVertex2f(4.7144926530025, 6.2194177722384);
        glVertex2f(4.7198561431573, 6.3695954965713);
        glVertex2f(4.8528216296048, 6.3684737291502);
        glVertex2f(4.8490796808459, 6.4994419357137);
        glVertex2f(5, 6.5);
        glVertex2f(4.9987576312042, 6.3609898316323);
        glVertex2f(5.1259838890088, 6.3460220365964);
        glVertex2f(5.1297258377678, 6.2187957787918);
        glVertex2f(5.2681779418492, 6.2150538300329);
        glVertex2f(5.2580689988387,3.5561721748859);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(4.6045812093472, 4.9611140030737);
        glVertex2f(4.0249188603411, 4.9599748858868);
        glVertex2f(4.0176770306045, 5.1023975373719);
        glVertex2f(3.8782661429533, 5.0955108854379);
        glVertex2f(3.8811256510887, 5.7932308704777);
        glVertex2f(4, 5.8);
        glVertex2f(4.005607314377, 5.9327940138274);
        glVertex2f(4.1552717955986, 5.9327940138274);
        glVertex2f(4.1504439091076, 5.8000271353244);
        glVertex2f(4.2904526173472, 5.7927853055878);
        glVertex2f(4.2904526173472, 5.3703452376236);
        glVertex2f(4.5897815797905, 5.363103407887);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(5.2558439663356, 4.6826260060134);
        glVertex2f(5.832363901875, 4.6914278370903);
        glVertex2f(5.8301634441057, 4.8168539299367);
        glVertex2f(5.9667175662422, 4.8155336552751);
        glVertex2f(5.9667175662422, 5.510333435096);
        glVertex2f(5.8297862227738, 5.5154049663356);
        glVertex2f(5.8348577540134, 5.6472647785643);
        glVertex2f(5.6903191136857, 5.6498005441841);
        glVertex2f(5.6903191136857, 5.510333435096);
        glVertex2f(5.5609950670767, 5.5128692007158);
        glVertex2f(5.5609950670767, 5.0995394046909);
        glVertex2f(5.2567031927026, 5.0893963422118);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void kaktusposition(){

    glPushMatrix();
    glTranslated(kaktuslvl3[0],1.5,0);
    kaktus();
    glPopMatrix();

    glPushMatrix();
    glTranslated(kaktuslvl3[1],1.5,0);
    kaktus();
    glPopMatrix();

    glPushMatrix();
    glTranslated(kaktuslvl3[2],1.5,0);
    kaktus();
    glPopMatrix();

    glPushMatrix();
    glTranslated(kaktuslvl3[3],1.5,0);
    kaktus();
    glPopMatrix();

    glPushMatrix();
    glTranslated(kaktuslvl3[4],1.5,0);
    kaktus();
    glPopMatrix();
}

void sandMountain() {

    /////////////////////////bentuk kanan pojok bawah//////
    glPushMatrix();
    glColor3ub(156, 86, 22);
    glBegin(GL_POLYGON);
        glVertex2f(12, 1);
        glVertex2f(1, 1);
        glVertex2f(11.9933028628485, 2.3481173357989);
        glVertex2f(11.7436478581712, 2.3405520326268);
        glVertex2f(11.4939928534939, 2.3254214262827);
        glVertex2f(11.3087794046711, 2.3184595578783);
        glVertex2f(11.0924283506082, 2.3084741246138);
        glVertex2f(10.9459753293964, 2.2918317358398);
        glVertex2f(10.809507741449, 2.2751893470657);
        glVertex2f(10.6197845094246, 2.2552184805368);
        glVertex2f(10.4467036661743, 2.2385760917627);
        glVertex2f(10.290265211698, 2.2219337029887);
        glVertex2f(10.1105274129381, 2.1919774031953);
        glVertex2f(9.9341180919329, 2.1753350144213);
        glVertex2f(9.7477233376634, 2.1553641478924);
        glVertex2f(9.6345550939997, 2.1387217591183);
        glVertex2f(9.4914305505427, 2.1187508925894);
        glVertex2f(9.3682768736146, 2.0921230705509);
        glVertex2f(9.2584371077057, 2.0788091595317);
        glVertex2f(9.128626475268, 2.0521813374932);
        glVertex2f(9.0154582316043, 2.0388674264739);
        glVertex2f(8.9089469434503, 2.0222250376998);
        glVertex2f(8.8, 2);
        glVertex2f(8.6809147758832, 1.9927993599671);
        glVertex2f(8.5599202330041, 1.9708003521709);
        glVertex2f(8.4471753180486, 1.9460514684002);
        glVertex2f(8.3096815193224, 1.9323020885276);
        glVertex2f(8.1584383407236, 1.9103030807314);
        glVertex2f(8.0099450380993, 1.8938038248842);
        glVertex2f(7.8697013633985, 1.8800544450116);
        glVertex2f(7.7459569445449, 1.8525556852664);
        glVertex2f(7.5782145100989, 1.8333065534447);
        glVertex2f(7.4, 1.8);
        glVertex2f(7.2317301373089, 1.7783090339542);
        glVertex2f(7.1024859665062, 1.7535601501835);
        glVertex2f(6.9567425398564, 1.7370608943363);
        glVertex2f(6.791749981385, 1.7095621345911);
        glVertex2f(6.6845048183785, 1.6848132508204);
        glVertex2f(6.536437023468, 1.6514872614992);
        glVertex2f(6.3430123654836, 1.6136433066761);
        glVertex2f(6.1201535204146, 1.5800042357223);
        glVertex2f(5.9141142108224, 1.5673895841146);
        glVertex2f(5.6113625722381, 1.5463651647685);
        glVertex2f(5.3590695400845, 1.53795539703);
        glVertex2f(5.1193911595385, 1.5337505131608);
        glVertex2f(4.8839176628618, 1.5295456292916);
        glVertex2f(4.534912301716, 1.5127260938147);
        glVertex2f(4.1985215921778, 1.5127260938147);
        glVertex2f(3.8411064632935, 1.5421602808993);
        glVertex2f(3.5888134311399, 1.5547749325069);
        glVertex2f(3.3503278341741, 1.5527071359254);
        glVertex2f(3.1430707436464, 1.5527071359254);
        glVertex2f(2.9740765006008, 1.5622728477959);
        glVertex2f(2.7636308394496, 1.5718385596664);
        glVertex2f(2.601013737651, 1.5718385596664);
        glVertex2f(2.4790321838898, 1.5759001048972);
        glVertex2f(2.4017060567622, 1.5777861079979);
        glVertex2f(2.2960898831245, 1.5796721110985);
        glVertex2f(2.1942457156882, 1.5834441172999);
        glVertex2f(2.0697695110438, 1.5891021266019);
        glVertex2f(1.9603813312047, 1.5966461390046);
        glVertex2f(1.8722703844087, 1.5992143845792);
        glVertex2f(1.7868690459428, 1.6023041483066);
        glVertex2f(1.7, 1.6);
        glVertex2f(1.6, 1.6);
        glVertex2f(1.5105410703662, 1.5930032516093);
        glVertex2f(1.4, 1.6);
        glVertex2f(1.3117340501329, 1.6123990584614);
        glVertex2f(1.2317263468682, 1.6220969618874);
        glVertex2f(1.1492941677471, 1.6317948653134);
        glVertex2f(1.0692864644824, 1.6342193411699);
        glVertex2f(0.9998399520319, 1.6381382072194);
    glEnd();
    glPopMatrix();

/////////////////////gambar kiri pojok bawah////
    glPushMatrix();
    glColor3ub(173, 110, 50);
    glBegin(GL_POLYGON);
    glVertex2f(1, 1);
        glVertex2f(7, 1);
        glVertex2f(6.9089705098427, 1.0283986881216);
        glVertex2f(6.8346274803317, 1.0524508447281);
        glVertex2f(6.7690306895867, 1.0699433222601);
        glVertex2f(6.7034338988417, 1.0896223594836);
        glVertex2f(6.6356505484052, 1.1136745160901);
        glVertex2f(6.5591209592026, 1.1377266726966);
        glVertex2f(6.4869644893831, 1.1683385083777);
        glVertex2f(6.4, 1.2);
        glVertex2f(6.3433750639389, 1.2153095634421);
        glVertex2f(6.2766937394735, 1.2444826428957);
        glVertex2f(6.2090073928275, 1.2643146876387);
        glVertex2f(6.1653161391651, 1.2813057307297);
        glVertex2f(6.0949246749312, 1.3031513575609);
        glVertex2f(6.0390969619181, 1.3249969843921);
        glVertex2f(5.9556304843485, 1.3498229627722);
        glVertex2f(5.874041114749, 1.378397405535);
        glVertex2f(5.8, 1.4);
        glVertex2f(5.7438949930499, 1.4195828870854);
        glVertex2f(5.6944724151895, 1.4409993374915);
        glVertex2f(5.6483446758532, 1.4574735301117);
        glVertex2f(5.5956272594688, 1.4739477227318);
        glVertex2f(5.5494995201324, 1.4904219153519);
        glVertex2f(5.5, 1.5);
        glVertex2f(5.4440646873635, 1.5316073969023);
        glVertex2f(5.3590695400845, 1.53795539703);
        glVertex2f(5.1193911595385, 1.5337505131608);
        glVertex2f(4.8839176628618, 1.5295456292916);
        glVertex2f(4.534912301716, 1.5127260938147);
        glVertex2f(4.1985215921778, 1.5127260938147);
        glVertex2f(3.8411064632935, 1.5421602808993);
        glVertex2f(3.5888134311399, 1.5547749325069);
        glVertex2f(3.3503278341741, 1.5527071359254);
        glVertex2f(3.1430707436464, 1.5527071359254);
        glVertex2f(2.9740765006008, 1.5622728477959);
        glVertex2f(2.7636308394496, 1.5718385596664);
        glVertex2f(2.601013737651, 1.5718385596664);
        glVertex2f(2.4790321838898, 1.5759001048972);
        glVertex2f(2.4017060567622, 1.5777861079979);
        glVertex2f(2.2960898831245, 1.5796721110985);
        glVertex2f(2.1942457156882, 1.5834441172999);
        glVertex2f(2.0697695110438, 1.5891021266019);
        glVertex2f(1.9603813312047, 1.5966461390046);
        glVertex2f(1.8722703844087, 1.5992143845792);
        glVertex2f(1.7868690459428, 1.6023041483066);
        glVertex2f(1.7, 1.6);
        glVertex2f(1.6, 1.6);
        glVertex2f(1.5105410703662, 1.5930032516093);
        glVertex2f(1.4, 1.6);
        glVertex2f(1.3117340501329, 1.6123990584614);
        glVertex2f(1.2317263468682, 1.6220969618874);
        glVertex2f(1.1492941677471, 1.6317948653134);
        glVertex2f(1.0692864644824, 1.6342193411699);
        glVertex2f(0.9998399520319, 1.6381382072194);
    glEnd();
    glPopMatrix();

    //////////////////////////////gambar tengah di kanan///////
    glPushMatrix();
    glColor3ub(36, 18, 2);
    glBegin(GL_POLYGON);
        glVertex2f(3.2810437156454, 1.5570589368881);
        glVertex2f(3.5017597756919, 1.6406635050875);
        glColor3ub(196, 116, 43);
        glVertex2f(3.6121178057151, 1.6908262460072);
        glVertex2f(3.7224758357383, 1.7343006214709);
        glVertex2f(3.8127687693936, 1.7610540832947);
        glVertex2f(3.9, 1.8);
        glVertex2f(3.9943907263713, 1.8363517321963);
        glVertex2f(4.0687819451795, 1.8635331390685);
        glVertex2f(4.1331589614557, 1.889283945579);
        glVertex2f(4.2333009867744, 1.9307713560682);
        glColor3ub(196, 116, 43);
        glVertex2f(4.3320124117313, 1.9751199672807);
        glVertex2f(4.4421686395818, 2.0237603795783);
        glVertex2f(4.5451718656239, 2.0695395911526);
        glVertex2f(4.6667728963679, 2.1310554067054);
        glVertex2f(4.8141247336225, 2.1968630233434);
        glVertex2f(4.9543235690686, 2.2641012403431);
        glVertex2f(5.0501737933022, 2.2984356490237);
        glVertex2f(5.1680258123556, 2.3452154307435);
        glVertex2f(5.3263533200653, 2.4134600461356);
        glVertex2f(5.4464638431554, 2.4735153076807);
        glVertex2f(5.6102509200965, 2.5417599230728);
        glVertex2f(5.8067954124258, 2.6318428153904);
        glVertex2f(5.9924207662924, 2.7137363538609);
        glVertex2f(6.1507482740021, 2.781980969253);
        glVertex2f(6.2872375047863, 2.825657523104);
        glVertex2f(6.437375658649, 2.8720638615706);
        glVertex2f(6.592973381743, 2.9211999846529);
        glVertex2f(6.7294626125272, 2.9566871846568);
        glVertex2f(6.8550327048487, 2.9867148154294);
        glVertex2f(6.9731358896113, 3.0186337914285);
        glVertex2f(7.0856310164641, 3.0461836184129);
        glVertex2f(7.2004219622322, 3.0714376264819);
        glVertex2f(7.312917089085, 3.0966916345508);
        glVertex2f(7.4254122159378, 3.1127623669584);
        glVertex2f(7.5333157049599, 3.1242414615352);
        glVertex2f(7.6412191939819, 3.135720556112);
        glVertex2f(7.7628975964962, 3.1403121939427);
        glVertex2f(7.8547303531107, 3.1494954696042);
        glVertex2f(7.9810003934556, 3.1586787452656);
        glVertex2f(8.0797206068162, 3.1678620209271);
        glVertex2f(8.1899199147537, 3.1678620209271);
        glVertex2f(8.3494717087483, 3.1718739557177);
        glVertex2f(8.4762590611857, 3.1687042719068);
        glVertex2f(8.6284038841106, 3.1655345880958);
        glVertex2f(8.7445583036386, 3.1579772986926);
        glVertex2f(8.8890956767938, 3.1526240626498);
        glVertex2f(9.0496927580772, 3.1365643545214);
        glVertex2f(9.2076132213393, 3.1151514103503);
        glVertex2f(9.3575038305372, 3.1044449382648);
        glVertex2f(9.5106666739827, 3.1006863044691);
        glVertex2f(9.6593172511369, 3.0929974815128);
        glVertex2f(9.7900272413932, 3.0776198356003);
        glVertex2f(9.9284260546058, 3.0724939536295);
        glVertex2f(10.028380753037, 3.0622421896878);
        glVertex2f(10.1232095694975, 3.0519904257462);
        glVertex2f(10.2385419138413, 3.0366127798336);
        glVertex2f(10.3359336712871, 3.0237980749066);
        glVertex2f(10.4922730713976, 3.0032945470232);
        glVertex2f(10.6255460026393, 2.9827910191399);
        glVertex2f(10.8382701044289, 2.946909845344);
        glVertex2f(10.9561653897581, 2.916154553519);
        glVertex2f(11.0663718521311, 2.9059027895774);
        glVertex2f(11.1637636095769, 2.885399261694);
        glVertex2f(11.2355259571686, 2.8725845567669);
        glVertex2f(11.3636730064395, 2.8572069108544);
        glVertex2f(11.4456871179728, 2.8367033829711);
        glVertex2f(11.5738341672437, 2.8059480911461);
        glVertex2f(11.6917294525729, 2.7803186812919);
        glVertex2f(11.8455059116979, 2.7470004484815);
        glVertex2f(11.9890306068813, 2.7239339796127);
        glVertex2f(11.9933028628485, 2.3481173357989);
        glVertex2f(11.7436478581712, 2.3405520326268);
        glVertex2f(11.4939928534939, 2.3254214262827);
        glVertex2f(11.3087794046711, 2.3184595578783);
        glVertex2f(11.0924283506082, 2.3084741246138);
        glVertex2f(10.9459753293964, 2.2918317358398);
        glVertex2f(10.809507741449, 2.2751893470657);
        glVertex2f(10.6197845094246, 2.2552184805368);
        glVertex2f(10.4467036661743, 2.2385760917627);
        glVertex2f(10.290265211698, 2.2219337029887);
        glVertex2f(10.1105274129381, 2.1919774031953);
        glVertex2f(9.9341180919329, 2.1753350144213);
        glVertex2f(9.7477233376634, 2.1553641478924);
        glVertex2f(9.6345550939997, 2.1387217591183);
        glVertex2f(9.4914305505427, 2.1187508925894);
        glVertex2f(9.3682768736146, 2.0921230705509);
        glVertex2f(9.2584371077057, 2.0788091595317);
        glVertex2f(9.128626475268, 2.0521813374932);
        glVertex2f(9.0154582316043, 2.0388674264739);
        glVertex2f(8.9089469434503, 2.0222250376998);
        glVertex2f(8.8, 2);
        glVertex2f(8.6809147758832, 1.9927993599671);
        glVertex2f(8.5599202330041, 1.9708003521709);
        glVertex2f(8.4471753180486, 1.9460514684002);
        glVertex2f(8.3096815193224, 1.9323020885276);
        glVertex2f(8.1584383407236, 1.9103030807314);
        glVertex2f(8.0099450380993, 1.8938038248842);
        glVertex2f(7.8697013633985, 1.8800544450116);
        glVertex2f(7.7459569445449, 1.8525556852664);
        glVertex2f(7.5782145100989, 1.8333065534447);
        glVertex2f(7.4, 1.8);
        glVertex2f(7.2317301373089, 1.7783090339542);
        glVertex2f(7.1024859665062, 1.7535601501835);
        glVertex2f(6.9567425398564, 1.7370608943363);
        glVertex2f(6.791749981385, 1.7095621345911);
        glVertex2f(6.6845048183785, 1.6848132508204);
        glVertex2f(6.536437023468, 1.6514872614992);
        glVertex2f(6.3430123654836, 1.6136433066761);
        glVertex2f(6.1201535204146, 1.5800042357223);
        glVertex2f(5.9141142108224, 1.5673895841146);
        glVertex2f(5.6113625722381, 1.5463651647685);
        glVertex2f(5.3590695400845, 1.53795539703);
        glVertex2f(5.1193911595385, 1.5337505131608);
        glVertex2f(4.8839176628618, 1.5295456292916);
        glVertex2f(4.534912301716, 1.5127260938147);
        glVertex2f(4.1985215921778, 1.5127260938147);
        glVertex2f(3.8411064632935, 1.5421602808993);
        glVertex2f(3.5888134311399, 1.5547749325069);
        glVertex2f(3.3503278341741, 1.5527071359254);
    glEnd();
    glPopMatrix();

    ///////gambat tengah kiriii///////
    glPushMatrix();
    glColor3ub(161, 102, 48);
    glBegin(GL_POLYGON);
        glVertex2f(1.0047117259507, 2.0502405671948);
        glVertex2f(1.1184062926167, 2.0731456682182);
        glVertex2f(1.2556839307135, 2.0891081842759);
        glVertex2f(1.3386890142139, 2.1050707003337);
        glVertex2f(1.4153090912913, 2.1210332163915);
        glVertex2f(1.4983141747917, 2.1338032292377);
        glVertex2f(1.5940892711383, 2.1593432549301);
        glVertex2f(1.7154043931774, 2.1721132677763);
        glVertex2f(1.8271420055818, 2.1880757838341);
        glVertex2f(1.9452646244093, 2.2136158095265);
        glVertex2f(2.0857347657177, 2.2263858223728);
        glVertex2f(2.1878948684874, 2.2359633320074);
        glVertex2f(2.3539050354883, 2.2710808673345);
        glVertex2f(2.4816051639505, 2.2742733705461);
        glVertex2f(2.5741877570855, 2.2870433833923);
        glVertex2f(2.7114653951824, 2.3125834090847);
        glVertex2f(2.8487430332792, 2.3381234347772);
        glVertex2f(2.9924056777992, 2.3540859508349);
        glVertex2f(3.2509984379351, 2.3796259765274);
        glVertex2f(3.4361636242053, 2.4115510086429);
        glVertex2f(3.6149438040523, 2.4275135247007);
        glVertex2f(3.7107189003989, 2.44666854397);
        glVertex2f(3.844786121203, 2.4610218230641);
        glVertex2f(3.9685280840457, 2.4733960193483);
        glVertex2f(4.0984571450305, 2.4857702156326);
        glVertex2f(4.2376668532284, 2.5012379609879);
        glVertex2f(4.3830636595686, 2.5105186082011);
        glVertex2f(4.5501153094061, 2.5259863535564);
        glVertex2f(4.7388218027412, 2.5631089424092);
        glVertex2f(4.8749379618681, 2.5754831386935);
        glVertex2f(5, 2.6);
        glVertex2f(5.1224218875534, 2.6126057275463);
        glVertex2f(5.2492573994671, 2.6280734729016);
        glVertex2f(5.335876773457, 2.6404476691859);
        glVertex2f(5.4688993835128, 2.6528218654702);
        glVertex2f(5.5833606991423, 2.6713831598966);
        glVertex2f(5.6854478184875, 2.6806638071098);
        glVertex2f(5.7906284869037, 2.6837573561808);
        glVertex2f(5.8927156062489, 2.693038003394);
        glVertex2f(5.9391188423149, 2.6868509052519);
        glVertex2f(5.8067954124258, 2.6318428153904);
        glVertex2f(5.6102509200965, 2.5417599230728);
        glVertex2f(5.4464638431554, 2.4735153076807);
        glVertex2f(5.3263533200653, 2.4134600461356);
        glVertex2f(5.1680258123556, 2.3452154307435);
        glVertex2f(5.0501737933022, 2.2984356490237);
        glVertex2f(4.9543235690686, 2.2641012403431);
        glVertex2f(4.8141247336225, 2.1968630233434);
        glVertex2f(4.6667728963679, 2.1310554067054);
        glVertex2f(4.5451718656239, 2.0695395911526);
        glVertex2f(4.4421686395818, 2.0237603795783);
        glVertex2f(4.3320124117313, 1.9751199672807);
        glVertex2f(4.2333009867744, 1.9307713560682);
        glVertex2f(4.1331589614557, 1.889283945579);
        glVertex2f(4.0687819451795, 1.8635331390685);
        glVertex2f(3.9943907263713, 1.8363517321963);
        glVertex2f(3.9, 1.8);
        glVertex2f(3.8127687693936, 1.7610540832947);
        glVertex2f(3.7224758357383, 1.7343006214709);
        glVertex2f(3.6121178057151, 1.6908262460072);
        glVertex2f(3.5017597756919, 1.6406635050875);
        glVertex2f(3.2810437156454, 1.5570589368881);
        glVertex2f(3.1430707436464, 1.5527071359254);
        glVertex2f(2.9740765006008, 1.5622728477959);
        glVertex2f(2.7636308394496, 1.5718385596664);
        glVertex2f(2.601013737651, 1.5718385596664);
        glVertex2f(2.4790321838898, 1.5759001048972);
        glVertex2f(2.4017060567622, 1.5777861079979);
        glVertex2f(2.2960898831245, 1.5796721110985);
        glVertex2f(2.1942457156882, 1.5834441172999);
        glVertex2f(2.0697695110438, 1.5891021266019);
        glVertex2f(1.9603813312047, 1.5966461390046);
        glVertex2f(1.8722703844087, 1.5992143845792);
        glVertex2f(1.7868690459428, 1.6023041483066);
        glVertex2f(1.7, 1.6);
        glVertex2f(1.6, 1.6);
        glVertex2f(1.5105410703662, 1.5930032516093);
        glVertex2f(1.4, 1.6);
        glVertex2f(1.3117340501329, 1.6123990584614);
        glVertex2f(1.2317263468682, 1.6220969618874);
        glVertex2f(1.1492941677471, 1.6317948653134);
        glVertex2f(1.0692864644824, 1.6342193411699);
        glVertex2f(0.9998399520319, 1.6381382072194);
    glEnd();
    glPopMatrix();

    ///////gambar kiri pojok atas///////////
    glPushMatrix();
    glColor3ub(36, 18, 2);
    glBegin(GL_POLYGON);
        glVertex2f(1.0047117259507, 2.0502405671948);
        glVertex2f(1.1184062926167, 2.0731456682182);
        glVertex2f(1.2556839307135, 2.0891081842759);
        glVertex2f(1.3386890142139, 2.1050707003337);
        glVertex2f(1.4153090912913, 2.1210332163915);
        glVertex2f(1.4983141747917, 2.1338032292377);
        glVertex2f(1.5940892711383, 2.1593432549301);
        glVertex2f(1.7154043931774, 2.1721132677763);
        glVertex2f(1.8271420055818, 2.1880757838341);
        glVertex2f(1.9452646244093, 2.2136158095265);
        glColor3ub(186, 116, 52);
        glVertex2f(2.0857347657177, 2.2263858223728);
        glVertex2f(2.1878948684874, 2.2359633320074);
        glVertex2f(2.3539050354883, 2.2710808673345);
        glVertex2f(2.4816051639505, 2.2742733705461);
        glVertex2f(2.5741877570855, 2.2870433833923);
        glVertex2f(2.7114653951824, 2.3125834090847);
        glVertex2f(2.8487430332792, 2.3381234347772);
        glVertex2f(2.9924056777992, 2.3540859508349);
        glVertex2f(3.2509984379351, 2.3796259765274);
        glVertex2f(3.4361636242053, 2.4115510086429);
        glVertex2f(3.6149438040523, 2.4275135247007);
        glVertex2f(3.7107189003989, 2.44666854397);
        glVertex2f(3.844786121203, 2.4610218230641);
        glVertex2f(3.9685280840457, 2.4733960193483);
        glVertex2f(4.0984571450305, 2.4857702156326);
        glVertex2f(4.2376668532284, 2.5012379609879);
        glVertex2f(4.3830636595686, 2.5105186082011);
        glVertex2f(4.5501153094061, 2.5259863535564);
        glVertex2f(4.7388218027412, 2.5631089424092);
        glVertex2f(4.8749379618681, 2.5754831386935);
        glVertex2f(5, 2.6);
        glVertex2f(5.1224218875534, 2.6126057275463);
        glVertex2f(5.2492573994671, 2.6280734729016);
        glVertex2f(5.335876773457, 2.6404476691859);
        glVertex2f(5.4688993835128, 2.6528218654702);
        glVertex2f(5.5833606991423, 2.6713831598966);
        glVertex2f(5.6854478184875, 2.6806638071098);
        glVertex2f(5.7906284869037, 2.6837573561808);
        glVertex2f(5.8927156062489, 2.693038003394);
        glVertex2f(5.9391188423149, 2.6868509052519);
        glVertex2f(5.9924207662924, 2.7137363538609);
        glVertex2f(6.1507482740021, 2.781980969253);
        glVertex2f(6.2872375047863, 2.825657523104);
        glVertex2f(6.437375658649, 2.8720638615706);
        glVertex2f(6.592973381743, 2.9211999846529);
        glVertex2f(6.7294626125272, 2.9566871846568);
        glVertex2f(6.8550327048487, 2.9867148154294);
        glVertex2f(6.9731358896113, 3.0186337914285);
        glVertex2f(7.0856310164641, 3.0461836184129);
        glVertex2f(7.2004219622322, 3.0714376264819);
        glVertex2f(7.312917089085, 3.0966916345508);
        glVertex2f(7.4254122159378, 3.1127623669584);
        glVertex2f(7.5333157049599, 3.1242414615352);
        glVertex2f(7.6412191939819, 3.135720556112);
        glVertex2f(7.7628975964962, 3.1403121939427);
        glVertex2f(7.8547303531107, 3.1494954696042);
        glVertex2f(7.6, 3.2);
        glVertex2f(7.3879594520381, 3.2282871536512);
        glVertex2f(7.1734166678648, 3.2629926040321);
        glVertex2f(6.8989281057608, 3.3134732591317);
        glVertex2f(6.5676488066697, 3.3702639961188);
        glVertex2f(6.3057804083405, 3.4112795283872);
        glVertex2f(6.0880825832235, 3.4491400197119);
        glVertex2f(5.9240204541499, 3.4743803472617);
        glVertex2f(5.6873923833705, 3.5090857976426);
        glVertex2f(5.4791596810847, 3.5406362070799);
        glVertex2f(5.2, 3.6);
        glVertex2f(5.0430574516786, 3.6122201915002);
        glVertex2f(4.8383602108838, 3.6475128192235);
        glVertex2f(4.6266044445443, 3.686334709719);
        glVertex2f(4.2489733279055, 3.7498614396209);
        glVertex2f(3.9631030433471, 3.8204466950674);
        glVertex2f(3.6419401310655, 3.8910319505139);
        glVertex2f(3.4337136274984, 3.9439708920988);
        glVertex2f(3.2, 4);
        glVertex2f(2.8831486350156, 4.0921999285364);
        glVertex2f(2.6572758175868, 4.1627851839829);
        glVertex2f(2.431403000158, 4.2227826511124);
        glVertex2f(2.2337642849078, 4.2898386437866);
        glVertex2f(2.1082041723334, 4.3368898265348);
        glVertex2f(2.0325522353574, 4.3747157950228);
        glVertex2f(1.969508954544, 4.4035355805375);
        glVertex2f(1.893857017568, 4.4359578392415);
        glVertex2f(1.82901250016, 4.4665788613508);
        glVertex2f(1.7569630363733, 4.5026035932442);
        glVertex2f(1.6975222287492, 4.5386283251375);
        glVertex2f(1.6578950236666, 4.5530382178949);
        glVertex2f(1.5876467964745, 4.5530382178949);
        glVertex2f(1.4957837301465, 4.5530382178949);
        glVertex2f(1.4309392127384, 4.5530382178949);
        glVertex2f(1.3192625438691, 4.5530382178949);
        glVertex2f(1.2346044239197, 4.5530382178949);
        glVertex2f(1.130132701429, 4.5548394544895);
        glVertex2f(1.0526795278583, 4.5602431642735);
        glVertex2f(1.0014958842794, 4.5608199657902);
    glEnd();
    glPopMatrix();


    /////////gambar kanan pojok atas///////////
    glPushMatrix();
    glColor3ub(66, 47, 30);
    glBegin(GL_POLYGON);
        glVertex2f(6.0880825832235, 3.4491400197119);
        glVertex2f(6.3057804083405, 3.4112795283872);
        glVertex2f(6.5676488066697, 3.3702639961188);
        glVertex2f(6.8989281057608, 3.3134732591317);
        glVertex2f(7.1734166678648, 3.2629926040321);
        glVertex2f(7.3879594520381, 3.2282871536512);
        glVertex2f(7.6, 3.2);
        glVertex2f(7.927471453415, 3.1462560891143);
        glVertex2f(7.9810003934556, 3.1586787452656);
        glVertex2f(8.0797206068162, 3.1678620209271);
        glColor3ub(191, 125, 65);
        glVertex2f(8.1899199147537, 3.1678620209271);
        glVertex2f(8.3494717087483, 3.1718739557177);
        glVertex2f(8.4762590611857, 3.1687042719068);
        glVertex2f(8.6284038841106, 3.1655345880958);
        glVertex2f(8.7445583036386, 3.1579772986926);
        glVertex2f(8.8890956767938, 3.1526240626498);
        glVertex2f(9.0496927580772, 3.1365643545214);
        glVertex2f(9.2076132213393, 3.1151514103503);
        glVertex2f(9.3575038305372, 3.1044449382648);
        glVertex2f(9.5106666739827, 3.1006863044691);
        glVertex2f(9.6593172511369, 3.0929974815128);
        glVertex2f(9.7900272413932, 3.0776198356003);
        glVertex2f(9.9284260546058, 3.0724939536295);
        glVertex2f(10.028380753037, 3.0622421896878);
        glVertex2f(10.1232095694975, 3.0519904257462);
        glVertex2f(10.2385419138413, 3.0366127798336);
        glVertex2f(10.3359336712871, 3.0237980749066);
        glVertex2f(10.4922730713976, 3.0032945470232);
        glVertex2f(10.6255460026393, 2.9827910191399);
        glVertex2f(10.8382701044289, 2.946909845344);
        glVertex2f(10.9561653897581, 2.916154553519);
        glVertex2f(11.0663718521311, 2.9059027895774);
        glVertex2f(11.1637636095769, 2.885399261694);
        glVertex2f(11.2355259571686, 2.8725845567669);
        glVertex2f(11.3636730064395, 2.8572069108544);
        glVertex2f(11.4456871179728, 2.8367033829711);
        glVertex2f(11.5738341672437, 2.8059480911461);
        glVertex2f(11.6917294525729, 2.7803186812919);
        glVertex2f(11.8455059116979, 2.7470004484815);
        glVertex2f(11.9890306068813, 2.7239339796127);
        glVertex2f(12, 3.8);
        glVertex2f(11.903842406317, 3.8119262449469);
        glVertex2f(11.767074791796, 3.8222874278651);
        glVertex2f(11.5909346821856, 3.8388653205343);
        glVertex2f(11.3464107653147, 3.8616599229545);
        glVertex2f(11.1081035581947, 3.8844545253747);
        glVertex2f(10.8511462218218, 3.8989601814602);
        glVertex2f(10.5299495513558, 3.9134658375458);
        glVertex2f(10.2046084077224, 3.9196825472968);
        glVertex2f(9.8150279299958, 3.9279714936314);
        glVertex2f(9.6824575045086, 3.9309046890874);
        glVertex2f(9.5146986858053, 3.9154742552116);
        glVertex2f(9.4241077904582, 3.9128098171132);
        glVertex2f(9.2935503236346, 3.9048165028179);
        glVertex2f(9.0590797709717, 3.899487626621);
        glVertex2f(8.8965490469668, 3.8888298742272);
        glVertex2f(8.7127028181743, 3.8808365599319);
        glVertex2f(8.5609093390438, 3.8683751134771);
        glVertex2f(8.4217036192544, 3.8534602149282);
        glVertex2f(8.2559825242671, 3.8335736835297);
        glVertex2f(8.0732376745483, 3.808896731274);
        glVertex2f(7.9569793511637, 3.7967506159057);
        glVertex2f(7.8104898267044, 3.7784394253483);
        glVertex2f(7.6735719597821, 3.7582724074036);
        glVertex2f(7.5190345500724, 3.736956902616);
        glVertex2f(7.3644971403628, 3.7129769597301);
        glVertex2f(7.2112144993709, 3.675230896752);
        glVertex2f(7.0330965548578, 3.6519257451335);
        glVertex2f(6.8662472159542, 3.6250505024815);
        glVertex2f(6.762334130115, 3.6117283119893);
        glVertex2f(6.6342137616741, 3.5844381826801);
        glVertex2f(6.4970117137195, 3.5569977730892);
        glVertex2f(6.3453673449277, 3.5266688993309);
        glVertex2f(6.1619498702937, 3.4876746330701);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(156, 89, 28);
    glBegin(GL_POLYGON);
        glVertex2f(12, 3.2);
        glVertex2f(11.9534508641426, 3.2092068889131);
        glVertex2f(11.9, 3.2);
        glVertex2f(11.858329928924, 3.1956181838819);
        glVertex2f(11.7920849918968, 3.176933714464);
        glVertex2f(11.7258400548696, 3.1616464213038);
        glVertex2f(11.6511021771978, 3.1463591281437);
        glVertex2f(11.5899530045573, 3.1327704231125);
        glVertex2f(11.5338995963035, 3.1259760705969);
        glColor3ub(66, 47, 30);
        glVertex2f(11.4625588948896, 3.1072916011789);
        glVertex2f(11.3436577258663, 3.0835113673743);
        glVertex2f(11.2417424381321, 3.0614297216985);
        glVertex2f(11.1313342097534, 3.0308551353783);
        glVertex2f(11, 3);
        glVertex2f(10.9003262242225, 2.9612130220932);
        glVertex2f(10.8382701044289, 2.946909845344);
        glVertex2f(10.9561653897581, 2.916154553519);
        glVertex2f(11.0663718521311, 2.9059027895774);
        glVertex2f(11.1637636095769, 2.885399261694);
        glVertex2f(11.2355259571686, 2.8725845567669);
        glVertex2f(11.3636730064395, 2.8572069108544);
        glVertex2f(11.4456871179728, 2.8367033829711);
        glVertex2f(11.5738341672437, 2.8059480911461);
        glVertex2f(11.6917294525729, 2.7803186812919);
        glVertex2f(11.8455059116979, 2.7470004484815);
        glVertex2f(11.9890306068813, 2.7239339796127);
    glEnd();
    glPopMatrix();
}

void piramid (){
    glPushMatrix();
    glScaled(1,1,0);
    glTranslated(piramidlvl3,2,0);
    ////////////piramida paling kanan depan
    glPushMatrix();
    glColor3ub(222, 127, 44); //warna atas
    glBegin(GL_POLYGON);
        glVertex2f(6.7539141575544,4.0934689397632);
        glColor3ub(140, 64, 93); //warna kanan bawah
        glVertex2f(9.4,1.4);
        glColor3ub(222, 127, 44); //warna kiri bawah
        glVertex2f(6.0503101626507,1.4);
    glEnd();
    glPopMatrix();

    //bayangan
    glPushMatrix();
    glColor3ub(255, 240, 58);
    glBegin(GL_POLYGON);
        glVertex2f(6.7539141575544,4.0934689397632);
        glVertex2f(5.7326530075775,3.2968958289151);
        glVertex2f(6.0503101626507,1.4);
    glEnd();
    glPopMatrix();

    //piramida tengah depan
    glPushMatrix();
    glBegin(GL_POLYGON);
        glColor3ub(222, 127, 44);
        glVertex2f(4.1689575136479,5.1957089666033);
        glColor3ub(140, 64, 93); //warna kanan bawah
        glVertex2f(7.9663931701172,1.3712072946193);
        glColor3ub(140, 64, 93); //warna kanan bawah
        glVertex2f(2.7474520245754,1.3712072946193);
    glEnd();
    glPopMatrix();

    //piramida tengah bayangan
    glPushMatrix();
    glColor3ub(255, 240, 58);
    glBegin(GL_POLYGON);
        glVertex2f(4.1689575136479,5.1957089666033);
        glVertex2f(0.7151457290647,1.3712072946193);
        glVertex2f(2.7474520245754,1.3712072946193);
    glEnd();
    glPopMatrix();

    //kiri depan

    glPushMatrix();
    glColor3ub(222, 127, 44);
    glBegin(GL_POLYGON);
        glVertex2f(2.4257377690714,3.9203615703171);
        glColor3ub(140, 64, 93); //warna kanan bawah
        glVertex2f(1.3460480581795,1.3712072946193);
        glColor3ub(222, 127, 44); //warna kiri bawah
        glVertex2f(4.606878739898,1.3712072946193);
    glEnd();
    glPopMatrix();

    //kiri bayangan
    glPushMatrix();
    glColor3ub(255, 240, 58);
    glBegin(GL_POLYGON);
        glVertex2f(2.4257377690714,3.9203615703171);
        glColor3ub(240, 148, 36);
        glVertex2f(-0.3169138576148, 1.3712072946193);
        glVertex2f(1.3967983139408,1.3712072946193);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

//Void untuk di DisplayFunc
void level3(){
    backgroundlevel3();

    glPushMatrix();
    glTranslated(-1,0,0);
    sandMountain();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-0.8,0);
    roadlevel3();
    glPopMatrix();

    glPushMatrix();
    glTranslated(8,7,0);
    glScaled(0.3,0.3,0);
    blackBird();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1,0.35,0);
    glScaled(0.6,0.6,0);
    piramid();
    glPopMatrix();

    glPushMatrix();
    glTranslated(8,0,0);
    glScaled(0.04,0.08,0);
    stone();
    glPopMatrix();

    glPushMatrix();
    glTranslated(10,0,0);
    glScaled(0.04,0.08,0);
    stone();
    glPopMatrix();

    kaktusposition();

    fireball();

    if (heartStatus_bar==3){
        glPushMatrix();
        heart();
        glTranslated(0.5,0,0);
        heart();
        glTranslated(0.5,0,0);
        heart();
        glPopMatrix();
    }if (heartStatus_bar==2){
        glPushMatrix();
        heart();
        glTranslated(0.5,0,0);
        heart();
        glPopMatrix();
    }if (heartStatus_bar==1){
        glPushMatrix();
        heart();
        glPopMatrix();
    }

    glPushMatrix();
    if (fireballStatus_bar==1){
        fireball_status();
    }
    glPopMatrix();

    glPushMatrix();
    if (fireballStatus_bar==2){
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
    }
    glPopMatrix();

    glPushMatrix();
    if (fireballStatus_bar==3){
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
    }
    glPopMatrix();

    glPushMatrix();
    if (fireballStatus_bar==4){
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
    }
    glPopMatrix();

    glPushMatrix();
    if (fireballStatus_bar==5){
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
        glTranslated(0.2,0,0);
        fireball_status();
    }
    glPopMatrix();


}

void body(void){

	//strip body hitam
	glBegin(GL_POLYGON);
		glColor3f(0,0,0);
		glVertex2f(-0.2479375326055,7.1695209271469);
		glVertex2f(-2.2446108978344,4.7972357407363);
		glVertex2f(-3.5718227411507,2.8021001816532);
		glVertex2f(-4.5425297341512,1.261558896897);
		glVertex2f(-6.1338671246944,-1.7497410882847);
		glVertex2f(-6.9417768768163,-3.9531313213444);
		glVertex2f(-6.599027285007,-2.6555792952092);
		glVertex2f(-6.7704020809116,-4.3203630268543);
		glVertex2f(-5.9624923287897,-4.7365589597656);
		glVertex2f(-4.2487443697432,-5.1282727789762);
		glVertex2f(-1.8984614544795,-5.3486118022822);
		glVertex2f(1.6024808047154,-5.4220581433842);
		glVertex2f(4.834119813203,-5.2017191200782);
		glVertex2f(6.8906173640588,-4.8100053008676);
		glVertex2f(7.5026702065754,-4.4672557090583);
		glVertex2f(7.709507644041,-3.8878003305898);
		glVertex2f(6.9233393546003,-1.7856546870853);
		glVertex2f(7.384785959272,-2.7256385114166);
		glVertex2f(5.3315855044572,0.9288304365744);
		glVertex2f(3.049013679358,4.0198131163963);
		glVertex2f(2.0266117160322,5.1373222391011);
		glVertex2f(1.0279865425513,6.2072777821164);
	glEnd();
	glBegin(GL_POLYGON); //body kuning
		glColor3f(0.807843137,0.807843137,0.137254902);
		glVertex2f(-6.5654286098696,-3.8279896295712);
		glVertex2f(-6.1295943440725,-4.4381576016871);
		glVertex2f(-5.2579258124783,-4.6560747345857);
		glVertex2f(-5.2579258124783,-4.6560747345857);
		glVertex2f(-3.4274218961305,-5.0483255738031);
		glVertex2f(-0.9431665810871,-5.2662427067016);
		glVertex2f(2.4127572655505,-5.3098261332813);
		glVertex2f(5.2892634198113,-5.0483255738031);
		glVertex2f(7.3812678956374,-4.4381576016871);
		glVertex2f(7.4248513222171,-3.3485719371944);
		glVertex2f(7.0326004829997,-2.4769034056002);
		glVertex2f(6.5531827906229,-1.605234874006);
		glVertex2f(6.0737650982461,-0.6899829158321);
		glVertex2f(2.9793418110867,3.9734437281968);
		glVertex2f(1.1950155141763,5.8692084628022);
		glVertex2f(-0.1311957662281,6.8240805846934);
		glVertex2f(-1.0330194369031,6.1344507188831);
		glVertex2f(-5,0);
		glVertex2f(-6.4439614609531,-2.8307375366507);
	glEnd();

	//line loop
	glLineWidth(2);
	glEnable( GL_LINE_SMOOTH );
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
	glBegin(GL_LINE_LOOP); //body kuning
		glColor3ub(0,0,0);

		glVertex2f(-6.5654286098696,-3.8279896295712);
		glVertex2f(-6.1295943440725,-4.4381576016871);
		glVertex2f(-5.2579258124783,-4.6560747345857);
		glVertex2f(-5.2579258124783,-4.6560747345857);
		glVertex2f(-3.4274218961305,-5.0483255738031);
		glVertex2f(-0.9431665810871,-5.2662427067016);
		glVertex2f(2.4127572655505,-5.3098261332813);
		glVertex2f(5.2892634198113,-5.0483255738031);
		glVertex2f(7.3812678956374,-4.4381576016871);
		glVertex2f(7.4248513222171,-3.3485719371944);
		glVertex2f(7.0326004829997,-2.4769034056002);
		glVertex2f(6.5531827906229,-1.605234874006);
		glVertex2f(6.0737650982461,-0.6899829158321);
		glVertex2f(2.9793418110867,3.9734437281968);
		glVertex2f(1.1950155141763,5.8692084628022);
		glVertex2f(-0.1311957662281,6.8240805846934);
		glVertex2f(-1.0330194369031,6.1344507188831);
		glVertex2f(-5,0);
		glVertex2f(-6.4439614609531,-2.8307375366507);
	glEnd();




	glBegin(GL_POLYGON);//strip putih atas
		glColor3f(1,1,1);
		glVertex3f(2.6989423838803,3.1735906043824,1.0);
		glVertex3f(1.8966971612196,3.5938142924428,1.0);
		glVertex3f(1.2090583989389,4.2814530547235,1.0);
		glVertex3f(0.4295906776575,5.1913610486493,1.0);
		glVertex3f(0.0059816145057,5.7561731328516,1.0);
		glVertex3f(0.0950595974821,6.2528289887187,1.0);
		glVertex3f(1.0257812109821,5.4737670907505,1.0);
		glVertex3f(1.8102424390409,4.7049950872529,1.0);
		glVertex3f(2.5319467688549,3.7793308381436,1.0);
		glVertex3f(0.0,6.0,1.0);
	glEnd();

	glBegin(GL_POLYGON); //alis kiri
		glColor3f(0.447058824,0.145098039,0.050980392);
		glVertex2f(-2.395212655955,0.3770462394276);
		glVertex2f(-1.8653459439985,1.297341054931);
		glVertex2f(2.3768759616585,-0.2441529554956);
		glVertex2f(2.1773296849784,-0.8354011826959);
		glVertex2f(2.0590800395384,-0.9093072110959);
		glVertex2f(1.8964867770583,-0.9093072110959);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3b(0,125,0);
		 glVertex2f(5.3446531116021,-1.9503532402756);
		 glVertex2f(5.5368450971547,-1.8008705848458);
		 glVertex2f(5.6970050851152,-1.5232599390477);
		 glVertex2f(5.7610690802994,-1.2242946281881);
		 glVertex2f(5.7076824176459,-0.9893933125128);
		 glVertex2f(5.6436184224617,-0.8078786594909);
		 glVertex2f(5.4727811019705,-0.6263640064691);
		 glVertex2f(3.5508612464448,-1.2670039583109);
		 glVertex2f(3.6469572392211,-0.9360066498593);
 		 glVertex2f(3.828471892243,-1.3737772836179);
	glEnd();//
	glBegin(GL_POLYGON);//alis kanan
		 glColor3f(0.447058824,0.145098039,0.050980392);
		 glVertex2f(7.3147120480453,-0.1056925894286);
		 glVertex2f(6.9700064585138,0.7090660767366);
		 glVertex2f(3.2471896053059,-0.345512021333);
		 glVertex2f(3.1930736017976,-0.6341307067104);
		 glVertex2f(3.2285484034107,-0.8709907843249);
 		glVertex2f(3.5626804456672,-0.9127572896069);
	glEnd();
	glBegin(GL_POLYGON);//mata hitam kiri
		glColor3f(0,0,0);
		glVertex2f(1.680388838318,-0.8284046464973);
		glVertex2f(1.6624553687358,-1.0974066902303);
		glVertex2f(1.6649829895366,-1.1782905558583);
		glVertex2f(1.6498172647314,-1.2743401462916);
		glVertex2f(1.6295962983244,-1.3476411495169);
		glVertex2f(1.5992648487139,-1.425997394344);
		glVertex2f(1.5436571910947,-1.5220469847773);
		glVertex2f(1.4653009462675,-1.6206241960114);
		glVertex2f(1.3768342182369,-1.7217290280464);
		glVertex2f(1.2833122486046,-1.7950300312717);
		glVertex2f(1.1771521749678,-1.8582205512936);
		glVertex2f(1.0836302053355,-1.9138282089128);
		glVertex2f(0.9799977524996,-1.9542701417268);
		glVertex2f(0.8763652996637,-1.9820739705364);
		glVertex2f(0.7449290180183,-2.0149330409478);
		glVertex2f(0.6236032195763,-2.0300987657531);
		glVertex2f(0.487111696329,-2.0376816281557);
		glVertex2f(0.3733687602897,-2.0402092489566);
		glVertex2f(0.2520429618477,-2.0275711449522);
		glVertex2f(0.125661921804,-2.0022949369434);
		glVertex2f(0.0068637441629,-1.9694358665321);
		glVertex2f(-0.096768708673,-1.931521554519);
		glVertex2f(-0.1928182991062,-1.8834967593023);
		glVertex2f(-0.2635916815307,-1.8405272056875);
		glVertex2f(-0.3545860303622,-1.7849195480682);
		glVertex2f(-0.440525137592,-1.7242566488472);
		glVertex2f(-0.5214090032199,-1.6307346792149);
		glVertex2f(-0.5972376272462,-1.5321574679808);
		glVertex2f(-0.6730662512724,-1.4083040487379);
		glVertex2f(-0.7261462880908,-1.2920334918977);
		glVertex2f(-0.7539501169004,-1.185873418261);
		glVertex2f(-0.761532979303,-1.0569647574164);
		glVertex2f(-0.741312012896,-0.9331113381735);
		glVertex2f(-0.700870080082,-0.8067302981298);
		glVertex2f(-0.6300966976576,-0.6752940164843);
		glVertex2f(-0.5567956944322,-0.5767168052502);
		glVertex2f(-0.4556908623972,-0.4579186276091);
		glVertex2f(-0.3722793759683,-0.3770347619811);
		glVertex2f(-0.3252458241147,-0.321351211085);
		glVertex2f(-0.2860630600569,-0.2847806312978);
	glEnd();
	glBegin(GL_POLYGON);//mata kiri putih
		glColor3f(1,1,1);
		glVertex2f(-0.4695604844269,-0.2866202657589);
		glVertex2f(-0.636923199897,-0.487455524323);
		glVertex2f(-0.8042859153671,-0.7552358690752);
		glVertex2f(-0.8795991373286,-0.9895436707333);
		glVertex2f(-0.8210221869141,-1.282428422806);
		glVertex2f(-0.7122364218585,-1.5251043602377);
		glVertex2f(-0.5616099779354,-1.7426758903488);
		glVertex2f(-0.3273021762773,-1.9267748773659);
		glVertex2f(-0.0762581030722,-2.060665049742);
		glVertex2f(0.2835717351886,-2.144346407477);
		glVertex2f(0.5848246230347,-2.144346407477);
		glVertex2f(0.9250566228898,-2.087756118887);
		glVertex2f(1.2202342719051,-1.9549261768302);
		glVertex2f(1.4932735972442,-1.7704401461957);
		glVertex2f(1.6998979515548,-1.4826419384058);
		glVertex2f(1.781071805034,-1.2317409367429);
		glVertex2f(1.8032101287101,-0.9070455228261);
		glVertex2f(1.781071805034,-0.7889744632201);
		glVertex2f(-0.3294483854249,-0.1764808415135);
	glEnd();
	glBegin(GL_POLYGON); //biji mata kiri hitam
		glColor3f(0,0,0);
		glVertex2f(1.0069693391377,-0.8973868304337);
		glVertex2f(0.9537568555053,-0.938505567786);
		glVertex2f(0.9150568674089,-0.9772055558823);
		glVertex2f(0.8860318763367,-1.0231617917467);
		glVertex2f(0.8594256345205,-1.0836305231472);
		glVertex2f(0.8473318882404,-1.1465180038037);
		glVertex2f(0.8521693867524,-1.2069867352042);
		glVertex2f(0.8811943778247,-1.2626179680926);
		glVertex2f(0.9319881122011,-1.3158304517251);
		glVertex2f(0.9827818465775,-1.3617866875895);
		glVertex2f(1.045669327234,-1.3980679264297);
		glVertex2f(1.1279068019387,-1.4149991712219);
		glVertex2f(1.2028880288753,-1.427092917502);
		glVertex2f(1.2681942587878,-1.4198366697339);
		glVertex2f(1.3335004887003,-1.4053241741978);
		glVertex2f(1.408481715637,-1.3617866875895);
		glVertex2f(1.4544379515013,-1.3255054487492);
		glVertex2f(1.5124879336458,-1.2601992188366);
		glVertex2f(1.541512924718,-1.177961744132);
		glVertex2f(1.5245816799259,-1.0666992783551);
		glVertex2f(1.539094175462,-1.1174930127315);
		glVertex2f(1.4979754381097,-1.0013930484425);
		glVertex2f(1.4616941992694,-0.9602743110902);
		glVertex2f(1.413319214149,-0.9215743229939);
		glVertex2f(1.3576879812605,-0.8998055796897);
		glVertex2f(1.3093129961402,-0.8731993378735);
		glVertex2f(1.2415880169716,-0.8586868423374);
		glVertex2f(1.169025539291,-0.8635243408494);
		glVertex2f(1.1061380586345,-0.8659430901054);
		glVertex2f(1.0601818227701,-0.8828743348976);
	glEnd();
	glBegin(GL_POLYGON);//mata hitam kanan
		glVertex2f(3.3324245598344,-1.3887839881221);
		glVertex2f(3.606255467909,-0.8416267382064);
		glVertex2f(5.3766942667894,-0.5431225221161);
		glVertex2f(5.5104437884106,-0.6857797618689);
		glVertex2f(5.6,-0.8);
		glVertex2f(5.6312052505891,-0.8755477738636);
		glVertex2f(5.6613956161337,-0.9747446892245);
		glVertex2f(5.6915859816784,-1.0610028764948);
		glVertex2f(5.721776347223,-1.1990159761274);
		glVertex2f(5.7260892565865,-1.2852741633977);
		glVertex2f(5.7045247097689,-1.4060356255762);
		glVertex2f(5.6700214348608,-1.5181712690277);
		glVertex2f(5.605327794408,-1.6604972780237);
		glVertex2f(5.5190696071377,-1.7898845589292);
		glVertex2f(5.4630017854119,-1.8804556555631);
		glVertex2f(5.3896823262321,-1.9710267521969);
		glVertex2f(5.1956014048739,-2.1349173080106);
	glEnd();
	glBegin(GL_POLYGON); //cucuk
		glColor3f(0,0,0);
		glVertex2f(1.2510858137285,-2.7453599148546);
		glVertex2f(1.3660827027056,-2.9482956012847);
		glVertex2f(3.0233908085515,-3.8682707131013);
		glVertex2f(3.1383876975286,-3.8682707131013);
		glVertex2f(4.8971636465896,-2.9482956012847);
		glVertex2f(4.9180174842868,-2.7268703446853);
		glVertex2f(2.2962921212419,-2.3523381499646);
		glVertex2f(2.0837197945085,-2.3827056252122);
	glEnd();
	glLineWidth(10.0f);
	glBegin(GL_POLYGON);
		glColor3f(0,0,0);
		glVertex2f(1.2510858137285,-2.7453599148546);
		glVertex2f(1.6115528610977,-2.2777133128731);
		glVertex2f(2.2992728049605,-1.6329758655017);
		glVertex2f(2.8150627628575,-1.2676246453246);
		glVertex2f(3.2448877277718,-1.310607141816);
		glVertex2f(3.9970814163717,-1.5685021207646);
		glVertex2f(5.9098025102401,-2.4926257953302);
		glVertex2f(6.3826099716458,-2.879468263753);
		glVertex2f(4.9180174842868,-2.7268703446853);
		glVertex2f(2.2962921212419,-2.3523381499646);
		glVertex2f(2.0837197945085,-2.3827056252122);
	glEnd();
	glLineWidth(10.0f);
	glBegin(GL_POLYGON);
		glColor3b(0,0,0);
		glVertex2f(5.4336202453311,-0.6750112582989);
		glVertex2f(5.6035578385461,-0.9393586255221);
		glVertex2f(5.6790856577527,-1.279233811952);
		glVertex2f(5.5846758837444,-1.5813450887786);
		glVertex2f(5.4147382905295,-1.8456924560018);
		glVertex2f(5.269053852525,-2.0345120040184);
		glVertex2f(4.8502204663482,-1.8994044600904);
		glVertex2f(4.4584085889569,-1.7102538985912);
		glVertex2f(4.0936182203513,-1.5616356002704);
		glVertex2f(3.7558493605312,-1.4940818283064);
		glVertex2f(3.5126557814608,-1.4130173019495);
		glVertex2f(3.634252570996,-0.9131193894159);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,1,1);
		glVertex2f(5.4336202453311,-0.6750112582989);
		glVertex2f(5.6035578385461,-0.9393586255221);
		glVertex2f(5.6790856577527,-1.279233811952);
		glVertex2f(5.5846758837444,-1.5813450887786);
		glVertex2f(5.4147382905295,-1.8456924560018);
		glVertex2f(5.269053852525,-2.0345120040184);
		glVertex2f(4.8502204663482,-1.8994044600904);
		glVertex2f(4.4584085889569,-1.7102538985912);
		glVertex2f(4.0936182203513,-1.5616356002704);
		glVertex2f(3.7558493605312,-1.4940818283064);
		glVertex2f(3.5126557814608,-1.4130173019495);
		glVertex2f(3.634252570996,-0.9131193894159);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1/255,1/255,1/255);
		glVertex2f(5.3313376168431,-1.4969831038094);
		glVertex2f(5.415565447673,-1.4717147545605);
		glVertex2f(5.4768850296845,-1.4307254754074);
		glVertex2f(5.5231979251953,-1.3776018599685);
		glVertex2f(5.5511073747867,-1.3262026776822);
		glVertex2f(5.5624753271641,-1.2624718586415);
		glVertex2f(5.5550800463165,-1.2144025331316);
		glVertex2f(5.5384406644092,-1.1700308480456);
		glVertex2f(5.5070107208066,-1.128987039341);
		glVertex2f(5.4604285346801,-1.0924768817625);
		glVertex2f(5.4031027758523,-1.0535209475238);
		glVertex2f(5.3190261931904,-1.0254954199699);
		glVertex2f(5.2209368467516,-1.0289986109141);
		glVertex2f(5.1368602640898,-1.0430113746911);
		glVertex2f(5.0702996361492,-1.1060688116875);
		glVertex2f(5,-1.2);
		glVertex2f(5.0072421991528,-1.302247504565);
		glVertex2f(5.0457772995395,-1.3758145143941);
		glVertex2f(5.1088347365359,-1.4388719513905);
		glVertex2f(5.182401746365,-1.4774070517772);
		glVertex2f(5.2524655652498,-1.4984261974426);
	glEnd(); //end of cucuk
	glBegin(GL_POLYGON); //cucuk orange
		glColor3f(1,0.222,0);
		glVertex2f(1.5498514511042,-2.5012938517838);
		glVertex2f(1.9871894969144,-2.0265010484669);
		glVertex2f(2.1987718491705,-1.8149186962108);
		glVertex2f(2.3990194325557,-1.6448971631479);
		glVertex2f(2.6677851692878,-1.4527658530818);
		glVertex2f(2.8595383841859,-1.347105918342);
		glVertex2f(2.9808516425907,-1.3314525946769);
		glVertex2f(3.1452115410748,-1.3510192492583);
		glVertex2f(3.6969912002712,-1.5232058095749);
		glVertex2f(4.733260747401,-1.9521539645898);
		glVertex2f(5.2340981894536,-2.1925559367751);
		glVertex2f(5.7357579414881,-2.4643190192363);
		glVertex2f(5.9829639089975,-2.6291229975759);
		glVertex2f(6.0833274749165,-2.7139918552109);
		glVertex2f(6.1446545767387,-2.7906507324887);
		glVertex2f(4.2680452609766,-2.502413353924);
		glVertex2f(2.9249817310685,-2.3000339179104);
		glVertex2f(2.3791705248501,-2.235640460997);
		glVertex2f(2.2258527702943,-2.2325741059059);
		glVertex2f(2.1461275379254,-2.2509722364526);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,0.222,0);
		glVertex2f(1.5926397869574,-2.8844721101042);
		glVertex2f(1.8891567327327,-2.701769749576);
		glVertex2f(2.0188564885701,-2.632453208689);
		glVertex2f(2.1522527881142,-2.5657550589169);
		glVertex2f(2.2511500446727,-2.5174563987372);
		glVertex2f(2.3431474926341,-2.508256653941);
		glVertex2f(2.5179426437609,-2.5266561435333);
		glVertex2f(2.6812381138924,-2.5657550589169);
		glVertex2f(3.0644805273164,-2.6418084334731);
		glVertex2f(3.6835142802156,-2.7239251557965);
		glVertex2f(4.2267479817393,-2.8123585490678);
		glVertex2f(4.4794148196573,-2.8628919166514);
		glVertex2f(4.3151813750106,-2.9639586518186);
		glVertex2f(4.1067312337282,-3.0650253869858);
		glVertex2f(3.7024642930594,-3.2166254897366);
		glVertex2f(3.0897472111082,-3.4377089729148);
		glVertex2f(2.9191970955136,-3.4313923019668);
		glVertex2f(2.6728469285435,-3.3555922505914);
		glVertex2f(2.3759633939899,-3.2671588573201);
		glVertex2f(2.0474965046965,-3.1534587802571);
		glVertex2f(1.8453630343621,-3.0523920450899);
		glVertex2f(1.7190296154031,-2.9702753227665);
	glEnd();
	glBegin(GL_POLYGON);//buntut
		glColor3f(0,0,0);
		glVertex2f(-5.0440869414158,0.1087726832799);
		glVertex2f(-5.2721505097501,0.3052449902698);
		glVertex2f(-5.3430921074606,0.3967223136334);
		glVertex2f(-5.4,0.5);
		glVertex2f(-5.4569720406275,0.6076802226146);
		glVertex2f(-5.5111116809855,0.7831673327407);
		glVertex2f(-5.5372480590894,0.98105705267);
		glVertex2f(-5.5316474066386,1.1733461201485);
		glVertex2f(-5.5223129858872,1.3469663461243);
		glVertex2f(-5.4961766077833,1.5261872245509);
		glVertex2f(-5.47377399798,1.6475346943189);
		glVertex2f(-5.4457707357258,1.7875510055896);
		glVertex2f(-5.4735225022027,1.798607228423);
		glVertex2f(-5.5300610952563,1.7485301888612);
		glVertex2f(-5.5752919696992,1.7194531981479);
		glVertex2f(-5.6253690092611,1.6709915469591);
		glVertex2f(-5.6819076023147,1.6160683422784);
		glVertex2f(-5.7255230883847,1.5756836329544);
		glVertex2f(-5.7836770698113,1.5094527096629);
		glVertex2f(-5.8579849349675,1.4319140677608);
		glVertex2f(-5.9549082373452,1.3042983862968);
		glVertex2f(-6.0340622676203,1.1782980932058);
		glVertex2f(-6.0986778025388,1.0555285768608);
		glVertex2f(-6.1519856188465,0.9376052256346);
		glVertex2f(-6.2,0.8);
		glVertex2f(-6.2330619612854,0.6611315056023);
		glVertex2f(-6.2643358801859,0.4949888114432);
		glVertex2f(-6.2780182197049,0.3640292760472);
		glVertex2f(-6.2819274595675,0.2565251798266);
		glVertex2f(-6.2799728396362,0.1646580430563);
		glVertex2f(-6.2780182197049,0.0747455262173);
		glVertex2f(-6.3307929578496,0.1021102052552);
		glVertex2f(-6.4207054746886,0.176385762644);
		glVertex2f(-6.6611237262365,0.3777116155662);
		glVertex2f(-7.0266376533864,0.7529986423726);
		glVertex2f(-7.2983298238348,1.1595595880795);
		glVertex2f(-7.4429716987498,1.4879357365351);
		glVertex2f(-7.5094287764134,1.7224901282891);
		glVertex2f(-7.5446119351765,1.9629083798369);
		glVertex2f(-7.540702695314,2.1603249928965);
		glVertex2f(-7.540702695314,2.2658744691858);
		glVertex2f(-7.5778404740084,2.2228728306976);
		glVertex2f(-7.7009815296792,2.0215469777754);
		glVertex2f(-7.7850301867244,1.8202211248532);
		glVertex2f(-7.8534418843193,1.6091221722747);
		glVertex2f(-7.8991427598555,1.274505294687);
		glVertex2f(-7.9093812452098,1.0185431608285);
		glVertex2f(-7.8524357647628,0.6503087218558);
		glVertex2f(-7.7391688639285,0.284551021245);
		glVertex2f(-7.6,0);
		glVertex2f(-7.4772391557492,-0.1991930344015);
		glVertex2f(-7.2625039895841,-0.4446046528759);
		glVertex2f(-7.1091217280377,-0.5814688247173);
		glVertex2f(-6.9533797393905,-0.6852968171488);
		glVertex2f(-6.8,-0.8);
		glVertex2f(-6.9109046515776,-0.9023917104145);
		glVertex2f(-7.2341872643756,-1.1076879681767);
		glVertex2f(-7.8335579479571,-1.2610702297232);
		glVertex2f(-7.6990535032164,-1.3814163118596);
		glVertex2f(-7.4583613389435,-1.494683212694);
		glVertex2f(-7.1586759971527,-1.5796333883197);
		glVertex2f(-6.8778684721676,-1.5914320238233);
		glVertex2f(-6.5829025845783,-1.5749139341183);
		glVertex2f(-6.3186131492982,-1.5395180276075);
		glVertex2f(-5.864250894696,-1.4549043865254);
	glEnd();
	glBegin(GL_POLYGON); //jambul
		glColor3f(0,0,0);
		glVertex2f(0.5711753327718,6.5456425244001);
		glVertex2f(0.6478000674097,6.7392208013799);
		glVertex2f(0.6961946366546,6.9126346745077);
		glVertex2f(0.7305242889035,7.1011171164678);
		glVertex2f(0.7505883613548,7.2435720308719);
		glVertex2f(0.7606203975804,7.3900397597662);
		glVertex2f(0.7626268048256,7.5244690451898);
		glVertex2f(0.7568942126966,7.7040902652298);
		glVertex2f(0.7301421160949,7.8703354369689);
		glVertex2f(0.7454290284388,7.7939008752498);
		glVertex2f(0.6957465633213,8.0270262884932);
		glVertex2f(0.636509777989,8.2104692366191);
		glVertex2f(0.5658078083988,8.3786252724013);
		glVertex2f(0.4817297905077,8.5219400756247);
		glVertex2f(0.4339581894332,8.5926420452149);
		glVertex2f(0.368988811972,8.6977395675787);
		glVertex2f(0.3059302985537,8.764619809083);
		glVertex2f(0.2505152413073,8.8143022742004);
		glVertex2f(0.2008327761898,8.856341283146);
		glVertex2f(0.18172413576,8.7130264799226);
		glVertex2f(0.1607046312873,8.5601573564843);
		glVertex2f(0.1492394470294,8.4130208251749);
		glVertex2f(0.1339525346856,8.2945472545102);
		glVertex2f(0.1263090785137,8.1512324512868);
		glVertex2f(0.1148438942558,8.0537783850949);
		glVertex2f(0.1033787099979,8.0270262884932);
		glVertex2f(0.0708940212673,8.0576001131808);
		glVertex2f(-0.0131839966238,8.1187477625562);
		glVertex2f(-0.1297467032455,8.1913605961894);
		glVertex2f(-0.2539528660391,8.2735277500374);
		glVertex2f(-0.4068219894774,8.3556949038855);
		glVertex2f(-0.5768888893025,8.4455055139055);
		glVertex2f(-0.80619257446,8.5429595800974);
		glVertex2f(-1.0106550270587,8.6251267339455);
		glVertex2f(-1.253334760517,8.7053830237506);
		glVertex2f(-1.5399643669638,8.7799067214268);
		glVertex2f(-1.74170137493,8.8121634621494);
		glVertex2f(-1.8992340921171,8.830696722995);
		glVertex2f(-2.0901266788263,8.8455233316714);
		glVertex2f(-2.2754592872818,8.8510833099251);
		glVertex2f(-2.4848851348364,8.8473766577559);
		glVertex2f(-2.6146179607553,8.8362567012486);
		glVertex2f(-2.7017242867293,8.8158701143185);
		glVertex2f(-2.8,8.8);
		glVertex2f(-2.8740836125929,8.7825102447965);
		glVertex2f(-2.927830069045,8.7695369622046);
		glVertex2f(-2.9926964820044,8.7621236578664);
		glVertex2f(-3.0371763080338,8.7454437231054);
		glVertex2f(-2.8296037865636,8.6453641145395);
		glVertex2f(-2.4570852435681,8.4804180930141);
		glVertex2f(-2.0141403093595,8.2858188541359);
		glVertex2f(-1.8213943965658,8.1875925716545);
		glVertex2f(-1.5767553534046,8.0374731588055);
		glVertex2f(-1.4,7.9);
		glVertex2f(-1.283929832045,7.7724475287142);
		glVertex2f(-1.20053015824,7.6593946375564);
		glVertex2f(-1.1960091611841,7.6330418278632);
		glVertex2f(-1.2268978972741,7.6285215250207);
		glVertex2f(-1.3745611234604,7.6322884440561);
		glVertex2f(-1.4958559163992,7.6360553630915);
		glVertex2f(-1.7376921184697,7.6345485954773);
		glVertex2f(-1.865333809916,7.6245370819018);
		glVertex2f(-2,7.6);
		glVertex2f(-2.1246387044913,7.5855857028884);
		glVertex2f(-2.2815571170884,7.5444085307884);
		glVertex2f(-2.4562818743773,7.4865379105399);
		glVertex2f(-2.6265550454932,7.4075222559697);
		glVertex2f(-2.7511994583363,7.3385226702887);
		glVertex2f(-2.8469085610551,7.2728617742375);
		glVertex2f(-2.9626498015522,7.178265568062);
		glVertex2f(-2.7011191138904,7.1548947406539);
		glVertex2f(-2.3505567027694,7.1259594305296);
		glVertex2f(-2.1,7.1);
		glVertex2f(-1.8152534654702,7.0781048791702);
		glVertex2f(-1.4991908471896,7.0502824655892);
		glVertex2f(-1.5014166402761,7.0213471554649);
		glVertex2f(-1.6605608459596,6.8699932255841);
		glVertex2f(-1.8642209133728,6.6652202616276);
		glVertex2f(-1.9910911193023,6.5383500556981);
		glVertex2f(-2.0801228427617,6.4437538495226);
		glVertex2f(-2.0812357393049,6.4270604013739);
		glVertex2f(-1.8553177410269,6.4370764702631);
		glVertex2f(-1.5726420190435,6.454882814955);
		glVertex2f(-1.3177887106412,6.4571086080415);
		glVertex2f(-1.1608702980442,6.4337377806334);
		glVertex2f(-1.012855057793,6.3780929534713);
		glVertex2f(-0.8163856537015,6.2784668119606);
	glEnd();
}

void bodyPosition(){
    glPushMatrix();
    glTranslated(8,10,0);
    body();
    glPopMatrix();
}

void overgame(){
    glPushMatrix();//untuk keseluruhan
    glTranslated(0,3,0);
    //awal g
    glPushMatrix();//untuk semua G dan bayangan
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(1.0974108217594, 3.8474271303571);
        glVertex2f(0.791217320511, 3.8474271303571);
        glVertex2f(0.7710570988224, 3.8453171792555);
        glVertex2f(0.7535962015039, 3.8437388174705);
        glVertex2f(0.7368741918051, 3.840110331634);
        glVertex2f(0.7223471047075, 3.8356404586809);
        glVertex2f(0.7089374858481, 3.8317293198469);
        glVertex2f(0.6944103987505, 3.8272594468938);
        glVertex2f(0.6821182481294, 3.8216721057024);
        glVertex2f(0.6703848316275, 3.8132910939153);
        glVertex2f(0.6618565190048, 3.8091878829601);
        glVertex2f(0.6501377772079, 3.8008713565236);
        glVertex2f(0.6414432268424, 3.7948229736607);
        glVertex2f(0.6350168200506, 3.7891526147267);
        glVertex2f(0.6289684371877, 3.7834822557927);
        glVertex2f(0.6229200543247, 3.7759217772141);
        glVertex2f(0.6170095669331, 3.7712473238553);
        glVertex2f(0.6115505270217, 3.7636886532088);
        glVertex2f(0.6050391479559, 3.7575181010372);
        glVertex2f(0.5990645654865, 3.7495519910781);
        glVertex2f(0.5928118431095, 3.7401478133968);
        glVertex2f(0.5860365354215, 3.7274861426166);
        glVertex2f(0.2959290646977, 2.6602657547916);
        glVertex2f(0.2921826508797, 2.6515850279395);
        glVertex2f(0.2905875517159, 2.6428119825385);
        glVertex2f(0.290188776925, 2.6344377119284);
        glVertex2f(0.2909863265069, 2.6260634413184);
        glVertex2f(0.2917838760888, 2.6188854950812);
        glVertex2f(0.2920697733013, 2.6112802472524);
        glVertex2f(0.2938807308713, 2.603001584075);
        glVertex2f(0.2959230525453, 2.5933318376957);
        glVertex2f(0.2993080766375, 2.5831767654189);
        glVertex2f(0.305231868799, 2.5730216931422);
        glVertex2f(0.3120019169835, 2.5611741088193);
        glVertex2f(0.3204644772141, 2.5510190365425);
        glVertex2f(0.3283634245623, 2.5420830687943);
        glVertex2f(0.3402871171111, 2.5331402993827);
        glVertex2f(0.3544465020128, 2.5219618376182);
        glVertex2f(0.3700963484831, 2.5137642989909);
        glVertex2f(0.3909628104435, 2.5055667603636);
        glVertex2f(0.8538032459636, 2.4989205078878);
        glVertex2f(0.342671524017, 2.8337584747434);
        glVertex2f(1.0814851253683, 3.5235349223396);
    glEnd();
    glPopMatrix();

    //
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(1.6, 2.4989205078878);
        glVertex2f(1.619075568372, 2.5021908697699);
        glVertex2f(1.6368551417091, 2.5098106869144);
        glVertex2f(1.6559046845703, 2.5174305040589);
        glVertex2f(1.6774941664797, 2.5301301992997);
        glVertex2f(1.7003536179132, 2.5402899554923);
        glVertex2f(1.7206731302985, 2.5529896507331);
        glVertex2f(1.7384527036356, 2.5682292850221);
        glVertex2f(1.7549623074487, 2.582198949787);
        glVertex2f(1.7689319722136, 2.5999785231241);
        glVertex2f(1.7816316674544, 2.6190280659853);
        glVertex2f(1.791791423647, 2.644427456467);
        glVertex2f(1.8027560494341, 2.6717136423768);
        glVertex2f(1.8139466374656, 2.7075235240777);
        glVertex2f(1.8391839665751, 2.833046722441);
        glVertex2f(0.9052776350118, 2.833046722441);
        glVertex2f(0.8538032459636, 2.4989205078878);
    glEnd();
    glPopMatrix();

//
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(1.8391839665751, 2.833046722441);
        glVertex2f(1.9399284972844, 3.2077622525424);
        glVertex2f(1.4770465692737, 3.2077622525424);
        glVertex2f(1.4634870198017, 3.20609052806);
        glVertex2f(1.4482346144422, 3.2020366503849);
        glVertex2f(1.4349670579537, 3.195256729138);
        glVertex2f(1.4226479062884, 3.1874172689874);
        glVertex2f(1.4108887160626, 3.1806977317155);
        glVertex2f(1.4002494487153, 3.1694985029289);
        glVertex2f(1.3907301042467, 3.1571793512637);
        glVertex2f(1.3828906440961, 3.1493398911131);
        glVertex2f(1.3739312610669, 3.1336609708119);
        glVertex2f(1.2882413932642, 2.833046722441);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(1.0974108217594, 3.8474271303571);
        glVertex2f(1.0314851253683,3.5235349223396);
        glVertex2f(1.9186599909336, 3.5235349223396);
        glVertex2f(1.9370763407361, 3.5268464762683);
        glVertex2f(1.9559826935082, 3.5306277468227);
        glVertex2f(1.9726202839476, 3.5397027961533);
        glVertex2f(1.989257874387, 3.5472653372621);
        glVertex2f(2.0036267024937, 3.5586091489253);
        glVertex2f(2.0172392764896, 3.5737342311429);
        glVertex2f(2.0316081045963, 3.592640583915);
        glVertex2f(2.0406831539269, 3.6168407154632);
        glVertex2f(2.1029676682042, 3.8474271303571);
    glEnd();
    glPopMatrix();
    //akhir G

    //bayangan g atas
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(2.2957116716906, 3.8347130866205);
        glVertex2f(2.1804008094867, 3.8347130866205);
        glVertex2f(2.1344966701365, 3.6505065159592);
        glVertex2f(2.1312788405072, 3.6372357059466);
        glVertex2f(2.1247799059975, 3.6177389024175);
        glVertex2f(2.1145672946251, 3.588493697124);
        glVertex2f(2.1110623428949, 3.5766438690307);
        glVertex2f(2.1033438021323, 3.5657677434106);
        glVertex2f(2.0941420718804, 3.5597127014382);
        glVertex2f(2.0862505085472, 3.5573916533991);
        glVertex2f(2.0774305259984, 3.5559990245756);
        glVertex2f(2.0690747530573, 3.5569274437912);
        glVertex2f(2.0718600107044, 3.5365022210465);
        glVertex2f(2.081144202861, 3.5262896096741);
        glVertex2f(2.0899641854099, 3.5221117232036);
        glVertex2f(2.1, 3.52);
        glVertex2f(2.1145672946251, 3.5193264655566);
        glVertex2f(2.1303504212915, 3.5202548847723);
        glVertex2f(2.1470619671735, 3.523968561635);
        glVertex2f(2.1628450938399, 3.5313959153603);
        glVertex2f(2.1786282205063, 3.5425369459484);
        glVertex2f(2.196268185604, 3.5541421861442);
        glVertex2f(2.2092660546234, 3.5638905879087);
        glVertex2f(2.2194786659957, 3.5750316184968);
        glVertex2f(2.2264418101133, 3.5847800202613);
        glVertex2f(2.2334049542308, 3.596849470065);
        glVertex2f(2.2399038887405, 3.6103115486922);
        glVertex2f(2.2426891463875, 3.6242378369272);
    glEnd();
    glPopMatrix();

    //bayangan G tengah
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(1.2653169764119, 3.4765359657901);
        glVertex2f(1.1391764074272, 3.4747524998018);
        glVertex2f(0.9864514480198, 2.8858275084935);
        glVertex2f(1.1041332666584, 2.8865955163644);
    glEnd();
    glPopMatrix();

    //bayagan G bawah
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(2.1238908556515, 3.1765612584853);
        glVertex2f(1.9995166158831, 3.1786515818428);
        glVertex2f(1.8590835680118, 2.6495999032269);
        glVertex2f(1.9786755730861, 2.6405516602493);
    glEnd();
    glPopMatrix();
    //lanjutan g
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(1.8590835680118, 2.6495999032269);
        glVertex2f(1.8512401515619, 2.6260703623488);
        glVertex2f(1.8435167926816, 2.6067619651482);
        glVertex2f(1.8357934338013, 2.5884189878076);
        glVertex2f(1.824208395481, 2.5729722700471);
        glVertex2f(1.8155196167407, 2.5623526515867);
        glVertex2f(1.8068308380004, 2.5469059338262);
        glVertex2f(1.7933149599599, 2.5362863153659);
        glVertex2f(1.7759374024793, 2.5218050174654);
        glVertex2f(1.7624215244389, 2.5082891394249);
        glVertex2f(1.75, 2.5);
        glVertex2f(1.735389768358, 2.4870499025042);
        glVertex2f(1.7324935087779, 2.4716031847437);
        glVertex2f(1.7479402265384, 2.4687069251636);
        glVertex2f(1.7691794634591, 2.4706377648837);
        glVertex2f(1.8000728989802, 2.481257383344);
        glVertex2f(1.8917877856832, 2.5208395976053);
        glVertex2f(1.9091653431638, 2.5343554756458);
        glVertex2f(1.9236466410643, 2.5478713536862);
        glVertex2f(1.9381279389648, 2.5642834913068);
        glVertex2f(1.9516438170052, 2.5816610487874);
        glVertex2f(1.9632288553256, 2.5971077665479);
        glVertex2f(1.9719176340659, 2.6154507438885);
        glVertex2f(1.9786755730861, 2.6405516602493);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //awal A
    glPushMatrix(); //untuk semua A
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(3.2067737791564, 3.8181411850273);
        glVertex2f(3.1760610844512, 3.8079677540202);
        glVertex2f(3.1487222212746, 3.7994243592775);
        glVertex2f(3.1265093949436, 3.7823375697921);
        glVertex2f(3.1094226054582, 3.7652507803067);
        glVertex2f(3.0836834368887, 3.7421836349166);
        glVertex2f(2.0704097001298, 2.4943948180557);
        glVertex2f(2.6003606550228, 2.4943948180557);
        glVertex2f(2.7944509728976, 2.7222399738218);
        glVertex2f(3.2623787207751, 3.3101862982868);
        glVertex2f(3.4939311303421, 2.4943948180557);
        glVertex2f(4.0536923819701, 2.4943948180557);
        glVertex2f(3.6686916781024, 3.7288807520822);
        glVertex2f(3.6634681165219, 3.7501736204585);
        glVertex2f(3.6503515689735, 3.7692522350743);
        glVertex2f(3.6360426080117, 3.7835611960361);
        glVertex2f(3.619565467092, 3.7984696491819);
        glVertex2f(3.601781205204, 3.8067266279156);
        glVertex2f(3.5788067641643, 3.8133715313733);
        glVertex2f(3.5561509093081, 3.8169487716138);
        glVertex2f(3.2353917010801, 3.8205260118542);
    glEnd();
    glPopMatrix();

    //A bagian tengah
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(2.7944509728976, 2.7222399738218);
        glVertex2f(3.024140987741, 3.047025082575);
        glVertex2f(3.3691597781182, 3.047025082575);
        glVertex2f(3.4476370133252, 2.7222399738218);
    glEnd();
    glPopMatrix();

    //A bayangan pertama
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(3.7371086308481, 3.7914076562327);
        glVertex2f(3.7452522058212, 3.7975967732122);
        glVertex2f(3.7530700377953, 3.8002027172036);
        glVertex2f(3.763168070762, 3.802808661195);
        glVertex2f(3.7745690757243, 3.802808661195);
        glVertex2f(3.7869473096834, 3.8018314321982);
        glVertex2f(3.79704534265, 3.7995512312057);
        glVertex2f(3.8074691186155, 3.7956423152187);
        glVertex2f(3.8185443805789, 3.789778941238);
        glVertex2f(3.830922614538, 3.7848927962542);
        glVertex2f(3.843626591496, 3.7783779362757);
        glVertex2f(3.8511186804713, 3.7721888192962);
        glVertex2f(3.8602394844411, 3.7627422723274);
        glVertex2f(4.2333794136086, 2.4984650560995);
        glVertex2f(4.1176071006257, 2.4881895082858);
        glVertex2f(3.7369661704642, 3.7663076821766);
        glVertex2f(3.7327565362614, 3.7803397961859);
    glEnd();
    glPopMatrix();

    //bayangan A bawah
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(2.8505732268905, 2.6901022976556);
        glVertex2f(2.9376551263034,2.6901022976556);
        glVertex2f(2.796015616999, 2.483372103795);
        glVertex2f(2.6973563725869, 2.483372103795);
    glEnd();
    glPopMatrix();

    //bayangan A tengah
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(3.2371941134114, 3.1986146337234);
        glVertex2f(3.2647216337675, 3.105444564826);
        glVertex2f(3.1694340633042, 3.105444564826);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    //akhir A

    //awal M
    glPushMatrix();
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(5.0635658861368, 3.8120443250206);
        glVertex2f(4.7717155092292, 3.8120443250206);
        glVertex2f(4.7588484256724, 3.8114594575862);
        glVertex2f(4.7469390578974, 3.8094538144375);
        glVertex2f(4.7352149036813, 3.807562821822);
        glVertex2f(4.7242471465113, 3.8030244395447);
        glVertex2f(4.712144793772, 3.796595064652);
        glVertex2f(4.6985296469403, 3.7909220868055);
        glVertex2f(4.6841581030625, 3.7822235207741);
        glVertex2f(4.6711110735523, 3.7734562081647);
        glVertex2f(4.6551882816228, 3.7622512805107);
        glVertex2f(4.6398552227278, 3.7480976876845);
        glVertex2f(4.6257016299017, 3.736303026996);
        glVertex2f(4.6139069692132, 3.7233289002387);
        glVertex2f(4.6044712406624, 3.7115342395503);
        glVertex2f(4.5972029074046, 3.7019944283185);
        glVertex2f(4.5902081304296, 3.6872175338192);
        glVertex2f(4.271814580076, 2.482215178619);
        glVertex2f(4.6562953612251, 2.482215178619);
        glVertex2f(4.6710525100218, 2.4856896939482);
        glVertex2f(4.6840127964481, 2.491706969789);
        glVertex2f(4.6941958786401, 2.5005014498639);
        glVertex2f(4.7034532260874, 2.5083701951941);
        glVertex2f(4.7127105735347, 2.5162389405243);
        glVertex2f(4.7210421862373, 2.5241076858546);
        glVertex2f(4.7284480641952, 2.5342907680466);
        glVertex2f(4.7363168095254, 2.5444738502387);
        glVertex2f(4.7437226874833, 2.5555826671754);
        glVertex2f(4.749739963324, 2.5694686883464);
        glVertex2f(4.7567831799065, 2.5813276269885);
        glVertex2f(4.7576539369026, 2.5952597389259);
        glVertex2f(4.8239983442971, 2.8477185921816);
        glVertex2f(4.9400355717182, 2.482215178619);
        glVertex2f(5.4853319841807, 2.482215178619);

    glEnd();
    glPopMatrix();
    //lanjutan
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(5.4853319841807, 2.482215178619);
        glVertex2f(5.7905825303401, 2.8515648944203);
        glVertex2f(6.0146217427682, 3.7614139384623);
        glVertex2f(5.3348277475257, 2.9482925685312);
    glEnd();
    glPopMatrix();
    //lanjutan
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(6.0146217427682, 3.7614139384623);
        glVertex2f(5.6974309904488, 2.482215178619);
        glVertex2f(5.6974309904488, 2.482215178619);
        glVertex2f(6.0542389273862, 2.482215178619);
        glVertex2f(6.0716717064567, 2.4856094158382);
        glVertex2f(6.0856344923519, 2.4925908087858);
        glVertex2f(6.1, 2.5);
        glVertex2f(6.1114921046508, 2.5079433430742);
        glVertex2f(6.1223728204524, 2.5183059295519);
        glVertex2f(6.1353179836103, 2.5274147893334);
        glVertex2f(6.143839467246, 2.5354064239849);
        glVertex2f(6.1543509384758, 2.5478304189577);
        glVertex2f(6.1627858837161, 2.5606159789437);
        glVertex2f(6.1670239263762, 2.5749600433807);
        glVertex2f(6.4837419328758, 3.8120443250206);
        glVertex2f(6.1214674386932, 3.8120443250206);
        glVertex2f(6.1076490238161, 3.8108727401537);
        glVertex2f(6.0947981406914, 3.8073679538469);
        glVertex2f(6.0807789954644, 3.8038631675402);
        glVertex2f(6.0677856476851, 3.7995430837696);
        glVertex2f(6.0544930981639, 3.79334880862);
        glVertex2f(6.0393056908348, 3.7834185807509);
        glVertex2f(6.0247054864991, 3.7698656393971);
        glVertex2f(6.0146217427682, 3.7614139384623);
    glEnd();
    glPopMatrix();

    //bayangan
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(5.2706449613682, 3.8120443250206);
        glVertex2f(5.1527658058007, 3.8120443250206);
        glVertex2f(5.3709127066402, 3.1005522569746);
        glVertex2f(5.4600750247005, 3.2009153110112);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(6.6820918028911, 3.8120443250206);
        glVertex2f(6.568578717894, 3.8120443250206);
        glVertex2f(6.2619553550643, 2.6459356977337);
        glVertex2f(6.3825726469507, 2.6459356977337);
    glEnd();
    glPopMatrix();

    //
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(6.2619553550643,2.6459356977337);
        glVertex2f(6.3825726469507,2.6459356977337);
        glVertex2f(6.36351142344,2.5748518139094);
        glVertex2f(6.3582611779707,2.5538508320319);
        glVertex2f(6.3488107361258,2.5391501447177);
        glVertex2f(6.3362101469993,2.5265495555912);
        glVertex2f(6.325546128085,2.5138738821073);
        glVertex2f(6.3085391024886,2.5043499477733);
        glVertex2f(6.2915320768922,2.4948260134393);
        glVertex2f(6.2718039272004,2.4893837652485);
        glVertex2f(6.254796901604,2.4866626411531);
        glVertex2f(6.2303067847452,2.4853020791054);
        glVertex2f(6.2044561058387,2.4853020791054);
        glVertex2f(6.1867687992185,2.4873429221769);
        glVertex2f(6.2,2.5);
        glVertex2f(6.2167011642681,2.5091119149403);
        glVertex2f(6.2275856606498,2.5206766923459);
        glVertex2f(6.2323476278168,2.5363231558945);
        glVertex2f(6.2405110001031,2.562173834801);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    //akhir M

    //awal E
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(8.3119625360849,3.8029520806043);
        glVertex2f(8.2798210560114,3.6475461179827);
        glVertex2f(8.275467495114,3.6323086548418);
        glVertex2f(8.2667603733192,3.6148944112522);
        glVertex2f(8.2547880808513,3.5963917774382);
        glVertex2f(8.2417273981591,3.5822427045216);
        glVertex2f(8.2275783252425,3.5659168511563);
        glVertex2f(8.2140504577898,3.5511356145234);
        glVertex2f(8.196927391935,3.5372740850219);
        glVertex2f(8.1814350942569,3.5242279396087);
        glVertex2f(8.1610504920488,3.5095510260189);
        glVertex2f(8.1341428171342,3.4965048806058);
        glVertex2f(8.1023428376896,3.4916125760758);
        glVertex2f(7.3857797836057,3.4916125760758);
        glVertex2f(6.8566379639379,3.4916125760758);
        glVertex2f(6.9010234859113,3.6595569631829);
        glVertex2f(6.9081521571827,3.6830309724463);
        glVertex2f(6.9188717075461,3.7044700731732);
        glVertex2f(6.9320697412765,3.7241855955235);
        glVertex2f(6.9495728682287,3.7427826679102);
        glVertex2f(6.9659820497463,3.7575509312761);
        glVertex2f(6.9829904329181,3.7715781467228);
        glVertex2f(7.0043349424555,3.7843444574868);
        glVertex2f(7.0253866282013,3.7934668546433);
        glVertex2f(7.0470586323547,3.8002652338142);
        glVertex2f(7.0738928974172,3.8029520806043);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(7.3806553913788, 3.4990081757712);
        glVertex2f(7.3059593201442, 3.3068307106687);
        glVertex2f(6.7998975915065, 3.3068307106687);
        glVertex2f(6.8566379639379, 3.4916125760758);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(8.0040863646547, 3.3068307106687);
        glVertex2f(7.9510473100623, 3.1168935557095);
        glVertex2f(7.946425683745, 3.1038776302493);
        glVertex2f(7.9408623058148, 3.0927170268534);
        glVertex2f(7.9322634675513, 3.0831627621161);
        glVertex2f(7.9230276783053, 3.0707422179577);
        glVertex2f(7.9109256096382, 3.0592771002731);
        glVertex2f(7.9010528694097, 3.0487674090621);
        glVertex2f(7.8886323252513, 3.0398500953074);
        glVertex2f(7.8774856830579, 3.0312512570439);
        glVertex2f(7.8642773994721, 3.0240420589886);
        glVertex2f(7.8515277859122, 3.0172119088672);
        glVertex2f(7.8378674856694, 3.0112924454287);
        glVertex2f(7.8251178721094, 3.006283668673);
        glVertex2f(7.8137342885737, 3.0021855786002);
        glVertex2f(7.8, 3);
        glVertex2f(7.7868337642469, 2.9980440154411);
        glVertex2f(7.2554621275863, 2.9980440154411);
        glVertex2f(6.7158575325943, 2.9980440154411);
        glVertex2f(6.8087700757935, 3.3068307106687);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(7.2554621275863, 2.9980440154411);
        glVertex2f(7.1926071580313, 2.8018161727043);
        glVertex2f(6.6373577214013, 2.7050250658794);
        glVertex2f(6.7158575325943, 2.9980440154411);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(7.1926071580313, 2.8018161727043);
        glVertex2f(8.0584022950296, 2.8018161727043);
        glVertex2f(8.02, 2.64);
        glVertex2f(8.0163137901117, 2.6249235022962);
        glVertex2f(8.0090344005341, 2.6109470743071);
        glVertex2f(8.0004353721208, 2.5973772326727);
        glVertex2f(7.9939897366038, 2.5898120923274);
        glVertex2f(7.9880652610686, 2.579956967187);
        glVertex2f(7.9796368820479, 2.5715285881663);
        glVertex2f(7.9704422867526, 2.5627171010083);
        glVertex2f(7.9616307995946, 2.5562042626741);
        glVertex2f(7.9497544473382, 2.5473927755161);
        glVertex2f(7.94, 2.54);
        glVertex2f(7.928559740739, 2.5316784422725);
        glVertex2f(7.9166319326213, 2.5235334625377);
        glVertex2f(7.9073578209953, 2.516367103554);
        glVertex2f(7.8955544061985, 2.5075145424564);
        glVertex2f(7.8845940924587, 2.5045636887572);
        glVertex2f(7.8723691271335, 2.5016128350581);
        glVertex2f(7.8597226112799, 2.4973973297735);
        glVertex2f(7.8453898933124, 2.4957111276597);
        glVertex2f(7.8285278721742, 2.493181824489);
        glVertex2f(7.8120874015644, 2.4919171729036);
        glVertex2f(6.6879643624052, 2.4919171729036);
        glVertex2f(6.6697295615921, 2.5011059073155);
        glVertex2f(6.6599321915648, 2.5129658815591);
        glVertex2f(6.6511661236457, 2.5268884600189);
        glVertex2f(6.6424000557265, 2.542873642695);
        glVertex2f(6.6356965920236, 2.5567962211549);
        glVertex2f(6.631055732537, 2.573297054885);
        glVertex2f(6.6269305241045, 2.59547005021);
        glVertex2f(6.6252380409277, 2.6183417371756);
        glVertex2f(6.6257357536809, 2.6402410983169);
        glVertex2f(6.6289189626837, 2.6676534201301);
        glVertex2f(6.6373577214013, 2.7050250658794);
    glEnd();
    glPopMatrix();

    //bayangan E pertama

    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(8.5,3.8029520806043);
        glVertex2f(8.4,3.8029520806043);
        glVertex2f(8.3556903171755,3.6398657051416);
        glVertex2f(8.4634033595141,3.6398657051416);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.3556903171755,3.6398657051416);
        glVertex2f(8.4634033595141,3.6398657051416);
        glVertex2f(8.45, 3.6);
        glVertex2f(8.4392732163862, 3.5842945683199);
        glVertex2f(8.4316720944721, 3.5706125488744);
        glVertex2f(8.4185038100492, 3.5568385750882);
        glVertex2f(8.4022481071032, 3.5465718153329);
        glVertex2f(8.3885590940961, 3.5345939289516);
        glVertex2f(8.3714478278371, 3.5256105141657);
        glVertex2f(8.3560476882041, 3.5183382260056);
        glVertex2f(8.3393642036016, 3.5097825928762);
        glVertex2f(8.3209695923733, 3.5037936496855);
        glVertex2f(8.3, 3.5);
        glVertex2f(8.2775841447414, 3.5011165881456);
        glVertex2f(8.2595157459714, 3.5044017515583);
        glVertex2f(8.2406928833182, 3.5116702875109);
        glVertex2f(8.2552705669395, 3.5164194258241);
        glVertex2f(8.2683662017551, 3.5202102674813);
        glVertex2f(8.2800833486954, 3.5271027068579);
        glVertex2f(8.2911112516981, 3.5339951462345);
        glVertex2f(8.29938217895, 3.5439891833307);
        glVertex2f(8.3079977281708, 3.5553617083021);
        glVertex2f(8.3173025213293, 3.5708696968996);
    glEnd();
    glPopMatrix();

    //bayang E kedua
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(7.5550781830823,3.4429844524599);
        glVertex2f(7.4424029988565,3.4429844524599);
        glVertex2f(7.4181005081411,3.3612397109628);
        glVertex2f(7.5307176203868,3.3612397109628);
    glEnd();
    glPopMatrix();

    //bayangan E ketiga
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(8.2,3.3068307106687);
        glVertex2f(8.0883576045314,3.3068307106687);
        glVertex2f(8.0501503851752,3.1515538840225);
        glVertex2f(8.158683375938,3.1515538840225);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.0501503851752, 3.1515538840225);
        glVertex2f(8.158683375938, 3.1515538840225);
        glVertex2f(8.158683375938, 3.1363230876955);
        glVertex2f(8.1549318005289, 3.1235677313045);
        glVertex2f(8.1504073398929, 3.109983449976);
        glVertex2f(8.1427251705216, 3.0979114695353);
        glVertex2f(8.1347686379584, 3.088583121013);
        glVertex2f(8.1251659262443, 3.078706046107);
        glVertex2f(8.1138989752096, 3.0670864829112);
        glVertex2f(8.1026069733502, 3.0572673508595);
        glVertex2f(8.0903330582856, 3.0464663056027);
        glVertex2f(8.0790410564262, 3.036647173551);
        glVertex2f(8.0618575753358, 3.0268280414994);
        glVertex2f(8.0466379206557, 3.0189727358581);
        glVertex2f(8.0289634829627, 3.0135722132296);
        glVertex2f(8.0053975660388, 3.0052259509857);
        glVertex2f(7.9376455548823, 3.0076807339986);
        glVertex2f(7.9532341592745, 3.0148339861589);
        glVertex2f(7.9689835015054, 3.0251953955213);
        glVertex2f(7.9810027363658, 3.0368001740072);
        glVertex2f(7.9946797967242, 3.0513061471146);
        glVertex2f(8.0066990315845, 3.0645687510985);
        glVertex2f(8.02, 3.08);
        glVertex2f(8.0323953268033, 3.0977252610582);
        glVertex2f(8.0402699979187, 3.111816777791);
        glVertex2f(8.0456579307872, 3.1321251401414);
    glEnd();
    glPopMatrix();

    //bayangan E3
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(7.4346614079561, 2.9489102143313);
        glVertex2f(7.3261053035999, 2.9536691311249);
        glVertex2f(7.2959512295261, 2.8632069089036);
        glVertex2f(7.4047649780675, 2.8632069089036);
    glEnd();
    glPopMatrix();

    //bayangan e terakhir
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(8.2569004833216,2.7985566375596);
        glVertex2f(8.1410368546387,2.7985566375596);
        glVertex2f(8.1060083157346,2.6712413711581);
        glVertex2f(8.2178301899286,2.662484236432);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(8.1060083157346, 2.6712413711581);
        glVertex2f(8.2178301899286, 2.662484236432);
        glVertex2f(8.2119773146279, 2.6385176570862);
        glVertex2f(8.2051887082181, 2.6222250017027);
        glVertex2f(8.1977212411673, 2.6066112069602);
        glVertex2f(8.1875383315526, 2.5876031090128);
        glVertex2f(8.1766765612969, 2.5726681749112);
        glVertex2f(8.1644570697593, 2.5611275440145);
        glVertex2f(8.15, 2.55);
        glVertex2f(8.1359449228381, 2.5407617247852);
        glVertex2f(8.1223677100185, 2.5332942577344);
        glVertex2f(8.1047173333531, 2.5237902087607);
        glVertex2f(8.0870669566876, 2.5190381842738);
        glVertex2f(8.0687377193811, 2.5142861597869);
        glVertex2f(8.0436198756649, 2.5095341353001);
        glVertex2f(8.0239329170765, 2.511570717223);
        glVertex2f(8.006961401052, 2.5170016023509);
        glVertex2f(8.0239329170765, 2.5305788151705);
        glVertex2f(8.0415832937419, 2.5414405854261);
        glVertex2f(8.0592336704074, 2.5577332408096);
        glVertex2f(8.074168604509, 2.5760624781161);
        glVertex2f(8.0816360715597, 2.5916762728586);
        glVertex2f(8.0897823992515, 2.6106843708061);
        glVertex2f(8.0952132843793, 2.6303713293945);
        glVertex2f(8.1, 2.65);
    glEnd();
    glPopMatrix();

    //awal O

    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(2.7339472183724, 1.7681242313563);
        glVertex2f(2.7392144017013, 1.7830085637688);
        glVertex2f(2.7433454316629, 1.7961527500102);
        glVertex2f(2.7459742689111, 1.8077947435383);
        glVertex2f(2.7478520098028, 1.8183100925314);
        glVertex2f(2.7497297506944, 1.8284498933462);
        glVertex2f(2.7493542025161, 1.8382141459827);
        glVertex2f(2.7474764616244, 1.8472273022625);
        glVertex2f(2.7452231725545, 1.8554893621856);
        glVertex2f(2.7414676907712, 1.8633758739305);
        glVertex2f(2.737712208988, 1.8716379338536);
        glVertex2f(2.7320789863131, 1.8787733492418);
        glVertex2f(2.727032501856, 1.8876547128397);
        glVertex2f(2.7207820044274, 1.8945631573661);
        glVertex2f(2.7151894540965, 1.9008136547948);
        glVertex2f(2.7082810095701, 1.9067351786745);
        glVertex2f(2.700385644397, 1.9119987554566);
        glVertex2f(2.6918323321263, 1.9169333586897);
        glVertex2f(2.6839369669532, 1.9205520677273);
        glVertex2f(2.6740677604869, 1.9238418032161);
        glVertex2f(2.6661723953139, 1.9281184593515);
        glVertex2f(2.655316268201, 1.9297633270959);
        glVertex2f(2.6437490684794, 1.9301240418515);
        glVertex2f(1.4540514330533, 1.9301240418515);
        glVertex2f(1.4313621699985, 1.9294024736949);
        glVertex2f(1.4169744790873, 1.9288595419624);
        glVertex2f(1.4051108838507, 1.9276144529326);
        glVertex2f(1.3948039756814, 1.9243213323547);
        glVertex2f(1.3847750027698, 1.9211302955192);
        glVertex2f(1.3747460298583, 1.9174833962787);
        glVertex2f(1.3644961115069, 1.9117380392183);
        glVertex2f(1.3561280994091, 1.9055390809109);
        glVertex2f(1.3478584606642, 1.8998537042738);
        glVertex2f(1.3395888219193, 1.8944267538475);
        glVertex2f(1.3308023307529, 1.8874492461565);
        glVertex2f(1.3225007985706, 1.878172928428);
        glVertex2f(1.3132293484201, 1.8698762638237);
        glVertex2f(1.3031507261998, 1.8585055105495);
        glVertex2f(1.2946488272929, 1.8468394607405);
        glVertex2f(1.286815460371, 1.8359597844602);
        glVertex2f(1.2789820934491, 1.8242097340774);
        glVertex2f(1.2681794969165, 1.8067154942038);
        glVertex2f(1.2571581837235, 1.7681242313563);
    glEnd();
    glPopMatrix();

    //O bawah
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(1.2571581837235,1.7864265410564);
        glVertex2f(1.4051108838507, 1.9276144529326);
        glVertex2f(1.3948039756814, 1.9243213323547);
        glVertex2f(1.3847750027698, 1.9211302955192);
        glVertex2f(1.3747460298583, 1.9174833962787);
        glVertex2f(1.3644961115069, 1.9117380392183);
        glVertex2f(1.3561280994091, 1.9055390809109);
        glVertex2f(1.3478584606642, 1.8998537042738);
        glVertex2f(1.3395888219193, 1.8944267538475);
        glVertex2f(1.3308023307529, 1.8874492461565);
        glVertex2f(1.3225007985706, 1.878172928428);
        glVertex2f(1.3132293484201, 1.8698762638237);
        glVertex2f(1.3031507261998, 1.8585055105495);
        glVertex2f(1.2946488272929, 1.8468394607405);
        glVertex2f(1.286815460371, 1.8359597844602);
        glVertex2f(1.2789820934491, 1.8242097340774);
        glVertex2f(1.2681794969165, 1.8067154942038);
        glVertex2f(1.2571581837235, 1.7864265410564);
        glVertex2f(0.9873823164991, 0.7598128965055);
        glVertex2f(0.9800515833047, 0.7484504665109);
        glVertex2f(0.9759066470265, 0.7364301513042);
        glVertex2f(0.9742486725153, 0.7244098360976);
        glVertex2f(0.9754313367219, 0.7131208960467);
        glVertex2f(0.97715012791, 0.7049286355903);
        glVertex2f(0.9800515833047, 0.6962242694062);
        glVertex2f(0.9841965195828, 0.6871054095942);
        glVertex2f(0.9891704431166, 0.6792300306658);
        glVertex2f(1.02, 0.64);
        glVertex2f(1.0343725168035, 0.6254218456817);
        glVertex2f(1.0430549208062, 0.6175663372983);
        glVertex2f(1.0533911160475, 0.6109511723439);
        glVertex2f(1.0637273112888, 0.6068166942474);
        glVertex2f(1.075303849959, 0.6043360073895);
        glVertex2f(1.0865196630656, 0.6030987241946);
        glVertex2f(1.1024529556541, 0.6031293650863);
        glVertex2f(2.2907631925546, 0.6031293650863);
        glVertex2f(2.3016660583463, 0.6046844699874);
        glVertex2f(2.3158430626154, 0.6081207547576);
        glVertex2f(2.3262606422417, 0.6112460286455);
        glVertex2f(2.3366782218679, 0.6143713025333);
        glVertex2f(2.3491793174194, 0.6195800923464);
        glVertex2f(2.3616804129709, 0.6258306401222);
        glVertex2f(2.3741815085224, 0.6320811878979);
        glVertex2f(2.3840782091673, 0.6404152515989);
        glVertex2f(2.3962010232657, 0.6493073844003);
        glVertex2f(2.4055772990927, 0.6575116257489);
        glVertex2f(2.4157349312386, 0.6684506142137);
        glVertex2f(2.4263391912876, 0.6791457070894);
        glVertex2f(2.4343344201301, 0.6911385503533);
        glVertex2f(2.4423296489727, 0.7028458497299);
        glVertex2f(2.450075160811, 0.7142643946811);
        glVertex2f(2.455983123379, 0.7243079310469);
        glVertex2f(2.4613002896903, 0.7340560692842);
        glVertex2f(2.4640472089567, 0.7445831185102);
        glVertex2f(2.7339472183724, 1.7681242313563);
    glEnd();
    glPopMatrix();

    //O tengah
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(1.763364100072,1.633141817858);
        glVertex2f(2.151941866678,1.633141817858);
        glVertex2f(1.9582245517622,0.9103849363812);
        glVertex2f(1.5748940086385,0.9103849363812);
    glEnd();
    glPopMatrix();

    //bayangan O
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
    glVertex2f(1.8294831486332,1.5857110816327);
    glVertex2f(1.9447812025967,1.5857110816327);
    glVertex2f(1.7875443345023,0.971970986103);
    glVertex2f(1.6668644418056,0.971970986103);
    glEnd();
    glPopMatrix();

    //awal v
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(3.7229425056301, 1.0513470750063);
        glVertex2f(3.6158627534089, 1.8858093921351);
        glVertex2f(3.6131184230783, 1.8956879810402);
        glVertex2f(3.6101956685344, 1.904456244672);
        glVertex2f(3.605717595406, 1.9119941553092);
        glVertex2f(3.600788120568, 1.9169615612035);
        glVertex2f(3.5955960861732, 1.9216343921588);
        glVertex2f(3.5901444500586, 1.9265668248339);
        glVertex2f(3.5839140087848, 1.9302012489103);
        glVertex2f(3.5782027709505, 1.9325376643879);
        glVertex2f(3.5715626916985, 1.934724043607);
        glVertex2f(3.5652226849635, 1.9359124867446);
        glVertex2f(3.0004253242714, 1.9394895409054);
        glVertex2f(3.2227313296349, 0.7076685969358);
        glVertex2f(3.2246026503672, 0.6958317981125);
        glVertex2f(3.2278996902435, 0.6801708586999);
        glVertex2f(3.2353180299652, 0.6682190891482);
        glVertex2f(3.2452091495942, 0.6562673195965);
        glVertex2f(3.2551002692232, 0.6439034200603);
        glVertex2f(3.267876298744, 0.631539520524);
        glVertex2f(3.28, 0.62);
        glVertex2f(3.2954890077083, 0.6142300611733);
        glVertex2f(3.3176039391923, 0.6111428647091);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(3.3176039391923, 0.6111428647091);
    glVertex2f(3.8897748353522, 0.6111428647091);
    glVertex2f(3.901774799637, 0.6116211143414);
    glVertex2f(3.9159331096592, 0.6146079663227);
    glVertex2f(3.9284993625516, 0.6169350501917);
    glVertex2f(3.9429272825392, 0.6211238011558);
    glVertex2f(3.9578206193006, 0.6262433856675);
    glVertex2f(3.9731793728358, 0.6327592205007);
    glVertex2f(3.9876072928234, 0.6402058888814);
    glVertex2f(4.0006389624897, 0.6518413082262);
    glVertex2f(4.0122743818345, 0.663476727571);
    glVertex2f(4.0280900908864, 0.6789892696743);
    glVertex2f(4.0420251120882, 0.6927657522559);
    glVertex2f(4.8403432794202, 1.9394895409054);
    glVertex2f(4.4378534348221, 1.9394895409054);
    glVertex2f(4.4198998020627, 1.9384317156367);
    glVertex2f(4.4045911603994, 1.9360145616899);
    glVertex2f(4.3885738161615, 1.9331721861983);
    glVertex2f(4.3715567231259, 1.9295688178316);
    glVertex2f(4.3540469878585, 1.9245404791226);
    glVertex2f(4.3387755061092, 1.9205566143184);
    glVertex2f(4.3254959567619, 1.9185646819163);
    glVertex2f(4.3102244750125, 1.9099329748405);
    glVertex2f(4.297708053785, 1.9037193267031);
    glVertex2f(4.2841806278067, 1.8919955575219);
    glVertex2f(4.2724568586255, 1.8811736167392);
    glVertex2f(3.7229425056301, 1.0513470750063);
    glEnd();
    glPopMatrix();

    //bayangan v 1
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(3.8700004649691,1.4261076239712);
        glVertex2f(3.7813149401028,1.2991955797659);
        glVertex2f(3.6966357298939, 1.9099941968784);
        glVertex2f(3.6724966317016, 1.9408386001241);
        glVertex2f(3.7489371093105, 1.9448617831561);
        glVertex2f(3.8012384887271, 1.9180405629425);
    glEnd();
    glPopMatrix();

    //bayangan v 2
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(5.0361571159137, 1.930097990517);
        glVertex2f(4.9231833775706, 1.9362378676008);
        glVertex2f(4.1165211705517, 0.68730253212);
        glVertex2f(4.0331225049526, 0.61031914849);
        glVertex2f(4.1261440935055, 0.6167344304592);
        glVertex2f(4.2127504000892, 0.6616414042433);
    glEnd();
    glPopMatrix();

    //awal e2
    glPushMatrix();
    glTranslated(-1.68,-1.87,0);
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(8.3119625360849,3.8029520806043);
        glVertex2f(8.2798210560114,3.6475461179827);
        glVertex2f(8.275467495114,3.6323086548418);
        glVertex2f(8.2667603733192,3.6148944112522);
        glVertex2f(8.2547880808513,3.5963917774382);
        glVertex2f(8.2417273981591,3.5822427045216);
        glVertex2f(8.2275783252425,3.5659168511563);
        glVertex2f(8.2140504577898,3.5511356145234);
        glVertex2f(8.196927391935,3.5372740850219);
        glVertex2f(8.1814350942569,3.5242279396087);
        glVertex2f(8.1610504920488,3.5095510260189);
        glVertex2f(8.1341428171342,3.4965048806058);
        glVertex2f(8.1023428376896,3.4916125760758);
        glVertex2f(7.3857797836057,3.4916125760758);
        glVertex2f(6.8566379639379,3.4916125760758);
        glVertex2f(6.9010234859113,3.6595569631829);
        glVertex2f(6.9081521571827,3.6830309724463);
        glVertex2f(6.9188717075461,3.7044700731732);
        glVertex2f(6.9320697412765,3.7241855955235);
        glVertex2f(6.9495728682287,3.7427826679102);
        glVertex2f(6.9659820497463,3.7575509312761);
        glVertex2f(6.9829904329181,3.7715781467228);
        glVertex2f(7.0043349424555,3.7843444574868);
        glVertex2f(7.0253866282013,3.7934668546433);
        glVertex2f(7.0470586323547,3.8002652338142);
        glVertex2f(7.0738928974172,3.8029520806043);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(7.3806553913788, 3.4990081757712);
        glVertex2f(7.3059593201442, 3.3068307106687);
        glVertex2f(6.7998975915065, 3.3068307106687);
        glVertex2f(6.8566379639379, 3.4916125760758);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(8.0040863646547, 3.3068307106687);
        glVertex2f(7.9510473100623, 3.1168935557095);
        glVertex2f(7.946425683745, 3.1038776302493);
        glVertex2f(7.9408623058148, 3.0927170268534);
        glVertex2f(7.9322634675513, 3.0831627621161);
        glVertex2f(7.9230276783053, 3.0707422179577);
        glVertex2f(7.9109256096382, 3.0592771002731);
        glVertex2f(7.9010528694097, 3.0487674090621);
        glVertex2f(7.8886323252513, 3.0398500953074);
        glVertex2f(7.8774856830579, 3.0312512570439);
        glVertex2f(7.8642773994721, 3.0240420589886);
        glVertex2f(7.8515277859122, 3.0172119088672);
        glVertex2f(7.8378674856694, 3.0112924454287);
        glVertex2f(7.8251178721094, 3.006283668673);
        glVertex2f(7.8137342885737, 3.0021855786002);
        glVertex2f(7.8, 3);
        glVertex2f(7.7868337642469, 2.9980440154411);
        glVertex2f(7.2554621275863, 2.9980440154411);
        glVertex2f(6.7158575325943, 2.9980440154411);
        glVertex2f(6.8087700757935, 3.3068307106687);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(7.2554621275863, 2.9980440154411);
        glVertex2f(7.1926071580313, 2.8018161727043);
        glVertex2f(6.6373577214013, 2.7050250658794);
        glVertex2f(6.7158575325943, 2.9980440154411);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(7.1926071580313, 2.8018161727043);
        glVertex2f(8.0584022950296, 2.8018161727043);
        glVertex2f(8.02, 2.64);
        glVertex2f(8.0163137901117, 2.6249235022962);
        glVertex2f(8.0090344005341, 2.6109470743071);
        glVertex2f(8.0004353721208, 2.5973772326727);
        glVertex2f(7.9939897366038, 2.5898120923274);
        glVertex2f(7.9880652610686, 2.579956967187);
        glVertex2f(7.9796368820479, 2.5715285881663);
        glVertex2f(7.9704422867526, 2.5627171010083);
        glVertex2f(7.9616307995946, 2.5562042626741);
        glVertex2f(7.9497544473382, 2.5473927755161);
        glVertex2f(7.94, 2.54);
        glVertex2f(7.928559740739, 2.5316784422725);
        glVertex2f(7.9166319326213, 2.5235334625377);
        glVertex2f(7.9073578209953, 2.516367103554);
        glVertex2f(7.8955544061985, 2.5075145424564);
        glVertex2f(7.8845940924587, 2.5045636887572);
        glVertex2f(7.8723691271335, 2.5016128350581);
        glVertex2f(7.8597226112799, 2.4973973297735);
        glVertex2f(7.8453898933124, 2.4957111276597);
        glVertex2f(7.8285278721742, 2.493181824489);
        glVertex2f(7.8120874015644, 2.4919171729036);
        glVertex2f(6.6879643624052, 2.4919171729036);
        glVertex2f(6.6697295615921, 2.5011059073155);
        glVertex2f(6.6599321915648, 2.5129658815591);
        glVertex2f(6.6511661236457, 2.5268884600189);
        glVertex2f(6.6424000557265, 2.542873642695);
        glVertex2f(6.6356965920236, 2.5567962211549);
        glVertex2f(6.631055732537, 2.573297054885);
        glVertex2f(6.6269305241045, 2.59547005021);
        glVertex2f(6.6252380409277, 2.6183417371756);
        glVertex2f(6.6257357536809, 2.6402410983169);
        glVertex2f(6.6289189626837, 2.6676534201301);
        glVertex2f(6.6373577214013, 2.7050250658794);
    glEnd();
    glPopMatrix();

    //bayangan E pertama

    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(8.5,3.8029520806043);
        glVertex2f(8.4,3.8029520806043);
        glVertex2f(8.3556903171755,3.6398657051416);
        glVertex2f(8.4634033595141,3.6398657051416);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.3556903171755,3.6398657051416);
        glVertex2f(8.4634033595141,3.6398657051416);
        glVertex2f(8.45, 3.6);
        glVertex2f(8.4392732163862, 3.5842945683199);
        glVertex2f(8.4316720944721, 3.5706125488744);
        glVertex2f(8.4185038100492, 3.5568385750882);
        glVertex2f(8.4022481071032, 3.5465718153329);
        glVertex2f(8.3885590940961, 3.5345939289516);
        glVertex2f(8.3714478278371, 3.5256105141657);
        glVertex2f(8.3560476882041, 3.5183382260056);
        glVertex2f(8.3393642036016, 3.5097825928762);
        glVertex2f(8.3209695923733, 3.5037936496855);
        glVertex2f(8.3, 3.5);
        glVertex2f(8.2775841447414, 3.5011165881456);
        glVertex2f(8.2595157459714, 3.5044017515583);
        glVertex2f(8.2406928833182, 3.5116702875109);
        glVertex2f(8.2552705669395, 3.5164194258241);
        glVertex2f(8.2683662017551, 3.5202102674813);
        glVertex2f(8.2800833486954, 3.5271027068579);
        glVertex2f(8.2911112516981, 3.5339951462345);
        glVertex2f(8.29938217895, 3.5439891833307);
        glVertex2f(8.3079977281708, 3.5553617083021);
        glVertex2f(8.3173025213293, 3.5708696968996);
    glEnd();
    glPopMatrix();

    //bayang E kedua
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(7.5550781830823,3.4429844524599);
        glVertex2f(7.4424029988565,3.4429844524599);
        glVertex2f(7.4181005081411,3.3612397109628);
        glVertex2f(7.5307176203868,3.3612397109628);
    glEnd();
    glPopMatrix();

    //bayangan E ketiga
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(8.2,3.3068307106687);
        glVertex2f(8.0883576045314,3.3068307106687);
        glVertex2f(8.0501503851752,3.1515538840225);
        glVertex2f(8.158683375938,3.1515538840225);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(8.0501503851752, 3.1515538840225);
        glVertex2f(8.158683375938, 3.1515538840225);
        glVertex2f(8.158683375938, 3.1363230876955);
        glVertex2f(8.1549318005289, 3.1235677313045);
        glVertex2f(8.1504073398929, 3.109983449976);
        glVertex2f(8.1427251705216, 3.0979114695353);
        glVertex2f(8.1347686379584, 3.088583121013);
        glVertex2f(8.1251659262443, 3.078706046107);
        glVertex2f(8.1138989752096, 3.0670864829112);
        glVertex2f(8.1026069733502, 3.0572673508595);
        glVertex2f(8.0903330582856, 3.0464663056027);
        glVertex2f(8.0790410564262, 3.036647173551);
        glVertex2f(8.0618575753358, 3.0268280414994);
        glVertex2f(8.0466379206557, 3.0189727358581);
        glVertex2f(8.0289634829627, 3.0135722132296);
        glVertex2f(8.0053975660388, 3.0052259509857);
        glVertex2f(7.9376455548823, 3.0076807339986);
        glVertex2f(7.9532341592745, 3.0148339861589);
        glVertex2f(7.9689835015054, 3.0251953955213);
        glVertex2f(7.9810027363658, 3.0368001740072);
        glVertex2f(7.9946797967242, 3.0513061471146);
        glVertex2f(8.0066990315845, 3.0645687510985);
        glVertex2f(8.02, 3.08);
        glVertex2f(8.0323953268033, 3.0977252610582);
        glVertex2f(8.0402699979187, 3.111816777791);
        glVertex2f(8.0456579307872, 3.1321251401414);
    glEnd();
    glPopMatrix();

    //bayangan E3
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(7.4346614079561, 2.9489102143313);
        glVertex2f(7.3261053035999, 2.9536691311249);
        glVertex2f(7.2959512295261, 2.8632069089036);
        glVertex2f(7.4047649780675, 2.8632069089036);
    glEnd();
    glPopMatrix();

    //bayangan e terakhir
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(8.2569004833216,2.7985566375596);
        glVertex2f(8.1410368546387,2.7985566375596);
        glVertex2f(8.1060083157346,2.6712413711581);
        glVertex2f(8.2178301899286,2.662484236432);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(8.1060083157346, 2.6712413711581);
        glVertex2f(8.2178301899286, 2.662484236432);
        glVertex2f(8.2119773146279, 2.6385176570862);
        glVertex2f(8.2051887082181, 2.6222250017027);
        glVertex2f(8.1977212411673, 2.6066112069602);
        glVertex2f(8.1875383315526, 2.5876031090128);
        glVertex2f(8.1766765612969, 2.5726681749112);
        glVertex2f(8.1644570697593, 2.5611275440145);
        glVertex2f(8.15, 2.55);
        glVertex2f(8.1359449228381, 2.5407617247852);
        glVertex2f(8.1223677100185, 2.5332942577344);
        glVertex2f(8.1047173333531, 2.5237902087607);
        glVertex2f(8.0870669566876, 2.5190381842738);
        glVertex2f(8.0687377193811, 2.5142861597869);
        glVertex2f(8.0436198756649, 2.5095341353001);
        glVertex2f(8.0239329170765, 2.511570717223);
        glVertex2f(8.006961401052, 2.5170016023509);
        glVertex2f(8.0239329170765, 2.5305788151705);
        glVertex2f(8.0415832937419, 2.5414405854261);
        glVertex2f(8.0592336704074, 2.5577332408096);
        glVertex2f(8.074168604509, 2.5760624781161);
        glVertex2f(8.0816360715597, 2.5916762728586);
        glVertex2f(8.0897823992515, 2.6106843708061);
        glVertex2f(8.0952132843793, 2.6303713293945);
        glVertex2f(8.1, 2.65);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //awal R
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(7.0743177440723, 0.6744842117039);
        glVertex2f(7.0641327770535, 0.6569146611829);
        glVertex2f(7.0497242608912, 0.6407050805003);
        glVertex2f(7.0323139705284, 0.626296564338);
        glVertex2f(7.0101008414449, 0.613689112696);
        glVertex2f(6.9880239083402, 0.6067068443533);
        glVertex2f(6.9614720993971, 0.603203026549);
        glVertex2f(6.517431320735, 0.603203026549);
        glVertex2f(6.8339824742981, 1.8218551448202);
        glVertex2f(6.8405126455629, 1.835786176852);
        glVertex2f(6.8505255748358, 1.8488465193817);
        glVertex2f(6.8593018261124, 1.8613417729821);
        glVertex2f(6.8690849629932, 1.8725520498281);
        glVertex2f(6.8809461845033, 1.8855993934891);
        glVertex2f(6.8945865892398, 1.9010189814522);
        glVertex2f(6.9103267906789, 1.9113127368725);
        glVertex2f(6.9263020966243, 1.9214534517325);
        glVertex2f(6.9432540067972, 1.9289499535644);
        glVertex2f(6.9615384863389, 1.9359154695802);
        glVertex2f(6.98, 1.94);
        glVertex2f(7.3990463469573, 1.94);
        glVertex2f(7.1678818620606, 0.998128296237);
    glEnd();
    glPopMatrix();

    //R kedua
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(7.3990463469573, 1.94);
        glVertex2f(8.2518290018053, 1.94);
        glVertex2f(8.2666590862535, 1.9370614344032);
        glVertex2f(8.2803239846101, 1.9322667332254);
        glVertex2f(8.2927902076723, 1.9253144165177);
        glVertex2f(8.3070286384043, 1.9158286237498);
        glVertex2f(8.3191870266595, 1.9056966335371);
        glVertex2f(8.3326963469431, 1.8928627792677);
        glVertex2f(8.3431660701629, 1.8773270609416);
        glVertex2f(8.350933929326, 1.8628045416367);
        glVertex2f(8.3573508564607, 1.8442292262468);
        glVertex2f(8.3597149875103, 1.8239652458214);
        glVertex2f(8.3556621914252, 1.7996484693109);
        glVertex2f(8.1723842238113, 1.112755253513);
        glVertex2f(8.1642479318212, 1.0958046452003);
        glVertex2f(8.1569976521611, 1.0838674955565);
        glVertex2f(8.147804303098, 1.073360810913);
        glVertex2f(8.1363126167691, 1.0598991212135);
        glVertex2f(8.1235075948599, 1.0470940993042);
        glVertex2f(8.1084753277126, 1.0349618526825);
        glVertex2f(8.0951465080887, 1.0252272924229);
        glVertex2f(8.0807451902323, 1.0157543230862);
        glVertex2f(8.0640306886919, 1.0075795142576);
        glVertex2f(8.0459184953117, 0.99829120996);
        glVertex2f(8.0273418867166, 0.9936470578113);
        glVertex2f(8.0073720324769, 0.9894673208774);
        glVertex2f(7.9850801021628, 0.9899317360922);
        glVertex2f(7.9604660957743, 0.9880740752327);
        glVertex2f(7.9335300133115, 0.9903961513071);
        glVertex2f(7.9000921178403, 0.9973623795303);
        glVertex2f(7.3087147471989, 0.998128296237);
        glVertex2f(7.1678818620606, 0.998128296237);
    glEnd();
    glPopMatrix();

    //R terakhir
    glPushMatrix();
    glColor3ub(252, 0, 252);
    glBegin(GL_POLYGON);
        glVertex2f(7.9000921178403, 0.9973623795303);
        glVertex2f(8.0714890415766, 0.603203026549);
        glVertex2f(7.5745906010666, 0.603203026549);
        glVertex2f(7.5596910984844, 0.6049554976511);
        glVertex2f(7.5453982573963, 0.6092851487686);
        glVertex2f(7.5281042156963, 0.6183645206611);
        glVertex2f(7.5151336844213, 0.6274438925536);
        glVertex2f(7.5025955041888, 0.6412791259136);
        glVertex2f(7.4922190791688, 0.6546820082311);
        glVertex2f(7.4827073562338, 0.6711113478461);
        glVertex2f(7.4755903802597, 0.6874679714345);
        glVertex2f(7.35, 0.95);
        glVertex2f(7.3087147471989, 0.998128296237);
    glEnd();
    glPopMatrix();

    //kotak R tengah
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(7.2441890655993,1.3030071674191);
        glVertex2f(7.6726837432693,1.3030071674191);
        glVertex2f(7.7612050988359,1.6340000621463);
        glVertex2f(7.3327104211659,1.6340000621463);
    glEnd();
    glPopMatrix();

    //bayangan R dalam
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
    glVertex2f(7.3378420939523,1.3556068134804);
    glVertex2f(7.4507388952546,1.3556068134804);
    glVertex2f(7.509753132299,1.5724199887087);
    glVertex2f(7.3968563309967,1.5724199887087);
    glEnd();
    glPopMatrix();

    //bayangan R kanan atas
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(8.3866835193382, 1.9402644441134);
        glVertex2f(8.4440671698472, 1.9477492680928);
        glVertex2f(8.5239052922945, 1.9003453828897);
        glVertex2f(8.5538445882123, 1.8429617323807);
        glVertex2f(8.5513496468858, 1.8005477298305);
        glVertex2f(8.4354934783018,1.8075109462185);
        glVertex2f(8.4286281768632,1.8830292620439);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(8.5513496468858, 1.8005477298305);
        glVertex2f(8.3589699855782, 1.0990954635759);
        glVertex2f(8.2594992216485, 1.0115611913178);
        glVertex2f(8.1421237202116, 0.9876882079747);
        glVertex2f(8.2128996056467, 1.0427395104236);
        glVertex2f(8.2442782417739, 1.0751635054607);
         glVertex2f(8.4286281768632,1.8830292620439);
    glEnd();
    glPopMatrix();

    //bayangan R kanan bawah
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(8.1045655622626,0.9628379174351);
        glVertex2f(8.0157985796697,0.9318937457021);
        glVertex2f(8.168547548426,0.60764506635);
        glVertex2f(8.2693375015592,0.617131179586);
    glEnd();
    glPopMatrix();


    //bayangan R kiri bawah
    glPushMatrix();
    glColor3ub(20, 209, 229);
    glBegin(GL_POLYGON);
        glVertex2f(7.2339246534783, 0.9354566005677);
        glVertex2f(7.2707795772728, 0.9268970635755);
        glVertex2f(7.3023781736802, 0.8927705794554);
        glVertex2f(7.3156495841714, 0.8358931059219);
        glVertex2f(7.2699703327214, 0.6560078697452);
        glVertex2f(7.241703677253, 0.631687253377);
        glVertex2f(7.1905171377672, 0.6201290025254);
        glVertex2f(7.1104349711522, 0.613524287753);
        glVertex2f(7.150888849133, 0.6630596485458);
    glEnd();
    glPopMatrix();

    //////////////////////////////////////
    glPopMatrix();//penutup seluruhnya
}

void congratulations(){
                        glPushMatrix();//untuk seluruh vertex
                        glTranslated(0,2,0);
//awal C
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(0.4912105635934, 1.4540625057374);
    glVertex2f(0.4813731683802, 1.4464045315534);
    glVertex2f(0.3013156716728, 0.5899285305152);
    glVertex2f(0.3102007516747, 0.5828343517185);
    glVertex2f(0.2540422957541, 0.4179141936715);
    glVertex2f(0.2339940064186, 0.4206882828239);
    glVertex2f(0.2164071418741, 0.4251872481725);
    glVertex2f(0.2033192426781, 0.4305042072209);
    glVertex2f(0.1898223466323, 0.4358211662692);
    glVertex2f(0.177961437986, 0.4440011032667);
    glVertex2f(0.1673275198893, 0.4529990339639);
    glVertex2f(0.16, 0.46);
    glVertex2f(0.152194636444, 0.4677229205593);
    glVertex2f(0.1448326931463, 0.478356838656);
    glVertex2f(0.139515734098, 0.4902177473023);
    glVertex2f(0.1350167687494, 0.5045326370479);
    glVertex2f(0.1309268002507, 0.5213015078926);
    glVertex2f(0.3344115988507, 1.5023080894842);
    glVertex2f(0.3409230538382, 1.5150366232843);
    glVertex2f(0.3487657447579, 1.5265555755728);
    glVertex2f(0.3553830152215, 1.5363589392225);
    glVertex2f(0.3622453697763, 1.5466524710547);
    glVertex2f(0.3705782288786, 1.5547402460657);
    glVertex2f(0.3786660038896, 1.563073105168);
    glVertex2f(0.3864006840364, 1.5712403433883);
    glVertex2f(0.3963240041585, 1.5791422464485);
    glVertex2f(0.4071661502179, 1.586309088759);
    glVertex2f(0.4204302592381, 1.594993971361);
    glVertex2f(0.4367523453969, 1.6022966600668);
    glVertex2f(0.4458018696856, 1.6069391567121);
    glVertex2f(0.4644446282123, 1.6138647872226);
    glVertex2f(0.4820900108678, 1.6175085182215);
    glVertex2f(0.7466961426291, 1.6175085182215);
glEnd();

//lanjutan
glBegin(GL_POLYGON);
    glVertex2f(0.7466961426291, 1.6175085182215);
    glVertex2f(0.7586711305632, 1.6136621046952);
    glVertex2f(0.772079993907, 1.6088120902943);
    glVertex2f(0.7854888572508, 1.6031061909991);
    glVertex2f(0.7963300659117, 1.5974002917038);
    glVertex2f(0.8063153896784, 1.588841442761);
    glVertex2f(0.8140183537269, 1.5822796585715);
    glVertex2f(0.8205801379165, 1.5751472844524);
    glVertex2f(0.8274272170707, 1.5654472556505);
    glVertex2f(0.8334184113307, 1.5546060469896);
    glVertex2f(0.8374125408374, 1.5423383635048);
    glVertex2f(0.8440107858802, 1.5191479109397);
    glVertex2f(0.8477581899074, 1.4934484463566);
    glVertex2f(0.8434708484957, 1.4695107901408);
    glVertex2f(0.7870871763734, 1.2064680934107);
    glVertex2f(0.6252730526488, 1.2073696043185);
    glVertex2f(0.6727659900332, 1.4540625057374);
glEnd();
glBegin(GL_POLYGON);
    glVertex2f(0.6727659900332, 1.4540625057374);
    glVertex2f(0.4912105635934, 1.4540625057374);
    glVertex2f(0.4820900108678, 1.6175085182215);
    glVertex2f(0.7466961426291, 1.6175085182215);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(0.4839541141559, 0.5828343517185);
    glVertex2f(0.4923176868774, 0.5916701671833);
    glVertex2f(0.5463398900637, 0.8362228678038);
    glVertex2f(0.7127634212064, 0.8362228678038);
    glVertex2f(0.651979600917, 0.5652512739126);
    glVertex2f(0.6458311640388, 0.548297858353);
    glVertex2f(0.640466431371, 0.5369372479977);
    glVertex2f(0.635732843723, 0.526523355172);
    glVertex2f(0.6291058210158, 0.5151627448168);
    glVertex2f(0.6217262524165, 0.5049875946454);
    glVertex2f(0.6136292339149, 0.4942543375619);
    glVertex2f(0.6076035457277, 0.487852043863);
    glVertex2f(0.602142765808, 0.4825795666991);
    glVertex2f(0.5968702886442, 0.4769304840236);
    glVertex2f(0.59, 0.47);
    glVertex2f(0.5836890957347, 0.4646908048933);
    glVertex2f(0.5759686827448, 0.4586651167061);
    glVertex2f(0.5684365725108, 0.453769245054);
    glVertex2f(0.56, 0.45);
    glVertex2f(0.5496062969257, 0.4441658045056);
    glVertex2f(0.5415092784241, 0.4390816300976);
    glVertex2f(0.532847351655, 0.4347506667131);
    glVertex2f(0.5241854248858, 0.4304197033285);
    glVertex2f(0.5138287733141, 0.427218556479);
    glVertex2f(0.5019728144843, 0.4228635035861);
    glVertex2f(0.4842636929856, 0.420180303359);
    glVertex2f(0.4637402402578, 0.4179141936715);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(0.4839541141559, 0.5828343517185);
    glVertex2f(0.3102007516747, 0.5828343517185);
    glVertex2f(0.2540422957541, 0.4179141936715);
    glVertex2f(0.4637402402578, 0.4179141936715);
glEnd();
glPopMatrix();

//awal O
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(1.2091026604557, 1.4502078872616);
    glVertex2f(1.0289308590086, 0.5892118899818);
    glVertex2f(0.9773326187627, 0.4189382507422);
    glVertex2f(0.9457945935847, 0.4239823160459);
    glVertex2f(0.9258649879336, 0.4297196267637);
    glVertex2f(0.915296257664, 0.4342490825935);
    glVertex2f(0.9053314548384, 0.4408922844772);
    glVertex2f(0.8980843255107, 0.445723704029);
    glVertex2f(0.892045051071, 0.4514610147468);
    glVertex2f(0.8863077403532, 0.4568963617426);
    glVertex2f(0.8820350123787, 0.4614779104998);
    glVertex2f(0.8774575568704, 0.4664074779704);
    glVertex2f(0.8725279893998, 0.4723933813275);
    glVertex2f(0.8684787018347, 0.4803159004766);
    glVertex2f(0.8637251903452, 0.4880623636446);
    glVertex2f(0.8605561826856, 0.4961609387748);
    glVertex2f(0.8565194127288, 0.5081592090972);
    glVertex2f(1.050597097699, 1.4841351748956);
    glVertex2f(1.0555212277467, 1.4954319286592);
    glVertex2f(1.0606535586035, 1.5062368357261);
    glVertex2f(1.066056012137, 1.516231374763);
    glVertex2f(1.0703124195909, 1.522510145484);
    glVertex2f(1.0748876213429, 1.5312902515491);
    glVertex2f(1.0805731436796, 1.5389611943843);
    glVertex2f(1.0863243826456, 1.5466428292359);
    glVertex2f(1.0923492950365, 1.5530505013303);
    glVertex2f(1.0973899598678, 1.5582850378859);
    glVertex2f(1.1028183681478, 1.5639073178901);
    glVertex2f(1.1084260983594, 1.5688746775824);
    glVertex2f(1.1138977595733, 1.5742060397909);
    glVertex2f(1.1213336068641, 1.5789762059774);
    glVertex2f(1.1278676454234, 1.5848767141929);
    glVertex2f(1.1355959361543, 1.590180443126);
    glVertex2f(1.1434757619977, 1.5947264964971);
    glVertex2f(1.1502286436095, 1.5992864966409);
    glVertex2f(1.1583262030102, 1.6023032521158);
    glVertex2f(1.1674183097525, 1.6070008405993);
    glVertex2f(1.1812645673746, 1.6114850575062);
    glVertex2f(1.2078333454293, 1.6180309883313);
glEnd();
//penghubung atas
glBegin(GL_POLYGON);
    glVertex2f(1.4,1.45);
    glVertex2f(1.2091026604557,1.4502078872616);
    glVertex2f(1.2078333454293,1.6180309883313);
    glVertex2f(1.471651662215,1.6180309883313);
glEnd();

//kanan
glBegin(GL_POLYGON);
    glVertex2f(1.471651662215, 1.6180309883313);
    glVertex2f(1.4882242701448, 1.6124924526392);
    glVertex2f(1.5034680903719, 1.6070833551393);
    glVertex2f(1.5147780215081, 1.6014283895712);
    glVertex2f(1.5241210080989, 1.5957734240031);
    glVertex2f(1.5310053140079, 1.590118458435);
    glVertex2f(1.5361685434396, 1.5849552290033);
    glVertex2f(1.5414178299995, 1.5793004414948);
    glVertex2f(1.5473377334095, 1.5721661989238);
    glVertex2f(1.5520432976585, 1.5630586552161);
    glVertex2f(1.5567488619075, 1.5541029039035);
    glVertex2f(1.5617898683408, 1.5431953588538);
    glVertex2f(1.566955473351, 1.5263509946902);
    glVertex2f(1.5677373923127, 1.4646525631529);
    glVertex2f(1.5620772929754, 1.436352066466);
    glVertex2f(1.5570649753794, 1.4106024954606);
    glVertex2f(1.5511402306985, 1.3842104509726);
    glVertex2f(1.373695602998, 0.5582626771939);
    glVertex2f(1.3678238420696, 0.5437043018977);
    glVertex2f(1.3622884652158, 0.532885156229);
    glVertex2f(1.3570046964009, 0.5228208346767);
    glVertex2f(1.3507144954307, 0.5125049050855);
    glVertex2f(1.3446759024993, 0.5031954076497);
    glVertex2f(1.3372662122798, 0.4934736541717);
    glVertex2f(1.3310524929268, 0.4870631620879);
    glVertex2f(1.3251108651741, 0.4793739967609);
    glVertex2f(1.3168974385749, 0.4732576152508);
    glVertex2f(1.3102567957925, 0.4669664799833);
    glVertex2f(1.3041404142824, 0.4615491135029);
    glVertex2f(1.2980043811115, 0.4557988827227);
    glVertex2f(1.2899201771838, 0.4508044446313);
    glVertex2f(1.2832260506733, 0.4460874084348);
    glVertex2f(1.2728108463645, 0.4404575682678);
    glVertex2f(1.2613426257552, 0.4347611988135);
    glVertex2f(1.2450201615192, 0.4283697403812);
    glVertex2f(1.2235031596666, 0.4227084855581);
    glVertex2f(1.1914193556611, 0.4185290227133);
    glVertex2f(1.2127461447748,0.5892118899818);
    glVertex2f(1.4,1.45);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.2127461447748,0.5892118899818);
    glVertex2f(1.0289308590086,0.5892118899818);
    glVertex2f(0.9773326187627,0.4189382507422);
    glVertex2f(1.1914193556611,0.4185290227133);
glEnd();
glPopMatrix();

//awal N
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(1.9521632027495,1.6189582554747);
    glVertex2f(1.7992782957718,1.6189582554747);
    glVertex2f(1.5455824702013,0.4181365804484);
    glVertex2f(1.7037479274546,0.4181365804484);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.9521632027495,1.6189582554747);
    glVertex2f(1.8548146708645,1.1769171529142);
    glVertex2f(1.91,0.4196105832612);
    glVertex2f(2.0645558063459,0.4196105832612);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(2.32,1.6189582554747);
    glVertex2f(2.1627167846927,1.6189582554747);
    glVertex2f(1.91,0.4196105832612);
    glVertex2f(2.0645558063459,0.4196105832612);
glEnd();
glPopMatrix();

//awal G
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(2.6526207662122, 1.4530412363186);
    glVertex2f(2.651641826348, 1.6179926034373);
    glVertex2f(2.6266788598107, 1.6135873740484);
    glVertex2f(2.6095474121871, 1.6082032047952);
    glVertex2f(2.598667121041, 1.6025062050627);
    glVertex2f(2.5868205236793, 1.596501765304);
    glVertex2f(2.5778950051191, 1.5903350433896);
    glVertex2f(2.5693119687991, 1.5851999760989);
    glVertex2f(2.562570961716, 1.5799263538);
    glVertex2f(2.5566165124689, 1.5754605168647);
    glVertex2f(2.5504494043201, 1.5701440443227);
    glVertex2f(2.5449202728764, 1.5648275717806);
    glVertex2f(2.54, 1.56);
    glVertex2f(2.5342873277923, 1.5544072855983);
    glVertex2f(2.5287581963486, 1.5480275185478);
    glVertex2f(2.5240797005116, 1.5416477514974);
    glVertex2f(2.5187632279696, 1.5348426666436);
    glVertex2f(2.5132340965259, 1.5261236516746);
    glVertex2f(2.5072796472788, 1.5163413421973);
    glVertex2f(2.4968889428214, 1.4946852317426);
    glVertex2f(2.3184386990797, 0.6818605850864);
    glVertex2f(2.4844634003098,0.673039138136);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(2.3184386990797, 0.6818605850864);
    glVertex2f(2.3128771628253, 0.6422346392737);
    glVertex2f(2.3135723548571, 0.5859240846977);
    glVertex2f(2.3182059707279, 0.5548662541933);
    glVertex2f(2.3253628119472, 0.536735589771);
    glVertex2f(2.3322729820348, 0.5225930871524);
    glVertex2f(2.3384945420796, 0.5094180188221);
    glVertex2f(2.3439841538839, 0.4991707434541);
    glVertex2f(2.3505716880491, 0.4889234680861);
    glVertex2f(2.3586494603229, 0.4799276386676);
    glVertex2f(2.3681384458228, 0.4709907361921);
    glVertex2f(2.3760205652302, 0.4644542174896);
    glVertex2f(2.3881030824273, 0.4577109095991);
    glVertex2f(2.4003173244095, 0.4499073661105);
    glVertex2f(2.4125315663917, 0.4434609606199);
    glVertex2f(2.4247458083738, 0.4380324086278);
    glVertex2f(2.4403528953511, 0.4319252876367);
    glVertex2f(2.4583349738249, 0.4275145891432);
    glVertex2f(2.4773349057972, 0.4234431751491);
    glVertex2f(2.526870442725, 0.418693192156);
    glVertex2f(2.5509180401456, 0.5834757368579);
    glVertex2f(2.5371602708988, 0.5856702174386);
    glVertex2f(2.5247603054988, 0.5900702051612);
    glVertex2f(2.5143603345181, 0.5956701895355);
    glVertex2f(2.5055603590729, 0.6020701716774);
    glVertex2f(2.4983603791632, 0.6088701527033);
    glVertex2f(2.4915603981373, 0.6168701303807);
    glVertex2f(2.4857982282709, 0.6294908060322);
    glVertex2f(2.4839604193437, 0.6436700556002);
    glVertex2f(2.4844634003098, 0.673039138136);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(2.5509180401456,0.5834757368579);
    glVertex2f(2.6565439194254,0.5834757368579);
    glVertex2f(2.7893362425744,0.418693192156);
    glVertex2f(2.526870442725,0.418693192156);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(2.7893362425744,0.418693192156);
    glVertex2f(2.6565439194254,0.5834757368579);
    glVertex2f(2.7758373080723,1.1020669885135);
    glVertex2f(2.931388118434,1.1020669885135);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(2.931388118434,1.1020669885135);
    glVertex2f(2.668877648914,1.1020669885135);
    glVertex2f(2.6321610217926,0.9372470117152);
    glVertex2f(2.8984985870047,0.9372470117152);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(2.6526207662122,1.4530412363186);
    glVertex2f(2.651641826348,1.6179926034373);
    glVertex2f(2.9149501347532,1.6179926034373);
    glVertex2f(2.840016218824,1.4530412363186);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(2.9149501347532, 1.6179926034373);
    glVertex2f(2.840016218824, 1.4530412363186);
    glVertex2f(2.9275890189646, 1.6132848334401);
    glVertex2f(2.9393986393477, 1.6076100807884);
    glVertex2f(2.9519751181973, 1.6022420715234);
    glVertex2f(2.9625577650341, 1.5961072037919);
    glVertex2f(2.9708398364716, 1.5913526813);
    glVertex2f(2.977434819283, 1.5864447871148);
    glVertex2f(2.9834163153212, 1.5800031759967);
    glVertex2f(2.9889376962795, 1.5738683082652);
    glVertex2f(2.9936922187714, 1.5671199537606);
    glVertex2f(2.9986994566512, 1.5569657245805);
    glVertex2f(3.003124719746, 1.5450420990193);
    glVertex2f(3.0075755972261, 1.53469696963);
    glVertex2f(3.010008462338, 1.5235304034193);
    glVertex2f(3.0096668107571, 1.4630200324099);
    glVertex2f(3.0044018980931, 1.4349787269933);
    glVertex2f(2.9976610424477, 1.4080153044116);
    glVertex2f(3.0137237713845, 1.4970467742815);
    glVertex2f(2.9568552683568, 1.2064569976529);
    glVertex2f(2.7920014909641, 1.2064569976529);
    glVertex2f(2.840016218824,1.4530412363186);
glEnd();
glPopMatrix();

//awal R
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(3.3735374322086,1.4521659913738);
    glVertex2f(3.2413903677943,1.6187704556702);
    glVertex2f(2.9854936075957,0.4188406938512);
    glVertex2f(3.1512267252976,0.4188406938512);
glEnd();
//penghubung atas
glBegin(GL_POLYGON);
    glVertex2f(3.6386567458031, 1.6187704556702);
    glVertex2f(3.5637032444045, 1.4521659913738);
    glVertex2f(3.3735374322086, 1.4521659913738);
    glVertex2f(3.2413903677943, 1.6187704556702);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(3.6386567458031, 1.6187704556702);
    glVertex2f(3.6526967048444, 1.6132079320074);
    glVertex2f(3.6665977197348, 1.6080972647683);
    glVertex2f(3.6807031613147, 1.6025777441501);
    glVertex2f(3.6893987812197, 1.5969052437692);
    glVertex2f(3.6967418098289, 1.5912449925496);
    glVertex2f(3.7022490812858, 1.5858907008554);
    glVertex2f(3.70760337298, 1.5803834293985);
    glVertex2f(3.7121927658608, 1.5727344412639);
    glVertex2f(3.7173940777923, 1.5647794936039);
    glVertex2f(3.7217211695212, 1.5576029658627);
    glVertex2f(3.7272451831681, 1.544468088969);
    glVertex2f(3.7319099058032, 1.5276505363108);
    glVertex2f(3.7335804143927, 1.4629579858389);
    glVertex2f(3.7275942555861, 1.4340248849406);
    glVertex2f(3.6471501481031, 1.1292950523342);
    glVertex2f(3.6419128835919, 1.1196596640963);
    glVertex2f(3.6379067439081, 1.1116473847286);
    glVertex2f(3.6322056989734, 1.1040973522475);
    glVertex2f(3.6251179133789, 1.0953146614021);
    glVertex2f(3.6191187128189, 1.0868494983547);
    glVertex2f(3.613536466084, 1.0799647273817);
    glVertex2f(3.6077681444579, 1.0745685555379);
    glVertex2f(3.6025580475054, 1.0689863088031);
    glVertex2f(3.5977201003352, 1.0630319122859);
    glVertex2f(3.5921378536003, 1.0581939651156);
    glVertex2f(3.5861834570831, 1.0533560179454);
    glVertex2f(3.5787404614366, 1.0492623703398);
    glVertex2f(3.5705531662254, 1.043680123605);
    glVertex2f(3.5618076463408, 1.0390282513259);
    glVertex2f(3.5530621264562, 1.0354928283938);
    glVertex2f(3.5417115580952, 1.0313991807882);
    glVertex2f(3.5305470646255, 1.027677682965);
    glVertex2f(3.5184521966999, 1.0243283349241);
    glVertex2f(3.5043338242909, 1.0205369503277);
    glVertex2f(3.5119132749201, 1.2039556777566);
    glVertex2f(3.5637032444045, 1.4521659913738);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(3.6714071885624,1.187496376911);
    glVertex2f(3.5119132749201, 1.2039556777566);
    glVertex2f(3.5083364336007, 1.1890865662632);
    glVertex2f(3.503441628196, 1.1757370969774);
    glVertex2f(3.4960994200888, 1.1612751719179);
    glVertex2f(3.4914271058388, 1.1521530345727);
    glVertex2f(3.4849748623507, 1.1439208618465);
    glVertex2f(3.4807618191663, 1.1372719509258);
    glVertex2f(3.4755072620342, 1.1313393864218);
    glVertex2f(3.470252704902, 1.1260848292897);
    glVertex2f(3.4641506385551, 1.1206607703146);
    glVertex2f(3.4553365427205, 1.1157452168684);
    glVertex2f(3.4451664321422, 1.1108296634222);
    glVertex2f(3.4334708049772, 1.1076091284058);
    glVertex2f(3.4106172984703, 1.1031833521583);
    glVertex2f(3.5043338242909, 1.0205369503277);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(3.2602713221054,0.9343226837851);
    glVertex2f(3.2974518787941, 1.1001087691445);
    glVertex2f(3.3825867597574, 1.1001087691445);
    glVertex2f(3.4106172984703, 1.1031833521583);
    glVertex2f(3.5043338242909, 1.0205369503277);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(3.5247175129963, 1.0128802266131);
    glVertex2f(3.539970425806, 1.0077959223432);
    glVertex2f(3.5505021989366, 1.0019852888919);
    glVertex2f(3.5576338043529, 0.9967763547919);
    glVertex2f(3.5629012602691, 0.9921673308652);
    glVertex2f(3.5680923048666, 0.9874725804206);
    glVertex2f(3.5731643119387, 0.9815552388365);
    glVertex2f(3.5780451960284, 0.9763649631164);
    glVertex2f(3.5825225335572, 0.9697806432211);
    glVertex2f(3.5866048118923, 0.9606942817655);
    glVertex2f(3.59323066734, 0.9493551583813);
    glVertex2f(3.5955990292708, 0.9292240819696);
    glVertex2f(3.5958823241546, 0.8320487848323);
    glVertex2f(3.5906134304835, 0.7994364001452);
    glVertex2f(3.5859764582187, 0.7737222812222);
    glVertex2f(3.5127116574606, 0.418817018851);
    glVertex2f(3.3491558591083, 0.418817018851);
    glVertex2f(3.4351996889736, 0.8219675695402);
    glVertex2f(3.4328464199552, 0.8974861116758);
    glVertex2f(3.4299217729236, 0.9059303380305);
    glVertex2f(3.4268692828875, 0.911988493533);
    glVertex2f(3.4223195758086, 0.9165382006118);
    glVertex2f(3.4164959507478, 0.9219978491064);
    glVertex2f(3.4094104708554, 0.9258668060548);
    glVertex2f(3.4018104351177, 0.9292868221368);
    glVertex2f(3.3926909432593, 0.932902384662);
    glVertex2f(3.3809103368388, 0.9343226837851);
    glVertex2f(3.2602713221054, 0.9343226837851);
    glVertex2f(3.5043338242909, 1.0205369503277);
glEnd();
glPopMatrix();

//awal A
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(4.0696707398407, 1.6179624557461);
    glVertex2f(3.6461619990161,0.4188750674099);
    glVertex2f(3.8045156855668,0.4188750674099);
    glVertex2f(4.16,1.48);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(4.3125932584383,1.6179624557461);
    glVertex2f(4.2255420218892,0.4192095454159);
    glVertex2f(4.0686977739537,0.4192095454159);
    glVertex2f(4.16,1.48);
    glVertex2f(4.0696707398407,1.6179624557461);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(4.1115289623432,0.8853565298443);
    glVertex2f(3.9542104960351,0.8853565298443);
    glVertex2f(3.8950075154207,0.72);
    glVertex2f(4.1,0.72);
glEnd();
glPopMatrix();

//awal T
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(5.024501830281,1.4558770045467);
    glVertex2f(4.502399818759,1.4558770045467);
    glVertex2f(4.5373782122905,1.6177458045877);
    glVertex2f(4.5373782122905,1.6177458045877);
    glVertex2f(5.06,1.6177458045877);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(4.8444084539636,1.4558770045467);
    glVertex2f(4.6826025222659,1.4558770045467);
    glVertex2f(4.463334854836,0.4189974616848);
    glVertex2f(4.6251977138845,0.4189974616848);
glEnd();
glPopMatrix();

//awal U
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(5.3382062899093, 1.6175356560614);
    glVertex2f(5.1747463069375, 1.6175356560614);
    glVertex2f(4.9549229604039, 0.5829213928848);
    glVertex2f(4.9555223999795, 0.5092843923018);
    glVertex2f(4.9609932853933, 0.4939138094727);
    glVertex2f(4.9647822843368, 0.4828728775775);
    glVertex2f(4.9711824379753, 0.472472627915);
    glVertex2f(4.9761183335157, 0.466125850966);
    glVertex2f(4.9807613236086, 0.4610830968716);
    glVertex2f(4.9863904425303, 0.4554539779499);
    glVertex2f(4.9928081825012, 0.4501412068673);
    glVertex2f(4.9977446167081, 0.4443820336259);
    glVertex2f(5.0043265289841, 0.4394455994189);
    glVertex2f(5.0134794759416, 0.4349973113648);
    glVertex2f(5.0246706732184, 0.4297069271975);
    glVertex2f(5.0395244441494, 0.4242130667162);
    glVertex2f(5.0761501806916, 0.4197365878055);
    glVertex2f(5.1276697234774, 0.5856062965354);
glEnd();

//penghubung bawah
glBegin(GL_POLYGON);
    glVertex2f(5.1276697234774,0.5856062965354);
    glVertex2f(5.0761501806916,0.4197365878055);
    glVertex2f(5.2912949017592,0.4197365878055);
    glVertex2f(5.3095955091518,0.5856062965354);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(5.7, 1.6175356560614);
    glVertex2f(5.5371099993123, 1.6175356560614);
    glVertex2f(5.3095955091518, 0.5856062965354);
    glVertex2f(5.2912949017592, 0.4197365878055);
    glVertex2f(5.3137161773128, 0.4217031916698);
    glVertex2f(5.3348419371112, 0.4257250113697);
    glVertex2f(5.3492964130071, 0.4292047926039);
    glVertex2f(5.3621448360256, 0.4334876002768);
    glVertex2f(5.37151347781, 0.4383057589087);
    glVertex2f(5.3814174705534, 0.4436592684998);
    glVertex2f(5.3899830858991, 0.4482097516522);
    glVertex2f(5.3990840522039, 0.4546339631615);
    glVertex2f(5.4073819920701, 0.4610581746707);
    glVertex2f(5.4154122564567, 0.4677500616596);
    glVertex2f(5.4226394944046, 0.4760480015257);
    glVertex2f(5.4304020833116, 0.4846136168714);
    glVertex2f(5.4362909438618, 0.4942499341353);
    glVertex2f(5.4432505063302, 0.5068306816743);
glEnd();
glPopMatrix();

//awal L
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(6.0613561327076,1.6180606172398);
    glVertex2f(5.8989561335651,1.6180606172398);
    glVertex2f(5.6442326525542,0.4185453869499);
    glVertex2f(5.8109934488351,0.4185453869499);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(5.841065758892,0.5836086089084);
    glVertex2f(6.1317731015842,0.5836086089084);
    glVertex2f(6.0929506916525,0.4185453869499);
    glVertex2f(5.8109934488351,0.4185453869499);
glEnd();
glPopMatrix();

//awal A
glPushMatrix();
glTranslated(2.55,0,0);
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(4.0696707398407, 1.6179624557461);
    glVertex2f(3.6461619990161,0.4188750674099);
    glVertex2f(3.8045156855668,0.4188750674099);
    glVertex2f(4.16,1.48);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(4.3125932584383,1.6179624557461);
    glVertex2f(4.2255420218892,0.4192095454159);
    glVertex2f(4.0686977739537,0.4192095454159);
    glVertex2f(4.16,1.48);
    glVertex2f(4.0696707398407,1.6179624557461);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(4.1115289623432,0.8853565298443);
    glVertex2f(3.9542104960351,0.8853565298443);
    glVertex2f(3.8950075154207,0.72);
    glVertex2f(4.1,0.72);
glEnd();
glPopMatrix();

//awal T
glPushMatrix();
glTranslated(2.48,0,0);
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(5.024501830281,1.4558770045467);
    glVertex2f(4.502399818759,1.4558770045467);
    glVertex2f(4.5373782122905,1.6177458045877);
    glVertex2f(4.5373782122905,1.6177458045877);
    glVertex2f(5.06,1.6177458045877);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(4.8444084539636,1.4558770045467);
    glVertex2f(4.6826025222659,1.4558770045467);
    glVertex2f(4.463334854836,0.4189974616848);
    glVertex2f(4.6251977138845,0.4189974616848);
glEnd();
glPopMatrix();

//awal i
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(7.6586245813263,1.6174807233798);
    glVertex2f(7.8217244857033,1.6174807233798);
    glVertex2f(7.5677670425119,0.418574763473);
    glVertex2f(7.4049274271212,0.418574763473);
glEnd();
glPopMatrix();

//awal O
glPushMatrix();
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(8.1539276438757, 1.6177387825163);
    glVertex2f(8.1288789451268, 1.6134200413527);
    glVertex2f(8.1113858336857, 1.606766187577);
    glVertex2f(8.101183948239, 1.6018962698889);
    glVertex2f(8.0905480838453, 1.5957671276959);
    glVertex2f(8.08, 1.59);
    glVertex2f(8.0733938821194, 1.5864103537978);
    glVertex2f(8.0656781615848, 1.5807843075747);
    glVertex2f(8.0579624410503, 1.5743545404626);
    glVertex2f(8.0520149064716, 1.5693714709507);
    glVertex2f(8.0468710927819, 1.563423936372);
    glVertex2f(8.0414057907366, 1.5582801226823);
    glVertex2f(8.0365834654026, 1.5523325881036);
    glVertex2f(8.0301992302748, 1.5451178567935);
    glVertex2f(8.0254962320645, 1.5371589367454);
    glVertex2f(8.02, 1.53);
    glVertex2f(8.0135829899526, 1.5222495937322);
    glVertex2f(8.0087381006924, 1.5134999766689);
    glVertex2f(8.0043342870352, 1.5038916559623);
    glVertex2f(7.9995301266819, 1.4942833352556);
    glVertex2f(7.8000420023322, 0.582888132585);
    glVertex2f(7.9706763853789, 0.5903626885452);
    glVertex2f(8.1554165908602, 1.4533869518782);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(7.8000420023322, 0.5903626885452);
    glVertex2f(7.7998629687128, 0.5073110960674);
    glVertex2f(7.8060116577239, 0.4925542424407);
    glVertex2f(7.8101107837314, 0.4814866022206);
    glVertex2f(7.8159857492696, 0.4710395476804);
    glVertex2f(7.8223231266755, 0.46383233416);
    glVertex2f(7.8291651073206, 0.455827539062);
    glVertex2f(7.838270588, 0.4476147525668);
    glVertex2f(7.8495185347216, 0.4386878107242);
    glVertex2f(7.8613020979538, 0.4326174902713);
    glVertex2f(7.8747900472282, 0.4279022520037);
    glVertex2f(7.8900437408762, 0.4228691003144);
    glVertex2f(7.9193721496511, 0.4184573104055);
    glVertex2f(8.1359404565132, 0.4184573104055);
    glVertex2f(8.1573688095867, 0.5903626885452);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(8.1359404565132, 0.4184573104055);
    glVertex2f(8.1688194982932, 0.4231857068553);
    glVertex2f(8.1893732570381, 0.428168436248);
    glVertex2f(8.2055671275643, 0.4334625862278);
    glVertex2f(8.2165264174708, 0.4391150587411);
    glVertex2f(8.227453187393, 0.4446576231944);
    glVertex2f(8.2355140347687, 0.4499776695291);
    glVertex2f(8.2429527320832, 0.4554823055419);
    glVertex2f(8.25, 0.46);
    glVertex2f(8.2567921853752, 0.4654274814499);
    glVertex2f(8.2623905022887, 0.4710257983634);
    glVertex2f(8.2670235921481, 0.4760449790444);
    glVertex2f(8.2714636365967, 0.4812572051362);
    glVertex2f(8.2752125522519, 0.4865658026438);
    glVertex2f(8.2797917354167, 0.4924753392468);
    glVertex2f(8.2844533789052, 0.499234722305);
    glVertex2f(8.3120560047707, 0.5461554467011);
    glVertex2f(8.5113532536974, 1.4533869518782);
    glVertex2f(8.3452872635177, 1.4533869518782);
    glVertex2f(8.1573688095867, 0.5903626885452);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(8.5121674259125, 1.4650004875319);
    glVertex2f(8.5114925864533, 1.5273811569092);
    glVertex2f(8.5072944569674, 1.5426750557287);
    glVertex2f(8.5028994381107, 1.5536626028705);
    glVertex2f(8.4987303961695, 1.5630327691622);
    glVertex2f(8.4934196188089, 1.570337116266);
    glVertex2f(8.488922551268, 1.5760535287728);
    glVertex2f(8.4843662736265, 1.5807987595878);
    glVertex2f(8.4801413792081, 1.5858283958003);
    glVertex2f(8.4745081866502, 1.5898521047702);
    glVertex2f(8.4686738086437, 1.5942781846372);
    glVertex2f(8.4615638492939, 1.5980643247497);
    glVertex2f(8.4555099494959, 1.6022554861483);
    glVertex2f(8.4493008214981, 1.6055152783472);
    glVertex2f(8.4417981463537, 1.6090231899376);
    glVertex2f(8.4344547884827, 1.6120002269124);
    glVertex2f(8.4253252084269, 1.6149772638871);
    glVertex2f(8.4140124679229, 1.6177387825163);
    glVertex2f(8.1539276438757, 1.6177387825163);
    glVertex2f(8.1554165908602, 1.4533869518782);
    glVertex2f(8.5113532536974, 1.4533869518782);
glEnd();
glPopMatrix();

//awal N
glPushMatrix();
glTranslated(6.9,0,0);
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(1.9521632027495,1.6189582554747);
    glVertex2f(1.7992782957718,1.6189582554747);
    glVertex2f(1.5455824702013,0.4181365804484);
    glVertex2f(1.7037479274546,0.4181365804484);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(1.9521632027495,1.6189582554747);
    glVertex2f(1.8548146708645,1.1769171529142);
    glVertex2f(1.91,0.4196105832612);
    glVertex2f(2.0645558063459,0.4196105832612);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(2.32,1.6189582554747);
    glVertex2f(2.1627167846927,1.6189582554747);
    glVertex2f(1.91,0.4196105832612);
    glVertex2f(2.0645558063459,0.4196105832612);
glEnd();
glPopMatrix();

//awal S
glPushMatrix();
glTranslated(-0.1,0,0);
glColor3ub(237, 196, 31);
glBegin(GL_POLYGON);
    glVertex2f(9.7524790076804, 1.4530423073113);
    glVertex2f(9.9179606266855, 1.4530423073113);
    glVertex2f(9.9208627239929, 1.5275891515852);
    glVertex2f(9.9149336482765, 1.5455871183772);
    glVertex2f(9.9107548205507, 1.5561442265426);
    glVertex2f(9.9053375662121, 1.5661579391079);
    glVertex2f(9.8990261890176, 1.5745097715754);
    glVertex2f(9.893429954064, 1.5805126614965);
    glVertex2f(9.8882626272827, 1.5856799882778);
    glVertex2f(9.8813190319204, 1.5918161888305);
    glVertex2f(9.8751828313677, 1.5971449945737);
    glVertex2f(9.8677547991197, 1.6015049265453);
    glVertex2f(9.8580660614048, 1.6069952112504);
    glVertex2f(9.8459551392613, 1.6116781011459);
    glVertex2f(9.8265776638316, 1.6166839489652);
    glVertex2f(9.5607538266943, 1.6166839489652);
    glVertex2f(9.5370813882173, 1.6124253392638);
    glVertex2f(9.5237166554187, 1.6071910942971);
    glVertex2f(9.5096198593746, 1.6014967716632);
    glVertex2f(9.4995319508202, 1.5958923780218);
    glVertex2f(9.4907731698825, 1.5913213743212);
    glVertex2f(9.4823518479326, 1.5855322680597);
    glVertex2f(9.4750401848305, 1.5809516552829);
    glVertex2f(9.4681199661732, 1.5750491158398);
    glVertex2f(9.4617289207739, 1.5702208140258);
    glVertex2f(9.4563314918277, 1.5645393098719);
    glVertex2f(9.4500409050873, 1.559228943177);
    glVertex2f(9.4450747874469, 1.5522364135911);
    glVertex2f(9.429708472427, 1.5327321817227);
    glVertex2f(9.4202788881089, 1.5173470704667);
    glVertex2f(9.4138270672596, 1.5036989879009);
    glVertex2f(9.4088641281448, 1.4937731096713);
    glVertex2f(9.3966659590873, 1.4530423073113);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(9.7524790076804,1.4530423073113);
    glVertex2f(9.9179606266855,1.4530423073113);
    glVertex2f(9.8672394808787,1.2069782004122);
    glVertex2f(9.7022614501569,1.2075448340416);
glEnd();


glBegin(GL_POLYGON);
    glVertex2f(9.5633084149814, 1.4530423073113);
    glVertex2f(9.5095373067928,1.2070345978564);
    glVertex2f(9.5308023520607, 1.137234976597);
    glVertex2f(9.3827780212522, 1.041552358387);
    glVertex2f(9.3762844162553, 1.0490200041333);
    glVertex2f(9.370764852008, 1.0568123301295);
    glVertex2f(9.364595927261, 1.0655786968753);
    glVertex2f(9.3600504037632, 1.0756437846204);
    glVertex2f(9.3548555197657, 1.090903756363);
    glVertex2f(9.3499853160181, 1.1068130886053);
    glVertex2f(9.3453552628389, 1.1350310840556);
    glVertex2f(9.3444877216323, 1.2040006099797);
    glVertex2f(9.3496929688718, 1.2339307816071);
    glVertex2f(9.3561995279213, 1.2625596414247);
    glVertex2f(9.3966659590873, 1.4530423073113);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(9.5308023520607, 1.137234976597);
    glVertex2f(9.6803493753603, 1.0562049452516);
    glVertex2f(9.7289660211541, 1.0181836050647);
    glVertex2f(9.7395928930961, 1.0049290036401);
    glVertex2f(9.7482330266554, 0.9958218358343);
    glVertex2f(9.7543044718592, 0.9857805995356);
    glVertex2f(9.7601423999398, 0.9764399146067);
    glVertex2f(9.765194233301, 0.9695888667396);
    glVertex2f(9.77, 0.96);
    glVertex2f(9.7753764712511, 0.9446105642684);
    glVertex2f(9.7803084927581, 0.9285417200035);
    glVertex2f(9.7845849686669, 0.9070529185851);
    glVertex2f(9.6042100775645, 0.865681616273);
    glVertex2f(9.597292130276, 0.8779210614757);
    glVertex2f(9.5877134340304, 0.8890962070956);
    glVertex2f(9.5759664912629, 0.8999481655664);
    glVertex2f(9.5618295066623, 0.9090956261903);
    glVertex2f(9.5419628215879, 0.9209484473318);
    glVertex2f(9.4485424143361, 0.9769616636362);
    glVertex2f(9.3827780212522, 1.041552358387);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(9.5937842005958, 0.8806328397146);
    glVertex2f(9.6101298577604, 0.8610025122546);
    glVertex2f(9.6161237602952, 0.8338301540971);
    glVertex2f(9.566404006604, 0.5844666937431);
    glVertex2f(9.7410454188863, 0.5844666937431);
    glVertex2f(9.7870814552464, 0.826322143349);
    glVertex2f(9.7845849686669, 0.9070529185851);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(9.566404006604, 0.5844666937431);
    glVertex2f(9.7330213422876, 0.5829288432835);
    glVertex2f(9.7269623580893, 0.554451617551);
    glVertex2f(9.7179320151704, 0.531830783719);
    glVertex2f(9.7045441165552, 0.509615134483);
    glVertex2f(9.6885430882275, 0.4871435112442);
    glVertex2f(9.6692188622925, 0.4678192853092);
    glVertex2f(9.6474791081156, 0.4529235278176);
    glVertex2f(9.6273497060999, 0.4416510626889);
    glVertex2f(9.6003763073989, 0.4299760095198);
    glVertex2f(9.5738054967383, 0.4219242487135);
    glVertex2f(9.5460269219567, 0.4183009563507);
    glVertex2f(9.3317494483986, 0.4183009563507);
    glVertex2f(9.384033595671, 0.5844666937431);
glEnd();

glBegin(GL_POLYGON);
    glVertex2f(9.390301460294, 0.5844666937431);
    glVertex2f(9.3301194179041, 0.4202299929324);
    glVertex2f(9.2994526142214, 0.4241330406738);
    glVertex2f(9.2710161235338, 0.4324967144054);
    glVertex2f(9.2520584630754, 0.4425331228834);
    glVertex2f(9.2364462721096, 0.4564725791028);
    glVertex2f(9.2247371288853, 0.470969613571);
    glVertex2f(9.2163734551536, 0.486024226288);
    glVertex2f(9.2096825161683, 0.5105576692342);
    glVertex2f(9.2075451845591, 0.5786309091417);
    glVertex2f(9.2630442965398, 0.8354256350799);
    glVertex2f(9.4264356906986, 0.8354256350799);
glEnd();
glPopMatrix();

glPopMatrix(); //untuk seluruh fertex
}

void timer_universal (int t){
    //Untuk pindah scene(dari scene 1) jika fireball sudah 5
    if (scene[1]&&fireballStatus_bar==5){
        fireballStatus_bar=0;
        scene[1]=false;
        scene[2]=true;
        ver=2;
    }
    //Untuk pindah scene(dari scene 2) jika fireball sudah 5
    if (scene[2]&&fireballStatus_bar==5){
        fireballStatus_bar=0;
        scene[2]=false;
        scene[3]=true;
        ver=2;
    }
    //Untuk pindah scene(dari scene 3) jika fireball sudah 5
    if (scene[3]&&fireballStatus_bar==5){
        fireballStatus_bar=0;
        scene[3]=false;
        scene[6]=true;
        ver=2;
    }
    //Untuk pindah scene game over jika heart sudah tidak ada
    if (heartStatus_bar==0){
        scene[1]=false;
        scene[2]=false;
        scene[3]=false;
        scene[5]=true;
        heartStatus_bar=3;
        ver=2;
    }

    if(scene[1]||scene[2]||scene[3]){
        //Untuk Menggerakkan blackbird (semua level)
        for (int i =0;i<1;i++){
            xx-=1;
            if(xx<=-40){
                xx=10;
            }
        }
        //Untuk Menggerakkan Fire ball (semua Level)
        for (int i =0;i<1;i++){
            fireball_all_x[i]-=0.2;
            if(fireball_all_x[i]<=-5){
                fireball_all_x[i]=70;
            }
            if (moven[4]>=fireball_all_x[i]+1.5&&moven[5]>=fireball_all_y[i]){
                fireball_all_x[i]=20;
                fireballStatus_bar+=1;
            }
        }

        //Untuk Menggerakkan Marka
        for (int i =0;i<6;i++){
            marka[i]-=0.2;
            if(marka[i]<=-2){
                marka[i]=10;
            }
        }
        //Untuk Menggerakkan cloud di Level 1
        for (int i =0;i<6;i++){
            cloudlvl1[i]-=0.2;
            if(cloudlvl1[i]<=-5.5){
                cloudlvl1[i]=14;
            }
        }
    }

    if(scene[1]){

        //Untuk Menggerakkan Rumput di Level 1
        for (int i =0;i<6;i++){
            rumputlvl1[i]-=0.2;
            if(rumputlvl1[i]<=-2.5){
                rumputlvl1[i]=10;
            }
        }
        //Untuk Menggerakkan batu di Level 1
        for (int i =0;i<2;i++){
            stonelvl1[i]-=5;
            if(stonelvl1[i]<=-250){
                stonelvl1[i]=50;
            }
            if(ver==1&&moven[4]==stonelvl1[0]+190){
                heartStatus_bar-=1;
                stonelvl1[i]=100;
            }
            if(ver==2&&moven[4]==stonelvl1[1]+190){
                heartStatus_bar-=1;
                stonelvl1[i]=500;
            }
        }
        //Untuk Menggerakkan tree di Level 1
        for (int i =0;i<6;i++){
            treelvl1[i]-=0.2;
            if(treelvl1[i]<=-5.5){
                treelvl1[i]=6;
            }
        }
    }

    if(scene[2]){
        //Untuk Menggerakkan lamp di level 2
        for (int i =0;i<=5;i++){
            lamplvl2[i]-=0.2;
            if(lamplvl2[i]<=-1){
                lamplvl2[i]=10;
            }
        }
        //Untuk Menggerakkan got di level 2
        for (int i =0;i<=2;i++){
            gotlvl2[i]-=0.2;
            if(gotlvl2[i]<=-3){
                gotlvl2[i]=10;
            }
            if(ver==2&&moven[4]>=gotlvl2[0]+0.5){
                heartStatus_bar-=1;
                gotlvl2[i]=70;
            }
            if(ver==1&&moven[4]>=gotlvl2[1]+0.5){
                heartStatus_bar-=1;
                gotlvl2[i]=30;
            }
        }
        //Untuk Menggerakkan roadline di level 2
        //for (int i =0;i<=2;i++){
          //  roadlinelvl2[i]-=0.2;
            //if(roadlinelvl2[i]<=-3){
              //  roadlinelvl2[i]=10;
            //}
        //}
    }

    if(scene[3]){
        //Untuk Menggerakkan piramid di level 3
        for (int i =0;i<=1;i++){
            piramidlvl3-=0.2;
            if(piramidlvl3<=-7){
                piramidlvl3=18;
            }
        }
        //Untuk Menggerakkan piramid di level 3
        for (int i =0;i<=5;i++){
            kaktuslvl3[i]-=0.2;
            if(kaktuslvl3[i]<=-5){
                kaktuslvl3[i]=12;
            }
        }
        //Untuk Menggerakkan batu di Level 3
        for (int i =0;i<2;i++){
            stonelvl1[i]-=5;
            if(stonelvl1[i]<=-250){
                stonelvl1[i]=50;
            }
            if(ver==1&&moven[4]==stonelvl1[0]+190){
                heartStatus_bar-=1;
                stonelvl1[i]=100;
            }
            if(ver==2&&moven[4]==stonelvl1[1]+190){
                heartStatus_bar-=1;
                stonelvl1[i]=500;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50,timer_universal,0);
}

void timer_buildlvl2 (int t){
    //Untuk Menggerakkan lamp di level 2
    for (int i =0;i<=1;i++){
        buildlvl2-=0.2;
        if(buildlvl2<=-6){
            buildlvl2=6;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(100,timer_buildlvl2,0);
}

void keyboard(int key, int z, int zz){
    if (scene[0]||scene[5]||scene[6]){
        switch (key) {                  // key untuk arah panah di ===Background Awal===
        case GLUT_KEY_UP:
            if ( ver < 2) {
            panah[0] += panah[1];
            ver++;
            }
            break;
        case GLUT_KEY_DOWN:
            if (ver >= 1){
            panah[0] -= panah[1];
            ver--;
            }
            break;
        }
    }
    if (scene[1]||scene[2]||scene[3]){
        switch(key){
        case GLUT_KEY_RIGHT:
            moven[4]+=0.2;
            if (moven[4]>=9){
                moven[4]=9;
            }
            break;
        case GLUT_KEY_LEFT:
            moven[4]-=0.2;
            if (moven[4]<=0){
                moven[4]=0;
            }
            break;
        case GLUT_KEY_UP:
            if ( ver< 2) {
            moven[5] +=1.2;
            ver++;
            }
            break;
        case GLUT_KEY_DOWN:
            if (ver >= 2){
            moven[5] -=1.2;
            ver--;
            }
            break;
        }
    }

    glutPostRedisplay();
}

void myKeyboard(unsigned char keyASCII,int z,int zz){
    switch (keyASCII){
    case 13:    //Enter
        if ( ver>= 2) {
        scene[6] = false;
        scene[5] = false;
        scene[0] = false;
        scene[1] = true;
        heartStatus_bar=3;
        fireballStatus_bar=0;
        moven[4]=0.0f;
        moven[5]=1.0f;

        }
        if ( ver == 1) {
        scene[6] = false;
        scene[5] = false;
        scene[0] = false;
        scene[4] = true;
        }
        if ( ver == 0) {
        exit(1);
        }
        break;
///Case ini digunakan jika colisen belum berhasil
    case 27:    //ESC                                //Tekan ESC untuk pindah scene 0
        if (scene[1]||scene[2]||scene[3]||scene[4]||scene[5]) {
        scene[5] = false;
        scene[4] = false;
        scene[3] = false;
        scene[2] = false;
        scene[1] = false;
        scene[0] = true;
        ver=2;
        }
        break;
    case 49:    //1                                //Tekan 1 untuk pindah scene 1 (lvl1)
        if (scene[2]||scene[3]) {
        scene[3] = false;
        scene[2] = false;
        scene[1] = true;
        }
        break;
    case 50:    //2                                //Tekan 2 untuk pindah scene 2 (lvl2)
        if (scene[1]||scene[3]) {
        scene[3] = false;
        scene[2] = true;
        scene[1] = false;
        }
        break;
    case 51:    //3                                //Tekan 3 untuk pindah scene 3 (lvl3)
        if (scene[1]||scene[2]) {
        scene[3] = true;
        scene[2] = false;
        scene[1] = false;
        }
        break;
    case 53:    //5                                //Tekan 3 untuk pindah scene 5 (gameover)
        if (scene[1]||scene[2]||scene[3]) {
        scene[6] = true;
        scene[3] = false;
        scene[2] = false;
        scene[1] = false;
        ver=2;
        }
        break;
    }
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    if(scene[0]){
        backgroundawal();
        glPushMatrix();
        glTranslated(0,panah[0],0);
        arahPanah();
        glPopMatrix();
    }
    if(scene[1]){
        level1();
        glPushMatrix();
        glTranslated(moven[4],moven[5],0);
        quads();
        glPushMatrix();
        glScaled(0.07,0.07,0);
        bodyPosition();
        glPopMatrix();
        glColor3f(1,1,1);
        glPopMatrix();
    }
    if(scene[2]){
        level2();
        glPushMatrix();
        glTranslated(moven[4],moven[5],0);
        quads();
        glPushMatrix();
        glScaled(0.07,0.07,0);
        bodyPosition();
        glPopMatrix();
        glColor3f(1,1,1);
        glPopMatrix();
    }
    if (scene[3]){
        level3();
        glPushMatrix();
        glTranslated(moven[4],moven[5],0);
        quads();
        glPushMatrix();
        glScaled(0.07,0.07,0);
        bodyPosition();
        glPopMatrix();
        glColor3f(1,1,1);
        glPopMatrix();

    }
    if (scene[4]){
        backgroundawalAboutDisplay();
        glPushMatrix();
        glColor3ub(0,0,0);
        glTranslated(-2.4,4.5,0);
        isiAbout(0,0,"1. Firratus Saadah                        182410102004");
        glPopMatrix();

        glPushMatrix();
        glTranslated(-2.4,4,0);
        isiAbout(0,0,"2. Zihan Muhammad Al Ghifari Ibnu Zain    182410102036");
        glPopMatrix();

        glPushMatrix();
        glTranslated(-2.4,3.5,0);
        isiAbout(0,0,"3. Mylian Gedhe                           182410102048");
        glPopMatrix();

        glPushMatrix();
        glTranslated(-2.4,3,0);
        isiAbout(0,0,"4. Denta Firdaus Fatoni Maulana           182410102056");
        glPopMatrix();

        glPushMatrix();
        glTranslated(-2.49,0.6,0);
        hastag(0,0,"#bagikamidesainjugapenting");
        glPopMatrix();
    }
    if (scene[5]){
        blackScreen();
        glPushMatrix();
        glTranslated(2,1,0);
        glScaled(0.6,1,0);
        overgame();
        glPopMatrix();
        glPushMatrix();
        glTranslated(0,panah[0],0);
        arahPanah();
        glPopMatrix();
    }
    if (scene[6]){
        blackScreen();
        glPushMatrix();
        glTranslated(-0.1,2.5,0);
        congratulations();
        glPopMatrix();
        glPushMatrix();
        glTranslated(0,panah[0],0);
        arahPanah();
        glPopMatrix();
    }
    glFlush();

}

void myinit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,10.0,0.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,200);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

int main(int argc, char* argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1380,734);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Project Akhir Lari Dari Kenyataan");
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutKeyboardFunc(myKeyboard);
    myinit();
    glutTimerFunc(50,timer_universal,0);
    glutTimerFunc(100,timer_buildlvl2,0);
    glutMainLoop();
    return 0; }
