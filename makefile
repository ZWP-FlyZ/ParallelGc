
GCC = gcc -c
LD 	= gcc 

OBJSET	= gc.o gc_inf.o line_search.o \
		vect_op.o 		



%.o: %.c makefile 
	$(GCC) $*.c -o $*.o

run:$(OBJSET)
	$(LD) *.o -o gc.out

clean:
	rm -f *.o *.out


