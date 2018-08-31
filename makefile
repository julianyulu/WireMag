PROG = run
CC = g++

CPPFLAGS = -g -Wall

# LDFLAGS = -lboost_iostreams -lboost_system -lboost_filesystem

OBJS = main.o wire.o biotSavartLaw.o vectorOperation.o mesh.o


$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS) 

main.o: main.h
	$(CC) $(CPPFLAGS) -c main.cc

vectorOperation.o: vectorOperation.h
	$(CC) $(CPPFLAGS) -c vectorOperation.cc

wire.o: wire.h
	$(CC) $(CPPFLAGS) -c wire.cc

mesh.o: mesh.h
	$(CC) $(CPPFLAGS) -c mesh.cc


biotSavartLaw.o: biotSavartLaw.h
	$(CC) $(CPPFLAGS) -c biotSavartLaw.cc

clean:
	rm $(PROG) $(OBJS) *.csv
