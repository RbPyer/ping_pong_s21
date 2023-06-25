#define width 80
#define heigth 25

void renderBall();
void renderEmpty();
void renderRakets();
short int print_rracket(const int row, const int col, const int coord);
short int print_lracket(const int row, int const col, const int coord);
void ball_move(char input, short int* x, short int* y, short int* dx, short int* dy);

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

void ball_move(char input, short int* x, short int* y, short int* dx, short int* dy) {
    if (input == 'a') {
        *x = *x - 1;
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