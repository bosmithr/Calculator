calc:	Vm.o Codegen.o
	gcc Vm.o Codegen.o -o calc

#object file targets:
Vm.o: Vm.c Codegen.c

Codegen.o: Codegen.c Codegen.h

# clean target
clean:
	rm *.o calc code.txt
	

