#pragma once
#include <vector>
#include <iostream>
using namespace std;



/// <summary>
/// ������ � ����������� ������ ����������
/// </summary>
void lab4task6();


/// <summary>
/// ������ � ����������� ������ ����������
/// </summary>
void ArrangementOfMagaraja(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, vector<int>& knight, int& count, int size);

/// <summary>
/// ��������� ��� ��� ���� (������ � ����������� ������ ����������)
/// </summary>
void NextStepKnight(vector<int>& knight, int index, vector<int>& indexes);

/// <summary>
/// ��� ����� ��� ���� (������ � ����������� ������ ����������)
/// </summary>
void PreviewStepKnight(vector<int> indexes, vector<int>& knight);

/// <summary>
/// ��������� ��� ��� ����� (������ � ����������� ������ ����������)
/// </summary>
void NextStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index);

/// <summary>
/// ��� ����� ��� ����� (������ � ����������� ������ ����������)
/// </summary>
void PreviewStep(vector<int>& field, vector<int>& vertical, vector<int>& diagonalUp, vector<int>& diagonalDown, int& count, int size, int index);
