#include "ball_functions.c"

#define width 80
#define heigth 25
#define rocket 3
#define ball 1
#define max_count 21

void print_border_y() { printf("-"); }
void print_border_x() { printf("|"); }
void space_entered() { printf("%40s", "\nSpace was entered!\n"); }

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
                    if ((print_lracket(el_h, el_w, lRacket) == 1)) {
                        el_w = el_w + 1;
                    };
                    if ((print_rracket(el_h, el_w, rRacket) == 1)) {
                        el_w = el_w + 1;
                    };
                    renderEmpty();
                }
            }
            printf("\n");
        }
        space_entered();
        scanf("%c", &input);
        ball_move(input, &ballX, &ballY, &ballDw, &ballDh);
    }
}
