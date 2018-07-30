/*************************************************************************
	> File Name: hash.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 16时24分55秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct Data{
    char *str;
    struct Data *next;
}Data;

typedef struct HashTable{
    Data *data;
    int size;
    int (*hash_func)(Data *);
    int cnt;
    int flag;
}HashTable;



int __APHash(Data *data){
    return APHash(data->str);
}
int __BKDRHash(Data *data){
    return BKDRHash(data->str);
}
int __ZobristHash(Data *data){
    return ZobristHash(data->str);
}






int APHash(const char *str){
    int hash=0;
    for(int i=0;str[i];i++){
        if(i & 1){
            
            hash ^= (hash << 7 ) ^ str[i]^(hash >> 3);
        }else {
            hash ^=(~((hash << 11)^str[i]^(hash>>5)));
        }
    }
    return  (hash & 0x7fffffff);
}
int BKDRHash(const char *str){
    int hash=0,seed = 131;
    for(int i=0;str[i];i++){
        hash=hash *seed +str[i];
    }
    return hash & 0x7ffffffff;
}
int zobrist_table[50][256]={0};
void init_zobrist_table(){
    for(int i=0;i<50;i++){
        for(int j=0;j<256;j++){
            zobrist_table[i][j]=rand();
        }
    }
    return ;
}

int ZobristHash(const char *str){
    static int flag=1;
    if(flag){
        flag=0;
        init_zobrist_table();
    }
    int hash=0;
    for(int i=0;str[i];i++){
        hash ^=zobrist_table[i][str[i]];

    }
    return hash & 0x7fffffff;
}




int MyHash(const char *str){
    int hash=1;
    for(int i=0;str[i];i++){
        hash *=str[i];
    }
    return hash &0x7fffffff;
}

HashTable *init(int size,int (*func)(Data *)){
    HashTable *p=(HashTable *)malloc(sizeof(HashTable));
    p->data=(Data *)calloc(size,sizeof(Data));
    p->size=size;
    p->cnt=0;
    p->hash_func=func;
    return p;

}

void clear(HashTable *h){
    if(h==NULL) return ;
    free(h->data);
    free(h);
    return ;
}

int query(HashTable *h,const char *str){
    int ind = h->hash_func(str)%h->size;
    Data *p=h->data[ind].next;
    while(p){
        if(strcmp(p->str,str)==0) return -1;
        p=p->next;
        h->cnt++;
    }
    return ind;
}

void insert(HashTable *h,const char *str){
    int ind=query(h,str);
    if(ind == -1) return ;
    Data *data = (Data *)malloc(sizeof(Data));
    
    data->str=strdup(str);
    data->next=h->data[ind].next;
    h->data[ind].next=data;
    return ;
}



int main(){
    HashTable *apHashTable=init(100,ApHash);
    HashTable *bkdrHashTable=init(100,BKDRhash);
    HashTable *zobristHashTable = init(100,ZobristHash);
    HashTable *myHashTable= init(100,MyHash);
    #define MAX_TEST_CNT 10000
    for(int i=0;i<MAX_TEST_CNT;i++){
        char str[7]={0};
        for(int j=0;j<6;j++){
            str[j]=rand()%26+'a';
        }
        str[6]=0;
        insert(apHashTable,str);
        insert(bkdrHashTable,str);
        insert(zobristHashTable,str);
    }
    printf("AP(%d)=%d\n",MAX_TEST_CNT,apHashTable->cnt);
    printf("NK(%d)=%d\n",MAX_TEST_CNT,bkdrHashTable->cnt);
    printf("ZO(%d)=%d\n",MAX_TEST_CNT,zobristHashTable->cnt);
    printf("MY(%d)=%d\n",MAX_TEST_CNT,myHashTable->cnt);
    #undef MAX_TEST_CNT



    srand(time(0));

    char str1[50]={0};
    char str2[50]={0};
    for(int i=0;i<16;i++){
        str1[i]=(i&1)? 'a' : 'b';

    }
    for(int i=0;i<32;i++){
        str2[i]=(i&1)? 'a':'b';
    }

    printf("BKDRhash(%s)=%d\n",str1,BKDRHash(str1));
    printf("BkDRhash(%s)=%d\n",str2,BKDRHash(str2));
    printf("APHash(%s)=%d\n",str1,APHash(str1));
    printf("APHash(%s)=%d\n",str2,APHash(str2));
    printf("zobrist_table(%s)=%d\n",str1,ZobristHash(str1));
    printf("zobrist_table(%s)=%d\n",str2,ZobristHash(str2));
    return 0;
}
