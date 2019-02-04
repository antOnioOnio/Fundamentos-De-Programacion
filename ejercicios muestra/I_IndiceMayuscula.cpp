//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Obtener el �ndice relativo de una may�scula

/*
Realice un programa que lea una may�scula desde teclado sobre una variable
de tipo char .
A continuaci�n, el programa imprimir� el 0 si se ha introducido
el car�cter A , el 1 si era la B , el 2 si era la C y as� sucesivamente.
Supondremos que el usuario introduce siempre un car�cter may�scula.

Ejemplo de entrada: C -- Salida correcta: 2
*/

#include <iostream>
using namespace std;

int main(){
   /*
   Para resolver este ejercicio, basta realizar una resta entre caracteres
   
   'A' - 'A' devuelve 0
   'A' - 'B' devuelve 1
   .......
   
   y as� sucesivamente.
	*/

   char letra_mayuscula;
   int orden_relativo_masyucula;

   cout << "Orden relativo de una may�scula.\n\n";
   cout << "Introduzca una letra may�scula  --> ";
   cin  >> letra_mayuscula;

   orden_relativo_masyucula = letra_mayuscula - 'A';

   cout << "\nLa may�scula " << letra_mayuscula
        << " est� " << orden_relativo_masyucula
        << " posiciones por encima de la letra A"
        << "\n\n";
}
 
