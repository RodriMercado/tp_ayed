#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "nodo.h"

struct Pila;
typedef struct Pila * pilaPtr;

pilaPtr crearPila();

/// Setters y Getters
nodoPtr getUltimoP(pilaPtr pila);
void setUltimoP(pilaPtr pila, nodoPtr nuevoUltimo);

void apilar(pilaPtr pila, void* dato);
void* desapilar(pilaPtr pila);

void recorrerPila(pilaPtr pila, void (*mostrarDato)(void*));
void liberarPila(pilaPtr pila);

#endif // PILA_H_INCLUDED
