complexeSportif: complexeSportif.c biblio_complexeSportif.so
	gcc -Wall complexeSportif.c biblio_complexeSportif.so -o complexeSportif

biblio_complexeSportif.so: biblio_complexeSportif.c biblio_complexeSportif.h
	gcc -Wall -c biblio_complexeSportif.c -o biblio_complexeSportif.so

run: complexeSportif
	./complexeSportif
