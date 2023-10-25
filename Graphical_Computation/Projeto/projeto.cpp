#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "RgbImage.h"
#define PI 3.14159

GLfloat tam = 0.5;
static GLfloat vertices[] = {
		 0,  -tam,  0,	// 0
		 0,   tam,  0,	// 1 
		 0,   tam, -tam,	// 2 
		 0,  -tam, -tam,	// 3

		 0,  -tam,  tam,	// 4
		 0,   tam,  tam,	// 5 
		 0,   tam, 0,	// 6 
		 0,  -tam, 0,	// 7

		 -0.05,  -tam,  0,	// 8
		 -0.05,   tam,  0,	// 9 
		 -0.05,   tam, -tam,	// 10 
		 -0.05,  -tam, -tam,	// 11

		 -0.05,  -tam,  tam,	// 12
		 -0.05,   tam,  tam,	// 13
		 -0.05,   tam, 0,	// 14 
		 -0.05,  -tam, 0,	// 15

		 //#############################################################//
		 // macaneta
		 0.01,	-0.025,	-0.075,	//16
		 0.01,  0.025, -0.075,	//17
		 0.01,  0.025, -0.125,	//18
		 0.01,	-0.025, -0.125,	//19

		 0.075,	-0.025,	-0.075,	//20
		 0.075,  0.025, -0.075,	//21
		 0.075,  0.025, -0.125,	//22
		 0.075,	-0.025, -0.125,	//23

		 0.01,	-0.025,	0.075,	//24
		 0.01,	 0.025,	0.075,	//25
		 0.01,   0.025,	0.125,	//26
		 0.01,	-0.025, 0.125,	//27

		 0.075,	-0.025,	0.075,	//28
		 0.075,  0.025, 0.075,	//29
		 0.075,  0.025, 0.125,	//30
		 0.075,	-0.025, 0.125,	//31

		 0.04,	-0.01, -0.075,	//32
		 0.04,   0.01, -0.075,	//33
		 0.04,	 0.01, -0.2,	//34
		 0.04,	-0.01, -0.2,	//35

		 0.065,	-0.01, -0.075,	//36
		 0.065,  0.01, -0.075,	//37
		 0.065,  0.01, -0.2,	//38
		 0.065,	-0.01, -0.2,	//39

		 0.04,	-0.01, 0.2,		//40
		 0.04,   0.01, 0.2,		//41
		 0.04,	 0.01, 0.075,	//42
		 0.04,	-0.01, 0.075,	//43

		 0.065,	-0.01, 0.2,		//44
		 0.065,  0.01, 0.2,		//45
		 0.065,  0.01, 0.075,	//46
		 0.065,	-0.01, 0.075,	//47

		 0.01,	(tam / 2) - 0.02,  tam / 2,	// 48
		 0.01,	(tam / 2) + 0.02,  tam / 2,	// 49
		 0.01,	(tam / 2) + 0.02, -tam / 2,	// 50
		 0.01,	(tam / 2) - 0.02, -tam / 2,	// 51

		 0.05,	(tam / 2) - 0.02,  tam / 2,	// 52
		 0.05,	(tam / 2) + 0.02,  tam / 2,	// 53
		 0.05,	(tam / 2) + 0.02, -tam / 2,	// 54
		 0.05,	(tam / 2) - 0.02, -tam / 2,	// 55


		 0.01,	(tam / 2) - 0.03, (-tam / 4) - 0.025,	// 56
		 0.01,	(tam / 2) - 0.03, (-tam / 4) + 0.025,	// 57
		 0.06,	(tam / 2) - 0.03, (-tam / 4) + 0.025,	// 58
		 0.06,	(tam / 2) - 0.03, (-tam / 4) - 0.025,	// 59

		 0.01,	(tam / 2) - 0.03, (tam / 4) - 0.025,	// 60
		 0.01,	(tam / 2) - 0.03, (tam / 4) + 0.025,	// 61
		 0.06,	(tam / 2) - 0.03, (tam / 4) + 0.025,	// 62
		 0.06,	(tam / 2) - 0.03, (tam / 4) - 0.025,	// 63

		 0.06,	(tam / 2) - 0.03, (-tam / 4) - 0.025,	// 64
		 0.06,	(tam / 2) - 0.03, (-tam / 4) + 0.025,	// 65
		 0.06,	(tam / 2) + 0.02, (-tam / 4) + 0.025,	// 66
		 0.06,	(tam / 2) + 0.02, (-tam / 4) - 0.025,	// 67

		 0.06,	(tam / 2) - 0.03, (tam / 4) - 0.025,	// 68
		 0.06,	(tam / 2) - 0.03, (tam / 4) + 0.025,	// 69
		 0.06,	(tam / 2) + 0.02, (tam / 4) + 0.025,	// 70
		 0.06,	(tam / 2) + 0.02, (tam / 4) - 0.025,	// 71

		  3.0,		-2.51,	-3.0,						// 72
		 -3.0,		-2.51,	-3.0,						// 73
		 -3.0,		-2.51,	-9.0,						// 74
		  3.0,		-2.51,	-9.0,						// 75

		  3.0,		-2.51,	 3.0,						// 72
		 -3.0,		-2.51,	 3.0,						// 73
		 -3.0,		-2.51,	-3.0,						// 74
		  3.0,		-2.51,	-3.0,						// 75

		  3.0,		-2.51,	 9.0,						// 76
	     -3.0,		-2.51,	 9.0,						// 77
		 -3.0,		-2.51,	 3.0,						// 78
		  3.0,		-2.51,	 3.0,						// 79
			
};

