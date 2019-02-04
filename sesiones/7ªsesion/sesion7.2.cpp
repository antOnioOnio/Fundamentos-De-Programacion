/* Ejercicio 2 de la sesion 7. 
 Reescribir la solucion al ejercicio 40 ( factorial y potencia ) modularizandola con funciones.
 Antonio Garcia Castillo */

#include <iostream>
using namespace std;

// funcion potencia
long long Potencia ( int base, int exponente){

    long long potencia;
    int i;
    
    potencia = 1.0;
    for (i= 1; i <= exponente; i++)
        potencia = potencia * base;
    
    return potencia;
    
    
}
// funcion factorial
long long Factorial( int numero){
    
    int multiplicando=2;
    long long fact=1 ;

    for ( multiplicando ; multiplicando <= numero ; multiplicando++ )
        fact *= multiplicando;

    return fact;
}

// funcion main
int main() {
   // declaracion de variables
    int base, exponente, numero;
    long long resultado_exponencial, resultado_factorial;
    
    // Entrada de datos para el calculo de una potencia
    cout << " Para calcular la potencia de un numero por favor siga los siguientes pasos :" <<endl;
    cout << " Introduce una base :" << endl;
    cin >> base;
    cout << " Introduce un exponente :" <<endl;
    cin >> exponente;
    
    resultado_exponencial = Potencia(base, exponente);
    
    cout << "\n" << base << " elevado a " << exponente << " es igual a " << resultado_exponencial << endl;

    
    // Entrada de datos para el calculo de un numero factorial
    cout << "Introduzca el numero del que desee calcular su factorial" <<endl;
    cin >> numero;
    
    resultado_factorial = Factorial(numero) ;
    
    cout << " \nEl factorial de " <<numero << " es igual a " <<resultado_factorial <<endl;
  
    
    return 0;
}
