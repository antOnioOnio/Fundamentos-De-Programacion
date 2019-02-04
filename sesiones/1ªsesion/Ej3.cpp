/*  Programa que nos pidae la longitud del radio y calcula el área del círculo y la longitud de la circunferencia correspondientes. Finalmente, el programa mostrará en pantalla los resultados.
 */

#include <iostream>
#include <cmath>

using namespace std;


int main () {
    
    const double PI = 3.1416;
    double radio,longitud,area ;
    
    
    cout << " introduzca el valor del radio " ;
    cin >> radio;
    
    area = PI * radio * radio;
    longitud = 2 * PI * radio;
    
    cout << "\nEl area del círculo es : " << area;
    
    cout << "\nla longitud del círculo es : " << longitud;

    return 0;
    
    
    
    
    
  
}
