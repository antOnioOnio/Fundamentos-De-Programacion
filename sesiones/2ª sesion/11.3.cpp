/*  Re-escriba las soluciones de los ejercicios 3, 9, 6, 10 (circunferencia, subir sueldo, diferencia de tiempo, gaussiana) utilizando datos de tipo constante en aquellos sitios donde considere oportuno.
 */

#include <iostream>
#include <cmath>

using namespace std;


int main () {
    
    //DECLARACION DE VARIABLES
    const double PI = 3.1416;
    double radio,longitud,area ;
    
    //INTRODUCCION DE DATOS
    
    cout << " introduzca el valor del radio " ;
    cin >> radio;
    
    //CALCULOS
    area = PI * radio * radio;
    longitud = 2 * PI * radio;
    
    //MUESTRA RESULTADOS
    cout << "\nEl area del círculo es : " << area;
    cout << "\nla longitud del círculo es : " << longitud;
    
    return 0;
    
    
    
    
    
    
}
