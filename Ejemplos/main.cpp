#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class LSE{
private:
    class Nodo{
    public:
        int dato;
        Nodo* siguiente;
        Nodo(void){
            dato = 0;
            siguiente = NULL;
        };
        Nodo(int d, Nodo* s){
            dato = d;
            siguiente = s;
        };
        void muestraTuEstado(void){
            cout<<"| "<<dato<<" -> ";
            if(siguiente==NULL)
                cout << "NULL";
            else
                cout<< siguiente;
            cout<<" |"<<endl;
        };
    };
    Nodo* busca(int d){
        Nodo* aux;
        aux = primero;
        while(aux!=NULL){
            if(aux->dato == d)
                return aux;

            aux = aux->siguiente;
        }
        return NULL;
    };
    Nodo* primero;
    Nodo* ultimo;
public:
    LSE(void){
        primero = NULL;
        ultimo = NULL;
    };
    ~LSE(void){
        cout<<endl<<"Se destruye LSE..."<<endl;
        liberaLSE();
        cout<<endl<<"LSE destruida..."<<endl;
    };
    void insertaAlFinal(int d){
        if(estaVacia()){
            ultimo = new Nodo(d, NULL);
            primero = ultimo;
        }
        else{
            ultimo->siguiente = new Nodo(d, NULL);
            ultimo = ultimo->siguiente;
        }
    };
    void insertaAlInicio(int d){
        if(estaVacia()){
            primero = new Nodo(d, NULL);
            ultimo = primero;
        }
        else{
            primero = new Nodo(d, primero);
        }
    };
    void inserta(int d){
        if(estaVacia()||d<=primero->dato)
            insertaAlInicio(d);
        else if(d>=ultimo->dato)
            insertaAlFinal(d);
        else{
            Nodo* aux1=primero;
            Nodo* aux2=primero->siguiente;
            while(d>aux2->dato){
                aux1=aux1->siguiente;
                aux2=aux2->siguiente;
            }
            aux1->siguiente = new Nodo(d, aux2);
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
            if(primero == ultimo){
                delete ultimo;
                primero = NULL;
                ultimo = NULL;
            }
            else{
                aux=primero;
                while(aux->siguiente != ultimo){
                    aux = aux->siguiente;
                }
                delete ultimo;
                aux->siguiente = NULL;
                ultimo = aux;
            }
        }
        return d;
    };
    bool estaVacia(void){
        return primero==NULL && ultimo==NULL;
    };
    void liberaLSE(void){
        while(!estaVacia()){
            cout<<eliminaAlInicio()<<" ";
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
        Nodo* aux1;
        Nodo* aux2;

        if(!estaVacia() && primero==ultimo)
            cout<<ultimo->dato;
        else if(!estaVacia() && primero!=ultimo){
            aux2=ultimo;
            do{
                aux1=primero;
                while(aux1->siguiente != aux2){
                    aux1 = aux1->siguiente;
                }
                cout<<aux2->dato<<" ";
                aux2=aux1;
            }while(aux2!=primero);
            cout<<aux2->dato<<" ";
        }
    };
    bool buscaDato(int d){
        return busca(d)!=NULL;
    };
    void modificaDato(int d, int x){
        Nodo* aqui = busca(d);
        if(aqui!=NULL){
            aqui->dato = x;
        }
    };
};

int main(){
    srand(time(NULL));
    LSE L;
    int i,n,x;

    cout<<"Cuantos nodos? ";cin>>n;
    for(i=0; i<n; i++){
        x = rand()%100;
        cout<<endl<<"Se inserta "<<x<<endl;
        L.inserta(x);
        cout<<"L"<<endl;
        L.muestraDePrimeroAUltimo();
    }

    cout<<endl<<endl;
    system("pause");
    cout<<endl<<endl<<"Destructor:";

    return 0;
}
