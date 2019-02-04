/*Sobre la clase SecuenciaCaracteres añada el método para eliminar todas las apariciones de un determinado carácter. Implementar el siguiente algoritmo:
 Recorrer todo el vector, si la componente del vector es igual al caracter a borrar, eliminarlo y desplazar a la izquierda los componentes que hay a su derecha.*/

#include <iostream>
using namespace std;

struct FrecuenciaCaracteres{
    char caracter;
    int frecuencia;
};

class SecuenciaCaracteres{
private:
    
    static const int TAMANIO = 1000;
    char vector_privado[TAMANIO];
    int total_utilizados;
    
public:
    SecuenciaCaracteres()
    :total_utilizados(0)
    {
    }
    
    int Capacidad(){
        return TAMANIO;
    }
    
    int TotalUtilizados(){
        return  total_utilizados;
    }
    
    void Aniade(char  nuevo){
        if (total_utilizados  <  TAMANIO){
            vector_privado[total_utilizados]  =  nuevo;
            total_utilizados++;
        }
    }
    
    char Elemento(int  indice){
        return  vector_privado[indice];
    }
    
    void EliminaCaracter ( char a_borrar){
        
        for ( int i=0 ; i<total_utilizados ; i++){
            if (vector_privado[i]==a_borrar){
                vector_privado[i]=vector_privado[i+1];
                
            }
          
        }
    
            
    }
    void MuestraVector (){
        
        for ( int i = 0; i < total_utilizados ; i++){
        
            cout << vector_privado[i];
        
        }
    
    
    }
    
    FrecuenciaCaracteres Moda(){
        
        FrecuenciaCaracteres moda;
        
        const int TAMANIO = 255 ;
        int frecuencia_max = -1;
        int vector[TAMANIO];
        
        for ( int i =0; i<TAMANIO ; i++){
            vector[i]=0;
            
        }
        
        for(int i=0;i<total_utilizados;i++){
            vector[vector_privado[i]]++;
            
            
            if ( vector[vector_privado[i]] > frecuencia_max)
                moda.caracter = vector_privado[i];
            moda.frecuencia=vector[moda.caracter];
            frecuencia_max=moda.frecuencia;
            
        }
        return moda;
    }
    
};




int main() {
    const char FIN = '#';
    SecuenciaCaracteres texto;
    char caracter, a_eliminar;
    

    cout << " Introduce una serie de caracteres terminado en '#' " <<endl;
    caracter=cin.get();
    
    while(caracter!=FIN ){
        texto.Aniade(caracter);
        caracter=cin.get();
    }

    cout << "Introduce el caracter que desea eliminar del texto " <<endl;
    cin >> a_eliminar;
    

    texto.EliminaCaracter(a_eliminar);
    texto.MuestraVector();
    
    
    
    return 0;
}
