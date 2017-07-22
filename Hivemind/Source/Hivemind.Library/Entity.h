#pragma once

/**
*	@Author: Dale Diaz
*	@Date: 7/21/2017
*/

class Entity
{
public:

#pragma region Constructors / Destructor / Move Semantics

	/**
	 * Constructor
	 * @Param position: The starting position of the Entity
	 * @Param outlineColor: The default color of the entity's outline
	 * @Param fillColor: The default color of the entity's body
	 */
	explicit Entity(const sf::Vector2f& position,
		const sf::Color& outlineColor = sf::Color::White,
		const sf::Color& fillColor = sf::Color::White);

	/**
	 * Default Destructor
	 */
	virtual ~Entity() = default;

	/**
	 * Default Copy Constructor
	 * @Param rhs: Entity being copied
	 */
	Entity(const Entity& rhs) = default;

	/**
	 * Default Assignment Operator
	 * @Param rhs: Entity being assigned to
	 * @Return: A copy of the specified entity
	 */
	Entity& operator=(const Entity& rhs) = default;

	/**
	 * Default Move Copy Constructor
	 * @Param rhs: Entity being moved
	 */
	Entity(Entity&& rhs) = default;

	/**
	 * Default Move Assignment Operator
	 * @Param rhs: Entity being moved
	 * @Return: A reference to the moved entity
	 */
	Entity& operator=(Entity&& rhs) = default;

#pragma endregion

#pragma region Public API

	/**
	 * Update method called by the main game loop
	 * @Param window: The window that the simulation is being rendered to
	 * @Param deltaTime: The time since the last Update call
	 */
	virtual void Update(sf::RenderWindow& window, const float& deltaTime) = 0;

	/**
	 * Render method called by the main game loop
	 * @Param window: The window that the simulation is being rendered to
	 */
	virtual void Render(sf::RenderWindow& window) const = 0;

	/**
	 * Computes the distance between the position of two entities
	 * @Param position_1: The position of the first entity
	 * @Param position_2: The position of the second entity
	 * @Return: A float representing the number of pixels between the two vectors
	 */
	static float DistanceBetween(const sf::Vector2f& position_1, const sf::Vector2f& position_2);

	/**
	 * Mutator method for the entity's position
	 * @Param position: The position that the entity is being moved to
	 */
	virtual void SetPosition(const sf::Vector2f& position);

	/**
	 * Accessor method for the entity's position
	 * @Return: The entity's position
	 */
	const sf::Vector2f& GetPosition() const;

	/**
	 * Determines if the entity has been marked for deletion
	 * @Return: True if the entity is marked for delete
	 */
	virtual bool MarkedForDelete() const;

	/**
	 *  Markes the entity for deletion
	 */
	void MarkForDelete();

#pragma endregion

protected:
	sf::Vector2f mPosition;
	sf::Color mOutlineColor, mFillColor;
	class CollisionNode* mCollisionNode;
	bool mMarkedForDelete;
};

