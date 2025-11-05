#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "nodo.h"

struct Nodo{
    datoPtr dato;
    struct Nodo * siguiente;
};


nodoPtr crearNodo(datoPtr dato, nodoPtr siguiente){

    nodoPtr nodo = (nodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;

}

nodoPtr getSiguiente(nodoPtr nodo){
    return nodo->siguiente;
}
datoPtr getDato(nodoPtr nodo){
    return nodo->dato;
}

void setDato(nodoPtr nodo, datoPtr nuevoDato){
    nodo->dato = nuevoDato;
}
void setSiguiente(nodoPtr nodo, nodoPtr nuevoSiguiente){
    nodo->siguiente = nuevoSiguiente;
}



void liberarNodo(nodoPtr nodo){

    free(nodo);

}


