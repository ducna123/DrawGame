#pragma once
#include "GameStates/GameStatebase.h"
#include "GameButton.h"

class Sprite2D;
class Sprite3D;
class Text;

class GSCredit :
	public GameStateBase
{
public:
	GSCredit();
	~GSCredit();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);

	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();


	void SetNewPostionForBullet();

private:

	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Sprite2D> m_bt;
	std::shared_ptr<Text>  m_txt;
	std::shared_ptr<GameButton>  m_btnBack;

};

#pragma once
