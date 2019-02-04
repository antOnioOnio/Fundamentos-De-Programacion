
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
    void MuestraVector(){
        for (int i=0; i<total_utilizados ; i++){
            cout << vector_privado[i];
        }
        cout << endl;
    }
    char Elemento(int posicion){
        char elemento;
        if (posicion>=0 && posicion<TotalUsados()){
            elemento = vector_privado[posicion];
        
        }
        return elemento;
    }
    
};

class MatrizVocales{
private:
    static const int MAXFILAS = 5;
    static const int MAXCOLS = 500;
    char matriz[MAXFILAS][MAXCOLS];
    int util_fil_a,
        util_fil_e,
        util_fil_i,
        util_fil_o,
        util_fil_u;
public:
    MatrizVocales(){
        for(int i = 0; i<MAXFILAS ;i++){
            for (int j= 0 ; j<MAXCOLS ;j++){
                matriz[i][j]=' ';
            }
        }
        util_fil_a=MAXFILAS-2;
        util_fil_e=MAXFILAS-2;
        util_fil_i=MAXFILAS-2;
        util_fil_o=MAXFILAS-2;
        util_fil_u=MAXFILAS-2;
        matriz[MAXFILAS-1][0]='a';
        matriz[MAXFILAS-1][1]='e';
        matriz[MAXFILAS-1][2]='i';
        matriz[MAXFILAS-1][3]='o';
        matriz[MAXFILAS-1][4]='u';
    }
    void MuestraMatriz(){
        for(int i = 0; i<MAXFILAS ;i++){
            for (int j= 0 ; j<MAXCOLS ;j++){
                cout<<  matriz[i][j];
            }
        }
        cout << "\n" ;
    }
    void AniadeFrecuencia (char vocal){
        if ( vocal == 'a' ){
            matriz[util_fil_a][0]='*';
            util_fil_a--;
        }
        if ( vocal == 'e' ){
            matriz[util_fil_e][1]='*';
            util_fil_e--;
        }
        if ( vocal == 'i' ){
            matriz[util_fil_i][2]='*';
            util_fil_i--;
        }
        if ( vocal == 'o' ){
            matriz[util_fil_o][3]='*';
            util_fil_o--;
        }
        if ( vocal == 'u' ){
            matriz[util_fil_u][4]='*';
            util_fil_u--;
        }
    
    }
    void RellenaMatriz (SecuenciaCaracteres objeto){
        for (int i =0 ; i< objeto.TotalUsados() ; i++){
            if (objeto.Elemento(i)=='a'){
                AniadeFrecuencia('a');
            }
            if (objeto.Elemento(i)=='e'){
                AniadeFrecuencia('e');
            }
            if (objeto.Elemento(i)=='i'){
                AniadeFrecuencia('i');
            }
            if (objeto.Elemento(i)=='o'){
                AniadeFrecuencia('o');
            }
            if (objeto.Elemento(i)=='u'){
                AniadeFrecuencia('u');
            }
        }
    
    }
};
int main() {
    const char FIN = '#';
    char caracter;
    SecuenciaCaracteres texto;
    MatrizVocales objeto;
    
    cout << " Introduce caracteres: \n";
    caracter = cin.get();
    
    while ( caracter != FIN){
        texto.Aniade(caracter);
        caracter=cin.get();
    }
    objeto.RellenaMatriz(texto);
    objeto.MuestraMatriz();
    return 0;
}
