/*6. Calcule el número de segundos que hay entre dos instantes del mismo día.
Cada instante se caracteriza por la hora (entre 0 y 23), minuto (entre 0 y 59) y segundo (entre 0 y 59).
El programa leerá la hora, minuto y segundo del instante inicial y la hora, minuto y segundo del instante final (supondremos que los valores introducidos son correctos) y mostrará el número de segundos entre ambos instantes. */

#include <iostream>
#include <cmath>


using namespace std;


int main() {
    
    
    //DECLARACION DE VARIABLES
    
    int hora_1, minuto_1, segundo_1, hora_2, minuto_2, segundo_2, momento_inicial;
    int momento_final, diferencia;

    const int hora_segundos = 3600;
    const int minutos_segundos = 60;
    
    //INTRODUCCION DE DATOS MOMENTO INICIAL
    
    cout << "Introduzca hora del momento inicial " ;
    cin >> hora_1 ;
    cout << " Introduzca minuto del momento inicial " ;
    cin >> minuto_1 ;
    cout << " Introduzca segundo del momento inicial " ;
    cin >> segundo_1 ;
    
    // CALCULO PRIMER MOMENTO EN SEGUNDOS
    
    momento_inicial = hora_1*hora_segundos + minuto_1*minutos_segundos + segundo_1;
    
    //INTRODUCCION DE DATOS MOMENTO FINAL
    
    cout << "Introduzca hora del momento final " ;
    cin >> hora_2;
    cout << "Introduzca minuto del momento final " ;
    cin >> minuto_2;
    cout << "Introduzca segundo del momento final " ;
    cin >> segundo_2;
    
    // CALCULO SEGUNDO MOMENTO EN SEGUNDOS
    
    momento_final = hora_2*hora_segundos + minuto_2*minutos_segundos + segundo_2;
    
    // CALCULO DIFERENCIA
    
    diferencia = momento_final-momento_inicial;
    
    // MUESTRA DATOS
    
    cout << "Numero de segundos entre ambos instantes es " << diferencia ;
    
    
  
    
    
    return 0;
}
