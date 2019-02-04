//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Gaussiana con clases (incluida CDF)

/*
Gaussiana
   - double _esperanza, _desviacion;
   + Gaussiana (double esperanza, double desviacion)
   + double Evalua(double x)
   + double AreaHasta(double x)
*/


#include <iostream>
#include <cctype>
#include <cmath>

const double PI = 3.1415927;   // Global por si la necesitamos en otras funciones

using namespace std;

// -----------------------------------------------------------------------
double LeeDoubleMayorIgualQue(double minimo, string mensaje){
   double a_leer;

   do{
      cout << mensaje;
      cin >> a_leer;
   }while (minimo > a_leer);

   return a_leer;
}

// -----------------------------------------------------------------------
//	Potencia de un número elevado a un entero.
double Potencia(double la_base, int el_exponente){
	// Observad que si exponente fuese cero, la variable potencia se quedaría con 1,
	// lo que es correcto ya que base elevado a 0 es siempre 1

	double potencia;
	int exponente_positivo;

	if (la_base == 0 && el_exponente == 0)
		potencia = sqrt (-1.0);						   // Devuelve NaN (Indeterminación)
	else{
		exponente_positivo = abs(el_exponente);
		potencia = 1;								   	// ¿Y si empezase con potencia = base?

		for (int i = 1; i <= exponente_positivo; i++)
			potencia = potencia * la_base;
	}

	if (el_exponente < 0)
		potencia = 1/potencia;

	return potencia;
}



class Gaussiana{
private:
   double _esperanza, _desviacion;
public:
   Gaussiana (double esperanza, double desviacion){
      _esperanza = esperanza;
      _desviacion = desviacion;
   }
   
   // Valor de la función Gaussiana (o "Normal") en un punto x
   double Evalua(double x){
      double valor_tipificado, exponente;
   	double ordenada;

   	valor_tipificado = (x - _esperanza) / _desviacion;
      exponente = -0.5 * valor_tipificado * valor_tipificado;
      ordenada = exp(exponente) / ( _desviacion * sqrt(2*PI) );

   	return ordenada;
   }
   
   // Área hasta x que queda por debajo de la Gaussiana
   double AreaHasta(double x){
   	// Aproximación dada por Zelen & Severo (1964)
   	// -ver Wikipedia (Normal distribution) para otras aproximaciones-
   	const double b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782,
   		          b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;
   	double area_hasta;
   	double t;

   	t = 1 / (1 + b0 * x);
   	area_hasta = 1 -  Evalua(x)
   							*
   							(b1*t + b2*Potencia(t,2) + b3*Potencia(t,3) +
                         b4*Potencia(t,4) + b5*Potencia(t,5));

   	return area_hasta;
   }
};


bool Menu2OpcionesSalirPrograma(string mensaje, 
                                char opcion_salir, 
                                char opcion_seguir){
   char opcion_menu;
   bool eligio_salir, es_correcta_opcion;
   
   cout << mensaje;
   
   do{
      cout << "\nIntroduzca la opción (" << opcion_seguir
           << "/" << opcion_salir << ") ";
      cin >> opcion_menu;
      opcion_menu = toupper(opcion_menu);
      eligio_salir = opcion_menu == opcion_salir;
      es_correcta_opcion = eligio_salir || opcion_menu == opcion_seguir;
   }while (! es_correcta_opcion);
   
   return eligio_salir;
}
      
