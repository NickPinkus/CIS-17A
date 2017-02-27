#include "Monster.h"
#include <iostream>
using namespace std;


string Monster::GetName()
{
	return _name;
}

Monster::Monster(int ID)
{
	health = 10;
	attack = 10;
	defense = 5;

	switch (ID)
	{
	case 0:
		_name = "Bulbasaur";
		break;
	case 1:
		_name = "Charmander";
		break;
	case 2:
		_name = "Squirtle";
		break;
	case 3:
		_name = "Pikachu";
		break;
	case 4:
		_name = "Eevee";
		break;
	default:
		_name = "DEFAULT";
	}
}


Monster::~Monster()
{
}
