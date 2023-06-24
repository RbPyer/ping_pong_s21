#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


#define width 80
#define heigth 25
#define rocket 3
#define ball 1
#define max_count 21

void print_field() {
    for (uint8_t el_h = 0; el_h <= heigth; ++el_h) {
        for (uint8_t el_w = 0; el_w <= width; ++el_w) {
            if (el_h == 0 || el_h == heigth) {
                printf("-");
            }
            else {
                if (el_w == 0 || el_w == width) {
                    printf("|");
                    continue;
                }
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    print_field();
}
