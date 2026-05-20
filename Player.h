#pragma once
#include <iostream>
#include <vector>

class Monster;

void printBrick();

struct Ingredient
{
	std::string name = "";
	int count = 0;

	void PrintIngredient() const;
};

struct PotionRecipe
{
	int id = 0;
	std::string name = "";
	std::vector<Ingredient> ingredient;

	void ShowAllRecipes() const;
	bool SearchByName(std::string sName) const;
	bool SearchByIngredient(std::string sIngredient) const;
};

struct Item
{
	std::string name = "";
	int price = 0;

	void PrintInfo() const;
};

class Player
{
protected:
	std::string name;
	std::string job;
	int level = 1;
	int hp;
	int mp;
	int ATK;
	int defense;

public:
	Player(std::string name, int hp, int mp, int ATK, int defense)
		:name(name), hp(hp), mp(mp), ATK(ATK), defense(defense) {
	}
	virtual ~Player() {}

	virtual void printAttack() const = 0;
	void printPlayerStatus() const;
	void attack(Monster& monster);

	std::string getName() const
	{
		return name;
	}
	std::string getJob() const
	{
		return job;
	}
	int getLevel() const
	{
		return level;
	}
	int getHp() const
	{
		return hp;
	}
	int getMp() const
	{
		return mp;
	}
	int getATK() const
	{
		return ATK;
	}
	int getDefense() const
	{
		return defense;
	}

	void setJob(std::string job)
	{
		this->job = job;
	}
	void setLevel(int level)
	{
		this->level = level;
	}
	void setHp(int hp)
	{
		this->hp = hp;
	}
	void setMP(int mp)
	{
		this->mp = mp;
	}
};