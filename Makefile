
CC=gcc
CFLAGS=-Wall -g -O -I. -MMD 
LFLAGS=

PROGS=wf
OBJECTS= WordObj.o Node.o List.o HashTable.o  

all: $(PROGS) dox


wf: wf.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)




clean:
	/bin/rm -f *.o


subsystem:
	cd subdir && $(MAKE)
 
