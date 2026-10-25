#include <cassert>
#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& s) {
    std::stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                return false;
            }

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return st.empty();
}

void test_isBalanced() {
    assert(isBalanced("({[]})"));
    assert(!isBalanced("([)]"));
    assert(!isBalanced("{[}]"));
    assert(isBalanced(""));
    assert(!isBalanced("((("));
    assert(!isBalanced(")"));

    std::cout << "isBalanced passed\n";
}

int main() {
    test_isBalanced();
    return 0;
}
