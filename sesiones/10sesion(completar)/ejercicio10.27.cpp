/* Recupere la solución del ejercicio 8 de esta relación de problemas sobre la función gaussiana. En vez de trabajar con funciones, plantee la solución con una clase. Debe diseñar la clase teniendo en cuenta que la función matemática gaussiana viene determinada unívocamente por el valor de la esperanza y la desviación, es decir, son estos dos parámetros lo que distinguen a una función gaussiana de otra.*/

// Antonio Garcia Castillo
// Ejercicio 27 de la Sesion nº10


/* hay que meterle dos constructores, el primero sin parametros y el segundo con los parametros que modificaran lo declarado en private.
 ella:
 double leedoublemayorigualque ( double minimo, string mensaje ) {
 double a leer;
 
en private bien, esperanza y desviacion..bien
 en public 
 gaussiana ( double esperanza y double desviacion
 iguala estas a las de privado
 }
 double evalua
*/
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.1414;


class Gaussiana {

    private :
    
    double esperanza_media = 0;
    double desviacion_tipica = 0;
    
    public :
    
    void SetEsperanza( double esperanza){
    
        esperanza_media= esperanza;
    }
    void SetDesviacion ( double Desviacion) {
    
        desviacion_tipica = Desviacion;
    }
    double GetEsperanza (){
    
        return esperanza_media;
    }
    double GetDesviacion (){
    
        return desviacion_tipica;
    }
    double GetGaussiana( double abcisa){
    
        double gaussiana =  1/( desviacion_tipica *sqrt(2*PI))*exp( -0.5 * pow( (abcisa - esperanza_media)/desviacion_tipica,  2) );
    
        return gaussiana;
    }
    Gaussiana(){
        esperanza_media = 0;
        desviacion_tipica = 0;
    
    
    }
    
};

// Funcion Main
int main (){

    
    Gaussiana gau1;
    
    // Declaracion de variables
    
    double valor_gaussiana, variable_abcisa, desviacion_tip, esperanza_med;
    
    
    // Introducción de datos
    do{
    cout << "Introduce una desviación típica mayor que cero: " <<endl;
    cin >> desviacion_tip;
    }while( desviacion_tip <0 ) ;
    
    cout << " Introduce una esperanza media: " <<endl;
    cin >> esperanza_med;
    
    cout << " Introduce un valor para la variable: " <<endl;
    cin >> variable_abcisa;
    
    gau1.SetEsperanza(esperanza_med);
    gau1.SetDesviacion(desviacion_tip);
    
    
    valor_gaussiana = gau1.GetGaussiana(variable_abcisa);
    
    // Muestra resultados
    
    cout << " El valor de gaussiana es: " << valor_gaussiana <<endl;
    
    
    
}
