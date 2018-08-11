
#ifndef _SEAR_H
#define _SEAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./trie.h"
#define null 300


typedef struct HashTable{

    int *data;
    int h_size;
}hashtable;

hashtable *init(int size){
    hashtable *h=(hashtable *)malloc(sizeof(hashtable));
    h->h_size=size;
    h->data=(int *)calloc(sizeof(int),size);
    for(int i=0;i<size;i++) h->data[i]=null;
    return h;
}

int hash_convert(hashtable *h,char *str){
    int ans=0;
    for(int i=0;str[i];i++){
        ans=(ans*256+str[i]+128)%h->h_size;
    }
    return ans;
}

void insert_ha(hashtable *h,char *huff_code,int val){
    int key=hash_convert(h,huff_code);
    while(h->data[key]!=null){
        key=(key+1)%h->h_size;
    }
    h->data[key]=val;
    return ;
}


void huff_to_str(char *hu_code,hashtable *h,unsigned char *ans){
    int ind=0;
    char temp[100]={0};
    int k=0;
    for(int i=0;hu_code[i];i++){
        temp[k]=hu_code[i];
        temp[k+1]='\0';
        int key=hash_convert(h,temp);
        if(h->data[key]!=null){
            ans[ind++]=h->data[key];
            printf("-->%d",h->data[key]);
            memset(temp,0,sizeof(temp));
            k=-1;
        }
        k++;
    }
    ans[ind]='\0';
    return ;
}



#endif
