#include "ball_functions.c"

#define width 80
#define heigth 25
#define rocket 3
#define ball 1
#define max_count 21
#define middle heigth / 2

void ball_print();
int bolder(int y);
short int print_rockets(const short int y1);

void print_border_y() { printf("-"); }
void print_border_x() { printf("|"); }

void print_field() {
    short int ballX = 39, ballY = 13;
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

                } else if (el_w == 4 || el_w == width - 5) {
                    if (print_rockets(el_h) == 1) {
                      el_w++;
                    };
                } else {
                    printf(" ");
                }
                /*if (el_w == 4 || el_w == width - 5) {
                    if (print_rockets(el_h) == 1) {
                    };
                }*/
            }
            printf("\n");
        }
    }
}




short int print_rockets(const short int y1) {
    if (y1 == middle - 1 || y1 == middle || y1 == middle + 1) {
        printf("#");
        return 1;
    }
    return 0;
}