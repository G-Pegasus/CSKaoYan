#include <stdio.h>
#include <stdlib.h>
#define InitSize 10

typedef struct {
    int *data;
    int length;
    int maxSize;
}SqList;

void initList(SqList &L) {
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.maxSize = InitSize;
    L.length = 0;
}

void increaseSize(SqList &L, int len) {
    int *p = L.data;
    L.data = (int *)malloc((InitSize + len) * sizeof(int));
    L.maxSize += len;
    
    for (int i = 0; i < L.maxSize; i++) {
        L.data[i] = p[i];
    }

    free(p);
}

void listInsert(SqList &L, int i, int e) {
    if (i < 0 || i >= L.length + 1) {
        printf("insert fail.\n");
        return;
    }
    if (L.length >= L.maxSize) 
        increaseSize(L, 10);
    for (int j = L.length; j > i; j--) {
        L.data[j] = L.data[j - 1];
    }

    L.data[i] = e;
    L.length++;
}

int listDelete(SqList &L, int i) {
    int e;
    if (i < 0 || i >= L.length + 1) {
        printf("delete fail.");
    } else {
        e = L.data[i - 1];
        for (int j = i - 1; j < L.length - 1; j++) {
            L.data[j] = L.data[j + 1];
        }
    }
    L.length--;
    return e;
}

void printList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }

    printf("\n");
}

// 过滤法，删除顺序表[a, b]区间的数
void deleteElem1(int a, int b, SqList &L) {
    int currlength = 0;

    for (int i = 0; i < L.length; i++) {
        if (L.data[i] < a || L.data[i] > b) {
            L.data[currlength] = L.data[i];
            currlength++;
        }
    }

    L.length = currlength;
}

// 偏移法，在非递减顺序表中删除区间[a, b]的数 [0 1 2 3 4 5 6 7 8 9]
int deleteElem2(int a, int b, SqList &L) {
    int aIndex = -1;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] >= a && L.data[i] <= b) {
            aIndex = i;
            break;
        }   
    }

    if (aIndex == -1) return 0;

    int bIndex = -1;
    for (int i = L.length - 1; i >= 0; i--) {
        if (L.data[i] >= a && L.data[i] <= b) {
            bIndex = i;
            break;
        }
    }

    if (bIndex == -1) return 0;

    int d = bIndex - aIndex + 1;
    for (int i = bIndex + 1; i < L.length; i++) 
        L.data[i - d] = L.data[i]; 
    
    L.length -= d;
    return 1;
}

// 删除非递减顺序表L中的重复元素 [1 2 2 3 3 3 4 5 6]
void deleteRepeat(SqList &L) {
    int cur = 0;
    for (int i = 0; i < L.length; i++) {
        if (cur == 0 || L.data[i] != L.data[cur - 1]) {
            L.data[cur] = L.data[i];
            cur++;
        }
    }

    L.length = cur;
}

// 一个非递减顺序表A[1,3,6,7]，一个非递增顺序表B[8,5,4,2]。将这两个顺序表合并为一个递增顺序表C
void combine1(SqList La, SqList Lb, SqList &Lc) {
    Lc.data = (int *)malloc((La.length + Lb.length) * sizeof(int));
    Lc.length = La.length + Lb.length;
    int a = 0, b = Lb.length - 1;
    int cur = 0;
    
    while (a < La.length && b >= 0) {
        if (La.data[a] < Lb.data[b]) {
            Lc.data[cur] = La.data[a];
            a++;
        } else {
            Lc.data[cur] = Lb.data[b];
            b--;
        }
        cur++;
    }

    while (a < La.length) {
        Lc.data[cur] = La.data[a];
        cur++;
        a++;
    }

    while (b >= 0) {
        Lc.data[cur] = Lb.data[b];
        cur++;
        b--;
    }
}

// 接上，表A有m+n个存储空间，将A、B两表合并，所有元素都存储到A中
// A[1,3,6,7]    B[8,5,4,2]
void combine2(SqList &La, SqList &Lb) {
    int oldALen = La.length;
    La.length += Lb.length;
    int cur = La.length - 1;
    int indexA = oldALen - 1, indexB = 0;

    while (indexA >= 0 && indexB < Lb.length) {
        if (La.data[indexA] < Lb.data[indexB]) {
            La.data[cur] = Lb.data[indexB];
            cur--;
            indexB++;
        } else {
            La.data[cur] = La.data[indexA];
            cur--;
            indexA--;
        }
    }

    while (indexA >= 0) { // A中还有元素剩余
        La.data[cur] = La.data[indexA];
        cur--;
        indexA--;
    }

    while (indexB < Lb.length) {
        La.data[cur] = Lb.data[indexB];
        cur--;
        indexB++;
    }
}

