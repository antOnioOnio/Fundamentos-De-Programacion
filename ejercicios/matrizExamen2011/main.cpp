
#include <iostream>
using namespace std;

class SecuenciaEnteros {
private:
    static const int TAMANIO=10;
    int vector_privado[TAMANIO];
    int total_utilizados;
public:
    SecuenciaEnteros():
    total_utilizados(0)
    {
    }
    int Elemento(int pos){
        return vector_privado[pos];
    }
    void Aniade( double valor){
        if (total_utilizados<TAMANIO){
            vector_privado[total_utilizados]=valor;
            total_utilizados++;
        }
    }
    int Utilizados(){
        return total_utilizados;
    }
    void MuestraVector(){
        for(int i=0; i<total_utilizados; i++){
            cout << vector_privado[i] << " " ;
        }
        cout << endl;
    }
};
class MatrizEnteros{
private:
    static const int M_FILAS = 10;
    static const int M_COLUMNAS = 10;
    int matriz[M_FILAS][M_COLUMNAS];
    int usados_filas, usados_columnas;
public:
    MatrizEnteros(){
        for (int i=0; i<M_FILAS; i++){
            for (int j=0 ; j<M_COLUMNAS; j++){
                matriz[i][j]=0;
            }
        }
        usados_filas=0;
        usados_columnas=0;
    }
    int Filas(){
        return M_FILAS;
    }
    int Columnas(){
        return M_COLUMNAS;
    }
    int Elemento( int i, int j){
        if (i>0 && i<M_FILAS && j>0 && j<M_COLUMNAS){
            return matriz[i][j];
        }
        else return -1;
    }
    void MueveFila(int Fila){
        for (int i=M_FILAS; i>Fila ; i--){
            for (int j=0 ; j<M_COLUMNAS ; j++){
            matriz[i][j]=matriz[i-1][j];
            }
        }
    }
    void AniadeFila(SecuenciaEnteros objeto){
        if (objeto.Utilizados()<M_COLUMNAS){
            for (int i=0; i<objeto.Utilizados(); i++){
                matriz[usados_filas][i]=objeto.Elemento(i);
               
            }
             usados_filas++;
        }
        
    }
    
    void MuestraMatriz(){
        for(int i = 0; i<M_FILAS ;i++){
            cout <<endl;
            for (int j= 0 ; j<M_COLUMNAS ;j++){
                cout<<  matriz[i][j];
            }
        }
        cout << "\n" ;
    }
};

            
int main() {
    const int FIN = -1;
    SecuenciaEnteros numeros;
    MatrizEnteros tabla;
    int entero;
    
    cout << " Mete numericos hermano: \n " ;
    cin>> entero;
    
    while (entero != FIN){
        numeros.Aniade(entero);
        cin>>entero;
    }
    
    tabla.AniadeFila(numeros);
    tabla.MueveFila(0);
    tabla.MuestraMatriz();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
