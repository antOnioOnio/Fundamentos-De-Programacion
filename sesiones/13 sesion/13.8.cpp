/* 8. [Inserta secuencia ineficiente]. Sobre la clase SecuenciaCaracteres, defina un
 método que inserte otra secuencia a partir de una posición.
 Implemente este método utilizando el método visto en clase que insertaba un único carácter:
 
        void Inserta(int pos_insercion, char valor_nuevo)
 Tendrá que llamar a este método para insertar, uno a uno, todos los caracteres de la nueva secuencia.
 Construya un programa para que lea los caracteres de la primera secuencia (hasta el terminador #), los caracteres de la segunda (hasta el terminador #), la posición de inserción e imprima el resultado de insertar la segunda dentro de la primera, a partir de la posición indicada.
 Observe que este algoritmo es bastante ineficiente ya que el algoritmo se reduce a la ejecución de un bucle anidado en otro. En el ejercicio 9 se pide una versión eficiente.
 Ejemplo de entrada: Esto es fácil#muy #8 −− Salida correcta: Esto es muy fácil
 
 Finalidad: Métodos que reciben como parámetro un objeto de la misma clase. Dificultad Baja */

// Ejercicio 8 de la sesion 13
// Antonio Garcia Castillo

#include <iostream>
using namespace std;


class SecuenciaCaracteres{
private:
    const static int TAMANIO = 1000;
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
    void Inserta(int pos_insercion, char valor_nuevo){
        
        for ( int i=total_utilizados ;  i>pos_insercion; i--){
            
            vector_privado[i]=vector_privado[i-1];
        }
            vector_privado[pos_insercion]=valor_nuevo;
            total_utilizados++;
    }
    
    void InsertaCadena(int pos_inserccion,SecuenciaCaracteres objeto){
        
        for ( int i=0; i<objeto.TotalUsados() ; i++){
            
            Inserta(pos_inserccion, objeto.vector_privado[i]);
            pos_inserccion++;
        
        }
    }
};



int main() {
    
    const char FIN = '#';
    SecuenciaCaracteres texto, objeto ;
    char caracter;
    int posicion;
    
    cout << " Introduce una serie de caracteres para la primera cadena, para terminar introduce '#' " <<endl;
    caracter=cin.get();
    
    while(caracter!=FIN ){
        
        texto.Aniade(caracter);
        caracter=cin.get();
    }
    
    cin.ignore();
    
    cout << " Introduce una serie de caracteres a insertar en el texto, para terminar introduce '#' " <<endl;
    caracter=cin.get();
    
    while(caracter!=FIN ){
        
        objeto.Aniade(caracter);
        caracter=cin.get();
    }
    
    cout << " Introduce una posicion de inserccion:\t " ;
    cin >> posicion;
    
    texto.InsertaCadena(posicion, objeto);
    
    cout << " El nuevo texto es: "<<endl;
    
    texto.MuestraVector();
    
    return 0;
}
