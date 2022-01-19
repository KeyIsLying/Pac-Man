#include <iostream>
#include "glut.h"
#include <fstream>
#include "BaseCharacter.h"
#include "Hero.h"
#include "Ghost.h"
#include "Point.h"


using namespace std;

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int NbC, NbL;	// Taille du niveau
int Tp1C, Tp1L, Tp2C, Tp2L;	// Coordonée case de Teleportation
int score = 0;
char** Matrix;
char level[] = "Stage3.txt";
//char level[] = "Stage9.txt";
const int TIMER_MILLIS = 500; // Temps en milliseconde, un déplacement de fantome toutes les 500 ms

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

Hero pacman;

// Couleur et nom des fantomes:
Ghost blinky;	// - Shadow (Ombre) - Blinky : le fantôme rouge.
Ghost pinky;	// - Speedy (Rapide) - Pinky : le fantôme rose.
Ghost inky;		// - Bashful (Timide) - Inky (ou encore Inkey) : le fantôme bleu.
Ghost clyde;	// - Pokey (Limité) - Clyde : le fantôme orange.

Point* firstPoint = NULL;


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

void OpenLvl(char* level);
void DrawLvl();
void LabyDraw();
void LabyResize(int x, int y);
void LabyKeyboard(int key, int x, int y);
void LabyTimer(int value);
void Teleportation();
void AddPoint(int Column, int Line);

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main()
{
	Matrix = NULL;
	NbC = NbL = 0;
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(750, 750);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutCreateWindow("Pacman");
	glutDisplayFunc(LabyDraw);
	glutReshapeFunc(LabyResize);
	glutSpecialFunc(LabyKeyboard);
	glutDisplayFunc(LabyDraw);
	glutReshapeFunc(LabyResize);
	OpenLvl(level);
	glutTimerFunc(TIMER_MILLIS, LabyTimer, 0);
	glutMainLoop();
}

void LabyDraw()
{
	glClearColor(0, 0, 0, 1.0); // Définit la couleur de fond
	glClear(GL_COLOR_BUFFER_BIT); // Efface l'écran
	glMatrixMode(GL_MODELVIEW); // Définit la matrice / la zone de jeu
	DrawLvl();
	pacman.Draw();				// Affichage du joueur
	blinky.DrawC(1);			// Affichage des 4 fantomes
	pinky.DrawC(2);
	inky.DrawC(3);
	clyde.DrawC(4);

	Point* P = firstPoint;
	while (P != NULL)
	{
		P->Draw();
		P = P->GetNextP();
	}
	glFlush();
}


void LabyResize(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)NbC, (double)NbL-1, 0.0); // -1 car sinon on affiche le point supp qui évite de faire crash le programme
}


void OpenLvl(char* Stage1)
{
	// Instruction d’ouverture du niveau
	ifstream lvlFile; // lvlFile est un objet de type ifstream
	lvlFile.open(Stage1); // Ouverture du fichier en lecture seule 
	if (lvlFile.good() == false) {
		cout << "Erreur lors de l'ouverture du fichier!" << endl;
		system("pause");
		exit(1);
	}
	lvlFile >> NbC;
	lvlFile >> NbL;

	// Allocation du tableau du niveau
	Matrix = new char* [NbC];
	for (int i = 0; i < NbC; i++)
		Matrix[i] = new char[NbL];

	// Initialisation des valeurs du tableau
	for (int i = 0; i < NbC; i++)
		for (int j = 0; j < NbL; j++)
			Matrix[i][j] = '0';
	
	// Lecture du tableau
	for (int j = 0; j < NbL; j++)
		for (int i = 0; i < NbC; i++)
		{
			lvlFile >> Matrix[i][j];
			switch (Matrix[i][j])
			{

				case 'H': 
					// Définir ici la position de départ
					pacman.SetPosC(i);
					pacman.SetPosL(j);
					break;
				case 'B':
					blinky.SetPosC(i);
					blinky.SetPosL(j);
					break;
				case 'P': 
					pinky.SetPosC(i);
					pinky.SetPosL(j);
					break;
				case 'I':
					inky.SetPosC(i);
					inky.SetPosL(j);
					break;
				case 'C':
					clyde.SetPosC(i);
					clyde.SetPosL(j);
					break;

				case 'x':
					Tp1C = i;
					Tp1L = j;
					break;
				case 'y':
					Tp2C = i;
					Tp2L = j;
					break;

				case 'p':
					AddPoint(i, j);
					break;
			}
		}
		
	lvlFile.close();
}


