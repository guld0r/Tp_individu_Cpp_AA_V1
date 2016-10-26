#pragma once
#include<string>

using namespace std;

struct compte 
{
	int leCow;
	int leBull;
};

enum statut 
{
	invalid_statut, //le reste
	ok, //le mot est bon
	not_isogram, //2 fois la même lettre
	wrong_length, //mauvaise longueur
	not_lowercase //pas en minuscule
};

class leJeu
{
public:
	//constructeur
	leJeu();
	//get
	int getMyCurrentTry()const;
	string getMyHiddenWord()const;
	bool getMyGameIsWon()const;
	int GetMaxTries() const;
	//set
	void setMyCurrentTry(int essai);
	void setMyHiddenWord(string word);
	void setMyGameIsWon(bool win);
	//fonctions
	string saisiWord();
	statut testWord(string leMot);
	void baseGame();
	void leMenu();
	bool replay();
	//destructeur
	~leJeu();
//arguments privés
private:
	int myCurrentTry;
	string myHiddenWord;
	bool myGameIsWon;
	statut leStatut;
	compte compteur;
};

