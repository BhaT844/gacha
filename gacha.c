#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

typedef struct {
	char* name;
	int damage;
	char* character;
	int rareNum;
} ITEM;

int collection[5] = { 0, 0, 0, 0, 0 };

ITEM weapon[5];

void initWeapons();
void printWeapon(selected);
int checkCollection();

int main_struct(void)
{
	srand(time(NULL));

	initWeapons();

	while (1)
	{
		printf("무 엇 이 나 올 까 나\n아무 키나 눌러서 확인하세요...");
		_getch();

		system("cls");

		int probability = rand() % 100 + 1;
		int selected;
		
		if (probability <= 40)
			selected = 0;
		else if (probability <= 65)
			selected = 1;
		else if (probability <= 85)
			selected = 2;
		else if (probability <= 95)
			selected = 3;
		else if (probability <= 100)
			selected = 4;

		printWeapon(selected);
		collection[selected] = 1;

		int collectAll = checkCollection();

		if (collectAll)
		{
			printf("축하합니다! 모든 무기를 획득하셨습니다!\n");
			break;
		}
	}

	return 0;
}

void initWeapons()
{
	char* nameArray[5] = { "모험가의 검", "기사의 검", "달인의 검", "명왕의 검", "일륜도" };
	int damageArray[5] = { 45, 150, 1200, 6500, 120000 };
	char* characterArray[5] = {
		"나무와 돌로 만들어져있다",
		"예리한 금속 재질로 이루어져 있다",
		"수많은 몬스터를 베어낸 검",
		"대지의 드래곤을 쓰러트린 명왕이 사용하던 검",
		"목숨을 뭐라고 생각하는거냐"
	};
	int rareArray[5] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++)
	{
		weapon[i].name = nameArray[i];
		weapon[i].damage = damageArray[i];
		weapon[i].character = characterArray[i];
		weapon[i].rareNum = rareArray[i];
	}
}

void printWeapon(int selected)
{
	printf("\n===== 당신이 뽑은 무기 =====\n\n");
	printf("  이름   : %s\n", weapon[selected].name);
	printf(" 공격력  : %d\n", weapon[selected].damage);
	printf("  설명   : %s\n", weapon[selected].character);
	printf(" 희귀도  : ");
	
	for (int i = 0; i < weapon[selected].rareNum; i++)
	{
		printf("★");
	}

	printf("\n\n");
}

int checkCollection()
{
	int collectAll = 1;

	printf("\n\n ===== 보유한 무기 목록 =====\n\n");

	for (int i = 0; i < 5; i++)
	{
		if (collection[i])
		{
			printf("%13s", weapon[i].name);
		}
		else
		{
			printf("%13s", "(비어 있음)");
			collectAll = 0;
		}
	}

	printf("\n\n=============================\n\n");

	return collectAll;
}
