#pragma once

enum class EGameState
{
    TITLE_SCREEN,
    GAMEPLAY,
    GAME_OVER
};

enum class EMenuState
{
    NULLPTR,
    PAUSE,
    OPTIONS,
    STATS
};

enum EAnimation_Warrior
{
	A_IDLE = 1,
	L_IDLE = 2,

	A_UP = 3,
	L_UP = 4,

	A_RIGHT = 3,
	L_RIGHT = 4,

	A_DOWN = 3,
	L_DOWN = 4,

	A_LEFT = 3,
	L_LEFT = 4
};

enum class ELayers
{
	GROUND,
	PLAYER,
	COLLISION
};
