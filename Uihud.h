#pragma once
#include "GameObject.h"
class Uihud : public GameObject
{
protected:
	sf::Text textScore;
	sf::Text textMessage;

	std::string fontIds;


	bool showtextMessage;
	

public:
	Uihud(const std::string& name);
	~Uihud() override = default;

	void SetScore1(int score);
	void SetScore2(int score1, int score2);
	void SetScorePosition(const sf::Vector2f& pos);
	void SetScoreSize(int size);
	void SetMessage(const std::string& msg);
	void SetMessagePosition(const sf::Vector2f& pos);
	void SetMessageSize(int size);
	void SetShowMassage(bool show) { showtextMessage = show; }

	void Init() override;

	void Release() override;

	void Reset() override;

	void Update(float dt) override;

	void Draw(sf::RenderWindow& window) override;

};

