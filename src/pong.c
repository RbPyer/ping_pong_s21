#include <stdio.h>

#define width 80      // ширина поля
#define heigth 25     // высота поля
#define max_count 21  // максимум очков

// Блок объявления функций //
void renderBall();                                                       // отрисовка мячика
void renderEmpty();                                                      // отрисовка пробела
void renderRakets();                                                     // отрисовка символа
short int print_rracket(const int row, const int col, const int coord);  // отрисовка правой ракетки
short int print_lracket(const int row, int const col, const int coord);  // отрисовка левой ракетки
void clear_screen();                                                     // очистка экрана
void print_score(short int player_score1, short int player_score2);  // вывод очков
short int check_score(short int player_score1, short int player_score2);  // проверка на конец игры
void pass_width(short int el_h, short int ballX, short int ballY, short int lRacket,
                short int rRacket);  // проход поля по ширине
void print_field();                  // отрисовка поля

// Конец блока объявления функций //

void renderBall() { printf("*"); }
void renderEmpty() { printf(" "); }
void renderRakets() { printf("|"); }
void print_border_y() { printf("-"); }
void print_border_x() { printf("|"); }
void clear_screen() { printf("\33[0d\33[2J"); }

void print_score(short int player_score1, short int player_score2) {
    for (short int i = 0; i < 80; i++) {
        putchar('-');
    }

    printf("\n%25d%30d\n", player_score1, player_score2);
}

short int check_score(short int player_score1, short int player_score2) {
    short int flag = 0;
    if (player_score1 == max_count || player_score2 == max_count) {
        printf("%45s", "Game over!\n");
        player_score1 > player_score2 ? printf("%47s", "Player 1 wins!\n")
                                      : printf("%47s", "Player 2 wins!\n");
        flag = 1;
    }
    return flag;
}

short int print_lracket(const int row, const int col, const int coord) {
    short int flag = 0;
    if (col == 2 && (coord == row || coord == row - 1 || coord == row + 1)) {
        renderRakets();
        flag = 1;
    }
    return flag;
}

short int print_rracket(const int row, const int col, const int coord) {
    short int flag = 0;
    if (col == width - 4 && (coord == row || coord == row - 1 || coord == row + 1)) {
        renderRakets();
        flag = 1;
    }
    return flag;
}

void pass_width(short int el_h, short int ballX, short int ballY, short int lRacket, short int rRacket) {
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
}

short int check_border(short int x, short int dx, short int y, short int dy, short int lRacket,
                       short int rRacket) {
    short int flag = 0;
    short int flag_borders = x + dx == 0 || x + dx == width - 1;
    short int flag_lracket =
        x + dx == 3 && (y + dy == lRacket - 1 || y + dy == lRacket || y + dy == lRacket + 1);
    short int flag_rracket =
        x + dx == width - 4 && (y + dy == rRacket - 1 || y + dy == rRacket || y + dy == rRacket + 1);
    if (flag_borders == 1 || flag_lracket == 1 || flag_rracket == 1) {
        flag = 1;
    }
    return flag;
}

void print_field() {
    short int ballX = 39, ballY = 13, lRacket = 16, rRacket = 8, ballDw = -1, ballDh = 1, p1_score = 0,
              p2_score = 0;
    char input;
    while (check_score(p1_score, p2_score) != 1) {
        for (short int el_h = -1; el_h < heigth; el_h++) {
            if (el_h == -1) {
                print_score(p1_score, p2_score);
                continue;
            }
            pass_width(el_h, ballX, ballY, lRacket, rRacket);
            putchar('\n');
        }
        scanf("%c", &input);  // ввод следующего символа
        switch (input) {
            case 'a':
                (lRacket < 3) ? lRacket : lRacket--;
                break;
            case 'z':
                (lRacket > 21) ? lRacket : lRacket++;
                break;
            case 'k':
                (rRacket < 3) ? rRacket : rRacket--;
                break;
            case 'm':
                (rRacket > 21) ? rRacket : rRacket++;
                break;
        }

        if (check_border(ballX, ballDw, ballY, ballDh, lRacket, rRacket) == 1) {
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
    clear_screen();
    print_field();
    return 0;
}
