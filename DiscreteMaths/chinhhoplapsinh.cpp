#include <stdio.h>
#include <stdlib.h>

#define MAX 20
int S[MAX], c=0, n, k; //bo qua S[0].

void print();

main()
{
  int i,j;
  
  //system("COLOR F0");
  printf("nhap n, k:"); scanf("%d%d", &n,&k);
  for (i=1; i<=k; i++) S[i]=1; print();
  while (1){
    i=k; while (i>0 && S[i]==n) i--;
    if (i==0) break;
    S[i]+=1;
    for (j=i+1;j<=k;j++) S[j]=1;
    print();
  }
}

void print()
{
  int i;
  printf("\n%3d:",++c);
  for (i=1; i<=k; i++) printf("%d ", S[i]);
}
