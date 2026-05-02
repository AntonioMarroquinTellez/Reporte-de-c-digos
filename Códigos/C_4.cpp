#include <stdio.h>

#define MAX 5

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

// ===== CLASE =====
typedef struct {
    Base base;
    int arr[MAX];
    int f, r;  // f = frente, r = final
} Cola;

// ===== IMPLEMENTACION =====

// INSERTAR (enqueue)
void enqueue(void* obj, int v){
    Cola* c = (Cola*)obj;

    if(c->r == MAX - 1){
        printf("Error: cola llena\n");
        return;
    }

    c->arr[++c->r] = v;
    printf("Se inserto: %d\n", v);
}

// ELIMINAR (dequeue)
int dequeue(void* obj){
    Cola* c = (Cola*)obj;

    if(c->f > c->r){
        printf("Error: cola vacia\n");
        return -1;
    }

    int valor = c->arr[c->f];
    c->f++;

    return valor;
}

// MOSTRAR
void mostrar(void* obj){
    Cola* c = (Cola*)obj;

    if(c->f > c->r){
        printf("Cola vacia\n");
        return;
    }

    printf("Contenido de la cola: ");
    for(int i = c->f; i <= c->r; i++){
        printf("%d ", c->arr[i]);
    }
    printf("\n");
}

// ===== MAIN =====
int main(){
    ICola ops = {enqueue, dequeue, mostrar};

    Cola c;
    c.base.ops = &ops;
    c.f = 0;
    c.r = -1;

    // Operaciones
    c.base.ops->enqueue(&c, 10);
    c.base.ops->enqueue(&c, 20);
    c.base.ops->enqueue(&c, 30);

    c.base.ops->mostrar(&c);

    printf("Se elimino: %d\n", c.base.ops->dequeue(&c));

    c.base.ops->mostrar(&c);

    return 0;
}