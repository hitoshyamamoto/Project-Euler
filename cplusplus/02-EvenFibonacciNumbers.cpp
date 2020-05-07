#include <bits/stdc++.h>
#define phi (1+sqrt(5))/2
#define psi (1-sqrt(5))/2

using namespace std;

double funcInversaBinet(double Fn){
    double cond_Fibonacci;
    cond_Fibonacci = sqrt(5*pow(Fn,2) - 4);
    
    double pos_N;
    pos_N = log((Fn*sqrt(5) + cond_Fibonacci)/2) / log(phi);

    return pos_N;
}

double formulaSerieGeometrica(double pos_N){
    double phi3 = pow(phi,3);
    double psi3 = pow(psi,3);

    double somatoria_Phi = phi3*((1-pow(phi3,pos_N))/(1-phi3));
    double somatoria_Psi = psi3*((1-pow(psi3,pos_N))/(1-psi3));

    double resposta_Somatoria;
    resposta_Somatoria = (somatoria_Phi - somatoria_Psi)/sqrt(5);

    return resposta_Somatoria;
}

int main(){
    double resposta;
    double valor_entrada;
    scanf("Insira o valor do ultimo Fibonacci: %lf", &valor_entrada);
    
    resposta = funcInversaBinet(valor_entrada);
    resposta = formulaSerieGeometrica(resposta);

    printf("\nResultado: %lf\n",resposta);

    return 0;
}