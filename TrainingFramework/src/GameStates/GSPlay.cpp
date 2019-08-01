#include "GSPlay.h"

#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include <time.h>

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);


	//text game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TEXT_COLOR::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	//Board
	auto texture1 = ResourceManagers::GetInstance()->GetTexture("plane_texture");
	auto shader1 = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_Board = std::make_shared<Sprite2D>(model, shader1, texture1);
	m_Board->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_Board->SetSize(500, 500);

	//text game time
	auto shader2 = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font1 = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_time = std::make_shared< Text>(shader2, font1, "Time : 10s", TEXT_COLOR::RED, 1.0);
	m_time->Set2DPosition(Vector2(350, 25));

	//back button
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture2 = ResourceManagers::GetInstance()->GetTexture("button_back");
	m_btnBack = std::make_shared<GameButton>(model, shader, texture2);
	m_btnBack->Set2DPosition(screenWidth / 2, (screenHeight / 2) + 300);
	m_btnBack->SetSize(200, 50);
	m_btnBack->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		});

	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	texture = ResourceManagers::GetInstance()->GetTexture("button_back");
	m_bt = std::make_shared<Sprite2D>(model, shader, texture);
	m_bt->Set2DPosition(screenWidth / 2, (screenHeight / 2) + 300);
	m_bt->SetSize(200, 50);

	//list ball

	int posX = 25;
	int posY = 180;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			if(i % 2 == 0) texture = ResourceManagers::GetInstance()->GetTexture("ball1");
			else if(j % 2 == 0) texture = ResourceManagers::GetInstance()->GetTexture("ball2");
			else texture = ResourceManagers::GetInstance()->GetTexture("ball3");

			shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
			std::shared_ptr<Sprite2D> obj = std::make_shared<Sprite2D>(model, shader, texture);
			obj->Set2DPosition(posX + 62*i, posY+62*j);
			obj->SetSize(50, 50);
			m_listBall.push_back(obj);
		}
	}

}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	(m_btnBack)->HandleTouchEvents(x, y, bIsPressed);
	//if ((m_btnBack)->IsHandle()) break;
}

void GSPlay::Update(float deltaTime)
{
	m_btnBack->Update(deltaTime);
}

void GSPlay::Draw()
{
	m_btnBack->Draw();
	m_BackGround->Draw();
	m_score->Draw();
	m_Board->Draw();
	m_time->Draw();
	m_bt->Draw();
	for (auto it : m_listBall)
	{
		it->Draw();
	}
}

void GSPlay::SetNewPostionForBullet()
{
}