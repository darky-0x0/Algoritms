#pragma once
#include <vector>
#include <iostream>
using namespace std;



/// <summary>
/// ������ � ����������� N ������ � �� ����� �������
/// </summary>
void lab4task2();


/// <summary>
/// ��������� ��� (������ � ����������� N ������ � �� ����� �������)
/// </summary>
void NextStep(vector<int>&, vector<int>&, int);

/// <summary>
/// ����� ���� (������ � ����������� N ������ � �� ����� �������)
/// </summary>
void PreviewStep(vector<int>&, vector<int>&, int);

/// <summary>
/// ������ � ����������� N ������ � �� ����� �������
/// </summary>
void CompactArrangementOfQueens(vector<int>&, vector<int>&, int n, int&, vector<int>&);

/// <summary>
/// ��������� ������ ������
/// </summary>
int GetEmpty1(vector<int>);