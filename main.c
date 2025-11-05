#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "nodo.h"
#include "libro.h"
#include "pila.h"
#include "cola.h"
#include "usuario.h"


int main()
{
    libroPtr libro;
    pilaPtr pilaLibros = crearPila();
    colaPtr colaUsuarios = crearCola();

    listaPtr listaLibros = crearLista();

    libroPtr libro1 = crearLibro("La espada de Shannara", "Terry Brooks");
    libroPtr libro2 = crearLibro("El nombre del viento", "Patrick Rothfuss");

    insertarUltimo(listaLibros, libro1);
    insertarUltimo(listaLibros, libro2);

    int opcion;
    char nombre[50];
    char autor[50];

    do {
        printf("\n----------------- MENU -----------------\n");
        printf("1. Apilar libro (registrar devolucion)\n");
        printf("2. Desapilar libro (reubicar)\n");
        printf("3. Encolar usuario (solicitud de prestamo)\n");
        printf("4. Desencolar usuario (procesar prestamo)\n");
        printf("5. Mostrar pila de libros (devoluciones)\n");
        printf("6. Mostrar cola de usuarios (solicitudes)\n");
        printf("7. Mostrar catalogo de libros\n");
        printf("0. Salir\n");

        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);

        while (getchar() != '\n');

        system("cls");

        switch (opcion) {
            case 1:
                printf("Titulo del libro: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = 0;

                printf("Autor: ");
                fgets(autor, sizeof(autor), stdin);
                autor[strcspn(autor, "\n")] = 0;

                apilar(pilaLibros, crearLibro(nombre, autor));
                printf("Libro '%s' de '%s' apilado correctamente.\n", nombre, autor);
                break;

            case 2:
                libro = (libroPtr) desapilar(pilaLibros);
                if (libro) mostrarLibro(libro);

                break;

            case 3: {
                printf("Nombre del usuario: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = 0;

                usuarioPtr nuevoUsuario = crearUsuario(nombre);
                encolar(colaUsuarios, nuevoUsuario);
                printf("Usuario '%s' agregado a la cola de solicitudes.\n", nombre);
                break;
            }

            case 4: {
                usuarioPtr usuario = (usuarioPtr)desencolar(colaUsuarios);
                if (usuario) mostrarUsuario(usuario);
                break;
            }

            case 5:
                printf("Libros en la pila (devoluciones) \n");
                recorrerPila(pilaLibros, mostrarLibro);
                break;

            case 6:
                printf("Usuarios en la cola (solicitudes) \n");
                recorrerCola(colaUsuarios, mostrarUsuario);
                break;
            case 7:
                printf("Catalogo de libros disponibles:\n");
                recorrerLista(listaLibros, mostrarLibro);
                break;

            case 0:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }

    } while (opcion != 0);

    // Liberar pila, cola y listas
    liberarPila(pilaLibros);
    liberarCola(colaUsuarios);
    liberarLista(listaLibros);

    return 0;
}
