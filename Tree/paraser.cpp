/*************************************************************************
	> File Name: paraser.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月26日 星期四 09时43分31秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int key;
    struct Node *lchild,*rchild;
}Node;
Node *getNewNode(char ch){
    Node *p=(Node *)malloc(sizeof(Node));
    p->key=ch;
    p->lchild=p->rchild=NULL;
    return p;
}
Node *build(char *str,Node *root){
    if(str[0]==0) return NULL;
    Node *p=NULL;
    static int i;
    if(init)  i=0;
    int flag=0;
    while(str[i]){
        switch(str[i]){
            case '(':{
                i++;
                p=build(str,p,0);
            }break;
            case ')':{
               if(root==NULL) return p;
               return root;
            }
            case ',':{
                
                flag = 1;
            }break;
            case ' ':{}break;
            default :{
                p=getNewNode(str[i]);
                if(root!=NULL){
                    if(flag==0) root->lchild=p;
                    else root->rchild=p;
                }
            }break;
        }
        i++;
    }
}
void output(Node *root){
    if(root==NULL) return ;
    output(root->lchild);
    output(root->rchild);
}
int main(){
    char str[1000];
    while(scanf("%[^\n]s",str)!=EOF){
        
        Node *p=build(str,NULL,1);
        output(str,p);
    }
    return 0;
}
