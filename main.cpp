#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
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
	int CanSolve();
};
int celda::CanSolve(){
	int a,b,c;
	a=HijoD()->MVal();
	b=HijoI()->MVal();
	c=MVal();
	if(a>0 && b>0 && c>0){
		if(a+b==c)
			return 0;
		else
			return 2;
	}
	else{
		if(a>0 && b>0 && !c){
			setVal(a+b);
			return 1;
		}
		else{
		if(a>0 && !b && c>0){
			if(c-a>0){
				HijoI()->setVal(c-a);
				return 1;
			}
			else
				return 2;
		}
		else
		if(!a && b>0 && c>0){
			if(c-b>0){
				HijoD()->setVal(c-b);
				return 1;
			}
			else
				return 2;
		}
		else
			return 0;
		}
	}
}
class peiramide {
private:
	celda *tabla[21];
	int n;
	void ingresarDatos() {
		int cas,val;
		cout<<"cantidad de datos a ingresar: ";
		cin>>n;
		for (size_t i = 0; i < n; ++i) {
			cout<<endl<<"posicion de casillero: ";
			cin>>cas;
			cout<<endl<<"valor del casillero "<<cas<<": ";
			cin>>val;
			tabla[cas]->setVal(val);
			system("cls");
			mostrar();
		}
	}
public:
	peiramide();
	void mostrar();
	bool Solve();
};
bool peiramide::Solve(){
	bool b=true;
	int a;
	if(n<6)
	return false;
	while(b){
		b=false;
		for (size_t i = 0; i < 15; ++i) {
			a=tabla[i]->CanSolve();
			if(a==2)
				return false;
			if(a==1)
				b=b|true;
		}
	}
	for (size_t i = 0; i<21; ++i) {
		if(!tabla[i]->MVal())
		return false;
	}
		return true;

}
peiramide::peiramide(){
        int casilla;
	for (size_t i = 0; i < 21; i++) {
		tabla[i]=new celda();
	}
	for (int i = 1; i <= 15; ++i)
	{
                casilla=i+rint(log2(i))+1;
		if(i==11)
		casilla++;
		if(i==3 || i==6)
		casilla--;
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
	system("cls");
	if(!c.Solve())
	cout<<"Cannot be Solved";
	else
	c.mostrar();
}
