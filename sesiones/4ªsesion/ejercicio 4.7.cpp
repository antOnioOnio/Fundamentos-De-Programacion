//
//  main.cpp
//  ejercicio 4.7
//
//  Created by antonio garcia on 20/10/16.
//  Copyright © 2016 antonio garcia. All rights reserved.
//

#include <iostream>

using namespace  std;

int main() {
    // Declaracion de variables
    
    int numero_x,numero_y,numero_z;
    
    cout << " introduce x" << endl;
    cin >> numero_x;
    cout << " introduce y" << endl;
    cin >> numero_y;
    cout << " introduce z" << endl;
    cin >> numero_z;
    
    
    if ( numero_x>numero_y){
        
        if (numero_y>numero_z){
            
            cout << "estan ordenados descendentemente" << endl;
            
        }else{
            
            cout << "no estan ordenados" << endl;
        }
    }
    if ( numero_x<numero_y){
        if (numero_y<numero_z){
            
            
                cout << "estan ordenados ascendentemente" << endl;
        }else{
            
            cout << "no estan ordenados" << endl ;
        
        }
    
    
    
    }
      return 0;
}
