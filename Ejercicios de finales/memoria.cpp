#include "iostream"

using namespace std;

int mgn;
int mg=0;
int funcion(int *p, int m){
    cout<<"direccion del *p: "<<&p<<endl;
    cout<<"direccion del entero m: "<<&m<<endl;
    return m;
}

int main(){
    int mi=1;
    int *pi=&mi;
    int *pf=(int*&)funcion;
    int *ph=new int(10);
    funcion(pi, mi);
    cout<<"direccion de *pf: "<<&pf<<endl;
    cout<<"direccion donde apunta pf: "<<pf<<endl;
    cout<<"direccion de mg: "<<&mg<<endl;
    cout<<"direccion de mgn: "<<&mgn<<endl;
    cout<<"direccion de mi: "<<&mi<<endl;
    cout<<"direccion de *pi: "<<&pi<<endl;
    cout<<"direccion donde apunta pi: "<<pi<<endl;
    cout<<"direccion de *ph: "<<&ph<<endl;
    cout<<"direccion donde apunta ph: "<<ph<<endl;
    delete ph;
    return 0;
}
