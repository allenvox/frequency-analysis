CC+FLAGS = gcc -Wall -Werror -Wextra -I src -MMD
DIRGUARD = @mkdir -p $(@D)

all: bin/calcFrequency
-include obj/*.d

bin/calcFrequency: obj/main.o obj/list.o obj/input.o
	$(DIRGUARD)
	$(CC+FLAGS) -o $@ $^

obj/%.o: src/%.c
	$(DIRGUARD)
	$(CC+FLAGS) -c -o $@ $<

clean:
	rm -rf obj/ bin/