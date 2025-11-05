#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "libro.h"

struct Libro{
    char titulo[30];
    char autor[30];
};

char* getTitulo(libroPtr libro) {
    return libro->titulo;
}

char* getAutor(libroPtr libro) {
    return libro->autor;
}



libroPtr crearLibro(char titulo[30], char autor[30]){


    libroPtr libro = (libroPtr) malloc (sizeof(struct Libro));

    strcpy(libro->titulo, titulo);
    strcpy(libro->autor, autor);

    return libro;
}

void mostrarLibro(void* dato) {
    libroPtr libro = (libroPtr) dato;
    printf("Titulo: %s | Autor: %s\n", getTitulo(libro), getAutor(libro));
}
