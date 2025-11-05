#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "cola.h"

struct Cola {
    nodoPtr primero;
    nodoPtr ultimo;
};

/// Setters y Getters
nodoPtr getPrimeroC(colaPtr cola){
    return cola->primero;
}
void setPrimeroC(colaPtr cola, nodoPtr nuevoPrimero){
    cola->primero = nuevoPrimero;
}

nodoPtr getUltimoC(colaPtr cola){
    return cola->ultimo;
}

void setUltimoC(colaPtr cola, nodoPtr nuevoUltimo){
    cola->ultimo = nuevoUltimo;
}

colaPtr crearCola() {
    colaPtr cola = (colaPtr) malloc(sizeof(struct Cola));
    cola->primero = NULL;
    cola->ultimo = NULL;

    return cola;
}

void encolar(colaPtr cola, void* dato) {
    nodoPtr nuevoNodo = crearNodo(dato, NULL);

    if (getPrimeroC(cola) == NULL) {
        setPrimeroC(cola, nuevoNodo);
        setUltimoC(cola, nuevoNodo);
    } else {
        setSiguiente(getUltimoC(cola), nuevoNodo);
        setUltimoC(cola, nuevoNodo);
    }
}

void* desencolar(colaPtr cola) {
    // Validar si la cola esta vacia
    if (!cola || !getPrimeroC(cola)) {
        printf("Error: la cola esta vacia.\n");
        return NULL;
    }

    nodoPtr nodoAEliminar = getPrimeroC(cola);
    void* dato = getDato(nodoAEliminar);

    setPrimeroC(cola, getSiguiente(nodoAEliminar));
    if (getPrimeroC(cola) == NULL){
        setUltimoC(cola, NULL);
    }

    liberarNodo(nodoAEliminar);

    return dato;
}

/// Callback
void recorrerCola(colaPtr cola, void (*mostrarDato)(void*)) {
    nodoPtr actual = cola->primero;
    while(actual) {
        mostrarDato(getDato(actual));
        actual = getSiguiente(actual);
    }
}

void liberarCola(colaPtr cola) {
    while (getPrimeroC(cola) != NULL) {
        desencolar(cola);
    }
    free(cola);
}

