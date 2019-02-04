//
//  main.cpp
//  examen otro grupo
//
//  Created by antonio garcia on 15/11/16.
//  Copyright © 2016 antonio garcia. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {
    const int FIN = 0 ;
    int origen, destino, minutos, segundos, ciudad_origen_maxima, ciudad_destino_maxima, maxima_minutos=0,
    maxima_segundos = 0, total_segundos = 0;
    double contador_casos = 0, contador_cortas = 0, contador_medias = 0, contador_largas = 0 , contador_muy_largas = 0, porcentaje_cortas = 0, porcentaje_medias = 0, porcentaje_largas = 0, porcentaje_muy_largas = 0;
    
    do {
        cout << " Origen : " <<endl ;
        cin >> origen;
    }while ( (origen <100 || origen > 999) && origen != FIN ) ;
    
    while ( origen != FIN) {
    
    contador_casos++;
    
        do {
            cout << " Destino : " <<endl;
            cin >> destino;
        }while ( destino <100 || destino >999) ;
    
    
        do {
            cout << " minutos : " <<endl;
            cin >> minutos;
        }while ( minutos <0 || minutos > 60);
            
        do {
            cout << " segundos "  << endl;
            cin >> segundos;
        }while ( segundos < 0 || minutos > 59 ) ;
        
        total_segundos = minutos * 60 + segundos;
        
        if (minutos >= maxima_minutos){
            
            if ( segundos > maxima_segundos){
                
                ciudad_origen_maxima = origen;
                ciudad_destino_maxima = destino;
            
            }
            
        }
        
        if (total_segundos <=30){
            
            contador_cortas++;
        }
        else if (total_segundos <= 90){
        
            contador_medias++;
        }
        else if ( total_segundos <= 120){
        
            contador_largas++;
        }
        else {
        
            contador_muy_largas++;
        }
        do {
            cout << " Origen : " <<endl ;
            cin >> origen;
        }while ( (origen <100 || origen > 999) && origen != FIN ) ;
    }
        
    
    
    porcentaje_cortas = (contador_cortas * 100 ) / contador_casos;
    
    porcentaje_medias = (contador_medias * 100 ) / contador_casos;
    
    porcentaje_largas = (contador_largas * 100 ) / contador_casos;
    
    porcentaje_muy_largas = ( contador_muy_largas * 100) / contador_casos;
    
    cout << " origen de la llamada mas larga : " <<ciudad_origen_maxima <<endl;
    cout << " destino de la llamada mas larga : " <<ciudad_destino_maxima <<endl;
    cout << " porcentaje cortas : " <<porcentaje_cortas <<endl;
    cout << " porcentaje medias : " <<porcentaje_medias <<endl;
    cout << " porcentaje largas : " <<porcentaje_largas <<endl;
    cout << " porcentaje muy largas : " <<porcentaje_muy_largas <<endl;
    
    return 0;
}
