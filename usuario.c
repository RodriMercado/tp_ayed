#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "nodo.h"
#include "usuario.h"

struct Usuario{
    char nombre[20];
    listaPtr listaUsuarios;
};

char* getNombre(usuarioPtr usuario) {
    return usuario->nombre;
}

void setNombre(usuarioPtr usuario, char* nuevoNombre) {
    strcpy(usuario->nombre, nuevoNombre);
}


usuarioPtr crearUsuario(char nombre[20]){
    usuarioPtr usuario = (usuarioPtr) malloc (sizeof(struct Usuario));

    strcpy(usuario->nombre, nombre);

    /// Crear lista
    usuario->listaUsuarios = crearLista();

    return usuario;
}

void mostrarUsuario(void* dato) {
    usuarioPtr usuario = (usuarioPtr) dato;
    printf("Usuario: %s\n", getNombre(usuario));
}
