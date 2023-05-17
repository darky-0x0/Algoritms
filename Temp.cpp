#include "Temp.h"
int turn = 0;
void second_solve() {

	int n; cout << "Enter size: "; cin >> n;

	vector<int> board(n * n, 0);

	vector<int> queens(n, -1);

	vector<int> result(n, -1);

	int fields = 0;

	second_solve(board, queens, n, fields, result);

	print_field(result, fields);
}

void second_solve(vector<int>& board, vector<int>& queens, int N, int& result, vector<int>& result_queens)
{
	if (N == 0) {

		result = get_empty(board);

		result_queens = queens;
	}
	else {

		int index = 0;

		for (int i = 0; i < queens.size(); ++i) {

			if (queens[i] != -1) {

				index = queens[i] + 1;

			}

		}

		for (int i = index; i < board.size(); ++i) {

			place_queen(board, queens, i);



			if (get_empty(board) <= result) {

				remove_queen(board, queens, i);

				continue;

			}

			//cout << turn++ << endl;
			/*print(queens);
			_getch();*/

			second_solve(board, queens, N - 1, result, result_queens);

			remove_queen(board, queens, i);
		}

	}

}

int get_empty(vector<int> board) {

	int count = 0;
	for (int i = 0; i < board.size(); ++i) {

		if (!board[i]) {

			count++;

		}

	}
	return count;
}

void print_field(vector<int>& queens, int result) {

	int k = 0;

	for (int i = 0; i < queens.size() * queens.size(); ++i) {

		if (i % queens.size() == 0) {
			cout << endl;
		}
		if (k != queens.size() && queens[k] == i) {

			cout << "F ";

			k++;

			continue;

		}

		cout << "- ";
	}
	cout << "Max empty fields is - " << result << endl;
}

void place_queen(vector<int>& board, vector<int>& queens, int pos) {

	int size = queens.size();

	int h = pos / queens.size();

	int v = pos % queens.size();

	int index;

	for (int i = 0; i < queens.size(); ++i) {

		index = i + h * size;



		board[index]++;



		index = v + i * size;



		board[index]++;



	}

	// UP LEFT
	for (int dh = h - 1, dv = v - 1; dh >= 0 && dv >= 0; --dv, --dh) {

		index = dh * size + dv;

		board[index]++;

	}

	// UP RIGHT
	for (int dh = h - 1, dv = v + 1; dh >= 0 && dv < size; --dh, ++dv) {
		index = dh * size + dv;

		board[index]++;

	}

	// DOWN LEFT
	for (int dh = h + 1, dv = v - 1; dh < size && dv >= 0; ++dh, --dv) {

		index = dh * size + dv;


		board[index]++;


	}

	// DOWN RIGHT
	for (int dh = h + 1, dv = v + 1; dh < size && dv < size; ++dh, ++dv) {
		index = dh * size + dv;

		board[index]++;

	}

	for (int i = 0; i < queens.size(); ++i) {

		if (queens[i] == -1) {

			queens[i] = pos;

			break;

		}

	}

	board[pos] -= 1; // 1 ÐÀÇ ß ÓÂÅËÈ×ÈÂÀË ÏÎÇÈÖÈÞ ÊÎÐÎËÅÂÛ
}

void remove_queen(vector<int>& board, vector<int>& queens, int pos) {

	int size = queens.size();

	int h = pos / queens.size();

	int v = pos % queens.size();

	int index;

	for (int i = 0; i < queens.size(); ++i) {

		index = i + h * size;


		board[index]--;



		index = v + i * size;



		board[index]--;



	}

	// UP LEFT
	for (int dh = h - 1, dv = v - 1; dh >= 0 && dv >= 0; --dv, --dh) {

		index = dh * size + dv;


		board[index]--;

	}

	// UP RIGHT
	for (int dh = h - 1, dv = v + 1; dh >= 0 && dv < size; --dh, ++dv) {
		index = dh * size + dv;

		board[index]--;

	}

	// DOWN LEFT
	for (int dh = h + 1, dv = v - 1; dh < size && dv >= 0; ++dh, --dv) {

		index = dh * size + dv;


		board[index]--;


	}

	// DOWN RIGHT
	for (int dh = h + 1, dv = v + 1; dh < size && dv < size; ++dh, ++dv) {
		index = dh * size + dv;

		board[index]--;

	}

	for (int i = 0; i < queens.size(); ++i) {

		if (queens[i] == pos) {

			queens[i] = -1;

			break;

		}

	}

	board[pos] += 1;

}

void print(vector<int>& queens) {

	int k = 0;

	for (int i = 0; i < queens.size() * queens.size(); ++i) {

		if (i % queens.size() == 0) {

			cout << endl;

		}

		if (k != queens.size() && queens[k] == i) {

			cout << "F ";

			k++;

			continue;

		}

		cout << "- ";

	}
}