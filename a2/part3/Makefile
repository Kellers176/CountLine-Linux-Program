all: countln.exe

countln.exe: countln.o
	gcc -o countln.exe countln.o

countln.o: countln.c
	gcc -c countln.c
     
clean:
	rm countln.o 
	rm countln.exe
