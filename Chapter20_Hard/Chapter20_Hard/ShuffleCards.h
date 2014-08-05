#include <stdlib.h>
#include <time.h>
#include <iostream>
#pragma once

void shuffleCards()
{
	int cards[52];

	for (int i = 0; i < 52; ++i)
	{
		cards[i] = i + 1;
	}

	std::cout << "Original\n";
	for (int i = 0; i < 52; ++i)
	{
		std::cout << cards[i] << " ";
	}
	std::cout << std::endl;

	srand(time(NULL));

	for (int i = 0; i < 51; ++i)
	{
		int index = rand() % (52 - i) + i;

		if (i != index)
		{
			cards[i] ^= cards[index];
			cards[index] ^= cards[i];
			cards[i] ^= cards[index];
		}
	}

	std::cout << "Shuffled\n";
	for (int i = 0; i < 52; ++i)
	{
		std::cout << cards[i] << " ";
	}
	std::cout << std::endl;
}