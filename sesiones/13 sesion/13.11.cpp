/* 11. [k Mayores que, dentro de una clase]. (Examen Septiembre 2016) Utilice la definición de la clase SecuenciaDoubles disponible en
 http://decsai.ugr.es/~carlos/FP/SecuenciaDoubles.cpp
 Esta clase es análoga a SecuenciaCaracteres, pero trabaja con datos de tipo double.
 Defina un método que construya otro objeto de la misma clase SecuenciaDoubles que contenga los k elementos ordenados mayores que un valor de referencia, según lo indicado en el ejercicio 3 de la relación de problemas IV. Modifique el programa principal de dicho ejercicio para que utilice la clase SecuenciaDoubles.
 Finalidad: Métodos que devuelven un objeto de la misma clase. Dificultad Media.
 
 3. [k mayores que otro valor, eficiente]. Modifique la solución del ejercicio 2 usando un algoritmo más eficiente. Observe que no hace falta ordenar todo el vector, sino únicamente considerar los datos que son mayores que la referencia.
 Aplique el siguiente algoritmo:
 Recorrer las componentes del vector original
 Si es mayor que la referencia, insertar dicho
 valor de forma ordenada en el vector "mayores_que"
 El vector "mayores_que" siempre tendrá,
 como mucho, k componentes
 Mientras que la versión vista en el ejercicio 2 tardaba varios segundos, esta nueva versión tarda menos de un segundo.
 Finalidad: Recorrido sobre un vector, insertando componentes. Dificultad Media.
 
 */

#include <iostream>
using namespace std;


// DECLARACION DE LAS CLASES
class SecuenciaDoubles{
private:
    static const int TAMANIO=100;
    double vector_privado[TAMANIO];
    int total_utilizados;
public:
    SecuenciaDoubles():
    total_utilizados(0)
    {
    }
    
    void Aniade( double valor){
        
        if (total_utilizados<TAMANIO){
            
            vector_privado[total_utilizados]=valor;
            total_utilizados++;
        }
    }
    void OrdenaVector(){
        
        double auxiliar=0 ;
        
        for (int i=0 ; i < total_utilizados -1 ; i++){
            
            for ( int j = i+1 ; j < total_utilizados ; j++){
                
                if ( vector_privado[i] > vector_privado[j]) {
                    
                    auxiliar = vector_privado[i];
                    
                    vector_privado[i] = vector_privado[j];
                    
                    vector_privado[j] = auxiliar;
            
                }
            }
        }
    }
    
    SecuenciaDoubles MayoresQue(double valor){
        
        SecuenciaDoubles objeto;
        
        
        for (int i=0; i<total_utilizados; i++){
            
            if(vector_privado[i]>valor){
                objeto.Aniade(vector_privado[i]);
            }
        }
        objeto.OrdenaVector();
        
        return objeto;
    }
    
    
    void MuestraVector(){
        
        for(int i=0; i<total_utilizados; i++){
            
            cout << vector_privado[i] << " " ;
        }
        cout << endl;
    
    
    }
    
};

// FUNCION MAIN

int main(){
    const double FIN = -1;
    SecuenciaDoubles objeto;
    SecuenciaDoubles mayores;
    
    double numero=0, referencia=0;
    
    cout << " Introduce numeros, para finalizar introduzca -1 " <<endl;
    cin >>numero;
    
    while ( numero != FIN ) {
        
        objeto.Aniade(numero);
        cin>> numero;
    }

    cout << " Introduce un valor de referencia:\t ";
    cin >> referencia;
    
    mayores = objeto.MayoresQue(referencia);
    
    cout << " Los valores por encima de " <<referencia << " son:\n ";
    mayores.MuestraVector();
    
    return 0;
}




















