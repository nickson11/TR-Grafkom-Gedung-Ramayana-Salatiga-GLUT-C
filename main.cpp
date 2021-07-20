#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <stdio.h>


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);


float xrot =0.f;
float yrot = 0.f;
float xdiff = 0.f;
float ydiff = 0.f;
bool mouseDown = false;
int is_depth;

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 50);
	glutCreateWindow("TR_GRAFKOM_F_RAMAYANA");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);

	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);

	glutReshapeFunc(ukuran);
	glutDisplayFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHT0);

	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(5.5);
	glLineWidth(1);
}

void bangun_atas(){
	glBegin(GL_QUADS);//depan besar
		glColor3ub(166,166,166);
		glVertex3f(-65,-18,40);//samping kanan
		glVertex3f(65,-18,40);
		glVertex3f(65,0,40);
		glVertex3f(-65,0,40);
		glVertex3f(-65,0.5,40);//samping kanan 2
		glVertex3f(65,0.5,40);
		glVertex3f(65,19,40);
		glVertex3f(-65,19,40);
		glVertex3f(-65,19.5,40);//samping kanan 3
		glVertex3f(65,19.5,40);
		glVertex3f(65,37,40);
		glVertex3f(-65,37,40);
		glVertex3f(-65,37.5,40);//samping kanan 4
		glVertex3f(65,37.5,40);
		glVertex3f(65,55,40);
		glVertex3f(-65,55,40);
		glVertex3f(-65,55.5,40);//samping kanan 5
		glVertex3f(65,55.5,40);
		glVertex3f(65,73,40);
		glVertex3f(-65,73,40);
		//sela kecil kanan
		glColor3ub(140,140,140);
		glVertex3f(-64.8,0.5,39.5);//depan
		glVertex3f(64.8,0.5,39.5);
		glVertex3f(64.8,0,39.5);
		glVertex3f(-64.8,0,39.5);
		glColor3ub(0,0,0);
		glVertex3f(-64.8,0,40);//bawah
		glVertex3f(64.8,0,40);
		glVertex3f(64.8,0,39.5);
		glVertex3f(-64.8,0,39.5);
		glVertex3f(-64.8,0.5,40);//atas
		glVertex3f(64.8,0.5,40);
		glVertex3f(64.8,0.5,39.5);
		glVertex3f(-64.8,0.5,39.5);
		//sela kecil kanan 2
		glColor3ub(140,140,140);
		glVertex3f(-64.8,19.5,39.5);//depan
		glVertex3f(64.8,19.5,39.5);
		glVertex3f(64.8,19,39.5);
		glVertex3f(-64.8,19,39.5);
		glColor3ub(0,0,0);
		glVertex3f(-64.8,19,40);//bawah
		glVertex3f(64.8,19,40);
		glVertex3f(64.8,19,39.5);
		glVertex3f(-64.8,19,39.5);
		glVertex3f(-64.8,19.5,40);//atas
		glVertex3f(64.8,19.5,40);
		glVertex3f(64.8,19.5,39.5);
		glVertex3f(-64.8,19.5,39.5);
		//sela kecil kanan 3
		glColor3ub(140,140,140);
		glVertex3f(-64.8,37.5,39.5);//depan
		glVertex3f(64.8,37.5,39.5);
		glVertex3f(64.8,37,39.5);
		glVertex3f(-64.8,37,39.5);
		glColor3ub(0,0,0);
		glVertex3f(-64.8,37,40);//bawah
		glVertex3f(64.8,37,40);
		glVertex3f(64.8,37,39.5);
		glVertex3f(-64.8,37,39.5);
		glVertex3f(-64.8,37.5,40);//atas
		glVertex3f(64.8,37.5,40);
		glVertex3f(64.8,37.5,39.5);
		glVertex3f(-64.8,37.5,39.5);
		//sela kecil kanan 4
		glColor3ub(140,140,140);
		glVertex3f(-64.8,55.5,39.5);//depan
		glVertex3f(64.8,55.5,39.5);
		glVertex3f(64.8,55,39.5);
		glVertex3f(-64.8,55,39.5);
		glColor3ub(0,0,0);
		glVertex3f(-64.8,55,40);//bawah
		glVertex3f(64.8,55,40);
		glVertex3f(64.8,55,39.5);
		glVertex3f(-64.8,55,39.5);
		glVertex3f(-64.8,55.5,40);//atas
		glVertex3f(64.8,55.5,40);
		glVertex3f(64.8,55.5,39.5);
		glVertex3f(-64.8,55.5,39.5);

	glEnd();
}

void bangun_samping(){
	glBegin(GL_QUADS);//depan besar
		glColor3ub(166,166,166);
		glVertex3f(65,-18,-94.8);//samping kanan luar
		glVertex3f(65,-18,40);
		glVertex3f(65,0,40);
		glVertex3f(65,0,-94.8);
		glVertex3f(65,0.5,-94.8);//samping kanan luar 2
		glVertex3f(65,0.5,40);
		glVertex3f(65,19,40);
		glVertex3f(65,19,-94.8);
		glVertex3f(65,19.5,-94.8);//samping kanan luar 3
		glVertex3f(65,19.5,40);
		glVertex3f(65,37,40);
		glVertex3f(65,37,-94.8);
		glVertex3f(65,37.5,-94.8);//samping kanan luar 4
		glVertex3f(65,37.5,40);
		glVertex3f(65,55,40);
		glVertex3f(65,55,-94.8);
		glVertex3f(65,55.5,-94.8);//samping kanan luar 5
		glVertex3f(65,55.5,40);
		glVertex3f(65,73,40);
		glVertex3f(65,73,-94.8);
		//sela kecil
		glColor3ub(140,140,140);
		glVertex3f(64.8,0.5,-94.8);//samping kanan luar
		glVertex3f(64.8,0.5,39.5);
		glVertex3f(64.8,0,39.5);
		glVertex3f(64.8,0,-94.8);
		glColor3ub(0,0,0);
		glVertex3f(64.8,0,-94.8);//atas
		glVertex3f(64.8,0,39.5);
		glVertex3f(65,0,39.5);
		glVertex3f(65,0,-94.8);
		glVertex3f(64.8,0.5,-94.8);//bawah
		glVertex3f(64.8,0.5,39.5);
		glVertex3f(65,0.5,39.5);
		glVertex3f(65,0.5,-94.8);
		//sela kecil 2
		glColor3ub(140,140,140);
		glVertex3f(64.8,19.5,-94.8);//samping kanan luar
		glVertex3f(64.8,19.5,39.5);
		glVertex3f(64.8,19,39.5);
		glVertex3f(64.8,19,-94.8);
		glColor3ub(0,0,0);
		glVertex3f(64.8,19,-94.8);//atas
		glVertex3f(64.8,19,39.5);
		glVertex3f(65,19,39.5);
		glVertex3f(65,19,-94.8);
		glVertex3f(64.8,19.5,-94.8);//bawah
		glVertex3f(64.8,19.5,39.5);
		glVertex3f(65,19.5,39.5);
		glVertex3f(65,19.5,-94.8);
		//sela kecil 3
		glColor3ub(140,140,140);
		glVertex3f(64.8,37.5,-94.8);//samping kanan luar
		glVertex3f(64.8,37.5,39.5);
		glVertex3f(64.8,37,39.5);
		glVertex3f(64.8,37,-94.8);
		glColor3ub(0,0,0);
		glVertex3f(64.8,37,-94.8);//atas
		glVertex3f(64.8,37,39.5);
		glVertex3f(65,37,39.5);
		glVertex3f(65,37,-94.8);
		glVertex3f(64.8,37.5,-94.8);//bawah
		glVertex3f(64.8,37.5,39.5);
		glVertex3f(65,37.5,39.5);
		glVertex3f(65,37.5,-94.8);
		//sela kecil 3
		glColor3ub(140,140,140);
		glVertex3f(64.8,55.5,-94.8);//samping kanan luar
		glVertex3f(64.8,55.5,39.5);
		glVertex3f(64.8,55,39.5);
		glVertex3f(64.8,55,-94.8);
		glColor3ub(0,0,0);
		glVertex3f(64.8,55,-94.8);//atas
		glVertex3f(64.8,55,39.5);
		glVertex3f(65,55,39.5);
		glVertex3f(65,55,-94.8);
		glVertex3f(64.8,55.5,-64.8);//bawah
		glVertex3f(64.8,55.5,39.5);
		glVertex3f(65,55.5,39.5);
		glVertex3f(65,55.5,-64.8);

	glEnd();
}

