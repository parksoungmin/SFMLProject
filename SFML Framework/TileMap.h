#pragma once

class TileMap : public GameObject
{
protected:
	sf::VertexArray vertexArray;
	sf::RenderStates renderState;
	std::string spriteSheetId;

	sf::Texture* texture;
	sf::Transform transform;

	sf::Vector2u cellCount;
	sf::Vector2f cellSize;

	float time = 0.f;
	sf::Vector2f direction;

public:

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void SetInfo(const sf::Vector2u& count, const sf::Vector2f& size);
	void SetInfo(const sf::Vector2u& tileCount, const sf::Vector2f& tileSize, const sf::Vector2u textTileSize);
	void UpdateTransform();

	sf::FloatRect GetLocalBounds() const override;
	sf::FloatRect GetGlobalBounds() const override;

	const sf::Vector2f& GetCellSize() const { return cellSize; }

public:

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
public:
	TileMap(const std::string& name = "");
	~TileMap() = default;

};