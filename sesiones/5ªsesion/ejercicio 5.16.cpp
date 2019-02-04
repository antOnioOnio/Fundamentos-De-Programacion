/*Modifique el ejercicio 7 para que el programa nos diga si los tres valores leídos es- tán ordenados de forma ascendente, ordenados de forma descendente o no están ordenados. Para resolver este problema, debe usar una variable de tipo enumerado */

#include <iostream>

using namespace  std;


int main() {
    
    enum Orden {ascendente, descendente, desordenados, mismo_numero}
    
    Orden=ascendente;
    
    
    // Declaracion de variables
    
    int numero_x,numero_y,numero_z;
    
    bool orden_ascendente, orden_descendente, constante;
    
    //introduccion de datos
    cout << " introduce x" << endl;
    cin >> numero_x;
    cout << " introduce y" << endl;
    cin >> numero_y;
    cout << " introduce z" << endl;
    cin >> numero_z;
    
    orden_descendente = numero_x>numero_y&&numero_y>numero_z;
    orden_ascendente = numero_x<numero_y&&numero_y<numero_z;
    constante = numero_x == numero_y && numero_y==numero_z;
   
    
    //identificamos que enum es cada uno
    
    if (orden_descendente){
        Orden=descendente;
    }
    
    else  if (orden_ascendente){
        Orden=ascendente;
    }
    else if ( constante ){
        Orden=mismo_numero;
    }
        
    else{
        Orden = desordenados;
    }
    
   // mostramos resultados en funcion del orden
    
    if (Orden == descendente) {
        cout << " El orden de los numeros es descendente" << endl;
    }
    
    else if (Orden == ascendente) {
        cout << " El orden de los numeros es ascendente" << endl;
    }
    
    else if ( Orden == mismo_numero){
        cout << " El numero introducido es el mismo, luego es una constante " <<endl;
    
    }
    else if (Orden == desordenados){
        cout << " Los numeros no estan ordenados" << endl;
    }
    
    
    
    


    return 0;
}
