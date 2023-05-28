#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>
#include <cmath>x
using namespace std;



/// <summary>
/// Задача о матрице
/// </summary>
void lab6task6();


/// <summary>
/// Задача о матрице
/// </summary>
void summatrix(vector<vector<int>>&, vector<vector<int>>&, pair<int, int>, pair<int, int>, int, vector<vector<int>>, int&);

/// <summary>
/// Чтение из файла
/// </summary>
void fileRead(string, vector<vector<int>>&, pair<int, int>&, pair<int, int>&, int&);

/// <summary>
/// Генерация матрицы
/// </summary>
void matrixGenerate();

/// <summary>
/// Вывод матрицы
/// </summary>
void printMatrix(vector<vector<int>> matrix, int x1, int x2, int y1, int y2);
