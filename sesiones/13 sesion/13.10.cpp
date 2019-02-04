/* 10. [Parking con la clase Instante]. Recupere la solución del ejercicio 46 de la relación de problemas III (Parking con clases y struct)
 Reescríbalo para que los instantes sean objetos de la clase Instante. Por lo tanto, tiene que eliminar la función que calculaba los minutos entre dos instantes y hacerlo dentro de la clase Instante.
 Finalidad: Métodos que reciben como parámetro un objeto de la misma clase. Dificultad Baja.
 
 46. Recupere la solución del ejercicio 29 (Parking con una clase) Defina un struct llamado InstanteTiempo para almacenar la hora, minutos y segundos que constituyen un instante de tiempo. Cambie la definición de la función MinutosEntreInstantes y el programa principal para que trabaje con este tipo struct.
 Finalidad: Trabajar con funciones y el tipo struct. Dificultad Baja.
 
 29. Recupere la solución del ejercicio 9 de esta relación de problemas (parking con funciones). Reescríbalo para que los cómputos relacionados con el cálculo de la tarifa, estén encapsulados en una clase. Mantenga la definición de la función MinutosEntreInstantes tal y como está. Modifique apropiadamente el programa principal.
 Finalidad: Diseño de una clase. Dificultad Media.
 
 9. Retome la solución del ejercicio 10 (parking) de la Relación de Problemas II. Se quiere extender para poder trabajar con varios parkings o con varias tarifas distintas. Supon- dremos que en todos los casos, se tiene el mismo número de tramos (4) aunque puede variar la cuantía a tarifar por minutos y los límites de cada uno de los tramos.
 Para ello, se pide definir la función Tarifa que obtenga la tarifa final aplicable a cualquier caso. En concreto, en este ejercicio, se van a leer sólo dos casos, corres- pondientes a dos parkings o tarificaciones distintas. Se pide por tanto construir un programa que lea los siguientes datos:
 • En primer lugar el programa lee los datos de cada uno de los dos casos, es decir, los límites de los tramos y las tarifas que se aplican en cada tramo (ver tabla debajo)
 • A continuación, se leen varios pares de instantes de entrada y salida. Se leen en el orden instante de entrada (hora, minuto y segundo) e instante de salida.
 La entrada de datos finaliza cuando se introduce un -1 como hora de entrada.
 El programa imprimirá la tarifa resultante de cada uno de los parkings para cada par de instantes de entrada y salida, así como la suma total recaudada en cada caso.
 Por ejemplo:
 30     -> Limite 1 del parking 1
 90     -> Limite 2 del parking 1
 120    -> Limite 3 del parking 1
 660    -> Limite 4 del parking 1
 0.0412 -> Tarifa Tramo 1 del parking 1
 0.0370 -> Tarifa Tramo 2 del parking 1
 0.0311 -> Tarifa Tramo 3 del parking 1
 0.0305 -> Tarifa Tramo 4 del parking 1
 31.55  -> Tarifa día completo del parking 1
 35     -> Limite 1 del parking 2
 Guión de Prácticas. Fundamentos de Programación
 RP-III.4
 RELACIÓN DE PROBLEMAS III. Funciones y Clases
 85     -> Limite 2 del parking 2
 110    -> Limite 3 del parking 2
 660    -> Limite 4 del parking 2
 0.0402 -> Tarifa Tramo 1 del parking 2
 0.0375 -> Tarifa Tramo 2 del parking 2
 0.0319 -> Tarifa Tramo 3 del parking 2
 0.0315 -> Tarifa Tramo 4 del parking 2
 32     -> Tarifa día completo del parking 2
 2 1 30 -> Entra a las 2 de la madrugada, 1 minuto, 30 segundos
 4 2 50 -> Sale a las 4 de la madrugada, 2 minutos y 50 segundos
 2 2 5  -> Entra a las 2 de la madrugada, 2 minutos, 5 segundos
 4 3 7  -> Sale a las 4 de la madrugada, 3 minutos, 7 segundos
 -1     -> Fin de la entrada de datos.
 Ejemplo de entrada:
 30 90 120 660 0.0412 0.0370 0.0311 0.0305 31.55
 35 85 110 660 0.0402 0.0375 0.0319 0.0315 32
 2 1 30 4 2 50
 2 1 30 3 41 31
 2 1 30 5 41 31
 2 1 30 23 1 1   -1
 −− Salida correcta:
 4.4195 4.4262
 3.767 3.7605
 7.439 7.5445
 31.55 32
 47.1755
 47.731
 Finalidad: Diseño de una función. Dificultad Media.
 
 10. La tabla para el cálculo del precio a pagar en los parkings de Madrid para el 2015 es
 la siguiente:
 Si permanece más de 660 minutos se paga una única tarifa de 31.55 euros Desde el minuto 0 al 30: 0.0412 euros cada minuto
 Desde el minuto 31 al 90: 0.0370 euros cada minuto
 Desde el minuto 91 al 120: 0.0311 euros cada minuto
 Desde el minuto 121 al 660: 0.0305 euros cada minuto
 Guión de Prácticas. Fundamentos de Programación RP-II.3
 RELACIÓN DE PROBLEMAS II. Estructuras de Control
 Dado un tiempo de entrada (hora, minuto y segundo) y un tiempo de salida, construya un programa que calcule la tarifa final a cobrar. Para calcular el número de minutos en- tre los dos instantes de tiempo, puede utilizar la solución del ejercicio 6 de la Relación de Problemas I.
 Ejemplo de entrada: 2 1 30 Ejemplo de entrada: 2 1 30 Ejemplo de entrada: 2 1 30 Ejemplo de entrada: 2 1 30 Ejemplo de entrada: 2 1 30 Ejemplo de entrada: 2 1 30 Ejemplo de entrada: 2 1 30
 2 1 29 −− Salida correcta: -1
 2 1 31 −− Salida correcta: 0
 2 2 31 −− Salida correcta: 0.0412 2 41 31 −− Salida correcta: 1.606 3 41 31 −− Salida correcta: 3.767 5 41 31 −− Salida correcta: 7.439 23 1 1 −− Salida correcta: 31.55
 Finalidad: Plantear una estructura condicional anidada. Dificultad Baja.
 
 */

