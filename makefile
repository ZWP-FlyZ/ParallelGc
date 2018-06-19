
# G++ = g++ -fopenmp
G++ = g++ 
all:
	$(G++) *.c -o gc.out

clean:
	rm -f *.o *.out


