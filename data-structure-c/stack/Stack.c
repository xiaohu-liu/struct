//
// Created by root on 17-12-23.
//
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_SIZE 100
#define STACK_INC_SIZE 10

typedef int ElemType;
typedef int Status;

typedef struct SqStack {
    ElemType *base;
    ElemType *top;
    int stackSize;
} SqStack;

SqStack *InitStack(SqStack *stack) {
    stack = (SqStack *) malloc(sizeof(SqStack));
    if (!stack) exit(0);
    stack->base = (ElemType *) malloc(STACK_SIZE * sizeof(ElemType));
    stack->top = stack->base;
    stack->stackSize = STACK_SIZE;
    printf("Init stack successfully\n");
    return stack;
}

Status freeStack(SqStack *s) {
    if (!s) {
        printf("Stack is null no need to free \n");
        return 0;
    } else {
        free(s->base);
        free(s);
        return 1;
    }
}

//push element into stack
Status Push(SqStack *s, ElemType e) {
    assert(s);
    //stack is full, need more space
    if (s->top - s->base >= s->stackSize) {
        s->base = (ElemType *) realloc(s->base, (s->stackSize + STACK_INC_SIZE) * sizeof(ElemType));
        if (!s->base) {
            printf("realloc failed!\n");
            exit(1);
        }
        s->top = s->base + s->stackSize;
        s->stackSize += STACK_INC_SIZE;
    }
    *(s->top) = e;
    ++(s->top);
    return 1;
}

//pop out elem from stack
ElemType Pop(SqStack *s) {
    assert(s);
    if (s->base == s->top) {
        printf("It's a empty stack\n");
        return 0;
    }
    --(s->top);
    ElemType e;
    e = *(s->top);
    return e;
}


//pop out elem from stack
void Pop2(SqStack *s, ElemType *e) {
    assert(s);
    if (s->base == s->top) {
        printf("It's a empty stack\n");
        return 0;
    }
    --(s->top);
    *e = *(s->top);
}

//traverse the stack from base to top
void print(SqStack *s) {
    assert(s);
    ElemType *elem = s->base;
    if (s->base == s->top) {
        printf("This is an empty stack!\n");
    }
    for (elem; elem != s->top; elem++) {
        printf("element is %d", *elem);
        printf("\n");
    }
}

void main3() {
    int i;
    SqStack *s;
    s = InitStack(s);
    for (i = 0; i < 20; i++) {
        int elem = rand() % 100;
        Push(s, elem);
    }
    print(s);
    printf("###############################");
    ElemType result = Pop(s);
    printf("result = %d\n", result);
    ElemType popValue = 0;
    Pop2(s, &popValue);
    printf("popValue => %d\n", popValue);
    ElemType *p = (ElemType *) malloc(sizeof(ElemType));
    Pop2(s, p);
    printf("pValue => %d\n", *p);
    print(s);
    freeStack(s);
}


