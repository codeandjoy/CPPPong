OUT = build/main.out
_src = main.cpp Racket.cpp
src = $(addprefix src/,$(_src))
_obj = main.o Racket.o
obj = $(addprefix build/obj/,$(_obj))
lib = -lsfml-graphics -lsfml-window -lsfml-system

all: $(OUT)

$(OUT): $(obj)
	g++ -o $(OUT) $(obj) $(lib)

$(obj): $(src)
	g++ -c $(src); \
	mkdir -p ./build/obj; \
	mv *.o ./build/obj;

clean:
	rm -rf build
