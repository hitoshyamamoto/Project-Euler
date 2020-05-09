#include <stdio.h>
#include <math.h>

int main(){
    unsigned long long n = 600851475143;
    unsigned long long i = 1;

    for(i=1; i<sqrt(n); i++){
        if(n%i == 0) n/=i;
    }

    printf("The largest prime factor is %llu\n",n);

    return 0;
}