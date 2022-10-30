main: main.o invert.o box.o scale.o imageio.o
	g++ -o main main.o invert.o box.o scale.o imageio.o

main.o: main.cpp imageio.h
	g++ -c main.cpp

invert.o: invert.cpp imageio.h
	g++ -c invert.cpp

box.o: box.cpp imageio.h
	g++ -c box.cpp

scale.o: scale.cpp imageio.h
	g++ -c scale.cpp

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h


clean:
	rm -f *o
