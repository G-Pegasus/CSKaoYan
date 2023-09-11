#include<bits/stdc++.h>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

// ��ʼ��
void initList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
}

// ��������
void printList(LinkList L) {
    LNode *p = L->next;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
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

// β�巨����������
// L[1 2 3 4 5]
void tailInsert(LinkList &L, int enterData[], int length) {
    LNode *pTail = L;
    int i = 0;
    while (i < length) {
        LNode *pNode = (LNode *)malloc(sizeof(LNode));
        pNode->data = enterData[i]; // ���½�㸳ֵ
        pNode->next = pTail->next; // �½�����һ��ָ��β������һ��
        pTail->next = pNode; // β������һ��ָ���½��
        pTail = pNode; // ����β���Ϊ�²���Ľ��
        i++;
    }
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






// �ݹ�ʵ�֣��������е��������
int listMax(LinkList p) {
    if (p == NULL) return -9999;
    int temp = listMax(p->next);
    return p->data > temp ? p->data : temp;
}

// �ݹ�ʵ�֣��������еĽ����
int listLength(LinkList p) {
    if (p == NULL) return 0;
    return listLength(p->next) + 1;
}

// �ݹ�ʵ�֣�����������Ԫ�ص�ƽ��ֵ
double listSum(LinkList p) {
    if (p == NULL) return 0;
    return (double)p->data + listSum(p->next);
}

// ��������ʵ�i�����ݽ��
int getIthNode(LinkList p, int i) {
    if (p == NULL) return -1;
    int cur = 0;
    i--;
    LinkList temp = p;
    while (cur < i) {
        if (temp->next != NULL) temp = temp->next;
        else {
            printf("����ʧ�ܣ� ");
            return -1;
        }
        cur++;
    }

    return temp->data;
}

// �ڵ�i�����ǰ����Ԫ��
void insertIth(LinkList &L, int i, int e) {
    LNode *t1 = getElem(L, i - 1);
    LNode *t2 = t1->next;
    LNode *n = (LNode *)malloc(sizeof(LNode));
    n->data = e;
    t1->next = n;
    n->next = t2;
}

// ���ҵ�����m��λ�õ�Ԫ��
int getLastM(LinkList &L, int m) {
    return 0;
}




int main() {
    //��ʼ����ͷ�巨����������
    int l1[] = {1, 2, 3, 4, 5};
    LinkList L1;
    initList(L1);
    tailInsert(L1, l1, 5);
    cout<<"����������Ϊ��";
    printList(L1);

    // �ݹ������ֵ
    printf("��������ֵ�ǣ�%d\n", listMax(L1->next));

    // �ݹ�����������
    int length = listLength(L1->next);
    printf("�����еĽ�����ǣ�%d\n", length);

    // �ݹ�����������Ԫ��ƽ��ֵ
    printf("����Ԫ�ص�ƽ��ֵΪ��%.1f\n", listSum(L1->next) / length);

    // ���ʵ�i�����
    printf("�����е�i�����Ϊ��%d\n", getIthNode(L1->next, 2));

    // �ڵ�i�����ǰ����Ԫ��
    insertIth(L1, 2, 6);
    printList(L1);

    return 0;
}












