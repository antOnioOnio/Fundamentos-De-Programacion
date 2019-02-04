#include <iostream>
using namespace std ;

class SecuenciaCaracteres{
private:
    static const int CAPACIDAD = 1000;
    char vector_privado[CAPACIDAD];
    int utilizados;
public:
    SecuenciaCaracteres(){
        utilizados=0;
    }
    int Utilizados(){
        return utilizados;
    }
    void Aniade(char caracter){
        if(utilizados<CAPACIDAD){
            vector_privado[utilizados]=caracter;
            utilizados++;
        }
    }
    char Elemento(int posicion){
        if(posicion>=0 && posicion<utilizados){
            return vector_privado[posicion];
        }
        else {
            return -1;
        }
    }
    
    void ReemplazaAlargando(int pos_inicio, int n_a_quitar, SecuenciaCaracteres objeto){
        if ( n_a_quitar<objeto.Utilizados()){
         
            int pos_final = (pos_inicio+n_a_quitar)-1;
            int pos_amover = objeto.Utilizados() -n_a_quitar;
            int a_recorrer = pos_inicio + objeto.Utilizados();
            
            for ( int i = Utilizados() ; i> pos_final; i--){
                vector_privado[i+pos_amover]=vector_privado[i];
            
            }
            utilizados +=pos_amover;
            int pos = 0;
            for ( int i = pos_inicio ; i<a_recorrer; i++){
                vector_privado[i]=objeto.Elemento(pos);
                pos++;
            
            }
            
        }

    }
    int EncuentraPosicionCadena(SecuenciaCaracteres objeto){
        int pos=-1;
        bool sigue = true;
        bool esta = false;
        int contador = 0;
        int en_palabra=0;
        int pasos = Utilizados()-1;
        
        for ( int i = 0; i<objeto.Utilizados()&& !esta; i++){
            if(objeto.Elemento(i)==vector_privado[contador]){
                pos=i;
                en_palabra = i;
                while ( sigue){
                    contador++;
                    en_palabra++;
                    if (objeto.Elemento(en_palabra)==vector_privado[contador]){
                        contador++;
                        en_palabra++;
                    }
                    else{
                        sigue = false;
                    }
                }
                if(contador == Utilizados()-1){
                    esta=true;
                
                }
            }
        }
     
        return pos;

    }
    void MuestraVector(){
        for ( int i=0; i< utilizados; i++){
            cout << vector_privado[i];
        }
        cout<<endl;
    }
};

int main (){
    const char FIN = '.';
    int pos_inicio;
    char caracter;
    SecuenciaCaracteres mundo, hola_mundo;
    
    cout << " introduce caracteres primo : \n";
    caracter= cin.get();
    
    while ( caracter != FIN){
        
        mundo.Aniade(caracter);
        
        caracter= cin.get();
    }
    cin.ignore();
    cout << " introduce caracteres primo : \n";
    caracter= cin.get();
    
    while ( caracter != FIN){
        
      hola_mundo.Aniade(caracter);
    
        caracter= cin.get();
    }
 
    pos_inicio = mundo.EncuentraPosicionCadena(hola_mundo);
    
    cout << pos_inicio << "\n";
    
}
