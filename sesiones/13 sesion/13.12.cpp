/*
 Un polígono regular de n caras tiene n lados de
 la misma longitud y todos los ángulos interiores son iguales. 
 Su centro geométrico esel centro de la circunferencia circunscrita (la que lo envuelve). Supondremos que dos polígonos son distintos si se
 diferencian o bien en sus centros geométricos, o bien en el número de lados o bien en la longitud de cualquiera de ellos. 
 Así pues, por ejemplo, no tendremos en cuenta las distintas posiciones en el plano que se podrían obtener girando el 
 polígono sobre su centro.
 
 Si llamamos n al número de lados y l la longitud de cualquiera de ellos, tenemos que:
 • la longitud r del radio de la circunferencia circunscrita viene definida por 
 r =l/(2 sin(π/n))
 • El área del polígono es A = (n/2) · r2 sin(2π/n)
 • Si queremos construir un polígono inscrito en la misma circunferencia, pero mul- tiplicando por un entero k el número de lados, la longitud de cada uno de los kn lados viene dada por l′ = r 2(1 − cos(2π/(kn))).
 Se quiere diseñar la clase PoligonoRegular para poder representar este tipo de polígonos y realizar las siguientes tareas:
 • Calcular el perímetro del polígono.
 • Calcular el área del polígono.
 • Calcular la diferencia entre el área del polígono y la del círculo correspondiente a la circunferencia circunscrita.
 • Comprobar si un polígono es más grande que otro (considerando al área de cada uno)
 • Construir un nuevo polígono que tenga la misma circunferencia circunscrita y con un número de lados que sea múltiplo del número de lados del polígono.
 Debe tener los siguientes constructores:
 • Un constructor sin parámetros en el que los valores a asignar por defecto sean: 3 para el número de lados (triángulo), 1 para la longitud y (0,0) para las coorde- nadas del centro.
 • Un constructor que cree un polígono regular con una longitud y número de lados concretos y deje como centro el valor por defecto (0,0).
 • Un constructor que cree un polígono regular con una longitud, número de lados y centro concretos.
 Defina un programa que realice lo siguiente:
 • Cree dos polígonos, poligono1 con los valores por defecto y poligono2 con 6 lados de longitud 4 y centrado en (0,0). El programa comprobará si poligono1 es más grande que poligono2.
 • Construya un nuevo polígono a partir de poligono1, con la misma circunferen- cia circunscrita y con el doble número de lados. El programa imprimirá en pantalla el área del nuevo polígono.
 • Repita el proceso anterior generando polígonos con el doble número de lados en cada iteración, hasta que el polígono generado tenga un área similar a la del círculo delimitado por la circunferencia circunscrita. Consideraremos que las áreas son similares si no se diferencian en más de 10−5.
 El programa mostrará el número de lados del polígono que aproxima a la circun- ferencia (el resultado con poligono1 es 1536 lados)
 Finalidad: Trabajar con constructores y con métodos que devuelven y reciben objetos. Dificultad Media. */

// Antonio Garcia Castillo
// Ejercicio 12 de la sesion 13.
#include <iostream>
#include <cmath>
using namespace std ;

const double PI =3.14159;

struct Punto2d {
    double x ;
    double y ;
};

