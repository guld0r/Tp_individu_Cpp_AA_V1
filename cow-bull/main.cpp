#include "leJeu.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	//initialisation variables
	leJeu jeu;
	jeu.leMenu();
	//test fin de partie
	while(jeu.getMyGameIsWon() != true)
	{
		//l'appel de la fonction du jeu
		jeu.baseGame();
	}
}