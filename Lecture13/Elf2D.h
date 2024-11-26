#ifndef ELF2D_H  // ELFMATH_H가 정의되어 있지 않으면
#define ELF2D_H  // ELFMATH_H를 정의하고 아래 코드를 컴파일

void ClearScreen(char* Buffer, int width, int height);

void DrawBuffer(char* Buffer);

void DrawLine(int x1, int y1, int x2, int y2, char* Buffer, int width, int height);

void InitScreen();

#endif