#include<bits/stdc++.h>
using namespace std;

typedef struct DNode {
    int data;
    struct DNode *prior;
    struct DNode *next;
}DNode, *DLinkList;

// 初始化
void initlist(DLinkList &L) {
    L = (DNode *)malloc(sizeof(DLinkList));
    L->prior = NULL;
    L->next = NULL;
}

// 遍历操作
void printList(DLinkList L) {
    DNode *p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// 求长度
int length(DLinkList L) {
    DNode *p = L->next;
    int len = 0;
    
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

// 头插法建立双链表
DLinkList headInsert(DLinkList &L) {
    initlist(L);
    int x;
    scanf("%d", &x);
    
    while (x != 9999) {
        DNode *t = (DNode *)malloc(sizeof(DNode));
        t->data = x;

        if (L->next == NULL) {
            t->next = NULL;
            t->prior = L;
            L->next = t;
        } else {
            t->next = L->next;
            L->next->prior = t;
            t->prior = L;
            L->next = t;
        }
        scanf("%d", &x);
    }
    return L;
}

// 尾插法建立单链表
DLinkList tailInsert(DLinkList &L) {
    initlist(L);
    DNode *t;
    DNode *s = L;
    int x;
    scanf("%d", &x);

    while (x != 9999) {
        t = (DNode *)malloc(sizeof(DNode));
        t->data = x;
        t->next = NULL;
        t->prior = s;
        s->next = t;
        s = t;
        scanf("%d", &x);
    }

    return L;
}

// 按值查找
DNode *locateElem(DLinkList L, int x) {
    DNode *p = L->next;
    while (p && p->data != x) {
        p = p->next;
    }

    return p;
}

//按位查找
DNode *getElem(DLinkList L, int i) {
    int j = 1;
    DNode *p = L->next;
    if (i == 0) return L;
    if (i < 1) return NULL;

    while (p && j < i) {
        p = p->next;
        j++;
    }

    return p;
}

// 将x插入到双链表L中*p的下一个结点
void insert(DLinkList &L, DNode *p, int x) {
    DNode *t = (DNode *)malloc(sizeof(DNode));
    t->data = x;
    t->next = p->next;
    p->next->prior = t;
    t->prior = p;
    p->next = t;
}

// 删除操作，将双链表中的第i个结点删除
void Delete(DLinkList &L, int i){
    if(i < 1 || i > length(L)) {
        cout << "delete failed: index is wrong." << endl;
        return;
    }

    DNode *p = getElem(L, i-1);
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
}








