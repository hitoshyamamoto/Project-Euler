#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

//maior divisor comum
ull mdc(ull a, ull b){
  while (a != 0){
    ull c = a;
    a = b % a;
    b = c;
  }
  return b;
}

//minimo multiplo comum
ull mmc(ull a, ull b){
  return a * (b/mdc(a,b));
}

int main(){
  while (1)
  {
    int entrada;
    scanf("%d", &entrada);
    if(entrada==0) break;

    //Procura minimo multiplo comum de todos os numeros
    ull result = 1;
    for(ull i = 2; i <= entrada; i++)
      result = mmc(result, i);

    printf("%lld\n",result);
  }
  return 0;
}

