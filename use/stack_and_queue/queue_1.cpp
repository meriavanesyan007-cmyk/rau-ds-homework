
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

std::string hotPotato(std::vector<std::string> players, int K) {
    std::queue<std::string> q;

    for (const std::string& player : players) {
        q.push(player);
    }

    while (q.size() > 1) {
        for (int i = 0; i < K; i++) {
            q.push(q.front());
            q.pop();
        }

        q.pop();
    }

    return q.front();
}

int main() {
    std::vector<std::string> players = {
        "Alice", "Bob", "Charlie", "David"
    };

   assert(hotPotato(players, 0) == "David");
   assert(hotPotato(players, 1) == "Alice");
   assert(hotPotato(players, 7) == "Charlie");

    std::cout << "Queue 1 passed\n";
    return 0;
}
