#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;
typedef struct Nodo * nodoPtr;

/// Lista generica VOID*
typedef void* datoPtr;

nodoPtr crearNodo(datoPtr dato, nodoPtr siguiente); // Cambiar int por datoPTR

nodoPtr getSiguiente(nodoPtr nodo);
datoPtr getDato(nodoPtr nodo); // Cambiar int por datoPTR

void setDato(nodoPtr nodo, datoPtr nuevoDato); // Cambiar int por datoPTR
void setSiguiente(nodoPtr nodo, nodoPtr nuevoSiguiente);
void liberarNodo(nodoPtr nodo);

#endif // NODO_H_INCLUDED
