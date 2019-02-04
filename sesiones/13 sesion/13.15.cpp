/*
 15. [Circunferencia con centro un Punto2D]. Recupere la solución del ejercicio 2 de esta relación de problemas (Circunferencia)
 Cámbielo para representar el centro de la circunferencia con un objeto de la clase Punto2D.
 Finalidad: Trabajar con objetos como datos miembros de otros objetos. Dificultad Media. */

// Antonio Garcia Castillo
// Ejercicio 15 de la sesion 13

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415927;

class Punto2D{
private:
    double abscisa;
    double ordenada;
public:
    Punto2D(double abscisaPunto, double ordenadaPunto){
        SetCoordenadas(abscisaPunto, ordenadaPunto);
    }
    Punto2D(){
        abscisa=0;
        ordenada=0;
    }
    double getAbscisa(){
        return abscisa;
    }
    double getOrdenada(){
        return ordenada;
    }
    void SetCoordenadas(double abscisaPunto, double ordenadaPunto){
        abscisa = abscisaPunto;
        ordenada = ordenadaPunto;
    }
    
};
class SegmentoDirigido{
    
private:
    
    Punto2D origen;
    Punto2D final;
    
public:
    
    SegmentoDirigido(Punto2D P_origen, Punto2D P_final){
        
        setCoordenadas(P_origen, P_final);
        
    }
    SegmentoDirigido(){
        origen.SetCoordenadas(0, 0);
        final.SetCoordenadas(0, 0);
    }
    void setCoordenadas(Punto2D inicio, Punto2D fin){
        double x1,y1,x2,y2;
        x1=inicio.getAbscisa();
        y1=inicio.getOrdenada();
        
        origen.SetCoordenadas(x1,y1);
        
        x2=fin.getAbscisa();
        y2=fin.getOrdenada();
        
        final.SetCoordenadas(x2,y2);
        
    }
    Punto2D getOrigen(){
        return origen;
    }
    Punto2D getFinal(){
        return final;
    }
    double getOrigenAbscisa(){
        return origen.getAbscisa();
    }
    double getOrigenOrdenada(){
        return origen.getOrdenada();
    }
    double getFinalAbscisa(){
        return final.getAbscisa();
    }
    double getFinalOrdenada(){
        return final.getOrdenada();
    }
    
    double Longitud(){
        double diferencia_abscisas = getOrigenAbscisa() - getFinalAbscisa();
        double diferencia_ordenadas =getOrigenOrdenada() - getFinalOrdenada();
        return sqrt(   (diferencia_abscisas * diferencia_abscisas)
                    +
                    (diferencia_ordenadas * diferencia_ordenadas) );
    }
};

class Circunferencia{
private:
    double radio;
    Punto2D centro;
public:
    Circunferencia(){
        radio = 1;
        centro.SetCoordenadas(0, 0);
        
    }
    Circunferencia(double longitud, Punto2D punto){
        double x1, y2;
        radio=longitud;
        x1=punto.getAbscisa();
        y2=punto.getOrdenada();
        
        centro.SetCoordenadas(x1,y2);
    }
    
    void setCoordenadas (double rad,Punto2D cntro){
        double x, y;
        
        x = cntro.getAbscisa();
        y = cntro.getOrdenada();
        
        centro.SetCoordenadas(x, y);
        radio = rad;
        
    }
    double getRadio(){
        return radio;
    }
    Punto2D getCentro(){
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
        
        Punto2D puntoCircunferencia, puntoCentro;
        double nuevocentro;
        
        puntoCentro = getCentro();
        
        nuevocentro = puntoCentro.getOrdenada() + getRadio() ;
        
        puntoCircunferencia.SetCoordenadas(puntoCentro.getAbscisa(), nuevocentro);
        
        objeto.setCoordenadas(puntoCentro, puntoCircunferencia);
        return objeto;
    }
};
// FUNCION MAIN

int main (){
    double abscisa,ordenada,radio, longitud_segmento;
    
    SegmentoDirigido segmento;
    Punto2D centro;
    Circunferencia circulo;
  
    
    // Introduccion da datos
    
    cout << "\nIntroduzca las coordenadas del centro x: \t";
    cin >> abscisa;
    cout << "\nIntroduzca las coordenadas del centro y: \t";
    cin >> ordenada;
    cout << "\nIntroduzca la longitud del radio: \t";
    cin >> radio;
    
    centro.SetCoordenadas(abscisa, ordenada);
    
    circulo.setCoordenadas(radio, centro);
    
    segmento = circulo.SegmentoRadio();
    
    longitud_segmento = segmento.Longitud();
    
    cout << "La longitud del radio es: ";
    cout << longitud_segmento <<endl;
    
    
    return 0;
    
}
