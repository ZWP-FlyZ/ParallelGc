
G++ = g++ -fopenmp -lm

all:
	$(G++) *.c -o gc.out

clean:
	rm -f *.o *.out


