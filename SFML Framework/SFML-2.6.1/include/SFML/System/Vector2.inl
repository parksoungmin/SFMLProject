#include "Vector2.hpp"
////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2023 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>::Vector2() :
    x(0),
    y(0)
{

}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>::Vector2(T X, T Y) :
    x(X),
    y(Y)
{

}

template<typename T>
inline float sf::Vector2<T>::Dot(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return (float)(lhs.x * rhs.x + lhs.y * rhs.y);
}

template<typename T>
inline Vector2<T> sf::Vector2<T>::Lerp(const Vector2<T>& startPosition, const Vector2<T>& destination, float time)
{
    time = (time > 1.0f) ? 1.0f : ((time < 0.0f) ? 0.0f : time);
    return startPosition * (1.0f - time) + destination * time;
}

template<typename T>
inline Vector2<T> sf::Vector2<T>::SmoothStep(const Vector2<T>& startPosition, const Vector2<T>& destination, float time)
{
    time = (time > 1.0f) ? 1.0f : ((time < 0.0f) ? 0.0f : time);
    time = time * time * (3.f - 2.f * time);
    return Vector2<T>(startPosition + time * (destination - startPosition));
}

template<typename T>
inline float sf::Vector2<T>::Distance(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return Vector2<T>(lhs.x - rhs.x, lhs.y - rhs.y).Length();
}

template<typename T>
inline float sf::Vector2<T>::SqrMagnitude(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    Vector2<T> sqrMagnitude(lhs.x - rhs.x, lhs.y - rhs.y);
    return sqrMagnitude.x * sqrMagnitude.x + sqrMagnitude.y * sqrMagnitude.y;
}

template<typename T>
inline Vector2<T> sf::Vector2<T>::Min(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return Vector2<T>(lhs.x <= rhs.x ? lhs.x : rhs.x, lhs.y <= rhs.y ? lhs.y : rhs.y);
}

template<typename T>
inline Vector2<T> sf::Vector2<T>::Max(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return Vector2<T>(lhs.x >= rhs.x ? lhs.x : rhs.x, lhs.y >= rhs.y ? lhs.y : rhs.y);
}

template<typename T>
inline Vector2<T> sf::Vector2<T>::Clamp(const Vector2<T>& value, const Vector2<T>& min, const Vector2<T>& max)
{
    Vector2<T> clampVector({ value.x >= min.x ? value.x : min.x , value.y >= min.y ? value.y : min.y });
    clampVector.x = value.x <= max.x ? value.x : max.x;
    clampVector.y = value.y <= max.y ? value.y : max.y;

    return clampVector;
}

template<typename T>
inline Vector2<T> sf::Vector2<T>::Normalized(const Vector2<T>& lhs)
{
    auto lenght = lhs.Length();
    if (lenght == 0)
        return zero;
    return Vector2<T>(lhs / lenght);
}

////////////////////////////////////////////////////////////
template <typename T>
template <typename U>
inline Vector2<T>::Vector2(const Vector2<U>& vector) :
    x(static_cast<T>(vector.x)),
    y(static_cast<T>(vector.y))
{
}

////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator -(const Vector2<T>& right)
{
    return Vector2<T>(-right.x, -right.y);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x += right.x;
    left.y += right.y;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x + right.x, left.y + right.y);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x - right.x, left.y - right.y);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator *(const Vector2<T>& left, T right)
{
    return Vector2<T>(left.x * right, left.y * right);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator *(T left, const Vector2<T>& right)
{
    return Vector2<T>(right.x * left, right.y * left);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>& operator *=(Vector2<T>& left, T right)
{
    left.x *= right;
    left.y *= right;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator /(const Vector2<T>& left, T right)
{
    return Vector2<T>(left.x / right, left.y / right);
}

////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>& operator /=(Vector2<T>& left, T right)
{
    left.x /= right;
    left.y /= right;

    return left;
}

////////////////////////////////////////////////////////////
template <typename T>
inline bool operator ==(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x == right.x) && (left.y == right.y);
}


////////////////////////////////////////////////////////////
template <typename T>
inline bool operator !=(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x != right.x) || (left.y != right.y);
}
