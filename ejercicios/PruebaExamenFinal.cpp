//Víctor Moreno
#include <iostream>
using namespace std;
const int CAPACIDAD=100;

class Reales{
	private:
		
		double vector[CAPACIDAD];
		int utilizados;
		
	public:
		Reales(){
			for (int i=0;i<utilizados;i++){
				vector[i]=0;
			}
			utilizados=0;
		}
		void Aniade(double num){
			if (utilizados<CAPACIDAD){
				vector[utilizados]=num;
				utilizados++;
			}
		}
		int Elemento(int posicion){
			return vector[posicion];
		}
		int getUtilizados(){
			return utilizados;
		}
		void Muestra(){
			for (int i=0;i<utilizados;i++){
				cout << vector[i] << "\t";
			}
		}
		void Elimina(){
			utilizados=0;
		}
		void intercambia(int pos1,int pos2){
			double aux;
			aux=vector[pos1];
			vector[pos1]=vector[pos2];
			vector[pos2]=aux;
			
		}
		void ordenar(){
			int derecha, izquierda;
			for(int i = 0; i < utilizados; i++){
				derecha = vector[i];
				izquierda = vector[i-1];			
				if(i != 0){
					int cont = i;
					while(derecha < izquierda && cont > 0){
						intercambia(cont, cont-1);
						cont--;
						derecha = vector[cont];
						izquierda = vector[cont-1];
					}
				}
			}
		}
};
class Intervalo{
	private:
		Reales interval;
		char cota_inferior;
		char cota_superior;
	
		
	public:
		Intervalo(){
			interval.Elimina();
		}
		void Aniade2(double num){
			interval.Aniade(num);
		}
		bool pertenece(double num){
			bool esta=false;
			for (int i=0;i<interval.getUtilizados();i++){
				if (interval.Elemento(i)==num){
					esta=true;
				}
			}
			return esta;
		}
		Reales Contenidos(Reales objeto){
			Reales interseccion;
			
			for (int i=0;i<objeto.getUtilizados();i++){
				if (i==0 && cota_inferior=='['){
					if (pertenece(objeto.Elemento(0))){
						interseccion.Aniade(objeto.Elemento(0));
						
					}
				}
				if (i==(objeto.getUtilizados()-1) && cota_superior==']'){
					if(pertenece(objeto.Elemento(objeto.getUtilizados()-1)))
					interseccion.Aniade(objeto.Elemento((objeto.getUtilizados()-1)));
				}

				if (i!=0 && i!= (objeto.getUtilizados()-1)){
					if (pertenece(objeto.Elemento(i))){
						interseccion.Aniade(objeto.Elemento(i));
					}
				}
			}
			
			return interseccion;
		}
		void setCotaSuperior(char cota){
			cota_superior=cota;
		}
		void setCotaInferior(char cota){
			cota_inferior=cota;
		}
		char getSuperior(){
			return cota_superior;
		}
		char getInferior(){
			return cota_inferior;
		}
		
	};
	
	int main(){
		const int FIN=-1;
		double numero;
		char superior,inferior;
		bool superior_valida;
		bool inferior_valida;
		Intervalo interv;
		Reales secuencia;
		Reales final;
		
		
		cout << "RELLENA INTERVALO: \t" ;
		cin >> numero;
		
		while (numero != FIN){
			interv.Aniade2(numero);
			cin >> numero;
		}
		
		do{
			
			cout << "COTA SUPERIOR \t";
			cin >> superior;
			superior_valida=(superior == ')' || superior == ']');
		}while (!superior_valida);
		
		do{
			cout << "COTA INFERIOR \t";
			cin >> inferior;
			inferior_valida=(inferior == '(' || inferior == '[');
		}while (!inferior_valida);
		
		interv.setCotaSuperior(superior);
		interv.setCotaInferior(inferior);
		
		cout << "RELLENA VECTOR \t";
		cin >> numero;
		
		while (numero != FIN){
			secuencia.Aniade(numero);
			cin >> numero;
		}
		
		secuencia.ordenar();
		
		final=interv.Contenidos(secuencia);
		
		final.Muestra();
		
	}
