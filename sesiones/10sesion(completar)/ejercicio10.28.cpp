//
//  main.cpp
//  nueva poblacion
//
//  Created by antonio garcia on 12/12/16.
//  Copyright © 2016 antonio garcia. All rights reserved.
//

#include <iostream>
using namespace std;

long long LeeLongLongMayorQue( long long minimo, string mensaje ){

    long long dato;
    do {
        cout << mensaje ;
        cin >> dato ;
    }while ( dato < minimo );

    return dato;
}
double  LeeDoubleEnrango( double minimo, double maximo, string mensaje){
    
    double dato;
    do {
        cout << mensaje;
        cin >> dato;
        
    }while ( dato < minimo || dato > maximo);


    return dato;
}

class CalculaPoblacion {
    private :
    long long Poblacion_inicial;
    double tasa_crecimiento;
    bool EsCorrectaTasa(double tasa){
    
     return (tasa >=0 && tasa <=1000 );
    }
    bool EsCorrectaPoblacion( long long pob){
        
        return ( pob >= 0);
        
    }
    public :
    CalculaPoblacion ( long long pob_inicial, double t_natal, double t_mortal, double t_migra){
    
        if ( EsCorrectaPoblacion(pob_inicial) && EsCorrectaTasa(t_natal) && EsCorrectaTasa(t_mortal) && (EsCorrectaTasa(t_migra)||EsCorrectaTasa(-t_migra))){
            Poblacion_inicial = pob_inicial;
            tasa_crecimiento = t_natal + t_migra -t_mortal;
        }
    }
    long long Poblacion_Futura ( int anios){
        
        long long pob_futura;
        double t_crecimiento;
        
        
        pob_futura = Poblacion_inicial;
        
        for ( int i=0 ; i < anios ; i++ ){
        pob_futura += (pob_futura/1000.0) * tasa_crecimiento;
        }
        
        return pob_futura;
    }
    
    int NumeroAniosHastaObtener(long long poblacion_objetivo){
        long long poblacion_futura;
        int numero_anios;
        
        poblacion_futura = Poblacion_inicial;
        numero_anios = 0;
        
        while (poblacion_futura < poblacion_objetivo){
            poblacion_futura += (poblacion_futura/1000) * tasa_crecimiento;
            numero_anios++;
        }
        
        return numero_anios;
    }
    
};


int main() {
    const string
    MSJ_POBLACION = "Introduce poblacion actual\n" ,
    MSJ_T_NATALIDAD = " Introduce tasa de natalidad\n",
    MSJ_T_MORTALIDAD = " Introduce tasa de mortalidad\n ",
    MSJ_T_MIGRACION = " Introduce tasa de migracion\n ";
    long long poblacion_actual,poblacion_futura, doble_poblacion;
    double tasa_natalidad, tasa_mortalidad, tasa_migracion;
    int anios;
    
    poblacion_actual = LeeLongLongMayorQue(0, MSJ_POBLACION);
    tasa_migracion = LeeDoubleEnrango(0, 1000, MSJ_T_MIGRACION);
    tasa_mortalidad = LeeDoubleEnrango(0,1000, MSJ_T_MORTALIDAD);
    tasa_natalidad = LeeDoubleEnrango(0, 1000, MSJ_T_NATALIDAD);
    
    doble_poblacion = poblacion_actual * 2 ;
    
    CalculaPoblacion España (poblacion_actual, tasa_natalidad, tasa_mortalidad, tasa_migracion);
    
    poblacion_futura = España.Poblacion_Futura (3);
    anios = España.NumeroAniosHastaObtener(doble_poblacion);
    
    
    cout << " Estimacion de la población futura " << poblacion_futura <<endl;
    cout << " Estimacion de años necesarios para doblar la poblacion " <<anios <<endl;

    poblacion_futura = España.Poblacion_Futura (anios);
    cout << " Estimacion de la población futura despues de  "<< anios << " años : " << poblacion_futura <<endl;
    
    
    return 0;
}
