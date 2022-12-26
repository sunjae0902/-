//2022-1 프로그래밍기초및실습 과제 2 의생명시스템학부 20212277 김선재
/*
 문제: 아래 기능을 만족하는 프로그램을 작성하여라. 단, 배운 내용만 사용해야 한다.
 8비트 이진수 변환기를 작성한다. 이진수를 입력하면 십진수 정수를 출력한다. 양수와 음수에 대해 모두 동작해야 한다.
 8비트 이진수 덧셈기를 작성한다.
 8비트 이진수 뺄셈기를 작성한다.

 실행 예:
 1. 이진수 변환기     2. 이진수 덧셈기     3. 이진수 뺄셈기
 
 
 
 번호를 선택하세요 : 1

 8비트 이진수를 입력하세요 : 01100101

 십진수로 101 입니다.


 
 */

#include <stdio.h>


int  BinarytoDecimal(int bin){ //이진수->십진수 변환
    int pow=128,sum=0;
    int ten=100000000; //10의 8승
    if (bin/(ten/10)==0){                  //양수일때
        while(ten>=10){
            sum+=pow*((bin%ten)/(ten/10));
             pow/=2;
            ten/=10;
        
    }    return sum;}

    else{
          while(ten>=10){
            sum+=pow*((bin%ten)/(ten/10));
               pow/=2;
            ten/=10;
        
    }
          return sum-256;
        }
}

void DecimaltoBinary(int sum){ //십진수->이진수 변환
    int quo=128,N=0;
        if (sum>=0){ //양수일 경우
            while(quo>=1){
                if (sum/quo<=1){
                    printf("%d",sum/quo);
                    quo/=2;
            }

                else{
                    if ((sum/quo)%2==0) printf("%d",0);
                 
                    else printf("%d",1);
                    quo/=2;
            
        }
      }
    }
        else { //음수일 경우
            N=sum+256;
            while(quo>=1){
                if (N/quo<=1){
                    printf("%d",N/quo);
                    quo/=2;
            }

                  else{
                    if ((N/quo)%2==0){
                        printf("%d",0);
                     }
                    else{
                        printf("%d",1);
                }
                    quo/=2;
            }

        }
        }

    return;
}



int main(void) {
    int n;
    int bin,add1,add2,min1,min2;

back:
    printf("1. 이진수 변환기   2. 이진수 덧셈기   3. 이진수 뺄셈기\n");
    printf("번호를 입력하세요: "); scanf("%d",&n);
    printf("\n");

    switch(n){
    case 1: //2->10진수 변환기
        printf("8비트 이진수를 입력하세요: ");
        scanf("%08d",&bin);
        printf("십진수로 %d 입니다\n",BinarytoDecimal(bin));
        break;

        
    case 2: //2진수 덧셈
        printf("첫번째 8비트 이진수를 입력하세요: ");
        scanf("%08d",&add1);
        printf("두번째 8비트 이진수를 입력하세요: ");
        scanf("%08d",&add2);

        int sum1=BinarytoDecimal(add1)+BinarytoDecimal(add2);

        printf("두 이진수의 합은 "); DecimaltoBinary(sum1);
        printf(" 이고, ");
        if (sum1>=-256 && sum1<-128)
            printf("십진수로는 %d입니다\n",sum1+256);

        else if (sum1>=-128 && sum1<=127)
            printf("십진수로는 %d입니다\n",sum1);
        else if (sum1>=128)
            printf("십진수로는 %d입니다\n",sum1-256);
        break;

    case 3: //2진수 뺄셈
           printf("첫번째 8비트 이진수를 입력하세요: ");
        scanf("%08d",&min1);
        printf("두번째 8비트 이진수를 입력하세요: ");
        scanf("%08d",&min2);

        int sum2=BinarytoDecimal(min1)-BinarytoDecimal(min2);

        printf("두 이진수의 차는 "); DecimaltoBinary(sum2);
        printf(" 이고, ");
        if(sum2>=-255 && sum2<-128)
            printf("십진수로는 %d입니다\n",sum2+256);
        else if (sum2>=-128 && sum2<=127)
            printf("십진수로는 %d입니다\n",sum2);
        else if (sum2>127) printf("십진수로는 %d입니다\n",sum2-256);

        break;

    

    default:
        goto back;
        break;
        

    }

    return 0;}

