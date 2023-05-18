#pragma once
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

void walker();

void countQueensMoves(int i, int j, int& N, int& countMoves, int& minMoves, int numberOfNotPassedFields, std::vector<std::vector<int>>& board, int lastDirection);

void move(int i, int j, int ni, int nj, std::vector<std::vector<int>>& board, int direction, int moveNumber);

void cancelMove(int i, int j, int ni, int nj, std::vector<std::vector<int>>& board, int direction, int moveNumber);

void printPath(int N);

