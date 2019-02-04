// EXAMEN BALONCESTO
// ANTONIO GARCIA CASTILLO

#include <iostream>
using namespace std;


int main (){
    
    const char FIN = 'S';
    char equipo, ganador;
    int anotacion, minuto, numero_triples=0, total_A=0, total_B=0;
    bool es_triple ;
    bool equipo_A , equipo_B ;
    
    
    do {
        
        cout << " Equipo: " ;
        cin >> equipo;
    equipo_A = equipo == 'A';
    equipo_B = equipo == 'B';
        
    }while (( equipo_A == false && equipo_B == false) && equipo != FIN);
    
    while (equipo != FIN){
        
        do {
            cout << " Anotacion: " ;
            cin >> anotacion;
            
            es_triple = anotacion == 3;
            
        }while ( anotacion <1 || anotacion > 3);
        
        
        if ( es_triple == true) {
            numero_triples++;
        }
        
        if ( equipo_A == true )
            total_A += anotacion;
        
        else {
            total_B += anotacion;
        }
        
        do {
            
            cout << " minuto: ";
            cin >> minuto;
        
        }while ( minuto<0);
        
        
        do {
            
            cout << " Equipo: " ;
            cin >> equipo;
            equipo_A = equipo == 'A';
            equipo_B = equipo == 'B';
            
        }while (( equipo_A == false && equipo_B == false) && equipo != FIN);
    
    }
    
    
    if ( total_A>total_B){
        
        ganador = 'A';
    }
    else {
        ganador = 'B';
    }
    
    cout << " El resultado fue equipo A : " <<total_A  << " equipo B : " <<total_B << endl;
    cout << " ganador : " << ganador << endl;
    cout << " Total triples en el partido "<< numero_triples <<endl;
    
    return 0;
}


