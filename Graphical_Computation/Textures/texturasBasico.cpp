
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL\glut.h>


//==================================================================== Definir cores
#define AZUL     0.0, 0.0, 1.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0, 1.0
#define AMARELO  1.0, 1.0, 0.0, 1.0
#define VERDE    0.0, 1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY1    0.2, 0.2, 0.2, 1.0
#define GRAY2    0.9, 0.9, 0.9, 1.0
#define PRETO    0.0, 0.0, 0.0, 1.0

#include "RgbImage.h"
#define   PI 3.14159


//================================================================================
//===========================================================Variaveis e constantes
GLint    msec = 100;					//.. definicao do timer (actualizacao)

//------------------------------------------------------------ Sistema Coordenadas Chao
GLfloat  xC = 15.0, zC = 15.0;
GLint    wScreen = 800, hScreen = 500;

//------------------------------------------------------------ Observador
GLfloat  rVisao = 3.0, aVisao = 0.5 * PI, incVisao = 0.1;
GLfloat  angPersp = 109.0;
GLfloat  obsPini[] = { 1, 1.0, 0.5 * xC };
GLfloat  obsPfin[] = { obsPini[0] - rVisao * cos(aVisao), obsPini[1], obsPini[2] - rVisao * sin(aVisao) };



//=================================================================== TEXTURAS

//------------------------------------------------------------ Skybox
GLUquadricObj* bola = gluNewQuadric();

//------------------------------------------------------------ Texturas (5 texturas)
GLuint   texture[5];
RgbImage imag;


//--------------------------------------------- Bola e Escada com Vertex Array
int   facesESC = 3;		   // 3 faces 

static GLuint    poligono[] = { 0, 0, 0, 0 };
static GLfloat vertices[] = {
-0.50, 0.00, -0.96, 
 0.50, 0.00, -0.96, 
 0.50, 0.00, -0.00, 
-0.50, 0.00, -0.00, 
-0.50, 0.00, -0.96, 
 0.50, 0.00, -0.96, 
 0.50, 0.16, -0.96, 
-0.50, 0.16, -0.96, 
-0.50, 0.16, -1.28, 
 0.50, 0.16, -1.28, 
 0.50, 0.16, -0.96, 
-0.50, 0.16, -0.96 };
static GLfloat normais[] = {
0.0, 0.0, 1.0, 
0.0, 0.0, 1.0,
0.0, 0.0, 1.0,
0.0, 0.0, 1.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 0.0, 1.0,
0.0, 0.0, 1.0,
0.0, 0.0, 1.0,
0.0, 0.0, 1.0 };
static GLfloat cores[] = {
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
1.0, 0.0, 0.0,
1.0, 0.0, 0.0,
1.0, 0.0, 0.0,
1.0, 0.0, 0.0,
1.0, 0.0, 1.0,
1.0, 0.0, 1.0,
1.0, 0.0, 1.0,
1.0, 0.0, 1.0 };
static GLfloat texturas[] = {
0, 0, 
1, 0, 
1, 1, 
0, 1, 
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1 };



