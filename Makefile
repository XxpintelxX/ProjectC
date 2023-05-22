CC = gcc

CFLAGS = -Wall -Wextra

SRC = project.c shape.c manage_shapes.c id.c area.c command.c

OBJS = $(SRC:.c=.o)

NAME = draw

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	rm -rf $(OBJS)

clean:
	rm -f $(NAME)
	rm -rf $(OBJS)

re: clean all

.PHONY: all clean re