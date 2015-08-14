kneighboor: parse.o test.o knn.o unseenPredicted.o
	gcc -o kneighboor parse.c test.c knn.c unseenPredicted.c -lm -Wall

parse.o : parse.c
		gcc -c parse.c
test.o : test.c
		gcc -c test.c
knn.o : knn.c
		gcc -c knn.c
		
unseenPredicted.o : unseenPredicted.c
		gcc -c unseenPredicted.c
clean:
	rm -rf *.o kneighboor
