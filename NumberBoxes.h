#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>
#include "Sorting.h"
using namespace std;



/// <summary>
/// Задача о коробках и сравнениях
/// </summary>
void lab7task2();


/// <summary>
/// Чтене из  файла
/// </summary>
void readFile(string, vector<string>&, vector<int>&);

/// <summary>
/// Задача о коробках и сравнениях
/// </summary>
void numberBoxes(vector<string>, vector<int>, vector<int>&);
