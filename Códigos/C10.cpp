#include <iostream>
using namespace std;

int main(){

    int n[5];
    int *p=n;
    int suma=0;

    for(int i=0;i<5;i++){
        cin>>*(p+i);
    }

    for(int i=0;i<5;i++){
        suma+=*(p+i);
    }

    cout<<"Promedio "<<suma/5.0<<endl;

}