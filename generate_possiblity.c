#include <stdio.h>

#define SIZE 10

int G_board[SIZE][SIZE];
int G_player;
int G_other_player;

void init_board() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            scanf("%d", &G_board[i][j]);
            if (G_board[i][j] == 3)
                G_board[i][j] = 0;
        }
    }
    scanf("%d", &G_player);
    if (G_player == 1)
        G_other_player = 2;
    else 
        G_other_player = 1;
}

void populate_possiblity(int x, int y) {
    int i, j;
    int found = 0;
    
    for(i = y-1; i >= 0; i--) {
        if (G_board[x][i] != G_other_player) {
            if (found == 1 && G_board[x][i] == 0) {
                G_board[x][i] = 3;
            }
            break;
        } else if (G_board[x][i] == G_other_player){
            found = 1;
            continue;
        } else {
            G_board[x][i] = 3;
        }
    }
    
    found = 0;
    for(i = y+1; i < SIZE; i++) {
        if (G_board[x][i] != G_other_player) {
            if (found == 1 && G_board[x][i] == 0) {
                G_board[x][i] = 3;
            }
            break;
        } else if (G_board[x][i] == G_other_player){
            found = 1;
            continue;
        } else {
            G_board[x][i] = 3;
        }
    }
    
    found = 0;
    for(i = x-1; i >= 0; i--) {
        if (G_board[i][y] != G_other_player) {
            if (found == 1 && G_board[i][y] == 0) {
                G_board[i][y] = 3;
            }
            break;
        } else if (G_board[i][y] == G_other_player){
            found = 1;
            continue;
        } else {
            G_board[i][y] = 3;
        }
    }
    
    found = 0;
    for(i = x+1; i < SIZE; i++) {
        if (G_board[i][y] != G_other_player) {
            if (found == 1 && G_board[i][y] == 0) {
                G_board[i][y] = 3;
            }
            break;
        } else if (G_board[i][y] == G_other_player){
            found = 1;
            continue;
        } else {
            G_board[i][y] = 3;
        }
    }
    
    i = x-1;
    j = y-1;
    found = 0;
    while(i >= 0 && j >=0) {
        if (G_board[x][y] != G_other_player) {
            if (found == 1 && G_board[x][y] == 0) {
                G_board[x][y] = 3;
            }
            break;
        } else if (G_board[x][y] == G_other_player){
            found = 1;
            continue;
        } else {
            G_board[x][y] = 3;
        }
        i--;
        j--;
    }
    
    i = x+1;
    j = y+1;
    found = 0;
    while(i < SIZE && j < SIZE) {
        if (G_board[x][y] != G_other_player) {
            if (found == 1 && G_board[x][y] == 0) {
                G_board[x][y] = 3;
            }
            break;
        } else if (G_board[x][y] == G_other_player){
            found = 1;
            continue;
        } else {
            G_board[x][y] = 3;
        }
        i++;
        j++;
    }
        
    i = x-1;
    j = y+1;
    found = 0;
    while(i >= 0 && j >=0) {
        if (G_board[x][y] != G_other_player) {
            if (found == 1 && G_board[x][y] == 0) {
                G_board[x][y] = 3;
            }
            break;
        } else if (G_board[x][y] == G_other_player){
            found = 1;
            continue;
        } else {
            G_board[x][y] = 3;
        }
        i--;
        j++;
    }
    
    i = x+1;
    j = y-1;
    found = 0;
    while(i < SIZE && j < SIZE) {
        if (G_board[x][y] != G_other_player) {
            if (found == 1 && G_board[x][y] == 0) {
                G_board[x][y] = 3;
            }
            break;
        } else if (G_board[x][y] == G_other_player){
            found = 1;
            continue;
        } else {
            G_board[x][y] = 3;
        }
        i++;
        j--;
    }    
}

void generate_possiblity() {
    int i, j, k;
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(G_board[i][j] == G_player) {
                populate_possiblity(i, j);
            }
        }
    }
    
}

int main(int argc, char *argv[]) {
    int i, j;
    
    init_board();
    generate_possiblity();
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%d ", G_board[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", G_player);
    
    return 0;
}

