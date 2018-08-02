/*************************************************************************
	> File Name: string_algorithm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月02日 星期四 20时35分47秒
 ************************************************************************/

#include<iostream>
using namespace std;
int BF(const char *text,const char *partten){
    int len1 = strlen(text);
    int len2=strlen(pattern);
    for(int i=0;i<len1-len2+1;i++){
        int flag=1;
        for(int j=0;pattern[j];j++){
            if(text[i+j]==pattern[j]) continue;
            flag=0;
        }
        if(flag)return 1;
    }
    return 0;
}
int KMP(const char *text,const char *pattern){
    int len1=strlen(text);
    int len2=strlen(pattern);
    int *next(int *)malloc(sizeof(int) *len2);
    int j=-1;
    next[0]=-1;
    for(int i=1;i<len2;i++){
        int j=next[i-1];
        while(j != -1&&pattern[j+1]!=pattern[i]) j=next[j];
        if(pattern[j+1]==pattern[i]){
            j+=1;
        }
        next[i]=j;
    }
    j=-1;
    for(int i=0;text[i];i++){
        while(j!=-1&&pattern[j+1]!=text[i]) j=next[j];
        if(pattern[j+1]==text[i]) j+=1;
        if(pattern[j+1]==0) return 1;
    }
    return 0;
}
int main(){


    return 0;
}
