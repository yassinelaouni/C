#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int rechDicRec(int T[], int n, int x, int g, int d){
    if(g>d) return -1;
    int m=(g+d)/2;
    if(T[m]==x) return m;
    if(T[m]>x) return rechDicRec(T,n,x,g,m-1);
    return rechDicRec(T,n,x,m+1,d);
}

int main(){
    int T[]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int x=5;
    printf("Position de %d dans le tableau: %d\n",x,rechDicRec(T,n,x,0,n-1));
    return 0;
}