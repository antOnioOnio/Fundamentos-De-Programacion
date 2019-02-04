/*Queremos construir un programa que simule un juego inspirado en el de los triles (del que procede el nombre de trilero). Suponemos que hay dos participantes y cada uno tiene una caja etiquetada con su nombre. Dentro de cada caja hay una cantidad de dinero y el objetivo es intercambiar las cantidades que hay dentro. */

#include <iostream>
#include <cmath>
using namespace std;


int main() {
    double caja_izqda, caja_dcha;
    double aux; // Esta variable la usaremos de apoyo;
    
    cout << "introduzca dinero en la caja derecha";
    cin >> caja_dcha;
    
    cout << "introduzca dinero en la caja izquierta";
    cin >> caja_izqda;
    
    // intercambiamos ambas con la variable aux
    
    aux = caja_izqda;
    caja_izqda = caja_dcha;
    caja_dcha = aux;
    
    cout << "\nEl valor de la caja derecha es:" <<caja_dcha;
    cout << "\nEl valor de la caja izquierda es:"<< caja_izqda;
    

    return 0;
}
