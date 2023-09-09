#include<bits/stdc++.h>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

// 初始化
void initList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LinkList));
    L->next = NULL;
}

// 遍历操作
void printList(LinkList L) {
    LNode *p = L->next;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
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

int main() {
    //初始化，头插法建立单链表
    LinkList L = headInsert(L);
    cout<<"建立的链表为：";
    printList(L);
    cout<<endl;

    //插入：在第二个位置插入结点，数据域为888，并遍历单链表
    insert(L, 2, 888);
    cout<<"在第二个位置插入888： ";
    printList(L);
    cout<<endl;

    //删除：删除第四个结点
    deleteElem(L, 4);
    cout<<"删除第四个结点后：";
    printList(L);
    cout<<endl;

    //按位查找：查找第三个结点，并输出其数据域的值
    LNode *p = getElem(L, 3);
    cout<<"第三个结点的值为："<<p->data<<endl;

    //按值查找：查找数据域为2的结点的指针
    LNode *q = locateElem(L, 5);
    cout<<"数据为5的结点的下一个结点的值为："<<q->next->data<<endl;
    
    //输出单链表的长度
    cout<<"单链表的长度："<<length(L)<<endl;

    return 0;
}












