#include "Matrix.h"





void lab6task6() {

	string fileName = "Matrix.txt";



	vector<vector<int>> matrix, resultMatrix; //основная матрица, матрица результатов, матрица префикс сумм

	pair<int, int> matrixSize, submatrixSize;

	int summ, count(0);

//	matrixGenerate();

	fileRead(fileName, matrix, matrixSize, submatrixSize, summ);

	resultMatrix = matrix;
	
	vector<vector<int>> prefixSum(matrixSize.first + 1, vector<int>(matrixSize.second + 1));

	cout << "Имеем матрицу:\n";

	printMatrix(matrix, 1, matrixSize.first+1, 1, matrixSize.second+1);

	summatrix(matrix, resultMatrix, matrixSize, submatrixSize, summ, prefixSum, count);

	cout << "\nКоличество подматриц " << submatrixSize.first << "x" << submatrixSize.second << " с суммой " << summ << ": " << count;

}



void summatrix(vector<vector<int>>& matrix, vector<vector<int>>& resultMatrix, pair<int, int> matrixSize, pair<int, int> submatrixSize, int summ, vector<vector<int>> prefixSum, int& count) {

	for (int i = 1; i < matrixSize.first+1; i++) { //заполняем матрицу префикс-суммами

		for (int j = 1; j < matrixSize.second+1; j++) {

			prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i][j];

		}

	}

	resultMatrix = prefixSum; //перезаписываем


	for (int i = submatrixSize.first; i < matrixSize.first+1; i++) { //заполняем матрицу готовыми результатами суммы субматриц

		for (int j = submatrixSize.second; j < matrixSize.second+1; j++) {

			resultMatrix[i][j] = prefixSum[i][j] - prefixSum[i - submatrixSize.first][j] - prefixSum[i][j - submatrixSize.second] + prefixSum[i - submatrixSize.first][j - submatrixSize.second];
			if (resultMatrix[i][j] == summ) { //если сумма набрана

				count++;

				cout << "\n(" << i - submatrixSize.first + 1 << ";" << j - submatrixSize.second + 1 << "), (" << i << ";" << j << ")\n";
				printMatrix(matrix, i - submatrixSize.first + 1, i+1, j - submatrixSize.second + 1, j+1);

			}

		}
	}

}


void fileRead(string fileName, vector<vector<int>>& matrix, pair<int, int>& matrixSize, pair<int, int>& submatrixSize, int& summ) {

	ifstream file;
	file.open("Matrix.txt");

	file >> matrixSize.first >> matrixSize.second >> submatrixSize.first >> submatrixSize.second >> summ;
	
	vector<vector<int>> matrx(matrixSize.first+1, vector<int>(matrixSize.second+1));

	for (int i = 1; i < matrixSize.first+1; i++) {

		for (int j = 1; j < matrixSize.second+1; j++) {

			file >> matrx[i][j];

		}

	}

	matrix = matrx;

	file.close();

}


void printMatrix(vector<vector<int>> matrix, int x1, int x2, int y1, int y2) { //вывод подматрицы 

	for (int x = x1; x < x2; x++) {

		for (int y = y1; y < y2; y++) {

			cout << matrix[x][y] << " ";

		}

		cout << "\n";

	}

}


void matrixGenerate() {

	ofstream file;
	file.open("Matrix.txt");

	for (int i = 0; i < 19; i++) {

		for (int j = 0; j < 14; j++) file << (rand()%103+1)*int(pow(-1, rand()%5)) << " ";

		file << "\n";

	}

	file.close();

}
