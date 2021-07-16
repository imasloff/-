#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int headX, headY, foodX, foodY, score;
int tailX[100], tailY[100];
int tailCnt;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

eDirection dir;

void putHead() //поставить голову в центр
{
    headX = width / 2;
    headY = height / 2;
}

void putFood() //заспоунить еду
{
    foodX = rand() % width;
    foodY = rand() % height;
}

void Setup() //запустить игру
{
    gameOver = false;
    dir = STOP;
    putHead();
    putFood();
    score = 0;
}

void Draw() //рисуем в консоли построчно
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == headX && j == headY)
                cout << "O";
            else if (i == foodX && j == foodY)
                cout << "@";
            else
            {
                bool tailPrntd = false;
                for (int k = 0; k < tailCnt; k++) //хвост растет, если мы сытно покушали
                {
                    if (tailX[k] == i && tailY[k] == j)
                    {
                        cout << "o";
                        tailPrntd = true;
                    }
                }
                if (!tailPrntd)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input() //читаем направление с клавиатуры, главное - включить английскую раскладку :)
{
    if (_kbhit()) //проверка, нажата ли кнопка на клавиатуре
    {
        switch (_getch())
        {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'q':
            gameOver = true;
            break;
        }
    }
}

void Logic() //а тут магия...
{
    int prevX = tailX[0]; //ну и желательно, чтобы хвост от головы не отрывался
    int prevY = tailY[0];
    int _prevX, _prevY;
    tailX[0] = headX;
    tailY[0] = headY;
    for (int i = 1; i < tailCnt; i++)
    {
        _prevX = tailX[i];
        _prevY = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = _prevX;
        prevY = _prevY;
    }
    switch (dir)
    {
    case UP:
        headX--;
        break;
    case LEFT:
        headY--;
        break;
    case RIGHT:
        headY++;
        break;
    case DOWN:
        headX++;
        break;
    default:
        break;
    }
    if (headX >= width) //учим змейку телепортироваться из одной стены в другую
        headX = 0;
    else if (headX < 0)
        headX = width - 1;
    if (headY >= height)
        headY = 0;
    else if (headY < 0)
        headY = height - 1;
    for (int i = 0; i < tailCnt; i++) //а надо было думать, прежде чем себя за хвост кусать
        if (tailX[i] == headX && tailY[i] == headY)
        { 
            cout << "YOU LOSE!" << endl; //сообщаем игроку, кто он такой на самом деле
            gameOver = true;
        }
    if (headX == foodX && headY == foodY) 
    {
        score++; //зарабатывать же что-то нужно (по единичке, чтобы не расслабляться)
        putFood();
        tailCnt++; //после сытного обеда полагается расти
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
    }
    Sleep(100); //чтобы игрок не сжег слишком много калорий, нажимая на клавиши
    return 0;
}
