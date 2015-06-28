#include <iostream>
#include <cstring>
using namespace std;
class celda {
private:

public:
        int valor;
        void setVal(int val){
                valor=val;
        }


};
class peiramide {
private:
        celda *tabla[21];
        void ingresarDatos() {
                int n,cas,val;
                cout<<"cantidad de datos a ingresar: ";
                cin>>n;
                for (size_t i = 0; i < n; i++) {
                        cout<<endl<<"posicion de casillero: ";
                        cin>>cas;
                        cout<<endl<<"valor del casillero "<<cas<<": ";
                        cin>>val;
                        tabla[cas]->setVal(val);
                }
        }
public:
        peiramide();
};

peiramide::peiramide(){
        for (size_t i = 0; i < 21; i++) {
                tabla[i]=new celda();
        }
        ingresarDatos();
}
int main() {
        peiramide c;


        return 0;
}
