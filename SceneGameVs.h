#pragma once
#include "Scene.h"
class BatVs;
class BallVs;
class Uihud;

class SceneGameVs : public Scene
{
protected:
	BatVs* batvs;
	BatVs* batvs2;
	BallVs* ballvs;
	Uihud* uihud;

	bool ballActive = true;

public:
	SceneGameVs();
	~SceneGameVs() override;

	void Init() override;
	void Enter() override;
	void Update(float dt) override;

	void SetGameOver();
	void SetballActive(bool bl) { ballActive = bl; }
};


