#include <iostream>
using namespace std;

class Conjunto{
private:
    const static int CAPACIDAD=500;
    bool vector[CAPACIDAD];
    int utiles;
    
public:
    Conjunto(){
        utiles=0;
        for (int i=0;i<CAPACIDAD;i++)
            vector[i]=false;
    }
    int getUtiles(){
        return utiles;
    }
    bool Elemento(int pos){
        if (pos >= 0 && pos < getUtiles()){
            return vector[pos];
        }
        else {
            return -1;
            }
    }
    void Aniade(bool cond){
        if (getUtiles()<CAPACIDAD){
            vector[utiles]=cond;
            utiles++;
        }
    }
   
    bool Pertenece(int num){
        bool esta=false;
        if (vector[num]==true)
            esta=true;
        return esta;
    }
    
    int Cardinal(){
        int cardinal=0;
        for (int i=0;i<getUtiles();i++){
            if (Elemento(i)==true){
                cardinal++;
            }
        }
        return cardinal;
    }
    Conjunto Interseccion(Conjunto serie){
        Conjunto local;
        
        for (int i=0;i<getUtiles();i++){
            if (serie.Elemento(i)==true && Elemento(i) == true){
                local.Aniade(true);
            }
            else {
                local.Aniade(false);
            }
        }
        return local;
    }
};

int main (void){
    const int FIN=-1;
    int  numero;
    Conjunto serie, serie2, serie3;
    
    cout << "\nRELLENA  ( 1 true 0 false )\t"	;
    cin >> numero;
    
    while (numero != FIN){
        if (numero == 1){
            serie.Aniade(true);
        }
        else if  (numero == 0){
            serie.Aniade(false);
        }
        cin >> numero;
    }
    
    cout << "\nRELLENA EL SEGUNDO CONJUNTO (1 true 0 false) \t";
    cin >> numero;
    while (numero != FIN){
        if (numero == 1){
            serie2.Aniade(true);
        }
        else if  (numero == 0){
            serie2.Aniade(false);
        }
        cin >> numero;
    }
    
    //serie3=serie.Interseccion(serie2);
    
    
    cout << "CARDINAL" << endl;
    cout << serie.Cardinal() << endl;
    cout << endl;
    
    cout << "CARDINAL INTERSECCION " << endl;
    cout << serie3.Cardinal() << endl;
    
    cout << "\nINTRODUZCA UN NUMERO PARA VER SI PERTENECE AL CONJUNTO COPON" << endl;
    cin >> numero;
    
    if (serie.Pertenece(numero)){
        cout << "El\t" << numero <<  "\tpertenece al conjunto" << endl;
    }
    else {
        cout << "El \t" << numero <<  "\tNO pertenece al conjunto" << endl;
    }
    
    
}
