#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class LDE{
private:
    class Nodo{
    public:
        Nodo* previo;
        int dato;
        Nodo* siguiente;
        Nodo(void){
            previo = NULL;
            dato = 0;
            siguiente = NULL;
        };
        Nodo(Nodo* p, int d, Nodo* s){
            previo = p;
            dato = d;
            siguiente = s;
        };
        void muestraTuEstado(void){
            cout<<"| ";
            if(previo==NULL)
                cout << "NULL";
            else
                cout<< previo;
            cout<<" <- "<<dato<<" -> ";
            if(siguiente==NULL)
                cout << "NULL";
            else
                cout<< siguiente;
            cout<<" |"<<endl;
        };
    };
    Nodo* busca(int d){
        if(!estaVacia()){
            Nodo* aux1 = primero;
            Nodo* aux2 = ultimo;
            while(aux1!=aux2 && aux1->siguiente!=aux2
                  && aux1->dato!=d && aux2->dato!=d){
                aux1 = aux1->siguiente;
                aux2 = aux2->previo;
            }
            if(aux1->dato==d)
                return aux1;
            else if(aux2->dato==d)
                return aux2;
        }
        return false;
    };
    Nodo* primero;
    Nodo* ultimo;
    public:
    LDE(void){
        primero = NULL;
        ultimo = NULL;
    };
    ~LDE(void){
        liberaLDE();
    };
    void liberaLDE(void){
        while(!estaVacia()){
            cout<<eliminaAlInicio()<<endl;
        }
    };
    int eliminaAlInicio(void){
        int d;
        Nodo* aux;
        if(!estaVacia() && primero!=ultimo){
            d = primero->dato;
            aux = primero;
            primero = primero->siguiente;
            delete aux;
            primero->previo = NULL;
        }
        else if(!estaVacia() && primero==ultimo){
            d = primero->dato;
            delete primero;
            primero = NULL;
            ultimo = NULL;
        }
        return d;
    };
    int eliminaAlFinal(void){
        int d;
        Nodo* aux;
        if(!estaVacia()){
            d = ultimo->dato;
            if(primero==ultimo){
                delete ultimo;
                ultimo = NULL;
                primero = NULL;
            }
            else{
                aux = ultimo;
                ultimo = ultimo->previo;
                delete aux;
                ultimo->siguiente = NULL;
            }
            return d;
        }
    };
    void insertaAlInicio(int d){
        if(estaVacia()){
            primero = new Nodo(NULL, d, NULL);
            ultimo = primero;
        }
        else{
            primero->previo = new Nodo(NULL, d, primero);
            primero = primero->previo;
        }
    };
    void insertaAlFinal(int d){
        if(estaVacia()){
            ultimo = new Nodo(NULL, d, NULL);
            primero = ultimo;
        }
        else{
            ultimo->siguiente = new Nodo(ultimo, d, NULL);
            ultimo = ultimo->siguiente;
        }
    };
    void muestraDePrimeroAUltimo(void){
        Nodo* aux;
        aux = primero;
        while(aux!=NULL){
            cout<<aux->dato<<" ";
            aux = aux->siguiente;
        }
    };
    void muestraDeUltimoAPrimero(void){
        Nodo* aux;
        aux = ultimo;
        while(aux!=NULL){
            cout<<aux->dato<<" ";
            aux = aux->previo;
        }
    };
    bool estaVacia(void){
        return primero==NULL && primero==ultimo;
    };
    bool buscaDato(int d){
        return busca(d)!=NULL;
    };
};

int main(){
    srand(time(NULL));
    LDE L;
    int x, i=0;

    for(i=0; i<5; i++){
        x = rand()%100;
        L.insertaAlInicio(x);
    };
    for(i=0; i<5; i++){
        x = rand()%100;
        L.insertaAlFinal(x);
    };

    cout<<"L de inicio a fin"<<endl;
    L.muestraDePrimeroAUltimo();cout<<endl;
    cout<<"L de fin a inicio"<<endl;
    L.muestraDeUltimoAPrimero();cout<<endl;
    cout<<endl<<endl;

    cout<<"Se borra al primero "<<L.eliminaAlInicio()<<endl;
    cout<<"L de inicio a fin"<<endl;
    L.muestraDePrimeroAUltimo();cout<<endl;
    cout<<"L de fin a inicio"<<endl;
    L.muestraDeUltimoAPrimero();cout<<endl;
    cout<<endl<<endl;

    cout<<"Se borra al ultimo "<<L.eliminaAlFinal()<<endl;
    cout<<"L de inicio a fin"<<endl;
    L.muestraDePrimeroAUltimo();cout<<endl;
    cout<<"L de fin a inicio"<<endl;
    L.muestraDeUltimoAPrimero();cout<<endl;
    cout<<endl<<endl;

    cout<<"Destructor:"<<endl;
    return 0;
}
