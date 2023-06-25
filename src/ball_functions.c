#include <stdio.h>

void renderBall();
void renderEmpty();
void renderBorderH();
void renderBorderW();
void renderRakets();
short int print_rracket(const int row, const int col, const int coord, const int width);
short int print_lracket(const int row, int const col, const int coord);
void ball_move(char input, short int* x, short int* y, short int* dx, short int* dy)


/*int main() {
    int width = 80;
    int height = 25;
    int ballW = 70;
    int ballH = 13;
    int ballDw = -1;
    int ballDh = 1;
    int lRacket = 16;
    int rRacket = 8;
    char a;

    while (getchar() != 'z') {
        // move(a, &ballH);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (ballW == j && ballH == i) {
                    renderBall();
                } else if (j == 0 || j == width - 1) {
                    renderBorderW();
                } else if (i == 0 || i == height - 1) {
                    renderBorderH();
                } else {
                    if ((print_lracket(i, j, lRacket) == 1)) {j = j + 1;};
                    if ((print_rracket(i, j, rRacket, width) == 1)) {j = j + 1;};
                    renderEmpty();
                }
            }
            printf("\n");
        }
        space_entered();
        scanf("%c", &a);
        /*if (a == 'a') {
          ballW--;
        }
        if (ballW + ballDw == 0 || ballW + ballDw == width - 1) {
            ballDw *= -1;
        }
        if (ballH + ballDh == 0 || ballH + ballDh == height - 1) {
            ballDh *= -1;
        }

        ballW += ballDw;
        ballH += ballDh;
    }

    return 0;
} */

short int print_lracket(const int row, const int col, const int coord) {
    if (col == 2 && (coord == row || coord == row - 1 || coord == row + 1)) {
        renderRakets();
        return 1;
    }
    return 0;
}

short int print_rracket(const int row, const int col, const int coord, const int width) {
    if (col == width - 4 && (coord == row || coord == row - 1 || coord == row + 1)) {
        renderRakets();
        return 1;
    }
    return 0;
}


void ball_move(char input, short int* x, short int* y, short int* dx, short int* dy) {
    if (input == 'a') {
          *x--;
        }
        if (*x + *dx == 0 || *x + *dx == width - 1) {
            *dx *= -1;
        }
        if (*y + *dy == 0 || *y + *dy == heigth - 1) {
            *dy *= -1;
        }
        *x += *dx;
        *y += *dy;
}

void renderBall() { printf("*"); }
void renderEmpty() { printf(" "); }
void renderBorderH() { printf("-"); }
void renderBorderW() { printf("|"); }
void renderRakets() { printf("#"); }
/*void move(char l, int b) {
  if (l == 'A' || l == 'a') {
    ;
  }
  printf("Ball == %d", *b);
}*/
