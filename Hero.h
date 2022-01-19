#ifndef HERO_H
#define HERO_H
#include "BaseCharacter.h"

class Hero : public BaseCharacter
{
public:
	// Appel du constructeur de la classe mère PersonnageBase
	Hero() : BaseCharacter() {}

	void Draw();
};
#endif