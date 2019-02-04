/*DESCRIPCION
 */

#include <iostream>

using namespace std;




int main(){
    
    const int TOPE=7;
    int j, i;
    
    
    for(j=1; j<=TOPE; j++){
        
        for(i=1; i<=TOPE; i++){
            
            if(i == 1 || i == TOPE || j == 1 || j == TOPE){
                
                cout << "X";
                
            }else{
               
                cout << "0";
                }
            }
        
        
        cout << endl;
    }
    
    
    return 0 ;

}
