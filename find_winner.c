#include <stdio.h>

#define SIZE 10

int main() {
    int i, j;
    int player[2];
    int val;

    player[0] = player[1] = 0;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            scanf("%d", &val);
            if (val != 0)
                player[val-1]++;
        }
    }
    printf("Player 1 : %d\nPlayer 2 : %d\n", player[0], player[1]);
    if (player[0] > player[1]) 
        printf("Player 1 WON!!!\n");
    else 
        printf("Player 2 WON!!!\n");
}

