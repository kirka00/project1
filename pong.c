#include <stdio.h>

int fieldrendering(int racketL_x, int racketL_y, int racketR_x, int racketR_y, int ball_x, int ball_y,
                   int score1, int score2);  // drawing pong

int main() {
    int score1 = 0, score2 = 0;          // player points
    int racketL_x = 8, racketL_y = 12;   // left player's position on the field
    int racketR_x = 72, racketR_y = 12;  // right player's position on the field
    int ball_x = 40, ball_y = 12;        // ball position on the field
    fieldrendering(racketL_x, racketL_y, racketR_x, racketR_y, ball_x, ball_y, score1, score2);
    while (score1 != 21 || score2 != 21) {
    }
    if (score1 == 21) {  // let's check who won
        printf("              Left player wins! You deserved it!    \n");
        return 0;
    } else if (score2 == 21) {
        printf("              Right player wins! You deserved it!    \n");
        return 0;
    } else {
        return 0;
    }
}

int fieldrendering(racketL_x, racketL_y, racketR_x, racketR_y, ball_x, ball_y, score1, score2) {
    printf("\033[0d\033[2J");  // clearing the console
    printf("                                      %d : %d        \n", score1,
           score2);                                  // displaying points on the screen
    for (int height = 0; height <= 25; height++) {   // field height
        for (int width = 0; width <= 80; width++) {  // field width
            if (height == 0 || height == 25) {       // horizontal borders
                printf("-");
            } else if ((width == 0 && height > 0 && height < 25) ||
                       (width == 80 && height > 0 && height < 25)) {  // vertical borders
                printf("|");
            } else if ((width != ball_x || height != ball_y) && width == 40 && height >= 1 &&
                       height <= 24) {  // dividing line
                printf("|");
            } else if ((width == racketL_x && height == racketL_y) ||
                       (width == racketL_x && height + 1 == racketL_y) ||
                       (width == racketL_x && height - 1 == racketL_y)) {  // left player
                printf("|");
            } else if ((width == racketR_x && height == racketR_y) ||
                       (width == racketR_x && height + 1 == racketR_y) ||
                       (width == racketR_x && height - 1 == racketR_y)) {  // right player
                printf("|");
            } else if (width == ball_x && height == ball_y) {  // ball
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}