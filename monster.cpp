#include <iostream>
#include "Monster.h"
#include "Player.h"

using namespace std;

void Monster::attack(Player* player)
{
	int damage = ATK - player->getDefense();
	if (damage < 1)
	{
		damage = 1;
	}
	cout << "Slime! Slam!" << endl;
	cout << damage << " damage to " << player->getName() << "!" << endl;
	cout << player->getName() << "HP: " << player->getHp() << " -> "; // 처음 체력 출력
	player->setHp(player->getHp() - damage); // 데미지 넣기
	cout << player->getHp(); // 데미지 받은 체력 출력

	if (player->getHp() < 1) // 사망하면
	{
		cout << " (Dead)" << endl;
	}
	else
	{
		cout << endl << endl;
	}
}