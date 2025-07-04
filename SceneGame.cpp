#include "stdafx.h"
#include "SceneGame.h"
#include "Bat.h"
#include "Ball.h"
#include "Uihud.h"

SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	fontIds.push_back("fonts/DS-DIGIT.TTF");

	bat = (Bat*)AddGameObject(new Bat("Bat"));
	ball = (Ball*)AddGameObject(new Ball("Ball"));
	uihud = (Uihud*)AddGameObject(new Uihud("Uihud"));
	ball->SetBat(bat);
	Scene::Init();
}

void SceneGame::Enter()
{
	ballActive = false;
	isPlaying = true;


	Scene::Enter();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);
		if (!ballActive)
		{
			ball->SetPosition(bat->GetPosition());
			if (InputMgr::GetKeyDown(sf::Keyboard::Space))
			{
				ballActive = true;
				sf::Vector2f dir(1.f, -1.f);
				Utils::Normallize(dir);
				ball->Fire(dir, 500.f);
			}
		}
}

void SceneGame::SetGameOver()
{
	SCENE_MGR.ChangeScene(SceneIds::Game);
}
