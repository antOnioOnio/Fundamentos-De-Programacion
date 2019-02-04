/*
 29. Construya un programa que calcule cuándo se produjo la mayor secuencia de días consecutivos con temperaturas crecientes. El programa leerá una secuencia de reales representando temperaturas, hasta llegar al -1 y debe calcular la subsecuencia de números ordenada, de menor a mayor, de mayor longitud.
 El programa nos debe decir la posición donde comienza la subsecuencia y su longitud.*/

#include <iostream>

using namespace std;

int main() {
    const int TERMINADOR = -1;
    double temperatura_dia_anterior, temperatura_dia_posterior;
    int longitud_maxima, longitud_actual, posicion_secuencia, posicion_total, posicion_comienzo;
    
    
    cout << " Indique la temperatura del primer dia " <<endl;
    cin >> temperatura_dia_anterior;
    
    cout << " indique la temperatura del dia siguiente " <<endl;
    cin >> temperatura_dia_posterior;
    
    
    
    posicion_secuencia=1;
    posicion_total=1;
    posicion_comienzo=1;
    longitud_maxima=1;
    longitud_actual=1;
    
    
    while ( temperatura_dia_posterior != TERMINADOR){
        posicion_total++;
        
        if (temperatura_dia_posterior > temperatura_dia_anterior){
            longitud_actual++;
            
            if(posicion_comienzo==posicion_secuencia){
                longitud_maxima++;
                
            }
            else if (longitud_actual > longitud_maxima){
                
                longitud_maxima = longitud_actual;
                posicion_comienzo = posicion_secuencia;
            }
            
        }else{
            longitud_actual=1;
            posicion_secuencia=posicion_total;
        }
        
        temperatura_dia_anterior = temperatura_dia_posterior;
        
        cout << " Indique la temperatura del dia siguiente " <<endl;
        cin >> temperatura_dia_posterior;
        
    }
    
    cout << " La secuencia de mayor duracion empezo en el dia " << posicion_comienzo << " y ";
    cout << " La longitud fue de " << longitud_maxima << " dias "<<endl ;
  
    

    return 0;
    
}
