#include "sssf_VS\stdafx.h"
#include "sssf\game\Game.h"
#include "sssf\graphics\GameGraphics.h"
#include "sssf\graphics\TextureManager.h"
#include "sssf\input\GameInput.h"
#include "sssf\gui\Life.h"

Life::Life()
{
	initial_image_id = 0;
    final_image_id = 0;
    current_life_per = 100;
	x = 0;
	y = 0;
	z = 0;
	width = 0;
	height = 0;
	
}

void Life::initLife(int initID,
				int finalID,
				int initX,
				int initY,
				int initZ,
				int initAlpha,
				int initWidth,
				int initHeight)
{
    initial_image_id = initID;
	final_image_id = finalID;
	x = initX;
	y = initY;
	z = initZ;
	alpha = initAlpha;
	width = initWidth;
	height = initHeight;
	
}

void Life::updateLife(int current_life_percentage)
{
    current_life_per = current_life_percentage;
}