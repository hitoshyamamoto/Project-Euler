#include <bits/stdc++.h>

using namespace std;

int main(){
    int num_digit;
    scanf("%d",&num_digit);

    long long int limite_superior = 0;
    long long int limite_inferior = 0;

    //A partir num_digit, calcula-se o maior valor possivel
    for(long long int i=1; i<=num_digit; i++){
        limite_superior *= 10;
        limite_superior += 9;
    }

    //A partir do limite_superior, calcula-se o menor
    limite_inferior = (1+limite_superior)/10;

    //Inicializa os testes
    long long int palindrome_max = 0;
    long long int produto_x = 0;
    long long int produto_y = 0;

    /*
    Como valor a ser buscado e o maior palindrome,
    entao comeca os primeiros testes pelo meior valor
    Por exemplo:
    Se num_digit = 2, então limite_superior é 99 e
    limite_inferior é 10
    Se num_digit = 3, então limite_superior é 999 e
    limite_inferior é 100
    */
    for(long long int i=limite_superior; i>=limite_inferior; i--){
        for(long long int j=i; j>=limite_inferior; j--){
            //Se num_digit = 3, primeiro produto_teste é 999*999
            //primeiro produto_teste é 999*998 e assim vai
            long long int produto_teste = i*j;
            
            if(produto_teste < palindrome_max){
                break;
            }
            
            long long int valor_original = produto_teste;
            long long int valor_reverso  = 0;

            //Espelha-se o valor_original e coloca no valor_reverso
            while(valor_original != 0){
                valor_reverso = (valor_reverso*10) + (valor_original%10);
                valor_original /=10;
            }

            if((produto_teste == valor_reverso) && (produto_teste > palindrome_max)){
                palindrome_max = produto_teste;
                produto_x = i;
                produto_y = j;
            }
        }
    }

    printf("Produto de %lld x %lld = %lld\n", produto_x, produto_y, palindrome_max);

    return 0;
}