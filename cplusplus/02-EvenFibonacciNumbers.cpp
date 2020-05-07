#include <iostream>
#include <math.h>
#include <cmath>
#define phi (1+sqrt(5))/2.0
#define psi (1-sqrt(5))/2.0

using namespace std;

double funcInversaBinet(double Fn){
    double cond_Fibonacci = 0.0;
    cond_Fibonacci = sqrt(5*Fn*Fn - 4);
    
    double pos_N = 0.0;
    pos_N = log((Fn*sqrt(5) + cond_Fibonacci)/2) / log(phi);

    return pos_N;
}

double formulaSerieGeometrica(double pos_N){
    double phi3 = phi*phi*phi;
    double psi3 = psi*psi*psi;

    printf("%d || %d\n", isnan(phi3),isnan(psi3));

    double somatoria_Phi = phi3*((1-pow(phi3,floor(pos_N/3)))/(1-phi3));
    double somatoria_Psi = psi3*((1-pow(psi3,floor(pos_N/3)))/(1-psi3));
    printf("%lf || %lf\n", somatoria_Phi, somatoria_Psi);
    printf("%d || %d\n", isnan(somatoria_Phi),isnan(somatoria_Psi));

    double resposta_Somatoria = 0.0;
    resposta_Somatoria = (somatoria_Phi - somatoria_Psi)/sqrt(5);

    printf("%d\n", isnan(resposta_Somatoria));

    return resposta_Somatoria;
}

int main(){
    double resposta = 0.0;
    double valor_entrada 0.0;
    scanf("%lf",&valor_entrada);
    
    resposta = funcInversaBinet(valor_entrada);
    resposta = formulaSerieGeometrica(resposta);

    printf("Resposta: %lf",resposta);

    return 0;
}