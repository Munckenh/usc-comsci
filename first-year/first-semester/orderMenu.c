#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(short x, short y);
void drawbox(int x, int y, int height, int width);
void drawmenu(int x, int y, int height, int width);
void cleararea(int x, int y, int height, int width);
void pickmaindish();
void pickbeverage();
void pickdessert();

int main()
{
	drawmenu(0, 0, 20, 41);
	drawbox(0, 20, 3, 41);
	
	gotoxy(17, 1);
	printf("Jollibee");

	gotoxy(21, 3);
	printf("Your order:");
	
	pickmaindish();
	pickbeverage();
	pickdessert();

	cleararea(1, 21, 1, 39);
	gotoxy(1, 21);
	printf("Thank you for ordering!");
	
	gotoxy(0, 23);
	system("pause");
}

void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawbox(int x, int y, int height, int width)
{
	int i;
	
	for (i = 0; i < height - 2; ++i)
	{
		gotoxy(x, y + 1 + i);
		printf("%c", 186);
		gotoxy(x + width - 1, y + 1 + i);
		printf("%c", 186);

	}
	
	for (i = 0; i < width; ++i)
	{
		if (i == 0)
		{
			gotoxy(x, y);
			printf("%c", 201);
			gotoxy(x, y + height - 1);
			printf("%c", 200);			
		}
		else if (i == width - 1)
		{
			gotoxy(x + i, y);
			printf("%c", 187);
			gotoxy(x + i, y + height - 1);
			printf("%c", 188);
		}
		else
		{
			gotoxy(x + i, y);
			printf("%c", 205);
			gotoxy(x + i, y + height - 1);
			printf("%c", 205);
		}
	}
}

void drawmenu(int x, int y, int height, int width)
{
	int i;
	
	for (i = 0; i < width; ++i)
	{
		if (i == 0)
		{
			gotoxy(x, y);
			printf("%c", 201);
			gotoxy(x + i, y + 2);
			printf("%c", 204);
			gotoxy(x, y + height - 1);
			printf("%c", 200);		
		}
		else if (i == width - 1)
		{
			gotoxy(x + i, y);
			printf("%c", 187);
			gotoxy(x + i, y + 2);
			printf("%c", 185);
			gotoxy(x + i, y + height - 1);
			printf("%c", 188);
		}
		else if (i == width / 2)
		{
			gotoxy(x + i, y);
			printf("%c", 205);
			gotoxy(x + i, y + 2);
			printf("%c", 203);
			gotoxy(x + i, y + height - 1);
			printf("%c", 202);
		}
		else
		{
			gotoxy(x + i, y);
			printf("%c", 205);
			gotoxy(x + i, y + 2);
			printf("%c", 205);
			gotoxy(x + i, y + height - 1);
			printf("%c", 205);
		}
	}
	
	for (i = 0; i < height - 2; ++i)
	{
		if (i == 0)
		{
			gotoxy(x, y + 1 + i);
			printf("%c", 186);
			gotoxy(x + width - 1, y + 1 + i);
			printf("%c", 186);
		}
		else if (i > 1)
		{
			gotoxy(x, y + 1 + i);
			printf("%c", 186);
			gotoxy(x + width / 2, y + 1 + i);
			printf("%c", 186);
			gotoxy(x + width - 1, y + 1 + i);
			printf("%c", 186);
		}
	}
	gotoxy(0, height - 1);
}

void cleararea(int x, int y, int height, int width)
{
	int i, j;
	for (i = 0; i < height; ++i)
	{
		gotoxy(x, y + i);
		for (j = 0; j < width; ++j)
		{
			printf(" ");
		}
	}
}

void pickmaindish()
{
	int order;

	gotoxy(1, 3);
	printf("Main dish:");

	gotoxy(1, 4);
	printf("  1 Burger steak");

	gotoxy(1, 5);
	printf("  2 Chickenjoy");

	gotoxy(1, 6);
	printf("  3 Spaghetti");

	gotoxy(1, 7);
	printf("  4 Palabok");

	gotoxy(1, 8);
	printf("  5 Corned beef");


	do
	{
		cleararea(1, 21, 1, 39);
		gotoxy(1, 21);
		printf("Please select your order: ");
		scanf("%d", &order);
	} while (order < 1 || order > 5);

	switch (order)
	{
		case 1:
			gotoxy(23, 4);
			printf("Burger steak");
			break;
		case 2:
			gotoxy(23, 4);
			printf("Chickenjoy");
			break;
		case 3:
			gotoxy(23, 4);
			printf("Spaghetti");
			break;
		case 4:
			gotoxy(23, 4);
			printf("Palabok");
			break;
		case 5:
			gotoxy(23, 4);
			printf("Corned beef");
			break;
		default:
			break;
	}

	cleararea(1, 3, 16, 19);
}

void pickbeverage()
{
	int order;

	gotoxy(1, 3);
	printf("Beverage:");
	gotoxy(1, 4);
	printf("  1 Iced tea");
	gotoxy(1, 5);
	printf("  2 Pineapple juice");
	gotoxy(1, 6);
	printf("  3 Water");
	gotoxy(1, 7);
	printf("  4 Coffee");
	gotoxy(1, 8);
	printf("  5 Soda");

	do
	{
		cleararea(1, 21, 1, 39);
		gotoxy(1, 21);
		printf("Please select your order: ");
		scanf("%d", &order);
	} while (order < 1 || order > 5);

	switch (order)
	{
		case 1:
			gotoxy(23, 5);
			printf("Iced tea");
			break;
		case 2:
			gotoxy(23, 5);
			printf("Pineapple juice");
			break;
		case 3:
			gotoxy(23, 5);
			printf("Water");
			break;
		case 4:
			gotoxy(23, 5);
			printf("Coffee");
			break;
		case 5:
			gotoxy(23, 5);
			printf("Soda");
			break;
		default:
			break;
	}

	cleararea(1, 3, 16, 19);
}

void pickdessert()
{
	int order;

	gotoxy(1, 3);
	printf("Dessert:");
	gotoxy(1, 4);
	printf("  1 Sundae");
	gotoxy(1, 5);
	printf("  2 Peach mango pie");
	gotoxy(1, 6);
	printf("  3 Mango graham");
	gotoxy(1, 7);
	printf("  4 Choco crumble");
	gotoxy(1, 8);
	printf("  5 Halo halo");

	do
	{
		cleararea(1, 21, 1, 39);
		gotoxy(1, 21);
		printf("Please select your order: ");
		scanf("%d", &order);
	} while (order < 1 || order > 5);

	switch (order)
	{
		case 1:
			gotoxy(23, 6);
			printf("Sundae");
			break;
		case 2:
			gotoxy(23, 6);
			printf("Peach mango pie");
			break;
		case 3:
			gotoxy(23, 6);
			printf("Mango graham");
			break;
		case 4:
			gotoxy(23, 6);
			printf("Choco crumble");
			break;
		case 5:
			gotoxy(23, 6);
			printf("Halo halo");
			break;
		default:
			break;
	}

	cleararea(1, 3, 16, 19);
}
