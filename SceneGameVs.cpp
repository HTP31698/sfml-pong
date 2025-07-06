#include "stdafx.h"
#include "SceneGameVs.h"
#include "BatVs.h"
#include "BallVs.h"
#include "Uihud.h"

SceneGameVs::SceneGameVs()
	:Scene(SceneIds::GameVs)
{
}

SceneGameVs::~SceneGameVs()
{
}


void SceneGameVs::Init()
{
	fontIds.push_back("fonts/DS-DIGIT.TTF");

	batvs = (BatVs*)AddGameObject(new BatVs("BatVs"));
	batvs2 = (BatVs*)AddGameObject(new BatVs("BatVs"));
	ballvs = (BallVs*)AddGameObject(new BallVs("BallVs"));
	ballvs->SetBat(batvs, batvs2);


	Scene::Init();
}


void SceneGameVs::Enter()
{
	ballActive = false;
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	batvs->SetPosition({ bounds.left + 20.f , bounds.height * 0.5f });
	batvs2->SetPosition({ bounds.left + 1260.f , bounds.height * 0.5f });


	Scene::Enter();
}

void SceneGameVs::Update(float dt)
{
	Scene::Update(dt);
	if (!ballActive)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			ballActive = true;
			sf::Vector2f dir(1.f, -1.f);
			Utils::Normallize(dir);
			ballvs->Fire(dir, 500.f);
		}
		
	}
}

void SceneGameVs::SetGameOver()
{
	SCENE_MGR.ChangeScene(SceneIds::GameVs);
}