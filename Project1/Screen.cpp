#include "Screen.h"

void Screen::initVariables()
{
	this->window = nullptr;
	this->videoMode.height = 600;
	this->videoMode.width = 800;
}

void Screen::initWindow()
{
	this->window = new sf::RenderWindow(this->videoMode, "Spinning Cube", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->clock = new sf::Clock;
}

Screen::Screen() 
{
	this->initVariables();
	this->initWindow();
}

Screen::~Screen()
{
}

bool const Screen::running() const
{
	return this->window->isOpen();
}

void Screen::pollEvent()
{
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Screen::update()
{
	this->pollEvent();
}

void Screen::renderLine()
{
	this->cube.line(this->window, 100, 100, 200, 100);
	this->cube.line(this->window, 200, 100, 200, 200);
	this->cube.line(this->window, 200, 200, 100, 200);
	this->cube.line(this->window, 100, 200, 100, 100);
}

void Screen::render()
{
	

	

	if (this->clock->getElapsedTime().asMilliseconds() > 60) {
		this->window->clear();
		this->cube.rotatePoints(this->window);
		this->window->display();
		this->clock->restart();
	}

}