void bangun_depan(){
	glBegin(GL_QUADS);
		glColor3ub(166,166,166); //depan kaca
		glVertex3f(-22,63,50);//atas
		glVertex3f(22,63,50);
		glVertex3f(22,81,50);
		glVertex3f(-22,81,50);
		glVertex3f(14,-15,50);//samping kanan
		glVertex3f(22,-15,50);
		glVertex3f(22,63,50);
		glVertex3f(14,63,50);
		glVertex3f(-14,-15,50);//samping kiri
		glVertex3f(-22,-15,50);
		glVertex3f(-22,63,50);
		glVertex3f(-14,63,50);
		glVertex3f(-22,-15,39);//samping kiri luar
		glVertex3f(-22,-15,50);
		glVertex3f(-22,81,50);
		glVertex3f(-22,81,39);
		glVertex3f(22,-15,39);//samping kanan luar
		glVertex3f(22,-15,50);
		glVertex3f(22,81,50);
		glVertex3f(22,81,39);
		glColor3ub(100,100,100);//dalam
		glVertex3f(-14,63,45);//atas
		glVertex3f(14,63,45);
		glVertex3f(14,63,50);
		glVertex3f(-14,63,50);
		glVertex3f(-14,-15,45);//samping kiri
		glVertex3f(-14,-15,50);
		glVertex3f(-14,63,50);
		glVertex3f(-14,63,45);
		glVertex3f(14,-15,45);//samping kanan
		glVertex3f(14,-15,50);
		glVertex3f(14,63,50);
		glVertex3f(14,63,45);
		// list bawah
		glVertex3f(25.5,-18,60.5);//depan
		glVertex3f(-25.5,-18,60.5);
		glVertex3f(-25.5,-15,60.5);
		glVertex3f(25.5,-15,60.5);
		glVertex3f(-25.5,-15,40);//atas
		glVertex3f(25.5,-15,40);
		glVertex3f(25.5,-15,60.5);
		glVertex3f(-25.5,-15,60.5);
		glVertex3f(25.5,-18,40);//samping kanan
		glVertex3f(25.5,-18,60.5);
		glVertex3f(25.5,-15,60.5);
		glVertex3f(25.5,-15,40);
		glVertex3f(-25.5,-18,40);//samping kiri
		glVertex3f(-25.5,-18,60.5);
		glVertex3f(-25.5,-15,60.5);
		glVertex3f(-25.5,-15,40);
		glColor3ub(0,0,0);
		glVertex3f(-25.5,-18,60);//bawah depan
		glVertex3f(25.5,-18,60);
		glVertex3f(25.5,-18,60.5);
		glVertex3f(-25.5,-18,60.5);
		glVertex3f(25,-18,40);//bawah kanan
		glVertex3f(25.5,-18,40);
		glVertex3f(25.5,-18,60.5);
		glVertex3f(25,-18,60.5);
		glVertex3f(-25,-18,40);//bawah kiri
		glVertex3f(-25.5,-18,40);
		glVertex3f(-25.5,-18,60.5);
		glVertex3f(-25,-18,60.5);

		glColor3ub(166,166,166);//depan kecil
		glVertex3f(45,-18,43);//depan
		glVertex3f(30,-18,43);
		glVertex3f(30,0,43);
		glVertex3f(45,0,43);
		glColor3ub(160,160,160);
		glVertex3f(45,-18,39.5);//samping kanan luar
		glVertex3f(45,-18,43);
		glVertex3f(45,0,43);
		glVertex3f(45,0,39.5);
		glVertex3f(30,-18,39.5);//samping kiri luar
		glVertex3f(30,-18,43);
		glVertex3f(30,0,43);
		glVertex3f(30,0,39.5);
		glColor3ub(166,166,166);//depan kecil 2
		glVertex3f(45,0.5,43);
		glVertex3f(30,0.5,43);
		glVertex3f(30,19,43);
		glVertex3f(45,19,43);
		glColor3ub(160,160,160);
		glVertex3f(45,0.5,39.5);//samping kanan luar
		glVertex3f(45,0.5,43);
		glVertex3f(45,19,43);
		glVertex3f(45,19,39.5);
		glVertex3f(30,0.5,39.5);//samping kiri luar
		glVertex3f(30,0.5,43);
		glVertex3f(30,19,43);
		glVertex3f(30,19,39.5);
		glColor3ub(166,166,166);//depan kecil 3
		glVertex3f(45,19.5,43);
		glVertex3f(30,19.5,43);
		glVertex3f(30,37,43);
		glVertex3f(45,37,43);
		glColor3ub(160,160,160);
		glVertex3f(45,19.5,39.5);//samping kanan luar
		glVertex3f(45,19.5,43);
		glVertex3f(45,37,43);
		glVertex3f(45,37,39.5);
		glVertex3f(30,19.5,39.5);//samping kiri luar
		glVertex3f(30,19.5,43);
		glVertex3f(30,37,43);
		glVertex3f(30,37,39.5);
		glColor3ub(166,166,166);//depan kecil 4
		glVertex3f(45,37.5,43);
		glVertex3f(30,37.5,43);
		glVertex3f(30,55,43);
		glVertex3f(45,55,43);
		glColor3ub(160,160,160);
		glVertex3f(45,37.5,39.5);//samping kanan luar
		glVertex3f(45,37.5,43);
		glVertex3f(45,55,43);
		glVertex3f(45,55,39.5);
		glVertex3f(30,37.5,39.5);//samping kiri luar
		glVertex3f(30,37.5,43);
		glVertex3f(30,55,43);
		glVertex3f(30,55,39.5);
		glColor3ub(166,166,166);//depan kecil 5
		glVertex3f(45,55.5,43);
		glVertex3f(30,55.5,43);
		glVertex3f(30,73,43);
		glVertex3f(45,73,43);
		glColor3ub(160,160,160);
		glVertex3f(45,55.5,39.5);//samping kanan luar
		glVertex3f(45,55.5,43);
		glVertex3f(45,73,43);
		glVertex3f(45,73,39.5);
		glVertex3f(30,55.5,39.5);//samping kiri luar
		glVertex3f(30,55.5,43);
		glVertex3f(30,73,43);
		glVertex3f(30,73,39.5);

		//sela kecil depan kecil
		glColor3ub(140,140,140);
		glVertex3f(29.8,0.5,42.5);//depan
		glVertex3f(44.8,0.5,42.5);
		glVertex3f(44.8,0,42.5);
		glVertex3f(29.8,0,42.5);
		glColor3ub(0,0,0);
		glVertex3f(29.8,0,43);//bawah
		glVertex3f(44.8,0,43);
		glVertex3f(44.8,0,42.5);
		glVertex3f(29.8,0,42.5);
		glVertex3f(29.8,0.5,43);//atas
		glVertex3f(44.8,0.5,43);
		glVertex3f(44.8,0.5,42.5);
		glVertex3f(29.8,0.5,42.5);
		glColor3ub(120,120,120);
		glVertex3f(44.8,0.5,42.5);//samping kanan
		glVertex3f(44.8,0.5,40);
		glVertex3f(44.8,0,40);
		glVertex3f(44.8,0,42.5);
		glVertex3f(29.8,0.5,42.5);//samping kiri
		glVertex3f(29.8,0.5,40);
		glVertex3f(29.8,0,40);
		glVertex3f(29.8,0,42.5);
		//sela kecil depan kecil 2
		glColor3ub(140,140,140);
		glVertex3f(29.8,19.5,42.5);//depan
		glVertex3f(44.8,19.5,42.5);
		glVertex3f(44.8,19,42.5);
		glVertex3f(29.8,19,42.5);
		glColor3ub(0,0,0);
		glVertex3f(29.8,19,43);//bawah
		glVertex3f(44.8,19,43);
		glVertex3f(44.8,19,42.5);
		glVertex3f(29.8,19,42.5);
		glVertex3f(29.8,19.5,43);//atas
		glVertex3f(44.8,19.5,43);
		glVertex3f(44.8,19.5,42.5);
		glVertex3f(29.8,19.5,42.5);
		glColor3ub(120,120,120);
		glVertex3f(44.8,19.5,42.5);//samping kanan
		glVertex3f(44.8,19.5,40);
		glVertex3f(44.8,19,40);
		glVertex3f(44.8,19,42.5);
		glVertex3f(29.8,19.5,42.5);//samping kiri
		glVertex3f(29.8,19.5,40);
		glVertex3f(29.8,19,40);
		glVertex3f(29.8,19,42.5);
		//sela kecil depan kecil 3
		glColor3ub(140,140,140);
		glVertex3f(29.8,37.5,42.5);//depan
		glVertex3f(44.8,37.5,42.5);
		glVertex3f(44.8,37,42.5);
		glVertex3f(29.8,37,42.5);
		glColor3ub(0,0,0);
		glVertex3f(29.8,37,43);//bawah
		glVertex3f(44.8,37,43);
		glVertex3f(44.8,37,42.5);
		glVertex3f(29.8,37,42.5);
		glVertex3f(29.8,37.5,43);//atas
		glVertex3f(44.8,37.5,43);
		glVertex3f(44.8,37.5,42.5);
		glVertex3f(29.8,37.5,42.5);
		glColor3ub(120,120,120);
		glVertex3f(44.8,37.5,42.5);//samping kanan
		glVertex3f(44.8,37.5,40);
		glVertex3f(44.8,37,40);
		glVertex3f(44.8,37,42.5);
		glVertex3f(29.8,37.5,42.5);//samping kiri
		glVertex3f(29.8,37.5,40);
		glVertex3f(29.8,37,40);
		glVertex3f(29.8,37,42.5);
		//sela kecil depan kecil 4
		glColor3ub(140,140,140);
		glVertex3f(29.8,55.5,42.5);//depan
		glVertex3f(44.8,55.5,42.5);
		glVertex3f(44.8,55,42.5);
		glVertex3f(29.8,55,42.5);
		glColor3ub(0,0,0);
		glVertex3f(29.8,55,43);//bawah
		glVertex3f(44.8,55,43);
		glVertex3f(44.8,55,42.5);
		glVertex3f(29.8,55,42.5);
		glVertex3f(29.8,55.5,43);//atas
		glVertex3f(44.8,55.5,43);
		glVertex3f(44.8,55.5,42.5);
		glVertex3f(29.8,55.5,42.5);
		glColor3ub(120,120,120);
		glVertex3f(44.8,55.5,42.5);//samping kanan
		glVertex3f(44.8,55.5,40);
		glVertex3f(44.8,55,40);
		glVertex3f(44.8,55,42.5);
		glVertex3f(29.8,55.5,42.5);//samping kiri
		glVertex3f(29.8,55.5,40);
		glVertex3f(29.8,55,40);
		glVertex3f(29.8,55,42.5);

	glEnd();
}

