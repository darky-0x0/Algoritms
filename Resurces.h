#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
using namespace std;



/// <summary>
/// ������ � �������
/// </summary>
void lab7task3();



/// <summary>
/// ������ � �������
/// </summary>
void resurcesDistribution(vector<pair<pair<int, int>, int>>&, vector<vector<pair<int, int>>>&, int&);

/// <summary>
/// ���������� ������ �� ������
/// </summary>
void sortRequests(vector<pair<pair<int, int>, int>>&);

/// <summary>
/// ������ �� �����
/// </summary>
void fileRead(string, vector<pair<pair<int, int>, int>>&, int&);

/// <summary>
/// ����� �������� 
/// </summary>
void printResurces(vector<vector<pair<int, int>>> resurces);

