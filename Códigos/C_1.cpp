#include <stdio.h>

// INTERFAZ
typedef struct {
    void (*mostrar)(void*);
} IPrint;

// ABSTRACTA
typedef struct {
    IPrint* ops;
} Base;

// CLASE
typedef struct {
    Base base;
    int valor;
} Objeto;

// IMPLEMENTACION
void mostrar(void* obj){
    Objeto* o = (Objeto*)obj;
    printf("Valor: %d\n", o->valor);
}

// MAIN
int main(){
    IPrint ops = {mostrar};

    Objeto obj;
    obj.base.ops = &ops;
    obj.valor = 100;

    obj.base.ops->mostrar(&obj);

    return 0;
}