void atap_bangun_depan(){
glBegin(GL_POLYGON); // lantai2 bawah
		glColor3ub(130, 130, 130);
		glVertex3f(-22, 81,20);
		glVertex3f(-22,81,50);
		glVertex3f(22,81,50);
		glVertex3f(22,81,20);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 atas
		glColor3ub(130, 130, 130);
		glVertex3f(-22,83,20);
		glVertex3f(-22,83,50);
		glVertex3f(22,83,50);
		glVertex3f(22,83,20);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 depan
		glColor3ub(110, 30, 30);
		glVertex3f(-22,83,50);
		glVertex3f(22,83,50);
		glVertex3f(22,81,50);
		glVertex3f(-22,81,50);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 belakng
		glColor3ub(110, 30, 30);
		glVertex3f(-22,83,20);
		glVertex3f(22,83,20);
		glVertex3f(22,81,20);
		glVertex3f(-22,81,20);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kiri
		glColor3ub(110, 30, 30);
		glVertex3f(-22,83,20);
		glVertex3f(-22,83,50);
		glVertex3f(-22,81,50);
		glVertex3f(-22,81,20);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kanan
		glColor3ub(110, 30, 30);
		glVertex3f(22,83,20);
		glVertex3f(22,83,50);
		glVertex3f(22,81,50);
		glVertex3f(22,81,20);
		glEnd();

		//layer2
		glBegin(GL_POLYGON); // lantai2 bawah
		glColor3ub(30, 30, 30);
		glVertex3f(-25,85,17);
		glVertex3f(-25,85,53);
		glVertex3f(25,85,53);
		glVertex3f(25,85,17);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 atas
		glColor3ub(30, 30, 30);
		glVertex3f(-25,83,17);
		glVertex3f(-25,83,53);
		glVertex3f(25,83,53);
		glVertex3f(25,83,17);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 depan
		glColor3ub(110, 30, 30);
		glVertex3f(-25,85,53);
		glVertex3f(25,85,53);
		glVertex3f(25,83,53);
		glVertex3f(-25,83,53);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 belakng
		glColor3ub(110, 30, 30);
		glVertex3f(-25,85,17);
		glVertex3f(25,85,17);
		glVertex3f(25,83,17);
		glVertex3f(-25,83,17);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kiri
		glColor3ub(110, 30, 30);
		glVertex3f(-25,85,17);
		glVertex3f(-25,85,53);
		glVertex3f(-25,83,53);
		glVertex3f(-25,83,17);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kanan
		glColor3ub(110, 30, 30);
		glVertex3f(25,85,17);
		glVertex3f(25,85,53);
		glVertex3f(25,83,53);
		glVertex3f(25,83,17);
		glEnd();

		//LAYER3
		glBegin(GL_POLYGON); // lantai2 bawah
		glColor3ub(30, 30, 30);
		glVertex3f(-28,87,14);
		glVertex3f(-28,87,56);
		glVertex3f(28,87,56);
		glVertex3f(28,87,14);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 atas
		glColor3ub(30, 30, 30);
		glVertex3f(-28,85,14);
		glVertex3f(-28,85,56);
		glVertex3f(28,85,56);
		glVertex3f(28,85,14);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 depan
		glColor3ub(110, 30, 30);
		glVertex3f(-28,87,56);
		glVertex3f(28,87,56);
		glVertex3f(28,85,56);
		glVertex3f(-28,85,56);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 belakng
		glColor3ub(110, 30, 30);
		glVertex3f(-28,87,14);
		glVertex3f(28,87,14);
		glVertex3f(28,85,14);
		glVertex3f(-28,85,14);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kiri
		glColor3ub(110, 30, 30);
		glVertex3f(-28,87,14);
		glVertex3f(-28,87,56);
		glVertex3f(-28,85,56);
		glVertex3f(-28,85,14);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kanan
		glColor3ub(110, 30, 30);
		glVertex3f(28,87,14);
		glVertex3f(28,87,56);
		glVertex3f(28,85,56);
		glVertex3f(28,85,14);
		glEnd();
		//TUTUP
		glBegin(GL_QUADS); //belakang
		glColor3ub(166, 166, 166);
		glVertex3f(-22,81,20);
		glVertex3f(22,81,20);
		glVertex3f(22,79.5,20);
		glVertex3f(-22,79.5,20);
		glVertex3f(-22,81,20);//kiri
		glVertex3f(-22,81,40);
		glVertex3f(-22,79.5,40);
		glVertex3f(-22,79.5,20);
		glVertex3f(22,81,20);//kanan
		glVertex3f(22,81,40);
		glVertex3f(22,79.5,40);
		glVertex3f(22,79.5,20);

}