void DrawLvl(){
	for (int i = 0; i < NbC; i++) {
		for (int j = 0; j < NbL; j++) {
			if (Matrix[i][j] == '0') {
				glColor3d(0, 0, 1);
				glBegin(GL_LINES);
				if (Matrix[i][j - 1] != '0' && j != 0) {	// Test vers le haut
					glVertex2f(i, j);
					glVertex2f(i + 1, j);
				}
				if (Matrix[i][j + 1] != '0' && j < NbL - 1) {	// Test vers le bas
					glVertex2f(i + 1, j + 1);
					glVertex2f(i, j + 1);
				}
				if (i >= 1) {	// Test vers la gauche
					if (Matrix[i - 1][j] != '0') {
						glVertex2f(i, j);
						glVertex2f(i, j + 1);
					}
				}
				if (i < NbC - 1) {	// Test vers la droite
					if (Matrix[i + 1][j] != '0') {
						glVertex2f(i + 1, j + 1);
						glVertex2f(i + 1, j);
					}
				}
				glEnd();
			}
		}
	}
}

void LabyKeyboard(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_UP: {
			pacman.GoUp();
			break;
		}
		case GLUT_KEY_DOWN: {
			pacman.GoDown();
			break;
		}
		case GLUT_KEY_LEFT: {
			pacman.GoLeft();
			break;
		}
		case GLUT_KEY_RIGHT: {
			pacman.GoRight();
			break;
		}
	}
	Teleportation();

	blinky.TestCollision();
	pinky.TestCollision();
	inky.TestCollision();
	clyde.TestCollision();

	Point* P = firstPoint;
	Point* Precedent = NULL;
	Point* Save = NULL;
	while (P != NULL)
	{
		if (pacman.GetPosC() == P->GetPosiC() && pacman.GetPosL() == P->GetPosiL()) {
			Save = P->GetNextP();
			P = Precedent;
			P->SetSuivant(Save);
			score = score + 10;
			cout << "Score : " << score << endl;
		}
		Precedent = P;
		P = P->GetNextP();
	}

	glutPostRedisplay();
}

void LabyTimer(int value)
{
	glutTimerFunc(TIMER_MILLIS, LabyTimer, 0);
	blinky.DeplacementAuto();
	pinky.DeplacementAuto();
	inky.DeplacementAuto();
	clyde.DeplacementAuto();

	blinky.TestCollision();
	pinky.TestCollision();
	inky.TestCollision();
	clyde.TestCollision();
	glutPostRedisplay();
}

void Teleportation()
{
	if (pacman.GetPosC() == Tp1C && pacman.GetPosL() == Tp1L)
	{
		pacman.SetPosC(Tp2C);
		pacman.SetPosL(Tp2L);
		glutPostRedisplay();
	}
	else if (pacman.GetPosC() == Tp2C && pacman.GetPosL() == Tp2L)
	{
		pacman.SetPosC(Tp1C);
		pacman.SetPosL(Tp1L);
		glutPostRedisplay();
	}
}

void AddPoint(int Column, int Line)
{
	Point* P = NULL;

	P = new Point();

	P->SetPosiC(Column);
	P->SetPosiL(Line);

	P->SetSuivant(firstPoint);
	firstPoint = P;
}

/*
blinky
pinky
inky
clyde
*/