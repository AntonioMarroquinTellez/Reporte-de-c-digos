#include <stdio.h>
#include <stdlib.h>

// ===== INTERFAZ =====
typedef struct {
    void (*enqueue)(void*, int);
    int (*dequeue)(void*);
    void (*mostrar)(void*);
} ICola;

// ===== ABSTRACTA =====
typedef struct {
    ICola* ops;
} Base;

// ===== NODO =====
typedef struct Nodo{
    int dato;
    struct Nodo* sig;
} Nodo;

// ===== CLASE =====
typedef struct {
    Base base;
    Nodo *f, *r;  // frente y final
} Cola;

// ===== IMPLEMENTACION =====

// ENQUEUE
void enqueue(void* obj, int v){
    Cola* c = (Cola*)obj;

    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    if(n == NULL){
        printf("Error: no hay memoria\n");
        return;
    }

    n->dato = v;
    n->sig = NULL;

    if(c->r == NULL){ // cola vacia
        c->f = c->r = n;
    } else {
        c->r->sig = n;
        c->r = n;
    }

    printf("Se inserto: %d\n", v);
}

// DEQUEUE
int dequeue(void* obj){
    Cola* c = (Cola*)obj;

    if(c->f == NULL){
        printf("Error: cola vacia\n");
        return -1;
    }

    Nodo* t = c->f;
    int v = t->dato;

    c->f = t->sig;

    // 🔥 si queda vacia, también resetear r
    if(c->f == NULL){
        c->r = NULL;
    }

    free(t);
    return v;
}

// MOSTRAR
void mostrar(void* obj){
    Cola* c = (Cola*)obj;

    if(c->f == NULL){
        printf("Cola vacia\n");
        return;
    }

    printf("Contenido de la cola: ");
    Nodo* aux = c->f;

    while(aux != NULL){
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

// ===== MAIN =====
int main(){
    ICola ops = {enqueue, dequeue, mostrar};

    Cola c;
    c.base.ops = &ops;
    c.f = c.r = NULL;

    // Operaciones
    c.base.ops->enqueue(&c, 1);
    c.base.ops->enqueue(&c, 2);
    c.base.ops->enqueue(&c, 3);

    c.base.ops->mostrar(&c);

    printf("Se elimino: %d\n", c.base.ops->dequeue(&c));

    c.base.ops->mostrar(&c);

    return 0;
}