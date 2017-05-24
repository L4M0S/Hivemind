#include "pch.h"
#include "Bee.h"
#include <math.h>


Bee::Bee():
	mBody(mBodyRadius), mFace(sf::Vector2f(mBodyRadius, 2)), mPosition(sf::Vector2f(200, 200)), speed(0.01f)
{
	mBody.setFillColor(sf::Color(0, 128, 128));
	mFace.setFillColor(sf::Color::Black);
	mBody.setPosition(mPosition);
	mFace.setPosition(mBody.getPosition().x + mBodyRadius, mBody.getPosition().y + mBodyRadius);
}

void Bee::update(sf::RenderWindow& window)
{
	mBody.setPosition(mPosition);
	mFace.setPosition(mPosition.x + mBodyRadius, mPosition.y + mBodyRadius);

	auto mousePosition = sf::Mouse::getPosition(window);
	auto facePosition = mFace.getPosition();

	float rotationRadians = atan2(mousePosition.y - facePosition.y, mousePosition.x - facePosition.x);
	float rotationAngle = rotationRadians * (180 / pi);
	
	auto xDif = abs(mousePosition.x - facePosition.x);
	auto yDif = abs(mousePosition.y - facePosition.y);
	auto distance = sqrt(xDif * xDif + yDif * yDif);
	speed = (distance > 20) ? 10000 / (distance * 50) : 0;
	mPosition.x += cos(rotationRadians) * speed;
	mPosition.y += sin(rotationRadians) * speed;

	mFace.setRotation(rotationAngle);
}

void Bee::render(sf::RenderWindow& window) const
{
	window.draw(mBody);
	window.draw(mFace);
}

void Bee::setPosition(const sf::Vector2f& position)
{
	mPosition = position;
}

const sf::Vector2f& Bee::getPosition() const
{
	return mPosition;
}

float Bee::getRadius() const
{
	return mBodyRadius;
}
