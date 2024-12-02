#include <time.h>
#include "ElfTime.h"

static clock_t lastTime = 0;  // static���� ������ �ܺο��� ���� �Ұ�
static double deltaTime = 0.0;

//�ð� �ʱ�ȭ
void ElfTimeInitialize() 
{
    lastTime = clock();  // static���� ������ �ܺο��� ���� �Ұ�
    deltaTime = 0.0;
}

void ElfTimeCalculateDeltaTime() 
{
    clock_t currentTime = clock();  // ���� �ð�
    deltaTime = (double)(currentTime - lastTime) / CLOCKS_PER_SEC;  // ��ŸŸ�� ���
    lastTime = currentTime;  // ������ �ð��� ����
}

double ElfTimeGetDeltaTime() 
{
    return deltaTime;
}