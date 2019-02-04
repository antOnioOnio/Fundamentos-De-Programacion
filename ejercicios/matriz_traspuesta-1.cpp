/*MATRIZ TRASPUESTA*/

#include <iostream>
using namespace std;

int main (){
	int util_columnas, util_filas,numero;

	cout << "\nUTIL COLUMNAS \t";
	cin >> util_columnas;
	
	cout << "\nUTIL FILAS \t";
	cin >> util_filas;
	
	int 
	matriz[util_filas][util_columnas];
	
	cout << "\nRELLENA LA MATRIZ \t";
	
	for (int i=0;i<util_filas;i++){
		for (int j=0;j<util_columnas;j++){
			cin >> numero;
			matriz[i][j]=numero;
		}
	}
	//Imprimimos la matriz
	cout << "\nMATRIZ INTRODUCIDA : \t" << endl;
	cout << endl;
	
	for (int i=0;i<util_filas;i++){
		for (int j=0;j<util_columnas;j++){
			cout << matriz[i][j];
		}
		cout << endl;
	}
	//Traspuesta
	cout << "\nTRASPUESTA \t" << endl; 
	cout << endl;
	
	for (int i=0;i<util_filas;i++){
		for (int j=0;j<util_columnas;j++){
			cout << matriz[j][i];
		}
		cout << endl;
	}

}
