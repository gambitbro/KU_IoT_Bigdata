#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"


static Node * createNode(int data, Node *next)
{
    Node *p = malloc(sizeof(Node));
    assert(p);
    p->data = data;
    p->next = next;
    return p;    
}

void initList(List *pList)
{
//     pList->ptr = malloc(sizeof(Node)); //더미노드 생성
//     assert(pList->ptr);

//     pList->ptr->data = ???;             // dummy
//     pList->ptr->next = NULL;            // 더미노드는 처음 아무것도 가리키지않음

    pList->ptr = createNode(-1, NULL);
}

void cleanupList(List *pList)
{
    Node *p = pList->ptr;
    while(p){
        Node *tmp;
        p = p->next;
        free(tmp);
    }
}

void insertFirstNode(List *pList, int data)
{
    //Node *p = malloc(sizeof(Node));
    //assert(p);
    //p->data = data;
    //p->next = pList->ptr->next;
    //pList->ptr->next = p;
    pList->ptr->next = createNode(data, pList->ptr->next);
}

void insertNode(List *pList, int prevData, int data)
{
    //값 찾기
    Node *p = pList->ptr->next;
    while(p){
        if(p->data == prevData){
            break;
        }
        p = p->next;
    }
    if(p){
        // Node *p2 = malloc(sizeof(Node));
        // assert(p2);
        // p2->data = data;
        // p2->next = p->next;
        // p->next = p2;
        p->next = createNode(data, p->next);
    }
}

void deleteNode(List *pList, int data)
{
    Node *p = pList->ptr->next;
    Node *p2 = pList->ptr;
    while(p){
        if(p->data == data){
            break;
        }
        p = p->next;
        p2 = p2->next;
    }
    if(p){
        p2->next = p->next;
        free(p);
    }
}

void printList(const List *pList)
{
    Node *p = pList->ptr->next;
    printf("[");
    while(p){
        printf("%d", p->data);
        printf( (p->next) ? ", " : "" );
        p = p->next;
    }
    printf("]\n");
}