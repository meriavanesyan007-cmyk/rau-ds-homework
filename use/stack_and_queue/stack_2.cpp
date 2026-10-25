
#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int evaluateRPN(const std::vector<std::string>& tokens) {
    std::stack<int> st;

    for (const std::string& token : tokens) {
        if (token == "+" || token == "-" ||
            token == "*" || token == "/") {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);
        } else {
            st.push(std::stoi(token));
        }
    }

    return st.top();
}

int main() {
    assert(evaluateRPN({"2", "3", "+"}) == 5);
    assert(evaluateRPN({"5", "2", "-"}) == 3);
    assert(evaluateRPN({"3", "4", "*"}) == 12);
    assert(evaluateRPN({"8", "2", "/"}) == 4);
    assert(evaluateRPN({"2", "3", "+", "4", "*"}) == 20);

    std::cout << "Stack 2 passed\n";
    return 0;
}
