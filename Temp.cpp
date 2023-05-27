#include <iostream>
#include <vector>
#include <string>

struct Result {
    int count;       // Количество операций
    std::string expression;  // Выражение
};

Result calculateMinimumOperations(int N, int k) {
    std::vector<Result> Op(N + 1);  // Массив для хранения результатов

    // Базовый случай: Op[1] = 0, так как нет операций для вычисления k^1
    Op[1].count = 0;
    Op[1].expression = "k";

    for (int i = 2; i <= N; i++) {
        Op[i].count = Op[i - 1].count + 1;
        Op[i].expression = "(" + Op[i - 1].expression + ")^k";

        for (int j = 2; j <= i - 1; j++) {
            if (i % j == 0) {
                int count = Op[i / j].count + j - 1;
                std::string expression = "(" + Op[i / j].expression + ")^" + std::to_string(j);

                if (count < Op[i].count) {
                    Op[i].count = count;
                    Op[i].expression = expression;
                }
            }
        }
    }

    return Op[N];
}

void task666() {
    int N;  // Заданное число N
    std::cin >> N;
    int k = 2;   // Заданное число k

    Result result = calculateMinimumOperations(N, k);

    std::cout << "Минимальное количество операций для получения k^N: " << result.count << std::endl;
    std::cout << "Выражение для k^N: " << result.expression << std::endl;

}