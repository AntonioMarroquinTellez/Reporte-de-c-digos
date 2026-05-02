#include <stdio.h>

#define MAX 10

// INTERFAZ
typedef struct {
    void (*insertar)(void*, int);
    void (*mostrar)(void*);
} IADT;

// ABSTRACTA
typedef struct {
    IADT* ops;
} Base;

// CLASE
typedef struct {
    Base base;
    int data[MAX];
    int size;
} ADT;

// IMPLEMENTACION
void insertar(void* obj, int v){
    ADT* a = (ADT*)obj;

    if(a->size < MAX){
        a->data[a->size++] = v;
    } else {
        printf("Error: estructura llena\n");
    }
}

void mostrar(void* obj){
    ADT* a = (ADT*)obj;

    if(a->size == 0){
        printf("Estructura vacia\n");
        return;
    }

    for(int i = 0; i < a->size; i++)
        printf("%d ", a->data[i]);
    printf("\n");
}

// MAIN
int main(){
    IADT ops = {insertar, mostrar};

    ADT a;
    a.base.ops = &ops;
    a.size = 0;

    a.base.ops->insertar(&a, 5);
    a.base.ops->insertar(&a, 10);
    a.base.ops->mostrar(&a);

    return 0;
}