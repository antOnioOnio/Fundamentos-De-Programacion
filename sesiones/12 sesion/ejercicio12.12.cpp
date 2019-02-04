/*Sobre la clase SecuenciaCaracteres añada el método para eliminar un bloque, desde un determinado valor a otro determninado valor.*/

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
    
    int LeeLongLongMayorQue( int minimo, string mensaje ){
        
        int dato;
        do {
            cout << mensaje ;
            cin >> dato ;
        }while ( dato < minimo );
        
        return dato;
    }
    double  LeeDoubleEnrango( double minimo, double maximo, string mensaje){
        
        double dato;
        do {
            cout << mensaje;
            cin >> dato;
            
        }while ( dato < minimo || dato > maximo);
        
        
        return dato;
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
    void EliminaBloque (){
    
        const string    Msj_minimo = " introduce minimo\n " ,
                        Msj_maximo = " introduce maximo \n ";
        
        int minimo, maximo, a_mover;
        
        minimo = LeeLongLongMayorQue(0, Msj_minimo);
        maximo =LeeLongLongMayorQue(minimo, Msj_maximo);
        a_mover = maximo - minimo;
        
        for ( int i=minimo; i<maximo; i++ ){
            
            vector_privado[i]=vector_privado[i + a_mover];
        
        
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
    char caracter;
    
    
    cout << " Introduce una serie de caracteres terminado en '#' " <<endl;
    caracter=cin.get();
    
    while(caracter!=FIN ){
        texto.Aniade(caracter);
        caracter=cin.get();
    }
    
    texto.EliminaBloque();
    
    
    texto.MuestraVector();
    

   
    return 0;
}
