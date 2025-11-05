#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED



struct Libro;
typedef struct Libro* libroPtr;

char* getTitulo(libroPtr libro);
char* getAutor(libroPtr libro);


libroPtr crearLibro(char nombre[30], char autor[30]);

void mostrarLibro(void* dato);

#endif // LIBRO_H_INCLUDED
