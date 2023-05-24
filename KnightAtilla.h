#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;



/// <summary>
/// Задача о коне Аттила
/// </summary>
void lab4task7();


/// <summary>
/// Задача о коне Аттила
/// </summary>
void AttilaKnight(vector<vector<int>>&, int, pair<int, int>&, pair<int, int> const, pair<int, int> const, vector<vector<int>>&, int);

/// <summary>
/// Шаг вперёд
/// </summary>
void NextStep(vector<vector<int>>&, pair<int, int>, int);

/// <summary>
/// Отмена хода
/// </summary>
void PreviewStep(vector<vector<int>>&, pair<int, int>);

/// <summary>
/// Вывод поля
/// </summary>

void printField(vector<vector<int>>, int, pair<int, int>);

/// <summary>
/// Считывание данных из файла
/// </summary>
void fileRead(vector<vector<int>>&, pair<int, int>&, pair<int, int>&, string);

/// <summary>
/// Создание поля
/// </summary>
vector<vector<int>> createField(int);
