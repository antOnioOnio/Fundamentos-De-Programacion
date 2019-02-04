/*Cree un programa que lea el número de un año e indique si es bisiesto o no. Un año es bisiesto si es múltiplo de cuatro, pero no de cien. Excepción a la regla anterior son los múltiplos de cuatrocientos que siempre son bisiestos. Por ejemplo, son bisiestos: 1600,1996, 2000, 2004. No son bisiestos: 1700, 1800, 1900, 1998, 2002*/


#include <iostream>
using namespace std;



int main() {
 
    // declaracion de variables
    int anio;
    
    //introduccion de datos
    cout << " Introduzca el año " ;
    cin >>anio;
    
    if (anio % 4 == 0 && anio %100 > 0) {
        
        
        
        cout <<anio << " " << "es un año bisiesto" << endl;
        
        
    }else if(anio %4 ==0 && anio % 400 ==0){
    
        cout << anio << " " << "es un año bisiesto" << endl;
    
    
    }
     
    else
        
        cout << anio << " " << "no es un año bisiesto "<< endl;
    
    
    
    return 0;
    
}
