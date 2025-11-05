#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "pila.h"

struct Pila {
    nodoPtr ultimo;
};

/// Setters y Getters

nodoPtr getUltimoP(pilaPtr pila){
    return pila->ultimo;
}

void setUltimoP(pilaPtr pila, nodoPtr nuevoUltimo){
    pila->ultimo = nuevoUltimo;
}

pilaPtr crearPila() {
    pilaPtr pila = (pilaPtr) malloc(sizeof(struct Pila));

    pila->ultimo = NULL;

    return pila;
}

void apilar(pilaPtr pila, void* dato) {

    nodoPtr nuevoNodo = crearNodo(dato, getUltimoP(pila));
    setUltimoP(pila, nuevoNodo);


}

void* desapilar(pilaPtr pila) {
    // Validar si la pila esta vacia
    if (!pila || !pila->ultimo) {
        printf("Error: la pila esta vacia.\n");
        return NULL;
    }

    nodoPtr nodoAEliminar = pila->ultimo;
    void* dato = getDato(nodoAEliminar);

    setUltimoP(pila, getSiguiente(nodoAEliminar));
    free(nodoAEliminar);

    return dato;
}

void liberarPila(pilaPtr pila) {

    while (getUltimoP(pila) != NULL) {
        desapilar(pila);
    }
    free(pila);
}


/// Callback
void recorrerPila(pilaPtr pila, void (*mostrarDato)(void*)){
    nodoPtr actual = pila->ultimo;
    while(actual) {
        mostrarDato(getDato(actual));
        actual = getSiguiente(actual);
    }
}

