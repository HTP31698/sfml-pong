#pragma once
#include "GameObject.h"
class Bat;
class SceneGame;

class Ball : public GameObject
{
protected:
    Bat* bat = nullptr;

    sf::CircleShape cir;

    sf::Vector2f direction;
    float speed = 0.f;

    float minX=0.f;
    float minY=0.f;
    float maxX=0.f;
    float maxY=0.f;

    int score = 0;

    SceneGame* scene;

public:
    Ball(const std::string& name);
    ~Ball();

    void SetPosition(const sf::Vector2f& pos) override;
    void SetRotation(float rot) override;
    void SetScale(const sf::Vector2f& s) override;
    void SetOrigin(const sf::Vector2f& o) override;
    void SetOrigin(Origins preset) override;

    void Init() override;
    void Release() override;
    void Reset() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;

    void Fire(const sf::Vector2f& d, float s);
    void SetBat(Bat* bat) { this->bat = bat; }
};

