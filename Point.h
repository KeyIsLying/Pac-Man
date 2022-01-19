#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "Hero.h"

using namespace std;

class Point
{
private:
	Point* Next;
	int PosiC, PosiL;
public:
	// Accesseur
	Point* GetNextP() const { return Next; }
	int GetPosiC() const { return PosiC; }
	int GetPosiL() const { return PosiL; }

	// Mutateur
	void SetSuivant(Point* ptr) { Next = ptr; }
	void SetPosiC(int C) { PosiC = C; }
	void SetPosiL(int L) { PosiL = L; }

	// Constructeur
	Point() {
		PosiC = PosiL = '0';
		Next = NULL;
	}

	void Draw();
	//int Mange();
};
#endif