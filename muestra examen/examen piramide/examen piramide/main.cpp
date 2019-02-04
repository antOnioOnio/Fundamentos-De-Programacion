/*Piramide definitivo*/

#include <iostream>
using namespace std;

int main (){
    int n;
    
    cout << "\Introduzca el n˙mero de escalones que desee para su Pir·mide  : \t" ;
    cin >> n;
    
    for (int i=0;i<=n;i++){
        
        for (int j=1 ; j<n-i+1; j++){
            
            cout << " ";
        }
        
        for ( int j=i-1; j>=1 ; j--){
            
            cout << j;
        }
        
        for ( int j=0 ; j<i;j++){
            
            cout << j;
        }
        cout << endl;
    }
    
}


