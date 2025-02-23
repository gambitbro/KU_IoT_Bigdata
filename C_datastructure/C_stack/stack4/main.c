// 예외처리 if문 대신 assert() 사용
// malloc과 free 사용

#include <stdio.h>
#include "stack.h"

// struct stack {
//     int array[100];
//     int tos;
// }; 

int main(void)
{
    Stack s1, s2;
    //struct stack stacks[20];

    //s1, s2 구조체는 지역 변수 tos를 갖기 때문에 initStack함수를 호출하여 0으로 초기화.(전역변수는 자동으로 초기화되니 필요없음)
    initStack(&s1, 10);
    initStack(&s2, 100);
    // s1.tos = 0;
    // s2.tos = 0;

    push(&s1, 100);
    push(&s1, 200);
    push(&s1, 300);

    int re;
    pop(&s1, &re);
    printf("s1 1st pop : %d\n", re);
    pop(&s1, &re);
    printf("s1 2nd pop : %d\n", re);
    pop(&s1, &re);
    printf("s1 3rd pop : %d\n", re);

    push(&s2, 900);
    push(&s2, 800);
    push(&s2, 700);

    pop(&s2, &re);
    printf("s2 1st pop : %d\n", re);
    pop(&s2, &re);
    printf("s2 2nd pop : %d\n", re);
    pop(&s2, &re);
    printf("s2 3rd pop : %d\n", re);
    // printf("s2 1st pop : %d\n", pop(&s2));
    // printf("s2 2nd pop : %d\n", pop(&s2));
    // printf("s2 3rd pop : %d\n", pop(&s2));
    

    clearStack(&s1);
    clearStack(&s2);
    return 0;
}


