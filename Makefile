CC=gcc
DEPS = programs.h
OBJ = main.o Answer.o Office.o Question.o Professor.o Student.o

obj-m += kernel.o
KDIR = /usr/src/kernels/$(shell uname -r)

all:

	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

test: $(OBJ)
	$(CC) -pthread -o $@ $^
	rm *.o

clean:
	rm -rf *.ko *.mod.* *.symvers *.order *test
