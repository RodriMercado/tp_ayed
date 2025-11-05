#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

struct Usuario;
typedef struct Usuario* usuarioPtr;

usuarioPtr crearUsuario(char Nombre[20]);
char* getNombre(usuarioPtr usuario);
void setNombre(usuarioPtr usuario, char* nuevoNombre);

void mostrarUsuario(void* dato);

#endif // USUARIO_H_INCLUDED
