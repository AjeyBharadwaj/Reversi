#include <stdio.h>

#define SIZE 10

int G_board[SIZE][SIZE];
int G_output_board[SIZE][SIZE];
int G_player;
int G_other_player;

void print_board() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%d ", G_output_board[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", G_other_player);
}

void make_moves(int x, int y, int player, int other_player) {
    int i, j;
    int found_player = 0;
    int found_other_player = 0;

    found_player = 0;
    found_other_player = 0;
    for(i = y-1; i >= 0; i--) {
        if(G_board[x][i] == player) {
            found_player = 1;
            break;
        } else if(G_board[x][i] == other_player) {
            found_other_player = 1;
        } else if(G_board[x][i] == 0) {
            break;
        }
    }
    if(found_player == 1 && found_other_player == 1) {
        for(i = y-1; i >= 0; i--) {
            if(G_board[x][i] == player || G_board[x][i] == 0) {
                break;
            } else if(G_board[x][i] == other_player) {
                G_output_board[x][i] = player;
            }
        }
    }
    
    found_player = 0;
    found_other_player = 0;
    for(i = y+1; i < SIZE; i++) {
        if(G_board[x][i] == player) {
            found_player = 1;
            break;
        } else if(G_board[x][i] == other_player) {
            found_other_player = 1;
        } else if(G_board[x][i] == 0) {
            break;
        }
    }
    if(found_player == 1 && found_other_player == 1) {
        for(i = y+1; i < SIZE; i++) {
            if(G_board[x][i] == player || G_board[x][i] == 0) {
                break;
            } else if(G_board[x][i] == other_player) {
                G_output_board[x][i] = player;
            }
        }
    }   
    
    found_player = 0;
    found_other_player = 0;
    for(i = x-1; i >= 0; i--) {
        if(G_board[i][y] == player) {
            found_player = 1;
            break;
        } else if(G_board[i][y] == other_player) {
            found_other_player = 1;
        } else if(G_board[i][y] == 0) {
            break;
        }
    }
    if(found_player == 1 && found_other_player == 1) {
        for(i = x-1; i >= 0; i--) {
            if(G_board[i][y] == player || G_board[i][y] == 0) {
                break;
            } else if(G_board[i][y] == other_player) {
                G_output_board[i][y] = player;
            }
        }
    }
    
    found_player = 0;
    found_other_player = 0;
    for(i = x+1; i < SIZE; i++) {
        if(G_board[i][y] == player) {
            found_player = 1;
            break;
        } else if(G_board[i][y] == other_player) {
            found_other_player = 1;
        } else if(G_board[i][y] == 0) {
            break;
        }
    }
    if(found_player == 1 && found_other_player == 1) {
        for(i = x+1; i < SIZE; i++) {
            if(G_board[i][y] == player || G_board[i][y] == 0) {
                break;
            } else if(G_board[i][y] == other_player) {
                G_output_board[i][y] = player;
            }
        }
    }
    
    found_player = 0;
    found_other_player = 0;
    i = x-1;
    j = y-1;
    while(i >= 0 && j >=0) {
        if(G_board[i][j] == player) {
            found_player = 1;
            break;
        } else if(G_board[i][j] == other_player) {
            found_other_player = 1;
        } else if(G_board[i][j] == 0) {
            break;
        }
        i--;
        j--;
    }    
    if(found_player == 1 && found_other_player == 1) {
        i = x-1;
        j = y-1;
        while(i >= 0 && j >=0) {
            if(G_board[i][j] == player || G_board[i][j] == 0) {
                break;
            } else if(G_board[i][j] == other_player) {
                G_output_board[i][j] = player;
            }
            i--;
            j--;
        }  
    }
    
    found_player = 0;
    found_other_player = 0;
    i = x+1;
    j = y+1;
    while(i < SIZE && j < SIZE) {
        if(G_board[i][j] == player) {
            found_player = 1;
            break;
        } else if(G_board[i][j] == other_player) {
            found_other_player = 1;
        } else if(G_board[i][j] == 0) {
            break;
        }
        i++;
        j++;
    }
    if(found_player == 1 && found_other_player == 1) {
        i = x+1;
        j = y+1;
        while(i < SIZE && j < SIZE) {
            if(G_board[i][j] == player || G_board[i][j] == 0) {
                break;
            } else if(G_board[i][j] == other_player) {
                G_output_board[i][j] = player;
            }
            i++;
            j++;
        }  
    }

    found_player = 0;
    found_other_player = 0;
    i = x-1;
    j = y+1;
    while(i >= 0 && j < SIZE) {
        if(G_board[i][j] == player) {
            found_player = 1;
            break;
        } else if(G_board[i][j] == other_player) {
            found_other_player = 1;
        } else if(G_board[i][j] == 0) {
            break;
        }
        i--;
        j++;
    }    
    if(found_player == 1 && found_other_player == 1) {
        i = x-1;
        j = y+1;
        while(i >= 0 && j < SIZE) {
            if(G_board[i][j] == player || G_board[i][j] == 0) {
                break;
            } else if(G_board[i][j] == other_player) {
                G_output_board[i][j] = player;
            }
            i--;
            j++;
        }  
    }
    
    found_player = 0;
    found_other_player = 0;
    i = x+1;
    j = y-1;
    while(i < SIZE && j >= 0) {
        if(G_board[i][j] == player) {
            found_player = 1;
            break;
        } else if(G_board[i][j] == other_player) {
            found_other_player = 1;
        } else if(G_board[i][j] == 0) {
            break;
        }
        i++;
        j--;
    }
    if(found_player == 1 && found_other_player == 1) {
        i = x+1;
        j = y-1;
        while(i < SIZE && j >= 0) {
            if(G_board[i][j] == player || G_board[i][j] == 0) {
                break;
            } else if(G_board[i][j] == other_player) {
                G_output_board[i][j] = player;
            }
            i++;
            j--;
        }  
    }

}


void init_board(char *file_name, char *move_file_name) {
    int i, j, x, y;
    FILE *fp = fopen(file_name, "r");
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            fscanf(fp, "%d", &G_board[i][j]);
            if (G_board[i][j] == 3) {
                G_board[i][j] = 0;
            }
            G_output_board[i][j] = G_board[i][j];
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
    fclose(fp);
   
    G_board[x][y] = G_output_board[x][y] = G_player; 
    make_moves(x, y, G_player, G_other_player);

    print_board();
}

int main(int argc, char *argv[]) {
    init_board(argv[1], argv[2]);
    return 0;
}

