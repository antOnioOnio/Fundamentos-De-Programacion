/* Construya un programa que lea caracteres con cin.get() hasta que el usuario introduzca el carácter #. Almacene todos los valores en un vector de caracteres. A continuación, calcule la moda y muéstrela en pantalla junto con su frecuencia.
*/
// Problema 4 de la sesion 11 de ejercicios
// Antonio Garcia Castillo


#include <iostream>

using namespace std;

//Struct dado

struct FrecuenciaCaracter{
    char caracter;
    int frecuencia=0;
};

int main (){
    const int TAMANIO=255;
    const char FIN='#';
    FrecuenciaCaracter vector[TAMANIO];
    char caracter;
    int posicion_caracter=-1, frecuencia_max=0;
    int usados=0;

    
    cout << " Introduzca una series de caracteres seguidos. Para finalizar introduzca # "<< endl;
    
    //Lectura de datos con la funcion cin.get()
    
    caracter=cin.get();
    

    
    while ( caracter != FIN && usados < TAMANIO){
        
        vector[caracter].caracter = caracter ; // vamos acumulando caracteres en el vector
        vector[caracter].frecuencia++ ;      // vamos aumentando la frecuencia cada vez que se repite un caracter
        
    
        
        if ( vector[caracter].frecuencia > frecuencia_max ){
            
            frecuencia_max = vector[caracter].frecuencia;   // Acumulamos la frecuencia maxima
            posicion_caracter = caracter;
        }
        
        usados++;
        
        
        caracter=cin.get();
    }
    
    //muestra datos
    cout << "El caracter de MODA es : " << vector[posicion_caracter].caracter << endl;
    cout << " Ha aparecido un total de " << frecuencia_max << " veces " <<endl;
    
    return 0;
    
    
}
