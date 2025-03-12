#include <iostream>
#include <cstdlib> // Para usar std::atoi (convierte texto a número entero) aunque tambien se podria stoi
using namespace std;

// Funciones que realizan las operaciones básicas
int add(int a, int b) // Suma dos números y devuelve el resultado
{
    return a + b;
}

int multiply(int a, int b) // Multiplica dos números y devuelve el resultado
{
    return a * b;
}

int subtract(int a, int b) // Resta dos números y devuelve el resultado
{
    return a - b;
}

// Función que recibe un puntero a una función (callback) y la ejecuta con los valores dados
// Un callback es básicamente una función que se pasa como argumento a otra función
// En este caso, pasamos una función matemática (suma, resta o multiplicación) para que se ejecute
void performOperation(int (*callback)(int, int), int x, int y)
{
    // Aquí estamos llamando la función que nos enviaron y le pasamos los valores
    // Por ejemplo, si callback es 'add', se ejecuta add(x, y)
    cout << callback(x, y) << endl; // Llama a la función y muestra el resultado en consola
}

int main(int argc, char *argv[])
{
    // Verificamos que el usuario ingresó exactamente 3 argumentos además del nombre del programa
    if (argc != 4)
    {
        cerr << "Uso: " << argv[0] << " <num1> <operador> <num2>" << endl;
        return 1; // Salimos del programa con error si no hay suficientes argumentos
    }

    // Convertimos el primer argumento a un número entero
    // std::atoi convierte una cadena de caracteres (char*) en un entero (int)
    int primero = std::atoi(argv[1]);

    /*argv[2] es una cadena de caracteres, pero como solo nos interesa el primer carácter,
    ya que es como si tuvieramos un arreglo dentro de otro arreglo, si no especificamos [0] genera conflicto
    accedemos a argv[2][0] para obtener el operador (por ejemplo, '+', '-', 'x')
    */
    char operador = argv[2][0];

    // Convertimos el tercer argumento a un número entero
    int segundo = std::atoi(argv[3]);

    // Evaluamos qué operación debe hacerse según el operador ingresado
    if (operador == '+')
    {
        cout << "La suma es: ";
        performOperation(add, primero, segundo); // Llamamos a performOperation con la función de suma
    }
    else if (operador == 'x') // Se usa 'x' en lugar de '*', ya que '*' puede causar problemas en la terminal
    {
        cout << "La multiplicación es: ";
        performOperation(multiply, primero, segundo); // Llamamos a performOperation con la función de multiplicación
    }
    else if (operador == '-')
    {
        cout << "La resta es: ";
        performOperation(subtract, primero, segundo); // Llamamos a performOperation con la función de resta
    }
    else
    {
        // Si el operador ingresado no es válido, mostramos un mensaje de error
        cerr << "Operador no válido. Use +, x o -." << endl;
        return 1; // Salimos con error
    }

    return 0; // Todo salió bien, terminamos el programa con éxito
}
