#include <bits/stdc++.h>
#include <math.h>

using namespace std;

bool quadratico(int n){
    double raiz = sqrt(n);
    if((raiz - floor(raiz))!=0) return true;
    else return false;
    
}

void crivoAtkin(unsigned long long int entrada){
    if(entrada%2==0){
        printf("[2] = 2\n");
        entrada = entrada/2;
    }
    if(entrada%3==0){
        printf("[3] = 3\n");
        entrada = entrada/3; 
    }
    if(entrada!=1){
        for (int x = 1; x*x < entrada; x++) { 
            for (int y = 1; y*y < entrada; y++) { 
                
                // Principal do Crivo de Atkin 
                int n = (4*x*x) + (y*y); 
                if (n <= entrada && (n % 12 == 1 || n % 12 == 5)){
                    if(entrada%n==0 && quadratico(n)){
                        entrada = entrada/n; 
                    }
                }
                n = (3*x*x) + (y*y); 
                if (n <= entrada && n % 12 == 7){
                    if(entrada%n==0 && quadratico(n)){
                        entrada = entrada/n;
                    }
                }
                n = (3*x*x) - (y*y); 
                if (x > y && n <= entrada && n % 12 == 11){
                    if(entrada%n==0 && quadratico(n)){
                        entrada = entrada/n;
                    }
                }
            } 
        }
    }
}

int main(){
    unsigned long long int entrada = 600851475143;

    crivoAtkin(entrada);

    return 0;
}