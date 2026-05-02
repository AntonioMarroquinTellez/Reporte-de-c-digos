#include <stdio.h>

#define MAX 5

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

// ===== CLASE =====
typedef struct {
    Base base;
    int arr[MAX];
    int top;  // índice del último elemento
} Pila;

// ===== IMPLEMENTACION =====

// PUSH: insertar elemento en la pila
void push(void* obj, int v){
    Pila* p = (Pila*)obj;

    if(p->top == MAX - 1){
        printf("Error: pila llena\n");
        return;
    }

    p->top++;
    p->arr[p->top] = v;

    printf("Se inserto: %d\n", v);
}

// POP: eliminar elemento de la pila
int pop(void* obj){
    Pila* p = (Pila*)obj;

    if(p->top == -1){
        printf("Error: pila vacia\n");
        return -1;
    }

    int valor = p->arr[p->top];
    p->top--;

    return valor;
}

// MOSTRAR: ver contenido de la pila
void mostrar(void* obj){
    Pila* p = (Pila*)obj;

    if(p->top == -1){
        printf("Pila vacia\n");
        return;
    }

    printf("Contenido de la pila: ");
    for(int i = p->top; i >= 0; i--){
        printf("%d ", p->arr[i]);
    }
    printf("\n");
}

// ===== MAIN =====
int main(){
    IPila ops = {push, pop, mostrar};

    Pila p;
    p.base.ops = &ops;
    p.top = -1; // pila inicia vacia

    // Operaciones
    p.base.ops->push(&p, 1);
    p.base.ops->push(&p, 2);
    p.base.ops->push(&p, 3);

    p.base.ops->mostrar(&p);

    printf("Elemento eliminado: %d\n", p.base.ops->pop(&p));

    p.base.ops->mostrar(&p);

    return 0;
}