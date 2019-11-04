CXX = g++
FLAGS = -Wall -lm
ODIR = obj/
IDIR = .

SRCS := $(wildcard *.cpp)
_OBJ := $(patsubst %.cpp, %.o, $(SRCS))
OBJ = $(patsubst %.o, $(ODIR)%.o, $(_OBJ))
DEPS = parser.hpp high-res-timer.hpp

main: $(OBJ)
	@echo "main..."
	$(CXX) -o $@ $^ $(FLAGS)

$(ODIR)%.o: %.cpp $(DEPS)
	@echo "objects..."
	$(CXX) -c -o $@ $< $(FLAGS)

clean:
	@echo "cleaning up"
	rm -rvf $(ODIR)/*.o main
