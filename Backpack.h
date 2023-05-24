#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
using namespace std;



/// <summary>
/// Задача о рюкзаке
/// </summary>
void lab5task2();


/// <summary>
/// Считывание из файла
/// </summary>
void readFile(vector<pair<int, int>>&, int&, int&, string);

/// <summary>
/// Задача о рюкзаке
/// </summary>
void backpack(vector<pair<int, int>> const, int const, vector<int>&, vector<int>&, int const, int&, int&, int&);

/// <summary>
/// Задача о рюкзаке
/// </summary>
void backpack2(vector<pair<int, int>> const, int const, vector<int>&, vector<int>&, int const, int&, int, int);

/// <summary>
/// Предмет в рюкзак
/// </summary>
void lay(vector<pair<int, int>>, int, vector<int>&, int&, int&);

/// <summary>
/// Предмет из рюкзака
/// </summary>
void layOut(vector<pair<int, int>>, int, vector<int>&, int&, int&);

/// <summary>
/// Вывести результат
/// </summary>
void printResult(int, vector<int>);
