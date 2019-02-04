// programa simula examen

	#include <iostream> 
	
	using namespace std ;
	
	int main (){
		
		const int FIN = -1 ;
		int cod_empleado, edad_empleado, edad_mas_joven = 100,contador = 0;
		double sueldo_empleado, sueldo_mas_joven = 0, nuestro_trabajador, edad_acumulada = 0, media_sueldo = 0, media_edad = 0, sueldo_acumulado=0;
		
		do{
			cout << "codigo del empleado : ";
			cin >> cod_empleado;
		}while ( cod_empleado < 0 && cod_empleado != FIN);
		
		while ( cod_empleado !=FIN){
			
			contador++;
			
			do{
				cout << "edad del empleado : ";
				cin >> edad_empleado;
			}while ( edad_empleado < 0);
			
			do{
				cout << " sueldo del empleado : " ;
				cin >> sueldo_empleado ; 
			}while ( sueldo_empleado < 0);
			
			if ( edad_empleado <= edad_mas_joven ){
				if ( sueldo_empleado >sueldo_mas_joven){
					edad_mas_joven=edad_empleado;
					sueldo_mas_joven= sueldo_empleado;
					nuestro_trabajador = cod_empleado;
				}
			}
			edad_acumulada += edad_empleado;
			sueldo_acumulado += sueldo_empleado;
			
			do{
				cout << "codigo del empleado : ";
				cin >> cod_empleado;
			}while ( cod_empleado < 0 && cod_empleado != FIN);
		}
		
		media_edad = edad_acumulada*1.0 / contador ;
		media_sueldo = sueldo_acumulado*1.0 / contador ;
		
		cout << " codigo del empleado mas joven y que cobra mas " << nuestro_trabajador;
		cout << " su edad " << edad_mas_joven;
		cout << " su sueldo" << sueldo_mas_joven;
		cout << " edad media "<< media_edad;
		cout << " sueldo medio "<< media_sueldo;		
		
		
		
		
	return 0 ;
		
		
		
		
		
		
		
		
		
	}
