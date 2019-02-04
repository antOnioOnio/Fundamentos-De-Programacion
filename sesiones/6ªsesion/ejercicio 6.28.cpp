/*Se quiere construir un programa para leer los datos necesarios del ejercicio 11 de la subida salarial.
 Supondremos que sólo hay tres empleados y que están identificados con un código (1, 2 y 3). Además, el salario por hora es el mismo para todos los empleados. Éste será el primer valor que se leerá (de tipo double) Después de haber leído este dato, se leerán los datos de los casos atendidos por los empleados en el siguiente orden: en primer lugar, el código del empleado, a continuación el número de segundos que ha durado la atención telefónica, en tercer lugar un 1 si el caso se resolvió de forma satisfactoria y un 0 en caso contrario; finalmente, un valor entero entre 0 y 5 con el grado de satisfacción del usuario.
 Cuando nos encontremos el terminador como primer dato (código del empleado) se detendrá la introducción de datos. Supondremos que siempre se introduce al menos el primer valor (el salario), pudiendo ser ya el siguiente dato leído el terminador.
 El programa debe imprimir el número total de casos introducidos (3 en el ejemplo anterior) y el código del empleado con mayor grado de satisfacción medio (también imprimirá dicho grado medio.        .*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    //declaracion de variables y constantes
    const int TERMINADOR = -1;
    const int EMPLEADO_1=1, EMPLEADO_2=2, EMPLEADO_3=3;
    
    double salario_por_hora, media_grado_satisfaccion_1, media_grado_satisfaccion_2 , media_grado_satisfaccion_3;
    int codigo_empleado , segundos_llamada , resolucion , grado_satisfaccion , contador_casos_totales=0 ,contador_casos_1=0,contador_casos_2=0, contador_casos_3=0,suma_grado_1=0 , suma_grado_2=0 , suma_grado_3=0;
    
    
    
    //introduccion de datos
    do{
    
    cout << "Introduzca el salario por hora de los trabajadores:" <<endl;
    cin >>salario_por_hora;
        
    }while(salario_por_hora<0);
    
    cout << "\nIntroduzca la informacion pertinente, para terminar con el proceso"
         << " introduzca como codigo de empleado -1." <<endl;
    
  
    
        cout << "Codigo de empleado :" <<endl;
        cin >> codigo_empleado;
    
        while (codigo_empleado != TERMINADOR){
            
            do{
            cout << "Numero de segundos de la llamada telefonica:"<<endl;
            cin >> segundos_llamada;
            }while(segundos_llamada<0); // Debe ser un dato positivo
            
            do{
                cout << "¿La incidencia fue resuelta ? 1 para si, 0 para no "<<endl;
                cin >> resolucion;
            }while(resolucion<0 || resolucion>1); // debe ser o un 0 o u 1
        
            if ( codigo_empleado==EMPLEADO_1){
                
                do{
                cout << " Grado de satisfaccion del 0 a 5: " <<endl;
                cin >>grado_satisfaccion;
                }while(grado_satisfaccion<0 || grado_satisfaccion>5); // del 0 al 5 obligatoriamente
                
                // acumulaos grado y casos
                suma_grado_1 += grado_satisfaccion;
                contador_casos_1++;
            }
        
            if ( codigo_empleado==EMPLEADO_2){
            
                cout << " Grado de satisfaccion " <<endl;
                cin >>grado_satisfaccion;
            
                suma_grado_2 += grado_satisfaccion;
                contador_casos_2++;
            }
            
            if ( codigo_empleado==EMPLEADO_3){
            
                cout << " Grado de satisfaccion " <<endl;
                cin >>grado_satisfaccion;
            
                suma_grado_3 += grado_satisfaccion;
                contador_casos_3++;
            }
            // suma de los casos totales
            contador_casos_totales = contador_casos_3+contador_casos_2+contador_casos_1;
            
            cout << "codigo de empleado " <<endl;
            cin >> codigo_empleado;
        }
    
    // calculamos respectivas medias
    if (contador_casos_1 >=1){
        media_grado_satisfaccion_1 = suma_grado_1*1.0/contador_casos_1;
    }
    if (contador_casos_2>=1){
    media_grado_satisfaccion_2 = suma_grado_2*1.0/contador_casos_2;
    }
    if (contador_casos_3>=1){
    media_grado_satisfaccion_3 = suma_grado_3*1.0/contador_casos_3;
    }
    
    
    
    cout << " Sobre " << contador_casos_totales << " casos totales,";
    // calculamos maxima de las 3 medias
    if ( media_grado_satisfaccion_1 > media_grado_satisfaccion_2){
        
        if ( media_grado_satisfaccion_1 > media_grado_satisfaccion_3){
        
            cout << " el empleado con mayor grado de satisfaccion fue el numero: " << EMPLEADO_1 << " con un grado medio de satisfaccion de " <<media_grado_satisfaccion_1 <<endl;
        }
        else {
            
            cout << " el empleado con mayor grado de satisfaccion fue el numero" << EMPLEADO_3 << " con un grado medio de satisfaccion de " <<media_grado_satisfaccion_3 <<endl;
        }
    }
    
    if ( media_grado_satisfaccion_2 > media_grado_satisfaccion_1){
        
        if (media_grado_satisfaccion_2 > media_grado_satisfaccion_3){
            
            cout << " el empleado con mayor grado de satisfaccion fue el  " << EMPLEADO_2 << " con un grado medio de satisfaccion de " <<media_grado_satisfaccion_2 <<endl;
        
        }
        
    }
    
}