static GLfloat texturas[] = {
0,1, 0,0, 1,0, 1,1, //1      
0,1, 0,0, 1,0, 1,1, //2
0,1, 0,0, 1,0, 1,1, //3
0,1, 0,0, 1,0, 1,1, //4
0,1, 0,0, 1,0, 1,1, //5
0,1, 0,0, 1,0, 1,1, //6
0,1, 0,0, 1,0, 1,1, //7
0,1, 0,0, 1,0, 1,1, //8
0,1, 0,0, 1,0, 1,1, //9
0,1, 0,0, 1,0, 1,1, //10
0,1, 0,0, 1,0, 1,1, //11
0,1, 0,0, 1,0, 1,1, //12
0,1, 0,0, 1,0, 1,1, //13
0,1, 0,0, 1,0, 1,1, //14
0,1, 0,0, 1,0, 1,1, //15
0,1, 0,0, 1,0, 1,1, //16
0,1, 0,0, 1,0, 1,1, //17
0,1, 0,0, 1,0, 1,1, //18
0,1, 0,0, 1,0, 1,1, //19
0,1, 0,0, 1,0, 1,1, //20
0,1, 0,0, 1,0, 1,1, //21
};

static GLfloat normais[] = {
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0 };//84 normais correspondentes aos 84 pontos

#pragma region FACES
//=========================================================== FACES DA MESA
GLboolean   frenteVisivel = 1;
static GLuint direita_frente[] = { 0,3,2,1 };
static GLuint direita_baixo[] = { 0,8,11,3 };
static GLuint direita_esq[] = { 0,1,9,8 };
static GLuint direita_cima[] = { 10,9,1,2 };
static GLuint direita_dir[] = { 10,2,3,11 };
static GLuint direita_costas[] = { 10,11,8,9 };

static GLuint esquerda_frente[] = { 4,7,6,5 };
static GLuint esquerda_baixo[] = { 4,12,15,7 };
static GLuint esquerda_esq[] = { 4,5,13,12 };
static GLuint esquerda_cima[] = { 14,13,5,6 };
static GLuint esquerda_dir[] = { 14,6,7,15 };
static GLuint esquerda_costas[] = { 14,15,12,13 };

static GLuint macaneta_dir_frente[] = { 20,23,22,21 };
static GLuint macaneta_dir_baixo[] = { 20,16,19,23 };
static GLuint macaneta_dir_esq[] = { 20,21,17,16 };
static GLuint macaneta_dir_cima[] = { 18,17,21,22 };
static GLuint macaneta_dir_dir[] = { 18,22,23,19 };
static GLuint macaneta_dir_costas[] = { 18,19,16,17 };

static GLuint macaneta_dir_2_frente[] = { 36,39,38,37 };
static GLuint macaneta_dir_2_baixo[] = { 36,32,35,39 };
static GLuint macaneta_dir_2_esq[] = { 36,37,33,32 };
static GLuint macaneta_dir_2_cima[] = { 34,33,37,38 };
static GLuint macaneta_dir_2_dir[] = { 34,38,39,35 };
static GLuint macaneta_dir_2_costas[] = { 34,35,32,33 };

static GLuint macaneta_esq_frente[] = { 28,31,30,29 };
static GLuint macaneta_esq_baixo[] = { 28,24,27,31 };
static GLuint macaneta_esq_esq[] = { 28,29,25,24 };
static GLuint macaneta_esq_cima[] = { 26,25,29,30 };
static GLuint macaneta_esq_dir[] = { 26,30,31,27 };
static GLuint macaneta_esq_costas[] = { 26,27,24,25 };

static GLuint macaneta_esq_2_frente[] = { 44,47,46,45 };
static GLuint macaneta_esq_2_baixo[] = { 44,40,43,47 };
static GLuint macaneta_esq_2_esq[] = { 44,45,41,40 };
static GLuint macaneta_esq_2_cima[] = { 42,41,45,46 };
static GLuint macaneta_esq_2_dir[] = { 42,46,47,43 };
static GLuint macaneta_esq_2_costas[] = { 42,43,40,41 };

static GLuint barra_frente[] = { 52, 55, 54, 53 };
static GLuint barra_baixo[] = { 52, 48, 51, 55 };
static GLuint barra_esq[] = { 52, 53, 49, 48 };
static GLuint barra_cima[] = { 50, 49, 53, 54 };
static GLuint barra_dir[] = { 50, 54, 55, 51 };
static GLuint barra_costas[] = { 50, 51, 48, 49 };


static GLuint clamp_1_1[] = { 56, 57, 58, 59 };
static GLuint clamp_1_2[] = { 64, 65, 66, 67 };
static GLuint clamp_2_1[] = { 60, 61, 62, 63 };
static GLuint clamp_2_2[] = { 68, 69, 70, 71 };

