/*************************************************************************
	> File Name: Trie.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月04日 星期六 15时28分18秒
 ************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BASE 26
#define BEGIN_LETTER 'a'
#include<time.h>
typedef struct Node{
    int flag;
    struct Node *next[26];

}Node,*Trie;

int node_cnt=0;

Node *get_new_node(){
    Node *p=(Node *)malloc(sizeof(Node));
    p->flag=0;
    memset(p->next,0,sizeof(Node *)*BASE);
    return p;
}

void clear(Trie root){
    if(root==NULL){
        return ;

    }
    for(int i=0;i<BASE;i++){
        clear(root->next[i]);
    }
    free(root);
    return ;
}
Node * insert(Trie root,const char *str){
    if(root==NULL) root = get_new_node();
    Node *p=root;
    for(int i=0;str[i];i++){
        if(p->next[str[i]-BEGIN_LETTER]==NULL) p->next[str[i]-BEGIN_LETTER]=get_new_node();
        p=p->next[str[i]-BEGIN_LETTER];
    }
    p->flag=1;
}


int search(Trie root,const char *str){
    Node *p;
    int i=0;
    while(p&&str[i]){
        int ind=str[i++]-BEGIN_LETTER;
        p=p->next[ind];

    }
    return (p&&p->flag);
}

void get_random_string(char *str){
    int len=rand()%10;
    for(int i=0;i<len;i++){
        str[i]=BEGIN_LETTER+rand()%BASE;

    }
    str[len]=0;
    return;
}



void output(Trie root,char *str,int level){
    if(root==NULL ) return ;
    str[level]=0;
    if(root->flag){
        printf("find word :%s\n",str);
    }
    for(int i=0;i<BASE;i++){
        if(root->next[i]==NULL) continue;
        str[level]=i+BEGIN_LETTER;
        output(root->next[i],str,level+1);

    }
    return ;

}
int main(){
    srand(time(0));
    #define INSERT_CNT 20;
    Trie root=NULL;
    char str[50];
    int word_cnt=0;
    for(int i=0;i<INSERT_CNT;i++){
        get_random_string(str);
        root =insert(root,str);
        word_cnt+=strlen(str);
        printf("insert %s to Trie\n",str);
    }
    output(root,str,0);
    printf("strorage rate :%lf\n",1.0*word_cnt/(1.0*node_cnt*sizeof(Node)));
    #undef INSERT_CNT
    return 0;
}
