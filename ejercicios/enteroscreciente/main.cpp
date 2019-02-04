//
//  main.cpp
//  enteroscreciente
//
//  Created by antonio garcia on 22/1/17.
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
    void MuestraVector(){
        for(int i=0; i<total_utilizados; i++){
            cout << vector_privado[i] << " " ;
        }
        cout << endl;
    }
    int getUtilizados(){
        return total_utilizados;
    }
    int Elemento(int pos){
        return vector_privado[pos];
    }
    int PosicionSecuenciaCreciente(){
        
        int longitud =1;
        int l_max = 0;
        int pos_ini = 0;
        int pos_ini_max = 0;
        
        for (int i=1;i<getUtilizados()-1;i++){
            if ( Elemento(i)<Elemento(i-1)){
                pos_ini=i;
                longitud =0;
            }
            else {
                longitud++;
                if (longitud>l_max){
                    l_max = longitud;
                    pos_ini_max = pos_ini;
                }
            }
        }
        return pos_ini_max;
    }
};

int main() {
   	const int TERMINADOR=-1;
    SecuenciaEnteros uno;
    int numero;
    
    cout << "\nRellena el primer vector \t";
    cin >> numero;
    
    while (numero != TERMINADOR){
        uno.Aniade(numero);
        
        cin >> numero;
    }
    numero= uno.PosicionSecuenciaCreciente();
    cout<< numero <<endl;
    
    return 0;
}
