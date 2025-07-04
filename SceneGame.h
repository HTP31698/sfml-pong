#pragma once
#include "Scene.h"

class Bat;
class Ball;
class Uihud;

class SceneGame : public Scene
{
protected:
	Bat* bat;
	Ball* ball;
	Uihud* uihud;

	bool ballActive = true;
	bool isPlaying = true;

public:
	SceneGame();
	~SceneGame() override;

	void Init() override;
	void Enter() override;
	void Update(float dt) override;

	void SetGameOver();
};

