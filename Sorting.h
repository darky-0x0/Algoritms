#pragma once
#include <iostream>
#include <vector>
using namespace std;




/// <summary>
/// ������� ����������
/// </summary>
void lab3task1();

/// <summary>
/// ���������� ������-��������
/// </summary>
void lab3task2();

/// <summary>
/// ��������� ����������
/// </summary>
void lab3task3();

/// <summary>
/// �������� ������ ��� �����������
/// </summary>
void createFilesForSort();

/// <summary>
/// ���������� ������-��������
/// </summary>
vector<int> sortingByParity(vector<int> array, int size);

/// <summary>
/// ���������� "�� ��������"
/// </summary>
vector<int> simpleSort(vector<int> array, int size, int m);


/// <summary>
/// �������� ���������� ������� �������
/// </summary>
vector<int> simpleSelect(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// �������� ���������� "���������"
/// </summary>
vector<int> simpleExchange(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// �������� ���������� "���������" (���� ���������� ������)
/// </summary>
vector<int> simpleExchangeUpgrade(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// �������� ���������� "���������" ("������-����������")
/// </summary>
vector<int> simpleExchangeShaker(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// �������� ������� ���������
/// </summary>
vector<int> insertionSort(vector<int> array, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// �������� ������� ��������� (���������� �������)
/// </summary>
vector<int> insertionSortWithBarrier(vector<int> arrayA, int size, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// �������� ���������� ��������
/// </summary>
vector<int> mergeSort(vector<int> array, int size, int& count, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

/// <summary>
/// ������� ���������� �����
/// </summary>
void sortHoar(vector<int>& array, int first, int last, int& count, unsigned long int& comparisonWithElement, unsigned long int& comparisionWithNotElement, unsigned long int& countReplace);

