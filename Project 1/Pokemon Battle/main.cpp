#include <iostream>
#include "Trainer.h"
using namespace std;

int main()
{
	int playerchoice = 0;
	enum monster { Bulbasaur, Charmander, Squirtle, Pikachu, Eevee };
	string nameset = "DEFAULT";
	Trainer Opponent = Trainer("Blue");
	
	cout << "Oak: Hello, welcome to the world of Pokemon!" << endl
		<< "My name is Oak! People call me a Pokemon Professor!" << endl
		<< "What about you? What is your name?" << endl;

	getline(cin, nameset);
	Trainer Player = Trainer(nameset);
	cout << "\nOak: " << Player.GetName() << ", huh? That's a cool name!" << endl;
	getchar();
	cout << endl << Player.GetName() << "! I have three Pokemon here!" << endl
		<< "You can choose one as your companion!\n\n";
	getchar();
	cout << Opponent.GetName() << ": Gramps, what about me?" << endl;
	getchar();
	cout << "\nOak: " << Opponent.GetName() << "! I forgot you were coming! You can pick one too!\n\n" <<
		Player.GetName() << ", choose a Pokemon:" << endl
		<< "(1) Bulbasaur - Grass Type" << endl
		<< "(2) Charmander - Fire Type" << endl
		<< "(3) Squirtle - Water Type" << endl;
	cin >> playerchoice;
	switch (playerchoice)
	{
	case 1:
		cout << Player.GetName() << " chose Bulbasaur!" << endl;
		Player.monster.ID = 0;
		cout << Opponent.GetName() << " chose Charmander!" << endl;
		Opponent.monster.ID = 1;

		cout << Player.monster.GetName() << endl << Opponent.monster.GetName() << endl;
		break;
	case 2:
		cout << Player.GetName() << " chose Charmander!" << endl;
		cout << Opponent.GetName() << " chose Squirtle!" << endl;
		break;
	case 3:
		cout << Player.GetName() << " chose Squirtle!" << endl;
		cout << Opponent.GetName() << " chose Bulbasaur!" << endl;
		break;
		
	default:
		cout << Player.GetName() << " chose Pikachu!" << endl;
		cout << Opponent.GetName() << " chose Eevee!" << endl;
	}


	cout << Opponent.GetName() << " challenges " << Player.GetName() << " to a battle!" << endl;
	cin.ignore();
	getchar();

	return 0;
}