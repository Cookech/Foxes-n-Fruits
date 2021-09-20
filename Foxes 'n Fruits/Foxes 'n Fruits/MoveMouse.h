void checkClicDot(Point clicDot, int& clicX, int& clicY);
void swapChips(int**& cards_numbers, int& clicX, int& clicY, int& clicX2, int& clicY2);
void checkThirdGenerate(int* ptriples, Point cords, int**& cards_numbers);
int hours = 0;
int minutes = 3;
int seconds = 0;

DWORD WINAPI timer(void* param)
{
    while (true)
    {
        seconds--;
        if (seconds < 0)
        {
            seconds = 59;
            minutes--;
        }
        if (minutes < 0)
        {
            minutes = 59;
            hours--;
        }
        if (hours == 0 && minutes == 0 && seconds == 0)
        {
            //cout << "TIME IS OVER!\n";
            break;
        }
        char* title = new char[200];
        wsprintfA(title, "Foxes 'n Fruits            Time left: %02d:%02d:%02d\n", hours, minutes, seconds);
        SetConsoleTitleA(title);
        delete[] title;
        //printf("%02d:%02d:%02d\n", hours, minutes, seconds);

        Sleep(1000);
    }
    return 0;
}

void mouseMove(int**& cards_numbers, Point cords, int* ptriples, Point clicDot, int& clicX, int& clicY, int& clicX2, int& clicY2, int* tripCheck, int* chipType, Fruits newFruets)
{
    int score = 0;

    int flag = 0;

    *tripCheck = 0;
    *chipType = 0;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // дескриптор окна
    COORD c; // переменная, отвечающая за координаты в консоли
    COORD position;

    position.Y = 0;
    position.X = 100;
    SetConsoleCursorPosition(h, position);
    cout << "Your score: " << score << "\n";

    position.Y = 2;
    position.X = 100;
    SetConsoleCursorPosition(h, position);
    cout << "Your triples: " << *ptriples << "\n";

    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); // дескриптор окна для работы с мышкой
    SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); // установка режима использования мышки

    const int events_count = 256;
    INPUT_RECORD all_events[events_count]; // массив событий, произошедших в консоли
    DWORD read_event; // переменная, в которую запишется количество произошедших событий

    CreateThread(0, 0, timer, 0, 0, 0); // запускаем таймер
    while (hours != 0 || minutes != 0 || seconds != 0) // пока таймер не досчитает до нуля
    {
        ReadConsoleInput(hin, all_events, events_count, &read_event); // получить все события, произошедшие в консоли
        for (int i = 0; i < read_event; i++)
        { // пройтись по всем событиям
            c.X = all_events[i].Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
            c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;

            if (
                all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            { // если нажата ЛЕВАЯ КНОПКА МЫШКИ
                Sleep(60);
                SetConsoleCursorPosition(h, c); // установка координат в то место, где курсор
                //score++;
                if (flag == 0)
                {
                    clicDot.x = c.X;
                    clicDot.y = c.Y;
                    checkClicDot(clicDot, clicX, clicY);
                    //cout << clicX;
                   // cout << clicY;
                    flag = 1;
                }
                else
                {
                    clicDot.x = c.X;
                    clicDot.y = c.Y;
                    checkClicDot(clicDot, clicX2, clicY2);
                    //cout << clicX2;
                    //cout << clicY2;
                    if ((clicX == clicX2 + 1 || clicX == clicX2 - 1) && clicY == clicY2) {
                        swapChips(cards_numbers, clicX, clicY, clicX2, clicY2);
                        redrawField(cords, cards_numbers);
                        checktriples(ptriples, cards_numbers, cords, tripCheck, chipType); // проверка на сложенные тройки
                        flag = 0;
                        if (*tripCheck == 0) {
                            swapChips(cards_numbers, clicX, clicY, clicX2, clicY2);
                            redrawField(cords, cards_numbers);

                        }
                        else {
                            checkChipType(chipType, newFruets);
                            checkThirdGenerate(ptriples, cords, cards_numbers);
                        }
                        *tripCheck = 0;
                        *chipType = 0;
                    }
                    else if ((clicY == clicY2 + 1 || clicY == clicY2 - 1) && clicX == clicX2) {
                        swapChips(cards_numbers, clicX, clicY, clicX2, clicY2);
                        redrawField(cords, cards_numbers);
                        checktriples(ptriples, cards_numbers, cords, tripCheck, chipType); // проверка на сложенные тройки
                        flag = 0;
                        if (*tripCheck == 0) {
                            swapChips(cards_numbers, clicX, clicY, clicX2, clicY2);
                            redrawField(cords, cards_numbers);

                        }
                        else {
                            checkChipType(chipType, newFruets);
                            checkThirdGenerate(ptriples, cords, cards_numbers);
                        }
                        *tripCheck = 0;
                        //*chipType = 0;
                    }
                    else {
                        flag = 0;
                    }
                }

            }
            COORD info{ 0, 0 };
            SetConsoleCursorPosition(h, info);
            cout << "Current cursor position:         ";
            SetConsoleCursorPosition(h, info);
            cout << "Current cursor position: " << c.X << " " << c.Y;

            position.Y = 0;
            position.X = 100;
            SetConsoleCursorPosition(h, position);
            cout << "Your score: " << score << "\n";

            position.Y = 2;
            position.X = 100;
            SetConsoleCursorPosition(h, position);
            cout << "Your triples: " << *ptriples << "\n";

            position.Y = 4;
            position.X = 100;
            SetConsoleCursorPosition(h, position);
            cout << "Your finiki: " << newFruets.finiki1 << "\n";

            position.Y = 6;
            position.X = 100;
            SetConsoleCursorPosition(h, position);
            cout << "Your hazelnut: " << newFruets.hazelnut1 << "\n";

            position.Y = 8;
            position.X = 100;
            SetConsoleCursorPosition(h, position);
            cout << "Your kiwi: " << newFruets.kiwi1<< "\n";

            position.Y = 10;
            position.X = 100;
            SetConsoleCursorPosition(h, position);
            cout << "Your pistachios: " << newFruets.pistachios1<< "\n";

            position.Y = 12;
            position.X = 100;
            SetConsoleCursorPosition(h, position);
            cout << "Your raspberry: " << newFruets.raspberry1 << "\n";
        }
    }
    system("title Foxes 'n Fruits");
    /////////////////////////////////////////////
    // ЗДЕСЬ НАЧИНАЕТСЯ КОД ДЛЯ ОКНА ПРОИГРЫША //
    /////////////////////////////////////////////
    system("cls");
    int startX = 50;
    int startY = 12;
    int margin = 1;
    position.X = startX;
    position.Y = startY;

    SetConsoleCursorPosition(h, position);
    cout << " ***    **    * *   ****";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << "*   *  *  *  * * *  *   ";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << "*      *  *  * * *  *   ";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << "*      ****  *   *  ****";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << "* ***  *  *  *   *  *   ";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << "*   *  *  *  *   *  *   ";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << " ***   *  *  *   *  ****";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << "\n";
    cout << "\n";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << " ***   *  *  ****   *** ";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << "*   *  *  *  *     *   *";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << "*   *  *  *  *     *   *";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << "*   *  *  *  ****  **** ";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << "*   *  *  *  *     *  * ";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << "*   *  *  *  *     *   *";
    position.Y += 1;
    SetConsoleCursorPosition(h, position);
    cout << " ***    **   ****  *   *";
    startX = 60;
    startY = 30;
    margin = 2;
    const int items_cnt = 2;
    string items[items_cnt] = { "TRY AGAIN", "EXIT TO MENU" };
    position.X = startX;
    position.Y = startY;
    for (auto item : items)
    {
        SetConsoleTextAttribute(h, DARK_CYAN);
        SetConsoleCursorPosition(h, position);
        cout << item;
        position.Y += margin;
    }

    int current_item = 0; // new game 
    SetConsoleTextAttribute(h, CYAN);
    position.Y = startY + current_item * margin;
    SetConsoleCursorPosition(h, position);
    cout << items[current_item];

    int code;
    while (true)
    {
        code = _getch();
        if (code == 224)
            code = _getch();

        SetConsoleTextAttribute(h, DARK_CYAN);
        position.Y = startY + current_item * margin;
        SetConsoleCursorPosition(h, position);
        cout << items[current_item];

        if ((code == DOWN || code == RIGHT) && current_item < items_cnt - 1) // down arrow 
        {
            current_item++;
        }
        else if ((code == UP || code == LEFT) && current_item > 0) // up arrow 
        {
            current_item--;
        }
        else if (code == ENTER)
        {
            switch (current_item)
            {
            case 0:
                system("cls");
                //menu();
                startGame(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2, tripCheck, chipType, newFruets);
                break;
            case 1:
                system("cls");
                menu(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2, tripCheck, chipType, newFruets);
                //startGame(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2);
                break;
            default:
                exit(0);
                break;
            }
            break;
        }
        SetConsoleTextAttribute(h, CYAN);
        position.Y = startY + current_item * margin;
        SetConsoleCursorPosition(h, position);
        cout << items[current_item];

    }
}
