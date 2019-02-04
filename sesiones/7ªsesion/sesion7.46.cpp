// EJERCICIO DE LA SESION 7 Nº 46
// PROGRAMA QUE CALCULA LA SUMA DE FACTORIALES HASTA UN NUMERO N INTRODUCIDO
// ANTONIO GARCIA CASTILLO
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long factorial, suma_factorial;
    int n;
    int multiplicando, cifra;
    
    // INTRODUCION DE DATOS
    do {
    cout << "Introduzca un entero entre 0 y 20: ";
    cin >> n;
    }while ( n < 1 || n > 20 );
    
    // calculos
    for ( cifra=1 ; cifra<=n ; cifra++){
        
        factorial = 1;
        for ( multiplicando=2; multiplicando <= cifra; multiplicando++){
           
            factorial = factorial * multiplicando;
        }
        suma_factorial += factorial;
    }
    // salida de datos
    cout << "\nLa suma de factoriales de " << n << " es " << suma_factorial <<endl;

    return 0 ;
    
    
    
}
