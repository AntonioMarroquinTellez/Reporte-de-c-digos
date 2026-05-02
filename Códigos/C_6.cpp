#include <stdio.h>
#include <stdlib.h>

// ===== INTERFAZ =====
typedef struct {
    void (*push)(void*, int);
    int (*pop)(void*);
    void (*mostrar)(void*);
} IPila;

// ===== ABSTRACTA =====
typedef struct {
    IPila* ops;
} Base;

// ===== NODO =====
typedef struct Nodo{
    int dato;
    struct Nodo* sig;
} Nodo;

// ===== CLASE =====
typedef struct {
    Base base;
    Nodo* top;
} Pila;

// ===== IMPLEMENTACION =====

// PUSH
void push(void* obj, int v){
    Pila* p = (Pila*)obj;

    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    if(n == NULL){
        printf("Error: no hay memoria disponible\n");
        return;
    }

    n->dato = v;
    n->sig = p->top;
    p->top = n;

    printf("Se inserto: %d\n", v);
}

// POP
int pop(void* obj){
    Pila* p = (Pila*)obj;

    if(p->top == NULL){
        printf("Error: pila vacia\n");
        return -1;
    }

    Nodo* t = p->top;
    int v = t->dato;

    p->top = t->sig;
    free(t);

    return v;
}

// MOSTRAR
void mostrar(void* obj){
    Pila* p = (Pila*)obj;

    if(p->top == NULL){
        printf("Pila vacia\n");
        return;
    }

    printf("Contenido de la pila: ");
    Nodo* aux = p->top;

    while(aux != NULL){
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

// ===== MAIN =====
int main(){
    IPila ops = {push, pop, mostrar};

    Pila p;
    p.base.ops = &ops;
    p.top = NULL;

    // Operaciones
    p.base.ops->push(&p, 5);
    p.base.ops->push(&p, 10);
    p.base.ops->push(&p, 15);

    p.base.ops->mostrar(&p);

    printf("Se elimino: %d\n", p.base.ops->pop(&p));

    p.base.ops->mostrar(&p);

    return 0;
}