void atap_segitiga(){
	glBegin(GL_POLYGON);
		glColor3ub(130, 130, 130);
		glVertex3f(-50,79,20);//depan
		glVertex3f(-50,85,20);
		glVertex3f(0,105,20);
		glVertex3f(50, 85,20);
		glVertex3f(50,79,20);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3ub(130, 130, 130);
		glVertex3f(-50,79,-80);// belakang
		glVertex3f(-50,85,-80);
		glVertex3f(0,105,-80);
		glVertex3f(50, 85,-80);
		glVertex3f(50,79,-80);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(130, 130, 130);
		glVertex3f(50, 85,-80);//kanan
		glVertex3f(50,85,20);
		glVertex3f(50,79,20);
		glVertex3f(50,79,-80);
		glVertex3f(-50, 85,-80);//kiri
		glVertex3f(-50,85,20);
		glVertex3f(-50,79,20);
		glVertex3f(-50,79,-80);

		//atap bawah
		glColor3ub(30, 30, 30);
		glVertex3f(55, 84,-85);//kanan
		glVertex3f(55,84,25);
		glVertex3f(0,105,25);
		glVertex3f(0,105,-85);
		glVertex3f(-55, 84,-85);//kiri
		glVertex3f(-55,84,25);
		glVertex3f(0,105,25);
		glVertex3f(0,105,-85);
		glColor3ub(30, 30, 30);
		//atap atas
		glVertex3f(55, 87,-85);//kanan
		glVertex3f(55,87,25);
		glVertex3f(0,108,25);
		glVertex3f(0,108,-85);
		glVertex3f(-55, 87,-85);//kiri
		glVertex3f(-55,87,25);
		glVertex3f(0,108,25);
		glVertex3f(0,108,-85);

		//tutup samping
		glVertex3f(55,87,-85);//kanan
		glVertex3f(55,87,25);
		glVertex3f(55,84,25);
		glVertex3f(55,84,-85);
		glVertex3f(-55,87,-85);//kiri
		glVertex3f(-55,87,25);
		glVertex3f(-55,84,25);
		glVertex3f(-55,84,-85);
		//tutup depan
		//kiri
		glVertex3f( 0,105,25);//depan
		glVertex3f(0,108,25);
		glVertex3f( 55,87,25);
		glVertex3f(55, 84,25);
		glVertex3f( 0,105,-85);//belakang
		glVertex3f(0,108,-85);
		glVertex3f( 55,87,-85);
		glVertex3f(55, 84,-85);
		//kanan samping
		glVertex3f( 0,105,25);//depan
		glVertex3f(0,108,25);
		glVertex3f( -55,87,25);
		glVertex3f(-55, 84,25);
		glVertex3f( 0,105,-85);//belakang
		glVertex3f(0,108,-85);
		glVertex3f( -55,87,-85);
		glVertex3f(-55, 84,-85);
		glEnd();

}

void jendela_samping(){
glBegin(GL_QUADS);
	glColor3ub(30, 30, 30);
		glVertex3f(-65.01,-23,-20);//pintu
		glVertex3f(-65.01,-23,5);
		glVertex3f(-65.01,-50,5);
		glVertex3f(-65.01,-50,-20);
		glVertex3f(-65.01,-23,-50);//jendela
		glVertex3f(-65.01,-23,-25);
		glVertex3f(-65.01,-45,-25);
		glVertex3f(-65.01,-45,-50);
		glVertex3f(-65.01,-23,-88);//jendela 2
		glVertex3f(-65.01,-23,-60);
		glVertex3f(-65.01,-45,-60);
		glVertex3f(-65.01,-45,-88);
		glVertex3f(-65.01,-23, 35);//jendela 3
		glVertex3f(-65.01,-23, 10);
		glVertex3f(-65.01,-45, 10);
		glVertex3f(-65.01,-45, 35);
	glEnd();
}

void teduhan(){
		glBegin(GL_POLYGON); // teduhan belakang
		glColor3ub(110, 30, 30);
		glVertex3f(-25,-19.9,40.1);
		glVertex3f(25,-19.9,40.1);
		glVertex3f(25,-17.9,40.1);
		glVertex3f(-25,-17.9,40.1);
		glEnd();

		glBegin(GL_POLYGON); // teduhan depan
		glColor3ub(110, 30, 30);
		glVertex3f(-25,-19.9,60.1);
		glVertex3f(25,-19.9,60.1);
		glVertex3f(25,-17.9,60.1);
		glVertex3f(-25,-17.9,60.1);
		glEnd();

		glBegin(GL_POLYGON); // teduhan belakang
		glColor3ub(110, 30, 30);
		glVertex3f(-25,-19.9,60.1);
		glVertex3f(25,-19.9,60.1);
		glVertex3f(25,-17.9,60.1);
		glVertex3f(-25,-17.9,60.1);
		glEnd();

		glBegin(GL_POLYGON); // teduhan KIRI
		glColor3ub(110, 30, 30);
		glVertex3f(-25,-19.9,40.1);
		glVertex3f(-25,-19.9,60.1);
		glVertex3f(-25,-17.9,60.1);
		glVertex3f(-25,-17.9,40.1);
		glEnd();

		glBegin(GL_POLYGON); // teduhan KIRI
		glColor3ub(110, 30, 30);
		glVertex3f(25,-19.9,40.1);
		glVertex3f(25,-19.9,60.1);
		glVertex3f(25,-17.9,60.1);
		glVertex3f(25,-17.9,40.1);
		glEnd();

		glBegin(GL_POLYGON); // teduhan bawah
		glColor3ub(50, 90, 90);
		glVertex3f(-25,-19.9,60.1);
		glVertex3f(-25,-19.9,40.1);
		glVertex3f(25,-19.9,40.1);
		glVertex3f(25,-19.9,60.1);
		glEnd();

		glBegin(GL_POLYGON); // teduhan atas
		glColor3ub(50, 90, 90);
		glVertex3f(-25,-17.9,60.1);
		glVertex3f(-25,-17.9,40.1);
		glVertex3f(25,-17.9,40.1);
		glVertex3f(25,-17.9,60.1);
		glEnd();
}

void pintu(){
	glBegin(GL_QUADS); // depan

		glColor3ub(1,1,1); //depan kaca tengah
		glVertex3f(-20,-48,40.5);//depan
		glVertex3f(20,-48,40.5);
		glVertex3f(20,-25,40.5);
		glVertex3f(-20,-25,40.5);

		glColor3ub(1,1,1); //depan kaca kiri
		glVertex3f(-25,-48,40.5);//depan
		glVertex3f(-53,-48,40.5);
		glVertex3f(-53,-25,40.5);
		glVertex3f(-25,-25,40.5);

        glColor3ub(1,1,1); //depan kaca kiri
		glVertex3f(25,-48,40.5);//depan
		glVertex3f(53,-48,40.5);
		glVertex3f(53,-25,40.5);
		glVertex3f(25,-25,40.5);


			glEnd();
}

