#include <iostream>
using namespace std;

// ===== INTERFAZ =====
class IOrdenador {
public:
    virtual void ordenar(int arr[], int l, int r) = 0;
    virtual void mostrar(int arr[], int n) = 0;
};

// ===== CLASE =====
class MergeSort : public IOrdenador {
private:
    void merge(int arr[], int l, int m, int r){
        int i = l, j = m + 1, k = 0;
        int temp[100];

        while(i <= m && j <= r){
            if(arr[i] < arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }

        while(i <= m) temp[k++] = arr[i++];
        while(j <= r) temp[k++] = arr[j++];

        for(i = l, k = 0; i <= r; i++, k++)
            arr[i] = temp[k];
    }

public:
    void ordenar(int arr[], int l, int r) override {
        if(l < r){
            int m = (l + r) / 2;
            ordenar(arr, l, m);
            ordenar(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    void mostrar(int arr[], int n) override {
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ===== MAIN =====
int main(){
    IOrdenador* ordenador = new MergeSort();

    int arr[] = {7, 3, 1, 9, 2};

    ordenador->ordenar(arr, 0, 4);
    ordenador->mostrar(arr, 5);

    delete ordenador;
    return 0;
}