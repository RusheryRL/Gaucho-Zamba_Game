#include "mouse.h"

#include "raylib.h"

namespace gauchoZambaGame
{
	Mouse initMouse()
	{
		Mouse mouse;

		mouse.x = GetMousePosition().x;
		mouse.y = GetMousePosition().y;

		return mouse;
	}
}
