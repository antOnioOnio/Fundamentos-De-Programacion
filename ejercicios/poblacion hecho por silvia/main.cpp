//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de ProgramaciÛn
// ETS Inform·tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la ComputaciÛn e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////


// PoblaciÛn (con clases)

/*
 Los estudios poblacionales utilizan los conceptos de tasa de natalidad,
 mortalidad, etc.
 Al igual que un porcentaje representa una razÛn del total por cada cien
 (tanto por ciento), la tasa es una razÛn del total por cada mil
 (tanto por mil).
 AsÌ pues una tasa de natalidad de 32, por ejemplo, significa que hay
 32 nacimientos por cada 1000 habitantes.
 
 Escriba un programa que calcule la estimaciÛn de la poblaciÛn de un
 territorio despuÈs de tres aÒos. Para ello, el programa debe leer
 la poblaciÛn inicial, la tasa de natalidad, la de mortalidad y
 la tasa de migraciÛn. …sta ˙ltima es la diferencia entre los que se
 van y los que vienen, por lo que puede ser o bien positiva o bien negativa.
 
 Suponga que todos los datos son enteros.
 
 Tenga en cuenta que una vez calculada la poblaciÛn que habr· el
 siguiente aÒo, las tasas se vuelven a aplicar sobre la poblaciÛn
 asÌ obtenida, y asÌ sucesivamente, tantos aÒos como estemos interesados.
 */

/*
 Amplie el ejercicio 12 (PoblaciÛn) de la relaciÛn de problemas I.
 Esta nueva versiÛn del programa, adem·s de los datos ya pedidos
 en dicho ejercicio, se le pedir· al usuario que introduzca un n˙mero
 de aÒos (ser· el ˙ltimo dato leÌdo)
 
 Debe leer cada dato con un filtro conveniente.
 Por ejemplo, las tasas de natalidad, mortalidad y emigraciÛn deben ser
 enteros entre 0 y 1000, mientras que la poblaciÛn
 inicial debe ser un entero positivo.
 
 El programa debe calcular el n˙mero total de habitantes transcurridos
 dichos aÒos.
 
 Adem·s, el programa tambiÈn calcular· el n˙mero de aÒos que tienen que
 pasar hasta que haya, como mÌnimo, el doble de la poblaciÛn inicial.
 
 Ejemplo de entrada: 1375570814 32 12 7 3 --
 Salida correcta: 1490027497  27  2824131580
 */

/*
 Retome la soluciÛn del ejercicio 23 (poblaciÛn) de la RelaciÛn de Problemas II. Re-
 escrÌbalo usando las funciones LeeEnteroRango del ejercicio 4 para leer los valores
 de las tasas y LeeEnteroMayorIgualQue del ejercicio 5 para leer el n˙mero de
 aÒos. Defina tambiÈn sendas funciones para calcular los dos valores que se piden en
 el ejercicio, a saber, el n˙mero de habitantes despuÈs de tres aÒos y el n˙mero de
 aÒos que pasar·n hasta doblar la poblaciÛn inicial. Intente diseÒar las funciones para
 que sean lo m·s generales posible.
 Ejemplo de entrada:
 1375570814 2000 32 2000 2000 12 7 -4 -4 3
 -- Salida correcta: 1490027497 27 2824131580
 */

#include <cmath>
#include <iostream>
using namespace std;

int LeeIntRango(int min, int max, string mensaje){
    int a_leer;
    
    do{
        cout << mensaje;
        cin >> a_leer;
    }while (min > a_leer || max < a_leer);
    
    return a_leer;
}

// Con templates no ser· necesario definir LeeLongLong, LeeInt, etc
// ya que se repite el mismo cÛdigo en todas ellas.

long long LeeLongLongMayorIgualQue(long long minimo, string mensaje){
    long long a_leer;
    
    do{
        cout << mensaje;
        cin >> a_leer;
    }while (minimo > a_leer);
    
    return a_leer;
}

int LeeIntMayorIgualQue(int minimo, string mensaje){
    int a_leer;
    
    do{
        cout << mensaje;
        cin >> a_leer;
    }while (minimo > a_leer);
    
    return a_leer;
}


class CalculadoraPoblacional{
private:
    long long poblacion_inicial = 0;
    double iv_tasa_global = NAN;
    
