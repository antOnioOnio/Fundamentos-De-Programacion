

/*Realice un programa que lea los coeficientes reales μ y de una función gaussiana. A continuación el programa leerá un valor de abscisa x y se imprimirá el valor que toma la función en x */




#include <iostream>
#include <cmath> 
using namespace std;

int main() {

    
    // DECLARACION DE VARIABLES
    
    const double PI = 3.1416;
    double desviacion_tipica, media, variable, valor_gaussiana;
 
    // ENTRADA DE DATOS
    
    cout << " desviacion tipica ";
    cin >> desviacion_tipica;
    
    cout << " media ";
    cin >> media;
    
    cout << " variable ";
    cin >> variable;
    
    // CALCULOS
    
    valor_gaussiana = (1/desviacion_tipica*sqrt(PI*2))*(exp(-0.5*pow((variable-media)/desviacion_tipica,2)));
    
    // MUESTRA RESULTADOS
    
    cout << " valor gaussiana es " << valor_gaussiana;
    
    return 0 ;
}
