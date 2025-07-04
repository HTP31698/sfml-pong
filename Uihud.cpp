#include "stdafx.h"
#include "Uihud.h"

Uihud::Uihud(const std::string& name)
	:GameObject(name)
{
}

void Uihud::SetScore1(int score)
{
	static std::string formatScore = "Score: ";
	textScore.setString(formatScore + std::to_string(score));
	Utils::SetOrigin(textScore, Origins::TL);
}

void Uihud::SetScore2(int score1, int score2)
{
	textScore.setString(std::to_string(score1) + " : " + std::to_string(score2));
	Utils::SetOrigin(textScore, Origins::TL);
}

void Uihud::SetScorePosition(const sf::Vector2f& pos)
{
	textScore.setPosition(pos);
}

void Uihud::SetScoreSize(int size)
{
	textScore.setCharacterSize(size);
}

void Uihud::SetMessage(const std::string& msg)
{
	textMessage.setString(msg);
	Utils::SetOrigin(textMessage, Origins::MC);
}

void Uihud::SetMessagePosition(const sf::Vector2f& pos)
{
	textMessage.setPosition(pos);
}

void Uihud::SetMessageSize(int size)
{
	textMessage.setCharacterSize(size);
}

void Uihud::Init()
{
	fontIds ="fonts/DS-DIGIT.TTF";

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	textMessage.setCharacterSize(100);
	textMessage.setFillColor(sf::Color::Red);
	textMessage.setPosition(bounds.width * 0.5f, bounds.height * 0.5f);
}

void Uihud::Release()
{
}

void Uihud::Reset()
{
	textScore.setFont(FONT_MGR.Get(fontIds));
	textMessage.setFont(FONT_MGR.Get(fontIds));

	showtextMessage = true;
}

void Uihud::Update(float dt)
{
}

void Uihud::Draw(sf::RenderWindow& window)
{
	window.draw(textScore);
	if (showtextMessage)
	{
		window.draw(textMessage);
	}
}
