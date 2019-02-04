//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Secuencia de enteros

#include <iostream>
using namespace std;

class SecuenciaEnteros{
private:
   static const int TAMANIO = 50;
   int vector_privado[TAMANIO];
   int total_utilizados;
   
public:
   SecuenciaEnteros()
      :total_utilizados(0) {
   }
   
   int TotalUtilizados(){
      return total_utilizados;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void EliminaTodos(){
      total_utilizados = 0;
   }
   
   void Aniade(int nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   
   void Modifica(int posicion, int nuevo){
      if (posicion >= 0 && posicion < total_utilizados)
         vector_privado[posicion] = nuevo;
   }

   int Elemento(int indice){
      return vector_privado[indice];
   }
   
   string ToString(){
      // Si el número de caracteres en memoria es muy grande,
      // es mucho más eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++){
         cadena.append(to_string(vector_privado[i]));
         cadena.append(" ");
         //cadena = cadena + to_string(vector_privado[i])  <- Evitarlo. Muy ineficiente para tamaños grandes;
      }
      
      return cadena;
   }

   
   SecuenciaEnteros suma(SecuenciaEnteros otra){
	   SecuenciaEnteros resultado;
	   if (otra.TotalUtilizados() == TotalUtilizados()){
		   for (int i = 0; i < TotalUtilizados(); i++){
			   int valor1 = Elemento(i);
			   int valor2 = otra.Elemento(i);
			   resultado.Aniade(valor1+valor2);
		   }
	   }
	   return resultado;
   }
   
   int numeroCadenasAscendentes(){
	   int numCadenas = 0;
	   int i = 0;
	   while(i < TotalUtilizados()){
		   numCadenas++;
		   int inicio = vector_privado[i];
		   i++;
		   while((i < TotalUtilizados()) && (vector_privado[i] >= vector_privado[i-1])){
			   i++;
		   }
	   }
	   return numCadenas;
   }

};



class LectorSecuenciaEnteros{
private:
   long terminador;
public:
   LectorSecuenciaEnteros(long entero_terminador)
      :terminador(entero_terminador)
   {
   }
   SecuenciaEnteros Lee(){
      SecuenciaEnteros a_leer;
      int total_introducidos;  // Esta variable es para contar los introducidos
                               // y que no nos pasemos de la capacidad de la secuencia.
      int capacidad_secuencia;
      long entero;

      total_introducidos = 0;
      capacidad_secuencia = a_leer.Capacidad();
      cin >> entero;

      while (entero != terminador && total_introducidos < capacidad_secuencia){
         a_leer.Aniade(entero);
         total_introducidos++;
         cin >> entero;
      }

      return a_leer;
   }
};



int main(){
   const long TERMINADOR = -1;
   LectorSecuenciaEnteros lector_secuencias(TERMINADOR);
   SecuenciaEnteros secuenciaA, secuenciaB, secuenciaC;

	cout << "Introduce una secuencia (-1 para terminar)" << endl;
   secuenciaA = lector_secuencias.Lee();
   cout << "Introduce otra secuencia (-1 para terminar)" << endl;
   secuenciaB = lector_secuencias.Lee();
   secuenciaC = secuenciaA.suma(secuenciaB);

   cout << "\n" << secuenciaC.ToString();
   
   cout << "Introduce otra secuencia (-1 para terminar)" << endl;
   secuenciaB = lector_secuencias.Lee();
   int numAscendentes = secuenciaB.numeroCadenasAscendentes();
   cout << "Numero de secuencias ascendentes para la secuencia = " << numAscendentes << endl;
   
   // 7 2 4 9 -1
}

