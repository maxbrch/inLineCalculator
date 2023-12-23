#include <iostream>
#include <cctype>

int main() {
    bool w = true; // for infinity work
    std::cout << "Bot: Hi!\n";

    while (w) {
        std::cout << "Bot: What do you want to do?\n";
        std::cout << "Me: ";
        std::string command;
        std::getline(std::cin, command);

        if (command == "exit") {
            std::cout << "You want to exit? (yes/no): ";
            std::string e;
            std::getline(std::cin, e);
            if (e == "yes") {
                w = false;
            }
        }
        else {
            int a, b, res;
            char op = '\0';  // Let's initialize op to avoid ambiguity


            bool opFound = false, operandFound = false;

            // Test on correct input
            for (char c : command) {
                if (isdigit(c)) {
                    if (!operandFound) {
                        a = c - '0';  // Frist num
                        operandFound = true;
                    }
                    else {
                        b = c - '0';  // Second num
                    }
                }
                else if (c == '+' || c == '-' || c == '*' || c == '/') {
                    if (!opFound) {
                        op = c;
                        opFound = true;
                    }
                }
            }

            // Test all find
            if (!operandFound || !opFound) {
                std::cout << "Error: Invalid expression format." << std::endl;
            }
            else {
                // Proces
                switch (op) {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    if (b != 0) {
                        res = a / b;
                    }
                    else {
                        std::cout << "Error: Division by zero." << std::endl;
                        return 1;
                    }
                    break;
                default:
                    std::cout << "Error: Unknown operator." << std::endl;
                    return 1;
                }

                std::cout << "Result: " << res << std::endl;
            }
        }
    }

    return 0;
}
