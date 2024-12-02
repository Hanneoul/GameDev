#ifndef ELFOBJECT_H  // 정의되어 있지 않으면
#define ELFOBJECT_H  // 정의하고 아래 코드를 컴파일

#include "ElfMath.h"

//행렬 사용할 학생들은 이걸쓰면 편합니다.
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

    Matrix3x3 ModelMatrix;

}GameObjectM_Line;

//행렬 사용 안할 학생들은 이걸 쓰세용
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