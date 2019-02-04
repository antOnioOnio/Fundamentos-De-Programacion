/*
 Facturacion SIMPLIFICADA de telefono
 a tres empresas U R T
 de acuerdo con rangos precios 60 900 3600 y tarifas;
 TARIFA1 = 0.025 0.025;
 TARIFA2 = 0.01;
 TARIFA3 = 0.007;
 TARIFA4 = 0.001;
 
 Esto es un simplificaciÛn, en realidad la facturaciÛn se hace por tramos
 Se pide :
 cu·nto se ha facturado en total en la central
 cantidad total m·xima facturada a una empresa
 cu·ntas llamadas se han realizado pertenecientes al ˙ltimo tramo de llamada ({\it muy largas})
 */

#include <iostream>

using namespace std;

const char FIN = 'Q';
const char EMPRESA1 = 'V';
const char EMPRESA2 = 'R';
const char EMPRESA3 = 'U';

const int TIEMPO_R1 = 60;
const int TIEMPO_R2 = 900;
const int TIEMPO_R3 = 3600;

const float TARIFA1 = 0.025;
const float TARIFA2 = 0.01;
const float TARIFA3 = 0.007;
const float TARIFA4 = 0.001;

const float TARIFA_STABLECIMIENTO = 0.30;
const int MIN2SEG = 60;

// filtro para leer numeros >= 0
int leePositivo(string msg){
    int dato;
    do {
        cout << msg;
        cin >> dato;
    }
    while(dato < 0 );
    
    return dato;
}

// filtro para leer  cotaInf <= valor <= cotaSup
int leeRangoCerrado(string msg, int cotaInf, int cotaSup){
    int dato;
    do {
        cout << msg;
        cin >> dato;
    }
    while(dato < cotaInf || dato > cotaSup);
    
    return dato;
}

char leeEmpresa(string msg){
    char empresa, ch;
    do {
        cout << msg;
        cin >> ch;
        empresa = toupper(ch);
    }
    while(empresa != EMPRESA1 && empresa != EMPRESA2 && empresa != EMPRESA3 && empresa != FIN);
    return empresa;
    
}

// calculo de factura, una simplificacion
float factura(int segundosTotal){
    
    float total, tarifa;
    
    if (segundosTotal < TIEMPO_R1 )
        tarifa  = TARIFA1;
    else if (segundosTotal < TIEMPO_R2)
        tarifa  = TARIFA2;
    else if (segundosTotal < TIEMPO_R3)
        tarifa  = TARIFA3;
    else tarifa = TARIFA4;
    
    total = tarifa * segundosTotal +  TARIFA_STABLECIMIENTO;
    
    return total;
}

bool llamadaLarga(int segundosTotal){
    return segundosTotal>= TIEMPO_R3;
}


float calculaMax(float v1, float v2){
    float maximo = v1;
    if (v2 > v1)
        maximo = v2;
    return maximo;
}

int main() {
    const string MSGEMPRESA = "Introduce empresa V,T, U (Q para salir) :";
    const string MSGMIN = "Introduce numero de minutos: ";
    const string MSGSEG = "Introduce numero de segundos [0..59]:  ";
    const string SALIDATOTAL = "\nLa facturacion total es : ";
    const string SALIDAMAXIMOTOTAL = "\nEl maximo total facturado es: ";
    const string SALIDALARGAS = "\nN˙mero de llamadas muy largas: ";
    const string NODATOS = "No se ha introducido ningun dato.";
    
    //DeclaraciÛn de variables
    char empresa;
    int minutos, segundos, segundosTotal, contadorLarga = 0;
    float  facturacionTotal, facturacionMax;
    
    float facturaEmpresa1, facturaEmpresa2, facturaEmpresa3;
    
    // //Lectura adelantada y filtro de empresa
    
    facturacionMax=-1;
    facturaEmpresa1 = facturaEmpresa2 = facturaEmpresa3 = 0;
    
    empresa = leeEmpresa(MSGEMPRESA);
    
    while(empresa != FIN) { 		//Bucle para controlar fin de entrada de datos
        
        minutos = leePositivo(MSGMIN);
        segundos = leeRangoCerrado(MSGSEG,0,MIN2SEG-1);
        segundosTotal = minutos*MIN2SEG + segundos;
        
        if (llamadaLarga(segundosTotal))
            contadorLarga++;
        
        if (empresa == EMPRESA1)
            facturaEmpresa1 += factura(segundosTotal);
        else if (empresa == EMPRESA2)
            facturaEmpresa2 += factura(segundosTotal);
        else facturaEmpresa3 += factura(segundosTotal);
        
        empresa = leeEmpresa(MSGEMPRESA);
        
    } // fin while
    
    facturacionTotal = facturaEmpresa1 + facturaEmpresa2 + facturaEmpresa3;
    
    if (facturacionTotal > 0){
        facturacionMax = calculaMax(facturaEmpresa1, facturaEmpresa2);
        facturacionMax = calculaMax(facturacionMax, facturaEmpresa3);
        
        cout <<  SALIDATOTAL << facturacionTotal << endl;
        cout <<  SALIDAMAXIMOTOTAL << facturacionMax << endl;
        cout <<  SALIDALARGAS  <<  contadorLarga << endl;
        
    }
    else
        cout << NODATOS << endl;
    
}
