// Ejercicio 8 de la sesion 8. Antonio Garcia Castillo




#include <iostream>
#include <cmath>

using namespace std;

// funcion potencia
double potencia(double base,int exp){
    double valor;
    valor=pow(base,exp);
    return valor;
}

// funcion gausiana
double Gaussiana(double esperanza_media, double desviacion_tipica, double variable){
    
    const int PI = 3.1415;
    double g_1, g_2, valor;
    
    g_1 = (1/(desviacion_tipica*sqrt(PI*2))); // primera parte de la funcion
    
    g_2 = exp( -0.5 * pow( (variable - esperanza_media)/desviacion_tipica,  2) ); // incluimos variables a la funcion
    
    valor = g_1 * g_2 ;
    
    return valor ;
}

// funcion cdf para calcular el area
double Cdf(double var, double gaussina){
    
    const double b0=0.2316419,b1=0.319381530,b2=-0.356563782,b3=1.781477937,b4=-1.821255978,b5=1.330274429;
    double valor,t;
    
    t=1/(1+b0*var);
    
    valor=1-gaussina*(b1*t+b2*potencia(t,2)+b3*potencia(t,3)+b4*potencia(t,4)+b5*potencia(t,5));
    
    return valor;
}
//Funcion main

int main (){
    
    // declaracion de variables
    double desviacion_tipica,esperanza_media,gaussina,maximo,minimo,incremento,valor_C;
    
    // entrada de datos
    do{
        cout<< "Introduzca el valor de la desviacion tipica ";
        cin>>desviacion_tipica;
    }while(desviacion_tipica<=0);
    
    cout<< "Introduzca el valor de la media ";
    cin>>esperanza_media;
    
    cout<< "Introduzca el minimo ";
    cin>>minimo;
    
    cout<<"Introduzca el maximo ";
    cin>>maximo;
    
    while(maximo<minimo){
        
        cout<<"Introduzca el maximo ";
        cin>>maximo;
    }
    
    cout<<"Introduzca un incremento ";
    cin>>incremento;
    
    //Calculos
    for (double i=minimo;i<=maximo;i*=incremento){
        
        gaussina=Gaussiana(esperanza_media, desviacion_tipica, i);
        
        valor_C=Cdf(i, gaussina);
        //muestra valores
        cout<< "El valor de la gaussina es: "<<gaussina ;
        cout<< "El valor de la cdf es: "<<valor_C;
    }
    return 0;
}
