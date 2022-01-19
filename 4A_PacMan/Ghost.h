#ifndef GHOST_H
#define GHOST_H

#include "BaseCharacter.h"

/*
Couleur et nom des fantomes:
	- Shadow (Ombre) - Blinky : le fant�me rouge.
	- Speedy (Rapide) - Pinky : le fant�me rose.
	- Bashful (Timide) - Inky (ou encore Inkey) : le fant�me bleu.
	- Pokey (Limit�) - Clyde : le fant�me orange.
*/

class Ghost : public BaseCharacter
{
public:
	// Constructeur
	Ghost() : BaseCharacter() {};

	void Draw(); //m�thode h�rit� de BaseCharacter
	void DrawC(int color);
	void DeplacementAuto();
	void TestCollision();
};
#endif