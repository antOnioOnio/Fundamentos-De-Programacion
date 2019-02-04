//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Pasar de carácter a entero

/*
Supongamos el siguiente código:

   int entero;
   char caracter;
   cin >> caracter;
   entero = caracter;
   
Supongamos que ejecutamos el código e introducimos el 7 desde teclado.
El programa está leyendo una variable de tipo char .
Por lo tanto, el símbolo 7 se interpreta como un carácter
y es como si hiciésemos la siguiente asignación:

   caracter = '7';
   entero = caracter;
   
por lo que la variable caracter almacenará internamente el valor 55
(el orden en la tabla ASCII del carácter '7' ).
Lo mismo ocurre con la variable entero , que pasa a contener 55 .

Sin embargo, queremos construir un programa para asignarle a la variable
entero el número 7 asociado al dígito representado en la variable caracter,
es decir, el 7 y no el 55.

¿Cómo se le ocurre hacerlo?

El programa también imprimirá en pantalla el resultado.

Nota. La comilla simple para representar un literal de carácter es la que
hay en el teclado del ordenador debajo de la interrogación ? .
Esta comilla hay que ponerla en el código pero no en la entrada del
carácter desde teclado.

Ejemplo de entrada: 7 ( cin de un char ) --
Salida correcta: 7 ( cout de un int )
*/

#include <iostream>
using namespace std;

int main(){
	/*
	En primer lugar, ejecutamos y entendemos el siguiente código:
	*/
   /*
	int  orden_caracter_cero;
	char caracter_cero;

	// El orden del carácter 0 es 48
	
   caracter_cero = 48;                   // Almacena 48
	caracter_cero = '0';                  // Almacena 48
	
	orden_caracter_cero = 48;             // Almacena 48
	orden_caracter_cero = '0';            // Almacena 48
	orden_caracter_cero = caracter_cero;  // Almacena 48

	cout << "\nEl orden del carácter " << caracter_cero << " es: "
        << orden_caracter_cero;
	*/
	
   /*
	Internamente ambas variables orden_caracter_cero y caracter_cero
   contienen 48
	Sin embargo, cout de un char imprime un pantalla el carácter asociado
   y cout de un int imprime el entero que contiene (48 en este caso)
   */
   
   ///////////////////////////////////////////////////////////////////////

	/*
	Queremos obtener el entero correspondiente a un carácter que representa
   un dígito numérico:
   
	'7' --> 7
	'3' --> 3
	
	Sabemos que sumar(restar) dos caracteres suma(resta) los órdenes
   correspondientes. Por ejemplo:
   
	'7' - '3'  equivale a   55 - 51 = 4
   
	Lo mismo ocurre si hacemos lo siguiente:
	
	'7' - 51   equivale a   55 - 51 = 4

   En concreto, podemos hacer lo siguiente:
   
	'7' - '0'  equivale a   55 - 48 = 7
	
   Esto es así porque '7' tiene un número de orden en la tabla ASCII
   siete veces superior al orden del carácter '0'.

   Voilá, ¡Ya lo tenemos!
	La expresión '7' - '0' devuelve 7
	

	En vez de usar '0' en la expresión anterior podríamos haber usado
   directamente su número de orden:
	
	'7' - 48   equivale a   55 - 48 = 7
	
	Sin embargo, este código no es "elegante".
	A un programador le resultará difícil entender la expresión '7' - 48
	El entero 48 parece "un número mágico sacado de la manga"
	Mucho más intuitiva es la expresión '7' - '0'
	
	Finalmente, una nota "avanzada":
	
      Si en una misma expresión, sólo aparecen datos del mismo tipo,
      la expresión resultante es del mismo tipo.
      Esto es cierto SALVO en el caso de la resta de dos char,
      que es una expresión de tipo int

      Así pues, '7' - '0' no es una expresión de tipo char sino de tipo int
	*/

   const char CARACTER_DIGITO_CERO = '0';
   char caracter;
   int caracter_a_entero;

   cout << "Conversión de carácter a número.\n\n";
   cout << "\nIntroduzca un carácter numérico  --> ";
   cin  >> caracter;

   caracter_a_entero = caracter - CARACTER_DIGITO_CERO;

   cout << "\nEl entero correspondiente es " << caracter_a_entero;
   cout << "\n\n";
}



 
