int level = 0;
bool music = true;
bool dark_theme = true;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
HWND hwnd = GetConsoleWindow();

const int items_count = 5;
string menu_items[items_count] = { "START", "GALLERY", "SETTINGS", "ABOUT US", "EXIT" };
const int settings_items_count = 3;
string settings_items[settings_items_count] = { "MUSIC: ON ", "THEME: DARK ", "<BACK" };
enum Colors { DARK_CYAN = 3, CYAN = 63 };
enum Keys { ENTER = 13, ESCAPE = 27, SPACE = 32, LEFT = 75, RIGHT = 77, DOWN = 80, UP = 72 };

void newGame()
{
    system("cls");
}

void menu(int**& cards_numbers, int* ptriples, Point cords, Point clicDot, int& clicX, int& clicY, int& clicX2, int& clicY2, int* tripCheck, int* chipType, Fruits newFruets);

void levelSelect(int**& cards_numbers, int* ptriples, Point cords, Point clicDot, int& clicX, int& clicY, int& clicX2, int& clicY2, int* tripCheck, int* chipType, Fruits newFruets)
{
    system("cls");
    COORD position = { 10, 2 };
    SetConsoleTextAttribute(h, 15);
    SetConsoleCursorPosition(h, position);

    bool menu_started = false;
    const int items_count = 4;
    string menu_items[items_count] = { "Level 1", "Level 2", "Level 3", "<BACK" };

    int startX = 50;
    int startY = 12;
    int margin = 2;

    position.X = startX;
    position.Y = startY;
    for (auto item : menu_items)
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
    cout << menu_items[current_item];

    int code;
    while (true)
    {
        code = _getch();
        if (code == 224)
            code = _getch();

        SetConsoleTextAttribute(h, DARK_CYAN);
        position.Y = startY + current_item * margin;
        SetConsoleCursorPosition(h, position);
        cout << menu_items[current_item];

        if ((code == DOWN || code == RIGHT) && current_item < items_count - 1) // down arrow 
        {
            current_item++;
        }
        else if ((code == UP || code == LEFT) && current_item > 0) // up arrow 
        {
            current_item--;
        }
        else if (code == ENTER)
        {
            menu_started = true;
            switch (current_item)
            {
            case 0:
                level = 1;
                system("cls");
                startGame(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2, tripCheck, chipType, newFruets);
                break;
            case 1:
                level = 2;
                system("cls");

                break;
            case 2:
                level = 3;
                system("cls");

                break;
            case 3:
                system("cls");
                menu(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2, tripCheck, chipType, newFruets);
                break;
            default:
                exit(0);
                break;
            }
            break;
        }
        if (menu_started == false)
        {
            SetConsoleTextAttribute(h, CYAN);
            position.Y = startY + current_item * margin;
            SetConsoleCursorPosition(h, position);
            cout << menu_items[current_item];
        }

    }
}

void gallery(int**& cards_numbers, int* ptriples, Point cords, Point clicDot, int& clicX, int& clicY, int& clicX2, int& clicY2, int* tripCheck, int* chipType, Fruits newFruets)
{
    system("cls");
    int startX = 50;
    int startY = 12;
    int margin = 2;

    COORD position = { startX, startY };
    SetConsoleTextAttribute(h, DARK_CYAN);
    SetConsoleCursorPosition(h, position);
    cout << "Here will be the gallery (maybe)";
    position.Y += margin;
    SetConsoleTextAttribute(h, CYAN);
    SetConsoleCursorPosition(h, position);
    cout << "<BACK";
    SetConsoleTextAttribute(h, DARK_CYAN);
    int code;
    while (true)
    {
        code = _getch();
        if (code == 224)
            code = _getch();

        if (code == ENTER)
        {
            system("cls");
            menu(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2, tripCheck, chipType, newFruets);
            break;
        }
    }
}

