#include <stdio.h>

int main() {
  FILE * f = fopen("pda64.img", "r+");
  fseek(f, 0x01FE, SEEK_SET);
  fputc(0x55, f);
  fputc(0xAA, f);
  return 0;
}