static GLuint chao_1[] = { 72, 73, 74, 75 };
static GLuint chao_2[] = { 76, 77, 78, 79 };
static GLuint chao_3[] = { 80, 81, 82, 83 };
#pragma endregion
#pragma region "VARIAVEIS"
//------------------------------------------------------------ Objectos (sistema coordenadas)
GLint		wScreen = 800, hScreen = 600;			//.. janela (pixeis)
GLfloat		xC = 10.0, yC = 10.0, zC = 30.0;		//.. Mundo  (unidades mundo)

//------------------------------------------------------------ Visualizacao/Observador 
GLfloat  rVisao = 10, aVisao = 0.5 * PI, incVisao = 0.05;
GLfloat  obsP[] = { rVisao * sin(aVisao), 9.0, rVisao * cos(aVisao) };
GLfloat  angZoom = 90, incZoom = 9;
GLfloat  intLuz=0.2;
GLboolean iluminacaoMax=false, luzBranco = true, espBranco = true;
GLfloat  lock_y_offset = 0, y_offset_mac_esq = 0, z_offset_mac_esq = 0, y_offset_mac_dir = 0, z_offset_mac_dir = 0, angulo_mac_dir = 0, angulo_mac_esq = 0, angulo_dir = 0.0, angulo_esq = 360.0, x_offset_dir = 0, x_offset_esq = 0, posX_dir = 0, posX_esq = 0, posZ_dir = 0, posZ_esq = 0;
GLboolean mesh = true, lock_preso = true, lock = true, espera = true, hold = true, fechar = false, abrir = false, macanetas_default = true, macanetas_baixo = false, modeT = true, modeR = false;
GLfloat alpha = 1.0;
GLfloat   luzR = 1, luzG = 1, luzB = 1;

GLfloat luzGlobalCorAmb[4] = { 0.2, 0.2, 0.2, 1.0 };
//#######################	  luz 0		##########################
GLfloat localPos[4] = { 2, tam/2, 0, 1.0 };  //pontual
GLfloat localCorAmb[4] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat localCorDif[4] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat localCorEsp[4] = { 0.5, 0.5, 0.5, 1.0 };
//#######################	  luz 1		##########################
GLfloat localPos_1[4] = { 0, -1, 0, 0.0 };      //direcional
GLfloat localCorAmb_1[4] = { luzR * intLuz, luzG * intLuz, luzB * intLuz, 1.0 };
GLfloat localCorDif_1[4] = { luzR * intLuz, luzG * intLuz, luzB * intLuz, 1.0 };
GLfloat localCorEsp_1[4] = { luzR * intLuz, luzG * intLuz, luzB * intLuz, 1.0 };

GLfloat shinyBoy[1] = { 50 };

GLfloat   espR = 1, espG = 1, espB = 1, espI = 1;
GLfloat esp[4] = { espR, espG, espB, espI };

GLuint   texture[5];
RgbImage imag;
#pragma endregion


void updateChao() {
	esp[0] = espR;
	esp[1] = espG;
	esp[2] = espB;
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, esp);
}

void updateLuz() {
	localCorAmb_1[0] = luzR * intLuz;
	localCorAmb_1[1] = luzG * intLuz;
	localCorAmb_1[2] = luzB * intLuz;
	localCorDif_1[0] = luzR * intLuz;
	localCorDif_1[1] = luzG * intLuz;
	localCorDif_1[2] = luzB * intLuz;
	localCorEsp_1[0] = luzR * intLuz;
	localCorEsp_1[1] = luzG * intLuz;
	localCorEsp_1[2] = luzB * intLuz;;
	glLightfv(GL_LIGHT1, GL_POSITION, localPos_1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, localCorAmb_1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, localCorDif_1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, localCorEsp_1);
}

void MeshDraw() {
	int i, j;
	float dim = 128;
	float med_dim = (float)dim / 2;
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glColor4f(0.6, 0.6, 0.6, 1);
	for (i = -dim*2; i < dim*2; i++) {
		for (j = -dim/2; j < dim/2; j++) {
			glTexCoord2f((float)j / dim, (float)i / dim);
			glVertex3f((float)j*3 / med_dim, -2.51, (float)i * 2 / med_dim);
			glTexCoord2f((float)(j + 1) / dim, (float)i / dim);
			glVertex3f((float)(j + 1)*3 / med_dim, -2.51, (float)i * 2 / med_dim);
			glTexCoord2f((float)(j + 1) / dim, (float)(i + 1) / dim);
			glVertex3f((float)(j + 1)*3 / med_dim, -2.51, (float)(i + 1) * 2 / med_dim);
			glTexCoord2f((float)j / dim, (float)(i + 1) / dim);
			glVertex3f((float)j*3 / med_dim, -2.51, (float)(i + 1)* 2 / med_dim);

		}
	}
	glEnd();
	glColor4f(1, 1, 1, 1);
}