// Ejercicio 10 de la sesion 13
// Antonio Garcia Castillo

#include <iostream>
using namespace std ;


class Instante{
    private :
    static const int PASO = 60 ;
    int horas, minutos, segundos;
public:
    
    Instante(){
        horas=0;
        minutos=0;
        segundos=0;
    }
    Instante(int hor, int min, int seg){
        horas=hor;
        minutos=min;
        segundos=seg;
    }
    void SetMinutos(int min){
        minutos=min;
    }
    void SetHoras(int hora){
        horas=hora;
    }
    void SetSegundos(int seg){
        segundos=seg;
    }
    
    int getHoras (){
        return horas ;
    }
    int getMinutos(){
        return minutos;
    }
    int getSegundos(){
        return segundos;
    }
    int MinutosTotales(){
        int t_segundos, t_minutos;
        t_segundos=(horas*PASO*PASO)+(minutos*PASO)+segundos;
        t_minutos=t_segundos/PASO;
        
        return t_minutos;
    }
    int DiferenciaEntreInstantes(Instante tiempo){
        int diferencia_instantes;
        
        diferencia_instantes=tiempo.MinutosTotales()-MinutosTotales();
        
        return diferencia_instantes;
    }
};

class Parking{
private:
    static const int CAPACIDAD=1000;
    double vector_tramo[CAPACIDAD];
    double vector_tarifa[CAPACIDAD];
    int total_utilizados;
    int tarifa_plana;
    
    
public:
    Parking(){
        for (int i=0;i<CAPACIDAD;i++){
            vector_tramo[i]=0;
            vector_tarifa[i]=0;
        }
        total_utilizados=0;
        tarifa_plana = 0;
    }
    Parking(double tramo, double tarifa,int tarifa_p, int utilizados){
        vector_tramo[utilizados]=tramo;
        vector_tramo[utilizados]=tarifa;
        total_utilizados=utilizados;
        tarifa_plana = tarifa_p;
        
    }
    void AniadeTramo(double limite_superior_tramo,double tarifa_tramo){
        vector_tramo[total_utilizados]=limite_superior_tramo;
        vector_tarifa[total_utilizados]=tarifa_tramo;
        total_utilizados++;
    }
    int getTramoFinal(){
        
        return vector_tramo[total_utilizados-1];
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
    double getTarifaPlana(double tarifa_p){
        return tarifa_p;
    }
    
};
double LeePositivo(string msj){
    double numero;
    cout << msj;
    cin >> numero;
    if (numero>0 && numero!=-1){
        
    }
    return numero;
}
int main(){
    
    Parking parking1, parking2;
    Instante tiempo_inicial;
    Instante  tiempo_final;
    Instante tiempo_total;
    const int TERMINADOR=-1;
    const int DIA = 1440;
    const string msg_tarifa="\nIntroduzca la tarifa para el limite introducido  : \t";
    const string msg_limite="\nIntroduzca el limite superior : \t";
    double limite, tarifa, apagar, tarifa_p1, tarifa_p2;
    int segundos, minutos,horas,minutos_f,segundos_f,horas_f;
    int parking,minutos_totales;
    
    
    cout << "\t\t INTRODUZCA LOS LIMITES DEL PARKING 1 DE FORMA ASCENDENTE ";
    
    limite=LeePositivo(msg_limite);
    
    if(limite != TERMINADOR)
        tarifa=LeePositivo(msg_tarifa);
    
    
    
    while (tarifa!=TERMINADOR && limite!=TERMINADOR){
        
        
        parking1.AniadeTramo(limite,tarifa);
        
        limite=LeePositivo(msg_limite);
        if(limite != TERMINADOR)
            tarifa=LeePositivo(msg_tarifa);
    }
    cout << " Introduce la tarifa plana del parking 1 : \n " ;
    cin >> tarifa_p1;
    
    cout << "\t\t INTRODUZCA LOS LIMITES DEL PARKING 2 DE FORMA ASCENDENTE ";
    
    
    limite=LeePositivo(msg_limite);
    
    if(limite != TERMINADOR)
        tarifa=LeePositivo(msg_tarifa);
    
    
    while (tarifa!=TERMINADOR && limite!=TERMINADOR){
        
        parking2.AniadeTramo(limite,tarifa);
        
        limite=LeePositivo(msg_limite);
        if(limite != TERMINADOR)
            tarifa=LeePositivo(msg_tarifa);
    }
    cout << " Introduce la tarifa plana del parking 2 : \n " ;
    cin >> tarifa_p2;
    
    
    cout << "\nIntroduzca el parking donde ha estado estacionado el vehiculo ( 1 o 2): \t";
    cin >> parking;
    cout << "Introduzca el instante de llegada: \n";
    cout << "Hora: \t";
    cin >> horas ;
    cout << "Minutos: \t ";
    cin >> minutos;
    cout << "Segundos: \t ";
    cin>> segundos;
    
    tiempo_inicial.SetHoras(horas);
    tiempo_inicial.SetMinutos(minutos);
    tiempo_inicial.SetSegundos(segundos);
    
    cout << "Introduzca el instante de salida: \n";
    cout << "Hora: \t";
    cin >> horas_f ;
    cout << "Minutos: \t";
    cin >> minutos_f;
    cout << "Segundos: \t ";
    cin>> segundos_f;
    
    tiempo_final.SetHoras(horas_f);
    tiempo_final.SetMinutos(minutos_f);
    tiempo_final.SetSegundos(segundos_f);
    
    minutos_totales=tiempo_inicial.DiferenciaEntreInstantes(tiempo_final);
    
    
    if(parking==1){
        if(minutos_totales>parking1.getTramoFinal()){
            apagar=parking1.getTarifaPlana(tarifa_p1);
        }
        else{
            apagar = minutos_totales * parking1.getTarifa(minutos_totales);
        }
    }
    
    else{
        if(minutos_totales>parking2.getTramoFinal()){
            apagar=parking2.getTarifaPlana(tarifa_p2);
        }
        else{
            apagar = minutos_totales * parking1.getTarifa(minutos_totales);
        }
    }
    
    
    cout << "\nTotal a pagar: \t" << apagar;
    
    cout << endl;
    
    
    return 0;
    
}
