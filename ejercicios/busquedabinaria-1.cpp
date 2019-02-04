//Busqueda binaria:

#include <iostream>
using namespace std;

int main (){
	const int TAM=100;
	const int FIN=-1;
	int vector[TAM];
	int total_utilizados=0, buscar, izda,dcha, centro, numero, posicion;
	bool encontrado, cambio;
	
	for (int i=0;i<TAM;i++){
		vector[i]=0; //Inicializamos vector a 0;
	}
	
	cout << "\nRELLENA VECTOR -1 PARA TERMINAR \t";
	cin >> numero;

	while (numero != FIN || total_utilizados > TAM){
		
			vector[total_utilizados]=numero;
			total_utilizados++;
		
			cin >> numero;
		}
	//En el caso de que el vector no este ordenado lo ordenamos por burbuja;
	
	int aux;
	cambio=true;
	
	for (int i=0;i<total_utilizados && cambio;i++){
		cambio=false;
		for (int j=total_utilizados-1;j>i;j--){
			if (vector[j]<vector[j-1]){
				aux=vector[j];
				vector[j]=vector[j-1];
				vector[j-1]=aux;
				
				cambio=true;
			}
			
		}
	}
	
	cout << "\nINTRODUCE NUMERO A BUSCAR \t";
	cin >> buscar;
	
	//Búsqueda Binaria.
	
	izda=0;
	dcha=total_utilizados-1;
	centro=(izda+dcha)/2;
	encontrado=false;
	
	while (izda <= dcha && !encontrado){
		if (centro == buscar){
			encontrado=true;
		}
		else if (centro >= buscar){
			dcha=centro-1;
		}
		else  {
			izda=centro+1;
		}

		centro=(izda+dcha)/2;
	}
	if (centro != buscar){
		cout << "\nEl numero no pertenece al vector \t" << endl;
	}

	for (int i=0;i<total_utilizados;i++){
		cout << vector[i] << endl;
	}
	if (centro == buscar){
		bool encontrado1=false;
		for (int i=0;i<total_utilizados && !encontrado;i++){
			if (vector[i]==buscar){
				posicion=i;
				encontrado=true;
			}
		}
		cout << "\nEl elmento buscado  \t " << centro  << "\nEn la posicion \t" << posicion << endl;
	}
	else 
		cout << "Nada mas que añadir";
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