void kaca(){
	glBegin(GL_QUADS); // depan
		glColor3ub(166,255,150);//kaca
		glVertex3f(-14,-18,45.01);
		glVertex3f(14,-18,45.01);
		glVertex3f(14,60,45.01);
		glVertex3f(-14,60,45.01);
		//list kaca 1 ATASBAWAH
		glColor3ub(0,255,0); //depan
		glVertex3f(-9,-18,45.2);
		glVertex3f(-8.5,-18,45.2);
		glVertex3f(-8.5,60,45.2);
		glVertex3f(-9,60,45.2);
		glColor3ub(166,166,166);
		glVertex3f(-9,-18,45.2);//samping kanan
		glVertex3f(-9,-18,45);
		glVertex3f(-9,60,45);
		glVertex3f(-9,60,45.2);
		glVertex3f(-8.5,-18,45.2);//samping kiri
		glVertex3f(-8.5,-18,45);
		glVertex3f(-8.5,60,45);
		glVertex3f(-8.5,60,45.2);
		//list kaca 2
		glColor3ub(0,255,0);
		glVertex3f(-3,-18,45.2);//depan
		glVertex3f(-2.5,-18,45.2);
		glVertex3f(-2.5,60,45.2);
		glVertex3f(-3,60,45.2);
		glColor3ub(166,166,166);
		glVertex3f(-3,-18,45.2);//samping kanan
		glVertex3f(-3,-18,45);
		glVertex3f(-3,60,45);
		glVertex3f(-3,60,45.2);
		glVertex3f(-2.5,-18,45.2);//samping kiri
		glVertex3f(-2.5,-18,45);
		glVertex3f(-2.5,60,45);
		glVertex3f(-2.5,60,45.2);
		//list kaca 3
		glColor3ub(0,255,0);
		glVertex3f( 3,-18,45.2);//depan
		glVertex3f( 3.5,-18,45.2);
		glVertex3f( 3.5,60,45.2);
		glVertex3f( 3,60,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 3,-18,45.2);//samping kanan
		glVertex3f( 3,-18,45);
		glVertex3f( 3,60,45);
		glVertex3f( 3,60,45.2);
		glVertex3f( 3.5,-18,45.2);//samping kiri
		glVertex3f( 3.5,-18,45);
		glVertex3f( 3.5,60,45);
		glVertex3f( 3.5,60,45.2);
		//list kaca 4
		glColor3ub(0,255,0);
		glVertex3f( 9,-18,45.2);//depan
		glVertex3f( 9.5,-18,45.2);
		glVertex3f( 9.5,60,45.2);
		glVertex3f( 9,60,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 9,-18,45.2);//samping kanan
		glVertex3f( 9,-18,45);
		glVertex3f( 9,60,45);
		glVertex3f( 9,60,45.2);
		glVertex3f( 9.5,-18,45.2);//samping kiri
		glVertex3f( 9.5,-18,45);
		glVertex3f( 9.5,60,45);
		glVertex3f( 9.5,60,45.2);

		//list kaca KANANKIRI 1
		glColor3ub(0,255,0);
		glVertex3f( 14,53.5,45.2);//depan
		glVertex3f(-14,53.5,45.2);
		glVertex3f(-14,54,45.2);
		glVertex3f( 14,54,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,54,45.2);//atas
		glVertex3f(-14,54,45.2);
		glVertex3f(-14,54,45);
		glVertex3f( 14,54,45);
		glVertex3f( 14,53.5,45.2);//bawah
		glVertex3f(-14,53.5,45.2);
		glVertex3f(-14,53.5,45);
		glVertex3f( 14,53.5,45);
		//list kaca KANANKIRI 2
		glColor3ub(0,255,0);
		glVertex3f( 14,47.5,45.2);//depan
		glVertex3f(-14,47.5,45.2);
		glVertex3f(-14,48,45.2);
		glVertex3f( 14,48,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,48,45.2);//atas
		glVertex3f(-14,48,45.2);
		glVertex3f(-14,48,45);
		glVertex3f( 14,48,45);
		glVertex3f( 14,47.5,45.2);//bawah
		glVertex3f(-14,47.5,45.2);
		glVertex3f(-14,47.5,45);
		glVertex3f( 14,47.5,45);
		//list kaca KANANKIRI 3
		glColor3ub(0,255,0);
		glVertex3f( 14,41.5,45.2);//depan
		glVertex3f(-14,41.5,45.2);
		glVertex3f(-14,42,45.2);
		glVertex3f( 14,42,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,42,45.2);//atas
		glVertex3f(-14,42,45.2);
		glVertex3f(-14,42,45);
		glVertex3f( 14,42,45);
		glVertex3f( 14,41.5,45.2);//bawah
		glVertex3f(-14,41.5,45.2);
		glVertex3f(-14,41.5,45);
		glVertex3f( 14,41.5,45);
		//list kaca KANANKIRI 4
		glColor3ub(0,255,0);
		glVertex3f( 14,35.5,45.2);//depan
		glVertex3f(-14,35.5,45.2);
		glVertex3f(-14,36,45.2);
		glVertex3f( 14,36,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,36,45.2);//atas
		glVertex3f(-14,36,45.2);
		glVertex3f(-14,36,45);
		glVertex3f( 14,36,45);
		glVertex3f( 14,35.5,45.2);//bawah
		glVertex3f(-14,35.5,45.2);
		glVertex3f(-14,35.5,45);
		glVertex3f( 14,35.5,45);
		//list kaca KANANKIRI 5
		glColor3ub(0,255,0);
		glVertex3f( 14,29.5,45.2);//depan
		glVertex3f(-14,29.5,45.2);
		glVertex3f(-14,30,45.2);
		glVertex3f( 14,30,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,30,45.2);//atas
		glVertex3f(-14,30,45.2);
		glVertex3f(-14,30,45);
		glVertex3f( 14,30,45);
		glVertex3f( 14,29.5,45.2);//bawah
		glVertex3f(-14,29.5,45.2);
		glVertex3f(-14,29.5,45);
		glVertex3f( 14,29.5,45);
		//list kaca KANANKIRI 6
		glColor3ub(0,255,0);
		glVertex3f( 14,29.5,45.2);//depan
		glVertex3f(-14,29.5,45.2);
		glVertex3f(-14,30,45.2);
		glVertex3f( 14,30,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,30,45.2);//atas
		glVertex3f(-14,30,45.2);
		glVertex3f(-14,30,45);
		glVertex3f( 14,30,45);
		glVertex3f( 14,29.5,45.2);//bawah
		glVertex3f(-14,29.5,45.2);
		glVertex3f(-14,29.5,45);
		glVertex3f( 14,29.5,45);
		//list kaca KANANKIRI 7
		glColor3ub(0,255,0);
		glVertex3f( 14,23.5,45.2);//depan
		glVertex3f(-14,23.5,45.2);
		glVertex3f(-14,24,45.2);
		glVertex3f( 14,24,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,24,45.2);//atas
		glVertex3f(-14,24,45.2);
		glVertex3f(-14,24,45);
		glVertex3f( 14,24,45);
		glVertex3f( 14,23.5,45.2);//bawah
		glVertex3f(-14,23.5,45.2);
		glVertex3f(-14,23.5,45);
		glVertex3f( 14,23.5,45);
		//list kaca KANANKIRI 8
		glColor3ub(0,255,0);
		glVertex3f( 14,17.5,45.2);//depan
		glVertex3f(-14,17.5,45.2);
		glVertex3f(-14,18,45.2);
		glVertex3f( 14,18,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,18,45.2);//atas
		glVertex3f(-14,18,45.2);
		glVertex3f(-14,18,45);
		glVertex3f( 14,18,45);
		glVertex3f( 14,17.5,45.2);//bawah
		glVertex3f(-14,17.5,45.2);
		glVertex3f(-14,17.5,45);
		glVertex3f( 14,17.5,45);
		//list kaca KANANKIRI 9
		glColor3ub(0,255,0);
		glVertex3f( 14,11.5,45.2);//depan
		glVertex3f(-14,11.5,45.2);
		glVertex3f(-14,12,45.2);
		glVertex3f( 14,12,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,12,45.2);//atas
		glVertex3f(-14,12,45.2);
		glVertex3f(-14,12,45);
		glVertex3f( 14,12,45);
		glVertex3f( 14,11.5,45.2);//bawah
		glVertex3f(-14,11.5,45.2);
		glVertex3f(-14,11.5,45);
		glVertex3f( 14,11.5,45);
		//list kaca KANANKIRI 10
		glColor3ub(0,255,0);
		glVertex3f( 14,5.5,45.2);//depan
		glVertex3f(-14,5.5,45.2);
		glVertex3f(-14,6,45.2);
		glVertex3f( 14,6,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,6,45.2);//atas
		glVertex3f(-14,6,45.2);
		glVertex3f(-14,6,45);
		glVertex3f( 14,6,45);
		glVertex3f( 14,5.5,45.2);//bawah
		glVertex3f(-14,5.5,45.2);
		glVertex3f(-14,5.5,45);
		glVertex3f( 14,5.5,45);
		//list kaca KANANKIRI 11
		glColor3ub(0,255,0);
		glVertex3f( 14,-0.5,45.2);//depan
		glVertex3f(-14,-0.5,45.2);
		glVertex3f(-14,0,45.2);
		glVertex3f( 14,0,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,0,45.2);//atas
		glVertex3f(-14,0,45.2);
		glVertex3f(-14,0,45);
		glVertex3f( 14,0,45);
		glVertex3f( 14,-0.5,45.2);//bawah
		glVertex3f(-14,-0.5,45.2);
		glVertex3f(-14,-0.5,45);
		glVertex3f( 14,-0.5,45);
		//list kaca KANANKIRI 12
		glColor3ub(0,255,0);
		glVertex3f( 14,-6.5,45.2);//depan
		glVertex3f(-14,-6.5,45.2);
		glVertex3f(-14,-6,45.2);
		glVertex3f( 14,-6,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,-6,45.2);//atas
		glVertex3f(-14,-6,45.2);
		glVertex3f(-14,-6,45);
		glVertex3f( 14,-6,45);
		glVertex3f( 14,-6.5,45.2);//bawah
		glVertex3f(-14,-6.5,45.2);
		glVertex3f(-14,-6.5,45);
		glVertex3f( 14,-6.5,45);
		//list kaca KANANKIRI 13
		glColor3ub(0,255,0);
		glVertex3f( 14,-12.5,45.2);//depan
		glVertex3f(-14,-12.5,45.2);
		glVertex3f(-14,-12,45.2);
		glVertex3f( 14,-12,45.2);
		glColor3ub(166,166,166);
		glVertex3f( 14,-12,45.2);//atas
		glVertex3f(-14,-12,45.2);
		glVertex3f(-14,-12,45);
		glVertex3f( 14,-12,45);
		glVertex3f( 14,-12.5,45.2);//bawah
		glVertex3f(-14,-12.5,45.2);
		glVertex3f(-14,-12.5,45);
		glVertex3f( 14,-12.5,45);

		glEnd();
}

