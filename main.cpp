#include "Window.h"

using namespace std;

int main() {
	Window window;
	srand(time(NULL));

	while (window.isRunning()) {
		window.restartClock();

		window.update();
		window.render();


	}

	return 0;
}