#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
using namespace std;



/// <summary>
/// ������ � ������������
/// </summary>
void lab5task3();


/// <summary>
/// ��������� �����
/// </summary>
void next(vector<int>&, vector<int>&, int);

/// <summary>
/// ���������� �����
/// </summary>
void preview(vector<int>&, vector<int>&, int);

/// <summary>
/// ������ � ������������
/// </summary>
void kommivoyager(vector<vector<int>> const, int, int, int&, vector<int>&, vector<int>&, int, int const, vector<int>&);

/// <summary>
/// ������ �� �����
/// </summary>
void fileRead(vector<vector<int>>&, int&, string);

/// <summary>
/// ����� ����������
/// </summary>
void printPlaces(vector<vector<int>>, int);
