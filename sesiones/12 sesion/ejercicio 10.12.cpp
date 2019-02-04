/* Recupere la solución del ejercicio 4. Defina el método Moda dentro de la clase SecuenciaCaracteres. Este método debe devolver un dato de tipo FrecuenciaCaracteres (struct) Apliquelo sobre el texto del Quijote sin espacios en blanco.
    */
// Antonio Garcia Castillo
// Ejercicio 10 de la 12ª sesion

#include <iostream>
#include <cctype>

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
    
    const char TERMINADOR='#';
    SecuenciaCaracteres texto;
    FrecuenciaCaracteres Moda;
    
    char caracter;
   
    cout << " Introduce una serie de caracteres, para terminar introduce '#' " <<endl;
    caracter=cin.get();
    while(caracter!=TERMINADOR ){
        texto.Aniade(caracter);
        caracter=cin.get();
    }
    
    Moda =  texto.Moda();
    
    cout << "\nEl caracter que mas veces ha salido  ha sido : \t" << Moda.caracter << endl;
    cout <<"\nUn total de :\t"  << Moda.frecuencia <<endl;



        return 0;
}
