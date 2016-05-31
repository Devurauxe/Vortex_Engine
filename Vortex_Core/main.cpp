#include "window.h"
#include "Sprite.h"

int main()
{
	using namespace vortex;
	using namespace graphics;

	Window window("Vortex Engine", 800, 600);
	Sprite _sprite;
	_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);

	while (!window.closed())
	{
		window.clear();
		window.getProgram().use();

		_sprite.draw();

		window.getProgram().unuse();
		window.update();
	}

	return 0;
}