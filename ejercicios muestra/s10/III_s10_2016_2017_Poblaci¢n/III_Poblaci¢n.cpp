//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////


// Población (con clases)

/*
Los estudios poblacionales utilizan los conceptos de tasa de natalidad,
mortalidad, etc.
Al igual que un porcentaje representa una razón del total por cada cien
(tanto por ciento), la tasa es una razón del total por cada mil
(tanto por mil).
Así pues una tasa de natalidad de 32, por ejemplo, significa que hay
32 nacimientos por cada 1000 habitantes.

Escriba un programa que calcule la estimación de la población de un
territorio después de tres años. Para ello, el programa debe leer
la población inicial, la tasa de natalidad, la de mortalidad y
la tasa de migración. Ésta última es la diferencia entre los que se
van y los que vienen, por lo que puede ser o bien positiva o bien negativa.

Suponga que todos los datos son enteros.

Tenga en cuenta que una vez calculada la población que habrá el
siguiente año, las tasas se vuelven a aplicar sobre la población
así obtenida, y así sucesivamente, tantos años como estemos interesados.
*/                  

/*
Amplie el ejercicio 12 (Población) de la relación de problemas I.
Esta nueva versión del programa, además de los datos ya pedidos
en dicho ejercicio, se le pedirá al usuario que introduzca un número
de años (será el último dato leído)

Debe leer cada dato con un filtro conveniente.
Por ejemplo, las tasas de natalidad, mortalidad y emigración deben ser
enteros entre 0 y 1000, mientras que la población
inicial debe ser un entero positivo.

El programa debe calcular el número total de habitantes transcurridos
dichos años.

Además, el programa también calculará el número de años que tienen que
pasar hasta que haya, como mínimo, el doble de la población inicial.

Ejemplo de entrada: 1375570814 32 12 7 3 --
Salida correcta: 1490027497  27  2824131580
*/

/*
Retome la solución del ejercicio 23 (población) de la Relación de Problemas II. Re-
escríbalo usando las funciones LeeEnteroRango del ejercicio 4 para leer los valores
de las tasas y LeeEnteroMayorIgualQue del ejercicio 5 para leer el número de
años. Defina también sendas funciones para calcular los dos valores que se piden en
el ejercicio, a saber, el número de habitantes después de tres años y el número de
años que pasarán hasta doblar la población inicial. Intente diseñar las funciones para
que sean lo más generales posible.
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

// Con templates no será necesario definir LeeLongLong, LeeInt, etc
// ya que se repite el mismo código en todas ellas.

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
      MSJ_INICIO           = "Cálculo de la población futura.\n",
      MSJ_POBLACION_ACTUAL = "\nIntroduzca la población actual: ",
      MSJ_TASA_NATALIDAD   = "\nIntroduzca la tasa de natalidad: ",
      MSJ_TASA_MORTALIDAD  = "\nIntroduzca la tasa de mortalidad: ",
      MSJ_TASA_MIGRACION   = "\nIntroduzca la tasa de migración: ",
      MSJ_NUMERO_ANIOS     = "\nIntroduzca el número de años: ";
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

   cout << "\n\nPoblación futura pasados " << numero_anios << " años: "
        << poblacion_futura;

   poblacion_objetivo = 2 * poblacion_actual;
   numero_anios       = poblacion.NumeroAniosHastaObtener(poblacion_objetivo);
   poblacion_futura   = poblacion.EstimacionDespuesDe(numero_anios);

   cout << "\n\nPasarán " << numero_anios << " años hasta llegar,"
        << "como mínimo, al doble de la población actual"
        << "\nLa población a la que se llegará es: "
        << poblacion_futura << " habitantes";
}
