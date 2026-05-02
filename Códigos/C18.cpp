#include <iostream>
using namespace std;

// ===== INTERFAZ =====
class IOrdenador {
public:
    virtual void ordenar(int arr[], int low, int high) = 0;
};

// ===== CLASE =====
class QuickSort : public IOrdenador {
private:
    int particion(int arr[], int low, int high){
        int pivot = arr[high];
        int i = low - 1;

        for(int j = low; j < high; j++){
            if(arr[j] < pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

public:
    void ordenar(int arr[], int low, int high) override {
        if(low < high){
            int pi = particion(arr, low, high);
            ordenar(arr, low, pi - 1);
            ordenar(arr, pi + 1, high);
        }
    }
};

// ===== MAIN =====
int main(){
    IOrdenador* ordenador = new QuickSort();

    int arr[] = {8, 4, 2, 6, 1};

    ordenador->ordenar(arr, 0, 4);

    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    delete ordenador;
    return 0;
}