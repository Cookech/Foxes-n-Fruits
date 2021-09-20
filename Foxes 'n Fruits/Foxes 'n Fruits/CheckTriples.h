void deleteChip(int**& cards_numbers, int card_numX, int card_numY);
void redrawField(Point cords, int**& cards_numbers);

void checktriples(int* triples, int**& cards_numbers, Point cords, int* tripCheck, int* chipType)
{
	for (int j = 0; j <= cords.x - 3; j++)
	{
		for (int i = 0; i <= cords.y - 1; i++)
		{
			if (cards_numbers[i][j] == cards_numbers[i][j + 1] && cards_numbers[i][j] == cards_numbers[i][j + 2] && cards_numbers[i][j] != 0)
			{
				*tripCheck = 1;
				*chipType = cards_numbers[i][j];
				deleteChip(cards_numbers, i, j);
				deleteChip(cards_numbers, i, j + 1);
				deleteChip(cards_numbers, i, j + 2);
				redrawField(cords, cards_numbers);
				(*triples)--;
				cout << *chipType;
			}
		}
	} //  проверка по горизонтали

	for (int j = 0; j <= cords.x - 1; j++)
	{
		for (int i = 0; i <= cords.y - 3; i++)
		{
			if (cards_numbers[i][j] == cards_numbers[i + 1][j] && cards_numbers[i][j] == cards_numbers[i + 2][j] && cards_numbers[i][j] != 0)
			{
				(*triples)--;
				deleteChip(cards_numbers, i, j);
				deleteChip(cards_numbers, i + 1, j);
				deleteChip(cards_numbers, i + 2, j);
				redrawField(cords, cards_numbers);
			}
		}
	} // проверка по вертикали
}

