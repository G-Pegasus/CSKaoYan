#include<bits/stdc++.h>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

// ��ʼ��
void initList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LinkList));
    L->next = NULL;
}

// ��������
void printList(LinkList L) {
    LNode *p = L->next;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// ��������
int length(LinkList L) {
    LNode *p = L->next;
    int len = 0;
    
    while(p) {
        len++;
        p = p->next;
    }

    return len;
}

// ͷ�巨����������
LinkList headInsert(LinkList &L) {
    initList(L); // ��ʼ��
    int x;
    scanf("%d", &x);

    while (x != 9999) {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }

    return L;
}

// ��ֵ���ң�����x��L�е�λ��
LNode *locateElem(LinkList L, int x) {
    LNode *p = L->next;
    while (p && p->data != x) {
        p = p->next;
    }

    return p;
}

// ��λ���ң������ڵ������е�i��λ�õĽ��
LNode *getElem(LinkList L, int i) {
    LNode *p = L->next;

    if (i < 0) return NULL;
    if (i == 0) return L;
    
    for (int j = 1; j < i; j++) p = p->next;

    return p;
}

// ��x���뵽����ĵ�i��λ����
void insert(LinkList &L, int i, int x) {
    LNode *p = getElem(L, i - 1);
    LNode *t = (LNode *)malloc(sizeof(LNode));
    t->data = x;
    t->next = p->next;
    p->next = t;
}

// ɾ����i�����
void deleteElem(LinkList &L, int i) {
    if (i < 1 || i > length(L)) {
        printf("delete wrong.");
        return;
    }

    LNode *p = getElem(L, i - 1);
    LNode *q = p->next;

    p->next = q->next;
    free(q);
}

int main() {
    //��ʼ����ͷ�巨����������
    LinkList L = headInsert(L);
    cout<<"����������Ϊ��";
    printList(L);
    cout<<endl;

    //���룺�ڵڶ���λ�ò����㣬������Ϊ888��������������
    insert(L, 2, 888);
    cout<<"�ڵڶ���λ�ò���888�� ";
    printList(L);
    cout<<endl;

    //ɾ����ɾ�����ĸ����
    deleteElem(L, 4);
    cout<<"ɾ�����ĸ�����";
    printList(L);
    cout<<endl;

    //��λ���ң����ҵ�������㣬��������������ֵ
    LNode *p = getElem(L, 3);
    cout<<"����������ֵΪ��"<<p->data<<endl;

    //��ֵ���ң�����������Ϊ2�Ľ���ָ��
    LNode *q = locateElem(L, 5);
    cout<<"����Ϊ5�Ľ�����һ������ֵΪ��"<<q->next->data<<endl;
    
    //���������ĳ���
    cout<<"������ĳ��ȣ�"<<length(L)<<endl;

    return 0;
}












