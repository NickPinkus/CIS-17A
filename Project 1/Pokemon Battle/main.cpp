#include <iostream>
#include <string>
#include "Trainer.h"
using namespace std;

string nameValidate(string &setname);

int main()
{
	int playerchoice = 0;
	enum monster { Bulbasaur, Charmander, Squirtle, Pikachu, Eevee };
	string nameset = "DEFAULT";
	
	cout << "Oak: Hello, welcome to the world of Pokemon!" << endl
		<< "My name is Oak! People call me a Pokemon Professor!" << endl
		<< "What about you? What is your name?" << endl
		<< "Name: ";

	nameValidate(nameset);
	Trainer Player = Trainer(nameset);
	cout << "\nOak: " << Player.GetName() << ", huh? That's a cool name!" << endl;
	getchar();
	cout << "\nOak: Ah! I see you came here with my grandson! What was his name again?" << endl
		<< "Name: ";
	nameValidate(nameset);
	Trainer Opponent = Trainer(nameset);
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
		Player.monsterSetInfo(Bulbasaur);
		Opponent.monsterSetInfo(Charmander);
		break;
	case 2:
		Player.monsterSetInfo(Charmander);
		Opponent.monsterSetInfo(Squirtle);
		break;
	case 3:
		Player.monsterSetInfo(Squirtle);
		Opponent.monsterSetInfo(Bulbasaur);
		break;
		
	default:
		Player.monsterSetInfo(Pikachu);
		Opponent.monsterSetInfo(Eevee);
	}

	cout << "\n\n" << Player.GetName() << " chose " << Player.monsterGetName() << "!" << endl;
	cout << "\n\n" << Opponent.GetName() << ": Then I'll choose this one!" << endl;
	cout << Opponent.GetName() << " chose " << Opponent.monsterGetName() << "!" << endl;
	getchar();

	cout << "\n\n" << Opponent.GetName() << ": Hey, " << Player.GetName() << "! Let's have a Pokemon battle!" << endl;

	getchar();
	cout << Opponent.GetName() << " challenges " << Player.GetName() << " to a battle!" << endl;
	cout << Opponent.GetName() << " sends out " << Opponent.monsterGetName() << "!" << endl;

	getchar();
	return 0;
}

string nameValidate(string &setname)
{
	getline(cin, setname);
	while (setname.empty())
	{
		cout << "Oak: I may be old, but I'm pretty sure that isn't a name..." << endl;
		getline(cin, setname);
	}

	return setname;
}