//
//  Programa para empresa de antencion al cliente
//  Ejercicio 4.6
//
//  Created by antonio garcia on 19/10/16.
//  Copyright © 2016 antonio garcia. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    //Declaracion de variables
    
    double salario_hora, satisfaccion, salario_total,incremento_casos, incremento_satisfaccion ;
    int horas_mes, casos_resueltos;
    
    //Introduccion de datos
    cout << " Salario por hora " << endl;
    cin >> salario_hora;
    
    cout << " Horas trabajadas en el mes " << endl;
    cin >> horas_mes;
    
    cout << " Numero de casos resueltos en el mes " << endl;
    cin >> casos_resueltos;
    
    cout << " Grado medio de satisfaccion de los clientes " << endl;
    cin >> satisfaccion;
    
    //calculos
    salario_total = salario_hora * horas_mes;
    incremento_casos = salario_total*0.04;
    incremento_satisfaccion = salario_total*0.02;
    
    
    // Salida de datos
    if (casos_resueltos > 30 && satisfaccion >= 4) {
        
        
        salario_total = salario_total + incremento_satisfaccion + incremento_casos;
        
        cout << " salario total es " << salario_total <<endl;
        
        }
    
    if (casos_resueltos<30 && satisfaccion >=4){
        
        salario_total = salario_total + incremento_satisfaccion;
        
        cout << " salario total es " << salario_total <<endl;
        
    }
    
    if (casos_resueltos >30 && satisfaccion <4){
   
        salario_total = salario_total + incremento_casos;

        
        cout << " salario total es " << salario_total <<endl;
    
    
    }
    else {
        
        cout << " salario total es " << salario_total <<endl;
    }
    // fin del programa
    
    return 0;
}
