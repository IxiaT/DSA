#include <stdio.h>
#include <stdlib.h>

#define MAX 0XA

//ADT version 1
typedef struct{
    char elem [MAX];
    int count;
}LIST;

void init(LIST *A);
void insertSorted(LIST *A, char new);
void deleteByPos(LIST *A, int pos);
void deleteByElem(LIST *A, char elem);
void deleteOccurances(LIST *A, char elem);
void makenull(LIST *A);
int locate(LIST A, char elem);
void display(LIST A);
char retrieve(LIST A, int pos);

int main(){
    LIST L;
    
    init(&L);
    insertSorted(&L, 'b');
    insertSorted(&L, 'c');
    insertSorted(&L, 'a');
    insertSorted(&L, 'd');
    insertSorted(&L, 'e');
    display(L);
    printf("\n");
    deleteByPos(&L, 3);
    display(L);
    printf("\n");
    deleteByElem(&L, 'b');
    display(L);
    printf("\n");
    int pos = locate(L, 'e');
    printf("%d\n", pos);
    int elem = retrieve(L, 3);
    printf("%c", elem);

}

void init(LIST *A){
    A->count = 0;
}

void insertSorted(LIST *A, char new){
    if(A->count!=MAX){
        int x, y;
        for(x=0; x<A->count && new>A->elem[x]; x++){}
        if(x<A->count){
            for(y=A->count; y>x; y--){
                A->elem[y] = A->elem[y-1];
            }
        }
        A->elem[x]=new;
        A->count++;
    }
}

void deleteByPos(LIST *A, int pos){
    int x;
    for(x=pos; x<A->count-1; x++){
        A->elem[x]=A->elem[x+1];
    }
    A->count--;
}

void deleteByElem(LIST *A, char elem){
    int x;
    for(x = 0; x<A->count && A->elem[x] < elem; x++){}
    if(x==A->count){
        printf("Element not found");
    }else{
    while(x<A->count){
        A->elem[x]=A->elem[x+1];
        x++;
    }
    A->count--;
    }
}

//void deleteOccurances(LIST *A, char elem){

//}

void makenull(LIST *A){
    A->count = 0;
}

int locate(LIST A, char elem){
    int pos;
    for(pos = 0; pos<A.count && A.elem[pos] <= elem; pos++){}
    return pos;
}

void display(LIST A){
    int x;
    for(x=0; x<A.count; x++){
        printf("%c \n", A.elem[x]);
    }
}

char retrieve(LIST A, int pos){
    return A.elem[pos];
}
