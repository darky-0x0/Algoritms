#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <ctime>
#include "Sorting.h"
using namespace std;




/// <summary>
/// ����� k-�� ���������� �� �������� � ������� �����
/// </summary>
void lab7task4();

/// <summary>
/// ����� k-�� ���������� �� �������� � ������ ������ �����
/// </summary>
void lab7task5();


/// <summary>
/// ����� k-�� ����������
/// </summary>
int searchingStatistic(vector<int>&, int, int, int, int);

/// <summary>
/// ����� ������� ������
/// </summary>
int select(vector<int>&, int, int);

/// <summary>
/// ��������� �� ��������
/// </summary>
pair<int, int> partition(int, int, int, vector<int>&);

/// <summary>
/// ������ �� �����
/// </summary>
void fileRead(string, vector<int>&);

/// <summary>
/// ����� �������
/// </summary>
void printArray(vector<int>);

/// <summary>
/// ��������� ���������� ����� �� end
/// </summary>
int randGenerate(int, int);

/// <summary>
/// ������� ����� ���������� �������
/// </summary>
void swap(vector<int>& array, int a, int b);

/// <summary>
/// ���������� 5 �� 7
/// </summary>
void sortFiveForSeven(vector<int>&, int);

/// <summary>
/// ����� ���������������� �������
/// </summary>
void printSortArray(vector<int>);
