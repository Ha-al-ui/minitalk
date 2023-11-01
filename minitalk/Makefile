
SRC_C	=	client.c\
			utils.c\
			utils1.c\

SRC_S	=	server.c \
			utils.c\
			utils1.c

C_OBJECTS = $(SRC_C:.c=.o)
S_OBJECTS = $(SRC_S:.c=.o)

CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -f
CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(SERVER): $(S_OBJECTS)
		$(CC) $(CFLAGS) $(S_OBJECTS) -o $(SERVER)

$(CLIENT): $(C_OBJECTS)
		$(CC) $(CFLAGS) $(C_OBJECTS) -o $(CLIENT)
	
%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< 

clean:
	$(RM) $(C_OBJECTS) $(S_OBJECTS)

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(S) $(C)

re: fclean $(CLIENT) $(SERVER) $(S) $(C)

.PHONY: all bonus clean fclean re