#include <iostream>
#include <ctime> 
#include <conio.h>
#include <Windows.h>  // allows sleep function
using namespace std; 

bool gameOver ; // global variable

const int width = 30;   // map
const int height = 20;  // map
int x, y, fruitX, fruitY, score;  // fruit variables and score
int tailX[100], tailY[100];
int nTail; 
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = STOP ; 
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;   // rand is a random number 
	fruitY = rand() % height; 
	score = 0;
}
void Draw()
{
	system("cls"); //system("clear");
	for (int i = 0; i < width+2; i++)   // walls
		cout << "#";
	cout << endl; 

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "V";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k= 0; k < nTail; k++)
				{ 
					if (tailX[k] == j && tailY[k] == i) 
					{
						cout << "o";
						print = true; 
					}
					
				}
				if (!print)
					cout << " ";
			}
				cout << " ";

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}


	for (int i = 0; i < width+2; i++)   // bottom walls
		cout << "#";
	cout << endl; 
	cout << "Score: " << score << endl;
}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':               // controls for movement
			dir = LEFT;
			break; 
		case 'd':
			dir = RIGHT;
			break; 
		case 'w':
			dir = UP;
			break; 
		case 's':
			dir = DOWN;
			break; 
		case 'x':
			gameOver = false;     // X ends the Game true will turn this on
			break; 
		}
	}
}
void Logic()
{
	int prevX = tailX[0];    // remembers previous coordinate
	int prevY = tailY[0];
	int prev2X, prev2Y; 
	tailX[0] = x;      // helps the tail follow the head
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)   // movement of tail
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX; 
		tailY[i] = prevY; 
		prevX = prev2X;
		prevY = prev2Y;


	}
	switch (dir)
	{
	case LEFT:
		x--; // decrease X value by left movement
		break;
	case RIGHT:
		x++; // increase X value by right movement
		break;
	case UP:
		y--;
		break;  // commands should always be above the break;
	case DOWN:
		y++; // 
		break;
	default:
		break;
	}
	if (x > width || x < 0 || y > height || y < 0 )  // these things tell the game to start over
		gameOver = false; // turn to true if you want game to end when you hit walls
	if (x >= width) x = 0; else if (x < 0) x = width - 1;  // this allows you to go through the wall
	if (y >= height) y = 0; else if (y < 0) y = height - 1; // this allows you to go through the wall 
	for (int i = 0; i < nTail; i++)  // if tail hits anything gameover
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	if (x == fruitX && y == fruitY)

	{
		score += 100;
		fruitX = rand() % width; 
		fruitY = rand() % height;
		nTail++; // increases tail of snake by 1 when fruit is eaten
	}
}
int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(70); //sleep() slows down the game
	}
	return 0;
}