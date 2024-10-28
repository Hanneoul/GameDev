//#include <stdio.h>
//#include <math.h>
//#include <windows.h> // Sleep 함수 사용을 위해 추가
//
//#define WIDTH 40 // 가로 길이 증가
//#define HEIGHT 20 // 세로 길이 증가
//
//#ifndef M_PI
//#define M_PI 3.14159265358979323846
//#endif
//
//void clearScreen() {
//    system("cls"); // Windows에서 콘솔 화면 지우기
//}
//
//void draw(int angle) {
//    clearScreen();
//
//    // P 위치
//    int pX = WIDTH / 2;
//    int pY = HEIGHT / 2;
//
//    // O의 위치 계산 (가로 비율을 보정)
//    float radian = angle * M_PI / 180; // 각도를 라디안으로 변환
//    int oX = (int)(pX + 10 * cos(radian)); // O의 X 위치 (가로 비율 조정)
//    int oY = (int)(pY + 5 * sin(radian)); // O의 Y 위치
//
//    // 화면 그리기
//    for (int y = 0; y < HEIGHT; y++) {
//        for (int x = 0; x < WIDTH; x++) {
//            if (x == pX && y == pY) {
//                printf("P"); // P 출력
//            }
//            else if (x == oX && y == oY) {
//                printf("O"); // O 출력
//            }
//            else {
//                printf(" "); // 빈 공간 출력
//            }
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    for (int angle = 0; angle < 360; angle += 5) {
//        draw(angle); // 회전 각도에 따라 그리기
//        Sleep(100); // 0.1초 대기
//    }
//    return 0;
//}