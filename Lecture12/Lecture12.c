#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>  // _kbhit(), _getch() 함수 사용을 위한 헤더
#include <windows.h>

#include "ElfMath.h"

#define WIDTH 60
#define HEIGHT 25

// 전역 변수로 스크린 버퍼 선언
char screenBuffer[(WIDTH+1) * HEIGHT];
int screenWidth = WIDTH;
int screenHeight = HEIGHT;

// 화면 초기화 함수
void ClearScreen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screenBuffer[i * (WIDTH + 1) + j] = ' ';  // 화면 초기화
        }
        screenBuffer[i * (WIDTH + 1) + WIDTH] = '\n';  // 개행 문자
    }
   
}

// 두 점을 연결하는 직선을 그리는 함수 (브레젠햄 알고리즘)
void DrawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if (x1 >= 0 && x1 < WIDTH && y1 >= 0 && y1 < HEIGHT) {
            screenBuffer[y1 * (WIDTH + 1) + x1] = '*';  // 화면에 점을 찍음
        }

        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

// 그네의 움직임을 구현하는 함수
void Render(float angle) {

    

    Vector3 p1 = { 0.0f, 3.0f, 1.0f };

    // 두 번째 관절 (회전된 첫 번째 선 끝점)
    Vector3 p2 = { 0.0f, 3.0f, 1.0f };

    // 세 번째 관절 (회전된 두 번째 선 끝점)
    Vector3 p3 = { 0.0f, 3.0f, 1.0f };

    // 회전 적용
    // 첫번째 관절 회전
    Matrix3x3 translation_w = translation_matrix(30, 0);
    Matrix3x3 rotation = rotation_matrix(angle);// 회전 행렬 생성
    Matrix3x3 translation = translation_matrix(0,3);
    Matrix3x3 World = multiply_matrices(translation, rotation);
    World = multiply_matrices(translation_w, World);
    p1 = multiply_matrix_vector(World, p1);  // 점과 회전 행렬 곱셈 (Matrix3x3 * Vector3)

    //두번째 관절 연산
    World = multiply_matrices(World, translation);
    World = multiply_matrices(World, rotation);
    p2 = multiply_matrix_vector(World, p2);  // 점과 회전 행렬 곱셈 (Matrix3x3 * Vector3)

    
    // 세 번째 관절 회전
    World = multiply_matrices(World, translation);
    World = multiply_matrices(World, rotation);
    p3 = multiply_matrix_vector(World, p3);  // 점과 회전 행렬 곱셈 (Matrix3x3 * Vector3)
    
    // 첫 번째 선 그리기
    DrawLine(p1.x, p1.y, (int)p2.x, (int)p2.y);

    // 두 번째 선 그리기
    DrawLine((int)p2.x, (int)p2.y, (int)p3.x, (int)p3.y);

    // 세 번째 선 그리기
    DrawLine((int)30, (int)0, p1.x, p1.y);  // 마지막 선 (고정점으로 돌아가도록)
}


// 게임 초기화 함수
void Init() {
    
    ClearScreen();

    //커서 숨기기
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE;  // 커서를 숨김
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// 화면을 그리는 함수
void Draw(char* Buffer) {
    //0,0으로 이동
    COORD coord = { 0, 0 };  // 좌표 (0, 0)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // 스크린 버퍼 출력
    printf("%s", screenBuffer);  // 화면 출력
}

float angle = 0;

// 화면 업데이트 함수
void Update() {
    ClearScreen();
    Render(angle);
    angle += 10;
}

// 게임 루프
int main() {
    // 게임 초기화
    Init();

    // 프레임 타이머
    clock_t lastTime = clock();
    int fps = 60;
    double frameTime = 1000.0 / fps;

    while (1) {
        // ESC 키를 눌렀는지 확인
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 27) {  // ESC 키가 눌리면 게임 종료
                break;
            }
        }

        // 현재 시간 계산
        clock_t now = clock();
        double deltaTime = (double)(now - lastTime) / CLOCKS_PER_SEC * 1000.0;

        // 프레임 제한 (60fps 유지)
        if (deltaTime >= frameTime) {
            lastTime = now;

            // 게임 업데이트
            Update();

            // 화면 그리기
            //Draw(clearBuffer);
            Draw(screenBuffer);
        }
    }

    return 0;
}