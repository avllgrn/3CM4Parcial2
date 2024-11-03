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
    int acumulaNodosEnLista(void){
        Nodo* aux;
        int s=0;
        aux=primero;
        while(aux!=NULL){
            s = s+aux->dato;
            aux=aux->siguiente;
        }
        return s;
    };
    int cuentaNodosEnLista(void){
        Nodo* aux;
        int s=0;
        aux=primero;
        while(aux!=NULL){
            ++s;
            aux=aux->siguiente;
        }
        return s;
    };
    float promediaNodosEnLista(){
        Nodo* aux;
        float s=0;
        int n=0;
        aux=primero;
        while(aux!=NULL){
            s = s+aux->dato;
            n++;
            aux=aux->siguiente;
        }
        return s/n;
    };
    void agregaListaEnLista(LSE& Copia){
        Nodo* aux;
        aux=primero;
        while(aux!=NULL){
            Copia.insertaAlFinal(aux->dato);
            aux=aux->siguiente;
        }
    };
    void copiaListaEnLista(LSE& Copia){
        Nodo* aux;
        Copia.liberaLSE();
        aux=primero;
        while(aux!=NULL){
            Copia.insertaAlFinal(aux->dato);
            aux=aux->siguiente;
        }
    };
    void aplicaBurbujaALista(void){
        if(!estaVacia()){
            int temp, n, i, intento=0;
            n = cuentaNodosEnLista();
            Nodo* aux1;
            Nodo* aux2;
            Nodo* aux3=ultimo->siguiente;
            aux1 = primero;
            aux2 = primero->siguiente;
            while(aux1!=aux3){
                while(aux2!=aux3){
                    //cout<<"Intento"<<++intento<<endl;
                    if(aux2->dato < aux1->dato){
                        temp = aux1->dato;
                        aux1->dato = aux2->dato;
                        aux2->dato = temp;
                    }
                    aux1 = aux1->siguiente;
                    aux2 = aux2->siguiente;
                }
                aux3 = aux1;
                aux1 = primero;
                aux2 = primero->siguiente;
            }
        }
    };
};

int main(){
    srand(time(NULL));
    LSE L1;
    int i,n,x;

    cout<<"Cuantos nodos? ";cin>>n;
    for(i=0; i<n; i++){
        x = rand()%100;
        //cout<<endl<<"Se inserta "<<x<<endl;
        L1.insertaAlFinal(x);
    }
    cout<<"L"<<endl;
    L1.muestraDePrimeroAUltimo();
    cout<<endl<<endl;
    cout<<"Tiene "<<L1.cuentaNodosEnLista()<<" nodos"<<endl
        <<"Suman "<<L1.acumulaNodosEnLista()<<endl
        <<"Promedian "<<L1.promediaNodosEnLista()<<endl;
    cout<<endl<<endl;

    LSE L2, Copia;
    cout<<"L2"<<endl;
    L2.muestraDePrimeroAUltimo();
    cout<<endl<<endl;
    cout<<"Copia"<<endl;
    Copia.muestraDePrimeroAUltimo();
    cout<<endl<<endl;

    L1.copiaListaEnLista(Copia);
    L1.copiaListaEnLista(Copia);
    L1.agregaListaEnLista(L2);
    L1.agregaListaEnLista(L2);
    cout<<endl<<endl;

    cout<<"L2 = L1 agregada 2 veces"<<endl;
    L2.muestraDePrimeroAUltimo();
    cout<<endl<<endl;
    cout<<"Copia = L1 'copiada' 2 veces"<<endl;
    Copia.muestraDePrimeroAUltimo();
    cout<<endl<<endl;

    Copia.aplicaBurbujaALista();
    cout<<"Copia ordenada con burbuja"<<endl;
    Copia.muestraDePrimeroAUltimo();
    cout<<endl<<endl;
    system("pause");
    cout<<endl<<endl<<"Destructor:";

    return 0;
}
