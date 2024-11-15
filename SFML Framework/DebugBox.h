#pragma once

class DebugBox
{

public:
	sf::RectangleShape shape;
private:
	bool isVisible;

public:
	DebugBox();

	void SetBounds(const sf::FloatRect& bounds);
	void SetVisible(bool v) { isVisible = v; }
	bool IsVisible() const { return isVisible; }

	void Draw(sf::RenderWindow& window);
	void SetOutlineColor(sf::Color color) { shape.setOutlineColor(color); }
};