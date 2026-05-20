#pragma once
#include <iostream>
#include "Player.h"

class Warrior : public Player
{
public:
	Warrior(std::string name, int hp, int mp, int ATK, int defense)
		: Player(name, hp + 30, mp, ATK, defense)
	{
		std::cout << "You became a Warrior! (HP +30)" << std::endl;
		job = "Warrior";
	}

	void printAttack() const
	{
		std::cout << "* Swings the sword!" << std::endl;
	}
};

class Magician : public Player
{
public:
	Magician(std::string name, int hp, int mp, int ATK, int defense)
		: Player(name, hp, mp + 30, ATK, defense)
	{
		std::cout << "You became a Magician! (MP +30)" << std::endl;
		job = "Magician";
	}

	void printAttack() const
	{
		std::cout << "* Fires a fireball!" << std::endl;
	}
};

class Thief : public Player
{
public:
	Thief(std::string name, int hp, int mp, int ATK, int defense)
		: Player(name, hp, mp, ATK + 30, defense)
	{
		std::cout << "You became a Thief! (ATK +30)" << std::endl;
		job = "Thief";
	}

	void printAttack() const
	{
		std::cout << "* Throws a shuriken!" << std::endl;
	}
};

class Archer : public Player
{
public:
	Archer(std::string name, int hp, int mp, int ATK, int defense)
		: Player(name, hp, mp, ATK, defense + 30)
	{
		std::cout << "You became a Archer! (Defense +30)" << std::endl;
		job = "Archer";
	}

	void printAttack() const
	{
		std::cout << "* Arrow Barrage!" << std::endl;
	}
};