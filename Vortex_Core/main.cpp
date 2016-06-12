#include "window.h"
#include "Sprite.h"

int main()
{
	using namespace vortex;
	using namespace graphics;

	Window window("Vortex Engine", 800, 600);
	Sprite _sprite;

	while (!window.closed())
	{
		window.clear();
		window.getProgram().use();

		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);

		window.getProgram().unuse();
		window.update();
	}

	return 0;
}