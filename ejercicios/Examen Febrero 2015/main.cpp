/*[top k]. (Examen Febrero 2015) Se dispone de una serie de datos pluviométricos de varios años, en concreto del número de litros que han caído en un día en cada una de las ciudades del mundo. Se quiere calcular los k mayores índices pluviométricos, ordenados de mayor a menor. Se pide implementar el siguiente algoritmo:
Construya un programa que vaya leyendo datos desde teclado hasta que se introduzca -1. A continuación lea el número k y aplique el siguiente algoritmo:
Ordenar el vector de mayor a menor
(se recomienda usar el algoritmo de ordenación por inserción)
Seleccionar los k primeros e introducirlos
en topk
Finalmente, imprima los valores del vector topk en pantalla.
Ejemplo de entrada: 2.1 0.7 12.4 2.6 3.2 -1 2 −− Salida correcta:
12.4 3.2
Posteriormente se verá una versión mejorada de este ejercicio. Finalidad: Ordenación de un vector. Dificultad Baja.*/

#include <iostream>
using namespace std;


// funcion para leer datos pluviometricos
double LeePluviometria ( int minimo, string mensaje) {
    
    double dato;
    do{
        cout << mensaje;
        cin >> dato;
    }while (dato < minimo);
    
    return dato;

}
// funcion para leer un valor k positivo
int LeeIntPositivo( int minimo, string mensaje ) {

    int k ;
    do {
        cout << mensaje;
        cin >> k ;
    }while (k < minimo);
    

    return k;
}
// FUNCION MAIN
int main (){
    
    const int CAPACIDAD = 20000;
    const string
    MSJ_DATO = " Introduce datos pluviometricos \n",
    MSJ_K = " Introduce valor K \n";
    const int FIN = -1;
    double pluviometria[CAPACIDAD], topK[CAPACIDAD];
    double dato;
    int usados_vector = 0, k ;
    double aux=0;
    
    dato=LeePluviometria(-2, MSJ_DATO);
    
    while ( dato != FIN && usados_vector < CAPACIDAD ){
        
        pluviometria[usados_vector]=dato;
        usados_vector++;
        
        dato=LeePluviometria(-2, MSJ_DATO);
        
    }
    for (int i = 0 ; i < usados_vector ; i++){
        for (int  j = i ; j< usados_vector ; j++){
        
            if ( pluviometria[i]<pluviometria[j]){
                
                aux = pluviometria[i];
                pluviometria[i] = pluviometria[j];
                pluviometria[j] = aux ;
            }
        
        
        }
        for ( int i = 0 ; i < CAPACIDAD ; i++);
        
    
    }
    k = LeeIntPositivo(0, MSJ_K);
    
    for ( int i= 0; i < k+1 ; i++){
        
        topK[i]= pluviometria[i];
    
    
    }
    
    
    for ( int i= 0; i < k ; i++){
        
        cout << topK[i] << " " ;
        
        
    }


}
