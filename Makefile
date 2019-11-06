CXX = g++
CPATH = inc
FLAGS = -Wall -lm
ODIR = obj/
IDIR = inc/
LDIR = lib/

LIBS := $(wildcard $(LDIR)*.a)

SRCS := $(wildcard *.cpp)
_OBJ := $(patsubst %.cpp, %.o, $(SRCS))
OBJ = $(patsubst %.o, $(ODIR)%.o, $(_OBJ))
DEPS = $(wildcard $(IDIR)*.hpp)

main: $(OBJ)
	@echo "main..."
	$(CXX) -o $@ $^ $(FLAGS) $(LIBS)

$(ODIR)%.o: %.cpp $(DEPS)
	@echo "objects..."
	$(CXX) -c -o $@ $< $(FLAGS)

clean:
	@echo "cleaning up"
	rm -rvf $(ODIR)/*.o main