void atap1(){
	//------------------------------------------------------------------
		glBegin(GL_POLYGON); // lantai2 bawah
		glColor3ub(30, 30, 30);
		glVertex3f(-65,-19.9,40);
		glVertex3f(-65,-19.9,-95);
		glVertex3f(65,-19.9,-95);
		glVertex3f(65,-19.9,40);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 atas
		glColor3ub(30, 30, 30);
		glVertex3f(-65,-17.9,40);
		glVertex3f(-65,-17.9,-95);
		glVertex3f(65,-17.9,-95);
		glVertex3f(65,-17.9,40);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 depan
		glColor3ub(110, 30, 30);
		glVertex3f(-65,-19.9,40);
		glVertex3f(65,-19.9,40);
		glVertex3f(65,-17.9,40);
		glVertex3f(-65,-17.9,40);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 belakng
		glColor3ub(110, 30, 30);
		glVertex3f(-65,-19.9,-95);
		glVertex3f(65,-19.9,-95);
		glVertex3f(65,-17.9,-95);
		glVertex3f(-65,-17.9,-95);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kiri
		glColor3ub(110, 30, 30);
		glVertex3f(-65,-19.9,-95);
		glVertex3f(-65,-19.9,40);
		glVertex3f(-65,-17.9,40);
		glVertex3f(-65,-17.9,-95);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kanan
		glColor3ub(110, 30, 30);
		glVertex3f(65,-19.9,-95);
		glVertex3f(65,-19.9,40);
		glVertex3f(65,-17.9,40);
		glVertex3f(65,-17.9,-95);
		glEnd();
}

void atap2(){
	//------------------------------------------------------------------
		glBegin(GL_POLYGON); // lantai2 bawah
		glColor3ub(30, 30, 30);
		glVertex3f(-68,-19.9,43);
		glVertex3f(-68,-19.9,-98);
		glVertex3f(68,-19.9,-98);
		glVertex3f(68,-19.9,43);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 atas
		glColor3ub(30, 30, 30);
		glVertex3f(-68,-17.9,43);
		glVertex3f(-68,-17.9,-98);
		glVertex3f(68,-17.9,-98);
		glVertex3f(68,-17.9,43);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 depan
		glColor3ub(110, 30, 30);
		glVertex3f(-68,-19.9,43);
		glVertex3f(68,-19.9,43);
		glVertex3f(68,-17.9,43);
		glVertex3f(-68,-17.9,43);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 belakng
		glColor3ub(110, 30, 30);
		glVertex3f(-68,-19.9,-98);
		glVertex3f(68,-19.9,-98);
		glVertex3f(68,-17.9,-98);
		glVertex3f(-68,-17.9,-98);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kiri
		glColor3ub(110, 30, 30);
		glVertex3f(-68,-19.9,-98);
		glVertex3f(-68,-19.9,43);
		glVertex3f(-68,-17.9,43);
		glVertex3f(-68,-17.9,-98);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kanan
		glColor3ub(110, 30, 30);
		glVertex3f(68,-19.9,-98);
		glVertex3f(68,-19.9,43);
		glVertex3f(68,-17.9,43);
		glVertex3f(68,-17.9,-98);
		glEnd();
}

void atap3(){
	//------------------------------------------------------------------
		glBegin(GL_POLYGON); // lantai2 bawah
		glColor3ub(30, 30, 30);
		glVertex3f(-71,-19.9,46);
		glVertex3f(-71,-19.9,-101);
		glVertex3f(71,-19.9,-101);
		glVertex3f(71,-19.9,46);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 atas
		glColor3ub(30, 30, 30);
		glVertex3f(-71,-17.9,46);
		glVertex3f(-71,-17.9,-101);
		glVertex3f(71,-17.9,-101);
		glVertex3f(71,-17.9,46);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 depan
		glColor3ub(110, 30, 30);
		glVertex3f(-71,-19.9,46);
		glVertex3f(71,-19.9,46);
		glVertex3f(71,-17.9,46);
		glVertex3f(-71,-17.9,46);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 belakng
		glColor3ub(110, 30, 30);
		glVertex3f(-71,-19.9,-101);
		glVertex3f(71,-19.9,-101);
		glVertex3f(71,-17.9,-101);
		glVertex3f(-71,-17.9,-101);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kiri
		glColor3ub(110, 30, 30);
		glVertex3f(-71,-19.9,-101);
		glVertex3f(-71,-19.9,46);
		glVertex3f(-71,-17.9,46);
		glVertex3f(-71,-17.9,-101);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kanan
		glColor3ub(110, 30, 30);
		glVertex3f(71,-19.9,-101);
		glVertex3f(71,-19.9,46);
		glVertex3f(71,-17.9,46);
		glVertex3f(71,-17.9,-101);
		glEnd();
}

