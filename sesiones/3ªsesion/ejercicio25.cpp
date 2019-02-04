/* 25. Construya un programa que lea un carácter (supondremos que el usuario introduce una mayúscula), lo pase a minúscula y lo imprima en pantalla. Hágalo sin usar las funciones               ni               de la biblioteca             . Para ello, debe considerarse la relación que hay en C++ entre los tipos enteros y caracteres */


#include <iostream>
using namespace std;



int main() {
    
    //Declaracion de variables
    char letra_mayuscula;
    
    cout << "letra mayuscula" ;
    cin >> letra_mayuscula;
    
    //Calculos
    letra_mayuscula = letra_mayuscula + ('a' - 'A');
    
    //Muestra resultados
    cout << "\nletra minuscula\t" << letra_mayuscula ;
    cout << "\n\n";
    
    
    
    return 0;
}
