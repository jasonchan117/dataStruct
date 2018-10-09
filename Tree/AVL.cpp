/*************************************************************************
	> File Name: AVL.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年10月09日 星期二 11时27分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX(a,b)({\
    __typeof(a) _a=(a);\
    __typeof(b) _b=(b);\
    _a>_b?_a:_b;\
})
typedef struct Node{

    int key,h;
    struct Node *lchild,*rchild;
}Node;

Node *NIL;

__attribute__((constructor))
void init_nil(){

    NIL=(Node *)malloc(sizeof(Node));
    NIL->key=0;
    NIL->child=NIL->rchild=NIL;
    NIL->h=0;

}
Node *init(int key){
    Node *p=(Node *)malloc(sizeof(Node));
    p->lchild=p->rchild=NIL;
    p->h=1;
    p->key=key;
    return p;
}
void clear(Node *root){

    if(root==NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}
Node *maintain(Node *root){
    if(abs(root->lchild-h-root->rchild->h)<2) return root;
    if(root->lchild->h>root->rchild->h){
        if(root->lchild->lchild->h<root->lchild->rchild->h){

        }
    }


}
Node *insert(Node *root,int key){
    if(root==NIL) return init(key);
    if(root->key==key) return root;
    if(root->key<key){
        root->rchild=insert(root->rchild,key);
    }else {
        root->lchild=insert(root->lchild,key);
    }
    root->h=MAX(root->lchild->h,root->rchild->h)+1;
    root=maintain(root);
}

int main(){



    return 0;
}












