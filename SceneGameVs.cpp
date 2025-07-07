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

	batvs = (BatVs*)AddGameObject(new BatVs("BatVs1"));
	batvs2 = (BatVs*)AddGameObject(new BatVs("BatVs2"));
	ballvs = (BallVs*)AddGameObject(new BallVs("BallVs"));
	uihud = (Uihud*)AddGameObject(new Uihud("Uihud"));
	ballvs->SetBat(batvs, batvs2);
	

	Scene::Init();
}


void SceneGameVs::Enter()
{
	ballActive = false;
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	batvs->SetPosition({ bounds.left + 20.f , bounds.height * 0.5f });
	batvs2->SetPosition({ bounds.left + 1260.f , bounds.height * 0.5f });

	batvs->SetWhatbat(true);
	batvs2->SetWhatbat(false);

	uihud->SetShowMassage(true);
	uihud->SetMessage("SpaceStart!!");

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
			if (ballvs->getScore1() < ballvs->getScore2())
			{
				ballvs->Fire(dir, 500.f);
			}
			else if (ballvs->getScore1() > ballvs->getScore2())
			{
				ballvs->Fire(dir * -1.f, 500.f);
			}
			else if (ballvs->getScore1() == ballvs->getScore2())
			{
				ballvs->Fire(dir, 500.f);
			}
			uihud->SetShowMassage(false);
		}
		
	}
	uihud->SetScore2(ballvs->getScore1(), ballvs->getScore2());
}

void SceneGameVs::SetGameOver()
{
	SCENE_MGR.ChangeScene(SceneIds::GameVs);
}