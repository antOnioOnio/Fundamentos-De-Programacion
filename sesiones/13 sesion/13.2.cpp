/*
 2. [Circunferencia]. Recupere la solucion del ejercicio 48 de la relacion de problemas III
 Circunferencia representando el centro con un struct)
 Sobre la clase Circunferencia, defina el metodo SegmentoRadio para que devuelva
 un objeto de la clase SegmentoDirigido con el segmento correspondiente al radio de la
 circunferencia. Cree un programa principal que lea el centro (dos datos de tipo double) y
 la longitud del radio (un dato de tipo double), construya una circunferencia con estos datos
 y a partir de ella, construya el segmento correspondiente al radio. Calcule ahora la
 longitud del segmento radio a traves del metodo Longitud de la clase SegmentoDirigido y
 muestre el resultado en pantalla (debe coincidir con la longitud original del radio)
 Finalidad: Metodos que devuelven objetos de otra clase. Dificultad Baja.
 
 
 Recupere la definición del registro CoordenadasPunto2D del ejercicio 47 de esta
 relación de problemas y la solución al ejercicio 3 (Circunferencia) de la relación de
 problemas I.
 Cree ahora una clase llamada Circunferencia . Para establecer el centro, se usará
 un dato miembro que ha de ser de tipo CoordenadasPunto2D .
 Añada métodos para obtener la longitud de la circunferencia y el área del círculo inte-
 rior.
 Añada también un método para saber si la circunferencia contiene a un punto cualquie-
 ra. Recordemos que un punto (x 1 ,y 1 ) está dentro de una circunferencia con centro
 (x0 ,y0 ) y radio r si se verifica que:
 (x0 - x1 ) ^ 2 + (y0 - y1 ) ^ 2 <= r^2
 Observe que el valor de p debe ser constante, y el mismo para todos los objetos de
 la clase Circunferencia
 Cree un programa principal que lea el centro y el radio de una circunferencia, las
 coordenadas de un punto y muestre en pantalla la longitud de la circunferencia, el
 área del círculo y nos diga si el punto está dentro o no de la circunferencia.
 
 Ejemplo de entrada: 2.1 3.2 5.8 2.2 4.6
 -- Salida correcta: 36.4425 105.683 El punto está dentro
 Ejemplo de entrada: 2.1 3.2 5.8 2.2 10.36
 -- Salida correcta: 36.4425 105.683 El punto no está dentro
 
 
 47. Defina un struct llamado CoordenadasPunto2D para representar un par de valores
 reales correspondientes a un punto en R2.
 Defina una función DistanciaEuclidea para que calcule la distancia entre dos
 puntos cualesquiera. Cree un programa principal que vaya leyendo 4 valores reales
 desde teclado representando las coordenadas de dos puntos y calcule la distancia
 euclídea entre ellos. Cada vez que se lean los cuatro valores se le preguntará al usuario
 si quiere seguir introduciendo datos o no (con las opciones 's'/'n').
 Ejemplo de entrada:
 s 3.1 4.2 5.3 6.4 j k s 2.1 4.9 -3.2 0 s 1 5 1 5 n
 .... Salida correcta: 3.11127 7.21803 0
 Finalidad: Trabajar con funciones y el tipo struct. Dificultad Baja
 
 3. Cree un programa que nos pida la longitud del radio y calcule el área del círculo y la
 longitud de la circunferencia correspondientes. Finalmente, el programa mostrará en
 pantalla los resultados. Recuerde que:
 área circ = r2 long. circunf = 2r
 En primera instancia, use como  el valor 3.1416. A continuación cambie el valor por
 3.1415927, recompile y ejecute.
 Ejemplo de entrada: 3 .... Salida correcta: 28.274 18.849
 Ejemplo de entrada: 0 .... Salida correcta: 0 0
 
 */
// Ejercicio 2 de la sesion 13
// Antonio Garcia Castillo

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415927;

struct CoordenadasPunto2d{
    double abscisa;
    double ordenada;
};

class SegmentoDirigido{
    
private:
    
    CoordenadasPunto2d origen;
    CoordenadasPunto2d final;
    
public:
    
    SegmentoDirigido(CoordenadasPunto2d P_origen, CoordenadasPunto2d P_final){
        
        setCoordenadas(P_origen, P_final);
        
    }
    SegmentoDirigido(){
        origen.abscisa =0;
        origen.ordenada = 0;
        final.abscisa=0;
        final.ordenada=0;
    }
    void setCoordenadas(CoordenadasPunto2d P_origen, CoordenadasPunto2d P_final){
        origen.abscisa = P_origen.abscisa;
        origen.ordenada = P_origen.ordenada;
        final.abscisa = P_final.abscisa;
        final.ordenada = P_final.ordenada;
    }
    CoordenadasPunto2d getOrigen(){
        return origen;
    }
    CoordenadasPunto2d getFinal(){
        return final;
    }
    double getOrigenAbscisa(){
        return origen.abscisa;
    }
    double getOrigenOrdenada(){
        return origen.ordenada;
    }
    double getFinalAbscisa(){
        return final.abscisa;
    }
    double getFinalOrdenada(){
        return final.ordenada;
    }
    
    double Longitud(){
        double diferencia_abscisas = getOrigenAbscisa() - getFinalAbscisa();
        double diferencia_ordenadas =getOrigenOrdenada() -getFinalOrdenada();
        return sqrt(   (diferencia_abscisas * diferencia_abscisas)
                    +
                    (diferencia_ordenadas * diferencia_ordenadas) );
    }
};

class Circunferencia{
private:
    double radio;
    CoordenadasPunto2d centro;
public:
    Circunferencia(){
        radio = 1;
        centro.abscisa = 0;
        centro.ordenada = 0;
        
    }
    Circunferencia (double r, double x, double y){
        setCoordenadas(r,x,y);
    }
    void setCoordenadas ( double r , double x, double y){
        centro.abscisa = x;
        centro.ordenada = y;
        radio = r ;
    }
    double getRadio(){
        return radio;
    }
    CoordenadasPunto2d getCentro(){
        return centro;
    }
    double LongitudCircunferencia(){
        double longitud;
        longitud=2*PI*radio;
        
        return longitud;
    }
    double Area(){
        double area;
        area=2*PI*radio*radio;
        
        return area;
    }
    // Metodo pedido
    
    SegmentoDirigido SegmentoRadio(){
        
        SegmentoDirigido objeto;
        
        CoordenadasPunto2d puntoCircunferencia, puntoCentro;
        
        puntoCentro = getCentro();
        puntoCircunferencia = puntoCentro;
        puntoCircunferencia.abscisa += getRadio();
       
        objeto.setCoordenadas(puntoCentro, puntoCircunferencia);
        
        return objeto;
    }
};
// FUNCION MAIN

    int main (){
        double abscisa,ordenada,radio, longitud_segmento;
        Circunferencia circulo1;
        SegmentoDirigido segmento;

        // Introduccion da datos
        
        cout << "\nIntroduzca las coordenadas del centro x: \t";
        cin >> abscisa;
        cout << "\nIntroduzca las coordenadas del centro y: \t";
        cin >> ordenada;
        cout << "\nIntroduzca la longitud del radio: \t";
        cin >> radio;
        
        circulo1.setCoordenadas(radio, abscisa, ordenada);
        
        segmento = circulo1.SegmentoRadio();
        
        longitud_segmento = segmento.Longitud();
        
        cout << "La longitud del radio es: ";
        cout << longitud_segmento <<endl;
        
        
        return 0;
        
    }
