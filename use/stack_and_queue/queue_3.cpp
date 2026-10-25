
#include <cassert>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int timeRequiredToBuy(std::vector<int> tickets, int k) {
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < (int)tickets.size(); i++) {
        q.push({i, tickets[i]});
    }

    int time = 0;

    while (!q.empty()) {
        std::pair<int, int> person = q.front();
        q.pop();

        person.second--;
        time++;

        if (person.first == k && person.second == 0) {
            return time;
        }

        if (person.second > 0) {
            q.push(person);
        }
    }

    return time;
}

int main() {
    assert(timeRequiredToBuy({2, 3, 2}, 2) == 6);
    assert(timeRequiredToBuy({5, 1, 1, 1}, 0) == 8);
    assert(timeRequiredToBuy({1}, 0) == 1);

    std::cout << "Queue 3 passed\n";
    return 0;
}
