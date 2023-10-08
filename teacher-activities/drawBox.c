#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void gotoxy(short x, short y);
void drawbox(int x, int y, int height, int width);
void drawbox_animate(int x, int y, int height, int width);
void drawbox_recursive(int x, int y, int height, int width);
void drawbox_divide(int x, int y, int height, int width);
void drawbox_divide2(int x, int y, int height, int width);

int main()
{
	int x, y, height, width;
	printf("Enter coordinates (x,y): ");
	scanf("%d,%d", &x, &y);
	printf("Enter height: ");
	scanf("%d", &height);
	printf("Enter width: ");
	scanf("%d", &width);
	system("cls");
	drawbox_divide2(x, y, height, width);
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
	gotoxy(0, y + height);
}

void drawbox_animate(int x, int y, int height, int width)
{
	int i;
	
	for (i = 0; i < width; ++i)
	{
		if (i == 0)
		{
			gotoxy(x + i, y);
			printf("%c", 201);
		}
		else if (i == width - 1)
		{
			gotoxy(x + i, y);
			printf("%c", 187);
		}
		else
		{
			gotoxy(x + i, y);
			printf("%c", 205);
		}
		Sleep(150);
	}
	
	for (i = 0; i < height - 2; ++i)
	{
		gotoxy(x + width - 1, y + 1 + i);
		printf("%c", 186);
		Sleep(150);
	}
	
	for (i = width - 1; i >= 0; --i)
	{
		if (i == 0)
		{
			gotoxy(x + i, y + height - 1);
			printf("%c", 200);
		}
		else if (i == width - 1)
		{
			gotoxy(x + i, y + height - 1);
			printf("%c", 188);
		}
		else
		{
			gotoxy(x + i, y + height - 1);
			printf("%c", 205);
		}
		Sleep(150);
	}
	
	for (i = height - 3; i >= 0; --i)
	{
		gotoxy(x, y + 1 + i);
		printf("%c", 186);
		Sleep(150);
	}
	gotoxy(0, y + height);
}

void drawbox_recursive(int x, int y, int height, int width)
{
	if (height < 2 || width < 2)
	{
		return;
	}
	drawbox_animate(x, y, height, width);
	drawbox_recursive(x + 1, y + 1, height - 2, width - 2);
	gotoxy(0, y + height);
}

void drawbox_divide(int x, int y, int height, int width)
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
		else
		{
			gotoxy(x + i, y);
			printf("%c", 205);
			gotoxy(x + i, y + 2);
			printf("%c", 205);
			gotoxy(x + i, y + height - 1);
			printf("%c", 205);
		}
		Sleep(150);
	}
	
	for (i = 0; i < height - 2; ++i)
	{
		if (i != 1)
		{
			gotoxy(x, y + 1 + i);
			printf("%c", 186);
			gotoxy(x + width - 1, y + 1 + i);
			printf("%c", 186);
		}
		Sleep(150);
	}
	gotoxy(0, y + height);
}

void drawbox_divide2(int x, int y, int height, int width)
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
		Sleep(150);
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
		Sleep(150);
	}
	gotoxy(0, y + height);
}
