CXXARGS = -Wall -Wextra -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system
NAME = rtype

SRC =	systems/GraphicSystem.cpp	\
		systems/EventSystem.cpp		\
		components/MovementManager.cpp \
		Entity.cpp					\
		main.cpp

compilar: $(SRC)
	g++ -c $(SRC)
	g++ $(SRC) -o $(NAME) $(CXXARGS)

debug: $(SRC)
	g++ $(SRC) -o $(NAME) $(CXXARGS) -g

clean:
	rm $(NAME)
	rm *.o