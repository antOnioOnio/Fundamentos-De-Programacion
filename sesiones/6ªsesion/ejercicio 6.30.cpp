/*Programa que lee un valor entero de tres digitos arbitrario y lo separa con espacios en blanco */

#include <iostream>

using namespace std;


int main(){
    
    //DECLARACION DE VARIABLES
    
    int numero;
    int exponencial;
    
    //Introduccion de numero
    
    do{
        cout << "Introduzca un numero entero positivo : ";
        cin >> numero;
    }while(numero < 1);
    
    
    
    
    //calculo
    for(exponencial=1; exponencial<numero; exponencial*=10);
    
        for(exponencial/=10; exponencial > 0; exponencial/=10)
        cout << (numero/exponencial)%10 << "  ";
    
    
    
    return 0;
}
