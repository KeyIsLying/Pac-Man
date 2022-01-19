#ifndef GHOST_H
#define GHOST_H

#include "BaseCharacter.h"

/*
Couleur et nom des fantomes:
	- Shadow (Ombre) - Blinky : le fantôme rouge.
	- Speedy (Rapide) - Pinky : le fantôme rose.
	- Bashful (Timide) - Inky (ou encore Inkey) : le fantôme bleu.
	- Pokey (Limité) - Clyde : le fantôme orange.
*/

class Ghost : public BaseCharacter
{
public:
	// Constructeur
	Ghost() : BaseCharacter() {};

	void Draw(); //méthode hérité de BaseCharacter
	void DrawC(int color);
	void DeplacementAuto();
	void TestCollision();
};
#endif