void getMaterialMadeiraLight() {
	GLfloat preto[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat castanho[] = { 0.45,0.26,0.15,1.0 };
	GLfloat branco[] = { 1.0, 1.0, 1.0, 1.0 };
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, castanho);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, branco);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shinyBoy);
}

void getMaterialFerroLight() {
	GLfloat preto[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat cinzento[] = { 35.3, 38.4, 40.0, 1.0 };
	GLfloat branco[] = { 1.0, 1.0, 1.0, 1.0 };
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, cinzento);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, branco);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shinyBoy);
}

void MaterialChao() {
	GLfloat preto[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat cinzento[] = { 35.3, 38.4, 40.0, 1.0 };
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, cinzento);
	updateChao();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shinyBoy);
}

void textMap(GLuint lado[]) {
	int a = lado[0];
	int b = lado[1];
	int c = lado[2];
	int d = lado[3];
	texturas[2 * a]		= 0; //x1
	texturas[2 * a + 1] = 0; //y1
	texturas[2 * b]		= 1; //x2
	texturas[2 * b + 1] = 0; //y2
	texturas[2 * c]		= 1; //x3
	texturas[2 * c + 1] = 1; //y3
	texturas[2 * d]		= 0; //x4
	texturas[2 * d + 1] = 1; //y4

	glTexCoordPointer(2, GL_FLOAT, 0, texturas);
}

void textMapInv(GLuint lado[]) {
	int a = lado[2];
	int b = lado[1];
	int c = lado[0];
	int d = lado[3];
	texturas[2 * a]		= 0; //x1
	texturas[2 * a + 1] = 0; //y1
	texturas[2 * b]		= 1; //x2
	texturas[2 * b + 1] = 0; //y2
	texturas[2 * c]		= 1; //x3
	texturas[2 * c + 1] = 1; //y3
	texturas[2 * d]		= 0; //x4
	texturas[2 * d + 1] = 1; //y4

	glTexCoordPointer(2, GL_FLOAT, 0, texturas);
}
//=========================================================//
void normais_frente(GLuint lado[]) {
	int a = lado[0];
	int b = lado[1];
	int c = lado[2];
	int d = lado[3];
	normais[3 * a] = 1; //x1
	normais[3 * a + 1] = 0; //y1
	normais[3 * a + 2] = 0; //z1
	normais[3 * b] = 1; //x2
	normais[3 * b + 1] = 0; //y2
	normais[3 * b + 2] = 0; //z2
	normais[3 * c] = 1; //x3
	normais[3 * c + 1] = 0; //y3
	normais[3 * c + 2] = 0; //z3
	normais[3 * d] = 1; //x4
	normais[3 * d + 1] = 0; //y4
	normais[3 * d + 2] = 0; //z4

	glNormalPointer(GL_FLOAT, 0, normais);
}

void normais_costas(GLuint lado[]) {
	int a = lado[0];
	int b = lado[1];
	int c = lado[2];
	int d = lado[3];
	normais[3 * a] = -1; //x1
	normais[3 * a + 1] = 0; //y1
	normais[3 * a + 2] = 0; //z1
	normais[3 * b] = -1; //x2
	normais[3 * b + 1] = 0; //y2
	normais[3 * b + 2] = 0; //z2
	normais[3 * c] = -1; //x3
	normais[3 * c + 1] = 0; //y3
	normais[3 * c + 2] = 0; //z3
	normais[3 * d] = -1; //x4
	normais[3 * d + 1] = 0; //y4
	normais[3 * d + 2] = 0; //z4

	glNormalPointer(GL_FLOAT, 0, normais);
}

void normais_cima(GLuint lado[]) {
	int a = lado[0];
	int b = lado[1];
	int c = lado[2];
	int d = lado[3];
	normais[3 * a] = 0; //x1
	normais[3 * a + 1] = 1; //y1
	normais[3 * a + 2] = 0; //z1
	normais[3 * b] = 0; //x2
	normais[3 * b + 1] = 1; //y2
	normais[3 * b + 2] = 0; //z2
	normais[3 * c] = 0; //x3
	normais[3 * c + 1] = 1; //y3
	normais[3 * c + 2] = 0; //z3
	normais[3 * d] = 0; //x4
	normais[3 * d + 1] = 1; //y4
	normais[3 * d + 2] = 0; //z4

	glNormalPointer(GL_FLOAT, 0, normais);
}

void normais_baixo(GLuint lado[]) {
	int a = lado[0];
	int b = lado[1];
	int c = lado[2];
	int d = lado[3];
	normais[3 * a] = 0; //x1
	normais[3 * a + 1] = -1; //y1
	normais[3 * a + 2] = 0; //z1
	normais[3 * b] = 0; //x2
	normais[3 * b + 1] = -1; //y2
	normais[3 * b + 2] = 0; //z2
	normais[3 * c] = 0; //x3
	normais[3 * c + 1] = -1; //y3
	normais[3 * c + 2] = 0; //z3
	normais[3 * d] = 0; //x4
	normais[3 * d + 1] = -1; //y4
	normais[3 * d + 2] = 0; //z4

	glNormalPointer(GL_FLOAT, 0, normais);
}

