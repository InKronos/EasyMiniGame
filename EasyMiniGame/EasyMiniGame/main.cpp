#include "game.h"


int main()
{
	Game window(1024, 768, "SFML Game!");
	window.run();

	std::cin.get();
	return 0;
}