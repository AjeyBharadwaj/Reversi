#include <stdio.h>

#define SIZE 10

int G_board[SIZE][SIZE];
int G_player;
int G_other_player;

void print_board() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if (G_board[i][j] == 3)
                printf("0 ");
            else
                printf("%d ", G_board[i][j]);
        }
        printf("\n");
    }
    printf("%d", G_other_player);
}

void init_board(char *file_name, char *move_file_name) {
    int i, j, x, y;
    FILE *fp = fopen(file_name, "r");
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            fscanf(fp, "%d", &G_board[i][j]);
        }
    }
    fscanf(fp, "%d", &G_player);
    if (G_player == 1)
        G_other_player = 2;
    else 
        G_other_player = 1;
    
    fclose(fp);
    
    fp = fopen(move_file_name, "r");
    fscanf(fp, "%d %d", &x, &y);
    G_board[x][y] = G_player;
    fclose(fp);
    print_board();
}

int main(int argc, char *argv[]) {
    init_board(argv[1], argv[2]);
    return 0;
}

