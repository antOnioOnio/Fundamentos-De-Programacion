/* 13. [Counting Sort]. (Examen Septiembre 2014)
 Sobre la clase SecuenciaCaracteres implemente el algoritmo Counting Sort para ordenar sus valores.
 SecuenciaCaracteres CountingSort()
 El método no modificará las componentes del vector privado sino que debe construir una secuencia nueva y devolverla. El algoritmo funciona de la siguiente forma:
 
 • Calcular los valores mínimo y máximo del vector.Por ejemplo,si el vector contiene
            cbbabccagcbgc
 el mínimo es 'a' y el máximo 'g'.
 
 • Construir un vector local de frecuencias con los conteos de todos los caracteres que hay entre el mínimo y el máximo. Con el ejemplo anterior, el vector de conteos será
            2450002
 que corresponden a las frecuencias de las letras que hay entre 'a' y 'g'.
 
 • Recorrer el vector de frecuencias almacenando cada carácter tantas veces como indique su frecuencia (2 veces el 'a', cuatro veces el 'b', etc)
            aabbbbcccccgg
 
 Para resolver este problema, debe definir un segundo método auxiliar:
 
 SecuenciaCaracteres CountingSortEntre(char min, char max)
 Este método sólo ordena los valores de la secuencia que hay entre un carácter izquierda y otro carácter derecha.
 Por ejemplo, si izquierda = 'b' y derecha = 'g' el resultado sería la siguiente secuencia:
 bbbbcccccgg
 Debe llamar a este método dentro de CountingSort().
 
 Finalidad: Trabajar con métodos con vectores locales y devolviendo un objeto de la misma clase. Dificultad Media.
 */

// Ejercicio 13 de la sesion 13
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
    void LimpiaVector (){
        total_utilizados = 0;
        
    }
    
    void MuestraVector(){
        for (int i=0; i<total_utilizados ; i++){
            cout << vector_privado[i];
        }
        cout << endl;
    }
    int PosicionMinimo(){
        int minimo=300;
        int posicion = 0;
        for (int i=0; i<total_utilizados ; i++){
            if(vector_privado[i]<minimo){
                minimo = vector_privado[i];
                posicion = i;
            }
        }
        return posicion;
    }
    int PosicionMaximo(){
        int maximo=0;
        int posicion = 0;
        for (int i=0; i<total_utilizados ; i++){
            if(vector_privado[i]>maximo){
                maximo = vector_privado[i];
                posicion = i;
            }
        }
        return posicion;
        }
    // Método auxiliar del que nos valemos en CountinSort, ordena nuestro vector.
    void CountinSortEntre (char min, char max){
        char intercambia;
            for (int i = min; i < max; i++){
                for (int j = max-1 ; j > i ; j--){
                    if (vector_privado[i] < vector_privado[i-1]){
                        intercambia =vector_privado[i];
                        vector_privado[i] = vector_privado[i-1];
                        vector_privado[i-1] = intercambia;
                    }
                }
            }
        }
    
    // Método pedido en el ejercicio
    SecuenciaCaracteres CountinSort(){
        SecuenciaCaracteres objeto ;
        const int CAPACIDAD = 255;
        int vector_frecuencias[CAPACIDAD];
        int max =0;
        int min =0;
        max = PosicionMaximo();
        min = PosicionMinimo();
        
        // Rellenamos un objeto de la clase SecuenciaCaracteres con los valores del vector
        // introducido para modificarlo
        for ( int i=0; i<TotalUsados() ; i++){
            objeto.Aniade(vector_privado[i]);
        }
        // Ordenamos nuestro vector con nuestro método auxiliar
        
        objeto.CountinSortEntre(min, max);
        
        // Ponemos nuestro vector frecuecnias a cero
        for ( int i =0; i<CAPACIDAD ; i++){
        vector_frecuencias[i]=0;
        }
        
        // Rellenamos nuestro vector frecuencias con los conteos de los caracteres
        for(int i=0;i<objeto.TotalUsados();i++){
            vector_frecuencias[objeto.vector_privado[i]]++;
            
        }
        // Vaciamos nuestro vector para introducirle los conteos de caracteres
        objeto.LimpiaVector();
        
        // Añadimos en nuestro los caracteres en funcion del conteo en el vector frecuencia
        // el algoritmo recorre el vector de frecuencias, si la cantidad es diferente de cero
        // se para y rellena tantas veces nuestro vector de caracteres tantas veces como conteo
        // tengamos
        for ( int i = 0; i<CAPACIDAD; i++){
            if (vector_frecuencias[i] != 0){
                for ( int j=0; j<vector_frecuencias[i]; j++){
                    objeto.Aniade(i);
                
                }
            }
        }
           
        return  objeto;
    }
};


int main() {
    
    const char FIN = '#';
    SecuenciaCaracteres texto ;
    SecuenciaCaracteres nuevo;
    
    char caracter;
    
    cout << " \nIntroduce una serie de caracteres, para terminar introduce '#': \n " <<endl;
    
    caracter=cin.get();
    
    while(caracter!=FIN ){
        
        texto.Aniade(caracter);
        caracter=cin.get();
    }
    // Aplicamos metodo
   nuevo =  texto.CountinSort();
    // Muestra resultados
    cout << " El texto despues de aplicarle el método CountinSort:\n " ;
    nuevo.MuestraVector();
    

    return 0;
}
