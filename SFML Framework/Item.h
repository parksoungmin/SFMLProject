#pragma once

class Item : public GameObject
{
public:
	enum class ItemType
	{
		health,
		Ammo,
		End
	};
	
	static int totalItemType;
protected:
	ItemType itemType;

	sf::Sprite	body;
	std::string textureId;

	int value;

public:
	void SetTypeInfo();

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void CreateItem(const sf::Vector2f& position);

	sf::FloatRect GetLocalBounds() const  override;
	sf::FloatRect GetGlobalBounds() const override;
public:
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

public:
	Item(const std::string& name = "");
	~Item() = default;
};
