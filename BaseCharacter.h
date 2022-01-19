#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include <iostream>
#include "glut.h"

using namespace std;

class BaseCharacter
{
protected:
	// Position Colonne et Ligne sur la matrice
	int PosC, PosL;
public:
	// Accesseurs
	int GetPosC() const { return PosC; }
	int GetPosL() const { return PosL; }

	// Mutateurs
	void SetPosC(int C) { PosC = C; }
	void SetPosL(int L) { PosL = L; }

	// Constructeur
	BaseCharacter() { PosC = PosL = 0; }

	// Fonction de déplacement
	void GoUp();
	void GoDown();
	void GoLeft();
	void GoRight();

	virtual void Draw() = 0;
};
#endif