
#include <iostream> 
#include <windows.h> 
#include <conio.h> 
#include <string> 
#include <ctime> 
using namespace std;

struct Point
{
    int x;
    int y;
}; // для хранения кординат в будущем

struct Fruits
{
    //счётчик для фишек
    int finiki = 0;
    int pistachios = 0;
    int hazelnut = 0;
    int kiwi = 0;
    int raspberry = 0;

    //ссылки
    int& finiki1 = finiki;
    int& pistachios1 = pistachios;
    int& hazelnut1 = hazelnut;
    int& kiwi1 = kiwi;
    int& raspberry1 = raspberry;
};

void startGame(int**& cards_numbers, int* ptriples, Point cords, Point clicDot, int& clicX, int& clicY, int& clicX2, int& clicY2, int* tripCheck, int* chipType, Fruits newFruets);

#include "GenerateObjCards.h"
#include "CheckTriples.h"
#include "Menu.h"
#include "MoveMouse.h"
#include "CheckThirdGenerate.h"
#include "DeleteChip.h"
#include "Intro.h"
#include "CheckClicDot.h"

void generateObj(int**& cards_numbers, Point cords); // генерация разных типов фишек

void generateCards(int card_num, int**& cards_numbers); // генерация игрового поля

void checktriples(int* triples, int**& cards_numbers, Point cords, int* tripCheck, int* chipType); // проверка на наличие сложенных троек

void mouseMove(int**& cards_numbers, Point cords, int* ptriples, Point clicDot, int& clicX, int& clicY, int& clicX2, int& clicY2, int* tripCheck, int* chipType, Fruits newFruets); // отслеживание курсора мыши

void startGame(int**& cards_numbers, int* ptriples, Point cords, Point clicDot, int& clicX, int& clicY, int& clicX2, int& clicY2, int* tripCheck, int* chipType, Fruits newFruets)
{
    generateObj(cards_numbers, cords); // заполнение 2д массива случайными числами
    generateCards(30, cards_numbers); // отрисовка поля
    checktriplesOpport(ptriples, cards_numbers, cords);
    checkThirdGenerate(ptriples, cords, cards_numbers); // проверка на возможность сложить тройки, иначе - обновляем поле
    //Sleep(5000);
    checktriples(ptriples, cards_numbers, cords, tripCheck, chipType); // проверка на сложенные тройки
    mouseMove(cards_numbers, cords, ptriples, clicDot, clicX, clicY, clicX2, clicY2, tripCheck, chipType, newFruets); // отслеживание координат курсора
}

int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.bVisible = false;
    info.dwSize = 100;
    SetConsoleCursorInfo(h, &info); // прячем курсор

    COORD c; // переменная, отвечающая за координаты в консоли
    COORD position;

    system("title Three in line"); // название окна
    MoveWindow(GetConsoleWindow(), 0, 0, 1800, 1000, true); // размер окна

    srand(time(0)); // делаем рандом рандомным
    rand();

    //animation(); // анимация заставки

    Point cords;
    cords.x = 6;
    cords.y = 5;

    Point clicDot;
    clicDot.x = 0;
    clicDot.y = 0;

    int& clicX = clicDot.x;
    int& clicY = clicDot.y;

    Point clicDot2;
    clicDot2.x = 0;
    clicDot2.y = 0;

    int& clicX2 = clicDot2.x;
    int& clicY2 = clicDot2.y;

    int** cards_numbers = new int* [cords.y]; // временное обозначение карт на поле

    int triples = 0;
    int* ptriples = &triples;

    int tripCheck = 0;
    int chipType = 0;

    Fruits newFruets;
    newFruets.finiki = 0;
    newFruets.hazelnut = 0;
    newFruets.kiwi = 0;
    newFruets.pistachios = 0;
    newFruets.raspberry = 0;

    for (int y = 0; y < cords.y; y++)
    {
        cards_numbers[y] = new int[cords.y]{};
    }

    menu(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2, &tripCheck, &chipType, newFruets); //выводим меню 
    //startGame(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2);
    /*
    generateObj(cards_numbers, cords); // заполнение 2д массива случайными числами
    generateCards(30, cards_numbers); // отрисовка поля
    checktriplesOpport(ptriples, cards_numbers, cords);
    checkThirdGenerate(ptriples, cords, cards_numbers); // проверка на возможность сложить тройки, иначе - обновляем поле
    //Sleep(5000);
    checktriples(ptriples, cards_numbers, cords); // проверка на сложенные тройки
    mouseMove(cards_numbers, cords, ptriples, clicDot, clicX, clicY, clicX2, clicY2); // отслеживание координат курсора
    */
}
