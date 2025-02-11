ht.exe: ht.o avlFunktiot.o kirjasto.o
	gcc ht.o avlFunktiot.o kirjasto.o -o ht.exe
ht.o: ht.c ht.h
	gcc ht.c -c -std=c99
avlFunktiot.o: avlFunktiot.c avlFunktiot.h
	gcc avlFunktiot.c -c -std=c99
kirjasto.o: kirjasto.c kirjasto.h
	gcc kirjasto.c -c -std=c99
	