
/*9. Recupere la solución del ejercicio 4 (Subir sueldo usando la variable salario_final) Además de mostrar el salario con la subida del 2% se quiere mostrar el salario resultante de subirle otro 3% adicional. Esta segunda subida se realizará sobre el resultado de haber aplicado la primera subida. El programa debe mostrar los salarios resultantes (el resultante de la subida del 2% y el resultante de las dos subidas consecutivas del 2% y del 3%).
Ejemplo de entrada: 30 −− Salida correcta: 30.6 31.518 Ejemplo de entrada: 0 −− Salida correcta: 0 0
Finalidad: Trabajar con expresiones numéricas y con variables para no repetir cómpu- tos. Dificultad Baja.*/



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
