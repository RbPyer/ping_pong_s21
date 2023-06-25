#include "ball_functions.c"
#include "game_rules.c"

#define width 80
#define heigth 25
#define rocket 3
#define ball 1


void print_border_y() { printf("-"); }
void print_border_x() { printf("|"); }
void space_entered() { printf("%40s", "\nSpace was entered!\n"); }
void clear_screen() { printf("\33[0d\33[2J");}

void print_field() {
    short int ballX = 39, ballY = 13;
    short int lRacket = 16, rRacket = 8;
    short int ballDw = -1, ballDh = 1;
    short int p1_score = 0, p2_score = 0;
    char input;
    while (1) {
        if (check_score(p1_score, p2_score) == 1) {break;}
        for (short int el_h = -1; el_h < heigth; el_h++) {
            if (el_h == -1) {
                print_score(p1_score, p2_score);
                continue;
            }
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
            putchar('\n');
        }
        scanf("%c", &input);
        ball_move(input, &ballX, &ballY, &ballDw, &ballDh, &p1_score, &p2_score);
        clear_screen();
    }
}
