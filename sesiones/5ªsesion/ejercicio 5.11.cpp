/* Programa para empresa de atención al cliente sesion 5, ejercicio 11.
 Subidas de salario en funcion de las horas trabajadas, casos resueltos y grado de satisfaccion.
 Antonio Garcia Castillo
 */


#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    //Declaracion de variables
    
    const double INCREMENTO_CASOS_4 = 0.04;
    const double INCREMENTO_CASOS_3 = 0.03;
    const double INCREMENTO_SATISFACCION = 0.02;
    
    double salario_hora,salario_total, grado_satisfaccion;
    double inc_casos_20_30, inc_casos_30, inc_satisfaccion;
    
    int horas_mes, casos_resueltos;
    
    //Introduccion de datos
    cout << " Salario por hora " << endl;
    cin >> salario_hora;
    
    cout << " Horas trabajadas en el mes " << endl;
    cin >> horas_mes;
    
    cout << " Numero de casos resueltos en el mes " << endl;
    cin >> casos_resueltos;
    
    cout << " Grado medio de satisfaccion de los clientes " << endl;
    cin >> grado_satisfaccion;
    
    //calculos
    salario_total = salario_hora * horas_mes;
    inc_casos_20_30 = salario_total*INCREMENTO_CASOS_3;
    inc_casos_30 = salario_total*INCREMENTO_CASOS_4;
    inc_satisfaccion = salario_total*INCREMENTO_SATISFACCION;
    
    
    
    // Salida de datos
    
    if(casos_resueltos>=20 && casos_resueltos<=30){
        
        
        if(grado_satisfaccion>=4){
            
            salario_total = salario_total + inc_casos_20_30 + inc_satisfaccion;
            
        }else{
            
            salario_total = salario_total + inc_casos_20_30;
            
        }
    }
    
    if( casos_resueltos>30){
        
        if(grado_satisfaccion>=4){
            
            salario_total = salario_total + inc_casos_30 + inc_satisfaccion;
            
        }else{
            
            salario_total = salario_total + inc_casos_30;
        }
    }
    
    else {
        
        salario_total = salario_total;
    
    }
    
    // MUESTRA RESULTADOS
    
    cout << " Salario total es de " <<salario_total <<endl;
    
    // fin del programa
    
    return 0;
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
