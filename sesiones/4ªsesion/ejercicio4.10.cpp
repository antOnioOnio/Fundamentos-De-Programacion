/*20. Programa que calcula el dinero a pagar por la estancia de un coche en un parkin. */

#include <iostream>
#include <cmath>


using namespace std;


int main() {
    
    
    //DECLARACION DE VARIABLES
    
    const int HORA_SEGUNDOS = 3600;
    const int MINUTOS_SEGUNDOS = 60;
    
    const double TARIFA_1 = 0.042;
    const double TARIFA_2 = 0.0370;
    const double TARIFA_3 = 0.0311;
    const double TARIFA_4 = 0.0305;
    const double TARIFA_UNICA = 31.55;
    
    int hora_1, minuto_1, segundo_1, hora_2, minuto_2, segundo_2, momento_inicial;
    int momento_final, tiempo_total;
    double a_pagar;
    
   
    //INTRODUCCION DE DATOS MOMENTO INICIAL
    
    cout << "Introduzca hora del momento inicial " ;
    cin >> hora_1 ;
    cout << " Introduzca minuto del momento inicial " ;
    cin >> minuto_1 ;
    cout << " Introduzca segundo del momento inicial " ;
    cin >> segundo_1 ;
    
    
    // CALCULO PRIMER. MOMENTO EN SEGUNDOS
    
    momento_inicial = hora_1*HORA_SEGUNDOS + minuto_1*MINUTOS_SEGUNDOS + segundo_1;
    
    //INTRODUCCION DE DATOS MOMENTO FINAL
    
    cout << "Introduzca hora del momento final " ;
    cin >> hora_2;
    cout << "Introduzca minuto del momento final " ;
    cin >> minuto_2;
    cout << "Introduzca segundo del momento final " ;
    cin >> segundo_2;
    
    // CALCULO SEGUNDO. MOMENTO EN SEGUNDOS
    
    momento_final = hora_2*HORA_SEGUNDOS + minuto_2*MINUTOS_SEGUNDOS + segundo_2;
    
    // CALCULO DIFERENCIA
    
    tiempo_total = (momento_final-momento_inicial)/60;
    
    
    if ( tiempo_total ==0 ){
        
        cout << " Gracias por su corta visita " ;
    }
    
    if (tiempo_total>0 && tiempo_total<=30){
        
        a_pagar = tiempo_total*TARIFA_1;
        
        cout << " Total a pagar es " <<a_pagar;
        
    } if (tiempo_total > 30 && tiempo_total <=90){
        
        
        a_pagar = tiempo_total*TARIFA_2;
        
        cout << " Total a pagar es " <<a_pagar;
        
    } if (tiempo_total > 90 && tiempo_total <=120){
        
        
        a_pagar = tiempo_total*TARIFA_3;
        
        cout << " Total a pagar es " <<a_pagar;
        
    }if (tiempo_total > 120 && tiempo_total <=660){
        
        
        a_pagar = tiempo_total*TARIFA_4;
        
        cout << " Total a pagar es " <<a_pagar;
        
        
    }if ( tiempo_total > 660 ){
        
        a_pagar = TARIFA_UNICA;
    
        cout << " Total a pagar es "
        <<a_pagar << endl;
    }
    return 0;
    
}









