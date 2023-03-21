#include "Cube.h"
#include <cmath>

Cube::Cube()
{
	for (auto& p : points) {
		this->c.x += p.x;
		this->c.y += p.y;
		this->c.z += p.z;
	}

	this->c.x /= points.size();
	this->c.y /= points.size();
	this->c.z /= points.size();
}

Cube::~Cube()
{
}

void Cube::line(sf::RenderWindow* target, float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;

	float lenght = std::sqrt(dx * dx + dy * dy);
	float angle = std::atan2(dy, dx);

	for (float i = 0; i < lenght; i++) {
		auto pixel = sf::RectangleShape(sf::Vector2f(2.f, 2.f));
		pixel.setPosition(sf::Vector2f(x1 + std::cos(angle) * i,
			y1 + std::sin(angle) * i));
		target->draw(pixel);
	}
}

void Cube::rotate(vec3& point, float x, float y, float z)
{
	float rad = 0;

	rad = x;
	point.y = std::cos(rad) * point.y - std::sin(rad) * point.z;
	point.z = std::sin(rad) * point.y + std::cos(rad) * point.z;

	rad = y;
	point.x = std::cos(rad) * point.x + std::sin(rad) * point.z;
	point.z = -std::sin(rad) * point.x + std::cos(rad) * point.z;

	rad = z;

	point.x = std::cos(rad) * point.x - std::sin(rad) * point.y;
	point.y = std::sin(rad) * point.x + std::cos(rad) * point.y;

}

void Cube::rotatePoints(sf::RenderWindow* target)
{
	for (auto& p : points) {
		p.x -= c.x;
		p.y -= c.y;
		p.z -= c.z;
		rotate(p, 0.02, 0.01, 0.04);
		p.x += c.x;
		p.y += c.y;
		p.z += c.z;
		auto pixel = sf::RectangleShape(sf::Vector2f(2.f, 2.f));
		pixel.setPosition(sf::Vector2f(p.x, p.y));
		target->draw(pixel);
	}

	for (auto& conn : connections) {
		line(target, points[conn.a].x,
			points[conn.a].y,
			points[conn.b].x,
			points[conn.b].y);
	};
}

