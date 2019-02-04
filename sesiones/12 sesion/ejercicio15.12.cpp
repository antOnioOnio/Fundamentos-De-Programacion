//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de ProgramaciÛn
// ETS Inform·tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la ComputaciÛn e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Parking con clases
/*
 Ejemplo de entrada:
 
 30 90 120 660 0.0412 0.0370 0.0311 0.0305 31.55
 35 85 110 660 0.0402 0.0375 0.0319 0.0315 32
 2 1 30 4 2 50
 2 1 30 3 41 31
 2 1 30 5 41 31
 2 1 30 23 1 1 -1
 
 -- Salida correcta:
 
 4.4195 4.4262
 3.767 3.7605
 7.439 7.5445
 31.55 32
 47.1755
 47.731
 */

#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;


struct InstanteTiempo{
    int hora;
    int minuto;
    int segundo;
};

int MinutosEntreInstantes (InstanteTiempo inicial, InstanteTiempo final){
    const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;
    int segundos_iniciales, segundos_finales, segundos_diferencia;
    
    segundos_iniciales = SEGUNDOS_POR_MINUTO * (inicial.hora * MINUTOS_POR_HORA   +
                                                inicial.minuto) +
    inicial.segundo;
    
    segundos_finales   = SEGUNDOS_POR_MINUTO * (final.hora * MINUTOS_POR_HORA   +
                                                final.minuto) +
    final.segundo;
    
    segundos_diferencia = abs(segundos_finales - segundos_iniciales);
    
    return segundos_diferencia / SEGUNDOS_POR_MINUTO;
}

// Prec:
// lÌmites positivos y en orden de menor a mayor
// tarifas todas reales positivos
// minutos_estacionamiento positivo
/*
 Nota:
 Otra posibilidad pasarÌa por comprobar las precondiciones dentro de la funciÛn
 y si no se satisfacen, devolverÌamos -1
 */

class Parking{
private:
    static const int CAPACIDAD=1000;
    double vector_tramo[CAPACIDAD];
    double vector_tarifa[CAPACIDAD];
    int total_utilizados;
    
    
    
public:
    Parking(){
        for (int i=0;i<CAPACIDAD;i++){
            vector_tramo[i]=0;
            vector_tarifa[i]=0;
        }
        total_utilizados=0;
        
    }
    Parking(double tramo, double tarifa, int utilizados){
        vector_tramo[utilizados]=tramo;
        vector_tramo[utilizados]=tarifa;
        total_utilizados=utilizados;
        
    }
    
    void AniadeTramo(double limite_superior_tramo,double tarifa_tramo){
        vector_tramo[total_utilizados]=limite_superior_tramo;
        vector_tarifa[total_utilizados]=tarifa_tramo;
        total_utilizados++;
    }
    double getTarifa(int minutos){
        double tarifa;
        for (int i=0;i<total_utilizados && total_utilizados < CAPACIDAD;i++){
            if(minutos<vector_tramo[i]){
                tarifa=vector_tarifa[i];
            }
        }
        return tarifa;
    }
    double LeePositivo(string msj){
        double numero;
        cout << msj;
        cin >> numero;
        while (numero<0 && numero!=-1){
            cin >> numero;
        }
        
        return numero;
    }
};


int main(){
    
        Parking parking1, parking2;
        InstanteTiempo tiempo_inicial;
        InstanteTiempo tiempo_final;
        const int TERMINADOR=-1;
        const string msg_tarifa="\nIntroduzca la tarifa para el limite introducido  : \t";
        const string msg_limite="\nIntroduzca el limite superior; \t";
        double limite, tarifa, apagar;
        int segundos, minutos,horas,minutos_f,segundos_f,horas_f;
        int parking,minutos_totales;
        
        limite=parking1.LeePositivo(msg_limite);
        tarifa=parking1.LeePositivo(msg_tarifa);
        
        int i=0;
        while (tarifa!=TERMINADOR && limite!=TERMINADOR){
            parking1.AniadeTramo(limite,tarifa);
            
            limite=parking1.LeePositivo(msg_limite);
            tarifa=parking1.LeePositivo(msg_tarifa);
            i++;
        }
        
        limite=parking2.LeePositivo(msg_limite);
        tarifa=parking2.LeePositivo(msg_tarifa);
        
        int j=0;
        while (tarifa!=TERMINADOR && limite!=TERMINADOR){
            parking2.AniadeTramo(limite,tarifa);
            
            limite=parking2.LeePositivo(msg_limite);
            tarifa=parking2.LeePositivo(msg_tarifa);
            j++;
        }
        if (j==0 && i==0){
            cout << "\nNo ha introducido suficientes datos " << endl;
        }
    
        else{
            
            
            cout << "\nIntroduzca el parking donde ha estado estacionado el vehiculo ( 1 o 2): \t";
            cin >> parking;
            cout << "\nIntroduce cuando entro  el vehiculo ( Horas, Minutos,Segundos): \t";
            cin >> horas >> minutos >> segundos;
            
            tiempo_inicial.hora=horas;
            tiempo_inicial.minuto=minutos;
            tiempo_inicial.segundo=segundos;
            
            cout << "\nIntroduce cuando salio el vehiculo (Horas, Minutos, Segundos); \t";
            cin >> horas_f >> minutos_f >> segundos_f;
            
            tiempo_final.hora=horas_f;
            tiempo_final.minuto=minutos_f;
            tiempo_final.segundo=segundos_f;
            
            minutos_totales=MinutosEntreInstantes(tiempo_inicial, tiempo_final);
            
            if(parking==1){
                tarifa=parking1.getTarifa(minutos_totales);
            }
            else{
                tarifa=parking2.getTarifa(minutos_totales);
            }
            
            apagar=tarifa*minutos_totales;
            
            cout << "\nTotal a pagar: \t" << apagar;
        }
    
            return 0;
}
