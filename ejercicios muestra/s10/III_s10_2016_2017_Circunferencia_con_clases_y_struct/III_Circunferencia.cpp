//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Circunferencia con clases y struct

/*
Recupere la definición del registro CoordenadasPunto2D del ejercicio 47 de esta
relación de problemas y la solución al ejercicio 3 (Circunferencia) de la relación de
problemas I.
Cree ahora una clase llamada Circunferencia . Para establecer el centro, se usará
un dato miembro que ha de ser de tipo CoordenadasPunto2D .
Añada métodos para obtener la longitud de la circunferencia y el área del círculo inte-
rior.
Añada también un método para saber si la circunferencia contiene a un punto cualquie-
ra. Recordemos que un punto (x 1 ,y 1 ) está dentro de una circunferencia con centro
(x0 ,y0 ) y radio r si se verifica que:
   (x0 - x1 ) ^ 2 + (y0 - y1 ) ^ 2 <= r^2
Observe que el valor de p debe ser constante, y el mismo para todos los objetos de
la clase Circunferencia 
Cree un programa principal que lea el centro y el radio de una circunferencia, las
coordenadas de un punto y muestre en pantalla la longitud de la circunferencia, el
área del círculo y nos diga si el punto está dentro o no de la circunferencia.

Ejemplo de entrada: 2.1 3.2 5.8 2.2 4.6
-- Salida correcta: 36.4425 105.683 El punto está dentro
Ejemplo de entrada: 2.1 3.2 5.8 2.2 10.36
-- Salida correcta: 36.4425 105.683 El punto no está dentro
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
   // no proporcionamos ningún método del tipo SetRadio o SetCentro
   
   // Si los valores pasados en el constructor no son correctos
   // los datos miembro se quedarán con NAN, indicativo de que
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
// Ampliación:
//	En la siguiente versión se define PI como una constante estática de la clase Circunferencia.
//	El problema es que lo normal es que tengamos en este programa más clases relativas a 
// conceptos de Trigonometría y posiblemente también sea necesario acceder a PI desde dichas clases
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
   cout << "\nÁrea:       " << area;
   
	if (esta_dentro)
		cout << "\nEl punto está dentro";
	else
		cout << "\nEl punto no está dentro";
}

