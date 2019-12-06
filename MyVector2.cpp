#include "MyVector2.h"
#include <cmath>

/// Jay Simzingili
/// c002525490
/// get length of vector using sqrt of the sum of the squares
/// Approx time: 6 hours
/// Actual time: 
/// session 1: 

const float PI = 3.14159265359f;

float vectorLength(sf::Vector2f t_vector)
{
	//The magnitude of a vector is the length
	float sumOfSquares = (t_vector.x * t_vector.x ) + (t_vector.y * t_vector.y);
	const float length = std::sqrt(sumOfSquares);
	return length;
}

float vectorLengthSquared(sf::Vector2f t_vector)
{
	float vectorLengthAnswer = (t_vector.x * t_vector.x) + (t_vector.y * t_vector.y);
	return vectorLengthAnswer;
}

float vectorCorssProduct(sf::Vector2f t_vectorA, sf::Vector2f t_VectorB)
{
	//Vx * Uy - Vy * Ux
	float vectorCorssProductAnswer = (t_vectorA.x * t_VectorB.y) - (t_VectorB.y * t_vectorA.x);
	return vectorCorssProductAnswer;
}

float vectorDotProduct(sf::Vector2f t_vectorA, sf::Vector2f t_VectorB)
{
	//Vx* Uy + Vy * Ux
	float vectorDotProductAnswer = (t_vectorA.x * t_VectorB.y) + (t_VectorB.x * t_vectorA.y);
	return vectorDotProductAnswer;
}

float vectorAngleBetween(sf::Vector2f t_vectorA, sf::Vector2f t_VectorB)
{
	float cosine = vectorDotProduct(vectorUnitVector(t_vectorA), vectorUnitVector(t_VectorB));
	if (cosine > 1.0f)
	{
		cosine = 1.0f;
	}
	if (cosine < -1.0f)
	{
		cosine = -1.0f;
	}
	const float angleInRadians = std::acos(cosine);
	const float  angleInDegrees = angleInRadians * 180.0f / PI;
	return angleInDegrees;
}

sf::Vector2f vectorRotateBy(sf::Vector2f t_vector, float t_angleRadians)
{
	const float cos = std::cos(t_angleRadians); //calculate once use twice
	const float sin = std::sin(t_angleRadians);
	const float xComponent = (t_vector.x * cos) - (t_vector.y * sin);
	const float yComponent = (t_vector.x * sin) + (t_vector.y * cos);
	const sf::Vector2f result{ xComponent, yComponent };
	return result;
}


sf::Vector2f vectorProjection(sf::Vector2f t_vector, sf::Vector2f t_onto)

{    // (dot product/magnitude of the vector(Vector squared)) * vector
	float vectorProjection = vectorDotProduct(t_vector, t_onto) / vectorLengthSquared(t_onto);
	sf::Vector2f vectorProjectionAnswer = t_onto * vectorProjection;
	return vectorProjectionAnswer;
}

sf::Vector2f vectorRejection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{

	sf::Vector2f vectorRejectionAnswer = t_vector - vectorProjection(t_vector, t_onto);
	return vectorRejectionAnswer;
}

float vectorScalarProjection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	//Dot product/magnitude
	float vectorScalarProjectionAnswer = vectorDotProduct(t_vector, t_onto) / vectorLength(t_onto);
	return vectorScalarProjectionAnswer;
}

sf::Vector2f vectorUnitVector(sf::Vector2f t_vector)
{
	sf::Vector2f result{ 0.0f,0.0f };
	const float lenght = vectorLength(t_vector);
	if (lenght != 0.0f) 
	{
		result = sf::Vector2f{ t_vector.x / lenght, t_vector.y / lenght };
	}
	return result;
}
