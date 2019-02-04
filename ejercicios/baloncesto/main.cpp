//
//  main.cpp
//  baloncesto
//
//  Created by antonio garcia on 13/1/17.
//  Copyright © 2017 antonio garcia. All rights reserved.
//

#include <iostream>
using namespace std;

struct Canasta{
    int nC1;
    int nC2;
    int nC3;
};
class Jugador{
private:
    int dorsal;
    Canasta Anotado;
public:
    Jugador(){
        dorsal=-1;
        Anotado.nC1=0;
        Anotado.nC2=0;
        Anotado.nC3=0;
    }
    Jugador(int dor, int c1, int c2, int c3){
        dorsal= dor;
        Anotado.nC1=c1;
        Anotado.nC2=c2;
        Anotado.nC3=c3;
    }
    int PuntuacionTotal(){
        return Anotado.nC1 + Anotado.nC2 +Anotado.nC3;
    }
    int Triples(){
        return Anotado.nC3;
    }
    int Libres(){
        return Anotado.nC1;
    }
    int Dorsal(){
        return dorsal;
    }
    int dobles(){
        return Anotado.nC2;
    }
    void setDorsal(int dors){
        dorsal=dors;
    }
    void SetTriples(int triples){
        Anotado.nC3=triples;
    }
    void setDobles(int dobles){
        Anotado.nC2 = dobles;
    }
    void setLibres(int libres){
        Anotado.nC1 = libres;
    }
};
class Equipo{
private:
    static const int MAX_JUGADORES=15;
    Jugador Team[MAX_JUGADORES];
    int usados;
public:
    Equipo(){
        usados = 0;
    }
    void Aniade(Jugador objeto){
        if(usados<MAX_JUGADORES){
            Team[usados]=objeto;
            usados++;
        }
    }
    int PuntuacionTotal(){
        int puntuacion=0;
      
        for (int i=0; i<usados-1 ;i++){
            
       
        return puntuacion;
    }
    
    int MediaTirosLibres(){
        int libres=0;
        int media;
        Jugador objeto;
        for(int i=0; i<usados-1 ; i++){
            objeto = Team[i];
            libres += objeto.Libres();
            
        }
        media = libres/usados;
        
        return media;
    }
    int MediaTotal(){
        int media;
        media =  PuntuacionTotal() / usados;
        return media;
    }
    int DorsalMaximo(){
        int maximo = -1;
        
        Jugador objeto;
        for(int i=0; i<usados-1 ; i++){
            objeto = Team[i];
            if ( objeto.PuntuacionTotal() > maximo){
                maximo = objeto.Dorsal();
            }
            
        }
        return maximo;
    }
    int JugadoresEncimaMedia(){
        int numero=0;
        int media = MediaTotal();
        Jugador objeto;
        
        for (int i=0; i<usados; i++){
            objeto = Team[i];
            
            if (objeto.PuntuacionTotal()>media){
                numero++;
            }
        
        }
        
        
        return numero;
    
    }
    
};



int main() {
    const int FIN = -1;
    Equipo Lancha;
    int dorsal, c1, c2, c3;
    cout << "Introduce dorsal: \t";
    cin>>dorsal;
    
    while ( dorsal!=FIN){
        cout<< "Introduce C1\t";
        cin >> c1;
        cout << "Introduce C2\t";
        cin >> c2;
        cout << "Introduce c3\t";
        cin >> c3;
        
    }

    
    
    
    return 0;
}
