#include <iostream>
using namespace std;

struct Persona{

    string nombre;
    string ap;
    string am;
    string genero;
    int edad;

};

int main(){

    Persona personas[3];

    Persona *p = personas;

    for(int i=0;i<3;i++){

        cout<<"Nombre: ";
        cin>>(p+i)->nombre;

        cout<<"Apellido paterno: ";
        cin>>(p+i)->ap;

        cout<<"Apellido materno: ";
        cin>>(p+i)->am;

        cout<<"Genero: ";
        cin>>(p+i)->genero;

        cout<<"Edad: ";
        cin>>(p+i)->edad;

        cout<<endl;
    }

    cout<<"\nLista de personas\n";

    for(int i=0;i<3;i++){

        cout<<(p+i)->nombre<<" "
        <<(p+i)->ap<<" "
        <<(p+i)->am<<" "
        <<(p+i)->edad<<" anios"<<endl;
    }

}