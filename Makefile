cc = gcc -std=c99 



make:
	$(cc) -Wall -c ./src/*.c
	$(cc) ./*.o -o bed

debug:
	$(cc) -Wall -c -g ./src/*.c
	$(cc) ./*.o -o bed;

clean:
	rm -rf ./*.o


