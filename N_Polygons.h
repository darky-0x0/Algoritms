#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <cmath>
using namespace std;




/// <summary>
/// ������ � ��������� ��������������
/// </summary>
void lab6task4();



/// <summary>
/// ������ � ��������� ��������������
/// </summary>
void polygonsCut(vector<vector<float>>, vector<vector<float>>&, int, vector<vector<vector<pair<int, int>>>>&);

/// <summary>
/// ������� ����������
/// </summary>
void lengthOfAllDiagonals(vector<vector<float>>&, vector<pair<int, int>>&);

/// <summary>
/// ������ �� �����
/// </summary>
void fileRead(string, vector<pair<int, int>>&);