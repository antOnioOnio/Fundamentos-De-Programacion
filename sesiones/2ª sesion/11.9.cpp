/*Re-escriba las soluciones de los ejercicios 3, 9, 6, 10 (circunferencia, subir sueldo, diferencia de tiempo, gaussiana) utilizando datos de tipo constante en aquellos sitios donde considere oportuno. */

#include <iostream>
#include <cmath>

using namespace std;


int main () {
    
    // DECLARACION DE VARIABLES
    const double INCREMENTO_1 = 1.02, INCREMENTO_2 = 1.03;
    double salario_base, salario_incrementado, salario_final;
    
    
    //ENTRADA DE DATOS
    cout << " introduzca el salario base ";
    cin >> salario_base;
    
    // CALCULOS
    salario_incrementado = salario_base * INCREMENTO_1 ;
    salario_final = salario_incrementado * INCREMENTO_2 ;
    
    // MUESTRA DATOS
    cout << "\nSalario base: " << salario_base;
    cout << "\nSalario incrementado: " << salario_incrementado;
    cout << "\nSalario final: " << salario_final;
    
    return 0 ;
    
}
