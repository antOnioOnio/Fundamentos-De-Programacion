#include <iostream>
#include <string>
using namespace std;

int leerNumeroCondicion(string mensaje, int limite);
bool numerosAmigos(int num1, int num2);
int sumaDivisores(int numero);
bool amigosRango(int numero, int radio);

int main(){
	int numero1, numero2;
	
	numero1 = leerNumeroCondicion("Introduce un Numero Positivo",0);
	numero2 = leerNumeroCondicion("Introduce otro Numero Positivo",0);
	
	//Parte 1
	bool amigos = numerosAmigos(numero1, numero2);

	cout << "Los numeros " << numero1 << " y " << numero2;
	if (amigos){
		cout << " son amigos" << endl;
	}else{
		cout << " NO son amigos" << endl;
	}
	
	
	//Parte 2
	numero1 = leerNumeroCondicion("Introduce otro Numero Positivo",0); 
	bool existeAmigo = amigosRango(numero1, 3);
	if (existeAmigo){
		cout << "SI ";
	}else{
		cout << "NO ";
	}
	cout << "existe numero amigo para " << numero1 << " en un radio " << numero1/3 << endl;
	
	
	return 0;
}

int leerNumeroCondicion(string mensaje, int limite){
	int numero;
	cout << mensaje << endl;
	cin >> numero;
	while(numero <= limite){
		cout << mensaje << endl;
		cin >> numero;
	}
	return numero;
}

bool numerosAmigos(int num1, int num2){
	int sumaDiv1, sumaDiv2;
	sumaDiv1 = sumaDivisores(num1);
	sumaDiv2 = sumaDivisores(num2);
	return ((sumaDiv1 == num2) && (sumaDiv2 == num1));
}

int sumaDivisores(int numero){
	int suma = 1;
	int limite = numero/2; //asi no se calcula esta expresion en cada etapa del bucle
	for (int i = 2; i <= limite; i++){
		suma += numero%i == 0?i:0;
	}
	return suma;
}

bool amigosRango(int numero, int radio){
	int inicio = numero - numero/radio;
	int fin = numero + numero/radio;
	bool amigos = false;
	for (int i = inicio; i < fin && !amigos; i++){
		if (i == numero)
			continue;
		amigos = numerosAmigos(numero, i);
	}
	return amigos;
}
