#include "Hero.h"

using namespace std;
extern char** Matrix;

void Hero::Draw()
{
	glPushMatrix();
	glTranslated(PosC + 0.5, PosL + 0.5, 0.0);
	glColor3d(1, 1, 0);	//Couleur jaune
	glutSolidSphere(0.5, 12, 12); // Sphère de la tête

	glColor3d(0, 0, 0); //Couleur noire
	glTranslated(0.1, -0.25, 0.0);
	glutSolidSphere(0.1, 12, 12); // Oeil

	glBegin(GL_TRIANGLES);	//Création de la bouche
	glColor3f(0, 0, 0);
	glVertex3f(0, 0.2, 0);
	glVertex3f(0.4, 0, 0);
	glVertex3f(0.4, 0.4, 0);
	glEnd();

	glPopMatrix();
}