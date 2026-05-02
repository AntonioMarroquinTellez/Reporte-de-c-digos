#include <stdio.h>

#define MAX 5

// ===== INTERFAZ =====
typedef struct {
    void (*ingresar)(void*);
    void (*mostrar)(void*);
} ILista;

// ===== ABSTRACTA =====
typedef struct {
    ILista* ops;
} Base;

// ===== CLASE =====
typedef struct {
    Base base;
    int arr[MAX];
    int size;
} Lista;

// ===== IMPLEMENTACION =====

// INGRESAR datos
void ingresar(void* obj){
    Lista* l = (Lista*)obj;

    printf("¿Cuantos numeros deseas ingresar? (max %d): ", MAX);
    scanf("%d", &l->size);

    if(l->size > MAX){
        printf("Excede el limite. Se ajustara a %d\n", MAX);
        l->size = MAX;
    }

    for(int i = 0; i < l->size; i++){
        printf("Numero %d: ", i + 1);
        scanf("%d", &l->arr[i]);
    }
}

// MOSTRAR datos
void mostrar(void* obj){
    Lista* l = (Lista*)obj;

    if(l->size == 0){
        printf("Lista vacia\n");
        return;
    }

    printf("Contenido de la lista: ");
    for(int i = 0; i < l->size; i++)
        printf("%d ", l->arr[i]);
    printf("\n");
}

// ===== MAIN =====
int main(){
    ILista ops = {ingresar, mostrar};

    Lista l;
    l.base.ops = &ops;
    l.size = 0;

    // Operaciones
    l.base.ops->ingresar(&l);
    l.base.ops->mostrar(&l);

    return 0;
}