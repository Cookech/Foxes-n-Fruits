void checkThirdGenerate(int* ptriples, Point cords, int**& cards_numbers) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.bVisible = false;
    info.dwSize = 100;
    SetConsoleCursorInfo(h, &info);

    COORD c; // переменная, отвечающая за координаты в консоли
    COORD position;

    while (*ptriples == 0) {
        position.Y = 1;
        position.X = 1;
        SetConsoleCursorPosition(h, position);
        for (; position.Y < 100; position.Y++) {
            for (; position.X < 99; position.X++) {
                cout << " ";
            }
        }


        //Sleep(1000);
        generateObj(cards_numbers, cords);
        generateCards(30, cards_numbers);
        checktriplesOpport(ptriples, cards_numbers, cords);
    }
}


void redrawField(Point cords, int**& cards_numbers) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.bVisible = false;
    info.dwSize = 100;
    SetConsoleCursorInfo(h, &info);

    COORD c; // переменная, отвечающая за координаты в консоли
    COORD position;

    position.Y = 1;
    position.X = 1;
    SetConsoleCursorPosition(h, position);
    for (; position.Y < 100; position.Y++) {
        for (; position.X < 99; position.X++) {
            cout << " ";
        }
    }

    generateCards(30, cards_numbers);
}
