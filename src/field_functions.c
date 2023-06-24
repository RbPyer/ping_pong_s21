#define width 80
#define heigth 25
#define rocket 3
#define ball 1
#define max_count 21
#define middle heigth / 2

void ball_print();
int bolder(int y);
uint8_t print_rockets(const uint8_t y1);

void print_field() {
  for (uint8_t el_h = 0; el_h < heigth; ++el_h) {
    for (uint8_t el_w = 0; el_w < width; ++el_w) {
      if (el_h == 0 || el_h == heigth - 1) {
        printf("-");
      }
      else {
        if (el_w == 0 || el_w == width - 1) {
          printf("|");
        } 
        else {
          if (el_w == 4 || el_w == width - 5) {
            if (print_rockets(el_h) == 1) {continue;};
          }
          printf(" ");
        }
      }
    }
    printf("\n");
  }
}

uint8_t print_rockets(const uint8_t y1) {
  if (y1 == middle - 1 || y1 == middle || y1 == middle + 1) {
    printf("#");
    return 1;
  }
  return 0;
}