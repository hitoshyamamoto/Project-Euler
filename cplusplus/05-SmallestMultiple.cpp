#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    while(1){
        int entrada;
        ll resposta=1;

        scanf("%d",&entrada);
        if(entrada==0) break;
        int multiplos[entrada];
        for(int i=0;i<sizeof(multiplos)/sizeof(multiplos[0]);i++){
            multiplos[i]=i+1;
            printf("%d ",multiplos[i]);
        }
        printf("\n");
        for(int i=0;i<sizeof(multiplos)/sizeof(multiplos[0]);i++){
            for(int j=0; j<i;j++){
                if(multiplos[i]%multiplos[j]==0 && multiplos[i]!=1){
                    multiplos[i]/=multiplos[j];
                }
            }
        }
        for(int i=0; i<sizeof(multiplos)/sizeof(multiplos[0]);i++){
            if(i==0) printf("%d",multiplos[i]);
            else if(i<(sizeof(multiplos)/sizeof(multiplos[0]))-1) printf("*%d",multiplos[i]);
            else printf("*%d = ",multiplos[i]);
            resposta*=multiplos[i];
        }

        printf("%lld\nRESPOSTA: %lld\n",resposta,resposta);
    }
    return 0;
}