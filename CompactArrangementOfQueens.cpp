#include "CompactArrangementOfQueens.h"




void lab4task2() {

	cout << "¬ведите размерность шахматной доски: "; int n; cin >> n;

	vector<int> MainField(n * n, 0);

	vector<int> queensField(n, -1);

	vector<int> result(n, -1);

	int fields = 0;

	system("cls");

	CompactArrangementOfQueens(MainField, queensField, n, fields, result);

	cout << fields << "\n";


	vector<int> printArray(n * n, 0);

	int k(0);

	for (int i = 0; i < n * n; i++) {

		if ((k < n) && (result[k] == i)) {

			printArray[i] = 1;

			k++;

		}

	}



	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			cout << printArray[j + (n * i)] << ' ';

		}

		cout << '\n';

	}
}


void CompactArrangementOfQueens(vector<int>& mainField, vector<int>& queensField, int n, int& fields, vector<int>& result) {

	if (n == 0) {

		fields = GetEmpty(mainField);

		result = queensField;

	}

	else {

		int index = 0;

		for (int i = 0; i < queensField.size(); ++i) {

			if (queensField[i] != -1) {

				index = queensField[i] + 1;

			}

		}

		for (int i = index; i < mainField.size(); ++i) {

			NextStep(mainField, queensField, i);

			if (GetEmpty(mainField) <= fields) {

				PreviewStep(mainField, queensField, i);

				continue;

			}

			CompactArrangementOfQueens(mainField, queensField, n - 1, fields, result);

			PreviewStep(mainField, queensField, i);

		}



	}
}

void NextStep(vector<int>& MainField, vector<int>& queensField, int pos) {

	int size = queensField.size();

	int h = pos / queensField.size();

	int v = pos % queensField.size();

	int index;
	for (int i = 0; i < queensField.size(); ++i) {
		index = i + h * size;
		MainField[index]++;
		index = v + i * size;
		MainField[index]++;
	}

	for (int dh = h - 1, dv = v - 1; dh >= 0 && dv >= 0; --dv, --dh) {
		index = dh * size + dv;
		MainField[index]++;
	}

	for (int dh = h - 1, dv = v + 1; dh >= 0 && dv < size; --dh, ++dv) {
		index = dh * size + dv;
		MainField[index]++;
	}


	for (int dh = h + 1, dv = v - 1; dh < size && dv >= 0; ++dh, --dv) {
		index = dh * size + dv;
		MainField[index]++;
	}

	// DOWN RIGHT
	for (int dh = h + 1, dv = v + 1; dh < size && dv < size; ++dh, ++dv) {
		index = dh * size + dv;
		MainField[index]++;
	}

	for (int i = 0; i < queensField.size(); ++i) {
		if (queensField[i] == -1) {
			queensField[i] = pos;
			break;
		}
	}

	MainField[pos] -= 1;
}

void PreviewStep(vector<int>& MainField, vector<int>& queensField, int pos) {

	int size = queensField.size();

	int h = pos / queensField.size();

	int v = pos % queensField.size();

	int index;

	for (int i = 0; i < queensField.size(); ++i) {
		index = i + h * size;
		MainField[index]--;
		index = v + i * size;
		MainField[index]--;
	}

	// UP LEFT
	for (int dh = h - 1, dv = v - 1; dh >= 0 && dv >= 0; --dv, --dh) {
		index = dh * size + dv;
		MainField[index]--;
	}

	// UP RIGHT
	for (int dh = h - 1, dv = v + 1; dh >= 0 && dv < size; --dh, ++dv) {
		index = dh * size + dv;
		MainField[index]--;
	}

	// DOWN LEFT
	for (int dh = h + 1, dv = v - 1; dh < size && dv >= 0; ++dh, --dv) {
		index = dh * size + dv;
		MainField[index]--;
	}

	// DOWN RIGHT
	for (int dh = h + 1, dv = v + 1; dh < size && dv < size; ++dh, ++dv) {
		index = dh * size + dv;
		MainField[index]--;
	}

	for (int i = 0; i < queensField.size(); ++i) {
		if (queensField[i] == pos) {
			queensField[i] = -1;
			break;
		}
	}

	MainField[pos] += 1;

}

int GetEmpty(vector<int> mainField) {

	int count = 0;

	for (int i = 0; i < mainField.size(); ++i) {

		if (!mainField[i]) {

			count++;

		}

	}

	return count;
}