#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>
#include <cmath>x
using namespace std;



/// <summary>
/// ������ � �������
/// </summary>
void lab6task6();


/// <summary>
/// ������ � �������
/// </summary>
void summatrix(vector<vector<int>>&, vector<vector<int>>&, pair<int, int>, pair<int, int>, int, vector<vector<int>>, int&);

/// <summary>
/// ������ �� �����
/// </summary>
void fileRead(string, vector<vector<int>>&, pair<int, int>&, pair<int, int>&, int&);

/// <summary>
/// ��������� �������
/// </summary>
void matrixGenerate();

/// <summary>
/// ����� �������
/// </summary>
void printMatrix(vector<vector<int>> matrix, int x1, int x2, int y1, int y2);
