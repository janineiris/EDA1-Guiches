output: main.o Fila.o ListaEncadeada.o Pilha.o
	gcc main.o Fila.o ListaEncadeada.o Pilha.o -o output

main.o: main.c
	gcc -c main.c

Fila.o: Fila.c
	gcc -c Fila.c

ListaEncadeada.o: ListaEncadeada.c
	gcc -c ListaEncadeada.c

Pilha.o: Pilha.c
	gcc -c Pilha.c

clean:
	rm *.o output
