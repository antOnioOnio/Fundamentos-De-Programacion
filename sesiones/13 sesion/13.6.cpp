/* [Moda vs 2]. Recupere la solución del ejercicio 5 (Moda) Elimine el método
 NumeroOcurrencias y en su lugar defina el método 
 SecuenciaEnteros PosicionesOcurrencias (char buscado, int izda, int dcha)
 que devuelve las posiciones en las que se encuentra el elemento buscado. Para ello, tendrá que usar la clase SecuenciaEnteros, análoga a SecuenciaCaracteres, cuya definición puede encontrarse en:
 http://decsai.ugr.es/~carlos/FP/SecuenciaEnteros.cpp
 Cambie la implementación del método Moda del ejercicio 5 para que use este nuevo método
 Finalidad: Métodos que devuelven objetos de otra clase. Dificultad Baja.*/

// Ejercicio 6 de la sesion 13
// Antonio Garcia Castillo

#include <iostream>
using namespace std;


// declaracion de las clases

struct FrecuenciaCaracteres{
    char caracter;
    int frecuencia;
};

class SecuenciaEnteros{
    
private:
    
    static const int TAMANIO = 1000;
    int vector_privado[TAMANIO];
    int total_utilizados;
    
public:
    
    SecuenciaEnteros()
    :total_utilizados(0) {
    }
    
    int Utilizados (){
        return total_utilizados;
    }
    void Aniade (int nuevo ){
        if (total_utilizados<TAMANIO){
            
            vector_privado[total_utilizados]=nuevo;
            
            total_utilizados++;
        }
    }
    
    void MuestraVector (){
    
        for ( int i= 0 ; i<total_utilizados; i++){
            cout << vector_privado[i] << "\t" ;
        }
        cout << endl;
    }
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
    
    void Aniade(char nuevo){
        
        if (total_utilizados  <  TAMANIO){
            vector_privado[total_utilizados]  =  nuevo;
            total_utilizados++;
        }
    }
    
    SecuenciaEnteros PosicionesOcurrencias( char buscado, int izda, int dcha ){
        SecuenciaEnteros objeto ;
        
        if ( izda < 0 || izda > dcha ){
            
            cout << " Limite inferior mal introducido, reajustado a cero " << endl;
            izda = 0;
        
        }
        if ( dcha< izda || dcha > total_utilizados){
            cout << " Limite superior mal introducido, reajustado al maximo " << endl;
            dcha = total_utilizados -1;
        
        }
        
        for ( izda; izda<= dcha; izda++){
            
            if( vector_privado[izda] == buscado)
                
                objeto.Aniade(izda);
            
        }
    
        return objeto;
    
    }
 
    
    char Elemento(int  indice){
        return  vector_privado[indice];
    }
  

    FrecuenciaCaracteres Moda(){
        
        FrecuenciaCaracteres struz;
        SecuenciaEnteros enteros;
        SecuenciaCaracteres caracteres;
        
        int frecuencia_maxima = -1, frecuencia = 0;
        char caracter=' ';
        
        // Copiamos los caracteres en nuestro objeto de la clase SecuenciaCaracteres
        for ( int i= 0 ; i< total_utilizados ; i++){
            caracteres.Aniade(vector_privado[i]);
            
        }
        // Recorremos el vector actualizando la frecuencia maxima y el caracter de moda
        for ( int i= 0 ; i< total_utilizados ;i++){
        
            enteros = PosicionesOcurrencias(caracteres.vector_privado[i], 0, total_utilizados);
            frecuencia = enteros.Utilizados();
            
            if (frecuencia>frecuencia_maxima ){
                frecuencia_maxima = frecuencia;
                caracter = vector_privado[i];
            }
    
        }
        struz.frecuencia = frecuencia_maxima;
        struz.caracter = caracter;
    
        return  struz;
    }
    
    //  FUNCION MAIN
};
int main() {
    
    const char FIN = '#';
    char caracter, a_buscar ;
    
    SecuenciaEnteros posiciones;
    SecuenciaCaracteres texto ;
    FrecuenciaCaracteres Fr;
    
   // INTRODUCCION DE DATOS
    cout << " Introduce caracteres, para finalizar introduce '#' " << endl;
    
    caracter = cin.get();
    while(caracter!=FIN ){
        texto.Aniade(caracter);
        caracter=cin.get();
    }
    
   
    
    Fr = texto.Moda();
    a_buscar = Fr.caracter;
    
    // MUESTRA RESULTADOS
    cout << " El caracter de moda es: " << a_buscar <<endl;
    
    posiciones = texto.PosicionesOcurrencias(a_buscar, 0, texto.TotalUtilizados());
    
    cout <<" Se encuentra en las posiciones : " <<endl;
    
    posiciones.MuestraVector();
   
    
    
    return 0;
    
}
