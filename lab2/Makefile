# The following rule means: "if ltest does not exist, or
# is older than ltest.o or list.o,
# then link ltest".
spell: spell.o dictionary.o trigrams.o word.o edit_distance.o
	g++ -o spell spell.o dictionary.o trigrams.o word.o edit_distance.o

# Rules to create the object files.
word.o: word.cc
	g++ -c word.cc -std=c++11
spell.o: spell.cc
	g++ -c spell.cc -std=c++11
dictionary.o: dictionary.cc dictionary.h
	g++ -c dictionary.cc -std=c++11
trigrams.o: trigrams.cc trigrams.h
	g++ -c trigrams.cc -std=c++11
edit_distance.o: edit_distance.cc edit_distance.h
	g++ -c edit_distance.cc -std=c++11
