#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int M = 6;
const int N = 6;

// �������� ����� ����
map<int, pair<int, int>> MOVE_LIST = {
        {1, pair<int, int>(-2, 1)},
        {2, pair<int, int>(-1, 2)},
        {3, pair<int, int>(1, 2)},
        {4, pair<int, int>(2, 1)},
        {5, pair<int, int>(2, -1)},
        {6, pair<int, int>(1, -2)},
        {7, pair<int, int>(-1, -2)},
        {8, pair<int, int>(-2, -1)}
};

const int rateKnight[8][2] = { {-2, 1},{-1, 2},{1, 2},{2, 1},{2, -1},{1, -2},{-1, -2},{-2, -1} };

void solve(int i, int j, vector<vector<int>>& field, int& moveCount, bool& isKingDefeated,
    pair<int, int> kingPosition, pair<int, int> startPosition, bool& answerIsFinded);
bool checkCell(int i, int j, vector<vector<int>>& field, bool isKingDefeated);
void showField(vector<vector<int>>& field);

void task366()
{

    pair<int, int> startPosition(3, 5);

    pair<int, int> kingPosition(4, 1);

    vector<pair<int, int>> burningCells;

    vector<vector<int>> field(N);

    for (int i = 0; i < field.size(); i++) {

        field[i] = vector<int>(M, 0);

    }

    int moveCount = 1;

    bool isKingDefeated = false;

    bool answerIsFinded = false;



    // ���������� �� ���� ������� ������

    for (size_t i = 0; i < burningCells.size(); i++)

        field[burningCells[i].first][burningCells[i].second] = -1;



    // ����������� ������

    field[kingPosition.first][kingPosition.second] = -2;



    solve(startPosition.first, startPosition.second, field, moveCount,

        isKingDefeated, kingPosition, startPosition, answerIsFinded);

}



void solve(int i, int j, vector<vector<int>>& field, int& moveCount, bool& isKingDefeated,

    pair<int, int> kingPosition, pair<int, int> startPosition, bool& answerIsFinded)

{

    // ������� ���������� ������ ������, ����� ���� � ������ � �������

    if (isKingDefeated && i == startPosition.first

        && j == startPosition.second && !answerIsFinded)

    {

        showField(field);

        answerIsFinded = true;

    }

    else if (!answerIsFinded)

    {

        // �������� �� ��, �������� �� ������

        if (field[i][j] == -2)

            isKingDefeated = true;



        // ������� ������

        field[i][j] = moveCount;

        moveCount++;



        // ������ �� ����� ����

        for (size_t q = 1; q <= MOVE_LIST.size(); q++)

        {

            // �������� ������� �� ����������� ����

            if (checkCell(i + MOVE_LIST[q].first, j + MOVE_LIST[q].second, field, isKingDefeated))

            {

                // ����������� �����

                solve(i + MOVE_LIST[q].first, j + MOVE_LIST[q].second, field,

                    moveCount, isKingDefeated, kingPosition, startPosition, answerIsFinded);

            }

        }



        // ������

        if (i == kingPosition.first && j == kingPosition.second)

        {

            isKingDefeated = false;

            field[i][j] = -2;

        }

        else

            field[i][j] = 0;

        moveCount--;

    }

}



// ������� �������� ������ �� ����������� ����

bool checkCell(int i, int j, vector<vector<int>>& field, bool isKingDefeated)

{

    return (i < N && i >= 0 && j < M && j >= 0 &&

        (field[i][j] == 0 || field[i][j] == -2 ||

            (field[i][j] == 1 && isKingDefeated)));

}



// ����� ����

void showField(vector<vector<int>>& field)

{

    for (size_t i = 0; i < N; i++)

    {

        for (size_t j = 0; j < M; j++)

        {

            switch (field[i][j])

            {

            default:

                cout << field[i][j] << '\t';

                break;

            case 0:

                cout << "*\t";

                break;

            case -1:

                cout << "F\t";

                break;

            }

        }

        cout << '\n';

    }

}
