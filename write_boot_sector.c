#include <stdlib.h>
#include <stdio.h>

FILE * open_image();
void write_boot_signature(FILE * f);
void crash();

// ----------

int main() {
  FILE * f = open_image();
  write_boot_signature(f);
  return EXIT_SUCCESS;
}

FILE * open_image() {
  return fopen("pda64.img", "r+");
}

void write_boot_signature(FILE * f) {
  if (fseek(f, 0x01FE, SEEK_SET) != 0) {
    crash("fseek failed");
  }
  fputc(0x55, f);
  fputc(0xAA, f);
}

void crash(char * message) {
  printf("Crashing: %s\n", message);
  exit(EXIT_FAILURE);
}
