#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
using namespace std;
class celda {
private:
	int valor;
	celda *der,*izq;
public:
	void setD(celda *d){
		der=d;
	}
	void setI(celda *i){
		izq=i;
	}
	celda HijoD(celda *d){
		return *der;
	}
	celda HijoI(celda *i){
		return *izq;
	}
	void setVal(int val){
		valor=val;
	}

	int MVal(){
		return valor;
	}
	celda(){
		valor=0;
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
	void mostrar();
};

peiramide::peiramide(){
	for (size_t i = 0; i < 21; i++) {
		tabla[i]=new celda();
	}
	for (int i = 0; i <= 15; ++i)
	{
		tabla[i]->setD(tabla[i+log(2,i)+i]);
	}
	ingresarDatos();
}
void peiramide::mostrar(){
	int i,space,rows=6,k=0,a=0;
	stringstream s,ss;
	s.width(5);
	s<<"     ";
	for(i=1;i<=rows;++i)
	{
		for(space=1;space<=rows-i;++space){
			cout<<s.str();
		}
		while(k!=i){
			ss.width(5);
			ss<<tabla[a++]->MVal();
			cout<<ss.str();
			cout<<s.str();
			ss.str("");
			++k;
		}
		k=0;
		cout<<"\n";
	}
}
int main() {
	peiramide c;
	c.mostrar();
	return 0;
}
