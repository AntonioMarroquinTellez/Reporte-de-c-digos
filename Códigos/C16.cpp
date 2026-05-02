#include <iostream>
using namespace std;

// ===== INTERFAZ =====
class IOperacion {
public:
    virtual void calcular() = 0;
    virtual void mostrar() = 0;
};

// ===== CLASE BASE (ABSTRACTA) =====
class Base : public IOperacion {
    // Puede tener lógica común si lo necesitas
};

// ===== CLASE =====
class Datos : public Base {
private:
    int arr[5];
    int suma;
    float promedio;
    int max;
    int min;

public:
    void ingresar() {
        cout << "Ingresa 5 numeros:\n";
        for(int i = 0; i < 5; i++)
            cin >> arr[i];
    }

    void calcular() override {
        suma = 0;
        max = min = arr[0];

        for(int i = 0; i < 5; i++) {
            suma += arr[i];

            if(arr[i] > max) max = arr[i];
            if(arr[i] < min) min = arr[i];
        }

        promedio = suma / 5.0;
    }

    void mostrar() override {
        cout << "Suma: " << suma << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Max: " << max << endl;
        cout << "Min: " << min << endl;
    }
};

// ===== MAIN =====
int main() {
    Datos d;

    d.ingresar();
    d.calcular();
    d.mostrar();

    return 0;
}