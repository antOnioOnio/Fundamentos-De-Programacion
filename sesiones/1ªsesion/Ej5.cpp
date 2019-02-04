//Un banco presenta la siguiente oferta. Si se deposita una cantidad de euros dada por la variable capital durante un año a plazo fijo, se dará un interés dado por la variable interes. Realice un programa que lea una cantidad capital y un interés interes desde teclado. A continuación, el programa debe calcular en una variable total el dinero que se tendrá al cabo de un año, aplicando la fórmula de abajo e imprimirá el resultado en pantalla.


#include <iostream>
#include <cmath>

using namespace std;



int main() {
    
    double capital,interes,dinero_total ;
    
    cout << " introduzca el capital a depositar " ;
    cin >> capital;
    
    cout << " introduzca el intereses deseado " ;
    cin >> interes ;
    
    dinero_total = capital + capital * interes / 100 ;
    
    cout << "\nEl dinero que usted tendra al cabo de un año es : " << dinero_total;
    
    
    
}
