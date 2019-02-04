/*

Programa que calcula el campeon de una competicion de salto de caballo. Donde cada jinete viene identificado por un dorsal y 
la puntuacion de un gimnasta es la media de las 3 notas. Mostrar la máxima nota obtenida en el campeonato.
*/

#include <iostream>
#include <climits>

using namespace std;



int leePositivo(string msg){
int dato;

    do {			//Filtro de lectura de numero positivo
            cout << msg;
            cin >> dato;
      }
     while(dato < 0 );
    return dato;
}

int penalizacionTiempo(int tiempo){

    const int TIEMPO_PENA1 = 180;
    const int TIEMPO_PENA2 = 190;
    const int TIEMPO_PENA3 = 195;

    const int PENAT1 = 1;
    const int PENAT2 = 2;
    const int PENAT3 = 4;

    int penalizacion = 0;

    if ( tiempo > TIEMPO_PENA1)
	if (tiempo < TIEMPO_PENA2)
	    penalizacion += PENAT1;
	else if (tiempo < TIEMPO_PENA3)
	    penalizacion += PENAT2;
	else  penalizacion += PENAT3;
     return penalizacion;
}


int main() {

const int FIN = 0;
    const string MSGDERRIBOS= "Numero derribos  :";
    const string MSGDORSAL = "Introduce numero de dorsal  (0 para salir del programa): ";
    const string MSGTIEMPO = "Introduce tiempo : ";
    const int PENADERRIBO = 4;

 
    const string MSGMEDIA = "Penalizacion obtenida: ";
    const string SALIDAGANADOR = "Dorsal ganador: ";
    const string SALIDAPENA = "La minima penalizacion  : ";
    const string SALIDATIEMPO = "con el menor tiempo : ";
    const string NODATOS = "No se ha introducido ningun dato.";


    			//Declaración de variables
    int dorsal, dorsalGana;
    int derribos;
    int tiempo, tiempoMin;
    int penalizacion, penalizacionMin;
  

    // //Lectura adelantada 

    penalizacionMin = INT_MAX;
    dorsal= leePositivo(MSGDORSAL);

    while(dorsal != FIN) { 		//Bucle para controlar fin de entrada de datos

            derribos = leePositivo(MSGDERRIBOS);
    	    tiempo = leePositivo(MSGTIEMPO);
            penalizacion = derribos * PENADERRIBO;

            penalizacion += penalizacionTiempo(tiempo);

            if (penalizacion < penalizacionMin){
                penalizacionMin = penalizacion;
                tiempoMin = tiempo;
		dorsalGana = dorsal;
            }
            else if (penalizacion == penalizacionMin) 
                     if (tiempo < tiempoMin){
                	 tiempoMin = tiempo;
			 dorsalGana = dorsal;
                     }

            dorsal= leePositivo(MSGDORSAL);

     } // fin while

     if (penalizacionMin != INT_MAX) {     // han habido JINETES
        cout << SALIDAPENA << penalizacionMin << endl;
        cout << SALIDATIEMPO << tiempoMin << endl;
        cout << SALIDAGANADOR << dorsalGana << endl;
     }
     else
        cout << NODATOS << endl;

}
 