// 接上，表A前r个元素递增有序，而表A中后n-r个元素递减有序，将表A进行排序
// A[1,3,4,13, 10,9,7,5]
void sortA(SqList &La, int r) {
    int count = r;
    while (count < La.length) {
        int temp = La.data[count];
        int i;
        for (i = count - 1; i >= 0; i--) {
            if (La.data[i] > temp) {
                La.data[i + 1] = La.data[i];
            } else {
                break;
            }
        }
        La.data[i + 1] = temp;
        count++;
    }
}

// 两个升序顺序表La Lb，求La和Lb的交集
// La[1 3 4 7]   Lb[1 2 4 9]
void commonAB(SqList &La, SqList &Lb) {
    int indexA = 0, indexB = 0;
    int cur = 0;
    while (indexA < La.length && indexB < Lb.length) {
        if (La.data[indexA] == Lb.data[indexB]) {
            La.data[cur] = La.data[indexA];
            indexA++;
            indexB++;
            cur++;
        } else if (La.data[indexA] > Lb.data[indexB]) {
            indexB++;
        } else {
            indexA++;
        }
    }
    La.length = cur;
}


// 接上，求A-B，即差集
// La[1 3 4 7]   Lb[1 2 4 9]
void except(SqList &La, SqList &Lb) {
    int cur = 0;
    int indexA = 0, indexB = 0;
    while (indexA < La.length && indexB < Lb.length) {
        if (La.data[indexA] == Lb.data[indexB]) {
            
        }
    }
}


int main() {
    SqList L;
    initList(L);
    listInsert(L, 0, 1);
    listInsert(L, 1, 2);
    listInsert(L, 2, 3);
    listInsert(L, 3, 4);
    listInsert(L, 4, 5);
    listInsert(L, 5, 6);
    listInsert(L, 6, 7);
    listInsert(L, 7, 8);
    listInsert(L, 8, 9);
    listInsert(L, 9, 10);
    listInsert(L, 10, 11);

    listDelete(L, 2);

    printList(L);

    deleteElem1(3, 5, L);
    printList(L);
    
    deleteElem2(3, 5, L);
    printList(L);

    SqList L1;
    initList(L1);
    listInsert(L1, 0, 1); listInsert(L1, 1, 3); listInsert(L1, 2, 3);
    listInsert(L1, 3, 6); listInsert(L1, 4, 7); listInsert(L1, 5, 7); 
    deleteRepeat(L1);
    printf("删除有序表中重复的元素：");
    printList(L1);

    SqList L2, L3;
    initList(L2);
    listInsert(L2, 0, 8); listInsert(L2, 1, 5); listInsert(L2, 2, 4); listInsert(L2, 3, 2);
    combine1(L1, L2, L3);
    printf("合并两个有序顺序表:");
    printList(L3);

    combine2(L1, L2);
    printf("将B中的元素移到A中，并保持升序：");
    printList(L1);

    // L4[1,3,4,10, 13,9,7,5]
    SqList L4;
    initList(L4);
    listInsert(L4, 0, 1); listInsert(L4, 1, 3); listInsert(L4, 2, 4); listInsert(L4, 3, 13);
    listInsert(L4, 4, 10); listInsert(L4, 5, 9); listInsert(L4, 6, 7); listInsert(L4, 7, 5);
    sortA(L4, 4);
    printf("A前r个递增，后n-r个递减，对A进行排序：");
    printList(L4);

    // La[1 3 4 7]   Lb[1 2 4 9]
    SqList L5, L6;
    initList(L5); initList(L6);
    listInsert(L5, 0, 1); listInsert(L5, 1, 3); listInsert(L5, 2, 4); listInsert(L5, 3, 7);
    listInsert(L6, 0, 1); listInsert(L6, 1, 2); listInsert(L6, 2, 4); listInsert(L6, 3, 9);
    commonAB(L5, L6);
    printf("求两个升序表的交集：");
    printList(L5);

    return 0;
}