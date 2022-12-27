//2022-2 알고리즘 과제 1
/*
 문제: 다음 상세형 재귀적 알고리즘을 참고하여 Linker Emulation을 통한 n번째 피보나치 항을 구하는 c/c++ 프로그램을 개발한다.
int fin (int n) {
 int t1, t2;
 if (n<=1) return n;
 else {           // return fib(n-1) + fib(n-2);
  t1 = fib(n-1); // a 
  t2 = fib(n-2); // b 
  return t1+t2; // c
  }
}

 입력 예: input n: 10
 출력 예: 55 (result2에 저장된 10번째 피보나치 수)
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long count2=0;

typedef struct fbARI{
    long long n,t1,t2,fv;
    char nStmt; //현재 처리 문장을 나타냄
    struct fbARI* prev; //다음 노드를 가리키는 포인터
}fbARI;

typedef struct Stack{
    fbARI *top; //가장 최근에 생성한 AR을 가리키는 포인터
}Stack;

void initStack(Stack *stack){ //스택 초기화 함수
    stack->top=NULL;
}

int isEmpty(Stack *stack){ //스택이 비었는지 확인하는 함수, 비었다면 TRUE 리턴
    return stack->top==NULL;
}

void push(Stack *stack, long long data){ // 스택 push 함수
    count2++;
    fbARI *now=(fbARI *)malloc(sizeof(fbARI));
    now->n=data;
    now->prev=stack->top; //널값
    stack->top=now;
}

long long pop(Stack *stack){ // 스택 Pop함수
    fbARI *now;
    long long re;

    if (isEmpty(stack)){ // 스택이 비어있다면 pop하지 못함
        return 0;
    }
    now=stack->top;
    re=now->n;
    stack->top=now->prev;
    free(now);
    return re;
}

int main(void){
    fbARI* cfbARI;
    
    Stack stack;
    initStack(&stack);
    
    int n;
    long long fv=0,result2=0; 
  
    
    printf("input n: "); scanf("%d",&n);
    
    push(&stack,n); //n push
    stack.top->nStmt='a'; //현재 처리 문장
    cfbARI=stack.top; //가장 최근에 생성한 노드 집어넣음
    
   

    while(!isEmpty(&stack)){ //스택이 빌 때까지 반복
        fv=pop(&stack);
        switch(cfbARI->nStmt){ //현재 처리 문장의 상태에 따라 분기
            case 'a':
                if (fv==1) {
                    result2+=fv;
                    cfbARI->nStmt='b';
                   }
                
                if (fv>=2){
                    cfbARI->t1=fv-2;
                    push(&stack,cfbARI->t1);
                }
                
                if (fv>=1){
                    cfbARI->t2=fv-1;
                    push(&stack,cfbARI->t2);
                    
                }
                break;
         

       case 'b':
                if (fv==1) {
                    result2+=fv;
                    cfbARI->nStmt='c';
                    
                    }
                
                if (fv>=2){
                    cfbARI->t1=fv-2;
                    push(&stack,fv-2);
                }
                
                if (fv>=1){
                    cfbARI->t2=fv-1;
                    push(&stack,fv-1);
                    }
                break;
                
          case 'c':
                if (fv==1) {
                    result2+=fv;
                   }
                
                if (fv>=2){
                    cfbARI->t1=fv-2;
                    push(&stack,fv-2);
                }
                
                if (fv>=1){
                    cfbARI->t2=fv-1;
                    push(&stack,fv-1);
                    }
                break;
                
              }
    }
 return result2;
   }

