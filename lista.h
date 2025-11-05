#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"
typedef struct Lista * listaPtr;



listaPtr crearLista();

void recorrerLista(listaPtr lista, void(*mostrarDato)(datoPtr));
void insertarUltimo(listaPtr lista, void* dato);

void liberarLista(listaPtr lista);

#endif // LISTA_H_INCLUDED