class PoligonoRegular {
private:
    double longitud_lado ;
    double numero_lados;
    Punto2d centro;
    
public:
    //              CONSTRUCTOR SIN PARAMETROS, POR DEFENTO TRIANGULO Y 1 LONGITUD
    PoligonoRegular(){
        longitud_lado = 1;
        numero_lados = 3;
        centro.x = 0;
        centro.y = 0;
    }
    //              CONSTRUCTOR CON LONGITUD Y LADOS CONCRETOS, CENTRO POR DEFECTO = 0
    PoligonoRegular(double longitud, int lados){
        longitud_lado=longitud;
        numero_lados=lados;
        centro.x=0;
        centro.y=0;
    }
    //              CONSTRUCTOR CON PARAMETROS
    PoligonoRegular(double longitud, int lados, double coordX, double coordY){
        longitud_lado=longitud;
        numero_lados=lados;
        centro.x=coordX;
        centro.y=coordY;
    }
    void setCentro(double coordX, double coordY){
        centro.x=coordX;
        centro.y=coordY;
    }
    void setLongitud(double longitud){
        longitud_lado=longitud;
    }
    void setLados(int numero){
        if(numero!=0){
            numero_lados=numero;
        }
        else {
            numero_lados=3;
        }
    }
    int getLados(){
        return numero_lados;
    }
    //      METODO QUE CALCULA PERIMETRO A PARTIR DEL PRODUCTO DE TODOS SUS LADOS
    double Perimetro(){
        double perimetro;
        
        perimetro=longitud_lado*numero_lados;
        return perimetro;
    }
    //     METODO CALCULA RADIO A PARTIR DE LA ECUACION DADA
    double Radio(){
        double radio;
        
        if (numero_lados!=0){
            radio=longitud_lado/(2*sin(PI/numero_lados));
            return radio;
        }
        else {
            radio=1;
            return radio;
        }
    }
    //      METODO CALCULA AREA POLIGONO A PARTIR DE LA ECUACION DADA
    double AreaPoligono(){
        double radio=Radio();
        double area;
        
        area=(numero_lados/2)*radio*radio*sin(2*PI/numero_lados);
        return area;
    }
    double AreaCirculo(){
        double radio=Radio();
        double area;
        area=2*PI*radio*radio;
        return area;
    }
    //     METODO PARA CALCULAR LA DIFERENCIA ENTRE EL AREA DEL CIRCULO Y DEL POLIGONO CIRCUNSCRITO
    double DiferenciaAreas(){
        double area_poligono=AreaPoligono();
        double area_circulo=AreaCirculo();
        double diferencia;
        
        diferencia=abs(area_circulo-area_poligono);
        
        return diferencia;
    }
    bool MayorQ(PoligonoRegular objeto2){
        
      if (AreaPoligono()>objeto2.AreaPoligono()){
        
            return true;
        }
        else {
            return false;
        }
    }
    

//          METODO PARA CALCULAR EL NUEVO POLIGONO A PARTIR DE UN MULTIPLO K
    PoligonoRegular PoligonoKlados(int k){
        
        double radio = Radio();
        double longitud_P= radio*(sqrt(2*(1-cos(2*PI/(k*numero_lados)))));
        
        PoligonoRegular objeto(longitud_P, k*numero_lados);
        
        
        return objeto;
    }

    
};
    
int main (){
    
    PoligonoRegular poligono1 ;
    PoligonoRegular poligono2(2,6);
    PoligonoRegular poligono3;
    double  diferencia = 0.00001;
    bool mayor ;
    
    mayor = poligono1.MayorQ(poligono2);
    
    // COMPROBAMOS QUE POLIGONO ES MAYOR
    if (mayor){
        cout<< "Poligono1 es mayor que Poligono2.\n" ;
    }
    else {
        cout<< "Poligono2 es mayor que Poligono1.\n" ;
    }
    // CREAMOS UN NUEVO POLIGONO A PARTIR DE POLIGONO 1 CON EL DOBLE NUMERO DE LADOS
    poligono3 = poligono1.PoligonoKlados(2);
    cout << " El area del primer poligono es:\t " << poligono1.AreaPoligono() <<endl;
    cout << " El area del poligono creado a partir de él es:\t " << poligono3.AreaPoligono()<<endl;
   

    while ( poligono3.DiferenciaAreas() >diferencia){
        
    poligono3 = poligono3.PoligonoKlados(2);
       
    }
    
    
    cout << "numeros de lados  " << poligono3.getLados()<<endl;
    return 0 ;

}

