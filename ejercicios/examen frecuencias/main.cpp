#include<iostream>
#include<cctype>
using namespace std;

class frecuencias{
private :
    static const int CAPACIDAD= 255 ;
    char letras[CAPACIDAD];
    int frecu[CAPACIDAD];
    int usados;
public:
    frecuencias(){
        usados = 0;
    }
    int Usados(){
        return usados;
    }
    int FrecuenciaLetra(char letra){
        return frecu[letra];
    }
    bool Pertenece (char letra){
        bool esta = false;
        for ( int i = 0; i< usados-1 && !esta ; i++){
            if ( letras[i]==letra){
                esta=true;
            }
        }
        return esta;
    }
    void Aniade(char letra){
        int posicion = letra;
        
        if (!Pertenece(letra)){
            usados++;
        }
        if ( usados < CAPACIDAD){
            letras[posicion]=letra;
            frecu[letra]++;
        }
    }
    void VaciaVector(){
        for (int i=0; i<CAPACIDAD ; i++){
            frecu[i]=0;
        }
    }
    
    void Muestra(){
        for ( int i = 0; i<CAPACIDAD; i++){
            if (frecu[i]!=0){
                if ((letras[i]>='A') && (letras[i]<='Z') || letras[i]>='a' && letras[i]<='z'){
                    
                    cout << letras[i] << ": " <<frecu[i] << "\n";
                    
                }
            }
        }
    }
    char FrecuenciaMaxima(){
        char letra = ' ' ;
        int frecuencia_max = 0;
        for ( int i = 0; i<CAPACIDAD; i++){
            if ( frecu[i]>frecuencia_max){
                frecuencia_max = frecu[i];
                letra = letras[i];
            }
        
        }
        
        return letra;
    }
    
};
int main (){
    const char FIN = '.';
    frecuencias fr_texto;
    char caracter;
    
    fr_texto.VaciaVector();
    cout << " sh cuchame, metele caracteres a eso:\n ";
    
    caracter = toupper(cin.get());
    
    
    
    while( caracter != FIN){
        fr_texto.Aniade(caracter);
        caracter = toupper(cin.get());
    }

    fr_texto.Muestra();
    caracter = fr_texto.FrecuenciaMaxima();
    cout << " letras mas repetida " << caracter << endl;
}
