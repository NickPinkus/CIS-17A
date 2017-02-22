#include "Monster.h"



string Monster::GetName()
{
	return _name;
}

Monster::Monster()
{
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
	}
}


Monster::~Monster()
{
}
