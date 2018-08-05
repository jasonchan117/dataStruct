#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST(func) { \
	printf("%s = %d\n", #func, func); \
}
#define RETURN(a,b,c) {\
	for(int i=0;i<128;i++) free(b[i]);\
	free(b);\
	free(c);\
	return a;\
}
int *state_change(int *p,int *d,int len){
	int *ans=(int *)calloc(sizeof(int),len);
	for(int i=0;i<len-1;++i) p[i]=p[i+1];
	p[len-1]=1;

	for(int i=0;i<len;i++){
		if(p[i]&&d[i]) ans[i]=1;
		else ans[i]=0;
	}
	return ans;
}

int shift_and(const char *text,const char *pattern){
	int len=strlen(pattern);
	int **digit=(int **)calloc(sizeof(int *),128);

	for(int i=0;i<128;i++) digit[i]=(int *)calloc(sizeof(int),len);

	for(int i=0;pattern[i];i++) digit[pattern[i]][len-1-i]=1;

	int *p=(int *)calloc(sizeof(int),len);
	for(int i=0;text[i];i++){
		p=state_change(p,digit[text[i]],len);
		if(p[0]) RETURN(1,digit,p);
	}
	RETURN(0,digit,p);
}

int main(){
	TEST(shift_and("hello world", "wor"))
	TEST(shift_and("hello world", "helo"))
}

