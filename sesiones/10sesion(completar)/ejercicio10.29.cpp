/*
 Dado un tiempo de entrada (hora, minuto y segundo) y un tiempo de salida, construya un programa que calcule la tarifa final a cobrar. Para calcular el número de minutos entre los dos instantes de tiempo, puede utilizar la solución del ejercicio 6 de la Relación de Problemas I.
 
 Retome la solución del ejercicio 10 (parking) de la Relación de Problemas II. Se quiere extender para poder trabajar con varios parkings o con varias tarifas distintas. Supondremos que en todos los casos, se tiene el mismo número de tramos (4) aunque puede variar la cuantía a tarifar por minutos y los límites de cada uno de los tramos.
 Para ello, se pide definir la función             que obtenga la tarifa final aplicable a cualquier caso. En concreto, en este ejercicio, se van a leer sólo dos casos, correspondientes a dos parkings o tarificaciones distintas. Se pide por tanto construir un programa que lea los siguientes datos:
 • En primer lugar el programa lee los datos de cada uno de los dos casos, es decir, los límites de los tramos y las tarifas que se aplican en cada tramo (ver tabla debajo)
 • A continuación, se leen varios pares de instantes de entrada y salida. Se leen en el orden instante de entrada (hora, minuto y segundo) e instante de salida.
 La entrada de datos finaliza cuando se introduce un -1 como hora de entrada.
 El programa imprimirá la tarifa resultante de cada uno de los parkings para cada par de instantes de entrada y salida, así como la suma total recaudada en cada caso.
 
 
 Recupere la solución del ejercicio 9 de esta relación de problemas (parking con funciones). Re-escríbalo para que los cómputos relacionados con el cálculo de la tarifa, estén encapsulados en una clase*/

#include <iostream>

const int HORA_SEGUNDOS = 3600;
const int MINUTOS_SEGUNDOS = 60;



int main() {
    
    
    //DECLARACION DE VARIABLES
    
    
    