    double IV_Tasa(int tasa){
        return 1 + tasa / 1000.0;
    }
    
    bool EsCorrectaPoblacion(long long poblacion){
        return poblacion >= 0;
    }
    
    bool EsCorrectaTasa(int tasa_por_mil){
        return (0 <= tasa_por_mil && tasa_por_mil <= 1000.0);
    }
public:
    CalculadoraPoblacional(long long poblacion_de_partida,
                           int tasa_natalidad, int tasa_mortalidad, int tasa_migracion){
        if (EsCorrectaPoblacion(poblacion_de_partida) &&
            EsCorrectaTasa(tasa_natalidad) &&
            EsCorrectaTasa(tasa_mortalidad) &&
            (EsCorrectaTasa(tasa_migracion) || EsCorrectaTasa(-tasa_migracion))){
            
            poblacion_inicial = poblacion_de_partida;
            iv_tasa_global = IV_Tasa(tasa_natalidad - tasa_mortalidad + tasa_migracion);
        }
    }
    
    long long EstimacionDespuesDe (int numero_anios){
        long long poblacion_futura;
        
        poblacion_futura = poblacion_inicial;
        
        for (int anio = 1; anio <= numero_anios; anio++)
            poblacion_futura = poblacion_futura * iv_tasa_global;
        
        return poblacion_futura;
    }
    
    int NumeroAniosHastaObtener(long long poblacion_objetivo){
        long long poblacion_futura;
        int numero_anios;
        
        poblacion_futura = poblacion_inicial;
        numero_anios = 0;
        
        while (poblacion_futura < poblacion_objetivo){
            poblacion_futura = poblacion_futura * iv_tasa_global;
            numero_anios++;
        }
        
        return numero_anios;
    }
};


// -----------------------------------------------------------------------
int main(){
    const string
    MSJ_INICIO           = "C·lculo de la poblaciÛn futura.\n",
    MSJ_POBLACION_ACTUAL = "\nIntroduzca la poblaciÛn actual: ",
    MSJ_TASA_NATALIDAD   = "\nIntroduzca la tasa de natalidad: ",
    MSJ_TASA_MORTALIDAD  = "\nIntroduzca la tasa de mortalidad: ",
    MSJ_TASA_MIGRACION   = "\nIntroduzca la tasa de migraciÛn: ",
    MSJ_NUMERO_ANIOS     = "\nIntroduzca el n˙mero de aÒos: ";
    const int LIMITE_SUPERIOR_TASA = 1000;
    long long poblacion_actual, poblacion_futura;
    int tasa_natalidad, tasa_mortalidad, tasa_migracion,
    numero_anios;
    long long poblacion_objetivo;
    
    cout << MSJ_INICIO;
    
    poblacion_actual = LeeLongLongMayorIgualQue(0, MSJ_POBLACION_ACTUAL);
    tasa_natalidad   = LeeIntRango(0, LIMITE_SUPERIOR_TASA, MSJ_TASA_NATALIDAD);
    tasa_mortalidad  = LeeIntRango(0, LIMITE_SUPERIOR_TASA, MSJ_TASA_MORTALIDAD);
    tasa_migracion   = LeeIntRango(-LIMITE_SUPERIOR_TASA, LIMITE_SUPERIOR_TASA, MSJ_TASA_MIGRACION);
    numero_anios     = LeeIntMayorIgualQue(0, MSJ_NUMERO_ANIOS);
    
    CalculadoraPoblacional poblacion(poblacion_actual, tasa_natalidad,
                                     tasa_mortalidad, tasa_migracion);
    
    poblacion_futura = poblacion.EstimacionDespuesDe(2);
    
    cout << "\n\nPoblaciÛn futura pasados " << numero_anios << " aÒos: "
    << poblacion_futura;
    
    poblacion_objetivo = 2 * poblacion_actual;
    numero_anios       = poblacion.NumeroAniosHastaObtener(poblacion_objetivo);
    poblacion_futura   = poblacion.EstimacionDespuesDe(numero_anios);
    
    cout << "\n\nPasar·n " << numero_anios << " aÒos hasta llegar,"
    << "como mÌnimo, al doble de la poblaciÛn actual"
    << "\nLa poblaciÛn a la que se llegar· es: "
    << poblacion_futura << " habitantes";
}
