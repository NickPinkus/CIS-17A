#pragma once
#include "Attacks.h"



Attacks::Attacks(string attackName, int attackDamage) : atkName(attackName), attack(attackDamage)
{
}


Attacks::~Attacks()
{
}

int Attacks::calculateAttackDamage()
{
	srand(time(NULL));

	switch (rand() % 20 + 1)
	{
	case 1:
		return 0;
		break;
	case 20:
		return attack * 2;
		break;
	default:
		return attack;
	}
}

string Attacks::GetAttackName()
{
	return atkName;
}
