#include <stdio.h>
#include <stdlib.h>

// ===== INTERFAZ =====
typedef struct {
    void (*push)(void*, int);
    int (*pop)(void*);
    void (*mostrar)(void*);
    void (*ingresar)(void*);
} IPila;

// ===== ABSTRACTA =====
typedef struct {
    IPila* ops;
} Base;

// ===== NODO =====
typedef struct Nodo {
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
void push(void* obj, int val){
    Pila* p = (Pila*)obj;

    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    if(n == NULL){
        printf("Error: no hay memoria\n");
        return;
    }

    n->dato = val;
    n->sig = p->top;
    p->top = n;
}

// POP
int pop(void* obj){
    Pila* p = (Pila*)obj;

    if(p->top == NULL){
        printf("Pila vacia\n");
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

    Nodo* aux = p->top;

    printf("Pila: ");
    while(aux){
        printf("%d -> ", aux->dato);
        aux = aux->sig;
    }
    printf("NULL\n");
}

// INGRESAR DATOS
void ingresar(void* obj){
    Pila* p = (Pila*)obj;
    int n, valor;

    printf("¿Cuantos elementos deseas ingresar?: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        p->base.ops->push(p, valor);
    }
}

// ===== MAIN =====
int main(){
    IPila ops = {push, pop, mostrar, ingresar};

    Pila p;
    p.base.ops = &ops;
    p.top = NULL;

    // Operaciones
    p.base.ops->ingresar(&p);
    p.base.ops->mostrar(&p);

    printf("Elemento eliminado: %d\n", p.base.ops->pop(&p));

    p.base.ops->mostrar(&p);

    return 0;
}