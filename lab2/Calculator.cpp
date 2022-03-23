
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