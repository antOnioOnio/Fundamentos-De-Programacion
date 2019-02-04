//////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//////////////////////////////////////////////////////////////////////////

// Clase Circunferencia

#include <iostream>
using namespace std;

const double PI = 3.1415927;

class Circunferencia{
private:
    double centro_x = 0.0;
    double centro_y = 0.0;
    double radio    = 0.0;
public:
    void SetCentro(double abscisa, double ordenada){
        centro_x = abscisa;
        centro_y = ordenada;
    }
    void SetRadio(double el_radio){
        if (el_radio > 0)
            radio = el_radio;
    }
    double GetAbscisaCentro(){
        return centro_x;
    }
    double GetOrdenadaCentro(){
        return centro_y;
    }
    double GetRadio(){
        return radio;
    }
    double Longitud(){
        return 2*PI*radio;
    }
    double Area(){
        return PI*radio*radio;
    }
    void Traslada(double en_horizontal, double en_vertical){
        centro_x = centro_x + en_horizontal;
        centro_y = centro_y + en_vertical;
    }
};
int main(){
    Circunferencia mi_aro;
    double longitud_mi_aro;
    
    mi_aro.SetCentro(4.5, 6.7);
    mi_aro.SetRadio(2.1);
    longitud_mi_aro = mi_aro.Longitud();    // 13.19468
    
    mi_aro.SetRadio(8.3);                   // Cambiamos el radio
    longitud_mi_aro = mi_aro.Longitud();    // 52,15044
    
    cout << "Circunferencia\n\n";
    cout << "Centro: " << mi_aro.GetAbscisaCentro() << " , " <<
    mi_aro.GetOrdenadaCentro();
    cout << "\nRadio: " << mi_aro.GetRadio();
    cout << "\nLongitud circunferencia: " << longitud_mi_aro;
    
    mi_aro.Traslada(10.1, 15.2);            // Traslación
    longitud_mi_aro = mi_aro.Longitud();    // 52,15044
    
    cout << "\n\n";
    cout << "Centro: " << mi_aro.GetAbscisaCentro() << " , " <<
    mi_aro.GetOrdenadaCentro();
    cout << "\nRadio: " << mi_aro.GetRadio();
    cout << "\nLongitud circunferencia: " << longitud_mi_aro;
}
