strtest: strfxn.c
	gcc strfxn.c -o strtest

run: strtest
	./strtest

clean:
	rm *~
