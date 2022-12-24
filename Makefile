run: main.o
	gcc main.c -o run
clean: 
	rm -f run main.o