void normais_esq(GLuint lado[]) {
	int a = lado[0];
	int b = lado[1];
	int c = lado[2];
	int d = lado[3];
	normais[3 * a] = 0; //x1
	normais[3 * a + 1] = 0; //y1
	normais[3 * a + 2] = -1; //z1
	normais[3 * b] = 0; //x2
	normais[3 * b + 1] = 0; //y2
	normais[3 * b + 2] = -1; //z2
	normais[3 * c] = 0; //x3
	normais[3 * c + 1] = 0; //y3
	normais[3 * c + 2] = -1; //z3
	normais[3 * d] = 0; //x4
	normais[3 * d + 1] = 0; //y4
	normais[3 * d + 2] = -1; //z4

	glNormalPointer(GL_FLOAT, 0, normais);
}

void normais_dir(GLuint lado[]) {
	int a = lado[0];
	int b = lado[1];
	int c = lado[2];
	int d = lado[3];
	normais[3 * a] = 0; //x1
	normais[3 * a + 1] = 0; //y1
	normais[3 * a + 2] = 1; //z1
	normais[3 * b] = 0; //x2
	normais[3 * b + 1] = 0; //y2
	normais[3 * b + 2] = 1; //z2
	normais[3 * c] = 0; //x3
	normais[3 * c + 1] = 0; //y3
	normais[3 * c + 2] = 1; //z3
	normais[3 * d] = 0; //x4
	normais[3 * d + 1] = 0; //y4
	normais[3 * d + 2] = 1; //z4

	glNormalPointer(GL_FLOAT, 0, normais);
}
//=========================================================//
void Foggyfog() {
	float foggish[4] = { 0.2, 0.2, 0.2, 1.0 };
	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, 0.04);
	glFogfv(GL_FOG_COLOR, foggish);
	glFogf(GL_FOG_START, 0);
	glFogf(GL_FOG_END, 75);
}

void drawPortaDir(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	getMaterialMadeiraLight();
	textMap(direita_frente);
	normais_frente(direita_frente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, direita_frente);

	textMapInv(direita_costas);
	normais_costas(direita_costas);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, direita_costas);

	textMapInv(direita_baixo);
	normais_baixo(direita_baixo);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, direita_baixo);

	textMap(direita_cima);
	normais_cima(direita_cima);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, direita_cima);

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	textMapInv(direita_esq);
	normais_esq(direita_esq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, direita_esq);

	textMap(direita_dir);
	normais_dir(direita_dir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, direita_dir);
	glDisable(GL_TEXTURE_2D);
}

void drawClamp_1() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	getMaterialFerroLight();

	textMap(clamp_1_1);
	normais_baixo(clamp_1_1);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, clamp_1_1);

	textMap(clamp_1_2);
	normais_frente(clamp_1_2);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, clamp_1_2);
	glDisable(GL_TEXTURE_2D);
}

void drawMacDir1() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	getMaterialFerroLight();

	textMap(macaneta_dir_cima);
	normais_cima(macaneta_dir_cima);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_dir_cima);

	textMapInv(macaneta_dir_baixo);
	normais_baixo(macaneta_dir_baixo);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_dir_baixo);

	textMap(macaneta_dir_frente);
	normais_frente(macaneta_dir_frente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_dir_frente);

	textMapInv(macaneta_dir_costas);
	normais_costas(macaneta_dir_costas);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_dir_costas);

	textMap(macaneta_dir_dir);
	normais_dir(macaneta_dir_dir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_dir_dir);

	textMapInv(macaneta_dir_esq);
	normais_esq(macaneta_dir_esq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_dir_esq);
}

void drawMacDir2() {
	textMap(macaneta_dir_2_cima);
	normais_cima(macaneta_dir_2_cima);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_dir_2_cima);

	textMapInv(macaneta_dir_2_baixo);
	normais_baixo(macaneta_dir_2_baixo);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_dir_2_baixo);

	textMap(macaneta_dir_2_frente);
	normais_frente(macaneta_dir_2_frente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_dir_2_frente);

	textMapInv(macaneta_dir_2_costas);
	normais_costas(macaneta_dir_2_costas);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_dir_2_costas);
	//======================================================================//
	textMap(macaneta_dir_2_dir);
	normais_dir(macaneta_dir_2_dir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_dir_2_dir);

	textMapInv(macaneta_dir_2_esq);
	normais_esq(macaneta_dir_2_esq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_dir_2_esq);
	glDisable(GL_TEXTURE_2D);
}

void drawPortaEsq() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	getMaterialMadeiraLight();
	textMap(esquerda_frente);
	normais_frente(esquerda_frente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, esquerda_frente);

	textMapInv(esquerda_costas);
	normais_costas(esquerda_costas);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, esquerda_costas);

	textMapInv(esquerda_baixo);
	normais_baixo(esquerda_baixo);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, esquerda_baixo);

	textMap(esquerda_cima);
	normais_cima(esquerda_cima);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, esquerda_cima);

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	textMapInv(esquerda_esq);
	normais_esq(esquerda_esq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, esquerda_esq);

	textMap(esquerda_dir);
	normais_dir(esquerda_dir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, esquerda_dir);
	glDisable(GL_TEXTURE_2D);
}