void settings(int**& cards_numbers, int* ptriples, Point cords, Point clicDot, int& clicX, int& clicY, int& clicX2, int& clicY2, int* tripCheck, int* chipType, Fruits newFruets)
{
    system("cls");
    COORD position = { 10, 2 };
    SetConsoleTextAttribute(h, 15);
    SetConsoleCursorPosition(h, position);

    int startX = 50;
    int startY = 12;
    int margin = 2;

    position.X = startX;
    position.Y = startY;
    for (auto item : settings_items)
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
    cout << settings_items[current_item];

    int code;
    while (true)
    {
        bool button_trigger = false;
        code = _getch();
        if (code == 224)
            code = _getch();

        SetConsoleTextAttribute(h, DARK_CYAN);
        position.Y = startY + current_item * margin;
        SetConsoleCursorPosition(h, position);
        cout << settings_items[current_item];

        if ((code == DOWN || code == RIGHT) && current_item < settings_items_count - 1) // down arrow 
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
                button_trigger = true;
                if (music == true)
                {
                    music = false;
                    SetConsoleTextAttribute(h, CYAN);
                    position.Y = startY + current_item * margin;
                    SetConsoleCursorPosition(h, position);
                    cout << "MUSIC: OFF";
                    settings_items[0] = "MUSIC: OFF";
                }
                else
                {
                    music = true;
                    SetConsoleTextAttribute(h, CYAN);
                    position.Y = startY + current_item * margin;
                    SetConsoleCursorPosition(h, position);
                    cout << "MUSIC: ON ";
                    settings_items[0] = "MUSIC: ON ";
                }
                break;
            case 1:
                button_trigger = true;
                if (dark_theme == true)
                {
                    dark_theme = false;
                    SetConsoleTextAttribute(h, CYAN);
                    position.Y = startY + current_item * margin;
                    SetConsoleCursorPosition(h, position);
                    cout << "THEME: LIGHT";
                    settings_items[1] = "THEME: LIGHT";
                }
                else
                {
                    dark_theme = true;
                    SetConsoleTextAttribute(h, CYAN);
                    position.Y = startY + current_item * margin;
                    SetConsoleCursorPosition(h, position);
                    cout << "THEME: DARK ";
                    settings_items[1] = "THEME: DARK ";
                }
                break;
            case 2:
                system("cls");
                menu(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2, tripCheck, chipType, newFruets);
                break;
            default:
                exit(0);
                break;
            }
            if (button_trigger == false)
            {
                break;
            }
        }
        if (button_trigger == false)
        {
            SetConsoleTextAttribute(h, CYAN);
            position.Y = startY + current_item * margin;
            SetConsoleCursorPosition(h, position);
            cout << settings_items[current_item];
        }

    }
}

void aboutUs(int**& cards_numbers, int* ptriples, Point cords, Point clicDot, int& clicX, int& clicY, int& clicX2, int& clicY2, int* tripCheck, int* chipType, Fruits newFruets)
{
    system("cls");
    int startX = 50;
    int startY = 12;
    int margin = 2;

    COORD position = { startX, startY };
    SetConsoleTextAttribute(h, DARK_CYAN);
    SetConsoleCursorPosition(h, position);
    cout << "Here will be some information about the authors (maybe)";
    position.Y += margin;
    SetConsoleTextAttribute(h, CYAN);
    SetConsoleCursorPosition(h, position);
    cout << "<BACK";
    SetConsoleTextAttribute(h, DARK_CYAN);
    int code;
    while (true)
    {
        code = _getch();
        if (code == 224)
            code = _getch();

        if (code == ENTER)
        {
            system("cls");
            menu(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2, tripCheck, chipType, newFruets);
            break;
        }
    }
}

void quit()
{
    exit(0);
}

void menu(int**& cards_numbers, int* ptriples, Point cords, Point clicDot, int& clicX, int& clicY, int& clicX2, int& clicY2, int* tripCheck, int* chipType, Fruits newFruets)
{

    int startX = 50;
    int startY = 12;
    int margin = 2;

    COORD position = { startX, startY };
    for (auto item : menu_items)
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
    cout << menu_items[current_item];

    int code;
    while (true)
    {
        code = _getch();
        if (code == 224)
            code = _getch();

        SetConsoleTextAttribute(h, DARK_CYAN);
        position.Y = startY + current_item * margin;
        SetConsoleCursorPosition(h, position);
        cout << menu_items[current_item];

        if ((code == DOWN || code == RIGHT) && current_item < items_count - 1) // down arrow
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
                levelSelect(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2, tripCheck, chipType, newFruets);
                break;
            case 1:
                gallery(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2, tripCheck, chipType, newFruets);
                break;
            case 2:
                settings(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2, tripCheck, chipType, newFruets);
                break;
            case 3:
                aboutUs(cards_numbers, ptriples, cords, clicDot, clicX, clicY, clicX2, clicY2, tripCheck, chipType, newFruets);
                break;
            case 4:
                quit();
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
        cout << menu_items[current_item];
    }
}
