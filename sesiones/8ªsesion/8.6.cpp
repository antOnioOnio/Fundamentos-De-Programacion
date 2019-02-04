/*Reescriba la solución del ejercicio 46 que calcula la suma de los primeros T factoctoriales. Para ello, debe leer el valor T usando la función LeeIntRango del ejercicio 4 para obligar a que esté en el intervalo [1,20].
Debe definir la función SumaFactoriales que calcule la suma pedida. Implemente dos versiones de esta función:
• En una primera versión, la función SumaFactoriales debe llamar a la función Factorial, para realizar la suma tal y como se indica en el ejercicio 46
• En una segunda versión, la función SumaFactoriales debe realizar la suma de forma directa tal y como se indica en el ejercicio 47. Ponga dentro de un comentario la primera versión.*/

// Ejercicio 6 de la sesion 8. Antonio Garcia Castillo


#include <iostream>
using namespace std;

    // funcion para leer en un determinado rango

bool LeeIntRango (int numero){
    
   
    
    if ( numero >0 && numero<20 )
        
        return true;
    
    else
        
        return false ;
    
}

// funcion que realiza la suma de factoriales
long long SumaFactorial ( long long numero_suma){

    int cifra;
    long long suma_factorial=0, factorial=0, multiplicando;
    for ( cifra=1 ; cifra<=numero_suma; cifra++){
        
        factorial = 1;
        for ( multiplicando=2; multiplicando <= cifra; multiplicando++){
            
            factorial = factorial * multiplicando;
        }
        suma_factorial += factorial;
    }

    return suma_factorial;
}

// funcion main

int main() {
    
    int numero;
    bool numero_rango;
    long long suma_de_factoriales=0;
    
    
    // Entrada de datos
    do {
    cout << " introduce un numero del 1 al 20 " <<endl;
    cin >> numero;
    
    numero_rango = LeeIntRango(numero);
    
    }while ( numero_rango == false);
    
    suma_de_factoriales = SumaFactorial(numero);
        
    cout << " la suma de factoriales de " << numero <<" es " <<suma_de_factoriales <<endl;
    
    
    return 0;
}
