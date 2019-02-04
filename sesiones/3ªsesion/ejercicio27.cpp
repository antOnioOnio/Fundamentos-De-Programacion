/*Escriba una expresión lógica que sea verdadera si una variable de tipo carácter llamada letra es una letra minúscula y falso en otro caso.
 Escriba una expresión lógica que sea verdadera si una variable de tipo entero llamada edad es menor de 18 o mayor de 65.
 Escriba una expresión lógica que sea verdadera si una variable de tipo entero llamada adivine está entre 1 y 100.
 Escriba una expresión lógica que sea verdadera si un año es bisiesto. Los años bisiestos son aquellos que o bien son divisibles por 4 pero no por 100, o bien son divisibles por 400.
 Escriba un programa que lea las variables y calcule el valor de las expresiones lógicas anteriores e imprima el resultado. Debe almacenarse el resultado de las expresiones lógicas en variables de tipo      bool.

 */


#include <iostream>

using namespace std;


int main() {
    // Declaracion de variables
    
    char letra;
    int edad, adivine, anio;
    bool es_mayuscula, edad_comprendida, numero_entre, es_bisiesto;
    
    
    // Entrada de datos
    
    cout << "\nIntroduce una letra" ;
    cin >> letra;
    
    cout << "\nIntroduce una edad" ;
    cin >> edad;
    
    cout << "\nIntroduce un numero" ;
    cin >> adivine;
    
    cout << "\nIntroduce una año" ;
    cin >> anio;
    
    // calculos
    
    es_mayuscula = (letra >='a' && letra <= 'z');
    edad_comprendida = edad <18 || edad >65 ;
    numero_entre = adivine >=1 && adivine <=100;
    es_bisiesto = ( anio % 4 == 0 && (anio % 100 != 0  || anio%400 ==0));
    
    // muestra resultados
    
    cout << "\n\nLetra" <<es_mayuscula;
    
    cout << "\n\nEdad" <<edad_comprendida;
    
    cout << "\n\nNumero" << numero_entre;
    
    cout << "\n\nAño" << es_bisiesto <<"\n";
    
    
    return 0;
}
