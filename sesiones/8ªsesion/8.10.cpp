/*Retome la solución del ejercicio 23 (población) de la Relación de Problemas II. Re- escríbalo usando las funciones                       del ejercicio 4 para leer los valores de las tasas y                                       del ejercicio 5 para leer el número de años que sea positivo. Defina también sendas funciones para calcular los dos valores que se piden en el ejercicio, a saber, el número de habitantes después de tres años y el número de años que pasarán hasta doblar la población inicial. Intente diseñar las funciones para que sean lo más generales posible.*/
// Ejercicio 10 de la sesion 8. Antonio Garcia Castillo

#include <iostream>
using namespace  std;

// FUNCION QUE NOS SERVIRA PARA QUE LAS TASAS ESTEN EN EL INTERVALO 0-100

bool LeeIntRango (long long numero){
    
    
    
    if ( numero >=0 && numero<=1000 )
        
        return true;
    
    else
        
        return false ;
}

// FUNCION QUE NOS SERVIRA PARA QUE LOS DATOS INTRODUCIDOS SEAN POSITIVOS
bool LeePositivo(long long numero){
    
    if ( numero>0)
        
        return true;
    
    else
        
        return false;

}

// FUNCION QUE NOS SERVIRA PARA CALCULAR LA POBLACION A LOS X ANIOS
long long Poblacion_x_anios ( long long poblacion_inicial, long long  suma_tasas, long long anios ){

   
    int contador = 0;
    double incremento, pob_final;
    
    pob_final=poblacion_inicial;
    
    while ( contador < anios){
        
        incremento = (pob_final/1000.0) * suma_tasas;
        pob_final = pob_final + incremento;
        contador ++;
    }
   
    return pob_final;



}
// FUNCION QUE NOS SERVIRA PARA CALCULAR LOS ANIOS NECESARIOS PARA DOBLAR LA POBLACION
long long Doble_Poblacion ( long long poblacion_inicial, long long suma_tasas){

    int anios_necesarios = 0;
    double incremento, pob_final, doble_poblacion;
    
    pob_final= poblacion_inicial;
    
    doble_poblacion = poblacion_inicial * 2;
    
    do{
        
        incremento = (pob_final/1000.0) * suma_tasas;
        pob_final = pob_final + incremento;
        anios_necesarios ++;
        
    }while ( pob_final < doble_poblacion );


    return anios_necesarios;

}
// FUNCION MAIN PRINCIPAL
int main() {
    
    long long  pob_inicial, tasa_natal, tasa_mortal, tasa_emigra, pob_final, numero_anios;
    long long  tasa_total,anios_doble_poblacion;
    
    bool anio_positivo,natalidad_positivo,mortalidad_positivo,emigracion_positivo,poblacion_positivo;
    
    // introduccion de datos
    
    do {
    cout << " introduce poblacion inicial " << endl;
    cin >> pob_inicial;
    
    poblacion_positivo = LeePositivo(pob_inicial);
        
    }while (poblacion_positivo == false );
    
    do {
    cout << " Introduzca la tasa de natalidad"<<endl;
    cin >> tasa_natal ;
    
    natalidad_positivo = LeeIntRango(tasa_natal);
    
    }while ( natalidad_positivo == false);
    
    
    do {
    cout << " Introduzca la tasa de mortalidad"<<endl;
    cin >> tasa_mortal ;
    
    mortalidad_positivo = LeeIntRango(tasa_mortal);
    
    }while ( mortalidad_positivo == false);
    
    do{
    cout << " Introduzca la tasa de emigracion"<<endl;
    cin >> tasa_emigra ;
    
    emigracion_positivo = LeeIntRango(tasa_emigra);
    
    }while ( emigracion_positivo == false);
    
    do{
    cout << " Introduzca el numero de años " <<endl;
    cin >> numero_anios;
    
    anio_positivo = LeePositivo( numero_anios);
        
    }while ( anio_positivo==false);

    tasa_total = tasa_natal + tasa_emigra - tasa_mortal ;
    
    // calculos
    

        
    pob_final =Poblacion_x_anios(pob_inicial, tasa_total, numero_anios);
    
    
    anios_doble_poblacion = Doble_Poblacion(pob_inicial, tasa_total);
    
    
    cout << "La poblacion final a los " <<numero_anios << " años sera de : " << pob_final << " habitantes"<<endl;
    
    cout << "Los años necesarios para doblar la población son " << anios_doble_poblacion <<endl;
    
    
    
    
    return 0;
    
}

