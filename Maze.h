#pragma once
#include <conio.h>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;



/// <summary>
/// Задача о лабиринте
/// </summary>
void lab5task1();


/// <summary>
/// Следующий шаг
/// </summary>
void nextStep(vector<vector<int>>&, pair<int, int>, pair<int, int>, int);

/// <summary>
/// Шаг назад
/// </summary>
void previewStep(vector<vector<int>>&, pair<int, int>, pair<int, int>);

/// <summary>
/// Задача о лабиринте
/// </summary>
void maze(vector<vector<int>>&, pair<int, int>&, pair<int, int>&, pair<int, int>, pair<int, int>, vector<vector<int>>&, int, int&);

/// <summary>
/// Вывод поля
/// </summary>
void printField(vector<vector<int>>, pair<int, int>, pair<int, int>, pair<int, int>);

/// <summary>
/// Чтение из файла
/// </summary>
void readFile(vector<vector<int>>&, pair<int, int>&, pair<int, int>&, pair<int, int>&, string);
