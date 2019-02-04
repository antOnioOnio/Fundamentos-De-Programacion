/*Los estudios poblacionales utilizan los conceptos de tasa de natalidad, mortalidad, etc. Al igual que un porcentaje representa una razón del total por cada cien (tanto por ciento), la tasa es una razón del total por cada mil (tanto por mil). Así pues una tasa de natalidad de 32, por ejemplo, significa que hay 32 nacimientos por cada 1000 habitantes.
 Escriba un programa que calcule la estimación de la población de un territorio después de tres años. Para ello, el programa debe leer la población inicial, la tasa de natalidad, la de mortalidad y la tasa de migración. Ésta última es la diferencia entre los que se van y los que vienen, por lo que puede ser o bien positiva o bien negativa.
 Suponga que todos los datos son enteros.
 Tenga en cuenta que una vez calculada la población que habrá el siguiente año, las tasas se vuelven a aplicar sobre la población así obtenida, y así sucesivamente, tantos años como estemos interesados.
 Ejemplo de entrada:                                      Salida correcta:
 Finalidad: Ejemplo básico de asignación acumulada y uso de tipos numéricos distintos.
 Dificultad Baja.*/

#include <iostream>
#include <cmath>

using namespace std;


int main() {

    int pob_inicial, tasa_natal, tasa_mortal, tasa_migra, pob_final;
    int tasa_total, incremento;
    
    // introduccion de datos
    cout << " Poblacion inicial:";
    cin >> pob_inicial;
    cout << " Tasa natal:" ;
    cin >> tasa_natal;
    cout << " Tasa mortal:" ;
    cin >> tasa_mortal;
    cout << " Tasa migracion";
    cin >> tasa_migra;
    
    // calculos
    tasa_total = tasa_natal + tasa_migra - tasa_mortal;
    incremento = pob_inicial/1000 *tasa_total;
    pob_final = pob_inicial + incremento;
    
    // MUESTRA RESULTADOS
    cout << "\nPoblacion final despues de un año \n\n " <<pob_final;
    
    incremento = pob_final/1000 *tasa_total;
    pob_final = pob_final + incremento;
    
    cout << "\nPoblacion final despues de dos años \n\n " <<pob_final;
    
    incremento = pob_final/1000 *tasa_total;
    pob_final = pob_final + incremento;
    
     cout << "\nPoblacion final despues de tres años \n\n " <<pob_final;
    
    return 0;
}
