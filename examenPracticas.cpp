//NOMBRE: Antonio Garcia Castillo
//DNI:76420014F
//PROBLEMA: telefono

#include<iostream>
#include<cmath>
using namespace std;
// struct que usamos para la llamada
struct Tiempo{
	int hora;
	int min;
	int segundo;

};
// definimos nuestra clase llamada 
class Llamada{
	private:
		int emisor;
		int receptor;
		Tiempo inicio;
		Tiempo final;
	public:
	// constructor por defecto
		Llamada(){
			emisor = 0;
			receptor = 0;
			inicio.hora = 0;
			inicio.min = 0;
			inicio.segundo = 0;
			final.hora = 0;
			final.min = 0;
			final.segundo = 0;
		}
		//Constructor con parametros
		Llamada(int emi, int recep, int hora_i, int min_i, int seg_i, int hora_f, int min_f, int seg_f ){
			emisor = emi;
			receptor= recep;
			inicio.hora = hora_i;
			inicio.min = min_i;
			inicio.segundo = seg_i;
			final.hora = hora_f;
			final.min = min_f;
			final.segundo = seg_f;
		
		}
		int getEmisor(){
			return emisor;	
		}
		int getReceptor(){
			return receptor;
		}	
		int getHoraInicial(){
			return inicio.hora;
		}
		int getHoraFinal(){
			return final.hora;
		}
		int getMinInicial(){
			return inicio.min;
		}
		int getMinFinal(){
			return final.min;
		}
		int getSegInicial(){
			return inicio.segundo;
		}
		int getSegFinal(){
			return final.segundo;
		}
		int TiempoLlamada(){
			const int Pasar=60;
			int segundosInicial=0;
			int segundosFinal=0;
			int tiempoTotal=0;
			
			segundosFinal=getSegFinal()+getMinFinal()*Pasar + getHoraFinal()*Pasar*Pasar;
			
			segundosInicial = getSegInicial()+getMinInicial()*60 + getHoraInicial()*Pasar*Pasar;
			
			tiempoTotal= segundosFinal - segundosInicial;
			
			return abs(tiempoTotal);
		}
};
// definimos nuestra clase que contendra un vector de llamadas
class EmpresaLlamadas{
	private: 
		static const int CAPACIDAD=1000;
		Llamada vector_privado[CAPACIDAD];
		int utilizados;
	public:
		// Normalmente lleno el vector de ceros antes de inicializar el utilizados
		// pero al ser un vector de objetos y no estar seguro he 
		// preferido dejar el utilizados a cero y yasta.
		EmpresaLlamadas(){
			utilizados = 0;
		}
		void Aniade(Llamada objeto){
			if (utilizados<CAPACIDAD){
				vector_privado[utilizados]=objeto;
				utilizados++;
			}
		}
		int Utilizados (){
			return utilizados;
		}
		
		int TiempoLlamadas(){
			int tiempototal = 0;
				for (int i = 0; i<Utilizados() ;  i++){
					tiempototal += vector_privado[i].TiempoLlamada();
				}
		
			return tiempototal;
		}
		// booleana de apoyo para saber si es interna o no
		bool EsInterna(Llamada llamada){
			
			bool es = false;
			int diferencia = abs(llamada.getEmisor() - llamada.getReceptor());
				if ( diferencia <= 100){
					es = true;
				}
			
		return es;
		}
		int NumeroInternas(){
			int contador =0;
			for (int i = 0; i< Utilizados() ; i++){
				if (EsInterna(vector_privado[i])){
					contador++;
				}
			
			}
			return contador;
		}
		
		int DuracionMedia(){
			return TiempoLlamadas()/Utilizados() ;
		}
		int SuperanMedia(){
			int contador = 0;
				for (int i = 0; i< Utilizados() ; i++){
					if (vector_privado[i].TiempoLlamada() > DuracionMedia()){
						contador++;
					}
				}
				
			return contador;
		}

		Llamada MasLarga(){
			Llamada larga;
			int maxima = -1;
			for ( int i = 0; i<Utilizados(); i++){
				if (vector_privado[i].TiempoLlamada() > maxima){
					maxima = vector_privado[i].TiempoLlamada();
					larga = vector_privado[i];
					
				}
			}
			return larga;
		}
		int LlamadasEntre9_10(){
			int numero = 0;
			Llamada objeto;
			for (int i=0; i<Utilizados(); i++){
				objeto = vector_privado[i];
				if (objeto.getHoraInicial() ==9 || objeto.getHoraFinal()==10){
					numero++;
				}
			}
			return numero;
		}
		
};
// funcion principal
int main (){
	const int FIN = -1 ;
	int emisor = 0;
	int receptor = 0;
	int hora_i = 0;
	int min_i = 0;
	int seg_i = 0;
	int hora_f = 0;
	int min_f = 0;
	int seg_f = 0;
	// Creo objeto llamada que igualare al metodo que me devuelve un objeto de mi otra clase
	Llamada mas_larga;
	// Creo mi objeto de mi clase EmpresaLlamadas, el cual contiene mi vector de llamadas
	EmpresaLlamadas llamadas;
	// rellenamos el vector
	cout << "Emisor: \t";
	cin >> emisor ;
	
	while (emisor != FIN ){
		cout << "Receptor: \t";
		cin >> receptor;
		
		cout << "Hora Inicial: \t";
		cin >> hora_i;
		
		cout << "Minuto Inicial: \t";
		cin >> min_i;
		
		cout << " Segundo Inicial: \t " ;
		cin >> seg_i;
		
		cout << "Hora final: \t";
		cin >> hora_f;
		
		cout << "Minuto final: \t";
		cin >> min_f;
		
		cout << " Segundo final: \t " ;
		cin >> seg_f;
		
		Llamada una_llamada(emisor,receptor,hora_i,min_i,seg_i,hora_f,min_f,seg_f);
		
		llamadas.Aniade(una_llamada);
		
		cout << "Emisor: \t";
		cin >> emisor ;
	} 
	 // Muestra resultados
	 cout << " La duracion total en llamadas es : \t " << llamadas.TiempoLlamadas() << endl;
	 cout << " La duracion media de las llamadas es de : \t " << llamadas.DuracionMedia() << endl;
	 cout << " Numero de llamadas internas : \t "<< llamadas.NumeroInternas() << endl;
	 cout << " Numero de llamadas que superan la media : \t" << llamadas.SuperanMedia() << endl;
	 
	 mas_larga = llamadas.MasLarga();
	 
	 cout << " Emisor llamada mas larga : " << mas_larga.getEmisor() << endl;
	 cout << " Receptor de la llamada mas larga: " << mas_larga.getReceptor() << endl;
	 cout << " Numero de llamadas entre las 9 y las 10 " <<llamadas.LlamadasEntre9_10() << endl;
}
