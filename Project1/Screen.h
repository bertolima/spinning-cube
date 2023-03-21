
#include "Cube.h"


class Screen {
	private:
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event ev;
		sf::Clock* clock;

		void initVariables();
		void initWindow();

		Cube cube;


		

	public:
		Screen();
		~Screen();
		bool const running() const;

		void pollEvent();
		void update();

		void renderLine();
		void render();
		
		


};
