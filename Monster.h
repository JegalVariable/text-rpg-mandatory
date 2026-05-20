#pragma once
#include <iostream>
#include <string>

class Player;

class Monster
{
protected:
	std::string name;
	std::string dropItemName;
	int hp;
	int ATK;
	int defense;
	int dropItemPrice;

public:
	Monster(std::string name, std::string dropItemName, int hp, int ATK, int defense, int dropItemPrice)
		: name(name), dropItemName(dropItemName), hp(hp), ATK(ATK), defense(defense), dropItemPrice(dropItemPrice) {
	}

	void attack(Player* player);
	std::string getName()
	{
		return name;
	}
	std::string getDropItemName()
	{
		return dropItemName;
	}
	int getHp() const
	{
		return hp;
	}
	int getDefense() const
	{
		return defense;
	}
	int getDropItemPrice() const
	{
		return dropItemPrice;
	}

	void setHp(int hp)
	{
		this->hp = hp;
	}
};