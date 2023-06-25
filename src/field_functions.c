#include "ball_functions.c"

#define width 80
#define heigth 25
#define rocket 3
#define ball 1
#define max_count 21


void print_border_y() { printf("-"); }
void print_border_x() { printf("|"); }
void space_entered() { printf("%40s", "\nSpace was entered!\n");}
void ball_move(char input, short int* x, short int* y, short int* dx, short int* dy);

void print_field() {
    short int ballX = 39, ballY = 13;
    short int lRacket = 16, rRacket = 8;
    short int ballDw = -1, ballDh = 1;
    char input;
    while (getchar() != 'z') {
        scanf("%c", &input);
        for (short int el_h = 0; el_h < heigth; el_h++) {
            for (short int el_w = 0; el_w < width; el_w++) {
                if (ballX == el_w && ballY == el_h) {
                    renderBall();
                } else if (el_h == 0 || el_h == heigth - 1) {
                    print_border_y();
                } else if (el_w == 0 || el_w == width - 1) {
                    print_border_x();
                } else {
                    if ((print_lracket(el_h, el_w, lRacket) == 1)) {el_w = el_w + 1;};
                    if ((print_rracket(el_h, el_w, rRacket, width) == 1)) {el_w = el_w + 1;};
                    renderEmpty();
                }
            }
            printf("\n");
        }
        space_entered();
        scanf("%c", &input);
        ball_move(input, &ballX, &ballY, &ballDw, &ballDh);
/*
        if (input == 'a') {
          ballX--;
        }
        if (ballX + ballDw == 0 || ballX + ballDw == width - 1) {
            ballDw *= -1;
        }
        if (ballY + ballDh == 0 || ballY + ballDh == heigth - 1) {
            ballDh *= -1;
        }

        ballX += ballDw;
        ballY += ballDh;*/
    }
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

