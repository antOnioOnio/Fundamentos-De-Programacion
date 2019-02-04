//
//  Programa para empresa de antencion al cliente
//  Ejercicio 4.5
//
//  Created by antonio garcia on 19/10/16.
//  Copyright © 2016 antonio garcia. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    //Declaracion de variables
    
    double salario_hora, satisfaccion, salario_total;
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
    
    salario_total = horas_mes*salario_hora;
    
    // Salida de datos
    if (casos_resueltos > 30) {
        
        
        salario_total = salario_total + salario_total*0.04;
        
        cout << " salario total es " << salario_total <<endl;
    }else {
        
        
        cout << " salario total es " << salario_total;
        
    }
    // fin del programa
    
    return 0;
}
