all: reversi generate_possiblity modify

reversi: reversi.c
	gcc reversi.c -o reversi

generate_possiblity: generate_possiblity.c
	gcc generate_possiblity.c -o generate_possiblity

modify: modify.c
	gcc modify.c -o modify

.PHONY: clean
clean: 
	rm -rf reversi generate_possiblity modify
