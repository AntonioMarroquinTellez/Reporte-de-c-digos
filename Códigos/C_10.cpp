#include <stdio.h>
#include <stdlib.h>

// ===== INTERFAZ =====
typedef struct {
    void (*insertar)(void*, int);
    void (*mostrar)(void*);
    void (*ingresar)(void*);
} ILista;

// ===== ABSTRACTA =====
typedef struct {
    ILista* ops;
} Base;

// ===== NODO =====
typedef struct Nodo {
    int dato;
    struct Nodo* sig;
} Nodo;

// ===== CLASE =====
typedef struct {
    Base base;
    Nodo* head;
} Lista;

// ===== IMPLEMENTACION =====

// INSERTAR AL INICIO
void insertar(void* obj, int val){
    Lista* l = (Lista*)obj;

    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    if(n == NULL){
        printf("Error: no hay memoria\n");
        return;
    }

    n->dato = val;
    n->sig = l->head;
    l->head = n;
}

// INGRESAR DATOS
void ingresar(void* obj){
    Lista* l = (Lista*)obj;
    int n, valor;

    printf("¿Cuantos elementos deseas ingresar?: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        l->base.ops->insertar(l, valor);
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
    while(aux){
        printf("%d -> ", aux->dato);
        aux = aux->sig;
    }
    printf("NULL\n");
}

// ===== MAIN =====
int main(){
    ILista ops = {insertar, mostrar, ingresar};

    Lista l;
    l.base.ops = &ops;
    l.head = NULL;

    // Operaciones
    l.base.ops->ingresar(&l);
    l.base.ops->mostrar(&l);

    return 0;
}