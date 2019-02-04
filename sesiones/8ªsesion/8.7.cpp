 /*Retome la solución del ejercicio 48 (Gaussiana) y modifíquela introduciendo funciones dónde crea conveniente. Al menos debe definir la función para que calcule el valor de la ordenada, para unos valores concretos de abscisa, esperanza y desviación. */
// Ejercicio 7 de la sesion 8. Antonio Garcia Castillo


#include <iostream>
#include <cmath>


using namespace std;

// funcion Gaussiana
double Gaussiana(double esperanza_media, double desviacion_tipica, double variable){

    const int PI = 3.1415;
    double g_1, g_2, valor;
    
    g_1 = (1/(desviacion_tipica*sqrt(PI*2))); // primera parte de la funcion
    
    g_2 = exp( -0.5 * pow( (variable - esperanza_media)/desviacion_tipica,  2) ); // incluimos variables a la funcion
    
    valor = g_1 * g_2 ;
    
    return valor ;
}

int main() {
  
    
    // DECLARACION DE VARIABLES
    

    double desviacion_tipica, media, variable, valor_gaussiana;
    
    // ENTRADA DE DATOS
    
    do{
    cout << " desviacion tipica ";
    cin >> desviacion_tipica;
    }while (desviacion_tipica <=0);
        
    cout << " Esperanza media ";
    cin >> media;
    
    cout << " Valor de la variable ";
    cin >> variable;
    
    // CALCULOS
    
    valor_gaussiana = Gaussiana(media, desviacion_tipica,variable);
    
    // MUESTRA RESULTADOS
    
    cout << " valor gaussiana es " << valor_gaussiana <<endl;
    

    return 0;
}
