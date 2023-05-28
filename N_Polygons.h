#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <cmath>
using namespace std;




/// <summary>
/// Задача о разбиении многоугольника
/// </summary>
void lab6task4();



/// <summary>
/// Задача о разбиении многоугольника
/// </summary>
void polygonsCut(vector<vector<float>>, vector<vector<float>>&, int, vector<vector<vector<pair<int, int>>>>&);

/// <summary>
/// Подсчёт диагоналей
/// </summary>
void lengthOfAllDiagonals(vector<vector<float>>&, vector<pair<int, int>>&);

/// <summary>
/// Чтение из файла
/// </summary>
void fileRead(string, vector<pair<int, int>>&);