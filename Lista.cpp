#include <iostream>
#include <stdlib.h>
#include "Nodo.cpp"
#pragma once
using namespace std;

class Lista {
protected:
	Nodo* cab;
	int largo;

public:
	Lista() {
		this->cab = NULL;
		this->largo = 0;
	}

	Nodo* getCab()
	{
		return this->cab;
	}

	int getLargo()
	{
		return this->largo;
	}

	void setCab(Nodo* _cab)
	{
		this->cab = _cab;
	}

	void setLargo(int _largo)
	{
		this->largo = _largo;
	}

	Nodo* ultimo()
	{
		Nodo* ult = NULL;
		if (!esVacia()) {
			int n = getLargo();
			ult = getCab();
			for (int i = 1; i < n; i++)
				ult = ult->getSgte();
		}

		return ult;
	}

	bool esVacia()
	{
		return cab == NULL;
	}

	Nodo* dirNodo(int _dato)
	{
		Nodo* aux = NULL;
		if (!esVacia()) {
			aux = getCab();
			bool encontrado = false;

			while (aux != NULL && !encontrado) {
				if (aux->getDato() == _dato)
					encontrado = true;
				else
					aux = aux->getSgte();
			}
		}
		return aux;
	}

    Nodo* getValue(int _position,int _largo)
    {
        Nodo* aux = NULL;
        if (!esVacia()) {
            aux = getCab();
            int counter=0;

            while (aux != NULL) {
                if(counter!=_position){
                    aux = aux->getSgte();
                }else{
                    return aux;
                }
                counter ++;
            }
        }
        return aux;
    }

	void agregarInicio(int _dato)
	{
		Nodo* nuevo = new Nodo(_dato);
		nuevo->setSgte(cab);
		setCab(nuevo);
		setLargo(getLargo() + 1);
	}

	void agregarFinal(int _dato)
	{
		Nodo* nuevo = new Nodo(_dato);
		if (esVacia()) {
			setCab(nuevo);
		}
		else {
			Nodo* ult = ultimo();
			ult->setSgte(nuevo);
		}
		setLargo(getLargo() + 1);

	}

	bool agregar(int _dato)
	{ //Inserta de manera ordenada y no agrega si el dato ya existe.
		bool agregado = false;
		if (esVacia()) {
			setCab(new Nodo(_dato));
			setLargo(1);
			agregado = true;
		}
		else {
			if (_dato < getCab()->getDato()) {
				agregarInicio(_dato);
				agregado = true;
			}
			else {
				bool yaExiste = false;
				Nodo* aux = getCab();
				while (aux->getSgte() != NULL && !agregado && !yaExiste) {
					if (aux->getDato() != _dato) {
						if (_dato < aux->getSgte()->getDato()) {
							Nodo* nuevo = new Nodo(_dato); 
							nuevo->setSgte(aux->getSgte()); 
							aux->setSgte(nuevo); 
							setLargo(getLargo() + 1);
							agregado = true;
						}
						else {
							aux = aux->getSgte();
						}
					}
					else {
						yaExiste = true;
					}
				}
				if (aux->getSgte() == NULL && !agregado && (aux->getDato() != _dato)) {
					Nodo* nuevo = new Nodo(_dato);
					aux->setSgte(nuevo);
					setLargo(getLargo() + 1);
					agregado = true;
				}
			}
		}
		return agregado;
	}
	void desplegarLista()
	{
		Nodo* aux = getCab();
		if (esVacia()) {
			cout << "Esta vacia la lista" << endl;;
		}
		else {
			while (aux != NULL) {
				cout << aux->getDato() << ",";
				aux = aux->getSgte();
			}
			cout << "fin" << endl;;
		}
	}



};






