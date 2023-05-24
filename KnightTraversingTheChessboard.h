#pragma once
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;



/// <summary>
/// ������ �� ������ ����� ���� 
/// </summary>
void lab4task5();


/// <summary>
/// ������ �� ������ ����� ���� (��������� ����)
/// </summary>
void KnightTraversingTheChessboard(int**, int, int, vector<int>, vector<int>&);

/// <summary>
/// ������� ��������� ����� �� ������
/// </summary>
int countingSteps(int**, int, int, vector<int>);

/// <summary>
/// ��������� ������ ������
/// </summary>
int getEmptyCells(int**, int, int);

/// <summary>
/// ������ �� ������ ����� ���� (��������� ���������� ��������� �������)
/// </summary>
void KnightTraversingTheChessboard(int**, int, int, vector<int>, int&);