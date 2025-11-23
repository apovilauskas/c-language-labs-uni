# C Compilation Stages & Libraries – Quick Demo

Simple project to practice:
- Connecting .c + .h files
- All GCC compilation stages
- Static & dynamic libraries

## Files

- `main.c` – main program, generates random arrays, saves/loads them
- `file.c` – binary write/read functions + global counters
- `file.h` – declarations

## Compilation Stages (Run Any Time)

```bash
# 1. Preprocessor → .i
gcc -E file.c -o file.i
gcc -E main.c -o main.i

# 2. C → Assembly → .s
gcc -S file.c -o file.s
gcc -S main.c -o main.s

# 3. Assembly → Object → .o
gcc -c file.c -o file.o
gcc -c main.c -o main.o
```

## Normal Executable

```bash
gcc main.o file.o -o main       
```

## Static Library

```bash
gcc -c file.c -o file.o
ar rcs libfile.a file.o
gcc main.o -L. -lfile -o main-static   
```

## Dynamic Library

```bash
gcc -c -fPIC file.c -o file.o
gcc -shared file.o -o libfile.dll      
gcc main.o -L. -lfile -o main-dynamic
```
