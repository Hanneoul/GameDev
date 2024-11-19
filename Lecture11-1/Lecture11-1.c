#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>  // _kbhit(), _getch() 함수 사용을 위한 헤더
#include <windows.h>

#define WIDTH 60
#define HEIGHT 25

// 전역 변수로 스크린 버퍼 선언
char screenBuffer[WIDTH * HEIGHT];
char clearBuffer[WIDTH * HEIGHT];   // 클리어 버퍼 (검정 배경)

int screenWidth = WIDTH;
int screenHeight = HEIGHT;

// 화면 초기화 함수
void Init() {
    // 화면 버퍼를 빈 공백으로 초기화
    for (int i = 0; i < screenWidth * screenHeight; i++) {
        screenBuffer[i] = ' ';  // 검정 배경, 문자 없음
        clearBuffer[i] = ' ';   // 클리어 버퍼도 같은 방식으로 초기화
    }

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
    for (int y = 0; y < screenHeight; y++) {
        for (int x = 0; x < screenWidth; x++) {
            putchar(Buffer[y * screenWidth + x]);
        }
        putchar('\n');
    }
}

// 화면 업데이트 함수
void Update() {
    // "게임중" 텍스트를 화면 중앙에 출력
    const char* message = "게임중";
    int msgLen = 6;  // "게임중"의 길이

    // 중앙 위치 계산
    int startX = (screenWidth - msgLen) / 2;
    int startY = screenHeight / 2;

    // 화면 버퍼에 메시지 삽입 (노란색 텍스트로 표시)
    for (int i = 0; i < msgLen; i++) {
        screenBuffer[(startY * screenWidth) + (startX + i)] = message[i];
    }
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