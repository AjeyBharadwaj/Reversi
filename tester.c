#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[512];
    int movex, movey;

    printf("This is the board. Press your Move :\n");
    system("rm -rf possiblity.log");
    system("./generate_possiblity < final.log > possiblity.log");
    system("cat possiblity.log");

    system("./reversi < possiblity.log");
    printf("\n");
    scanf("%d %d", &movex, &movey);

    system("rm -rf move_done.log");
    snprintf(buf, 512, "echo %d %d > move_done.log", movex, movey);
    system(buf);

    system("rm -rf final.log");
    system("./modify possiblity.log move_done.log > final.log");
}

