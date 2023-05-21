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
void NextStep(vector<int>& field, vector<int>& queensField, int index, int size, int n);

/// <summary>
/// ����� ���� (������ � ����������� N ������ � �� ����� �������)
/// </summary>
void PreviewStep(vector<int>& field, vector<int>& queensField, int index, int size, int n);

/// <summary>
/// ������ � ����������� N ������ � �� ����� �������
/// </summary>
void CompactArrangementOfQueens(vector<int>& mainField, vector<int>& queensField, int n, int& fields, vector<int>& result);

/// <summary>
/// ��������� ������ ������
/// </summary>
int GetEmpty(vector<int> mainField);