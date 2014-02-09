# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kube <kube@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 02:31:26 by cfeijoo           #+#    #+#              #
#    Updated: 2014/02/09 18:46:46 by kube             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVERNAME = serveur
CLIENTNAME = client

INCLUDEFOLDERS = -I./includes/ -I./libft/includes
LIBFOLDERS = -L./libft/
LIBS = -lft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVERFILES =	server.c

CLIENTFILES =	client.c

CLIENTOBJECTS = $(CLIENTFILES:.c=.o)
SERVEROBJECTS = $(SERVERFILES:.c=.o)

all: client server

client :
	$(CC) -c $(CLIENTFILES) $(INCLUDEFOLDERS) $(CFLAGS)
	$(CC) $(CLIENTOBJECTS) $(INCLUDEFOLDERS) $(LIBFOLDERS) $(LIBS) $(CFLAGS) -o $(CLIENTNAME)

server :
	$(CC) -c $(SERVERFILES) $(INCLUDEFOLDERS) $(CFLAGS)
	$(CC) $(SERVEROBJECTS) $(INCLUDEFOLDERS) $(LIBFOLDERS) $(LIBS) $(CFLAGS) -o $(SERVERNAME)

complibs :
	make -C libft re

updatelibs :
	cd libft && git pull
	$(MAKE) complibs

clean :
	rm -f $(SERVEROBJECTS)
	rm -f $(CLIENTOBJECTS)

fclean : clean
	rm -f $(SERVERNAME)
	rm -f $(CLIENTNAME)

re : fclean all
