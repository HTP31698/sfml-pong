#pragma once
#include "GameObject.h"
class BatVs;
class SceneGameVs;

class BallVs : public GameObject
{
    protected:
        BatVs* bat = nullptr;
        BatVs* bat1 = nullptr;

        sf::CircleShape cir;

        sf::Vector2f direction;
        float speed = 0.f;

        float minX = 0.f;
        float minY = 0.f;
        float maxX = 0.f;
        float maxY = 0.f;

        int score1 = 0;
        int score2 = 0;

        SceneGameVs* scene;

    public:
        BallVs(const std::string& name);
        ~BallVs();

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
        void SetBat(BatVs* batvs, BatVs* batvs1)
        { 
            this->bat = batvs;
            this->bat1 = batvs1;
        }

        int getScore1();
        int getScore2();
        void ResetScore();
   };


