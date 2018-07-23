/*************************************************************************
	> File Name: binaryTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月23日 星期一 11时43分04秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int key;
    struct Node *lchild, *rchild;
}Node;
Node *getNode(int );
void clear(Node *);
void preorder(Node *);
void inorder(Node *);
void postorder(Node *);
Node *getNode(int key){
    Node *p=(Node *)malloc(sizeof(Node));
    p->key=key;
    p->lchild=p->rchild=NULL;
    return p;
}
void clear(Node *root){
    if(root ==NULL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}
void preorder(Node *root){
    if(root == NULL) return ;
    printf("%d ",root->key);
    preorder(root->lchild);
    preorder(root->rchild);
    return ;
}
void inorder(Node *root){
    if(root==NULL) return ;
    inorder(root->lchild);
    printf("%d ",root->key);
    inorder(root->rchild);
    return ;
}
void postorder(Node *root){
    if(root==NULL) return ;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->key);
    return ;
}
int main(){
    Node *root=getNode(1);
    root->lchild=getNode(2);
    root->rchild=getNode(3);
    root->lchild->lchild=getNode(7);
    root->lchild->rchild=getNode(8);
    root->rchild->rchild=getNode(4);
    root->rchild->rchild->lchild=getNode(5);
    root->rchild->rchild->rchild=getNode(6);
    root->lchild->rchild->lchild=getNode(9);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
}
