/*
Recupere la solución del ejercicio 10 (función gaussiana) de la relación de problemas I.
 Se pide construir un programa para imprimir el resultado de aplicar dicha función a varios valores de abscisas.
 En primer lugar, se leerán los parámetros que den en la función, es decir, la esperanza y la desviación.
 La esperanza puede ser cualquier valor, pero para leer el valor de desviación debe utilizar
 un bucle y obligar a que sea mayor o igual que cero.
 A continuación el programa pedirá un valor minimo, un valor maximo y un incremento.
 El valor maximo ha de leerse con un fltro de entrada obligando a que sea mayor que minimo.
 El programa mostrará el valor de la función gaussiana en todos los valores de x (la abscisa) entre minimo y maximo a saltos de incremento,
 
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    
    // DECLARACION DE VARIABLES
    
    const double PI = 3.1415927;
    double desviacion_tipica, media,valor_maximo, valor_minimo, incremento;
    double contador ; // nos sirve de apoyo para el incremento
    double g_1, g_2, g_t; // para la ecuacion de gaussiana
    
    // ENTRADA DE DATOS
    
    cout << " Introduce el valor de la esperanza ( media )  :" <<endl;
    cin >> media;
    
    do {                //valor de la desviacion tipica tiene que ser mayor que cero, filtro para ello
        cout << "Introduce el valor de la desviacion típica ( mayor que cero): " <<endl;
        cin >>desviacion_tipica;
    }while ( desviacion_tipica <0);
    
    cout << " Introduce un valor minimo: " << endl ;
    cin >> valor_minimo;
    
    do {               // valor del maximo tiene que ser mayor que el minimo, filtro para ello
        cout << "Introduce el valor del maximo:" <<endl;
        cin >>valor_maximo;
    }while ( valor_maximo<valor_minimo);
    
    cout << "Introduce un incremento: " <<endl;
    cin >> incremento;
    
    
    
    // CALCULOS
    
    contador = valor_minimo; // Igualamos el contador al valor minimo
    g_1 = (1/(desviacion_tipica*sqrt(PI*2))); // primera parte de la funcion, constante
    
    while (contador <= valor_maximo){
    
        g_2 = exp( -0.5 * pow( (contador - media)/desviacion_tipica,  2) ); // incluimos variables a la funcion
        g_t = g_1 * g_2 ;
        
        cout << "Valor en "<<contador <<" es igual a "  <<g_t << endl;
    
        contador += incremento ;
    }
    
    return 0 ;
}

