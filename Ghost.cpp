#include "Ghost.h"
#include "Hero.h"

extern Hero pacman;
extern void LabyDraw();


void Ghost::Draw(){}

void Ghost::DrawC(int color)
{
	glPushMatrix();
	int couleur = color;
	
	switch (couleur) {
		case 1://rouge
			glColor3d(0.79, 0.14, 0.05); //valeur RGB/255 car prend des valeurs de 0 à 1
			break;
		case 2://rose
			glColor3d(.85, .6, .71);
			break;
		case 3://bleu
			glColor3d(.14, .61, .77);
			break;
		case 4://orange
			glColor3d(.86, .55, .02);
			break;
	}
	//glColor3d(0.79, 0.14, 0.05);//rouge
	glTranslated(PosC + 0.5, PosL + 0.5, 0.0);	// Définition du centre de notre zone de dessin

	// Sphère de la tête
	glutSolidSphere(0.5, 12, 12);

	// Carre du corps
	glBegin(GL_QUADS);
	glVertex3f(-0.5, 0.0, 0.0);
	glVertex3f(-0.5, 0.4, 0.0);
	glVertex3f(0.5, 0.4, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glEnd();

	// Bas du corps
		// Triangle 1
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, 0.4, 0);
	glVertex3f(-0.25, 0.4, 0);
	glVertex3f(-0.5, 0.5, 0);
	glEnd();
	// Triangle 2
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.25, 0.4);
	glVertex2f(0, 0.4);
	glVertex2f(0, 0.5);
	glEnd();
	// Triangle 3
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0.4);
	glVertex2f(0.25, 0.4);
	glVertex2f(0, 0.5);
	glEnd();
	// Triangle 4
	glBegin(GL_TRIANGLES);
	glVertex2f(0.25, 0.4);
	glVertex2f(0.5, 0.4);
	glVertex2f(0.5, 0.5);
	glEnd();

	// Yeux
	glColor3d(1, 1, 1);				//Couleur blanche
		// Oeil gauche					// il y certaines bizarderies avec la creation de cercles
	glTranslated(-0.2, -0.2, 0.0);
	glutSolidSphere(0.15, 12, 12);

	glColor3d(0.25, 0.25, 1);
	glTranslated(-0.05, 0, 0.0);
	glutSolidSphere(0.08, 12, 12);
	// Oeil droit
	glColor3d(1, 1, 1);				//Couleur blanche
	glTranslated(0.4, 0.0, 0.0);
	glutSolidSphere(0.15, 12, 12);
	glColor3d(0.25, 0.25, 1);
	glTranslated(-0.05, 0, 0.0);
	glutSolidSphere(0.08, 12, 12);

	glPopMatrix();
}

void Ghost::DeplacementAuto()
{
	int hasard = rand() % 4;

	switch (hasard)
	{
	case 0:
		GoUp();
		break;
	case 1:
		GoDown();
		break;
	case 2:
		GoLeft();
		break;
	case 3:
		GoRight();
	default:
		break;
	}
	glutPostRedisplay();
}

void Ghost::TestCollision()

{
	if (PosC == pacman.GetPosC() && PosL == pacman.GetPosL())
	{
		cout << "Vous avez perdu !" << endl;
		LabyDraw();
		// LibererMemoire();
		system("pause");
		exit(0);
	}
}
