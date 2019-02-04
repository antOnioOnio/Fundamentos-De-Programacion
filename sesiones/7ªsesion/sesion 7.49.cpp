// EJERCICIO DE LA SESION 7 Nº 49
// PROGRAMA QUE DIVIDE UN ENTERO EN UNA SECUENCIA DE NUMEROS ENTEROS
// SIEMPRE Y CUANDO SEA SECUENCIABLE EN NUMEROS SEGUIDOS
// ANTONIO GARCIA CASTILLO

#include <iostream>
using namespace std ;

int main() {
    
    int acumulador, numero, n, i , r;
    
    // introduccion de datos
    
    do {
        cout << " introduce un numero positivo : " << endl ;
        cin >> numero;
    }while (numero<0);
    
;
    // inicializamos desde 0
    for (i=0; i<numero ; i++){
    
        acumulador = 0;
        
        n = i;
        
        while ( acumulador < numero) {
        
            acumulador += n;
            
            if (acumulador == numero){ // si la suma de los anteriores es = al numero entramos
            
                cout << " \n" << numero << "= " ;
                
                for ( r = i ; r<n ; r++){
                    
                    cout << r << " + " ;
                }
                cout << n ;
            }
            
            n++;
        }
    }
    return 0;
}
