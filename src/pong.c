#include <stdio.h>

#define width 80
#define heigth 25
#define max_count 21

void renderBall();
void renderEmpty();
void renderRakets();
short int print_rracket(const int row, const int col, const int coord);
short int print_lracket(const int row, int const col, const int coord);
void renderBall() { printf("*"); }
void renderEmpty() { printf(" "); }
void renderBorderH() { printf("-"); }
void renderBorderW() { printf("|"); }
void renderRakets() { printf("#"); }
void print_border_y() { printf("-"); }
void print_border_x() { printf("|"); }
void space_entered() { printf("%40s", "\nSpace was entered!\n"); }
void clear_screen() { printf("\33[0d\33[2J"); }

void print_score(short int player_score1, short int player_score2) {
    for (short int i = 0; i < 80; i++) {
        putchar('-');
    }

    printf("\n%25d%30d\n", player_score1, player_score2);
}

short int check_score(short int player_score1, short int player_score2) {
    if (player_score1 == max_count || player_score2 == max_count) {
        printf("%45s", "Game over!\n");
        player_score1 > player_score2 ? printf("%47s", "Player 1 wins!\n")
                                      : printf("%47s", "Player 2 wins!\n");
        return 1;
    }
    return 0;
}

short int print_lracket(const int row, const int col, const int coord) {
    if (col == 2 && (coord == row || coord == row - 1 || coord == row + 1)) {
        renderRakets();
        return 1;
    }
    return 0;
}

short int print_rracket(const int row, const int col, const int coord) {
    if (col == width - 4 && (coord == row || coord == row - 1 || coord == row + 1)) {
        renderRakets();
        return 1;
    }
    return 0;
}

void print_field() {
    short int ballX = 39, ballY = 13;
    short int lRacket = 16, rRacket = 8;
    short int ballDw = -1, ballDh = 1;
    short int p1_score = 0, p2_score = 0;
    char input;
    while (1) {
        if (check_score(p1_score, p2_score) == 1) {
            break;
        }
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
        if (input == 'a') {
            ballX = ballX - 1;
        }
        if (ballX + ballDw == 0 || ballX + ballDw == width - 1) {
            if (ballX + ballDw == 0) {
                p2_score = p2_score + 1;
            } else if (ballX + ballDw == width - 1) {
                p1_score = p1_score + 1;
            }
            ballDw *= -1;
        }
        if (ballY + ballDh == 0 || ballY + ballDh == heigth - 1) {
            ballDh *= -1;
        }
        ballX += ballDw;
        ballY += ballDh;
        clear_screen();
    }
}

int main() {
    print_field();
    return 0;
}
