#include <iostream>
using namespace std;

// ===== INTERFAZ =====
class IOrden {
public:
    virtual void ordenar(int arr[], int idx[], int n) = 0;
    virtual void mostrar(int arr[], int idx[], int n) = 0;
};

// ===== CLASE =====
class BurbujaIndirecto : public IOrden {
public:
    void ordenar(int arr[], int idx[], int n) override {
        // Inicializar índices
        for(int i = 0; i < n; i++)
            idx[i] = i;

        // Burbuja indirecto
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(arr[idx[j]] > arr[idx[j + 1]]){
                    swap(idx[j], idx[j + 1]);
                }
            }
        }
    }

    void mostrar(int arr[], int idx[], int n) override {
        for(int i = 0; i < n; i++)
            cout << arr[idx[i]] << " ";
        cout << endl;
    }
};

// ===== MAIN =====
int main(){
    IOrden* obj = new BurbujaIndirecto();

    int arr[] = {5, 2, 9, 1};
    int idx[4];

    obj->ordenar(arr, idx, 4);
    obj->mostrar(arr, idx, 4);

    delete obj;
    return 0;
}