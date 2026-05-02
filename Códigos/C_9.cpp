#include <stdio.h>
#include <stdlib.h>

// ===== INTERFAZ =====
typedef struct {
    void (*enqueue)(void*, int);
    int (*dequeue)(void*);
    void (*mostrar)(void*);
    void (*ingresar)(void*);
} ICola;

// ===== ABSTRACTA =====
typedef struct {
    ICola* ops;
} Base;

// ===== NODO =====
typedef struct Nodo {
    int dato;
    struct Nodo* sig;
} Nodo;

// ===== CLASE =====
typedef struct {
    Base base;
    Nodo *front, *rear;
} Cola;

// ===== IMPLEMENTACION =====

// ENQUEUE
void enqueue(void* obj, int val){
    Cola* c = (Cola*)obj;

    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    if(n == NULL){
        printf("Error: no hay memoria\n");
        return;
    }

    n->dato = val;
    n->sig = NULL;

    if(c->rear == NULL){
        c->front = c->rear = n;
    } else {
        c->rear->sig = n;
        c->rear = n;
    }
}

// DEQUEUE
int dequeue(void* obj){
    Cola* c = (Cola*)obj;

    if(c->front == NULL){
        printf("Cola vacia\n");
        return -1;
    }

    Nodo* t = c->front;
    int v = t->dato;

    c->front = t->sig;

    if(c->front == NULL)
        c->rear = NULL;

    free(t);
    return v;
}

// MOSTRAR
void mostrar(void* obj){
    Cola* c = (Cola*)obj;

    if(c->front == NULL){
        printf("Cola vacia\n");
        return;
    }

    Nodo* aux = c->front;

    printf("Cola: ");
    while(aux){
        printf("%d -> ", aux->dato);
        aux = aux->sig;
    }
    printf("NULL\n");
}

// INGRESAR DATOS
void ingresar(void* obj){
    Cola* c = (Cola*)obj;
    int n, valor;

    printf("¿Cuantos elementos deseas ingresar?: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        c->base.ops->enqueue(c, valor);
    }
}

// ===== MAIN =====
int main(){
    ICola ops = {enqueue, dequeue, mostrar, ingresar};

    Cola c;
    c.base.ops = &ops;
    c.front = c.rear = NULL;

    // Operaciones
    c.base.ops->ingresar(&c);
    c.base.ops->mostrar(&c);

    printf("Elemento eliminado: %d\n", c.base.ops->dequeue(&c));

    c.base.ops->mostrar(&c);

    return 0;
}