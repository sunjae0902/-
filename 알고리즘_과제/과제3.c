//2022-2 알고리즘 과제3
/*
 문제: 분할정복법을 사용하여 평면 좌표들의 집합으로 이루어져 연속인 곡선을 다각형으로 근사시키는 프로그램을 개발해라.
 procedure:
 1. 곡선은 n개의 (x,y)좌표들로 이루어져있고 좌표들은 2차원 배열 data[2][n]에 저장한다.
 (data[0][]: x좌표, data[1][]: y좌표)
 2. 곡선의 두 끝점(중단점)을 연결하여 만든 직선 이 있을 때, 곡선을 이루는 n개의 각 좌표들에서 직선에 내린 수선의 발의 길이를 1차원 배열 temp[n]에 저장한다.
 3. 이때 temp에서 최댓값(가장 긴 거리) m을 가지는 좌표 값을 breakpoint로 설정하고 m이 임계 값보다 크다면 스택에 좌표 값과 그 점의 배열의 인덱스를 push하고 시작점은 그대로 두고 end point를 설정된 breakpoint로 잡고 위의 과정을 반복한다.
 4. 만약 임계 값보다 작다면 스택을 pop하여 반환된 인덱스 값에 해당하는 좌표 값을 output배열에 저장하고, start point를 pop한 좌표로 잡고, end point는 스택의 최상단에 위치한 점으로 갱신한다.
 5. 스택이 빌 때까지 반복하고 output배열에 저장된 좌표들을 출력한다.
 
 입력: x,y로 구성된 수열-> 연속인 곡선을 이루는 n개의 x, y좌표를 저장하는 2차원 배열 data[2][1..n]
 출력: 근사된 다각형을 이루는 (x,y) 좌표 값들의 열 output[2][]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000


float cp=2.0;//임계값



typedef struct Node{ //노드 정의
    int x,y,ind;
    struct Node *prev; //다음 노드의 주소값을 저장하는 포인터
} Node;

typedef struct {
    Node *top; //가장 최근에 입력된 데이터를 가리키는 top
} Stack;


//initstack->스택 초기화
void initStack(Stack *s){
    s->top=NULL;
}
//isempty
int isEmpty(Stack *s){
    return s->top==NULL; //스택이 비어있다면 참값을 리턴
}
//push
void push(Stack *s,int px,int py,int ind){
    Node *now=(Node *)malloc(sizeof(Node)); // 메모리 동적 할당으로 처음 노드 생성
    now->x=px;
    now->y=py;
    now->ind=ind; //배열의 인덱스 같이 push
    now->prev=s->top; //새로운 노드가 기존의 top노드를 가리키도록
    s->top=now;}
  
int pop(Stack *s){
    if (isEmpty(s)){ //스택이 비었다
        return 0;}

    Node *now=s->top; //now포인터가 top을 가리키도록 선언
    int a=now->ind=s->top->ind;
    s->top=s->top->prev; //기존 top노드가 가리키는 노드가 됨
    free(now);
    return a; //배열 상의 인덱스 반환
}

double dist(int data[2][MAX],int i,int S, int E){
    double a=abs((data[0][i]*(data[1][S]-data[1][E])-data[1][i]*(data[0][S]-data[0][E])-data[0][E]*data[1][S]+data[0][S]*data[1][E]))/sqrt((pow(data[1][E]-data[1][S],2)+pow(data[0][E]-data[0][S],2)));
    return a;
}




int main(void){
    int n;
    Stack s;
    initStack(&s);
    
    int data[2][MAX],output[2][MAX];
    scanf("%d",&n); //좌표 수 입력
    int S=0,E=n-1; //start,end point의 인덱스
    int m=1;
    for (int i=0;i<n;i++) scanf("%d %d",&data[0][i], &data[1][i]); //각 좌표들의 x,y값 입력
    
    output[0][0]=data[0][0];
    output[1][0]=data[1][0]; //output 배열에 처음 s.p 저장
    
    push(&s,data[0][n-1],data[1][n-1],n-1); //스택에 처음 e.p push
    
    
    
    double tdist=sqrt(pow(data[0][0]-data[0][n-1], 2)+pow(data[1][0]-data[1][n-1], 2));
    
    if (tdist<=sqrt(2)) //폐곡선인 경우
    {
        while (!isEmpty(&s)) { //스택이 빌 때까지 반복
            int k=0,ind=0; int M=n/2; double max=0.0;
            double temp[MAX]={0,};
            push(&s,data[0][M],data[1][M],M); //입력 데이터의 중간값 push
            
            for (int i=S+1;i<M;i++,k++) temp[k]=dist(data,i,S,M);
            
            
            for (int j=0;j<k;j++){
                if (max<temp[j]) {
                    max=temp[j];
                    ind=j+S+1;}
            }
        
         
            if (max>cp){
                push(&s,data[0][ind],data[1][ind],ind);
                M=ind;
            }
            
            else {
                int p_ind=pop(&s); //pop한 점의 배열 인덱스 반환
                output[0][m]=data[0][p_ind];
                output[1][m]=data[1][p_ind];
                m++;
               //스타트 포인트 갱신
                printf("%d %d %lf\n",m,ind,max);
                S=p_ind;
                M=s.top->ind;
            
            }
        }
    }
        
    
    
    else{ //폐곡선이 아닐 경우
        
        while (!isEmpty(&s)) { //스택이 빌 때까지 반복
            int k=0,ind=0; double max=0.0;
            double temp[MAX]={0,};
            
            
            for (int i=S+1;i<E;i++,k++) temp[k]=dist(data, i, S, E);
            
            for (int j=0;j<k+1;j++){
                if (max<temp[j]) {
                    max=temp[j];
                    ind=j+S+1; }
            }
          
        
            
            if (max>cp){
                push(&s,data[0][ind],data[1][ind],ind);
                E=ind;
                
                
            }
            else {
                
                int p_ind=pop(&s);
                output[0][m]=data[0][p_ind];
                output[1][m]=data[1][p_ind];
                m++;

                S=p_ind;
                E=s.top->ind;
             
            }
       }
      
    }
    
    
    for (int i=0;i<m;i++)printf("(%d,%d)\n",output[0][i],output[1][i]);
  
    
    
    return 0;
}
