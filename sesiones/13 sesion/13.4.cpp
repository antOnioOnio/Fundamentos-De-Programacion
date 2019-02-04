/* Recupere la solución del ejercicio 5 (Descodifica) de la relación de problemas IV. Implemente el método de descodificación como un método de la clase SecuenciaCaracteres.
 
 El método no modificará la secuencia de caracteres sobre la que se aplica, sino que construirá y devolverá una nueva secuencia.
 Dado un vector de caracteres que contiene un mensaje cifrado, se pide construir otro vector nuevo con el mensaje descifrado. La forma de descifrado consiste en coger la primera y última letra de cada palabra. Las palabras están separadas por uno o más espacios en blanco o el final del vector. Si la última palabra no tiene espacios en blanco a su derecha, se coge sólo el primer carácter.
 Ejemplo de entrada: [Hidrógeno limpia ]   −− Salida correcta: [Hola]
 Ejemplo de entrada: [Hidrógeno limpia]    −− Salida correcta: [Hol]
 Ejemplo de entrada: [Hidrógeno]           −− Salida correcta: [H]
 Ejemplo de entrada: [Hidrógeno ]          −− Salida correcta: [Ho]
 Ejemplo de entrada: [H]                   −− Salida correcta: [H]
 Ejemplo de entrada: [H ]                  −− Salida correcta: [H]*/

// Antonio Garcia Castillo
// Ejercicio 4 de la 13ª sesion.



#include <iostream>
using namespace std ;

// DECLARACION DE LA CLASE
class SecuenciaCaracteres{
private:
    static const int CAPACIDAD= 1000;
    char vector_privado[CAPACIDAD];
    int total_utilizados;
    
public:
    SecuenciaCaracteres():
    total_utilizados(0)
    {
    }
    
    void Aniade(char a_meter){
        if (total_utilizados<CAPACIDAD){
            
            vector_privado[total_utilizados]=a_meter;
            total_utilizados++;
        }
    }
    
    void MuestraVector (){
        for ( int i=0; i<total_utilizados; i++){
            cout << vector_privado[i];
        }
        cout << endl;
    }
    
    
    
    SecuenciaCaracteres Decodificado(){
        SecuenciaCaracteres vd; // VECTOR DECODIFICADO
        
        if (vector_privado[0]!=' '){
            vd.Aniade(vector_privado[0]);
           
        }
        
        for (int i=1; i<total_utilizados; i++){
            if (vector_privado[i]!=' '){
                if ( (vector_privado[i-1]==' ') || (vector_privado[i+1]==' ')){
                   vd.Aniade(vector_privado[i]);
                    
                }
                
            }
            
        }
        return vd;
    }
    
};

// FUNCION PRINCIPAL

int main (){
    // DECLARACION DE VARIABLES
    const char TERMINADOR = '#';
    SecuenciaCaracteres texto;
    SecuenciaCaracteres Decodificado;
    char a_meter;
    
    // INTRODUCCION DE DATOS
    cout << " Introduce un texto, para finalizar escriba # "<<endl;
    a_meter = cin.get();
    
    while (a_meter != TERMINADOR  ){
        
        texto.Aniade(a_meter);
        
        a_meter = cin.get();
    }
    
    // MUESTRA RESULTADO
    
    Decodificado = texto.Decodificado();
    
    cout << " El texto decodificado es: \t";
    Decodificado.MuestraVector();
    
    
    cout << " \n\n ";
    
    
    
    
    
    return 0 ;
}
