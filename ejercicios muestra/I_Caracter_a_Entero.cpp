//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Pasar de car�cter a entero

/*
Supongamos el siguiente c�digo:

   int entero;
   char caracter;
   cin >> caracter;
   entero = caracter;
   
Supongamos que ejecutamos el c�digo e introducimos el 7 desde teclado.
El programa est� leyendo una variable de tipo char .
Por lo tanto, el s�mbolo 7 se interpreta como un car�cter
y es como si hici�semos la siguiente asignaci�n:

   caracter = '7';
   entero = caracter;
   
por lo que la variable caracter almacenar� internamente el valor 55
(el orden en la tabla ASCII del car�cter '7' ).
Lo mismo ocurre con la variable entero , que pasa a contener 55 .

Sin embargo, queremos construir un programa para asignarle a la variable
entero el n�mero 7 asociado al d�gito representado en la variable caracter,
es decir, el 7 y no el 55.

�C�mo se le ocurre hacerlo?

El programa tambi�n imprimir� en pantalla el resultado.

Nota. La comilla simple para representar un literal de car�cter es la que
hay en el teclado del ordenador debajo de la interrogaci�n ? .
Esta comilla hay que ponerla en el c�digo pero no en la entrada del
car�cter desde teclado.

Ejemplo de entrada: 7 ( cin de un char ) --
Salida correcta: 7 ( cout de un int )
*/

#include <iostream>
using namespace std;

int main(){
	/*
	En primer lugar, ejecutamos y entendemos el siguiente c�digo:
	*/
   /*
	int  orden_caracter_cero;
	char caracter_cero;

	// El orden del car�cter 0 es 48
	
   caracter_cero = 48;                   // Almacena 48
	caracter_cero = '0';                  // Almacena 48
	
	orden_caracter_cero = 48;             // Almacena 48
	orden_caracter_cero = '0';            // Almacena 48
	orden_caracter_cero = caracter_cero;  // Almacena 48

	cout << "\nEl orden del car�cter " << caracter_cero << " es: "
        << orden_caracter_cero;
	*/
	
   /*
	Internamente ambas variables orden_caracter_cero y caracter_cero
   contienen 48
	Sin embargo, cout de un char imprime un pantalla el car�cter asociado
   y cout de un int imprime el entero que contiene (48 en este caso)
   */
   
   ///////////////////////////////////////////////////////////////////////

	/*
	Queremos obtener el entero correspondiente a un car�cter que representa
   un d�gito num�rico:
   
	'7' --> 7
	'3' --> 3
	
	Sabemos que sumar(restar) dos caracteres suma(resta) los �rdenes
   correspondientes. Por ejemplo:
   
	'7' - '3'  equivale a   55 - 51 = 4
   
	Lo mismo ocurre si hacemos lo siguiente:
	
	'7' - 51   equivale a   55 - 51 = 4

   En concreto, podemos hacer lo siguiente:
   
	'7' - '0'  equivale a   55 - 48 = 7
	
   Esto es as� porque '7' tiene un n�mero de orden en la tabla ASCII
   siete veces superior al orden del car�cter '0'.

   Voil�, �Ya lo tenemos!
	La expresi�n '7' - '0' devuelve 7
	

	En vez de usar '0' en la expresi�n anterior podr�amos haber usado
   directamente su n�mero de orden:
	
	'7' - 48   equivale a   55 - 48 = 7
	
	Sin embargo, este c�digo no es "elegante".
	A un programador le resultar� dif�cil entender la expresi�n '7' - 48
	El entero 48 parece "un n�mero m�gico sacado de la manga"
	Mucho m�s intuitiva es la expresi�n '7' - '0'
	
	Finalmente, una nota "avanzada":
	
      Si en una misma expresi�n, s�lo aparecen datos del mismo tipo,
      la expresi�n resultante es del mismo tipo.
      Esto es cierto SALVO en el caso de la resta de dos char,
      que es una expresi�n de tipo int

      As� pues, '7' - '0' no es una expresi�n de tipo char sino de tipo int
	*/

   const char CARACTER_DIGITO_CERO = '0';
   char caracter;
   int caracter_a_entero;

   cout << "Conversi�n de car�cter a n�mero.\n\n";
   cout << "\nIntroduzca un car�cter num�rico  --> ";
   cin  >> caracter;

   caracter_a_entero = caracter - CARACTER_DIGITO_CERO;

   cout << "\nEl entero correspondiente es " << caracter_a_entero;
   cout << "\n\n";
}



 
