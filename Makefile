all :program

main.o: main.c library.h
		gcc -c $< -o $@

signup.o: signup.c library.h
		gcc -c $< -o $@
		
connectedmenue.o: connectedmenue.c library.h
		gcc -c $< -o $@

program: main.o signup.o connectedmenue.o
		gcc $^ -o $@

