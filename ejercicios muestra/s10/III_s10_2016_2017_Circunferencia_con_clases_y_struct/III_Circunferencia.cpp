//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Circunferencia con clases y struct

/*
Recupere la definici�n del registro CoordenadasPunto2D del ejercicio 47 de esta
relaci�n de problemas y la soluci�n al ejercicio 3 (Circunferencia) de la relaci�n de
problemas I.
Cree ahora una clase llamada Circunferencia . Para establecer el centro, se usar�
un dato miembro que ha de ser de tipo CoordenadasPunto2D .
A�ada m�todos para obtener la longitud de la circunferencia y el �rea del c�rculo inte-
rior.
A�ada tambi�n un m�todo para saber si la circunferencia contiene a un punto cualquie-
ra. Recordemos que un punto (x 1 ,y 1 ) est� dentro de una circunferencia con centro
(x0 ,y0 ) y radio r si se verifica que:
   (x0 - x1 ) ^ 2 + (y0 - y1 ) ^ 2 <= r^2
Observe que el valor de p debe ser constante, y el mismo para todos los objetos de
la clase Circunferencia 
Cree un programa principal que lea el centro y el radio de una circunferencia, las
coordenadas de un punto y muestre en pantalla la longitud de la circunferencia, el
�rea del c�rculo y nos diga si el punto est� dentro o no de la circunferencia.

Ejemplo de entrada: 2.1 3.2 5.8 2.2 4.6
-- Salida correcta: 36.4425 105.683 El punto est� dentro
Ejemplo de entrada: 2.1 3.2 5.8 2.2 10.36
-- Salida correcta: 36.4425 105.683 El punto no est� dentro
*/

#include <cmath>  // NAN
#include <iostream>
using namespace std;

const double PI = 3.1415927;

struct CoordenadasPunto2D{
	double abscisa;
	double ordenada;
};

class Circunferencia{
private:
	CoordenadasPunto2D centro = {NAN, NAN};
	double radio = NAN;
	
	bool EsCorrectoRadio(double long_radio){
	   return long_radio >= 0;
	}
public:
   // Hemos decidido que, una vez establecidos el centro y el radio
   // en el constructor, luego ya no pueden modificarse, por lo que
   // no proporcionamos ning�n m�todo del tipo SetRadio o SetCentro
   
   // Si los valores pasados en el constructor no son correctos
   // los datos miembro se quedar�n con NAN, indicativo de que
   // ha habido un error.
   
	Circunferencia(CoordenadasPunto2D centro_circunferencia, 
                  double longitud_radio)
   {
      if (EsCorrectoRadio(longitud_radio)){
         centro = centro_circunferencia;
         radio  = longitud_radio;
      }
	}
	
	double Longitud(){
		return 2*PI*radio;
	}
	
	double Area(){
		return PI*radio*radio;
	}
	
	bool Contiene(CoordenadasPunto2D un_punto){
		double diferencia_abscisas, diferencia_ordenadas;
		bool contiene;

		diferencia_abscisas = centro.abscisa - un_punto.abscisa;
		diferencia_ordenadas = centro.ordenada - un_punto.ordenada;

		contiene = diferencia_abscisas*diferencia_abscisas 
                 + 
                 diferencia_ordenadas*diferencia_ordenadas 
                 <= 
                 radio * radio; 
              
      return contiene;
	}
};

/*
// Ampliaci�n:
//	En la siguiente versi�n se define PI como una constante est�tica de la clase Circunferencia.
//	El problema es que lo normal es que tengamos en este programa m�s clases relativas a 
// conceptos de Trigonometr�a y posiblemente tambi�n sea necesario acceder a PI desde dichas clases
// Por eso, en este ejemplo, es preferible definir PI como una constante global

// Un dato declarado como const en una clase declara un dato constante
//	en cada objeto, pero puede ser distinto entre objetos
// Para que sea la misma cte para todos los objetos, debemos declararla como static
// Las constantes enteras static se pueden incializar dentro de la clase
//	pero no las doubles!!! que deben asignarse fuera del class :-((

class Circunferencia{
private:
	CoordenadasPunto2D centro;
	double radio;
	static const double PI;
public:
	Circunferencia(CoordenadasPunto2D centro_circunferencia, double longitud_radio)
		: centro(centro_circunferencia),
		  radio(longitud_radio)
		{	
		}
	double Longitud(){
		return 2*PI*radio;
	}
	double Area(){
		return PI*radio*radio;
	}
};

const double Circunferencia::PI = 3.1416;
*/



int main(){
	CoordenadasPunto2D centro_circunf, punto;
	double radio;
	double longitud, area;
	bool esta_dentro;

   cout << "Circunferencia\n\n";
   cout << "Introduzca las coordenadas del centro y la longitud del radio:\n";   
   cin >> centro_circunf.abscisa;
   cin >> centro_circunf.ordenada;
   cin >> radio;
   
   cout << "\nIntroduzca las coordenadas de otro punto:\n";
   cin >> punto.abscisa;
   cin >> punto.ordenada;
      
	Circunferencia circunf(centro_circunf, radio);
	
	longitud    = circunf.Longitud();
	area        = circunf.Area();
	esta_dentro = circunf.Contiene(punto);

   cout << "\n\nLongitud: " << longitud;
   cout << "\n�rea:       " << area;
   
	if (esta_dentro)
		cout << "\nEl punto est� dentro";
	else
		cout << "\nEl punto no est� dentro";
}

