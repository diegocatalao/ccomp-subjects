#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

typedef struct sNo {
    int value;
    struct sNo *pNext;
} No;

/******************************************************************************/

int A(int a, int b) {
    if (a < b)
        return A(b, a);
    else if (b != 0)
        return (a + A(a, b - 1));
    else
        return 0;
}

BOOL B(int list[], int n) {
    if (n == 1 || n == 0)
        return TRUE;
    if (list[n - 1] < list[n - 2])
        return FALSE;
    return B(list, n - 1);
}

void C(No *pNode, int *MSeqIni, int *MSeq) {
    if (pNode->pNext == NULL)
        return;
    if (pNode->pNext->value < pNode->value) {
        *MSeqIni++;
    }

    printf("%d\n", pNode->value);
    return C(pNode->pNext, MSeqIni, MSeq);
}

void No_append(No *pNode, int value) {
    No *pNewNode = (No*) malloc(sizeof(No));

    pNewNode->pNext = pNode->pNext;
    pNode->pNext = pNewNode;
    pNewNode->value = value;
}

int main(int argc, char *argv[]) {

    // int a, b;
    // printf("Valor de a: ");
    // scanf("%d", &a);
    // printf("Valor de b: ");
    // scanf("%d", &b);

    // printf("a*b: %d\n", A(a, b));

    // int ordered[] = { 1, 2, 3, 4, 5};
    // int notOrdered[] = { 2, 1, 3, 4, 5};
    // printf("lista 1: %d\n", B(ordered, sizeof(ordered)/sizeof(ordered[0])));
    // printf("lista 2: %d\n", B(notOrdered, sizeof(notOrdered)/sizeof(notOrdered[0])));

    No *pNode = (No *) malloc(sizeof(No));
    int MSeqIni = 0, MSeq = 0;

    // int list[] = {1, 3, 5, 2, 3, 4, 5, 6, 1, 2, 3, 4};
    int list[] = {4, 3, 2, 1, 6, 5, 4, 3, 2, 5, 3, 1};
    for (int i = 0; i < sizeof(list)/sizeof(list[0]); i++)
        No_append(pNode, list[i]);

    C(pNode, &MSeqIni, &MSeq);
    printf("MSeqIni: %d\n", MSeqIni);
    printf("MSeq: %d\n", MSeq);

    return 0;
}