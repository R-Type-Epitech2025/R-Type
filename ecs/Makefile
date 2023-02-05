CC=g++
# CFLAGS=-c -Wall -I"../../../SFML-2.5.1/include"
LDFLAGS=-L"/opt/homebrew/Cellar/sfml/2.5.1_2/lib" -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=systems/GraphicSystem.cpp systems/EventSystem.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=MyGame

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)





