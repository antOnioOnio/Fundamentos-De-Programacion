/*1. Indique cuál sería el resultado de las siguientes operaciones:
    int salario_base;
    int salario_final;
    int incremento;
    salario_base = 1000;
    salario_final = salario_base;
    incremento = 200;
    salario_final = salario_final + incremento;
    salario_base = 3500;
    cout << "\nSalario base:  " << salario_base;
    cout << "\nSalario final: " << salario_final;
   */



#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    int salario_base;
    int salario_final;
    int incremento;
    salario_base = 1000;
    salario_final = salario_base;
    incremento = 200;
    salario_final = salario_final + incremento;
    salario_base = 3500;
    cout << "\nSalario base:  " << salario_base;
    cout << "\nSalario final: " << salario_final;

    return 0;
}
    /*El resultado es
        Salario base: 3500
        Salario final: 1200
     
     Responda razonadamente a la siguiente pregunta: ¿El hecho de realizar la asignación salario_final = salario_base; hace que ambas variables estén ligadas durante todo el programa y que cualquier modificación posterior de salario_base afecte a salario_final? 
        No, solo afecta en el momento. Cualquier modificación de salario base posterior es independiente. */
     
     


