#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
using namespace std;



/// <summary>
/// Задача о коммивояжере
/// </summary>
void lab5task3();


/// <summary>
/// Следующий город
/// </summary>
void next(vector<int>&, vector<int>&, int);

/// <summary>
/// Предыдущий город
/// </summary>
void preview(vector<int>&, vector<int>&, int);

/// <summary>
/// Задача о коммивояжере
/// </summary>
void kommivoyager(vector<vector<int>> const, int, int, int&, vector<int>&, vector<int>&, int, int const, vector<int>&);

/// <summary>
/// Чтение из файла
/// </summary>
void fileRead(vector<vector<int>>&, int&, string);

/// <summary>
/// Вывод результата
/// </summary>
void printPlaces(vector<vector<int>>, int);
