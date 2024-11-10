#include <iostream>
#include <stack>
#include <string>

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

bool checkBrackets(const std::string& expression) {
    std::stack<char> stack;
    for (size_t i = 0; i < expression.size(); ++i) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty() || !isMatchingPair(stack.top(), ch)) {
                std::cout << "неправилное расположение " << i << ": ";
                std::cout << expression.substr(0, i + 1) << std::endl;
                return false;
            }
            stack.pop();
        }
    }
    if (stack.empty()) {
        std::cout << "неправильеок расположение выражения" << std::endl;
        return true;
    }
    else {
        std::cout << "привышен лимит" << std::endl;
        return false;
    }
}

int main() {
    std::string expression;
    std::cout << "введи ; для проверки ";
    std::getline(std::cin, expression);

    if (!expression.empty() && expression.back() == ';') {
        expression.pop_back();
    }

    checkBrackets(expression);

    return 0;
}
