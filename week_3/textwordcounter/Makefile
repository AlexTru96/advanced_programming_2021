CC = c++
EXE = wordcounter
OBJS = littlewomen.o src/uniq_counter.o

CFLAGS= -Iinclude
EXTRAFLAGS = -Wall -Wextra -O3 -std=c++14
LFLAGS= -fsanitize=address


$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)
#exe: littlewomen.o src/uniq_counter.o
#c++ -o littlewomen -fsanitize=address littlewomen.o src/uniq_counter.o
%.o:%.cpp
	$(CC) -c $< -o $@ $(CFLAGS) $(EXTRAFLAGS)
#c++ -c littlewomen.cpp -o littlewomen.o -Iinclude  -Wall -Wextra -O0
#c++ -c src/uniq_counter.cpp -o src/uniq_counter.o -Iinclude  -Wall -Wextra -O0

#prerequisites
littlewomen.o: littlewomen.cpp include/struct.h 
src/uniq_counter.o: src/uniq_counter.cpp include/struct.h

#NOT A PHYSICAL FILE
.PHONY: clean default

#CLEAN OBJECTS AND EXECUTABLE FILE
clean:
	rm -f $(OBJS) $(EXE)
