#include <iostream>
#include <cmath>
#include "Calculator.cpp"

int calcuate(){
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