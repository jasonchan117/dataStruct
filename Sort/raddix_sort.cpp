/*************************************************************************
	> File Name: odd.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 11时48分34秒
 ************************************************************************/
#define lowbit(x) (x&0xffff)
#define highbit(x) ((x >>16)& 0xffff)
#include<stdio.h>
#include<stdlib.h>
#define MAX_N 65536

int main(){

    return 0;
}
void raddix_sort(int *num,int n){
    int *temp=(int *)malloc(sizeof(int)*n);
    int cnt[MAX_N]={0};
    for(int i=0;i<n;i++) cnt[lowbit(num[i])]++;
    for(int i=1;i<MAX_N;i++) cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--)
        temp[--cnt[lowbit(num[i])]]=num[i];


    for(int i=0;i<n;i++) cnt[highbit(temp[i])]++;
    for(int i=1;i<MAX_N;i++) cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--)
        num[--cnt[highbit(temp[i])]]=temp[i];
    
    free(temp);
#undef MAX_N
}
