#include <iostream>
#include <cstdlib> // Para usar std::atoi
using namespace std;

// Callback functions for different operations
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int subtract(int a, int b)
{
    return a - b;
}

// Function that performs an operation using a callback
void performOperation(int (*callback)(int, int), int x, int y)
{
    cout << "" << callback(x, y) << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Uso: " << argv[0] << " <num1> <operador> <num2>" << endl;
        return 1;
    }

    int primero = std::atoi(argv[1]);
    char si = argv[2][0];
    int segundo = std::atoi(argv[3]);

    if (si == '+')
    {
        cout << "La suma es: ";
        performOperation(add, primero, segundo);
    }
    else if (si == 'x')
    {
        cout << "La multiplicación es: ";
        performOperation(multiply, primero, segundo);
    }
    else if (si == '-')
    {
        cout << "La resta es: ";
        performOperation(subtract, primero, segundo);
    }
    else
    {
        cerr << "Operador no válido. Use +, * o -." << endl;
        return 1;
    }

    return 0;
}