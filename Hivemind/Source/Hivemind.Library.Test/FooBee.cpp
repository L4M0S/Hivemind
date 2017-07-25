#include "pch.h"
#include "FooBee.h"

/**
*	@Author: Dale Diaz
*	@Date: 7/25/2017
*/

FooBee::FooBee(const sf::Vector2f& position, Hive& hive) :
	Bee(position, hive)
{
}

FooBee::~FooBee()
{
}

void FooBee::Update(sf::RenderWindow& window, const double& deltaTime)
{
	UNREFERENCED_PARAMETER(window);
	UNREFERENCED_PARAMETER(deltaTime);
	// Do nothing. This is just an instantiable version of the abstract Bee class
}
