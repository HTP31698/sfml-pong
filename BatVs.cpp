#include "stdafx.h"
#include "BatVs.h"


BatVs::BatVs(const std::string& name)
	: GameObject(name)
{
}

BatVs::~BatVs()
{
}

void BatVs::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	shape.setPosition(pos);
}

void BatVs::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	shape.setRotation(rot);
}

void BatVs::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	shape.setScale(s);
}

void BatVs::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	shape.setOrigin(o);
}

void BatVs::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	Utils::SetOrigin(shape, preset);
}


void BatVs::Init()
{
	shape.setSize({ 5.f, 100.f });
	shape.setFillColor(sf::Color::White);
	SetOrigin(Origins::BC);
}

void BatVs::Release()
{
}

void BatVs::Reset()
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	sf::Vector2f size = shape.getSize();
	minY = bounds.top + size.y;
	maxY = bounds.top + bounds.height;

}

void BatVs::Update(float dt)
{
	if (whatbat == true)
	{
		direction.y = InputMgr::GetAxisRaw(Axis::Vertical);
		sf::Vector2f pos = GetPosition() + direction * speed * dt;
		pos.y = Utils::Clamp(pos.y, minY, maxY);
		SetPosition(pos);

	}
	else
	{
		direction.y = InputMgr::GetAxisRaw(Axis::Vertical);
		sf::Vector2f pos = GetPosition() + direction * speed * dt;
		pos.y = Utils::Clamp(pos.y, minY, maxY);
		SetPosition(pos);
	}

}

void BatVs::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void BatVs::SetWhatbat(bool what)
{
	whatbat = what;
}
