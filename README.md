The goal of this programm is to find the quickest way to get n ants across the farm.

At the beginning of the game, all the ants are in the room ##start.
The goal is to bring them to the room ##end with as few turns as possible.
Each room can only contain one ant at a time.
(except at ##start and ##end which can contain as many ants as necessary.)

At each turn you can move each ant only once and through a tube (the room at the receiving end must be empty).

Program get data from standart output in the following format: number_of_ants, the_rooms, the_links
following one to each other strictly in this order:

###The NUMBER OF ANTS should be a positive number
	between 1 and max-integer value (2147483647) Every other input would cause an ERROR.
	Whitespaces are not supported.

###ROOMS format contains 3 blocks separated by spaces:
---name:
	is a unique string, but it shouldn't start with spaces,
	'L' and '#' symbols and can not contain a '-' and ' ' symbols
---coordinates X and Y separated by spaces.
	They are a positive integers just like the number of ant, but they are supporting a zero value.

IMPORTANT!
	The coordinates for each room and a room name are unique.
	Duplicating them on input will cause an ERROR message

###LINKS:
	two names of rooms that already exist on input separated by one '-' symbol
	every occurance of deprecated in ROOMS field symbols will cause an ERROR

###COMANDS:
	start with "##". The programm support only two types of commands
	##start and ##end followed by corresponding rooms
	every input can contain only one start and only one end
	every unknown command would be marked as a coment

###COMENTS
	start with '#' symbol
	this type of input can be placed everywhere

EXAMPLE:
3
2 5 0
##start
0 1 2
##end
1 9 2
3 5 4
0-2
0-3
2-1
3-1
2-3

If a valid input turned in 
Program shows the input data and a shortest path with minimal ants moves.
However it supportes a several flags that may be used together:

EXAMPLE:
	./lem-in [-pdmq] < [...file path];
	./lem-in [--help] to view this message :)

FLAGS:
	[-d] is a debug option. It shows contain of a main data structure
			after reading it and handle more gentle
			and straight error messages if input is invalid
	[-p] print all valid founded path to input graph.
	[-m] change algorithm to move ants not in minimal steps, but in minimal turns
	[-q] quiet mode hide an input and shows only result of
			programm execution if other flags are not set

For any additional information you may contact me on e-mail
dmelehov1986@gmail.com

Copyright (C) 2018 bla bla bla

Have a nice time!!!
:)
