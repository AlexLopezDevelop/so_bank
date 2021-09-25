all:starter # change to project name

main.o: main.c funciones.h tools/reader.h models/banco.h
	gcc -c main.c

reader.o: tools/reader.c tools/reader.h funciones.h models/cliente.h models/banco.h
	gcc -c tools/reader.c

funciones.o: funciones.c funciones.h
	gcc -c funciones.c

servicioBanco.o: tools/servicioBanco.c tools/servicioBanco.h models/banco.h
	gcc -c tools/servicioBanco.c

interfaz.o: tools/interfaz.c tools/interfaz.h funciones.h models/banco.h models/cuenta.h tools/servicioBanco.h
	gcc -c tools/interfaz.c

starter: main.o reader.o funciones.o servicioBanco.o interfaz.o
	gcc main.o reader.o funciones.o servicioBanco.o interfaz.o -o starter.exe
