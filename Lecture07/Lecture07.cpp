#include <stdio.h>
#include <conio.h> // Windows 환경에서 getch 사용을 위한 헤더파일
#include <stdlib.h>
#include <time.h>

struct Node
{
    struct Node *UpNode;
    struct Node *DownNode;

    int myNum;
    int piece = 0;
};

Node *root;

int SetTree()
{
    root = (struct Node*)malloc(sizeof(struct Node));
    root->myNum = 2047;
    
    Node* childL = (struct Node*)malloc(sizeof(struct Node));
    Node* childR = (struct Node*)malloc(sizeof(struct Node));
    childL->myNum = 1023;
    childL->myNum = 1024+2047;
    
    childL->DownNode = 0;
    childL->UpNode = 0;

    childR->DownNode = 0;
    childR->UpNode = 0;

    root->DownNode = childL;
    root->UpNode = childR;
}



// 초기화 함수
void Initialize() {
    printf("게임 초기화 중...\n");
}

// 렌더링 함수
void Render() {
    printf("화면을 렌더링 중...\n");

}

// 업데이트 함수 (입력 처리 포함)
void Update() {
    if (_kbhit()) { // 키가 눌렸는지 확인
        char key = _getch(); // 키 입력을 받음
        printf("입력된 키: %c\n", key);

        // 키에 따른 동작 추가 가능
        if (key == 'q') {
            printf("게임 종료...\n");
            exit(0); // 'q'를 입력하면 게임 종료
        }
    }
}

// 메인 게임 루프
void GameLoop() {
    Initialize();

    clock_t start_time = clock(); // 현재 시간을 기록
    while (1) {
        Update(); // Update는 계속 호출하여 키 입력을 처리
        // 현재 시간과 시작 시간의 차이를 확인하여 1초마다 렌더링
        if ((clock() - start_time) >= CLOCKS_PER_SEC) { // CLOCKS_PER_SEC는 1초
            Render();
            start_time = clock(); // 시간을 초기화하여 다음 1초를 기다림
        }
    }
}

int main() {
    GameLoop();
    return 0;
}
