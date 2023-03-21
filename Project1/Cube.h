#pragma once
#include <SFML/Graphics.hpp>
#include <vector>


struct vec3 {
	float x, y, z;
};

struct connection {
	float a, b;
};



class Cube {
private:
	std::vector<vec3> points{
		{100.f,100.f,100.f},
		{200.f,100.f,100.f},
		{200.f,200.f,100.f},
		{100.f,200.f,100.f},
		{100.f,100.f,200.f},
		{200.f,100.f,200.f},
		{200.f,200.f,200.f},
		{100.f,200.f,200.f}

	};

	std::vector<connection> connections{
		{0.f,4.f},
		{1.f,5.f},
		{2.f,6.f},
		{3.f,7.f},
		{0.f,1.f},
		{1.f,2.f},
		{2.f,3.f},
		{3.f,0.f},
		{4.f,5.f},
		{5.f,6.f},
		{6.f,7.f},
		{7.f,4.f}
	
	};
	vec3 c{0,0,0};

public:
	Cube();
	~Cube();
	void line(sf::RenderWindow*, float, float, float, float);
	void rotate(vec3& point, float x = 1, float y = 1, float z = 1);
	void rotatePoints(sf::RenderWindow*);
};