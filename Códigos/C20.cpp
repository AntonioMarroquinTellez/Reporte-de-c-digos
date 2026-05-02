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
} MergeIndirecto;

// IMPLEMENTACION
void merge(int* a, int* idx, int l, int m, int r){
    int temp[100], i = l, j = m + 1, k = 0;

    while(i <= m && j <= r){
        if(a[idx[i]] < a[idx[j]]) temp[k++] = idx[i++];
        else temp[k++] = idx[j++];
    }

    while(i <= m) temp[k++] = idx[i++];
    while(j <= r) temp[k++] = idx[j++];

    for(i = l, k = 0; i <= r; i++, k++)
        idx[i] = temp[k];
}

// 🔥 ahora sí inicializa idx internamente
void mergeSort(void* arr, int* idx, int l, int r){
    int* a = (int*)arr;

    // Inicialización SOLO una vez
    if(l == 0){
        for(int i = 0; i <= r; i++)
            idx[i] = i;
    }

    if(l < r){
        int m = (l + r) / 2;
        mergeSort(a, idx, l, m);
        mergeSort(a, idx, m + 1, r);
        merge(a, idx, l, m, r);
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
    IOrden ops = {mergeSort, mostrar};

    MergeIndirecto obj;
    obj.base.ops = &ops;

    int arr[] = {4, 1, 7, 2};
    int idx[4]; // 🔥 ya no necesitas inicializarlo manualmente

    obj.base.ops->ordenar(arr, idx, 0, 3);
    obj.base.ops->mostrar(arr, idx, 4);

    return 0;
}