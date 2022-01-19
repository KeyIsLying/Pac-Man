#include "Point.h"
#include "Hero.h"

extern Hero pacman;

void Point::Draw()
{

	glPushMatrix();
	glTranslated(PosiC + 0.5, PosiL + 0.5, 0.0);	// Définition du centre de notre zone de dessin
	glColor3d(1, 1, 0);
	glutSolidSphere(0.15, 12, 12);
	glColor3d(1, 1, 1);
	glutSolidSphere(0.07, 12, 12);
	glPopMatrix();
}