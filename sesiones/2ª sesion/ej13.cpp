/*Escriba un programa que lea un valor entero e imprima en pantalla cada uno de sus dígitos separados por dos espacios en blanco.
*/
#include <iostream>
#include <cmath>

using namespace std;


int main() {
    
    int valor;
    cout << "\n introduce un valor de tres cifras " ;
    cin >> valor;
    
    cout << "\nvalor dividido" << (valor/100)%10 << "  " << (valor/10)%10 << "  " << (valor/1)%10;
    return 0;
}
                 
