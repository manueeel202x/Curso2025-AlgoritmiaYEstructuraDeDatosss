# Reproductor (FLTK + C++) — Lista enlazada simple

Estructura solicitada:
```
apps/
 └── app_main.cpp
bin/
 └── app_lista_circular
include/
 └── lista_circular.h
obj/
 ├── app_main.o
 └── lista_circular.o
src/
 └── lista_circular.cpp
Makefile
README.md
```

## Requisitos

### Ubuntu/Debian
```
sudo apt-get update
sudo apt-get install build-essential fltk1.3-dev
```

### Windows (MSYS2 MINGW64)
```
pacman -Syu
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-fltk make
```

## Compilar
```
make
```
Genera `bin/app_lista_circular` (o `bin/app_lista_circular.exe`).

## Ejecutar
```
./bin/app_lista_circular
```

## Notas
- Navegación circular.
- Toda la lógica de la lista está encapsulada en `struct ListaCircular` con funciones miembro.
