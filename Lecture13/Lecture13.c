#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>  // _kbhit(), _getch() 함수 사용을 위한 헤더

#include "ElfMath.h"
#include "Elf2D.h"

#define WIDTH 60
#define HEIGHT 25

typedef struct
{
    //Transform
    Vector2 Position;
    float Rotation;
    Vector2 Scale;

    //Geometry
    Vector2 Line[2];

    char* Symbol;

}GameObject_Line;

// 0: 입력없음
// 99 : 게임 종료
int Input()
{
    // ESC 키를 눌렀는지 확인
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 27) {  // ESC 키가 눌리면 게임 종료
            return 99;
        }
    }

    return 0;
}


void Update(GameObject_Line* obj, int objNum, int inputEvent)
{    
    
}

//
void Render(GameObject_Line* obj, int objNum, char* Buf, int width, int height)
{
    Vector3 lineA, lineB;
    Matrix3x3 world = identity_matrix();    //단위행렬로 초기화

    lineB.x = 0;
    lineB.y = 0;

    int i = 0;
   
        obj[i].Position.x = lineB.x;
        obj[i].Position.y = lineB.y;

        lineA.x = obj[i].Line[0].x;
        lineA.y = obj[i].Line[0].y;
        lineA.z = 1;
        lineB.x = obj[i].Line[1].x;
        lineB.y = obj[i].Line[1].y;
        lineB.z = 1;

        Matrix3x3 scale = scale_matrix(obj[i].Scale.x, obj[i].Scale.y); // 크기조정 행렬 적용
        Matrix3x3 rotation = rotation_matrix(obj[i].Rotation);// 회전 행렬 생성
        Matrix3x3 translation = translation_matrix(obj[i].Position.x, obj[i].Position.y); // 이동 행렬 적용
        
        world = multiply_matrices(scale, world);
        world = multiply_matrices(rotation, world);
        world = multiply_matrices(translation, world);
        lineA = multiply_matrix_vector(world, lineA);  // 점과 회전 행렬 곱셈 (Matrix3x3 * Vector3)
        lineB = multiply_matrix_vector(world, lineB);  // 점과 회전 행렬 곱셈 (Matrix3x3 * Vector3)

        Elf2DDrawLine((int)lineA.x, (int)lineA.y, (int)lineB.x, (int)lineB.y, Buf, width, height);
 

}


// 게임 루프
int main() {
    int fps = 60;
    double frameTime = 1000.0 / fps;

    // 전역 변수로 스크린 버퍼 선언
    char screenBuffer[(WIDTH + 1) * HEIGHT];
    int screenWidth = WIDTH;
    int screenHeight = HEIGHT;

    GameObject_Line LineObj[3];

    // 게임 초기화
    Elf2DInitScreen();
    Elf2DClearScreen(screenBuffer, screenWidth, screenHeight);
    Elf2DDrawBuffer(screenBuffer);

    //객체 초기화(관절 3개)
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        LineObj[i].Position.x = 0;
        LineObj[i].Position.y = 0;

        LineObj[i].Rotation = 0;
        
        
        //(0,0) ~ (3,0) 을 잇는 직선
        LineObj[i].Line[0].x = 0;
        LineObj[i].Line[0].y = 0;

        LineObj[i].Line[1].x = 3;
        LineObj[i].Line[1].y = 0;
    }

    LineObj[1].Rotation = 30;
    LineObj[2].Rotation = 30;

    //화면 출력 심볼 입력
    LineObj[0].Symbol = "11";
    LineObj[1].Symbol = "22";
    LineObj[2].Symbol = "33";

    //크기 입력
    LineObj[0].Scale.x = 1;
    LineObj[0].Scale.y = 1;
    LineObj[1].Scale.x = 2;
    LineObj[1].Scale.y = 2;
    LineObj[2].Scale.x = 2;
    LineObj[2].Scale.y = 2;

    


    // 프레임 타이머
    clock_t lastTime = clock();

    while (1) {
        
        int event = Input();
        //입력 계산
        if (event == 99)
        {
            break;
        }
              
        // 게임 업데이트
        Update(LineObj, 3, event);

        // 스크린버퍼에 게임 렌더링
        Render(LineObj, 3, screenBuffer, screenWidth, screenHeight);

        // 화면 그리기
        Elf2DDrawBuffer(screenBuffer);
        
        // 현재 시간 계산
        clock_t now = clock();
        double deltaTime = (double)(now - lastTime) / CLOCKS_PER_SEC * 1000.0;
        Elf2DSleep(frameTime - deltaTime);
        lastTime = now;
    }

    return 0;
}