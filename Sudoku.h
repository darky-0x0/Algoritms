#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;





/// <summary>
/// Судоку
/// </summary>
void lab5task4();


/// <summary>
/// Судоку
/// </summary>
void sudoku(vector<vector<int>> const, vector<pair<pair<int, int>, int>>&, vector<pair<pair<int, int>, int>>&, int);

/// <summary>
/// Рассчитываем недостающие числа
/// </summary>
void possibleSteps(vector<int>&, vector<vector<int>> const, vector<pair<pair<int, int>, int>> const, int);

/// <summary>
/// Считываем из файла
/// </summary>
void fileRead(string, vector<pair<pair<int, int>, int>>&, vector<vector<int>>&);

/// <summary>
/// Выводим
/// </summary>
void printField(vector<vector<int>>, vector<pair<pair<int, int>, int>>);
