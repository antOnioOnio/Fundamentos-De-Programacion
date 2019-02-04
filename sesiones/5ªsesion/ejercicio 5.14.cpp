/*Modifique la solución del ejercicio 8 (año bisiesto) para que no se mezclen E/S y C (entradas/salidas y cómputos) dentro de la misma estructura condicional.
 Finalidad: Diseñar programas que separen Entradas/Salidas y cómputos. Dificultad Baja.*/


#include <iostream>
using namespace std;



int main() {
    
    // declaracion de variables
    int anio;
    bool bisiesto;
    
    //introduccion de datos
    cout << " Introduzca el año " <<endl;
    cin >> anio;
    
    bisiesto = anio % 400 == 0 || (anio % 4 == 0 && anio %100 > 0);
    
    if (bisiesto) {
    
        cout << anio << " es un año bisiesto " << endl ;
    
    }
    else {
    
        cout << anio << " no es un año bisiesto " << endl ;
    }
    
    return 0;
    
}