//================================================================================
//=========================================================================== INIT
//================================================================================
void initTexturas()
{
	//----------------------------------------- Chao
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	imag.LoadBmpFile("iron.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//----------------------------------------- Bola
	glGenTextures(1, &texture[1]);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	imag.LoadBmpFile("bola.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//-----------------------------------------  Face lado escada
	glGenTextures(1, &texture[2]);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	imag.LoadBmpFile("madeira.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//-----------------------------------------  Face cima escada
	glGenTextures(1, &texture[3]);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	imag.LoadBmpFile("colorida.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//----------------------------------------- Chaleria
	glGenTextures(1, &texture[4]);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	imag.LoadBmpFile("tea.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

}


//---------------------------------------- Inicializacoes
void init(void) {
	glClearColor(WHITE);
	glShadeModel(GL_SMOOTH);

	initTexturas();
	glEnable(GL_DEPTH_TEST);

	//------------------------------- Definição da ESCADA
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glEnableClientState(GL_VERTEX_ARRAY);
	glNormalPointer(GL_FLOAT, 0, normais);
	glEnableClientState(GL_NORMAL_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, cores);
	glEnableClientState(GL_COLOR_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, texturas);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}



GLvoid resize(GLsizei width, GLsizei height)
{
	wScreen = width;
	hScreen = height;
	glViewport(0, 0, wScreen, hScreen);
	glutPostRedisplay();
}

//-------------------------------------------------------- posicao observador
void drawQuadrado() {
	float tam=0.5;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Chao y=0
	glPushMatrix();
	glBegin(GL_QUADS);
		glVertex3f(-tam, 0.1, -tam);
		glVertex3f(-tam, 0.1, tam);
	    glVertex3f( tam, 0.1, tam);
		glVertex3f( tam, 0.1, -tam);
	glEnd();
	glPopMatrix();	
}

void drawOrientacao()
{
	//----------------------- OBSERVADOR: onde esta; para onde olha
	glPushMatrix();
		glColor4f(VERDE);
		glTranslatef(obsPini[0], obsPini[1], obsPini[2]);
		drawQuadrado();
	glPopMatrix();
	glPushMatrix();
		glColor4f(AMARELO);
		glTranslatef(obsPfin[0], obsPfin[1], obsPfin[2]);
		drawQuadrado();
	glPopMatrix();

	//----------------------- EIXOS
	glColor4f(VERMELHO);
	glBegin(GL_LINES);
		glVertex3i(0, 0, -xC);
		glVertex3i(0, 0, xC);
	glEnd();
	glColor4f(VERDE);
	glBegin(GL_LINES);
		glVertex3i(0, -xC, 0);
		glVertex3i(0, xC, 0);
	glEnd();
	glColor4f(AZUL);
	glBegin(GL_LINES);
		glVertex3i(-xC, 0, 0);
		glVertex3i(xC, 0, 0);
	glEnd();
}

//================================================================================
//================== OBJECTOS
//================================================================================

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Chao : poligono regular
void drawChao() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPushMatrix();
		glTranslatef(0, -5, 0);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);  	 glVertex3i(-xC, 0, -xC);
			glTexCoord2f(1.0f, 0.0f); 	 glVertex3i(-xC, 0, xC);
			glTexCoord2f(1.0f, 1.0f);    glVertex3i(xC, 0, xC);
			glTexCoord2f(0.0f, 1.0f);    glVertex3i(xC, 0, -xC);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Bola : Quadrica
void drawBola()
{
	//------------------------- Bola
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glPushMatrix();
		glTranslatef(2, 4, 2);
		gluQuadricDrawStyle(bola, GLU_FILL);
		gluQuadricNormals(bola, GLU_SMOOTH);
		gluQuadricTexture(bola, GL_TRUE);
		gluSphere(bola, 30.0, 100, 100);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Vertex Array
void drawEscada()
{
	glEnable(GL_TEXTURE_2D);
	//------------------------- Posicionamento da ESCADA
	glPushMatrix();
	glTranslatef(5, -4.0, 0.0);
	glScalef(6, 8, 7);

	for (int p = 0; p < facesESC; p++)
	{   //..................... texturas diferentes cima/lado escada
		if (p % 2 ==0 )
			glBindTexture(GL_TEXTURE_2D, texture[2]);
		else
			glBindTexture(GL_TEXTURE_2D, texture[3]);
	  
		poligono[0] = p * 4 + 0;
		poligono[1] = p * 4 + 1;
		poligono[2] = p * 4 + 2;
		poligono[3] = p * 4 + 3;
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, poligono);
	}
	glPopMatrix();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GLUT ??? chaleira
void drawChaleira()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	//------------------------- Posicionamento da ESCADA
	glPushMatrix();
		glTranslatef(-5, -4.0, -2.0);
		glScalef(3, 3, 3);
		glutSolidTeapot(1.0);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}


//___________________________________________________   jh
void display(void) {



	//================================================================= Viewport1
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, hScreen / 4, wScreen / 6, hScreen / 5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-xC, xC, -xC, xC, -zC, zC);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 5, 0, 0, 0, 0, 0, 0, -1);
	//--------------------- desenha objectos
	drawOrientacao();
	drawChao();
	drawBola();
	drawEscada();
	drawChaleira();

	//================================================================= Viewport2
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(wScreen / 5, 0, 0.75 * wScreen, hScreen);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angPersp, (float)wScreen / hScreen, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsPini[0], obsPini[1], obsPini[2], obsPfin[0], obsPfin[1], obsPfin[2], 0, 1, 0);
	//--------------------- desenha objectos
	drawChao();
	drawBola();
	drawEscada();
	drawChaleira();

	glutSwapBuffers();
}


//======================================================= EVENTOS
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	//--------------------------- Escape
	case 27:
		exit(0);
		break;

	}
}

void teclasNotAscii(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) {
		obsPini[0] = obsPini[0] + incVisao * cos(aVisao);
		obsPini[2] = obsPini[2] - incVisao * sin(aVisao);
	}
	if (key == GLUT_KEY_DOWN) {
		obsPini[0] = obsPini[0] - incVisao * cos(aVisao);
		obsPini[2] = obsPini[2] + incVisao * sin(aVisao);
	}
	if (key == GLUT_KEY_LEFT)
		aVisao = (aVisao + 0.1);
	if (key == GLUT_KEY_RIGHT)
		aVisao = (aVisao - 0.1);

	obsPfin[0] = obsPini[0] + rVisao * cos(aVisao);
	obsPfin[2] = obsPini[2] - rVisao * sin(aVisao);
	glutPostRedisplay();
}


void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(msec, Timer, 1);
}


//======================================================= MAIN
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(wScreen, hScreen);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("{jh,ct,ep}@dei.uc.pt-CG      ");

	init();
	glutSpecialFunc(teclasNotAscii);
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(msec, Timer, 1);

	glutMainLoop();

	return 0;
}

