#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "nodo.h"

struct Cola;
typedef struct Cola * colaPtr;

colaPtr crearCola();

/// Setters y Getters
nodoPtr getPrimeroC(colaPtr cola);
void setPrimeroC(colaPtr cola, nodoPtr nuevoPrimero);

nodoPtr getUltimoC(colaPtr cola);
void setUltimoC(colaPtr cola, nodoPtr nuevoUltimo);

void encolar(colaPtr cola, void* dato);
void* desencolar(colaPtr cola) ;

void recorrerCola(colaPtr cola, void (*mostrarDato)(void*));
void liberarCola(colaPtr cola);

#endif // COLA_H_INCLUDED
