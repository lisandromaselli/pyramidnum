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
	celda* HijoD(){
		return der;
	}
	celda* HijoI(){
		return izq;
	}
	void setVal(int val){
		valor=val;
	}

	int MVal(){
		return valor;
	}
	celda(){
		valor=0;
		der=NULL;
		izq=NULL;
	}
	bool CanSolve();
};
bool celda::CanSolve(){
	if((HijoD()->MVal())!=0 && (HijoI()->MVal())!=0 && !MVal()){
		setVal(HijoD()->MVal()+HijoI()->MVal());
		return true;
	}
	if((HijoD()->MVal())!=0 && (HijoI()->MVal())==0 && MVal()){
		HijoI()->setVal(MVal()-(HijoD()->MVal()));
		return true;
	}
	if((HijoD()->MVal())==0 && (HijoI()->MVal())!=0 && MVal()){
		HijoD()->setVal(MVal()-(HijoI()->MVal()));
		return true;
	}

}
class peiramide {
private:
	celda *tabla[21];
	int n;
	void ingresarDatos() {
		int n,cas,val;
		cout<<"cantidad de datos a ingresar: ";
		cin>>n;
		for (size_t i = 0; i < n; ++i) {
			cout<<endl<<"posicion de casillero: ";
			cin>>cas;
			cout<<endl<<"valor del casillero "<<cas<<": ";
			cin>>val;
			tabla[cas]->setVal(val);
		}
		tabla[0]->CanSolve();
	}
public:
	peiramide();
	void mostrar();
	bool Solve();
};
bool peiramide::Solve(){
	bool b=true;
	if(n<6)
	return false;
	while(b){
		b=false;
		for (size_t i = 0; i < 16; ++i) {
			b=b|(tabla[i]->CanSolve());
		}
	}
}
peiramide::peiramide(){
        int casilla;
	for (size_t i = 0; i < 21; i++) {
		tabla[i]=new celda();
	}
	for (int i = 1; i <= 16; ++i)
	{
                casilla=i+log2(i)+1;
		tabla[i-1]->setI(tabla[casilla-1]);
                tabla[i-1]->setD(tabla[casilla]);
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
	if(c.Solve())
        c.mostrar();
	return 0;
}
