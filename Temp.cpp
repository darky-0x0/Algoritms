#include "Temp.h"

std::vector<int> di{ -1, -1, 0, 1, 1, 1, 0, -1 };
std::vector<int> dj{ 0, 1, 1, 1, 0, -1, -1, -1 };
std::vector<std::vector<int>> path;
std::vector<std::vector<int>> minPath;


void walker() {
	int N;
	std::cout << "Введите размерность шахматной доски: "; std::cin >> N;

	system("cls");

	std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));

	int minMoves = 2 * N;

	int countMoves = 0;

	for (int i = 0; i <= (N - 1) / 2; ++i)
	{
		for (int j = 0; j <= (N - 1) / 2; ++j)
		{

			std::cout << "\n" << i << " " << j << "\n";

			board[i][j] = 1;

			path.push_back({ i, j });

			countQueensMoves(i, j, N, countMoves, minMoves, N * N - 1, board, -8);

			path.pop_back();

			board[i][j] = 0;

		}
	}


	printPath(N);
	std::cout << "Минимум " << minMoves << " ходов\n";
}

void countQueensMoves(int i, int j, int& N, int& countMoves, int& minMoves, int numberOfNotPassedFields, std::vector<std::vector<int>>& board, int lastDirection)
{
	if (numberOfNotPassedFields == 0)
	{
		if (countMoves < minMoves)
		{
			minMoves = countMoves;
			if (N == 1) minMoves = 1;
			minPath = path;
		}
	}
	else
	{
		for (int k = 0; k < 8; ++k)
		{
			if (k != lastDirection && k != (lastDirection + 4) % 8)
			{
				int numberOfCompletedFieldsPerTurn = 0;

				for (int w = 1; w < N; ++w)
				{
					int ni = i + w * di[k];

					int nj = j + w * dj[k];

					if (ni >= 0 && ni < N && nj >= 0 && nj < N && board[ni][nj] == 0)
					{
						++numberOfCompletedFieldsPerTurn;

						if (countMoves + 1 < minMoves && minMoves - countMoves - 1 < 2 * ((int)sqrt(numberOfNotPassedFields - numberOfCompletedFieldsPerTurn) + 1))
						{
							++countMoves;

							move(i, j, ni, nj, board, k, countMoves);

							countQueensMoves(ni, nj, N, countMoves, minMoves, numberOfNotPassedFields - numberOfCompletedFieldsPerTurn, board, k);

							cancelMove(i, j, ni, nj, board, k, countMoves);

							--countMoves;

						}
					}
				}
			}
		}
	}
}

void move(int i, int j, int ni, int nj, std::vector<std::vector<int>>& board, int direction, int moveNumber)
{
	do
	{
		i += di[direction];

		j += dj[direction];

		if (board[i][j] == 0)
		{

			board[i][j] = moveNumber;

		}

	} while (i != ni || j != nj);

	path.push_back({ ni, nj });
}

void cancelMove(int i, int j, int ni, int nj, std::vector<std::vector<int>>& board, int direction, int moveNumber)
{
	do
	{
		i += di[direction];

		j += dj[direction];

		if (board[i][j] == moveNumber)
		{

			board[i][j] = 0;

		}

	} while (i != ni || j != nj);

	path.pop_back();
}

void printPath(int N)
{
	for (int i = 0; i < minPath.size(); i++) {

		std::cout << minPath[i][0] * N + minPath[i][1] << " ";

	}

	std::cout << "\n";
}