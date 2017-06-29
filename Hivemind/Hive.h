#pragma once
#include "Entity.h"
#include "OnlookerBee.h"

class Hive :
	public Entity
{
public:
	/// Constructor
	/// @Param position: The starting position of the food source
	explicit Hive(const sf::Vector2f& position);
	
	/// Destructor
	virtual ~Hive();

	/// Updates the current game state of the hive
	/// @Param window: The screen that the game is being rendered to
	/// @Param deltaTime: The time elapsed since last update
	void update(sf::RenderWindow& window, const float& deltaTime) override;
	
	/// Renders the hive to the screen
	/// @Param window: The screen which the hive is being rendered to
	void render(sf::RenderWindow& window) const override;

	/// Accessor method for the center point of the food source
	/// @Return: A vector representing the center point of the source
	sf::Vector2f getCenterTarget() const;

	/// Accessor method for the dimensions of the food source
	/// @Return: A vector representing the width and height of the food source
	const sf::Vector2f& getDimensions() const;
	
	/// Adds food to the hive
	/// @Param foodAmount: Amount of food being added to the hive
	void depositFood(const float& foodAmount);

	/// Adds an onlooker to the hive for easy tracking during waggle dance phase
	/// @Param bee: Bee being added as idle to the hive
	void addIdleBee(OnlookerBee* const bee);

	/// Removes an onlooker from the hives collection of idle bees
	/// @Param bee: Bee being removed from the collection of idle bees
	void removeIdleBee(OnlookerBee* const bee);

	/// Accessor for the begin iterator of the idle bees
	/// @Return: An iterator pointing to the beginning of the idle bees vector
	std::vector<OnlookerBee*>::iterator idleBeesBegin();

	/// Accessor for the end iterator of the idle bees
	/// @Return: An iterator pointing to the end of the idle bees vector
	std::vector<OnlookerBee*>::iterator idleBeesEnd();

	/// Iterates over the idle bees vector and removes all bees which are no longer idle
	void validateIdleBees();

	/// Deposits food source information into the hive
	void updateKnownFoodSource(class FoodSource* const foodSource, const std::pair<float, float>& foodSourceData);

	/// Causes all bees within the hive to watch the waggle dance and decide on updated food source data
	void handleWaggleDance();

private:
	/// Constants
	const float STANDARD_WIDTH = 200.0f;
	const float STANDARD_HEIGHT = 200.0f;

	static float computeFitness(const std::pair<float, float>&, const float& minYield, const float& maxYield, const float& minDistance, const float& maxDistance);

	/// Fields
	sf::Vector2f mDimensions;
	sf::RectangleShape mBody;
	float mFoodAmount;
	sf::Font mFont;
	sf::Text mText;
	std::vector<OnlookerBee*> mIdleBees;
	std::map<class FoodSource* const, std::pair<float, float>> mFoodSourceData;
	std::default_random_engine mGenerator;
};

