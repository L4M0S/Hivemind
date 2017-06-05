#include "pch.h"
#include "FoodSourceManager.h"
#include "FoodSource.h"


FoodSourceManager* FoodSourceManager::sInstance = nullptr;

FoodSourceManager::FoodSourceManager()
{
}

FoodSourceManager* FoodSourceManager::getInstance()
{
	if (sInstance == nullptr)
	{
		sInstance = new FoodSourceManager();
	}
	return sInstance;
}

FoodSourceManager::~FoodSourceManager()
{
	mFoodSources.clear();
}

void FoodSourceManager::spawnFoodSource(const sf::Vector2f& position)
{
	mFoodSources.push_back(FoodSource(position));
}

void FoodSourceManager::update(sf::RenderWindow& window, const float& deltaTime)
{
	for (auto iter = mFoodSources.begin(); iter != mFoodSources.end(); ++iter)
	{
		iter->update(window, deltaTime);
	}
}

void FoodSourceManager::render(sf::RenderWindow& window)
{
	for (auto iter = mFoodSources.begin(); iter != mFoodSources.end(); ++iter)
	{
		iter->render(window);
	}
}

std::uint32_t FoodSourceManager::getFoodsourceCount() const
{
	return mFoodSources.size();
}

std::vector<FoodSource>::iterator FoodSourceManager::begin()
{
	return mFoodSources.begin();
}

std::vector<FoodSource>::iterator FoodSourceManager::end()
{
	return mFoodSources.end();
}