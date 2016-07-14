all: reversi generate_possiblity modify find_winner

reversi: reversi.c
	gcc reversi.c -o reversi

generate_possiblity: generate_possiblity.c
	gcc generate_possiblity.c -o generate_possiblity

modify: modify.c
	gcc modify.c -o modify

find_winner: find_winner.c
	gcc find_winner.c -o find_winner

.PHONY: clean
clean: 
	rm -rf reversi generate_possiblity modify find_winner possiblity.log move_done.log modify.log final.log
