# Nombre del ejecutable
TARGET = brick_breaker

# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Directorio de SFML (modificar según sea necesario)
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Archivos de código fuente
SOURCES = main.cpp Game.cpp Paddle.cpp Ball.cpp Brick.cpp

# Archivos de objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Regla para generar el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(SFML_LIBS)

# Regla para compilar los archivos fuente
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: clean