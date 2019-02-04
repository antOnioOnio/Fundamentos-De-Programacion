

// Examen de los jinetes del otro grupo

	#include <iostream>
	using namespace std;
	
	int main (){
		
		const int FIN=0;
		int dorsal, puertas, segundos, puntos, pen_minima=100, time_minimo=400, ganador;
		
			do{
				
				cout <<"\nDorsal nº: ";
				cin >> dorsal;
				
			}while(dorsal<0 && dorsal != FIN);
			
			while (dorsal != FIN){
				
				do{
				
					cout << "\n Numero de Puertas derribadas: ";
					cin>> puertas;
				
				}while (puertas < 0);
				
				puntos = puertas * 4 ;	
				
				do{
					
					cout << "\nTiempo del jinete en segundos: ";
					cin >> segundos;
					
				}while(segundos<0);
				
				if (segundos < 180){
					puntos = puntos ;
				}
				else if ( segundos <190){
					puntos = puntos + 1;
				}
				else if ( segundos <195){
					puntos = puntos + 2;
				}
				else {
					puntos = puntos + 4;
				}
				if ( puntos<pen_minima){
					if (segundos<time_minimo){
						pen_minima=puntos;
						time_minimo=segundos;
						ganador=dorsal;
					}
				}
				
				do{
				
				cout <<"\nDorsal nº: ";
				cin >> dorsal;
				
			}while(dorsal<0 && dorsal != FIN);
			}
		cout << " \nDorsal Ganador: " <<ganador <<endl;
		cout << " \nCon una penalizacion de: " <<pen_minima << " puntos "<<endl;
		cout << " \ny un tiemo de " <<time_minimo << " segundos "<< endl;
	
		return 0;		 
	}
