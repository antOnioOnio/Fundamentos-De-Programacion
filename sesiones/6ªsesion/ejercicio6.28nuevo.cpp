// problema 28 de la relacion de ejercicios sesion 6


#include <iostream>

using namespace std;


int main (){
    const int FIN = -1;
    double sueldo,media1=0,media2=0,media3=0, mejor_media=0;
    int cod_empleado, segundos, solucion, valoracion, acumulado_1=0, acumulado_2=0, acumulado_3=0,contador_casos=0,contador_1=0,contador_2=0, contador_3=0, mejor_empleado=0;
 
    
    do {
        cout << " introduce el salario\n " ;
        cin >> sueldo;
    }while(sueldo<0);
    
    do {
        
        cout << " Introduce el codigo del empleado\n " ;
        cin >> cod_empleado;
        
    }while((cod_empleado<1 || cod_empleado >3) && cod_empleado != FIN);
    
    while ( cod_empleado != FIN) {
        
        contador_casos++;
        
        do {
            
            cout << " segundos \n" ;
            cin >> segundos;
            
        }while(segundos<0);
        
        do {
            
            cout << " solucionado---1, no solucionado----0 \n";
            cin >>solucion;
        }while ( solucion <0 || solucion >1) ;
        
        do {
            
            cout << " valoracion del 1 al 5\n";
            cin>> valoracion;
        }while (valoracion <0 || valoracion>5);
        
        if ( cod_empleado == 1){
            
            contador_1++;
            acumulado_1 += valoracion;
            
        }
        else if ( cod_empleado == 2){
        
            contador_2++;
            acumulado_2 += valoracion;
        }
        else {
            
            contador_3++;
            acumulado_3 += valoracion;
        }
        
        do {
            
            cout << " Introduce el codigo del empleado\n " ;
            cin >> cod_empleado;
            
        }while((cod_empleado<1 || cod_empleado >3) && cod_empleado != FIN);
        }
    media1 = acumulado_1*1.0/contador_1;
    media2 = acumulado_2*1.0/contador_2;
    media3 = acumulado_3*1.0/contador_3;
    
    
    if (media1 > mejor_media) {
        
        mejor_media = media1;
        mejor_empleado = 1;
        
    }
    else if ( media2 > mejor_media ){
    
        mejor_media = media2;
        mejor_empleado = 2;
    }
        
    if ( media3 > mejor_media){
    
        mejor_media = media3;
        mejor_empleado = 3;
    
    }
    
    cout << " Sobre un total de " <<contador_casos <<" casos, el mejor empleado fue el " << mejor_empleado << " con una media de " <<mejor_media <<endl;
    return 0;
    
    
}
    
    
    
    

