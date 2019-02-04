/*Construya un programa que lea desde teclado tres variables correspondientes a un número de horas, minutos y segundos, respectivamente. A continuación, el programa debe calcular las horas, minutos y segundos dentro de su rango correspondiente. Por ejemplo, dadas 312 horas, 119 minutos y 1291 segundos, debería dar como resultado 13 días, 2 horas, 20 minutos y 31 segundos. El programa no calculará meses, años, etc. sino que se quedará en los días.*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    //DECLARACION DE VARIABLES
    
 
    int dias, horas,  minutos, segundos;
    
    //INTRODUCCION DE DATOS
    
    cout << "Introduce las horas: " ;
    cin >> horas;
    cout << "Introduce los minutos:" ;
    cin >> minutos;
    cout << "Introduce segundos:" ;
    cin >> segundos;
    
    //Calculos
    
    minutos = minutos + segundos/60;
  
    segundos = segundos % 60 ;
    
    horas = horas + minutos/60 ;
    
    minutos = minutos % 60 ;
    
    dias = horas/24 ;
    
    horas = horas % 24 ;
    
    
    
    //muestra resultados
  
    cout <<"\ndias"<< dias;
    cout <<"\nhoras "<<horas;
    cout <<"\nminutos " <<minutos;
    cout <<"\nsegundos" <<segundos;
    return 0;
}
