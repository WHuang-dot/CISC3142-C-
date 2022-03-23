#include <iostream>
#include <cmath>


enum class Operation { Add, Subtract, Multiply, Divide, SquareRoot };

struct Calculator {
    Operation op;
    Calculator(Operation operation) { op = operation; }

    int calculate(int a, int b) {
        switch (op) {
            case Operation::Add: {
                return a + b;
            } break;
            case Operation::Subtract: {
                return a - b;
            } break;
            case Operation::Multiply: {
                return a * b;
            } break;
            case Operation::Divide: {
                return a / b;
            }case Operation::SquareRoot: {
                return a * sqrt(b);
            }break;
            default: {
                std::cout << "Error: invalid operation!\n";
                return 0;
            }
        }
    }
};

int main() {
    int num1, num2;
    std::string operation;
    printf("Please enter the left operand, then hit Enter. \n");
    std::cin >> num1;
    printf("What type of operation do you want to perform? (+, -, *, /,sqrt)\n");
    std::cin >> operation;
    printf("Please enter the right operand, then hit Enter.\n");
    std::cin >> num2;

    Operation op{};

    if (operation == "+") {
        op = Operation::Add;
    } else if (operation == "-") {
        op = Operation::Subtract;
    } else if (operation == "*") {
        op = Operation::Multiply;
    } else if (operation == "/") {
        op = Operation::Divide;
    } else if (operation == "sqrt"){
        op = Operation::SquareRoot;
    }

    Calculator calc(op);
    auto answer = calc.calculate(num1, num2);
    printf("The result is: %d\n",answer);
}