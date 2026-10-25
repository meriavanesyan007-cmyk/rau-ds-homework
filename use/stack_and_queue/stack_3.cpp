
#include <cassert>
#include <iostream>
#include <stack>
#include <string>

void reverseString(std::string& s) {
    std::stack<char> st;

    for (char c : s) {
        st.push(c);
    }

    for (int i = 0; i < (int)s.size(); i++) {
        s[i] = st.top();
        st.pop();
    }
}

int main() {
    std::string s1 = "hello";
    reverseString(s1);
    assert(s1 == "olleh");

    std::string s2 = "abc";
    reverseString(s2);
    assert(s2 == "cba");

    std::string s3 = "";
    reverseString(s3);
    assert(s3 == "");

    std::cout << "Stack 3 passed\n";
    return 0;
}
