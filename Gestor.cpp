//
// Created by Allan Diaz on 25/5/22.
//

#include "Pila.cpp"
#include "Cola.cpp"
#include "Lista.cpp"
#include "NodoArbol.cpp"
#pragma once

class Gestor {

    Cola* cola;
    Lista* lista;
    Pila* pila;
    NodoArbol* nodoArbol;

public:
    Gestor(Cola* cola, Lista* lista, Pila* pila) {

        this->cola = cola;
        this->lista = lista;
        this->pila = pila;
    }

    void pasarDeListaACola(int x){
        if(!lista->esVacia() && lista->dirNodo(x) != nullptr){
            cola->encolar(x);
        }
    }

    void generateRandomValues(){
        int max;
        max = 1000; //set the upper bound to generate the random number
        srand(time(0));

        for(int i = 0; i<10; i++) { //generate 10 random numbers
            //lista->agregar(rand()%max);
            lista->agregarFinal(rand()%max);
        }

        lista->desplegarLista();
    }

    struct nodo{
        int nro;
        struct nodo *izq, *der;
    };

    typedef struct nodo *ABB;

    ABB crearNodo(int x)
    {
        ABB nuevoNodo = new(struct nodo);
        nuevoNodo->nro = x;
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;

        return nuevoNodo;
    }


    void insertar(ABB &arbol, int x)
    {
        if(arbol==NULL)
        {
            arbol = crearNodo(x);
            cout << "Raiz: " << arbol->nro <<"\n";
        }
        else if(x < arbol->nro){
            insertar(arbol->izq, x);
            cout << "Izq: " << arbol->izq->nro <<"\n";
        }
        else if(x > arbol->nro){
            insertar(arbol->der, x);
            cout << "Der: " << arbol->der->nro <<"\n";
        }


    }

    void preOrden(ABB arbol)
    {
        if(arbol!=NULL)
        {
            cout << arbol->nro <<" ";
            preOrden(arbol->izq);
            preOrden(arbol->der);
        }
    }

    void enOrden(ABB arbol)
    {
        if(arbol!=NULL)
        {
            enOrden(arbol->izq);
            cout << arbol->nro << " ";
            enOrden(arbol->der);
        }
    }

    void postOrden(ABB arbol)
    {
        if(arbol!=NULL)
        {
            postOrden(arbol->izq);
            postOrden(arbol->der);
            cout << arbol->nro << " ";
        }
    }

    void verArbol(ABB arbol, int n)
    {
        if(arbol==NULL)
            return;
        verArbol(arbol->der, n+1);

        for(int i=0; i<n; i++)
            cout<<"   ";

        cout<< arbol->nro <<endl;

        verArbol(arbol->izq, n+1);
    }

    void ejecutarArbol(){
        ABB arbol = NULL;   // creado Arbol

        int n;  // numero de nodos del arbol
        int x; // elemento a insertar en cada nodo

        cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";

        cout << " Numero de nodos del arbol:  ";
        n=lista->getLargo();

        for(int i=0; i<n; i++)
        {
            cout << " Numero del nodo " << i+1 << ": ";

            x=lista->getValue(i,n)->getDato();
           insertar( arbol, x);
        }

        cout << "\n Mostrando ABB \n\n";
        verArbol( arbol, 0);

        cout << "\n Recorridos del ABB";

        cout << "\n\n En orden   :  ";   enOrden(arbol);
        cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
        cout << "\n\n Post Orden :  ";   postOrden(arbol);

        cout << endl << endl;

        system("pause");
        //return 0;
    }

};


