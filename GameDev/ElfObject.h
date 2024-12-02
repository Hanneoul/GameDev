#ifndef ELFOBJECT_H  // ���ǵǾ� ���� ������
#define ELFOBJECT_H  // �����ϰ� �Ʒ� �ڵ带 ������

#include "ElfMath.h"

//���� ������Ʈ
typedef struct
{
    //Transform
    Vector2 Position;
    float Rotation;
    Vector2 Scale;

    //Geometry
    Vector2 Line[2];

    //�ȼ�ä�� ����
    char* Symbol;

}GameObject_Line;

#endif