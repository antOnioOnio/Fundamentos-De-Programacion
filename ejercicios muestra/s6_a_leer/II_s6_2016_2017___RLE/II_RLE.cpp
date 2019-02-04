//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// RLE

/*
El m�todo RLE (Run Length Encoding) codifica una secuencia de datos
formada por series de valores id�nticos consecutivos como una secuencia
de parejas de n�meros
(valor de la secuencia y n�mero de veces que se repite).

Esta codificaci�n es un mecanismo de compresi�n de datos (zip) sin p�rdidas.
Se aplica, por ejemplo, para comprimir los ficheros de im�genes en las que
hay zonas con los mismos datos (fondo blanco, por ejemplo).
Realice un programa que lea una secuencia de n�meros naturales terminada
con un n�mero negativo y la codifique mediante el m�todo RLE.

Entrada: 1 1 1 2 2 2 2 2 3 3 3 3 3 3 5 -1
   (tres veces 1, cinco veces 2, seis veces 3, una vez 5)
Salida: 3 1 5 2 6 3 1 5
*/

#include <iostream> 
using namespace std;  
   
int main(){    
   const int TERMINADOR = -1;
   int actual, anterior, iguales_hasta_ahora;

   /*
      Idea:
      
         Llevar dos variables actual y anterior que "apunten"
         al valor le�do en un momento dado y al valor anterior,
         respectivamente.

      Algoritmo (RLE):

         Mientras que el actual no sea el terminador 
            Avanzar anterior y actual
   
            Si son iguales
               incrementar la longitud de la secuencia actual
            si no
               Imprimir el anterior junto con la longitud de la secuencia
               y resetear el contador de la longitud actual
   */
   /*
   cin >> actual;
   bool hay_secuencia_por_procesar = actual != TERMINADOR;

   if (hay_secuencia_por_procesar)
      iguales_hasta_ahora = 1;
   else
      iguales_hasta_ahora = 0;

   while (hay_secuencia_por_procesar){
      if (anterior == actual)
         iguales_hasta_ahora++;
      else{
         cout << iguales_hasta_ahora << " " << anterior << " ";
         iguales_hasta_ahora = 1;
      }

      if (actual == TERMINADOR)
         hay_secuencia_por_procesar = false;
      else{
         anterior = actual;
         cin >> actual;           // Si actual == TERMINADOR,
      }                           //  debemos procesar la �ltima secuencia
   }
   */
   
   /*
   La anterior versi�n es completamente v�lida.
   Podemos implementar otra versi�n m�s corta.
   Observe que en esta nueva versi�n, cuando lleguemos al final de la
   secuencia, actual ser� el TERMINADOR y anterior ser� el valor justo
   anterior a �ste. Por lo tanto, la expresi�n del condicional
      if (anterior == actual)
   ser� false y se ir� al bloque else, que es el que se tiene que ejecutar
   cuando se ha terminado una secuencia de n�meros iguales (en este caso,
   la �ltima)
   */
   
   cout << "RLE\n\ n";
   cin >> actual;
   
   iguales_hasta_ahora = 1;

   while (actual != TERMINADOR){
      anterior = actual;
      cin >> actual;                
      
      if (anterior == actual)
         iguales_hasta_ahora++;
      else{
         cout << iguales_hasta_ahora << " " << anterior << " ";
         iguales_hasta_ahora = 1;
      }
   }
}
   

