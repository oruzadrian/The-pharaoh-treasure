GCC = gcc
CARGS = -std=gnu99

build: comoara

comoara: main.c
	$(GCC) $(CARGS) -o $@ $^

clean:
	rm -f comoara

