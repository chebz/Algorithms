#include <iostream>
using namespace std;

struct Board
{
	enum GameState { ready, ended };

	GameState state;
	int data[9];
	int playerTurn;
	int available;

	Board()
	{
		for (int i = 0; i < 9; ++i)
			data[i] = 0;
		state = GameState::ready;
		playerTurn = 1;
		available = 9;
		printBoard();
	}

	void printBoard()
	{
		for(int y = 0; y < 3; ++y)
		{
			for (int x = 0; x < 3; ++x)
			{
				int index = y * 3 + x;
				cout << data[index] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	bool play(int player, int x, int y)
	{
		if (player != playerTurn)
			return false;

		if (x < 0 || x > 2)
			return false;
		if (y < 0 || y > 2)
			return false;

		int index = y * 3 + x;

		if (data[index] != 0)
			return false;

		data[index] = player;
		available--;

		printBoard();

		if (checkWin(player))
		{
			state = GameState::ended;
			cout << "player " << player << " wins!\n";			
		}
		else
		{
			playerTurn = 3 - player;

			if (available == 0)
				state = GameState::ended;
		}
		return true;		
	}

	bool checkWin(int player)
	{
		if (checkRows(player))
			return true;
		if (checkCols(player))
			return true;
		if (checkDiags(player))
			return true;

		return false;
	}

	bool checkRows(int player)
	{
		bool win = false;

		for (int y = 0; y < 3; ++y)
		{
			win = true;

			for (int x = 0; x < 3; ++x)
			{
				int index = y * 3 + x;

				if (data[index] != player)
				{
					win = false;
					break;
				}
			}

			if (win)
				break;
		}

		return win;
	}

	bool checkCols(int player)
	{
		bool win = false;

		for (int x = 0; x < 3; ++x)
		{
			win = true;

			for (int y = 0; y < 3; ++y)
			{
				int index = y * 3 + x;

				if (data[index] != player)
				{
					win = false;
					break;
				}
			}

			if (win)
				break;
		}

		return win;
	}

	bool checkDiags(int player)
	{
		if (data[0] == player && data[0] == data[4] && data[4] == data[8])
			return true;

		if (data[2] == player && data[2] == data[4] && data[4] == data[6])
			return true;

		return false;
	}
};

void playTicTacToe()
{
	Board b;

	while (b.state != Board::GameState::ended)
	{
		cout << "Player " << b.playerTurn << " turn\n";
		int x, y;
		cout << "Enter x: ";
		cin >> x;
		cout << "Enter y: ";
		cin >> y;
		b.play(b.playerTurn, x, y);
	}
}