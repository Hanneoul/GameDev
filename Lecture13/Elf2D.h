#ifndef ELF2D_H  // ELFMATH_H�� ���ǵǾ� ���� ������
#define ELF2D_H  // ELFMATH_H�� �����ϰ� �Ʒ� �ڵ带 ������

void ClearScreen(char* Buffer, int width, int height);

void DrawBuffer(char* Buffer);

void DrawLine(int x1, int y1, int x2, int y2, char* Buffer, int width, int height);

void InitScreen();

#endif