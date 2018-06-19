
G++ = g++ -fopenmp

all:
	$(G++) *.c -o gc.out

clean:
	rm -f *.o *.out


