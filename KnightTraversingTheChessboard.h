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
void KnightTraversingTheChessboard(int** field, int N, int M, vector<int> position, vector<int>& result);

/// <summary>
/// ������� ��������� ����� �� ������
/// </summary>
int countingSteps(int** field, int N, int M, vector<int> position);

/// <summary>
/// ��������� ������ ������
/// </summary>
int getEmptyCells(int** field, int N, int M);

/// <summary>
/// ������ �� ������ ����� ���� (��������� ���������� ��������� �������)
/// </summary>
void KnightTraversingTheChessboard(int** field, int N, int M, vector<int> position, int& result);