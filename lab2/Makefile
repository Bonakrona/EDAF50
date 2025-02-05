# The following rule means: "if ltest does not exist, or
# is older than ltest.o or list.o,
# then link ltest".
make_dict: make_dict.o trigrams.o
	g++ -o make_dict make_dict.o trigrams.o

# Rules to create the object files.
make_dict.o: make_dict.cc trigrams.h
	g++ -c make_dict.cc -std=c++11
trigrams.o: trigrams.cc trigrams.h
	g++ -c trigrams.cc -std=c++11
