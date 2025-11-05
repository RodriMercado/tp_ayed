#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "nodo.h"

struct Lista{
    nodoPtr primero;
    int tam;
};


listaPtr crearLista(){

    listaPtr lista = (listaPtr) malloc (sizeof(struct Lista));

    lista->primero = NULL;
    lista->tam = 0;

    return lista;
}

void insertarUltimo(listaPtr lista, void* dato){
    nodoPtr nuevoNodo = crearNodo(dato, NULL);

    nodoPtr actual = lista->primero;

    if(actual == NULL){
        lista->primero = nuevoNodo;
    }else{
        while(getSiguiente(actual)!=NULL){
            actual = getSiguiente(actual);
        }
        setSiguiente(actual, nuevoNodo);

    }
    lista->tam++;
}


/// Callback
void recorrerLista(listaPtr lista, void(*mostrarDato)(datoPtr)){
    nodoPtr actual = lista->primero;
    while (actual!=NULL){
        mostrarDato(getDato(actual));
        actual = getSiguiente(actual);
    }
    printf("\n\n");
};


void liberarLista(listaPtr lista){
    nodoPtr actual = lista->primero;
    while (actual) {
        nodoPtr aux = actual;
        actual = getSiguiente(actual);
        free(getDato(aux));
        free(aux);
    }
    free(lista);
}
