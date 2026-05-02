#include <stdio.h>
#include <stdlib.h>

// ===== INTERFAZ =====
typedef struct{
    void (*ingresar)(void*);
    void (*insertarInicio)(void*, int);
    void (*mostrar)(void*);
} ILista;

// ===== ABSTRACTA =====
typedef struct{
    ILista* ops;
} Base;

// ===== NODO =====
typedef struct Nodo{
    int dato;
    struct Nodo* sig;
} Nodo;

// ===== CLASE =====
typedef struct{
    Base base;
    Nodo* head;
} Lista;

// ===== IMPLEMENTACION =====

// INSERTAR AL INICIO
void insertarInicio(void* obj, int v){
    Lista* l = (Lista*)obj;

    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    if(n == NULL){
        printf("Error: no hay memoria\n");
        return;
    }

    n->dato = v;
    n->sig = l->head;
    l->head = n;
}

// INGRESAR DATOS
void ingresar(void* obj){
    Lista* l = (Lista*)obj;
    int n, valor;

    printf("¿Cuantos datos deseas ingresar?: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Dato %d: ", i + 1);
        scanf("%d", &valor);
        l->base.ops->insertarInicio(l, valor);
    }
}

// MOSTRAR LISTA
void mostrar(void* obj){
    Lista* l = (Lista*)obj;

    if(l->head == NULL){
        printf("Lista vacia\n");
        return;
    }

    Nodo* aux = l->head;

    printf("Lista: ");
    while(aux != NULL){
        printf("%d -> ", aux->dato);
        aux = aux->sig;
    }
    printf("NULL\n");
}

// ===== MAIN =====
int main(){
    ILista ops = {ingresar, insertarInicio, mostrar};

    Lista l;
    l.base.ops = &ops;
    l.head = NULL;

    // Operaciones
    l.base.ops->ingresar(&l);
    l.base.ops->mostrar(&l);

    return 0;
}