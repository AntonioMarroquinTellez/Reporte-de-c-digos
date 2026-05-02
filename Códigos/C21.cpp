#include <stdio.h>

// INTERFAZ
typedef struct {
    void (*ordenar)(void*, int*, int, int);
    void (*mostrar)(void*, int*, int);
} IOrden;

// ABSTRACTA
typedef struct {
    IOrden* ops;
} Base;

// CLASE
typedef struct {
    Base base;
} QuickIndirecto;

// IMPLEMENTACION
int particion(int* a, int* idx, int low, int high){
    int pivot = a[idx[high]];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(a[idx[j]] < pivot){
            i++;
            int t = idx[i]; idx[i] = idx[j]; idx[j] = t;
        }
    }

    int t = idx[i+1]; idx[i+1] = idx[high]; idx[high] = t;
    return i + 1;
}

void quickSort(void* arr, int* idx, int low, int high){
    int* a = (int*)arr;

    // 🔥 Inicializar índices solo una vez
    if(low == 0){
        for(int i = 0; i <= high; i++)
            idx[i] = i;
    }

    if(low < high){
        int pi = particion(a, idx, low, high);
        quickSort(a, idx, low, pi - 1);
        quickSort(a, idx, pi + 1, high);
    }
}

void mostrar(void* arr, int* idx, int n){
    int* a = (int*)arr;
    for(int i = 0; i < n; i++)
        printf("%d ", a[idx[i]]);
    printf("\n");
}

// MAIN
int main(){
    IOrden ops = {quickSort, mostrar};

    QuickIndirecto obj;
    obj.base.ops = &ops;

    int arr[] = {6, 3, 9, 1};
    int idx[4]; // 🔥 ya no se inicializa aquí

    obj.base.ops->ordenar(arr, idx, 0, 3);
    obj.base.ops->mostrar(arr, idx, 4);

    return 0;
}