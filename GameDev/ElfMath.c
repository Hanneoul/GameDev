#include "ElfMath.h"

//단위행렬(Identity Matrix) 생성
Matrix3x3 identity_matrix() 
{
    Matrix3x3 mat = { 
        {
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f}
        } 
    };
    return mat;
}

//이동행렬(Translation Matrix) 생성
Matrix3x3 translation_matrix(float dx, float dy) 
{
    Matrix3x3 mat = { 
        {
            {1.0f, 0.0f, dx},
            {0.0f, 1.0f, dy},
            {0.0f, 0.0f, 1.0f}
        } 
    };
    return mat;
}

//회전행렬(Rotation Matrix) 생성
Matrix3x3 rotation_matrix(float theta) 
{
    float radians = theta * (3.14159265359f / 180.0f);  // 각도를 라디안으로 변환
    Matrix3x3 mat = { 
        {
            {cosf(radians), -sinf(radians), 0.0f},
            {sinf(radians), cosf(radians), 0.0f},
            {0.0f, 0.0f, 1.0f}
        } 
    };
    return mat;
}

//크기조정행렬(Scale Matrix) 생성 
Matrix3x3 scale_matrix(float sx, float sy) 
{
    Matrix3x3 mat = { 
        {
            {sx, 0.0f, 0.0f},
            {0.0f, sy, 0.0f},
            {0.0f, 0.0f, 1.0f}
        } 
    };
    return mat;
}

//행렬곱셈
Matrix3x3 multiply_matrices(Matrix3x3 a, Matrix3x3 b) 
{
    Matrix3x3 result = { {{0}} };

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j) 
        {
            for (int k = 0; k < 3; ++k) 
            {
                result.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return result;
}

Vector3 multiply_matrix_vector(Matrix3x3 mat, Vector3 v) 
{
    Vector3 result;
    result.x = mat.m[0][0] * v.x + mat.m[0][1] * v.y + mat.m[0][2] * v.z;
    result.y = mat.m[1][0] * v.x + mat.m[1][1] * v.y + mat.m[1][2] * v.z;
    result.z = mat.m[2][0] * v.x + mat.m[2][1] * v.y + mat.m[2][2] * v.z;
    return result;
}

// 행렬과 벡터 곱셈 (동차 좌표를 고려한 2D 변환)
Vector2 multiply_matrix_vector2(Matrix3x3 mat, Vector2 v)
{
    Vector2 result;

    // 동차 좌표 (x, y, 1)로 확장된 벡터와 행렬 곱셈
    result.x = mat.m[0][0] * v.x + mat.m[0][1] * v.y + mat.m[0][2] * 1.0f;
    result.y = mat.m[1][0] * v.x + mat.m[1][1] * v.y + mat.m[1][2] * 1.0f;

    return result;
}


//행렬 안쓰실 분들은 이거 쓰세요

// 이동 (Translation)
Vector2 translate(Vector2 position, Vector2 translation)
{
    Vector2 result;
    result.x = position.x + translation.x;
    result.y = position.y + translation.y;
    return result;
}

// 회전 (Rotation)
Vector2 rotate(Vector2 position, float angle)
{
    float radians = angle * (3.14159265359f / 180.0f);  // 각도를 라디안으로 변환
    Vector2 result;
    result.x = position.x * cosf(radians) - position.y * sinf(radians);
    result.y = position.x * sinf(radians) + position.y * cosf(radians);
    return result;
}

// 크기 조정 (Scaling)
Vector2 scale(Vector2 position, float scaleX, float scaleY)
{
    Vector2 result;
    result.x = position.x * scaleX;
    result.y = position.y * scaleY;
    return result;
}