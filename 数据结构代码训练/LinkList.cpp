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

void printList2(LinkList L) {
    while(L) {
        printf("%d ", L->data);
        L = L->next;
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
// L[1 6 2 3 4 5]
int getLastM(LinkList L, int m) {
    LNode *fore = L;
    int count = 1;
    while (count != m) {
        count++;
        fore = fore->next;
    }

    LNode *last = L;
    while (fore->next != NULL) {
        fore = fore->next;
        last = last->next;
    }

    return last->data;
}


// ��λ���ң������ڵ������е�i��λ�õĽ��
LNode *getElem2(LinkList L, int i) {

    if (i < 0) return NULL;
    if (i == 0) return L;
    
    for (int j = 1; j < i; j++) L = L->next;

    return L;
}

// ��La��ɾ����j��Ԫ�ؿ�ʼ�Ĺ�len��Ԫ��
// ������len��Ԫ�ز��뵽��Lb�е�j��Ԫ��ǰ
// La[1 6 2 3 4 5]  Lb[2 5 7 9 10] (j = 3, len = 2)
void operateLinkList(LinkList &La, LinkList &Lb, int j, int len) {
    LNode *La2 = getElem2(La, j + len); // �ҵ�Ҫɾ��������һ�����
    LNode *La1 = getElem2(La, j - 1); // �ҵ�Ҫɾ��������һ�����
    
    LNode *LaDel = La1->next; // ȡ��Ҫɾ�������ĵ�һ�����
    
    int count = len - 1;  // �ƶ���Ҫɾ�����������һ��Ԫ�أ�����ļ���
    LNode *LaInsert = LaDel;
    while (count > 0) {
        count--;
        LaInsert = LaInsert->next; 
    }
    LaInsert->next = NULL; // �ҵ�Ҫɾ���������һ����㣬���������Ľ���ÿա���ʱ��LaDel����Ҫɾ������

    LNode *LbNew = getElem2(Lb, j - 1); // �ҵ�Lb�е� j-1 ��Ԫ�أ�Ҫ��������ĺ������LaDel
    LaInsert->next = LbNew->next;
    LbNew->next = LaDel;

    La1->next = La2; // ɾ��La�е���
}

// �ӷǵݼ�����ĵ�������ɾ��ֵ��ͬ�Ķ���Ԫ��
// L[1 2 2 3 5 5]
void delSimilar(LinkList &L) {
    LNode *temp = L->next;
    while (temp && temp->next) {
        if (temp->next->data == temp->data) {
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
}

// ��һ�������б�xС��Ԫ������
// L[1 2 2 3 5 5] (x = 4)
int lessThanXCnt(LinkList L, int x) {
    int cnt = 0;
    LNode *temp = L->next;
    
    int num = -999;
    while (temp->next) {
        if (temp->data < x && temp->data != num) {
            cnt++;
            num = temp->data;
        }
        temp = temp->next;
    }
    
    return cnt;
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

    // ���������е�����m�����
    printf("�����е�����m�����Ϊ��%d\n", getLastM(L1, 3));

    // ��La��ɾ����j��Ԫ�ؿ�ʼ�Ĺ�len��Ԫ��
    // ������len��Ԫ�ز��뵽��Lb�е�j��Ԫ��ǰ
    // La[1 6 2 3 4 5]  Lb[2 5 7 9 10] (j = 3, len = 2)
    int l2[] = {2, 5, 7, 9, 10};
    LinkList L2;
    initList(L2);
    tailInsert(L2, l2, 5);
    operateLinkList(L1->next, L2->next, 3, 2);
    printList(L1);
    printList(L2);

    
    int l3[] = {1, 2, 2, 3, 5, 5};
    LinkList L3;
    initList(L3);
    tailInsert(L3, l3, 6);

    // ��һ�������б�xС��Ԫ������
    printf("�����б�xС��Ԫ������Ϊ��%d\n", lessThanXCnt(L3, 4));

    // �ӷǵݼ�����ĵ�������ɾ��ֵ��ͬ�Ķ���Ԫ��
    delSimilar(L3);
    printf("ɾ����������ͬ�Ķ���Ԫ�أ�");
    printList(L3);

    return 0;
}












