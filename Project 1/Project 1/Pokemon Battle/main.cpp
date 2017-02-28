#include <iostream>
#include <string>
#include "Trainer.h"
using namespace std;

string nameValidate();

int main()
{
	enum pokemon { Bulbasaur, Charmander, Squirtle, Pikachu, Eevee };
	int playerchoice = 0;
	string NameSet = "DEFAULT";
	
	cout << "Oak: Hello, welcome to the world of Pokemon!" << endl
		<< "My name is Oak! People call me a Pokemon Professor!" << endl
		<< "What about you? What is your name?" << endl
		<< "Name: ";

	NameSet = nameValidate();
	Trainer Player = Trainer(NameSet);

	cout << "\nOak: " << Player.GetName() << ", huh? That's a cool name!" << endl;
	getchar();
	cout << "\nOak: Ah! I see you came here with my grandson! What was his name again?" << endl
		<< "Name: ";

	NameSet = nameValidate();
	Trainer Opponent = Trainer(NameSet);
	cout << endl <<"Oak: " << Player.GetName() << "! I have three Pokemon here!" << endl
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
		Player.Pokemon.SetIDNum(Bulbasaur);
		Opponent.Pokemon.SetIDNum(Charmander);
		break;
	case 2:
		Player.Pokemon.SetIDNum(Charmander);
		Opponent.Pokemon.SetIDNum(Squirtle);
		break;
	case 3:
		Player.Pokemon.SetIDNum(Squirtle);
		Opponent.Pokemon.SetIDNum(Bulbasaur);
		break;
		
	default:
		Player.Pokemon.SetIDNum(Pikachu);
		Opponent.Pokemon.SetIDNum(Eevee);
	}

	Player.Pokemon.SetInfo();
	Opponent.Pokemon.SetInfo();


	cout << "\n\n" << Player.GetName() << " chose " << Player.Pokemon.GetName() << "!" << endl;
	cout << "\n\n" << Opponent.GetName() << ": Then I'll choose this one!" << endl;
	cout << Opponent.GetName() << " chose " << Opponent.Pokemon.GetName() << "!" << endl;
	getchar();

	cout << "\n\n" << Opponent.GetName() << ": Hey, " << Player.GetName() << "! Let's have a Pokemon battle!" << endl;

	getchar();

	cout << Opponent.GetName() << " challenges " << Player.GetName() << " to a battle!" << endl;
	cout << Opponent.GetName() << " sends out " << Opponent.Pokemon.GetName() << "!" << endl;

	getchar();

	cout << "Go! " << Player.Pokemon.GetName() << "!" << endl;
	
	getchar();

	cout << Opponent.Pokemon.GetName() << endl
		<< "Health: " << Opponent.Pokemon.GetHealth() << "/" << Opponent.Pokemon.GetMaxHealth() << "\n\n";

	cout << Player.Pokemon.GetName() << endl
		<< "Health: " << Player.Pokemon.GetHealth() << "/" << Player.Pokemon.GetMaxHealth() << "\n\n";

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