//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Alberto Fernández Hilario
//
//////////////////////////////////////////////////////////////////////////

// Media de un conjunto de numeros y mostrar si son mayor o igual a ésta

/*
Escriba un algoritmo para calcular la media aritmética muestral y la desviación estándar
(o típica) muestral de las alturas de tres personas (n=3). Éstos valores serán
reales (de tipo double). La fórmula general para un valor arbitrario de n 
aparece en la relacion de problemas.
* 
Para resolver este problema es necesario usar la función sqrt (raíz cuadrada) 
que se encuentra en la biblioteca cmath.

Estas medidas se utilizan mucho en Estadística para tener una idea de la distribución
de datos. La media (mean en inglés) nos da una idea del valor central y
la desviación típica (standard deviation) nos da una idea de la dispersión de éstos.
Ejecutad el programa con varios valores y comprobad que el resultado es correcto
utilizando una calculadora científica o cualquier calculadora online
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	//Declaracion de variables
	int altura1, altura2, altura3;
	double media,desv_tipica;
	
	//Entrada
	cout << "Introduzca la altura de las tres personas (en centimetros): " << endl;
	cin >> altura1 >> altura2 >> altura3;
	
	//Calculos
	media = (altura1 + altura2 + altura3)/3.0;
	desv_tipica = sqrt(
					((altura1 - media)*(altura1 - media) +
					(altura2 - media)*(altura2 - media) +
					(altura2 - media)*(altura2 - media))/3.0);
	
	//Salida
	cout << "Media aritmetica: " << media << endl;
	cout << "Desviacion tipica: " << desv_tipica << endl;
	cout << endl;
	
	if (altura1 < media){
		cout << altura1 << " es menor que su media" << endl;
	}else{
		cout << altura1 << " es mayor o igual que su media" << endl;
	}
	
	if (altura2 < media){
		cout << altura2 << " es menor que su media" << endl;
	}else{
		cout << altura2 << " es mayor o igual que su media" << endl;
	}
	
	if (altura3 < media){
		cout << altura3 << " es menor que su media" << endl;
	}else{
		cout << altura3 << " es mayor o igual que su media" << endl;
	}
	
	//Fin del programa
	return 0;
	
}
 
