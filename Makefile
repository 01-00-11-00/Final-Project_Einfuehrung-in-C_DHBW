NAME 		= student_app

SOURCES 	= $(shell find . -name "*.c")
HEADERS 	= $(shell find . -name "*.h")

OBJECTS 	= $(patsubst %.c, %.o, $(SOURCES))
DEPENDS 	= $(patsubst %.c, %.d, $(SOURCES))

CFLAGS 		= -g

all: $(NAME)

%.o: %.c
	@$(CC) -Iincludes $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "Dependencies Compiled !"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "Compiled !"

clean:
	-@$(RM) $(OBJECTS) $(DEPENDS)
	-@$(RM) $(OBJECTS)
	@echo "Everything is Cleaned !"

fclean: clean
	-@$(RM) $(NAME)

run: all
	./$(NAME)

re: clean all

.PHONY: re run fclean clean all