// -----------------------------------------------------------------------
int main(){
	/*
		Como norma general no usaremos nombres de variables como x, y, etc.
		Hacemos una excepción en este programa ya que son nombres
      omnipresentes en Matemáticas.
	*/
	
	/*
	(P)arámetros  -> [cin esperanza y desviación] -> (R)ango -> [cin min, max, incremento] -> Resultados ->|
	(S)alir       <--------------------------------- (V)olver <--------------------------------------------|	
	*/
	/*
	do{
	  Mostrar Menú Ppal (Parámetros o Salir)
	  Leer opcion_menu_ppal
	  
	  if opcion_ppal no es Salir
	     Lectura de esperanza y desviación
	     
	     do{
	        Mostrar Menú (Rango o Volver)
	        Leer opcion_menu_secundario
	        
	        if opcion_menu_secundario no es Volver
	           Lectura de min, max e incremento
	           Mostrar resultados
        }while (opcion_menu_secundario != 'V')
   }while (opcion_ppal != 'S')
   */       
   const char OPCION_INTRO_PARAMETROS = 'P',
              OPCION_SALIR = 'S',
              OPCION_INTRO_RANGO = 'R',
              OPCION_VOLVER = 'V';
   bool eligio_salir_ppal, eligio_salir_secundario;
	
	const string
      MSJ_MENU_PPAL =
	   "\n\n---------------------\nMenú Principal\n\nParámetros\nSalir\n",
	   MSJ_MENU_SECUNDARIO =
	   "\n\nMenú Secundario\n\nRango\nVolver\n",
      MSJ_INTRO_ESPERANZA =
      "\nIntroduzca el valor del parámetro 'esperanza': ",
      MSJ_INTRO_DESVIACION =
      "\nIntroduzca el valor del parámetro 'desviacion'. Debe ser un número positivo: ",
      MSJ_INTRO_MINIMO =
      "\nIntroduzca el valor mínimo de la abscisa: ",
      MSJ_INTRO_MAXIMO =
      "\nIntroduzca el valor máximo de la abscisa. Debe ser un número positivo: ",
      MSJ_INTRO_INCREMENTO =
      "\nIntroduzca el valor del incremento. Debe ser un número positivo: ";
      
	double esperanza, desviacion, x, min_x, max_x, incremento;
	double y, cdf;
	
   cout << "Gaussiana";
   
   do{
      eligio_salir_ppal = Menu2OpcionesSalirPrograma(
                                                MSJ_MENU_PPAL,
                                                OPCION_SALIR,
                                                OPCION_INTRO_PARAMETROS);
      
      if (! eligio_salir_ppal){
         cout << MSJ_INTRO_ESPERANZA;
      	cin >> esperanza;
         desviacion = LeeDoubleMayorIgualQue(0, MSJ_INTRO_DESVIACION);
         
         /*
            Cada vez que se lea un nuevo valor de esperanza y desviación
            se creará un nuevo objeto de la clase Gaussiana.
            El objeto "antiguo" desaparecerá como le ocurre a cualquier
            variable declarada a nivel de bloque.
            
            Esta recarga computacional habría que tenerla en cuenta
            en programas en los que se crean continuamente objetos.
            En ese caso sería mejor crear un único objeto fuera del
            bloque y dentro del bloque cambiar sus datos miembros
            con métodos Set
         */
         
         // >>>>>>>>>   Creación del objeto    <<<<<<<<<<<<<
         Gaussiana gaussiana(esperanza, desviacion);
         
         do{
            eligio_salir_secundario = Menu2OpcionesSalirPrograma(
                                                      MSJ_MENU_SECUNDARIO,
                                                      OPCION_VOLVER,
                                                      OPCION_INTRO_RANGO);
            
            if (! eligio_salir_secundario){
               cout << MSJ_INTRO_MINIMO;
            	cin >> min_x;
            	max_x      = LeeDoubleMayorIgualQue(min_x, MSJ_INTRO_MAXIMO);
               incremento = LeeDoubleMayorIgualQue(0, MSJ_INTRO_INCREMENTO);
               
               x = min_x;
               
               while (x <= max_x){
                  y   = gaussiana.Evalua(x);
                  cdf = gaussiana.AreaHasta(x);
                  
                  cout << "\nf(" << x << ")= " << y;
                  cout << "\n\t\t\tCDF(" << x << ")= " << cdf;
                  
                  x = x + incremento;
               }
            }
         }while (! eligio_salir_secundario);
      }
   }while (! eligio_salir_ppal);
}
