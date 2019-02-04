/*
 18. [Elimina exceso de blancos]. Sobre la clase SecuenciaCaracteres, añada un método EliminaExcesoBlancos para eliminar el exceso de caracteres en blanco, es decir, que sustituya todas las secuencias de espacios en blanco por un sólo espacio. Por ejemplo, si la secuencia original es (' ','a','h',' ',' ',' ','c'), que contiene una secuencia de tres espacios consecutivos, la secuencia resultante debe ser (' ','a','h',' ','c').
 Nota: Debe hacerse lo más eficiente posible.
 Construya un programa que lea los caracteres de la cadena uno a uno con cin.get(), hasta que se introduzca el carácter # y muestre el resultado de quitarle el exceso de blancos. Puede probar el programa con el siguiente fichero, que contiene el Quijote con más de un espacio en blanco entre palabras:
 http://decsai.ugr.es/~carlos/FP/Quijote_con_exceso_de_
 blancos.txt
 Finalidad: Recorrido de las componentes de un vector, en el que hay que recordar lo que ha pasado en la iteración anterior. Dificultad Media.
*/

// Ejercicio 18 de la sesion 13
// Antonio Garcia Castillo

#include <iostream>
using namespace std;

class SecuenciaCaracteres{
private:
    static const int TAMANIO=1000;
    char vector_privado[TAMANIO];
    int total_utilizados;
public:
    
    SecuenciaCaracteres():
    total_utilizados(0)
    {
    }
    
    void Aniade(char a_meter){
        if( total_utilizados<TAMANIO){
            vector_privado[total_utilizados]=a_meter;
            total_utilizados++;
        }
    }
    
    int TotalUsados(){
        return total_utilizados;
    }
    
    void MuestraVector(){
        
        for (int i=0; i<total_utilizados ; i++){
            
            cout << vector_privado[i];
        }
        cout << endl;
    }
    
    // Metodo pedido
    
    SecuenciaCaracteres EliminaExcesoBlancos(){
        SecuenciaCaracteres objeto;
        
    // Recorremos el vector, si el siguiente componente es otro espacio en blanco, no lo añadimos a nuestro nuevo objeto
        
        for (int i = 0; i<total_utilizados;i++){
           
            if(vector_privado[i]==' '){
                if(vector_privado[i+1]!=' ' ){
                    objeto.Aniade(vector_privado[i]);
                }
            }
            else{
                objeto.Aniade(vector_privado[i]);
            }
        }
        return objeto;
    }
};

// Funcion principal

int main() {
    
    const char FIN = '#';
    SecuenciaCaracteres texto ;
    SecuenciaCaracteres sin_blancos;
    char caracter;
    
    cout << " Introduce una serie de caracteres, para terminar introduce '#' " <<endl;
    caracter=cin.get();
    
    while(caracter!=FIN ){
        
        texto.Aniade(caracter);
        caracter=cin.get();
    }
    cin.ignore();
    
    // Aplicamos metodo
    sin_blancos = texto.EliminaExcesoBlancos();
    // Muestra resultados
    cout << " El texto con los espacios innecesarios eliminados:\n\n " ;
    sin_blancos.MuestraVector();

    return 0;
}
