#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;



/// <summary>
/// ������ � ��������� � ������
/// </summary>
void lab6task1();


/// <summary>
/// ������ � ��������� � ������
/// </summary>
void turtleCity(vector<vector<int>>&, vector<vector<pair<int, int>>>&, pair<int, int>);

/// <summary>
/// ����������� �� �����
/// </summary>
void fileRead(vector<vector<int>>&, vector<vector<pair<int, int>>>&, pair<int, int>&, string);

/// <summary>
/// ����� ����
/// </summary>
void printField(vector<vector<int>>&, vector<vector<pair<int, int>>>&, pair<int, int>);

/// <summary>
/// ����� ����
/// </summary>
void printPath(vector<vector<pair<int, int>>>, pair<int, int>, pair<int, int>, pair<int, int>);
