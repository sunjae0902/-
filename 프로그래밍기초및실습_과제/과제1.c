//2022-1 프로그래밍기초및실습  과제 1 의생명시스템학부 20212277 김선재
/*
 문제: -128부터 127까지의 십진수 정수 하나를 입력하면 8비트 이진수로 출력하는 프로그램을 작성하여라. 단, 나누기와 나머지 연산자를 이용하여 프로그래밍해야 하며, 단순히 256가지 경우의 수로 결과를 출력해서는 안 된다. 또한, 배운 내용만 사용해야 한다(배열 사용 금지, 사용자 정의 함수 사용 금지)
 
 입력 예: -128부터 127까지의 십진수 정수 하나를 입력하세요 : -69
 
 출력 예: -69의 이진수는 1011 1011 입니다.

 
*/


#include <stdio.h>

int main(void)
{
    int n,quo=128,cnt=0,N=0;

    do {
        printf("-128부터 127까지의 10진수 정수 하나만 입력하세요:" );
        scanf("%d",&n);} while (n<-128 && n>127);

    if (n>=0){ //양수일 경우
        printf("%d의 이진수는 ",n);
        while(quo>=1){
            if (n/quo<=1){
                printf("%d",n/quo); cnt++;
                quo/=2;
                if (cnt==4) printf(" ");
            }

            else{
                if ((n/quo)%2==0){
                    printf("%d",0);
                    cnt++;
                    if (cnt==4) printf(" "); }
                else{
                    printf("%d",1);
                    cnt++;
                    if (cnt==4) printf(" ");}
                quo/=2;
            }
        }
        printf(" 입니다\n");
    }
    else { //음수일 경우
        quo/=2; //64대입
        N=n+128;
        printf("%d의 이진수는 ",n);
        printf("%d",1);//부호비트 1출력
        cnt++;
        while(quo>=1){
            if (N/quo<=1){
                printf("%d",N/quo); cnt++;
                quo/=2;
                if (cnt==4) printf(" ");
            }

            else{
                if ((N/quo)%2==0){
                    printf("%d",0);
                    cnt++;
                    if (cnt==4) printf(" "); }
                else{
                    printf("%d",1);
                    cnt++;
                    if (cnt==4) printf(" ");}
                quo/=2;
            }
        }
        printf(" 입니다\n");
    }
return 0;
}
