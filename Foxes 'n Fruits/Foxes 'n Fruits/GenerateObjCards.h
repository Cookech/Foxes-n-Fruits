void generateObj(int**& cards_numbers, Point cords)
{
    for (int i = 0; i < cords.y; i++)
    {
        for (int j = 0; j < cords.x; j++)
        {
            cards_numbers[i][j] = rand() % 5 + 1; // заполн€ем поле случайными числами
        }
    }
}

void generateCards(int card_num, int**& cards_numbers)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    int height = 5;
    int wigth = 8;
    int card_row = 1;
    int card_col = 1;
    position.X = 1;
    position.Y = 1;
    SetConsoleCursorPosition(h, position);
    if (card_num == 30)
    {

        for (int i = 0; i < card_num; i++)
        {
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < wigth; x++)
                {
                    if (x == 0 && y == 0)
                    {
                        cout << char(218);
                    }
                    else if (x == 0 && y == height - 1)
                    {
                        cout << char(192);
                    }
                    else if (x == wigth - 1 && y == 0)
                    {
                        cout << char(191);
                    }
                    else if (x == wigth - 1 && y == height - 1)
                    {
                        cout << char(217);
                    }
                    else if (x == 0 || x == wigth - 1)
                    {
                        cout << char(179);
                    }
                    else if (y == 0 || y == height - 1)
                    {
                        cout << char(196);
                    }
                    else if (x == wigth / 2 && y == height / 2)
                    {
                        if (card_row == 1 && card_col > 1)
                        {
                            cout << cards_numbers[card_col - 1][5];
                        }
                        else if (card_row != 1 && card_col > 1)
                        {
                            cout << cards_numbers[card_col - 1][card_row - 2];
                        }
                        else
                        {
                            cout << cards_numbers[card_col - 1][card_row - 1];
                        }

                    }
                    else
                    {
                        cout << " ";
                    }
                }
                position.Y++;
                SetConsoleCursorPosition(h, position);
            }  // отрисовка 1 €чейки
            //Sleep(1000);
            if (card_row > 6) { // переход на первую карту р€да
                card_col++;
                card_row = 1;
            }
            if (card_row < 6 && card_col == 1) { // отрислвка 1 р€да
                position.Y = 1;
                position.X = 1 + wigth * card_row;
                SetConsoleCursorPosition(h, position);
                card_row++;
            }
            else if (card_row < 6 && card_col > 1) { // отрислвка €чеек не 1 р€да
                if (card_row == 1) {
                    position.Y = 1 + height * (card_col - 1);
                    position.X = 1;
                    SetConsoleCursorPosition(h, position);
                    card_row++;
                }
                else if (card_row < 6) {
                    position.Y = 1 + height * (card_col - 1);
                    position.X = 1 + wigth * (card_row - 1);
                    SetConsoleCursorPosition(h, position);
                    card_row++;
                }

            }
            else if (card_row == 6) { // переход на последнюю €чейку р€да ниже 
                position.Y = 1 + height * card_col;
                position.X = 1 + wigth * (card_row - 1);
                SetConsoleCursorPosition(h, position);
                card_row = 1;
                card_col++;
            }
        }
    }

    //Sleep(INFINITE);
}