void checktriplesOpport(int* triples, int**& cards_numbers, Point cords)
{
	for (int i = 0; i < cords.x - 1; i++)
	{
		for (int j = 0; j < cords.y - 3; j++)
		{
			if (cards_numbers[i][j] == cards_numbers[i][j + 1] == cards_numbers[i][j + 3] && cards_numbers[i][j] != 0)
			{

				(*triples)++;
			}
			if (cards_numbers[i][j] == cards_numbers[i][j + 2] == cards_numbers[i][j + 3] && cards_numbers[i][j] != 0)
			{

				(*triples)++;
			}
		}

	} // проверка по вертикали

	for (int i = 0; i < cords.x - 2; i++)
	{
		for (int j = 0; j < cords.y - 2; j++)
		{
			if (cards_numbers[i][j] == cards_numbers[i][j + 1] == cards_numbers[i + 1][j + 2] && cards_numbers[i][j] != 0)
			{

				(*triples)++;
			}
		}

	} // проверка по вертикали

	for (int i = 0; i < cords.x - 2; i++)
	{
		for (int j = 0; j < cords.y - 2; j++)
		{
			if (cards_numbers[i + 1][j] == cards_numbers[i][j + 1] == cards_numbers[i][j + 2] && cards_numbers[i][j] != 0)
			{

				(*triples)++;
			}
		}

	} // проверка по вертикали

	for (int i = 1; i < cords.x - 1; i++)
	{
		for (int j = 0; j < cords.y - 2; j++)
		{
			if (cards_numbers[i][j] == cards_numbers[i][j + 1] == cards_numbers[i - 1][j + 2] && cards_numbers[i][j] != 0)
			{

				(*triples)++;
			}
		}

	} // проверка по вертикали

	for (int i = 1; i < cords.x - 1; i++)
	{
		for (int j = 0; j < cords.y - 2; j++)
		{
			if (cards_numbers[i - 1][j] == cards_numbers[i][j + 1] == cards_numbers[i][j + 2] && cards_numbers[i][j] != 0)
			{

				(*triples)++;
			}
		}

	} // проверка по вертикали

	for (int i = 0; i < cords.x - 2; i++)
	{
		for (int j = 0; j < cords.y - 3; j++)
		{
			if (cards_numbers[i][j] == cards_numbers[i + 1][j + 1] == cards_numbers[i][j + 2] && cards_numbers[i][j] != 0)
			{

				(*triples)++;
			}
		}

	} // проверка по вертикали

	for (int i = 1; i < cords.x - 2; i++)
	{
		for (int j = 0; j < cords.y - 3; j++)
		{
			if (cards_numbers[i][j] == cards_numbers[i - 1][j + 1] == cards_numbers[i][j + 2] && cards_numbers[i][j] != 0)
			{

				(*triples)++;
			}
		}

	} // проверка по вертикали

	for (int j = 0; j < cords.y - 1; j++)
	{
		for (int i = 0; i < cords.x - 4; i++)
		{
			if (cards_numbers[i][j] == cards_numbers[i + 1][j] == cards_numbers[i + 3][j] && cards_numbers[i][j] != 0)
			{
				(*triples)++;
			}
			if (cards_numbers[i][j] == cards_numbers[i + 2][j] == cards_numbers[i + 3][j] && cards_numbers[i][j] != 0)
			{
				(*triples)++;
			}
		}
	} // проверка по горизонтали

	for (int j = 1; j < cords.y - 1; j++)
	{
		for (int i = 0; i < cords.x - 3; i++)
		{
			if (cards_numbers[i][j] == cards_numbers[i + 1][j] == cards_numbers[i + 2][j + 1] && cards_numbers[i][j] != 0)
			{
				(*triples)++;
			}
		}
	} // проверка по горизонтали

	for (int j = 0; j < cords.y - 2; j++)
	{
		for (int i = 0; i < cords.x - 3; i++)
		{
			if (cards_numbers[i][j + 1] == cards_numbers[i + 1][j] == cards_numbers[i + 2][j] && cards_numbers[i][j] != 0)
			{
				(*triples)++;
			}
		}
	} // проверка по горизонтали
	for (int j = 1; j < cords.y - 1; j++)
	{
		for (int i = 0; i < cords.x - 3; i++)
		{
			if (cards_numbers[i][j - 1] == cards_numbers[i + 1][j] == cards_numbers[i + 2][j] && cards_numbers[i][j] != 0)
			{
				(*triples)++;
			}
		}
	} // проверка по горизонтали

	for (int j = 0; j < cords.y - 2; j++)
	{
		for (int i = 0; i < cords.x - 3; i++)
		{
			if (cards_numbers[i][j] == cards_numbers[i + 1][j + 1] == cards_numbers[i + 2][j] && cards_numbers[i][j] != 0)
			{
				(*triples)++;
			}
		}
	} // проверка по горизонтали

	for (int j = 1; j < cords.y - 1; j++)
	{
		for (int i = 0; i < cords.x - 3; i++)
		{
			if (cards_numbers[i][j] == cards_numbers[i + 1][j - 1] == cards_numbers[i + 2][j] && cards_numbers[i][j] != 0)
			{
				(*triples)++;
			}
		}
	} // проверка по горизонтали
}

void checkChipType(int* chipType, Fruits newFruets) {
	cout << *chipType;
	switch (*chipType) 
	{
	case 1:
		newFruets.finiki1 += 3;
		cout << newFruets.finiki1;
		Sleep(1000);
		break;
	case 2:
		newFruets.hazelnut1 += 3;
		cout << newFruets.hazelnut1;
		Sleep(1000);
		break;
	case 3:
		newFruets.kiwi1 += 3;
		cout << newFruets.kiwi1;
		Sleep(1000);
		break;
	case 4:
		newFruets.pistachios1 += 3;
		cout << newFruets.pistachios1;
		Sleep(1000);
		break;
	case 5:
		newFruets.raspberry1 += 3;
		cout << newFruets.raspberry1;
		Sleep(1000);
		break;
	default:
		break;
	}
}