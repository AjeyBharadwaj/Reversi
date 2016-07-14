#include <stdio.h>

#define SIZE 10

int G_board[SIZE][SIZE];
int G_player;

void init_board() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            scanf("%d", &G_board[i][j]);
        }
    }
    scanf("%d", &G_player);
}

int compute_score_row(int x, int y, int player_num) {
    int i;
    int score = 0;
    int tmp_score = 0;
    
    tmp_score = 0;
    for(i = y-1; i >= 0; i--) {
        tmp_score++;
        if(G_board[x][i] == 0 || G_board[x][i] == 3) {
            break;
        } else if(G_board[x][i] == player_num) {
            score += tmp_score;
            break;
        }
    }
    
    tmp_score = 0;
    for(i = y+1; i < SIZE; i++) {
        tmp_score++;
        if(G_board[x][i] == 0 || G_board[x][i] == 3) {
            break;
        } else if(G_board[x][i] == player_num) {
            score += tmp_score;
            break;
        }
    }
    return score;
}

int compute_score_column(int x, int y, int player_num) {
    int i;
    int score = 0;
    int tmp_score = 0;
    
    tmp_score = 0;
    for(i = x-1; i >= 0; i--) {
        tmp_score++;
        if(G_board[i][y] == 0 || G_board[i][y] == 3) {
            break;
        } else if(G_board[i][y] == player_num) {
            score += tmp_score;
            break;
        }
    }
    
    tmp_score = 0;
    for(i = x+1; i < SIZE; i++) {
        tmp_score++;
        if(G_board[i][y] == 0 || G_board[i][y] == 3) {
            break;
        } else if(G_board[i][y] == player_num) {
            score += tmp_score;
            break;
        }
    }
    return score;
}

int compute_score_RT_LB(int x, int y, int player_num) {
    int i, j;
    int score = 0;
    int tmp_score;
    
    tmp_score = 0;
    i = x-1;
    j = y-1;
    while(i >= 0 && j >=0) {
        tmp_score++;
        if (G_board[i][j] == 0 || G_board[i][j] == 3) {
            break;
        } else if(G_board[i][j] == player_num) {
            score += tmp_score;
            break;
        }
        i--;
        j--;
    }
    
    tmp_score = 0;
    i = x+1;
    j = y+1;
    while(i < SIZE && j < SIZE) {
        tmp_score++;
        if (G_board[i][j] == 0|| G_board[i][j] == 3) {
            break;
        } else if(G_board[i][j] == player_num) {
            score += tmp_score;
            break;
        }
        i++;
        j++;
    }
    
    return score;
}

int compute_score_LT_RB(int x, int y, int player_num) {
    int i, j;
    int score = 0;
    int tmp_score;
    
    tmp_score = 0;
    i = x-1;
    j = y+1;
    while(i >= 0 && j >=0) {
        tmp_score++;
        if (G_board[i][j] == 0 || G_board[i][j] == 3) {
            break;
        } else if(G_board[i][j] == player_num) {
            score += tmp_score;
            break;
        }
        i--;
        j++;
    }
    
    tmp_score = 0;
    i = x+1;
    j = y-1;
    while(i < SIZE && j < SIZE) {
        tmp_score++;
        if (G_board[i][j] == 0 || G_board[i][j] == 3) {
            break;
        } else if(G_board[i][j] == player_num) {
            score += tmp_score;
            break;
        }
        i++;
        j--;
    }
    
    return score;
}

// SCORE is the nubmer of Black dots that I can get by marking [x,y]
int compute_score(int x, int y, int player_num) {
    int score = 0;
    
    // Analyse row
    score += compute_score_row(x, y, player_num);
    
    // Analyse Column
    score += compute_score_column(x, y, player_num);
    
    
    // Analyse Vertical from Right Top to Left Bottom
    score += compute_score_RT_LB(x, y, player_num);
    
    // Analyse Column
    score += compute_score_LT_RB(x, y, player_num);
    
    return score;
}

void decide_next_move() {
    int i, j;
    int score = 0;
    int max_score = 0, x, y;
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if (G_board[i][j] == 3) {
                score = compute_score(i, j, G_player);
                // TODO : Handle in equal case.
                if (score > max_score) {
                    x = i;
                    y = j;
                    max_score = score;
                }
            }
        }
    }
    printf("%d %d", x, y);
}

int main(int argc, char *argv[]) {
    init_board();
    decide_next_move();
    return 0;
}

