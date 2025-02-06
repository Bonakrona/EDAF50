# The following rule means: "if ltest does not exist, or
# is older than ltest.o or list.o,
# then link ltest".
spell: spell.o dictionary.o trigrams.o
	g++ -o spell spell.o dictionary.o trigrams.o

# Rules to create the object files.
spell.o: spell.cc
	g++ -c spell.cc -std=c++11
dictionary.o: dictionary.cc dictionary.h
	g++ -c dictionary.cc -std=c++11
trigrams.o: trigrams.cc trigrams.h
	g++ -c trigrams.cc -std=c++11
