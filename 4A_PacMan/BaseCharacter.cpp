#include "BaseCharacter.h"

extern int NbC;
extern int NbL;
extern char** Matrix;


void BaseCharacter::GoUp() {
	if (PosL > 0 && Matrix[PosC][PosL - 1] != '0') {
		PosL--;
	}
}
void BaseCharacter::GoDown() {
	if (PosL < NbL - 1 && Matrix[PosC][PosL + 1] != '0')
		PosL++;
}
void BaseCharacter::GoLeft() {
	if (PosC > 0 && Matrix[PosC - 1][PosL] != '0') {
		PosC--;
	}
}
void BaseCharacter::GoRight() {
	if (PosC < NbC - 1 && Matrix[PosC + 1][PosL] != '0') {
		PosC++;
	}
}