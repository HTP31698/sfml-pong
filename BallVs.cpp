#include "stdafx.h"
#include "BallVs.h"
#include "BatVs.h"
#include "SceneGameVs.h"

BallVs::BallVs(const std::string& name)
	:GameObject(name)
{
}

BallVs::~BallVs()
{
}

void BallVs::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	cir.setPosition(pos);
}

void BallVs::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	cir.setRotation(rot);
}

void BallVs::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	cir.setScale(s);
}

void BallVs::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	cir.setScale(o);
}

void BallVs::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	Utils::SetOrigin(cir, preset);
}

void BallVs::Init()
{
	cir.setRadius(10.f);
	cir.setFillColor(sf::Color::Yellow);
	SetOrigin(Origins::MC);
}

void BallVs::Release()
{
}

void BallVs::Reset()
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	if (getScore1() < getScore2())
	{
		SetPosition({ bounds.left + 32.f, bounds.height * 0.5f - 45.f });
	}
	else if (getScore1() > getScore2())
	{
		SetPosition({ bounds.left + 1248.f, bounds.height * 0.5f - 45.f });
	}
	else
	{
		SetPosition({ bounds.left + bounds.width * 0.5f, bounds.height * 0.5f - 45.f });
	}

	float radius = cir.getRadius();
	minX = bounds.left + radius;
	maxX = (bounds.left + bounds.width) - radius;

	minY = bounds.top + radius * 2.f;
	maxY = bounds.top + bounds.height;

	direction = { 0.f, 0.f };
	speed = 0.f;
	if (SCENE_MGR.GetCurrentSceneId() == SceneIds::Game)
	{
		(SceneGameVs*)SCENE_MGR.GetCurrentScene();
		scene->SetballActive(false);
	}
}

void BallVs::Update(float dt)
{
	sf::Vector2f pos = GetPosition() + direction * speed * dt;

	if (pos.x < minX)
	{
		score2 += 1;
		Reset();
	}
	else if (pos.x > maxX)
	{
		score1 += 1;
		Reset();
	}
	if (pos.y < minY)
	{
		pos.y = minY;
		direction.y *= -1.f;
	}
	else if (pos.y > maxY)
	{
		pos.y = maxY;
		direction.y *= -1.f;
	}

	if (bat != nullptr)
	{
		const sf::FloatRect& batBounds = bat->GetGlobalBounds();
		const sf::FloatRect& batBounds1 = bat1->GetGlobalBounds();
		if (cir.getGlobalBounds().intersects(batBounds))
		{
			pos.x = minX + 25.f;
			direction.x *= -1.f;
		}
		if (cir.getGlobalBounds().intersects(batBounds1))
		{
			pos.x = maxX - 25.f;
			direction.x *= -1.f;
		}
	}


	SetPosition(pos);
}

void BallVs::Draw(sf::RenderWindow& window)
{
	window.draw(cir);
}

void BallVs::Fire(const sf::Vector2f& d, float s)
{
	direction = d;
	speed = s;
}

int BallVs::getScore1()
{
	return score1;
}

int BallVs::getScore2()
{
	return score2;
}

void BallVs::ResetScore()
{
	score1 = 0;
	score2 = 0;
}

