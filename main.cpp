#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Job.h"
#include "Monster.h"

using namespace std;

void printBrick()
{
	for (int i = 0; i < 40; i++)
	{
		cout << "=";
	}
	cout << endl;
}

void printStatus(string name, int stat[])
{
	printBrick();
	cout << "        " << name << "'s Stats" << endl;
	printBrick();
	cout << "HP: " << stat[0] << "        MP: " << stat[1] << endl;
	cout << "ATK: " << stat[2] << "    Defense: " << stat[3] << endl;
	printBrick();
	cout << endl;
}

int main(void)
{
	const int SIZE = 4;
	int stat[SIZE] = { 0 }; // HP, MP, 공격, 방어
	string name = "";
	int hpPotion = 5;
	int mpPotion = 5;

	int choice; // 게임시작
	bool isGameStart = false;

	int jobChoice; // 직업 선택
	bool bJobChoice = false;

	int menuChoice;
	bool bMenu = false;
	Player* player = nullptr;
	Monster monster("Slime", "Slime Jelly", 30, 20, 10, 30); // 슬라임 체30 공20 방10 값30
	vector<Item> inventory;
	Item droppedItem;

	vector<PotionRecipe> potionRecipe;
	potionRecipe.push_back({ 1, "HPPotion", {{"Herb", 1 }, { "Clear Water", 1 }} });
	potionRecipe.push_back({ 2, "StaminaPotion", { {"Herb", 1}, { "Berry", 1 }} });

	printBrick();
	cout << "     [ Dungeon Escape Text RPG ]" << endl;
	printBrick();
	cout << "Enter your hero's name: ";
	cin >> name;
	cout << endl;

	while (true) // 체력 마나 입력
	{
		cout << "Enter HP and MP: ";
		cin >> stat[0] >> stat[1];
		if (stat[0] > 50 && stat[1] > 50)
		{
			break;
		}
		else
		{
			cout << "HP or MP is too low. Try again." << endl;
		}
	}
	while (true) // 공격 방어 입력
	{
		cout << "Enter ATK and Defense: ";
		cin >> stat[2] >> stat[3];
		if (stat[2] > 50 && stat[3] > 50)
		{
			break;
		}
		else
		{
			cout << "ATK or Defense is too low. Try again." << endl;
		}
	}
	cout << endl;

	printStatus(name, stat);

	cout << "* You received 5 HP Potions and 5 MP Potions." << endl;
	printBrick();
	cout << "< Character Upgrade >" << endl;
	cout << "1. HP UP    2. MP UP    3. ATK x2" << endl;
	cout << "4. Defense x2  5. Show Stats  0. Start Game" << endl;
	printBrick();

	while (!isGameStart)
	{
		cout << "Choose: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "Starting the game!" << endl << endl;
			isGameStart = true;
			break;
		case 1:
			if (hpPotion > 0)
			{
				stat[0] += 20;
				hpPotion -= 1;
				cout << "* HP increased by 20. (HP Potion used: " << hpPotion << " left)" << endl;
			}
			else
			{
				cout << "Out of HP Potions!" << endl;
			}
			break;
		case 2:
			if (mpPotion > 0)
			{
				stat[1] += 20;
				mpPotion -= 1;
				cout << "* MP increased by 20. (MP Potion used: " << mpPotion << " left)" << endl;
			}
			else
			{
				cout << "Out of MP Potions!" << endl;
			}
			break;
		case 3:
			stat[2] *= 2;
			cout << "Your ATK has doubled." << endl;
			break;
		case 4:
			stat[3] *= 2;
			cout << "Your defense has doubled." << endl;
			break;
		case 5:
			printStatus(name, stat);
			break;
		default:
			cout << "Invalid input!" << endl;
			break;
		}
	}

	cout << "     < Job Selection >" << endl;
	cout << name << ", choose your job!" << endl;
	cout << "1. Warrior   2. Magician   3. Thief   4. Archer" << endl;


	while (!bJobChoice) // 직업선택
	{
		cout << "Choose: ";
		cin >> jobChoice;
		cout << endl;

		switch (jobChoice)
		{
		case 1:
			player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
			bJobChoice = true;
			break;
		case 2:
			player = new Magician(name, stat[0], stat[1], stat[2], stat[3]);
			bJobChoice = true;
			break;
		case 3:
			player = new Thief(name, stat[0], stat[1], stat[2], stat[3]);
			bJobChoice = true;
			break;
		case 4:
			player = new Archer(name, stat[0], stat[1], stat[2], stat[3]);
			bJobChoice = true;
			break;
		default:
			cout << "Invalid input!" << endl;
			break;
		}
	}
	player->printAttack();
	player->printPlayerStatus();

	cout << "[Battle Start!] " << name << "(" << player->getJob() << ") vs " << monster.getName() << endl << endl; // 전투시작

	while (player->getHp() > 0 && monster.getHp() > 0)
	{
		cout << "--- Player Turn ---" << endl;
		player->printAttack();
		player->attack(monster); // 슬라임 체30 공20 방10 값30

		if (monster.getHp() <= 0) // 유저 승 / 유저가 이긴 경우는 몬스터가 1대 때리고 끝나서 브레이크 추가
		{
			cout << "★ Victory!" << endl;
			cout << "  -> Got: " << monster.getDropItemName() << "!" << endl;
			droppedItem.name = monster.getDropItemName(); // 아이템 이름 저장
			droppedItem.price = monster.getDropItemPrice(); // 아이템 값 저장
			inventory.push_back(droppedItem); // 인벤토리에 저장
			cout << "  -> Saved to inventory." << endl; // 저장완료 출력
			break;
		}

		cout << "--- " << monster.getName() << " Turn ---" << endl; // 몬스터가 이긴 경우는 while 조건에서 끝남
		monster.attack(player);
	}

	if (player->getHp() <= 0) // 몬스터 승
	{
		cout << "★ defeat..." << endl;
	}

	while (!bMenu)
	{
		cout << endl;
		cout << "=== Main Menu ===" << endl;
		cout << "1. Enter Dungeon" << endl;
		cout << "2. Check Inventory" << endl;
		cout << "3. Potion Workshop" << endl;
		cout << "0. Quit" << endl;
		cout << endl;
		cout << "Choose: ";
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 0:
			cout << "Exiting the game." << endl;
			bMenu = true;
			break;
		case 1:
			cout << "Enter the dungeon!" << endl;
			break;
		case 2:
		{
			int i = 1;

			cout << "[ Inventory (" << inventory.size() << " / 10) ]" << endl;
			for (const Item& item : inventory)
			{
				cout << i++ << ". ";
				item.PrintInfo();
			}
			break;
		}
		case 3: // 포션 제작소
		{
			int potionChoice;
			bool bPotionMenu = false;

			while (!bPotionMenu)
			{
				cout << endl;
				cout << "=== Potion Workshop ===" << endl;
				cout << "1. Show all recipes" << endl;
				cout << "2. Search by potion name" << endl;
				cout << "3. Search by ingredient" << endl;
				cout << "0. Go back" << endl;
				cout << endl;
				cout << "Choose: ";
				cin >> potionChoice;

				switch (potionChoice)
				{
				case 0: // 메인메뉴 돌아가기
					bPotionMenu = true;
					break;
				case 1: // 레시피 전체 출력
					for (const PotionRecipe& pR : potionRecipe)
					{
						pR.ShowAllRecipes();
						cout << endl;
					}
					break;
				case 2: // 포션 검색
				{
					string potionName = "";
					bool found = false;

					cout << "Search potion name: ";
					cin >> potionName;

					for (const PotionRecipe& pR : potionRecipe)
					{
						found = pR.SearchByName(potionName);
						if (found)
						{
							break;
						}
					}
					if (!found)
					{
						cout << "Potion not found..." << endl;
					}
					break;
				}
				case 3: // 재료검색
				{
					string ingredientName = "";
					int count = 0;

					cout << "Search ingredient: ";
					cin.ignore();
					getline(cin, ingredientName);

					for (const PotionRecipe& pR : potionRecipe)
					{
						if (pR.SearchByIngredient(ingredientName))
						{
							count++;
						}
					}
					if (count == 0)
					{
						cout << "Ingredient not found..." << endl;
					}
					else
					{
						cout << "Found " << count << " recipes." << endl;
					}
					break;
				}
				default:
					cout << "Invalid input!" << endl;
					break;
				}
			}
			break;
		}
		default:
			cout << "Invalid input!" << endl;
			break;
		}
	}

	delete player;

	return 0;
}