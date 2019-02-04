#include <iostream>
using namespace std;

class SecuenciaEnteros{
private:
    static const int CAPACIDAD = 100;
    int vector_privado[CAPACIDAD];
    int total_utilizados;
public:
    SecuenciaEnteros(){
        total_utilizados = 0;
    }
    void Aniade(int a_meter){
        if (total_utilizados<CAPACIDAD){
            vector_privado[total_utilizados]=a_meter;
            total_utilizados++;
        }
    }
    int Utilizados(){
        return total_utilizados;
    }
    int MaxNegativos(){
        int maximo = -1000;
        for (int i=0; i<total_utilizados; i++){
            if (vector_privado[i]<0){
                if (vector_privado[i]>maximo){
                    maximo = vector_privado[i];
                }
            }
        }
        return maximo;
    }
    int Elemento( int posicion){
        return vector_privado[posicion];
    }
    bool pertenece(int numero){
        bool esta=false;
        for( int i =0 ; i<total_utilizados && !esta ; i++){
            if ( vector_privado[i]==numero){
                esta=true;
            }
        }
        return esta;
    }
    
    SecuenciaEnteros sinRepetidos(){
        SecuenciaEnteros objeto;
        bool metemos = false ;
        
        for (int i=0; i<total_utilizados; i++){
            metemos = objeto.pertenece(vector_privado[i]);
            if (!metemos){
                objeto.Aniade(vector_privado[i]);
            }
        }
        return objeto;
    }
    SecuenciaEnteros Posiciones(int k){
        SecuenciaEnteros objeto;
        
        for (int i=0; i<total_utilizados; i++){
            
            if (vector_privado[i]<k){
                
                objeto.Aniade(i);
            }
        }
        return objeto;
    }
    void MuestraVector (){
        for (int i=0; i<total_utilizados; i++){
            cout << vector_privado[i];
        }
        cout << "\n";
    }
};


int main (){
    const int FIN = 0 ;
    SecuenciaEnteros objeto1, objeto2, objeto3;
    int entero ;
    
    
    cout << " Introduce una serie de enteros, para finalizar introduzca -1\n";
    cin >> entero ;
    
    while (entero != FIN){
        objeto1.Aniade(entero);
        cin>> entero;
    }
    
    
    entero = objeto1.MaxNegativos();
    
    cout << " el maximo de los negativos:   " <<entero <<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
