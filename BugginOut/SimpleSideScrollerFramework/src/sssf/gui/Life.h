
#pragma once
#include "sssf_VS\stdafx.h"

class ButtonEventHandler;
class Game;
class GameInput;
class TextureManager;

class Life
{
private:    
    
    int initial_image_id;
    int final_image_id;
    int current_life_per;
    int current_number_lives;
	// OTHER RENDERING VARIABLES
	int x;
	int y;
	int z;
	int alpha;
	int width;
	int height;
	


public:
	// INLINED ACCESSOR METHODS
	int		getInitialId()	{ return initial_image_id;		}
	int		getFinalId()	{ return final_image_id;	}
	int		getX()					{ return x;						}
	int		getY()					{ return y;						}
	int		getZ()					{ return z;						}
	int		getAlpha()				{ return alpha;					}
	int		getHeight()				{ return height;				}
	int		getWidth()				{ return width;					}
    int		getPercentageOfLife()					{ return current_life_per;}
    //bool	isMouseOver()			{ return mouseOver;				}
	//wstring	getCommand()			{ return command;				}

	// INLINED MUTATOR METHODS
	void setInitialId(int initTextureID)
	{ initial_image_id = initTextureID;		}
	void setFinalId(int initFinalTextureID)
	{ final_image_id = initFinalTextureID;	}
	void setX(int initX)
	{ x = initX;									}
	void setY(int initY)
	{ y = initY;									}
	void setZ(int initZ)
	{ z = initZ;									}
	void setAlpha(int initAlpha)
	{ alpha = initAlpha;							}
	void setWidth(int initWidth)
	{ width = initWidth;							}
	void setHeight(int initHeight)
	{ height = initHeight;							}
	/*void setCommand(wstring changeCommand)
	{ command = changeCommand;						}
	void setEventHandler(ButtonEventHandler *initEventHandler)
	{ eventHandler = initEventHandler;				}
*/

	// METHODS DEFINED IN Button.cpp
	Life::Life();
	Life::~Life();
	//void fireEvent(Game *game);
	void initLife(int initNormalTextureID, int initMouseOverTextureID, int initX, int initY, int initZ, int initAlpha, int initWidth, int initHeight);
	void updateLife(int current_life_per);
};
