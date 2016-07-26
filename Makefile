CC	= cc
RM	= rm -f

NAME	= merreles

SRCS	= src/main.c \
	  src/xmalloc.c \
	  src/game_create.c \
	  src/game_init.c \
	  src/game_loop.c \
	  src/game_update.c \
	  src/game_draw.c \
	  src/game_win.c \
	  src/game_sleep.c \
	  src/game_quit.c \
	  src/field_index.c \
	  src/field_count.c \
	  src/field_line.c \
	  src/field_move.c \
	  src/phase_one.c \
	  src/phase_two.c \
	  src/phase_del.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -Wall -Wextra -pedantic
CFLAGS	+= -Isrc/
LDFLAGS	+= -lSDL_ttf -lSDL_image -lSDLmain -lSDL

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
