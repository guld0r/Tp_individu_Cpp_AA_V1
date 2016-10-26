#include "leJeu.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

//constructeur initial
leJeu::leJeu()
{
	this->myCurrentTry = 0;
	this->myGameIsWon = false;
	this->myHiddenWord = "ule";
}

//get
//renvoi nombre max essai
int leJeu::GetMaxTries() const
{
	map<int, int> wordLengthToMaxTries{ { 3,4 },{ 4,7 },{ 5,10 },{ 6,16 },{ 7,20 } };
	return wordLengthToMaxTries[myHiddenWord.length()];
}

//renvoi essai en cours
int leJeu::getMyCurrentTry()const
{
	return this->myCurrentTry;
}

//renvoi le mot à trouver
string leJeu::getMyHiddenWord()const
{
	return this->myHiddenWord;
}

//renvoi si le jeu est gagner ou non
bool leJeu::getMyGameIsWon()const
{
	return this->myGameIsWon;
}

//set
//permet d'instancier l'essai
void leJeu::setMyCurrentTry(int essai)
{
	this->myCurrentTry = essai;
}

//instancie le mot à trouver
void leJeu::setMyHiddenWord(string word)
{
	this->myHiddenWord = word;
}

//instancie la victoire ou non de la partie
void leJeu::setMyGameIsWon(bool win)
{
	this->myGameIsWon = win;
}

//permet la saisie d'un mot
string leJeu::saisiWord()
{
	string essai;
	cin >> essai;
	return essai;
}

//test les différents cas d'erreur d'un mot
statut leJeu::testWord(string leMot)
{
	if (leMot.length() != this->myHiddenWord.length())
	{
		return wrong_length;
	}
	for (int i = 0;i < leMot.length();i++)
	{
		if (isupper(leMot[i]))
		{
			return not_lowercase;
		}
	}
	for (int i = 0;i < leMot.length();i++)
	{
		for (int j = 0;j < leMot.length();j++)
		{
			if (leMot[i] == leMot[j]&& i!=j)
			{
				return not_isogram;
			}
		}
	}
	return ok;
}

//affichage victoire défaite+compte bull & cow
void leJeu::baseGame()
{
		string essai;
		bool rejoue;
		compteur.leBull = 0;
		compteur.leCow = 0;
		cout << "essai numero " << getMyCurrentTry()+1 << " sur " << GetMaxTries() << endl;
		cout << "veuillez saisir un mot : ";
		essai=saisiWord();
		//incrémentation essai
		setMyCurrentTry(getMyCurrentTry() + 1);
		//test victoire
		if (essai== getMyHiddenWord())
		{
			setMyGameIsWon(true);
			cout << "Felicitation vous avez gagne" << endl;
			system("pause");
		}else if (testWord(essai)==ok){
			//compte bull et cow
			for (int i = 0;i < this->myHiddenWord.length();i++)
			{
				if (myHiddenWord[i] == essai[i])
				{
					compteur.leBull += 1;
				}
				for (int j = 0;j < essai.length();j++)
				{
					if (this->myHiddenWord[i] == essai[j] && i != j)
					{
						compteur.leCow += 1;
					}
				}
			}
			cout << "Bull : " << compteur.leBull << "\t Cow : " << compteur.leCow << endl;
			compteur.leBull = 0;
			compteur.leCow = 0;
		}
		//affichage si pas isogramme
		else if (testWord(essai) == not_isogram)
		{
			cout << "il y a 2 fois la meme lettre dans votre mot" << endl;
		}
		//affichage si mauvaise longueur
		else if (testWord(essai) == wrong_length)
		{
			cout << "le mot n'a pas la bonne longueur" << endl;
		}
		//affichage si il y'a une majuscule dans le mot
		else if (testWord(essai) == not_lowercase){
			cout << "le mot rentre contient une majuscule" << endl;
		}
		if (this->myCurrentTry==GetMaxTries())
		{
			//défaite
			setMyGameIsWon(true);
			cout << "Vous avez perdu" << endl;
			system("pause");
		}
}

//création du menu du jeu
void leJeu::leMenu()
{
	cout << "Bienvenue dans Bulls and Cows, un amusant jeu de mots.\n";
	cout << endl;
	cout << "          }   {         ___ " << endl;
	cout << "          (o o)        (o o) " << endl;
	cout << "   /-------\\ /          \\ /-------\\ " << endl;
	cout << "  / | BULL |O            O| COW  | \\ " << endl;
	cout << " *  |-,--- |              |------|  * " << endl;
	cout << "    ^      ^              ^      ^ " << endl;
	cout << endl;
	return;
}

//destructeur
leJeu::~leJeu()
{
}
