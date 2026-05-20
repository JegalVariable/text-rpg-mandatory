#include <iostream>
#include "Player.h"
#include "Monster.h"

using namespace std;

void Ingredient::PrintIngredient() const
{
	cout << name << " x" << count;
}

void PotionRecipe::ShowAllRecipes() const
{
	cout << id << ". " << name << ": ";
	for (int i = 0; i < ingredient.size(); i++)
	{
		ingredient[i].PrintIngredient();
		if (i + 1 < ingredient.size())
		{
			cout << ", ";
		}
	}
}

bool PotionRecipe::SearchByName(string sName) const
{
	if (sName == name)
	{
		cout << "-> " << name << ": ";
		for (int i = 0; i < ingredient.size(); i++)
		{
			ingredient[i].PrintIngredient();
			if (i + 1 < ingredient.size())
			{
				cout << ", ";
			}
		}
		cout << endl;
		return true;
	}
	return false;
}

bool PotionRecipe::SearchByIngredient(string sIngredient) const
{
	bool check = false;

	for (const Ingredient& igrd : ingredient)
	{
		if (igrd.name == sIngredient)
		{
			check = true;
			break; // 입력받은 재료가 있다면 그 레시피 전체를 출력해야해서 더이상 확인할 필요가 없음
		}
	}
	if (check)
	{
		cout << "-> " << name << ": (";
		for (int i = 0; i < ingredient.size(); i++)
		{
			ingredient[i].PrintIngredient();
			if (i + 1 < ingredient.size())
			{
				cout << ", ";
			}
			else
			{
				cout << ")" << endl;
			}
		}
		return true;
	}
	return false;
}

void Item::PrintInfo() const
{
	cout << name << " (" << price << "G)" << endl;
}

void Player::printPlayerStatus() const// 능력치 출력
{
	printBrick();
	cout << "Name " << name << " | Job: " << job << " | Lv." << level << endl;
	cout << "HP: " << hp << " | MP: " << mp << " | ATK: " << ATK << " | Defense: " << defense << endl;
	printBrick();
}

void Player::attack(Monster& monster)
{
	int damage = ATK - monster.getDefense();
	if (damage < 1) // 0이하라면 
	{
		damage = 1;
	}
	cout << damage << " damage to " << monster.getName() << "!" << endl;
	cout << monster.getName() << "HP: " << monster.getHp() << " -> "; // 처음 체력 출력
	monster.setHp(monster.getHp() - damage); // 데미지 넣기
	cout << monster.getHp(); // 데미지 받은 체력 출력

	if (monster.getHp() < 1) // 사망하면
	{
		cout << " (Dead)" << endl;
	}
	else
	{
		cout << endl << endl;
	}
}