void deleteChip(int**& cards_numbers, int card_numX, int card_numY)
{
    cards_numbers[card_numX][card_numY] = 0;
    //cout << cards_numbers[card_numX][card_numY];
}

void swapChips(int**& cards_numbers, int& clicX, int& clicY, int& clicX2, int& clicY2) {
    int t = cards_numbers[clicY][clicX];
    cards_numbers[clicY][clicX] = cards_numbers[clicY2][clicX2];
    cards_numbers[clicY2][clicX2] = t;
}
