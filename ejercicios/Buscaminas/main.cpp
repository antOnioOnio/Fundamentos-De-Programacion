//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Alberto Fernandez
//
//////////////////////////////////////////////////////////////////////////

// Tablero Busca Minas

#include <iostream>
using namespace std;

class TablaRectangularEnteros{
private:
    static const int MAXFILAS = 50;
    static const int MAXCOLS = 50;
    int tablero[MAXFILAS][MAXCOLS];
    int util_fil, util_col;
    
    
public:
    TablaRectangularEnteros()
    :util_fil(0),
    util_col(0)
    {   }
    
    TablaRectangularEnteros(int filas, int columnas)
    :util_fil(filas),
    util_col(columnas)
    {
        for (int i = 0; i < filas; i++){
            for (int j = 0; j < columnas; j++){
                tablero[i][j] = 0;
            }
        }
    }
    
    void Modifica(int fila, int columna, int valor){
        if ((fila < util_fil)&&(columna < util_col)){
            tablero[fila][columna] = valor;
        }
    }
    
    void imprimir(){
        for (int i = 0; i < util_fil; i++){
            for (int j = 0; j < util_col; j++){
                cout << tablero[i][j] << "\t";
            }
            cout << endl;
        }
    }
    
};

class TableroBuscaMinas{
private:
    static const int MAXFILAS = 50;
    static const int MAXCOLS = 50;
    bool tablero[MAXFILAS][MAXCOLS];
    int util_fil, util_col;
    
    int max(int v1, int v2){
        return v1 > v2?v1:v2;
    }
    
    int min(int v1, int v2){
        return v1 < v2?v1:v2;
    }
    
public:
    TableroBuscaMinas()
    :util_fil(0),
    util_col(0)
    {   }
    TableroBuscaMinas(int filas, int columnas)
    :util_fil(filas),
    util_col(columnas)
    {
        for (int i = 0; i < filas; i++){
            for (int j = 0; j < columnas; j++){
                tablero[i][j] = false;
            }
        }
    }
    
    void Flip(int fila, int columna){
        if ((fila < util_fil)&&(columna < util_col)){
            tablero[fila][columna] = !tablero[fila][columna];
        }
    }
    
    void Modifica(int fila, int columna, bool valor){
        if ((fila < util_fil)&&(columna < util_col)){
            tablero[fila][columna] = valor;
        }
    }
    
    int Minas(int fila, int columna){
        int minas = 0;
        if ((fila < util_fil)&&(columna < util_col)){
            if (tablero[fila][columna]){
                minas = -1;
            }
            else{
                int inicioF = max(0,fila-1);
                int finF = min(util_fil-1, fila+1);
                int inicioC = max(0,columna-1);
                int finC = min(util_col-1, columna+1);
                for (int i = inicioF; i <= finF; i++){
                    for(int j = inicioC; j <= finC; j++){
                        minas += tablero[i][j]?1:0;
                    }
                }
            }
        }
        
        return minas;
    }
    
    TablaRectangularEnteros crearTabla(){
        TablaRectangularEnteros tabla(util_fil,util_col);
        for (int i = 0; i < util_fil; i++){
            for (int j = 0; j < util_col; j++){
                int minas = Minas(i,j);
                tabla.Modifica(i,j,minas);
            }
        }
        return tabla;
    }
    
    void imprimir(){
        for (int i = 0; i < util_fil; i++){
            for (int j = 0; j < util_col; j++){
                cout << tablero[i][j] << "\t";
            }
            cout << endl;
        }
    }
    
};

int main(){
    TableroBuscaMinas juego(6,4);
    juego.Flip(0,3);
    juego.Flip(1,1);
    juego.Flip(2,3);
    juego.Flip(3,1);
    juego.Flip(3,2);
    juego.Flip(3,3);
    juego.Flip(4,2);
    juego.imprimir();
    cout << endl;
    TablaRectangularEnteros tabla = juego.crearTabla();
    tabla.imprimir();
    return 0;
}
