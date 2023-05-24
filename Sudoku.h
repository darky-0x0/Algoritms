#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;






void lab5task4();



void sudoku(vector<vector<int>> const, vector<pair<pair<int, int>, int>>&, vector<pair<pair<int, int>, int>>&, int);


void possibleSteps(vector<int>&, vector<vector<int>> const, vector<pair<pair<int, int>, int>> const, int);


void fileRead(string, vector<pair<pair<int, int>, int>>&, vector<vector<int>>&);


void printField(vector<vector<int>>, vector<pair<pair<int, int>, int>>);