void drawClamp_2() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	getMaterialFerroLight();

	textMap(clamp_2_1);
	normais_baixo(clamp_2_1);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, clamp_2_1);

	textMap(clamp_2_2);
	normais_frente(clamp_2_2);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, clamp_2_2);
	glDisable(GL_TEXTURE_2D);
}

void drawMacEsq1(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	getMaterialFerroLight();

	textMap(macaneta_esq_dir);
	normais_esq(macaneta_dir_costas);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_esq_dir);

	textMapInv(macaneta_esq_esq);
	normais_dir(macaneta_esq_esq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_esq_esq);

	textMap(macaneta_esq_cima);
	normais_cima(macaneta_esq_cima);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_esq_cima);

	textMapInv(macaneta_esq_baixo);
	normais_baixo(macaneta_esq_baixo);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_esq_baixo);

	textMap(macaneta_esq_frente);
	normais_frente(macaneta_esq_frente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_esq_frente);

	textMapInv(macaneta_esq_costas);
	normais_costas(macaneta_esq_costas);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_esq_costas);
}

void drawMacEsq2(){
	textMap(macaneta_esq_2_cima);
	normais_cima(macaneta_esq_2_cima);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_esq_2_cima);

	textMapInv(macaneta_esq_2_baixo);
	normais_baixo(macaneta_esq_2_baixo);
	glTexCoordPointer(2, GL_FLOAT, 0, texturas);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_esq_2_baixo);

	textMap(macaneta_esq_2_frente);
	normais_frente(macaneta_esq_2_frente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_esq_2_frente);

	textMapInv(macaneta_esq_2_costas);
	normais_costas(macaneta_esq_2_costas);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_esq_2_costas);

	textMap(macaneta_esq_2_dir);
	normais_dir(macaneta_esq_2_dir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_esq_2_dir);

	textMapInv(macaneta_esq_2_esq);
	normais_esq(macaneta_esq_2_esq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, macaneta_esq_2_esq);
	glDisable(GL_TEXTURE_2D);
}

void drawBarra(){

	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, alpha);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	getMaterialFerroLight();
	glTranslatef(0.0, lock_y_offset, 0.0);

	textMap(barra_dir);
	normais_dir(barra_dir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, barra_dir);

	textMapInv(barra_esq);
	normais_esq(barra_esq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, barra_esq);

	textMap(barra_cima);
	normais_cima(barra_cima);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, barra_cima);

	textMapInv(barra_baixo);
	normais_baixo(barra_baixo);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, barra_baixo);

	textMap(barra_frente);
	normais_frente(barra_frente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, barra_frente);

	textMapInv(barra_costas);
	normais_costas(barra_costas);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, barra_costas);
	glDisable(GL_TEXTURE_2D);
	glColor4f(1, 1, 1, 1);
}

void initLights() {
	//..................................................... Ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCorAmb);

	//......................................................Cores
	glLightfv(GL_LIGHT0, GL_POSITION, localPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, localCorAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, localCorDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, localCorEsp);

	glLightfv(GL_LIGHT1, GL_POSITION, localPos_1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, localCorAmb_1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, localCorDif_1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, localCorEsp_1);
}

