#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;



/// <summary>
/// �������� ������ ��������� � ������
/// </summary>
void lab2task1();

/// <summary>
/// ���������� ����� �� �����
/// </summary>
string** FileReader2(string filename, int& n, int& m);

/// <summary>
/// �������� �������� ������ ��������� � ������
/// </summary>
int LineSearchStr(string str, string substr, int& count);

/// <summary>
/// �������� ������ ��������� � ������ ����������� 
/// </summary>
int boyerMoore(string& s, string& x, int& c);

/// <summary>
/// �������� �������
/// </summary>
int* createArr(string& s);

/// <summary>
/// �������� ������ ��������� � ������ �������������������� 
/// </summary>
int KnutMorrisPratt(string& s, string& x, int& c);

/// <summary>
/// �������� ������ ��������� � ������ �����-������
/// </summary>
int karpRabin(string& s, string& x, int& c, int& hashs);

/// <summary>
/// ������� ���� (�������� ������ ��������� � ������ �����-������)
/// </summary>
int SymbolHash(string& s);
