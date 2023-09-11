#include<bits/stdc++.h>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

// 初始化
void initList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
}

// 遍历操作
void printList(LinkList L) {
    LNode *p = L->next;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 求链表长度
int length(LinkList L) {
    LNode *p = L->next;
    int len = 0;
    
    while(p) {
        len++;
        p = p->next;
    }

    return len;
}

// 头插法建立单链表
LinkList headInsert(LinkList &L) {
    initList(L); // 初始化
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

// 尾插法建立单链表
// L[1 2 3 4 5]
void tailInsert(LinkList &L, int enterData[], int length) {
    LNode *pTail = L;
    int i = 0;
    while (i < length) {
        LNode *pNode = (LNode *)malloc(sizeof(LNode));
        pNode->data = enterData[i]; // 给新结点赋值
        pNode->next = pTail->next; // 新结点的下一个指向尾结点的下一个
        pTail->next = pNode; // 尾结点的下一个指向新结点
        pTail = pNode; // 更新尾结点为新插入的结点
        i++;
    }
}

// 按值查找，查找x在L中的位置
LNode *locateElem(LinkList L, int x) {
    LNode *p = L->next;
    while (p && p->data != x) {
        p = p->next;
    }

    return p;
}

// 按位查找，查找在单链表中第i个位置的结点
LNode *getElem(LinkList L, int i) {
    LNode *p = L->next;

    if (i < 0) return NULL;
    if (i == 0) return L;
    
    for (int j = 1; j < i; j++) p = p->next;

    return p;
}

// 将x插入到链表的第i个位置上
void insert(LinkList &L, int i, int x) {
    LNode *p = getElem(L, i - 1);
    LNode *t = (LNode *)malloc(sizeof(LNode));
    t->data = x;
    t->next = p->next;
    p->next = t;
}

// 删除第i个结点
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






// 递归实现：求链表中的最大整数
int listMax(LinkList p) {
    if (p == NULL) return -9999;
    int temp = listMax(p->next);
    return p->data > temp ? p->data : temp;
}

// 递归实现：求链表中的结点数
int listLength(LinkList p) {
    if (p == NULL) return 0;
    return listLength(p->next) + 1;
}

// 递归实现：求链表所有元素的平均值
double listSum(LinkList p) {
    if (p == NULL) return 0;
    return (double)p->data + listSum(p->next);
}

// 单链表访问第i个数据结点
int getIthNode(LinkList p, int i) {
    if (p == NULL) return -1;
    int cur = 0;
    i--;
    LinkList temp = p;
    while (cur < i) {
        if (temp->next != NULL) temp = temp->next;
        else {
            printf("访问失败！ ");
            return -1;
        }
        cur++;
    }

    return temp->data;
}

// 在第i个结点前插入元素
void insertIth(LinkList &L, int i, int e) {
    LNode *t1 = getElem(L, i - 1);
    LNode *t2 = t1->next;
    LNode *n = (LNode *)malloc(sizeof(LNode));
    n->data = e;
    t1->next = n;
    n->next = t2;
}

// 查找倒数第m个位置的元素
int getLastM(LinkList &L, int m) {
    return 0;
}




int main() {
    //初始化，头插法建立单链表
    int l1[] = {1, 2, 3, 4, 5};
    LinkList L1;
    initList(L1);
    tailInsert(L1, l1, 5);
    cout<<"建立的链表为：";
    printList(L1);

    // 递归求最大值
    printf("链表的最大值是：%d\n", listMax(L1->next));

    // 递归求链表结点数
    int length = listLength(L1->next);
    printf("链表中的结点数是：%d\n", length);

    // 递归求链表所有元素平均值
    printf("链表元素的平均值为：%.1f\n", listSum(L1->next) / length);

    // 访问第i个结点
    printf("链表中第i个结点为：%d\n", getIthNode(L1->next, 2));

    // 在第i个结点前插入元素
    insertIth(L1, 2, 6);
    printList(L1);

    return 0;
}












