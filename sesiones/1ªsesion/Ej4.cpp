/*  programa para leer el valor de una variable salario_base de tipo double, la incremente un 2% e imprima el resultado en pantalla. Para realizar este cómputo, multiplique por 1.02 el valor original. Para resolver este ejercicio tiene varias alternativas: */

#include <iostream>
#include <cmath>

using namespace std;


int main () {
    
    double salario_incrementado, salario_base;
    
    cout << " introduzca el salario base ";
    cin >> salario_base;
    
    salario_incrementado = salario_base * 1.02 ;
    
    
    cout << "\nEl salario a recibir es " << salario_incrementado;
    
    return 0 ;
    
    
    
    
    
    
    
    //poner el incremento como variable
    
    
    
}
