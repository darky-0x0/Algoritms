#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;



/// <summary>
/// Задача о черепашке в городе
/// </summary>
void lab6task1();


/// <summary>
/// Задача о черепашке в городе
/// </summary>
void turtleCity(vector<vector<int>>&, vector<vector<pair<int, int>>>&, pair<int, int>);

/// <summary>
/// ЗСчитывание из файла
/// </summary>
void fileRead(vector<vector<int>>&, vector<vector<pair<int, int>>>&, pair<int, int>&, string);

/// <summary>
/// Вывод поля
/// </summary>
void printField(vector<vector<int>>&, vector<vector<pair<int, int>>>&, pair<int, int>);

/// <summary>
/// Вывод пути
/// </summary>
void printPath(vector<vector<pair<int, int>>>, pair<int, int>, pair<int, int>, pair<int, int>);
