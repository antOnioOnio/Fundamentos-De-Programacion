/*Amplie el ejercicio 12 (Población) de la relación de problemas I.
 Esta nueva versión del programa, además de los datos ya pedidos en dicho ejercicio, se le pedirá al usuario que introduzca un número de años (será el último dato leído) Debe leer cada dato con un filtro conveniente. Por ejemplo, las tasas de natalidad, mortalidad y emigración deben ser enteros entre 0 y 1000, mientras que la población inicial debe ser un entero positivo.
 El programa debe calcular e imprimir el número total de habitantes transcurridos dichos años.
 Además, el programa también calculará el número de años que tienen que pasar hasta que haya, como mínimo, el doble de la población inicial. Imprima dicho número de años, junto con la población que habrá pasado ese tiempo.*/
#include <iostream>
#include <cmath>

using namespace std;


int main() {
    
   long long  pob_inicial, tasa_natal, tasa_mortal, tasa_emigra, pob_final, numero_anios, doble_poblacion;
    long tasa_total, incremento, contador,anios_doble_poblacion;
    
    // introduccion de datos
    
    do {
        cout << " Introduzca la poblacion inicial:"<<endl;
        cin >> pob_inicial;
    }while( pob_inicial<0);
    
    do {
        cout << " Introduzca la tasa de natalidad"<<endl;
        cin >> tasa_natal ;
    }while (tasa_natal <= 0 && tasa_natal>=1000);
    
    do {
        cout << " Introduzca la tasa de mortalidad" <<endl;
        cin >> tasa_mortal ;
    }while(tasa_natal <= 0 && tasa_natal>=1000);
    
    do {
        cout << " Introduzca la tasa de emigracion"<<endl;
        cin >> tasa_emigra ;
    }while(tasa_natal <= 0 && tasa_natal>=1000);
    
    cout << " Introduzca el numero de años " <<endl;
    cin >> numero_anios;
    
    
    
    
    // calculos
    
    tasa_total = tasa_natal + tasa_emigra - tasa_mortal;
    incremento = (pob_inicial/1000.0) * tasa_total;
    pob_final = pob_inicial + incremento;
    contador = 1;
    doble_poblacion = (pob_inicial)*2;
   
    
    while ( contador < numero_anios){
        
        incremento = (pob_final/1000.0) * tasa_total;
        pob_final = pob_final + incremento;
        contador += 1;
        }
    
       cout << "La poblacion final a los " <<numero_anios << " años sera de : " << pob_final << " habitantes"<<endl;
    

    anios_doble_poblacion = 0 ;
    pob_final= pob_inicial;    
    do{
        incremento = (pob_final/1000.0) * tasa_total;
        pob_final = pob_final + incremento;
        anios_doble_poblacion += 1;
        
    }while ( pob_final < doble_poblacion );
    
    //Muestra resultados
    
    cout << "Los años necesarios para doblar la poblacion son " <<anios_doble_poblacion <<endl;
    
    cout << "La poblacion final a los " <<anios_doble_poblacion << " sera de " << pob_final << " habitantes" << endl;
}
