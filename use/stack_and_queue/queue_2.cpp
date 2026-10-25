
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

std::vector<std::string> generateBinaryNumbers(int N) {
    std::vector<std::string> result;
    std::queue<std::string> q;

    if (N <= 0) {
        return result;
    }

    q.push("1");

    for (int i = 0; i < N; i++) {
        std::string current = q.front();
        q.pop();

        result.push_back(current);

        q.push(current + "0");
        q.push(current + "1");
    }

    return result;
}

int main() {
    std::vector<std::string> result = generateBinaryNumbers(5);

    assert(result.size() == 5);
    assert(result[0] == "1");
    assert(result[1] == "10");
    assert(result[2] == "11");
    assert(result[3] == "100");
    assert(result[4] == "101");

    assert(generateBinaryNumbers(0).empty());

    std::cout << "Queue 2 passed\n";
    return 0;
}
