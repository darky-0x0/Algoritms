#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;


/// <summary>
/// Задача о треугольнике
/// </summary>
void lab6task2();


/// <summary>
/// Вывод результатов
/// </summary>
void printResults(vector<vector<int>> triangle, vector<vector<pair<int, int>>> results, int size);

/// <summary>
/// Задача о треугольнике
/// </summary>
void classicTriangle(vector<vector<int>>&, vector<vector<pair<int, int>>>&, int);

/// <summary>
/// Вывод треугольников
/// </summary>
void printTriangle(vector<vector<int>>, int, vector<vector<pair<int, int>>>);

/// <summary>
/// Считывание из файла
/// </summary>
void fileReader(vector<vector<int>>&, int&, vector<vector<pair<int, int>>>&, string);
