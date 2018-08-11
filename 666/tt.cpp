#include<stdio.h>
int main(){
    unsigned char ans[100]={0};
    scanf("%s",ans);

    for(int i=0;ans[i];i++) printf("%d\n",ans[i]);

    return 0;
}
