//
// Created by root on 17-12-23.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define null NULL
typedef int ElemType;
typedef struct BTNode {
    ElemType data;
    struct BTNode *lchild, *rchild;
} BTree;

#define QUEUE_SIZE 100
#define STACK_SIZE 100
#define STACK_INC_SIZE 10
#define true 1
#define false 0
typedef int Status;

typedef struct Stack {
    BTree *base;
    BTree *top;
    int stackSize;
} Stack;

Stack *InitStack(Stack *stack) {
    stack = (Stack *) malloc(sizeof(Stack));
    if (!stack) exit(0);
    stack->base = (BTree *) malloc(STACK_SIZE * sizeof(BTree));
    stack->top = stack->base;
    stack->stackSize = STACK_SIZE;
    printf("Init stack successfully\n");
    return stack;
}

Status freeStack(Stack *s) {
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
Status Push(Stack *s, BTree *e) {
    assert(s);
    //stack is full, need more space
    if (s->top - s->base >= s->stackSize) {
        s->base = (BTree *) realloc(s->base, (s->stackSize + STACK_INC_SIZE) * sizeof(BTree));
        if (!s->base) {
            printf("realloc failed!\n");
            exit(1);
        }
        s->top = s->base + s->stackSize;
        s->stackSize += STACK_INC_SIZE;
    }
    *(s->top) = *e;
    ++(s->top);
    return 1;
}

//pop out elem from stack
BTree *Pop(Stack *s) {
    assert(s);
    if (s->base == s->top) {
        printf("It's a empty stack\n");
        return null;
    }
    --(s->top);
    BTree *e;
    e = (s->top);
    return e;
}

int Is_Empty(Stack *s) {
    assert(s);
    if (s->base == s->top) {
        return true;
    } else {
        return false;
    }

}


//pop out elem from stack
void Pop2(Stack *s, BTree *e) {
    assert(s);
    if (s->base == s->top) {
        printf("It's a empty stack\n");
    }
    --(s->top);
    *e = *(s->top);
}


BTree *GetTop(Stack *s) {
    return (s->top - 1);
}

//traverse the stack from base to top
void print(Stack *s) {
    assert(s);
    BTree *elem = s->base;
    if (s->base == s->top) {
        printf("This is an empty stack!\n");
    }
    for (elem; elem != s->top; elem++) {
        printf("element is %d", *elem);
        printf("\n");
    }
}


BTree *Init_BTNode() {
    BTree *bt = null;
    ElemType a;
    bt = (BTree *) malloc(sizeof(BTree));
    printf("input the root node , input 0 to specify an empty tree\n");
    scanf("%d", &a);
    if (a == 0) {
        printf("this is an empty tree\n");
        exit(0);
    }

    bt->data = a;
    bt->lchild = null;
    bt->rchild = null;
    return bt;
}

int create_BTree(BTree *bt) {
    ElemType a;
    BTree *node = null;
    printf("input %d 's lchild node (0 is empty)\n", bt->data);
    scanf("%d", &a);
    if (a != 0) {
        node = (BTree *) malloc(sizeof(BTree));
        node->data = a;
        node->lchild = null;
        node->rchild = null;
        bt->lchild = node;
        create_BTree(bt->lchild);
    }
    printf("input %d 's rchild node (0 is empty)\n", bt->data);
    scanf("%d", &a);
    if (a != 0) {
        node = (BTree *) malloc(sizeof(BTree));
        node->data = a;
        node->lchild = null;
        node->rchild = null;
        bt->rchild = node;
        create_BTree(bt->rchild);
    }

    return 0;
}

void preOrderTraverse(BTree *bt) {
    if (bt != null) {
        printf("%d --> \n", bt->data);
        preOrderTraverse(bt->lchild);
        preOrderTraverse(bt->rchild);
    }
}

void preOrderTraveseNoRicursion(BTree *bt, Stack *s) {
    s = InitStack(s);
    BTree *cur = bt;
    BTree *pre = cur;
    while (cur != null || !Is_Empty(s)) {
        printf("%d-->", cur->data);
        Push(s, cur);
        pre = cur;
        cur = cur->lchild;
        while (!cur && !Is_Empty(s)) {
            Pop2(s, pre);
            cur = pre;
            cur = cur->rchild;
        }
    }
    freeStack(s);
}


void inOrderTraverse(BTree *bt) {
    if (bt != null) {
        inOrderTraverse(bt->lchild);
        printf("%d --> \n", bt->data);
        inOrderTraverse(bt->rchild);
    }
}

void inOrderTraverseNoRecursion(BTree *bt, Stack *s) {
    s = InitStack(s);
    BTree *cur = bt;
    BTree *pre = cur;
    while (cur || !Is_Empty(s)) {
        if (cur->lchild != null) {
            Push(s, cur);
            pre = cur;
            cur = cur->lchild;
        } else {
            printf("%d-->", cur->data);
            cur = cur->rchild;
            while (!cur && !Is_Empty(s)) {
                Pop2(s, pre);
                cur = pre;
                printf("%d-->", cur->data);
                cur = cur->rchild;
            }
        }
    }
    freeStack(s);
}


void postOrderTraverse(BTree *bt) {
    if (bt != null) {
        postOrderTraverse(bt->lchild);
        postOrderTraverse(bt->rchild);
        printf("%d --> \n", bt->data);
    }
}

void postOrderTraverseNoRecursion(BTree *bt, Stack *s) {
    BTree *stack[100];
    BTree *cur;
    BTree *pre = NULL;
    int top = 0;
    int base = top;
    if (bt) {
        cur = bt;
        stack[top++] = cur;
    }
    while (top != base) {
        cur = stack[top - 1];
        if ((cur->lchild == null && cur->rchild == null) ||
            (pre != null && (cur->lchild == pre || cur->rchild == pre))) {
            printf("%d-->", cur->data);
            --top;
            pre = cur;
        } else {
            if (cur->rchild != null) {
                stack[top++] = cur->rchild;
            }
            if (cur->lchild != null) {
                stack[top++] = cur->lchild;
            }
        }
    }
}

void levelOrderTraverse(BTree *bt) {
    BTree *queue[QUEUE_SIZE];
    BTree *cur = null;
    int front = 0;
    int rear = 0;
    if (bt != null) {
        queue[rear] = bt;
        rear = (rear + 1) % QUEUE_SIZE;
    }
    while (front != rear) {
        cur = queue[front];
        front = (front + 1) % QUEUE_SIZE;
        printf("%d --> ", cur->data);
        if (cur->lchild != null) {
            queue[rear] = cur->lchild;
            rear = (rear + 1) % QUEUE_SIZE;
        }
        if (cur->rchild != null) {
            queue[rear] = cur->rchild;
            rear = (rear + 1) % QUEUE_SIZE;
        }
    }

}

void main() {
    BTree *bt;
    int a;
    printf("\t\t****************  二叉树操作  ****************\n\n");
    bt = Init_BTNode();
    create_BTree(bt);
    printf("以%d为根的树创建成功！\n", bt->data);
    while (1) {
        system("clear");
        printf("\t\t1. 先序遍历\n");
        printf("\t\t2. 中序遍历\n");
        printf("\t\t3. 后序遍历\n");
        printf("\t\t4. 层序遍历\n");
        printf("\t\t5. 退出程序\n");
        printf("\t\t6. 非递归前序\n");
        printf("\t\t7. 非递归中序\n");
        printf("\t\t8. 非递归后序\n");
        printf("\t请选择：");
        scanf("%d", &a);
        switch (a) {
            case 1:
                printf("先序遍历\n");
                preOrderTraverse(bt);
                printf("\n");
                system("date");
                break;
            case 2:
                printf("中序遍历\n");
                inOrderTraverse(bt);
                printf("\n");
                system("date");
                break;

            case 3:
                printf("后序遍历\n");
                postOrderTraverse(bt);
                printf("\n");
                system("date");
                break;
            case 4:
                printf("层序遍历\n");
                levelOrderTraverse(bt);
                printf("\n");
                system("date");
                break;
            case 5:
                exit(0);
            case 6:
                printf("非递归前序\n");
                Stack *s;
                preOrderTraveseNoRicursion(bt, s);
                printf("\n");
                system("date");
                break;
            case 7:
                printf("非递归中序\n");
                Stack *s1;
                inOrderTraverseNoRecursion(bt, s1);
                //freeStack(s1);
                printf("\n");
                system("date");
                break;
            case 8:
                printf("非递归中序\n");
                Stack *s2;
                postOrderTraverseNoRecursion(bt, s2);
                //freeStack(s1);
                printf("\n");
                system("date");
                break;
            default:
                printf("输入错误");
        }
    }
}


