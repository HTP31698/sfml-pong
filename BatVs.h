#pragma once
#include "GameObject.h"
class BatVs :
    public GameObject
{
protected:
    sf::RectangleShape shape;
    float speed = 500.f;
    sf::Vector2f direction;
    sf::Vector2f direction1;

    float minY;
    float maxY;

    bool whatbat;

public:
    BatVs(const std::string& name);
    ~BatVs() override;

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
    void SetWhatbat(bool what);

    sf::FloatRect GetGlobalBounds() { return shape.getGlobalBounds(); }
};

