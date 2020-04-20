cc=g++
target=Growable
objects = main.o
cflags = -W -g

$(target) : $(objects)
	$(cc) $(cflags) -o $(target) $(objects)

.PHONY : clean

clean :
	rm $(target) $(objects)
