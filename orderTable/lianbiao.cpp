/*************************************************************************
	> File Name: lianbiao.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月06日 星期三 18时14分50秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct LinkNode{
    
    int data;
    struct LinkNode *next;

}LinkNode;

typedef struct LinkList{
    LinkNode *head;
    int n;
}LinkList;
LinkList *init(){
    LinkList *p=(LinkList *)malloc(sizeof(LinkList));
    p->head=NULL;
    p->n=0;
    return p; 
}
LinkNode *getNewNode(int data){
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));
    p->data = data;
    p->next=NULL;
    return p;
}
int insert(LinkList *l,int data,int ind){
    if(ind<0||ind >l->n) return 0;
    LinkNode ret,*p;
    ret.next = l->head;
    p=&ret;
    while(p&&ind--){
        p = p->next;
    }
    if(p==NULL) return 0;
    LinkNode *new_node =getNewNode(data);
    new_node->next = p->next;
    p->next = new_node;
    l->head=ret.next;
    l->n+=1;
    return 1;
}

void clear(LinkList *l){
    LinkNode *head =l->head;
    while(head){
        LinkNode *next= head->next;
        free(head);
        head=next;
    }
    free(l);
    return ;

}

void output(LinkList *l){
    LinkNode *head=l->head;
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("null\n");
}
int main(){
    LinkList *l = init();
    srand(time(0));
    for(int i=0;i<=10;i++){
        int data = rand()%100,ind = rand()%(i+1);
        printf("%d : insert(%d %d)=",i,data,ind);
        fflush(stdout);
        printf("%d:",insert(l,data,ind));
        output(l);
    }
    clear(l);
    return 0;
}








