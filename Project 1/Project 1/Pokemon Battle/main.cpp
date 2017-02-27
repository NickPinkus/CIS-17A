#include <iostream>
#include <string>
#include "Trainer.h"
using namespace std;

string nameValidate();

int main()
{
	enum monster { Bulbasaur, Charmander, Squirtle, Pikachu, Eevee };
	int playerchoice = 0,
		playerMonsterID = 0,
		opponentMonsterID = 0;
	string playerNameSet = "Player One",
		opponentNameSet = "Player Two";
	
	cout << "Oak: Hello, welcome to the world of Pokemon!" << endl
		<< "My name is Oak! People call me a Pokemon Professor!" << endl
		<< "What about you? What is your name?" << endl;

	playerNameSet = nameValidate();

	cout << "\nOak: " << playerNameSet << ", huh? That's a cool name!" << endl;
	getchar();
	cout << "\nOak: Ah! I see you came here with my grandson! What was his name again?" << endl;

	opponentNameSet = nameValidate();

	cout << endl << playerNameSet << "! I have three Pokemon here!" << endl
		<< "You can choose one as your companion!\n\n";
	getchar();
	cout << opponentNameSet << ": Gramps, what about me?" << endl;
	getchar();
	cout << "\nOak: " << opponentNameSet << "! I forgot you were coming! You can pick one too!\n\n" <<
		playerNameSet << ", choose a Pokemon:" << endl
		<< "(1) Bulbasaur - Grass Type" << endl
		<< "(2) Charmander - Fire Type" << endl
		<< "(3) Squirtle - Water Type" << endl;

	cin >> playerchoice;
	switch (playerchoice)
	{
	case 1:
		playerMonsterID = Bulbasaur;
		opponentMonsterID = Charmander;
		break;
	case 2:
		playerMonsterID = Charmander;
		opponentMonsterID = Squirtle;
		break;
	case 3:
		playerMonsterID = Squirtle;
		opponentMonsterID = Bulbasaur;
		break;
		
	default:
		playerMonsterID = Pikachu;
		opponentMonsterID = Eevee;
	}

	Trainer Player = Trainer(playerNameSet, playerMonsterID);
	Trainer Opponent = Trainer(opponentNameSet, opponentMonsterID);


	cout << "\n\n" << Player.GetName() << " chose " << Player.Pokemon.GetName() << "!" << endl;
	cout << "\n\n" << Opponent.GetName() << ": Then I'll choose this one!" << endl;
	cout << Opponent.GetName() << " chose " << Opponent.Pokemon.GetName() << "!" << endl;
	getchar();

	cout << "\n\n" << Opponent.GetName() << ": Hey, " << Player.GetName() << "! Let's have a Pokemon battle!" << endl;

	getchar();
	cout << Opponent.GetName() << " challenges " << Player.GetName() << " to a battle!\n\n";
	cout << Opponent.GetName() << " sends out " << Opponent.Pokemon.GetName() << "!" << endl;

	getchar();
	return 0;
}

string nameValidate()
{
	string setname;
	getline(cin, setname);
	while (setname.empty())
	{
		cout << "Oak: I may be old, but I'm pretty sure that isn't a name..." << endl;
		getline(cin, setname);
	}

	return setname;
}