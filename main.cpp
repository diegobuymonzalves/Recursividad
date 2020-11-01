#include <iostream>
#include <string>
#include <exception>

unsigned long factorial(unsigned long n);
unsigned long fibonacci(unsigned long n);

int main()
{
    std::cout << "Calcular el factorial de un numero entero n y el numero n de la serie Fibonacci." << std::endl;
    std::cout << "Escriba \"factorial\" para calcular factorial." << std::endl;
    std::cout << "Escriba \"fibonacci\" para calcular fibonacci." << std::endl;
    std::cout << "Escriba \"fin\" para salir.\n" << std::endl;

    std::string dataIn;
    unsigned long n;
    bool isForFactorial = true;

    while(true) {
        if(isForFactorial)
            std::cout << "factorial> ";
        else
            std::cout << "fibonacci> ";
        std::cin >> dataIn;
        if(dataIn == "fin")
            break;
        else if(dataIn == "factorial") {
            isForFactorial = true;
            std::cout << std::endl;
            continue;
        } else if(dataIn == "fibonacci") {
            isForFactorial = false;
            std::cout << std::endl;
            continue;
        }

        try {
            n = std::stoul(dataIn);
            if(isForFactorial) {
                std::cout << n << "! = " << factorial(n) << std::endl;
            } else {
                std::cout << "fibonacci( " << n << " ) = " << fibonacci(n) << std::endl;
            }
        } catch(std::invalid_argument &exp){
            std::cout << "Error. Ingrese un numero entero positivo" << std::endl;
        } catch(std::out_of_range &exp) {
            std::cout << "El numero es demasiado grande para ser almacenado" << std::endl;
        }
    }

    return 0;
}

unsigned long factorial(unsigned long n) {
    if(n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

unsigned long fibonacci(unsigned long n) {
    if((0 == n) || (1 == n))
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
