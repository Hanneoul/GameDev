#ifndef ELFOBJECT_H  // 정의되어 있지 않으면
#define ELFOBJECT_H  // 정의하고 아래 코드를 컴파일

#include "ElfMath.h"

//게임 오브젝트
typedef struct
{
    //Transform
    Vector2 Position;
    float Rotation;
    Vector2 Scale;

    //Geometry
    Vector2 Line[2];

    //픽셀채울 글자
    char* Symbol;

}GameObject_Line;

#endif