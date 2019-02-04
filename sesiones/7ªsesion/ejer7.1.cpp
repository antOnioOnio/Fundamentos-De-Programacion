/*
 
1
 
 int ValorAbsoluto (int entero) {
    if (entero < 0)
        entero = -entero;
    else
        return entero;
} 

-Vemos que cuando el valor es negativo, la funcion lo transforma a positivo, pero el return
esta solo cuando el valor es positivo, con lo que cuando es negativo nunca devuelve el valor.

2
 
 void Cuadrado (int entero) {
    return entero*entero
 }
-Las funciones void no devuelven ningun valor, no hay return en ellas

3

void Imprime(double valor){
    double valor;
 
    cout << valor ;
 }

-El double valor dentro de la funcion es inutil, no se debe poner pues interfiere con la variable
argumento.

4
bool EsPositivo(int valor) {
    if(valor > 0)
        return true;
}

-Devolvemos un valor a la funcion booleana solo cuando el valor es positivo, cuando el valor 
es negativo no nos dice que es falsa. No hace nada. 
*/
