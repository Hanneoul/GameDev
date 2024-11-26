#ifndef ELF2D_H  // ELFMATH_H가 정의되어 있지 않으면
#define ELF2D_H  // ELFMATH_H를 정의하고 아래 코드를 컴파일

void Elf2DClearScreen(char* Buffer, int width, int height);

void Elf2DDrawBuffer(char* Buffer);

void Elf2DDrawLine(int x1, int y1, int x2, int y2, char* Buffer, int width, int height);

void Elf2DInitScreen();

void Elf2DSleep(int ms);

#endif