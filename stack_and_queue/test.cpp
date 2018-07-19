/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月19日 星期四 14时34分17秒
 ************************************************************************/

#include<stdio.h>
using namespace std;
int a(){
    static char a[10]="hello";
}
int main(){
    a();
    puts(a);
}
