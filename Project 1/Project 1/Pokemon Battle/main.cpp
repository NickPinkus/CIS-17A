#include <iostream>
#include "Trainer.h"

string nameValidate();

void NewGame();
bool Battle(Trainer Player, Trainer Opponent);

int main()
{
	NewGame();

	cin.ignore();
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

void NewGame()
{
	enum pokemon { Bulbasaur, Charmander, Squirtle, Pikachu, Eevee };
	int playerchoice = 0;
	string NameSet = "DEFAULT";

	cout << "Oak: Hello, welcome to the world of Pokemon!"        << endl
		 << "My name is Oak! People call me a Pokemon Professor!" << endl
		 << "What about you? What is your name?"                  << endl
		 << "Name: ";

	NameSet = nameValidate();

	Trainer Player = Trainer(NameSet);

	cout << "\nOak: " << Player.GetName() << ", huh? That's a cool name!" << endl;
	getchar();
	cout << "\nOak: Ah! I see you came here with my grandson! What was his name again?" << endl
		 << "Name: ";

	NameSet = nameValidate();
	Trainer Opponent = Trainer(NameSet);

	cout << endl << "Oak: " << Player.GetName() << "! I have three Pokemon here!" << endl
		 << "You can choose one as your companion!\n\n";
	getchar();
	cout << Opponent.GetName() << ": Gramps, what about me?" << endl;
	getchar();
	cout << "\nOak: " << Opponent.GetName() << "! I forgot you were coming! You can pick one too!\n\n";
	cout << Player.GetName() << ", choose a Pokemon:" << endl
		 << "(1) Bulbasaur - Grass Type"              << endl
		 << "(2) Charmander - Fire Type"              << endl
		 << "(3) Squirtle - Water Type"               << endl;
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
	cout << "\n\n" << Opponent.GetName() << ": Then I'll choose this one!"             << endl;
	cout << Opponent.GetName() << " chose " << Opponent.Pokemon.GetName() << "!"       << endl;
	getchar();

	cout << "\n\n" << Opponent.GetName() << ": Hey, " << Player.GetName() << "! Let's have a Pokemon battle!" << endl;

	getchar();

	Battle(Player, Opponent);
	
}

bool Battle(Trainer Player, Trainer Opponent)
{
	int playerchoice;
	srand(time(NULL));

	cout << "Trainer " << Opponent.GetName() << " challenges Trainer " << Player.GetName() << " to a battle!" << endl;
	cout << Opponent.GetName() << " sends out " << Opponent.Pokemon.GetName() << "!" << endl;

	getchar();

	cout << "Go! " << Player.Pokemon.GetName() << "!" << endl;

	getchar();
	while (Player.Pokemon.Health > 0 && Opponent.Pokemon.Health > 0)
	{
		cout << Opponent.Pokemon.GetName() << endl
			 << "Health: " << Opponent.Pokemon.Health
			 << "/" << Opponent.Pokemon.GetMaxHealth() << "\n\n";

		cout << Player.Pokemon.GetName() << endl
			 << "Health: " << Player.Pokemon.Health
			 << "/" << Player.Pokemon.GetMaxHealth() << "\n\n";

	//Start Player's Turn

		cout << "(1) Attack / (2) Items" << endl
			<< "Your Choice: ";
		cin >> playerchoice;

		switch (playerchoice)
		{
		case 1:
			cout << "\n\n" << Player.Pokemon.GetName() << "'s attacks:" << endl
				 << "(1)" << Player.Pokemon.Attack1.GetAttackName()     << endl
				 << "(2)" << Player.Pokemon.Attack2.GetAttackName()     << endl
				 << "Your Choice: ";
			cin  >> playerchoice;

			if (playerchoice == 1)
			{
				cout << "\n\n" << Player.Pokemon.GetName() << " used " << Player.Pokemon.Attack1.GetAttackName() << "!";
				Opponent.Pokemon.Health -= Player.Pokemon.Attack1.calculateAttackDamage();
			}
			else
			{
				cout << "\n\n" << Player.Pokemon.GetName() << " used " << Player.Pokemon.Attack2.GetAttackName() << "!";
				Opponent.Pokemon.Health -= Player.Pokemon.Attack2.calculateAttackDamage();
			}

			break;

		case 2:
			int counter = 1;
			for (int i = 0; i < sizeof(Player.Inventory)/sizeof(*Player.Inventory); i++)
			{
				if (Player.Inventory[i].GetItemCount() > 0)
				{
					cout << "(" << counter << ") " << Player.Inventory[i].GetItemName()
						<< " x" << Player.Inventory[i].GetItemCount() << endl;
					counter++;
				}
			}
			cin >> playerchoice;
			switch (playerchoice)
			{
			case 1:
				if (Player.Inventory[0].GetItemCount() > 0 && Player.Pokemon.Health + 5 <= Player.Pokemon.GetMaxHealth())
				{
					Player.Inventory[0].UseItem();
					Player.Pokemon.Health += 5;
					cout << Player.GetName() << " used a " << Player.Inventory[0].GetItemName();
				}
				else
				{
					Player.Inventory[0].UseItem();
					Player.Pokemon.Health = Player.Pokemon.GetMaxHealth();
					cout << Player.GetName() << " used a " << Player.Inventory[0].GetItemName();
				}

				break;
			case 2:
				cout << "Pokeball! Go!" << endl;
				cout << Player.GetName() << "! You can't steal another trainer's Pokemon!" << endl;
				Player.Inventory[1].UseItem();
				break;
			}
			break;
		}
		getchar();
		//Check for player win condition
		if (Opponent.Pokemon.Health <= 0)
		{
			cout << Opponent.Pokemon.GetName() << " has fainted." << endl
				 << "Trainer " << Player.GetName() << " defeated Trainer " << Opponent.GetName() << "!\n\n";

			cout << Opponent.GetName() << ": Whatever... My Pokemon is weak. I'm going to force it to get stronger!" << endl;

			return true;
		}

		//Opponent's Turn
		playerchoice = rand() % 2 + 1;
		switch (playerchoice)
		{
		case 1:
			playerchoice = rand() % 2 + 1;

			if (playerchoice == 1)
			{
				cout << "\n\n" << Opponent.Pokemon.GetName() << " used " << Opponent.Pokemon.Attack1.GetAttackName() << "!";
				Player.Pokemon.Health -= Opponent.Pokemon.Attack1.calculateAttackDamage();
			}
			else
			{
				cout << "\n\n" << Opponent.Pokemon.GetName() << " used " << Opponent.Pokemon.Attack2.GetAttackName() << "!";
				Player.Pokemon.Health -= Opponent.Pokemon.Attack2.calculateAttackDamage();
			}

			break;

		case 2:
			if (Opponent.Inventory[0].GetItemCount() > 0 && Opponent.Pokemon.Health + 5 <= Opponent.Pokemon.GetMaxHealth())
			{
				Opponent.Pokemon.Health += 5;
				Opponent.Inventory[0].UseItem();
				cout << Opponent.GetName() << " used a " << Opponent.Inventory[0].GetItemName() << endl;
			}
			else
			{
				Opponent.Pokemon.Health = Opponent.Pokemon.GetMaxHealth();
				Opponent.Inventory[0].UseItem();
				cout << Opponent.GetName() << " used a " << Opponent.Inventory[0].GetItemName() << endl;
			}
			break;
		}

		//Check for Opponent Win Condition
		if (Player.Pokemon.Health <= 0)
		{
			cout << Player.Pokemon.GetName() << " has fainted." << endl
				<< Player.GetName() << " blacked out." << endl;
			return false;
		}

		cin.ignore();
		getchar();
	}
}