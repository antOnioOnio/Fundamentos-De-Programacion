
/*Construya un programa que vaya leyendo datos desde teclado e introdúzcalos en un vector. La entrada de datos termina con el -1. A continuación lea el real de referencia y el entero k Calcule el vector mayores_que e imprímalo en pantalla.
Aplique el siguiente algoritmo:
Copiar el vector original en "mayores_que"
Ordenar el vector "mayores_que" de menor a mayor
(utilizar el algoritmo de ordenación por inserción)
Seleccionar los k primeros que sean mayores que la referencia*/

// Ejercicio 3 de la sesion nº 11
// Antonio Garcia Castillo

#include <iostream>


using namespace std;

int main (){
    const int FIN = -1;
    const long long TAMANIO = 10000; // tamaño vectores
    int k; // para mostrar los k elementos del vector mayores_que
    int usados_vector = 0, usados_mayores = 0;
    double vector[TAMANIO];
    double mayores_que[TAMANIO];
    double dato, referencia;
    double auxiliar ; // nos valemos de esta variable para ordenar los elementos del vector mayores_que
    
    //entrada de datos, los cuales acumulamos en el vector " vector "
    
    cout << " Introduce los datos correspondientes del vector: "<<endl;
    cin >> dato;
    
    while ( dato != FIN && usados_vector < TAMANIO ){
        vector[usados_vector] = dato;
        usados_vector++;
        cin >>dato;
    }
    
    
    cout << " Introduce el valor minimo de referencia: "<<endl;
    cin >> referencia;
    
    // Rellenamos el vector mayores_que
    for ( int i = 0 ; i < usados_vector ; i++){
        
        if (vector[i] > referencia){
            mayores_que[usados_mayores] = vector[i];
            
            usados_mayores++;
        }
    }
    for (int i=0 ; i < usados_mayores ; i++){
        
        for ( int j = i ; j < usados_mayores ; j++){
            
            if ( mayores_que[i] > mayores_que[j]) {
                
                auxiliar = mayores_que[i];
                
                mayores_que[i] = mayores_que[j];
                
                mayores_que[j] = auxiliar;
                
            }
        }
    }
        

    cout << " Introduce el numero de elementos a mostrar "<< endl;
    cin >> k;
    
    for ( int i=0 ;  i <= usados_mayores && i<k ;i++){
        
        cout << mayores_que[i] << " ";
    
    }
    cout << endl;
    
    return 0;
}
