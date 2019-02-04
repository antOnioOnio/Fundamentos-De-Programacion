// ejercicion Nº 3 de la sesion 7
// Usaremos una funcion Max que calculara el valor maximo de dos valores.
// Despues otra funcion Max3  que llamara a la funcion Max e incluira un tercer valor,
// La funcion Max 3 calculara el maximo de los tres valores
// Antonio Garcia Castillo

#include <iostream>
using namespace std ;

// Hacemos una funcion que calcula el maximo de dos valores
double Max(double valor_1, double valor_2){
    
    
        double maximo;
        if ( valor_1>valor_2){
            maximo = valor_1;
            
        }else{
            maximo = valor_2;
        }
    return maximo;

}
// Hacemos una funcion que llama a la funcion anterior y la compara con otro valor
double Max3(double valor_1, double valor_2, double valor_3){
  
    double maximo;
    
    maximo = Max(valor_1, valor_2);
    
    if (valor_3>maximo){
        maximo = valor_3;
    }
    return maximo;
    
}

int main() {
   
    // Declaracion de variables
    double valor_a, valor_b,valor_c, maximo;
    
    // Entrada de datos
    cout << " Introduce primer valor ";
    cin >> valor_a;
    cout << " Introduce segundo valor ";
    cin >> valor_b;
    cout << " Introduce tercer valor ";
    cin >> valor_c;
    // Calculos
    maximo =Max3(valor_a, valor_b, valor_c);
    
    // Salida
    cout << " \nMaximo de los tres valores es : " << maximo <<endl;
    return 0;
}
