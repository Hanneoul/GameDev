#include <stdio.h>
#include <math.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct {
    float m[3][3]; // 3x3 ���
} Matrix3x3;

// 3x3 ��� �ʱ�ȭ
void initIdentityMatrix(Matrix3x3* mat) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                mat->m[i][j] = 1;
            }
            else {
                mat->m[i][j] = 0;
            }
        }
    }
}

// �̵� ��� ����
Matrix3x3 createTranslationMatrix(float tx, float ty) {
    Matrix3x3 mat;
    initIdentityMatrix(&mat);
    mat.m[0][2] = tx; // X�� �̵�
    mat.m[1][2] = ty; // Y�� �̵�
    return mat;
}

// ȸ�� ��� ����
Matrix3x3 createRotationMatrix(float angle) {
    Matrix3x3 mat;
    initIdentityMatrix(&mat);
    float radian = angle * M_PI / 180;
    mat.m[0][0] = cos(radian); // cos(��)
    mat.m[0][1] = -sin(radian); // -sin(��)
    mat.m[1][0] = sin(radian); // sin(��)
    mat.m[1][1] = cos(radian); // cos(��)
    return mat;
}

// ��� ����
Matrix3x3 multiplyMatrices(Matrix3x3 a, Matrix3x3 b) {
    Matrix3x3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = a.m[i][0] * b.m[0][j] + a.m[i][1] * b.m[1][j] + a.m[i][2] * b.m[2][j];
        }
    }
    return result;
}

// ���� ��ȯ
void transformPoint(float* x, float* y, Matrix3x3 mat) {
    float newX = mat.m[0][0] * *x + mat.m[0][1] * *y + mat.m[0][2];
    float newY = mat.m[1][0] * *x + mat.m[1][1] * *y + mat.m[1][2];
    *x = newX;
    *y = newY;
}

// �ܼ� ȭ�� �����
void clearScreen() {
    system("cls");
}



// ȭ�� �׸���
void draw(int angle) {
    clearScreen();

    // P ��ġ
    int pX = WIDTH / 2;
    int pY = HEIGHT / 2;

    // O�� �ʱ� ��ġ
    float oX = 0.0f;
    float oY = 0.0f;

    // �̵� ��� ���� (P���� �Ÿ�)
    Matrix3x3 translationDist = createTranslationMatrix(0, 3);

    // ȸ�� ��� ����
    Matrix3x3 rotation = createRotationMatrix(angle);

    Matrix3x3 translationToP = createTranslationMatrix(pX, pY);

    // O�� ��ġ ��ȯ
    Matrix3x3 combined = multiplyMatrices(rotation, translationDist);
    combined = multiplyMatrices(translationToP, combined);
    transformPoint(&oX, &oY, combined);
    

    // ȭ�� �׸���
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == pX && y == pY) {
                printf("P"); // P ���
            }
            else if ((int)oX == x && (int)oY == y) {
                printf("O"); // O ���
            }
            else {
                printf(" "); // �� ���� ���
            }
        }
        printf("\n");
    }
}

int main() {
    for (int angle = 0; angle < 360; angle += 5) {
        draw(angle); // ȸ�� ������ ���� �׸���
        Sleep(100); // 0.1�� ���
    }
    return 0;
}