void initTexturas(){
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	imag.LoadBmpFile("door_1.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	glGenTextures(1, &texture[1]);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	imag.LoadBmpFile("door_2.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	glGenTextures(1, &texture[2]);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	imag.LoadBmpFile("door_side.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	glGenTextures(1, &texture[3]);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	imag.LoadBmpFile("Iron.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	glGenTextures(1, &texture[4]);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	imag.LoadBmpFile("padraoFloor.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

}

void inicializa(void){
	glClearColor(0.0, 0.0, 0.0, 1.0);			//………………………………………………………………………………Fundo Preto
	glEnable(GL_DEPTH_TEST);					//………………………………………………………………………………Profundidade

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	initLights(); 

	glShadeModel(GL_SMOOTH);					//………………………………………………………………………………Interpolacao de cores	
	initTexturas();
	glVertexPointer(3, GL_FLOAT, 0, vertices);	//………………………………………VertexArrays: vertices + normais + cores
	glEnableClientState(GL_VERTEX_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, texturas);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glNormalPointer(GL_FLOAT, 0, normais);
	glEnableClientState(GL_NORMAL_ARRAY);

	glEnable(GL_NORMALIZE);
}

void drawEixos()
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixo X
	glColor4f(1.0, 0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3i(0, 0, 0);
	glVertex3i(10, 0, 0);
	glEnd();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixo Y
	glColor4f(0.0, 1.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3i(0, 0, 0);
	glVertex3i(0, 10, 0);
	glEnd();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixo Z
	glColor4f(0.0, 0.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3i(0, 0, 0);
	glVertex3i(0, 0, 10);
	glEnd();
}

void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(20, Timer, 1);
}

void drawScene() {
	
	/*printf("hold: %s	|", hold ? "true" : "false");
	printf("fechar: %s	|", fechar ? "true" : "false");
	printf("abrir: %s	|", abrir ? "true" : "false");*/
	printf("mesh: %s\n", mesh ? "true" : "false");
	//######################################	CHAO	 #############################################
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);

	if (mesh) {
		MaterialChao();
		textMap(chao_1);
		normais_cima(chao_1);
		MeshDraw();
	}
	else if (!mesh) {
		//nao mesh
		glColor4f(0.6, 0.6, 0.6, 1);
		textMap(chao_1);
		normais_cima(chao_1);
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, chao_1);

		textMap(chao_2);
		normais_cima(chao_2);
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, chao_2);

		textMap(chao_3);
		normais_cima(chao_3);
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, chao_3);
		glColor4f(1, 1, 1, 1);
	}
	glDisable(GL_TEXTURE_2D);
	//#######################################	PORTA DIREITA	 #######################################
	glPushMatrix();
		glScalef(5, 5, 5);
		if (modeT) {
			if (abrir && !hold) {
				x_offset_dir -= 0.1;
				if (x_offset_dir >= -0.1) { hold = true; }
			}
			else if (fechar && !hold) {
				x_offset_dir += 0.1;
				if (x_offset_dir <= -1.0) { hold = true; }
			}
			glTranslatef(0, 0, x_offset_dir);
			glRotatef(0, 0, 1, 0);
		}
		if (modeR && !lock) {
			if (abrir && !hold) {
				angulo_dir++;
				if (posX_dir < tam)posX_dir += tam / 80;
				if (posZ_dir > -tam)posZ_dir -= tam / 80;
				if (angulo_dir > 80) { hold = true; }
			}
			else if (fechar && !hold) {
				angulo_dir--;
				if (posX_dir > -tam)posX_dir -= tam / 80;
				if (posZ_dir < tam)posZ_dir += tam / 80;
				if (angulo_dir < 0) { hold = true; }
			}
			glTranslatef(posX_dir, 0.0, posZ_dir);
			glRotatef(angulo_dir, 0, 1, 0);
		}
		drawPortaDir();
		drawClamp_1();

		if (macanetas_default && !espera) {
			angulo_mac_dir -= 5;
			y_offset_mac_dir += 0.1 / 20;
			z_offset_mac_dir -= 0.0625 / 12;
			if (angulo_mac_dir < -79) { espera = true; macanetas_baixo = true; macanetas_default = false; }
		}
		else if (macanetas_baixo && !espera) {
			angulo_mac_dir += 5;
			y_offset_mac_dir -= 0.1 / 20;
			z_offset_mac_dir += 0.0625 / 12;
			if (angulo_mac_dir > -1) { espera = true; macanetas_baixo = false; macanetas_default = true; }
		}
		drawMacDir1();
		glPushMatrix();
			glTranslatef(0.0, y_offset_mac_dir, z_offset_mac_dir);
			glRotatef(angulo_mac_dir, 1, 0, 0);
			drawMacDir2();
		glPopMatrix();
	glPopMatrix();

	//#######################################	PORTA ESQUERDA	 #######################################
	glPushMatrix();
		glScalef(5, 5, 5);
		if (modeT) {
			if (abrir && !hold) {
				x_offset_esq += 0.1;
				if (x_offset_esq >= 1.0) { hold = true; }
			}
			else if (fechar && !hold) {
				x_offset_esq -= 0.1;
				if (x_offset_esq <= 0.1) { hold = true; }
			}
			glTranslatef(0, 0, x_offset_esq);
			glRotatef(0, 0, 1, 0);
		}
		if (modeR && !lock) {
			if (abrir && !hold) {
				angulo_esq--;
				if (posX_esq < tam)posX_esq += tam / 90;
				if (posZ_esq < tam)posZ_esq += tam / 90;
				if (angulo_esq < 280) { hold = true; }
			}
			else if (fechar && !hold) {
				angulo_esq++;
				if (posX_esq > -tam)posX_esq -= tam / 90;
				if (posZ_esq > -tam)posZ_esq -= tam / 90;
				if (angulo_esq > 360) { hold = true; }
			}
			glTranslatef(posX_dir, 0.0, posZ_esq);
			glRotatef(angulo_esq, 0, 1, 0);
		}
		drawPortaEsq();
		drawClamp_2();

		if (macanetas_default && !espera) {
			angulo_mac_esq += 5;
			y_offset_mac_esq += 0.1 / 20;
			z_offset_mac_esq += 0.0625 / 12;
			if (angulo_mac_esq > 79) { espera = true; macanetas_baixo = true; macanetas_default = false; }
		}
		else if (macanetas_baixo && !espera) {
			angulo_mac_esq -= 5;
			y_offset_mac_esq -= 0.1 / 20;
			z_offset_mac_esq -= 0.0625 / 12;
			if (angulo_mac_esq < -1) { espera = true; macanetas_baixo = false; macanetas_default = true; }
		}
		drawMacEsq1();
		glPushMatrix();
			glTranslatef(0.0, y_offset_mac_esq, z_offset_mac_esq);
			glRotatef(angulo_mac_esq, 1, 0, 0);
			drawMacEsq2();
		glPopMatrix();
	glPopMatrix();

	//#######################################		BARRA		 #######################################
	glPushMatrix();
		if (lock && !lock_preso) {
			lock_y_offset += 0.025;
			alpha -= 0.08;
			if (lock_y_offset >= ((tam / 2) + 0.02)) { lock = false; lock_preso = true; }
		}
		else if (!lock && !lock_preso && !abrir && hold) {
			lock_y_offset -= 0.025;
			alpha += 0.08;
			if (lock_y_offset <= 0.02) { lock = true; lock_preso = true; }
		}
		glScalef(5, 5, 5);
		drawBarra();
	glPopMatrix();


}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	glViewport(0, 0, wScreen, hScreen);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angZoom, (float)wScreen / hScreen, 0.1, 3 * zC);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsP[0], obsP[1], obsP[2], 0, 0, 0, 0, 1, 0);

	//…………………………………………………………………………………………………………………………………………………………Objectos
	glLightfv(GL_LIGHT0, GL_POSITION, localPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, localCorAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, localCorDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, localCorEsp);
	glLightfv(GL_LIGHT1, GL_POSITION, localPos_1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, localCorAmb_1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, localCorDif_1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, localCorEsp_1);
	Foggyfog();
	drawScene();
	//drawEixos();
	//. . . . . . . . . . . . . . . . . . . . .  Actualizacao
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'f':
	case 'F':
		if (macanetas_default && espera) { espera = false; }
		else if (macanetas_baixo && espera) { espera = false; }
		glutTimerFunc(20, Timer, 1);
		break;

	case 'A':
	case 'a':
		angZoom += 1;
		glutPostRedisplay();
		break;

	case 'S':
	case 's':
		angZoom -= 1;
		glutPostRedisplay();
		break;

	case 'm':
	case 'M':
		if (hold && !fechar && !abrir && modeT) { modeT = false; modeR = true; }
		else if (hold && fechar && !abrir && modeT) { modeT = false; modeR = true; }
		else if (hold && !fechar && !abrir && !modeT) { modeR = false; modeT = true; }
		else if (hold && fechar && !abrir && !modeT) { modeR = false; modeT = true; }
		glutTimerFunc(20, Timer, 1);
		break;

	case 'd':
	case 'D':
		if (mesh)mesh = false;
		else if (!mesh)mesh = true;
		glutTimerFunc(20, Timer, 1);
		break;

	case 'l':
	case 'L':
		if (lock) { lock_preso = false; }
		if (!lock) { lock_preso = false; }
		glutTimerFunc(20, Timer, 1);
		break;

	case 'r':
	case 'R':
		if (hold && !fechar && !abrir) { abrir = true; hold = false; }
		else if (hold && !fechar && abrir) { fechar = true; abrir = false; hold = false; }
		else if (hold && !abrir && fechar) { abrir = true; fechar = false; hold = false; }
		glutTimerFunc(20, Timer, 1);
		break;

	case 'i':
	case 'I':
		if (!iluminacaoMax) {
			intLuz += 0.1;
			if (intLuz >= 1) {
				iluminacaoMax = true;
			}
		}
		else if (iluminacaoMax) {
			intLuz -= 0.1;
			if (intLuz <= 0.1) {
				iluminacaoMax = false;
			}
		}
		updateLuz();
		glutTimerFunc(20, Timer, 1);
		break;

	case 'c':
	case 'C':
		if (!luzBranco) {
			luzB += 0.1;
			if (luzB >= 0.9) {
				luzBranco = true;
			}
		}
		else if (luzBranco) {
			luzB -= 0.1;
			if (luzB < 0.1) {
				luzBranco = false;
			}
		}
		updateLuz();
		glutTimerFunc(20, Timer, 1);
		break;

	case 'e':
	case 'E':
		if (!espBranco) {
			espR += 0.1;
			espG += 0.1;
			espB += 0.1;
			espI += 0.1;
			if (espB >= 0.9) {
				espBranco = true;
			}
		}
		else if (espBranco) {
			espR -= 0.1;
			espG -= 0.1;
			espB -= 0.1;
			espI -= 0.1;
			if (espB < 0.1) {
				espBranco = false;
			}
		}
		updateChao();
		glutTimerFunc(20, Timer, 1);
		break;
		//--------------------------- Escape
	case 27:
		exit(0);
		break;
	}

}

void teclasNotAscii(int key, int x, int y) {
	if (key == GLUT_KEY_UP)   obsP[1] = (obsP[1] + 0.1);      // setas
	if (key == GLUT_KEY_DOWN) obsP[1] = (obsP[1] - 0.1);
	if (key == GLUT_KEY_LEFT)  aVisao = (aVisao - 0.1);
	if (key == GLUT_KEY_RIGHT) aVisao = (aVisao + 0.1);
	if (obsP[1] > yC)   obsP[1] = yC;					// limita altura
	if (obsP[1] < -yC)  obsP[1] = -yC;
	obsP[0] = rVisao * sin(aVisao);						// actualiza posicao (X,Z)
	obsP[2] = rVisao * cos(aVisao);

	glutPostRedisplay();
}


//======================================================= MAIN
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(wScreen, hScreen);
	glutInitWindowPosition(600, 200);
	glutCreateWindow("");

	inicializa();

	glutSpecialFunc(teclasNotAscii);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}