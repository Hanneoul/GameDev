#include <time.h>
#include "ElfTime.h"

static clock_t lastTime = 0;  // static으로 선언해 외부에서 접근 불가
static double deltaTime = 0.0;

//시계 초기화
void ElfTimeInitialize() 
{
    lastTime = clock();  // static으로 선언해 외부에서 접근 불가
    deltaTime = 0.0;
}

void ElfTimeCalculateDeltaTime() 
{
    clock_t currentTime = clock();  // 현재 시간
    deltaTime = (double)(currentTime - lastTime) / CLOCKS_PER_SEC;  // 델타타임 계산
    lastTime = currentTime;  // 마지막 시간을 갱신
}

double ElfTimeGetDeltaTime() 
{
    return deltaTime;
}