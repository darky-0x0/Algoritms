#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;


/// <summary>
/// ������ � ������������
/// </summary>
void lab6task2();


/// <summary>
/// ����� �����������
/// </summary>
void printResults(vector<vector<int>> triangle, vector<vector<pair<int, int>>> results, int size);

/// <summary>
/// ������ � ������������
/// </summary>
void classicTriangle(vector<vector<int>>&, vector<vector<pair<int, int>>>&, int);

/// <summary>
/// ����� �������������
/// </summary>
void printTriangle(vector<vector<int>>, int, vector<vector<pair<int, int>>>);

/// <summary>
/// ���������� �� �����
/// </summary>
void fileReader(vector<vector<int>>&, int&, vector<vector<pair<int, int>>>&, string);
