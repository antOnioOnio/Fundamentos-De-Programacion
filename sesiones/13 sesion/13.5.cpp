/* 5. [Moda]. Recupere la solución del ejercicio 10 de la relación de problemas IV (Moda).
 Reescriba el método Moda de la siguiente forma:
 
 • Use como dato local para guardar los caracteres procesados un objeto de la clase
 SecuenciaCaracteres, en vez de un vector clásico de corchetes. • 
 
 Defina dentro de la clase SecuenciaCaracteres el método
  int NumeroOcurrencias(char buscado, int izda, int dcha)
 que devuelve el número de ocurrencias de un valor buscado entre las posiciones izda y dcha de la secuencia. Llame a este método dentro de Moda para calcular las frecuencias de cada carácter.
 Finalidad: Métodos con objetos de la misma clase como datos locales. Dificultad Baja.
 
 10. [Moda]. Recupere la solución del ejercicio 4. Defina el método Moda dentro de la clase SecuenciaCaracteres. Este método debe devolver un dato de tipo FrecuenciaCaracter (struct) Aplíquelo sobre el texto del Quijote sin espacios en blanco.
 Finalidad: Diseñar las cabeceras de los métodos que acceden a las componentes del vector. Dificultad Baja.
 
 Se quiere calcular la moda de un vector de caracteres, es decir, el carácter
 que más veces se repite. Por ejemplo, si el vector fuese
 {'l','o','s',' ','d','o','s',' ','c','o','f','r','e','s'} los caracteres que más se repiten son 'o' y 's' con un total de 3 apariciones. La
 moda sería cualquiera de ellos, por ejemplo, el primero encontrado 'o'.
 Guión de Prácticas. Fundamentos de Programación RP-IV.5
 RELACIÓN DE PROBLEMAS IV. Vectores
 Para almacenar de forma conjunta el carácter y la frecuencia usaremos el siguiente struct:
 struct FrecuenciaCaracter{
 char caracter;
 int  frecuencia;
 }
 El campo caracter contendrá el carácter en cuestión ('o') y en el campo
 frecuencia el conteo de la moda (3).
 Construya un programa que lea caracteres con cin.get() (repase lo visto al inicio de esta relación de problemas) hasta que el usuario introduzca el carácter #. Alma- cene todos los valores en un vector de caracteres. A continuación, calcule la moda y muéstrela en pantalla junto con su frecuencia.
 Para calcular la moda, se recomienda que use un vector auxiliar en el que almacene los caracteres que ya se han procesado en algún momento anterior.
 Utilice el texto del Quijote sin espacios en blanco disponible en:
 http://decsai.ugr.es/~carlos/FP/Quijote_sin_espacios.txt
 La moda es la letra 'e' con un total de 217900 apariciones. Finalidad: Recorridos sobre un vector. Dificultad Media.
 
 */

// Ejercicio 5 de la seesion 13
// Antonio Garcia Castillo


#include <iostream>
#include <cctype>

using namespace std;


// Declaracion de las clases

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
    
    int NumeroOcurrencias(char buscado, int izda, int dcha){
        
        // si introduce un dato no valido, ajustamos al principio o al final del vector
        
        if ( izda < 0 || izda > dcha ){
            
            cout << " Limite inferior mal introducido, reajustado a cero " << endl;
            izda = 0;
            
        }
        if ( dcha< izda || dcha > total_utilizados){
            
            cout << " Limite superior mal introducido, reajustado al maximo " << endl;
            dcha = total_utilizados -1;
            
        }
        
      
        int contador=0;
        
        for( izda ; izda<=dcha ;izda++){
          
           if(vector_privado[izda] == buscado)
               contador++;
        }
        return contador;
        }
    
    char Elemento(int  indice){
        return  vector_privado[indice];
    }
    
    FrecuenciaCaracteres Moda(){
        
        FrecuenciaCaracteres fr;
        SecuenciaCaracteres objeto;
        
        int frecuencia_maxima=-1, frecuencia=0;
     
        
        for ( int i=0; i<total_utilizados; i++){
        
            objeto.Aniade(vector_privado[i]);
        }
        
        for ( int i = 0 ; i < objeto.total_utilizados ;i++){
            
           frecuencia =  NumeroOcurrencias(objeto.vector_privado[i], 0, total_utilizados-1);
        
            if ( frecuencia > frecuencia_maxima){
                frecuencia_maxima = frecuencia;
                
                fr.frecuencia = frecuencia_maxima;
                fr.caracter = objeto.vector_privado[i];
             
                }
           
        }
       
        return fr;
    }
    
    
};

//                  FUNCION MAIN
int main() {
    
    const char TERMINADOR='#';
    SecuenciaCaracteres texto;
    FrecuenciaCaracteres texto_f;
    
    //              INTRODUCCION DE DATOS
    char caracter;
    cout << " Introduce una serie de caracteres, para terminar introduce '#' " <<endl;
    caracter=cin.get();
    while(caracter!=TERMINADOR ){
        texto.Aniade(caracter);
        caracter=cin.get();
    }
    
    texto_f = texto.Moda();
    
    
    
    //              MUESTRA RESULTADOS
    cout << "\nEl caracter que mas veces ha salido  ha sido : \t" << texto_f.caracter << endl;
    cout <<"\nUn total de :\t"  << texto_f.frecuencia <<endl;
    
    
    
    return 0;
}










































