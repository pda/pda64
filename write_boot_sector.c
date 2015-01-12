#include <stdlib.h>
#include <stdio.h>

FILE * open_image();
void write_code(FILE * f);
void write_boot_signature(FILE * f);
void crash();

// ----------

int main() {
  FILE * f = open_image();
  write_code(f);
  write_boot_signature(f);
  return EXIT_SUCCESS;
}

FILE * open_image() {
  return fopen("pda64.img", "r+");
}

void write_code(FILE * f) {
  fseek(f, 0, SEEK_SET);

  // Write string using BIOS
  // AH = 0x13
  fputc(0xB4, f);
  fputc(0x13, f);

  // BL = yellow (E) on black (0) = 0x0E
  fputc(0xB3, f);
  fputc(0x0E, f);

  // AL = write mode = 0
  fputc(0xB0, f);
  fputc(0x00, f);

  // CX = length("hello pda64") = 11
  fputc(0xB9, f);
  fputc(0x0B, f);
  fputc(0x00, f);

  // DH = row = 0
  fputc(0xB6, f);
  fputc(0x18, f);

  // DL = col = 0
  fputc(0xB2, f);
  fputc(0x00, f);

  // Offset of string = 0
  // ES = 0
  // fputc(0x??, f);
  // BP = 0
  fputc(0xBD, f);
  fputc(0x12, f);
  fputc(0x7C, f);

  // INT 10h
  fputc(0xCD, f);
  fputc(0x10, f);

  fwrite("hello pda64", 11, 1, f);
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