void tampil(void)
{

	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    gluLookAt(0,0,10,0,0,0,0,1,0);
	glRotatef(xrot, 1, 0,0);
	glRotatef(yrot, 0,1,0);
	//-----
	pintu();
	atap_bangun_depan();
	bangun_depan();
	bangun_atas();
	bangun_samping();
	atap_segitiga();
	jendela_samping();
	glPushMatrix();
	glRotated(180,0,5,0);
	glTranslated(0,0,54.8);
	bangun_samping(); //kiri
	bangun_atas(); //belakang
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,3,0);
	kaca();

	glPushMatrix(); //samping
	glRotated(-90,0,5,0);
	glTranslated(-15,0,25);
	kaca();
	glTranslated(0,-3,0);
	atap_bangun_depan();
	bangun_depan();
	teduhan();
	glPopMatrix();

	//-------
	glPushMatrix();
	glTranslated(0,90,0);
	atap1();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,92,0);
	atap2();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,94,0);
	atap3();
	glPopMatrix();

	glPopMatrix();
	//-----

		glBegin(GL_POLYGON); // tanah
		glColor3ub(158, 55, 0);
		glVertex3f(-75,-48,65);
		glVertex3f(-75,-48,-105);
		glVertex3f(75,-48,-105);
		glVertex3f(75,-48,65);
		glEnd();

		glBegin(GL_POLYGON); // bawah
		glColor3f(1,0.5,0);
		glVertex3f(-65,-47.9,40);
		glVertex3f(65,-47.9,40);
		glVertex3f(65,-47.9,-95);
		glVertex3f(-65,-47.9,-95);
		glEnd();

		glBegin(GL_POLYGON); // kiri
		glColor3f(1,0.5,0);
		glVertex3f(-65,-47.9,-95);
		glVertex3f(-65,-47.9,40);
		glVertex3f(-65,-20,40);
		glVertex3f(-65,-20,-95);
		glEnd();

		glBegin(GL_POLYGON); // kanan
		glColor3f(1,0.5,0);
		glVertex3f(65,-47.9,-95);
		glVertex3f(65,-47.9,40);
		glVertex3f(65,-20,40);
		glVertex3f(65,-20,-95);
		glEnd();

		glBegin(GL_POLYGON); // belakang
		glColor3f(1,0.5,0);
		glVertex3f(-65,-47.9,-95);
		glVertex3f(65,-47.9,-95);
		glVertex3f(65,-20,-95);
		glVertex3f(-65,-20,-95);
		glEnd();

		glBegin(GL_POLYGON); // depan
		glColor3f(1,0.5,0);
		glVertex3f(-65,-47.9,40);
		glVertex3f(65,-47.9,40);
		glVertex3f(65,-20,40);
		glVertex3f(-65,-20,40);
		glEnd();
		//------------------------------------------------------------------
		glBegin(GL_POLYGON); // lantai2 bawah
		glColor3ub(30, 30, 30);
		glVertex3f(-65,-19.9,40);
		glVertex3f(-65,-19.9,-95);
		glVertex3f(65,-19.9,-95);
		glVertex3f(65,-19.9,40);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 atas
		glColor3ub(30, 30, 30);
		glVertex3f(-65,-17.9,40);
		glVertex3f(-65,-17.9,-95);
		glVertex3f(65,-17.9,-95);
		glVertex3f(65,-17.9,40);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 depan
		glColor3ub(110, 30, 30);
		glVertex3f(-65,-19.9,40);
		glVertex3f(65,-19.9,40);
		glVertex3f(65,-17.9,40);
		glVertex3f(-65,-17.9,40);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 belakng
		glColor3ub(110, 30, 30);
		glVertex3f(-65,-19.9,-95);
		glVertex3f(65,-19.9,-95);
		glVertex3f(65,-17.9,-95);
		glVertex3f(-65,-17.9,-95);
		glEnd();

		glBegin(GL_POLYGON); // lantai2 kiri
		glColor3ub(110, 30, 30);
		glVertex3f(-65,-19.9,-95);
		glVertex3f(-65,-19.9,40);
		glVertex3f(-65,-17.9,40);
		glVertex3f(-65,-17.9,-95);
		glEnd();


		glBegin(GL_POLYGON); // lantai2 kanan
		glColor3ub(110, 30, 30);
		glVertex3f(65,-19.9,-95);
		glVertex3f(65,-19.9,40);
		glVertex3f(65,-17.9,40);
		glVertex3f(65,-17.9,-95);
		glEnd();

		//----------------------------------------------
		glBegin(GL_POLYGON); // teduhan belakang
		glColor3ub(110, 30, 30);
		glVertex3f(-25,-19.9,40.1);
		glVertex3f(25,-19.9,40.1);
		glVertex3f(25,-17.9,40.1);
		glVertex3f(-25,-17.9,40.1);
		glEnd();

		glBegin(GL_POLYGON); // teduhan depan
		glColor3ub(110, 30, 30);
		glVertex3f(-25,-19.9,60.1);
		glVertex3f(25,-19.9,60.1);
		glVertex3f(25,-17.9,60.1);
		glVertex3f(-25,-17.9,60.1);
		glEnd();

		glBegin(GL_POLYGON); // teduhan belakang
		glColor3ub(110, 30, 30);
		glVertex3f(-25,-19.9,60.1);
		glVertex3f(25,-19.9,60.1);
		glVertex3f(25,-17.9,60.1);
		glVertex3f(-25,-17.9,60.1);
		glEnd();

		glBegin(GL_POLYGON); // teduhan KIRI
		glColor3ub(110, 30, 30);
		glVertex3f(-25,-19.9,40.1);
		glVertex3f(-25,-19.9,60.1);
		glVertex3f(-25,-17.9,60.1);
		glVertex3f(-25,-17.9,40.1);
		glEnd();

		glBegin(GL_POLYGON); // teduhan KIRI
		glColor3ub(110, 30, 30);
		glVertex3f(25,-19.9,40.1);
		glVertex3f(25,-19.9,60.1);
		glVertex3f(25,-17.9,60.1);
		glVertex3f(25,-17.9,40.1);
		glEnd();

		glBegin(GL_POLYGON); // teduhan bawah
		glColor3ub(50, 90, 90);
		glVertex3f(-25,-19.9,60.1);
		glVertex3f(-25,-19.9,40.1);
		glVertex3f(25,-19.9,40.1);
		glVertex3f(25,-19.9,60.1);
		glEnd();

		glBegin(GL_POLYGON); // teduhan atas
		glColor3ub(50, 90, 90);
		glVertex3f(-25,-17.9,60.1);
		glVertex3f(-25,-17.9,40.1);
		glVertex3f(25,-17.9,40.1);
		glVertex3f(25,-17.9,60.1);
		glEnd();

		//---------------------------------------------------
		//PAGER
		glBegin(GL_POLYGON); // pager atas
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-40,75);
		glVertex3f(5,-40,75);
		glVertex3f(5,-40,70);
		glVertex3f(-75,-40,70);
		glEnd();

		glBegin(GL_POLYGON); // pager bawah
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-48,75);
		glVertex3f(5,-48,75);
		glVertex3f(5,-48,70);
		glVertex3f(-75,-48,70);
		glEnd();

		glBegin(GL_POLYGON); // pager kiri
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-48,70);
		glVertex3f(-75,-48,75);
		glVertex3f(-75,-40,75);
		glVertex3f(-75,-40,70);
		glEnd();

		glBegin(GL_POLYGON); // pager kanan
		glColor3ub(20, 20, 20);
		glVertex3f(5,-48,70);
		glVertex3f(5,-48,75);
		glVertex3f(5,-40,75);
		glVertex3f(5,-40,70);
		glEnd();

		glBegin(GL_POLYGON); // pager depan
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-48,75);
		glVertex3f(5,-48,75);
		glVertex3f(5,-40,75);
		glVertex3f(-75,-40,75);
		glEnd();

		glBegin(GL_POLYGON); // pager BELAKANG
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-48,70);
		glVertex3f(5,-48,70);
		glVertex3f(5,-40,70);
		glVertex3f(-75,-40,70);
		glEnd();

		//----------------------------------------------------------
		//PAGER2
		glBegin(GL_POLYGON); // pager atas
		glColor3ub(20, 20, 20);
		glVertex3f(45,-40,75);
		glVertex3f(75,-40,75);
		glVertex3f(75,-40,70);
		glVertex3f(45,-40,70);
		glEnd();

		glBegin(GL_POLYGON); // pager bawah
		glColor3ub(20, 20, 20);
		glVertex3f(45,-48,75);
		glVertex3f(75,-48,75);
		glVertex3f(75,-48,70);
		glVertex3f(45,-48,70);
		glEnd();

		glBegin(GL_POLYGON); // pager kiri
		glColor3ub(20, 20, 20);
		glVertex3f(45,-48,70);
		glVertex3f(45,-48,75);
		glVertex3f(45,-40,75);
		glVertex3f(45,-40,70);
		glEnd();

		glBegin(GL_POLYGON); // pager kanan
		glColor3ub(20, 20, 20);
		glVertex3f(75,-48,70);
		glVertex3f(75,-48,75);
		glVertex3f(75,-40,75);
		glVertex3f(75,-40,70);
		glEnd();

		glBegin(GL_POLYGON); // pager belakang
		glColor3ub(20, 20, 20);
		glVertex3f(45,-48,70);
		glVertex3f(75,-48,70);
		glVertex3f(75,-40,70);
		glVertex3f(45,-40,70);
		glEnd();

		glBegin(GL_POLYGON); // pager belakang
		glColor3ub(20, 20, 20);
		glVertex3f(45,-48,75);
		glVertex3f(75,-48,75);
		glVertex3f(75,-40,75);
		glVertex3f(45,-40,75);
		glEnd();

		//------------------------------------------------------------
	/*	//PAGER KIRI
		glBegin(GL_POLYGON); // pager bawah
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-48,70);
		glVertex3f(-70,-48,70);
		glVertex3f(-70,-48,-105);
		glVertex3f(-75,-48,-105);
		glEnd();

		glBegin(GL_POLYGON); // pager atas
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-40,70);
		glVertex3f(-70,-40,70);
		glVertex3f(-70,-40,-105);
		glVertex3f(-75,-40,-105);
		glEnd();

		glBegin(GL_POLYGON); // pager kiri
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-48,-105);
		glVertex3f(-75,-48,70);
		glVertex3f(-75,-40,70);
		glVertex3f(-75,-40,-105);
		glEnd();

		glBegin(GL_POLYGON); // pager kiri
		glColor3ub(20, 20, 20);
		glVertex3f(-70,-48,-105);
		glVertex3f(-70,-48,70);
		glVertex3f(-70,-40,70);
		glVertex3f(-70,-40,-105);
		glEnd();
*/
		//------------------------------------------------------------
		//PAGER KANAN
		glBegin(GL_POLYGON); // pager bawah
		glColor3ub(20, 20, 20);
		glVertex3f(75,-48,70);
		glVertex3f(70,-48,70);
		glVertex3f(70,-48,-105);
		glVertex3f(75,-48,-105);
		glEnd();

		glBegin(GL_POLYGON); // pager atas
		glColor3ub(20, 20, 20);
		glVertex3f(75,-40,70);
		glVertex3f(70,-40,70);
		glVertex3f(70,-40,-105);
		glVertex3f(75,-40,-105);
		glEnd();

		glBegin(GL_POLYGON); // pager kiri
		glColor3ub(20, 20, 20);
		glVertex3f(75,-48,-105);
		glVertex3f(75,-48,70);
		glVertex3f(75,-40,70);
		glVertex3f(75,-40,-105);
		glEnd();

		glBegin(GL_POLYGON); // pager kiri
		glColor3ub(20, 20, 20);
		glVertex3f(70,-48,-105);
		glVertex3f(70,-48,70);
		glVertex3f(70,-40,70);
		glVertex3f(70,-40,-105);
		glEnd();

		//---------------------------------------------------
		//PAGER
		glBegin(GL_POLYGON); // pager atas
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-40,-105);
		glVertex3f(75,-40,-105);
		glVertex3f(75,-40,-100);
		glVertex3f(-75,-40,-100);
		glEnd();

		glBegin(GL_POLYGON); // pager bawah
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-48,-105);
		glVertex3f(75,-48,-105);
		glVertex3f(75,-48,-100);
		glVertex3f(-75,-48,-100);
		glEnd();

		glBegin(GL_POLYGON); // pager kiri
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-48,-100);
		glVertex3f(-75,-48,-105);
		glVertex3f(-75,-40,-105);
		glVertex3f(-75,-40,-100);
		glEnd();

		glBegin(GL_POLYGON); // pager kanan
		glColor3ub(20, 20, 20);
		glVertex3f(75,-48,-100);
		glVertex3f(75,-48,-105);
		glVertex3f(75,-40,-105);
		glVertex3f(75,-40,-100);
		glEnd();

		glBegin(GL_POLYGON); // pager depan
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-48,-105);
		glVertex3f(75,-48,-105);
		glVertex3f(75,-40,-105);
		glVertex3f(-75,-40,-105);
		glEnd();

		glBegin(GL_POLYGON); // pager BELAKANG
		glColor3ub(20, 20, 20);
		glVertex3f(-75,-48,-100);
		glVertex3f(75,-48,-100);
		glVertex3f(75,-40,-100);
		glVertex3f(-75,-40,-100);
		glEnd();

	glPopMatrix();
	glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{
		//maju
		case 'w':
		case 'W':
			glTranslatef(0,0,3);
			break;
		//mundur
		case 's':
		case 'S':
			glTranslatef(0,0,-3);
			break;
		//kanan
		case 'd':
		case 'D':
			glTranslatef(3,0,0);
			break;
		//kiri
		case 'a':
		case 'A':
			glTranslatef(-3,0,0);
			break;
		//naik
		case '7':
			glTranslatef(0,3,0);
			break;
		//turun
		case '9':
			glTranslatef(0,-3,0);
			break;
		//memutar maju naik
		case '2':
			glRotatef(2,1,0,0);
			break;
		//memutar maju turun
		case '8':
			glRotatef(-2,1,0,0);
			break;
		//memutar maju kanan
		case '6':
			glRotatef(2,0,1,0);
			break;
		//memutar maju kiri
		case '4':
			glRotatef(-2,0,1,0);
			break;
		//memutar kiri ditempat
		case '1':
			glRotatef(2,0,0,1);
			break;
		//	memutar kanan ditempat
		case '3':
			glRotatef(-2,0,0,1);
			break;
		//lihat bagian dalam
		case '5':
			if(is_depth)
			{
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			}
			else
			{
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}
	}
	tampil();
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3;
		yrot += 0.4;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if(mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi ==0) tinggi =1;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(50,lebar/tinggi, 5, 1000);
glTranslatef(0,0,-260);
glMatrixMode(GL_MODELVIEW);
}
