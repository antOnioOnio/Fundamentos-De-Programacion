/* Se quiere generalizar el ejercicio 7 que intercambiaba el valor de dos variables al caso de tres variables. Construya un programa que declare las variables x  ,   y   , lea su valor desde teclado e intercambien entre sí sus valores de forma que el valor de pasa a   , el de   pasa a   y el valor de   pasa a   (se pueden declarar variables auxiliares aunque se pide que se use el menor número posible */



#include <iostream>
#include <cmath>
using namespace std;


int main() {
    double variable_x, variable_y, variable_z, aux;
    
    
    cout << "introduzca variable x";
    cin >> variable_x;
    
    cout << "introduzca variable y";
    cin >> variable_y;
    
    cout << "introduzca variable z";
    cin >> variable_z;
    
    
    // intercambiamos ambas con la variables con aux
    
    aux = variable_y;
    variable_y = variable_x;
    variable_x = variable_z;
    variable_z = aux;
    
    cout << "\nEl valor de la variable x:" << variable_x;
    cout << "\nEl valor de la variable y:" << variable_y;
    cout << "\nEl valor de la variable z" <<  variable_z; 
    return 0;
}
