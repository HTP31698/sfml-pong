#pragma once
#include "Scene.h"

class Bat;
class Ball;

class SceneGame : public Scene
{
protected:
	Bat* bat;
	Ball* ball;

	bool ballActive = true;

public:
	SceneGame();
	~SceneGame() override;

	void Init() override;
	void Enter() override;
	void Update(float dt) override;

	void SetGameOver();
};

