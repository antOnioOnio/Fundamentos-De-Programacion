
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
    char Elemento (int pos){
        if (pos>0 && pos<total_utilizados);
        return vector_privado[pos];
    }
    
    SecuenciaCaracteres login(int k, SecuenciaCaracteres objeto){
        
        SecuenciaCaracteres a_devolver;
        
        char letra = 49;
        a_devolver.Aniade(letra);
        letra++;
        int contador = 0;
        
        for (int i=0; i<total_utilizados; i++){
            if ( objeto.Elemento(i)!=' '){
                contador++;
                if ( contador <= k){
                    a_devolver.Aniade(objeto.Elemento(i));
                }
            }else{
                a_devolver.Aniade(letra);
                letra++;
                contador=0;
            
                }
            
        }
        return a_devolver;
    }
};
int main (){
    const char FIN = '.';
    int numero;
    char caracter;
    SecuenciaCaracteres palabra, a_insertar, log;
    
    cout << " introduce caracteres primo : \n";
    caracter= cin.get();
    
    while ( caracter != FIN){
        
        a_insertar.Aniade(caracter);
        
        caracter= cin.get();
    }
    cout << " Introduce un numerico: \t" ;
    cin >> numero;
    log=a_insertar.login(numero,a_insertar);
    
    log.MuestraVector();

}
