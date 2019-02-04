//
//  main.cpp
//  SeleccionDireccional
//
//  Created by antonio garcia on 21/1/17.
//  Copyright © 2017 antonio garcia. All rights reserved.
//

#include <iostream>
using namespace std;

class SecuenciaEnteros {
private:
    static const int TAMANIO=1000;
    int vector_privado[TAMANIO];
    int total_utilizados;
public:
    SecuenciaEnteros():
    total_utilizados(0)
    {
    }
    
    void Aniade( double valor){
        if (total_utilizados<TAMANIO){
            vector_privado[total_utilizados]=valor;
            total_utilizados++;
        }
    }
    void Vacia(){
        total_utilizados=0;
    }
    int Elemento(int pos){
        return vector_privado[pos];
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
    static const int M_FILAS = 5;
    static const int M_COLUMNAS= 5;
    int matriz[M_FILAS][M_COLUMNAS];
    int usados_filas, usados_columnas;
public:
    MatrizEnteros(){
        usados_filas=0;
        usados_columnas=0;
    }
    MatrizEnteros (int columnas, int filas){
            usados_columnas= columnas ;
            usados_filas = filas;
        
        for ( int i = 0; i< usados_filas ; i++){
            for ( int j=0; j< usados_columnas; j++){
                matriz[i][j]=0;
            }
        
        }
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
    void AniadeFila(SecuenciaEnteros Fila){
        if (Fila.Utilizados() <= M_COLUMNAS){
            for (int i=0; i<Fila.Utilizados(); i++){
                matriz[usados_filas][i]=Fila.Elemento(i);
            }
            usados_filas++;
        }
        
    }
    bool EnMatriz(int i, int j){
        bool esta = false;
        if (i < usados_filas && j<M_COLUMNAS){
            esta= true;
        }
        return esta;
    }
    SecuenciaEnteros SeleccionDireccional(int i, int j, int dx, int dy){
        SecuenciaEnteros objeto;
        int pos_fila= i;
        int pos_columna = j;
        while (EnMatriz(pos_fila, pos_columna)){
            objeto.Aniade(matriz[pos_fila][pos_columna]);
            pos_fila+=dy;
            pos_columna+=dx;
        }
        
        return objeto;
    }
    void imprimir(){
        for (int i = 0; i < usados_filas; i++){
            for (int j = 0; j < Columnas(); j++){
                cout << matriz[i][j] << "\t";
            }
            cout << endl;
        }
    }

};


int main() {
    const int FIN = -1;
    SecuenciaEnteros fila1, seleccion, seleccion1;
    MatrizEnteros matriz;
    int numero;
    int contador = 0;
    int tope = 5;
    
    
    while ( contador < tope){
       
        cout << "Metele numeros hasta que huela a vinagre, y las 5 filas esten rellenas " <<endl;
        cin >> numero;
            while ( numero != FIN){
                fila1.Aniade(numero);
                cin >> numero;
        }
        matriz.AniadeFila(fila1);
        contador++;
        fila1.Vacia();
    }
    cout << " Tu matriz pishica\n ";
    matriz.imprimir();
    
    seleccion = matriz.SeleccionDireccional(0, 0, 1, 2);
    seleccion1 = matriz.SeleccionDireccional(1, 3, 0, 1);
    cout << " Tu vectorsico: \n";
    seleccion.MuestraVector();
    cout << " Tu otro vectorsico: \n";
    seleccion1.MuestraVector();
    
}
