#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include "SFML/Graphics.hpp"
#include "Ball.h"

#include <iostream>
#include <string>
#include <vector>



class Window{
	public:
		Window(sf::Vector2i l_windSize = sf::Vector2i(800, 600));
		~Window();

		void update();
		void render();

		bool isRunning();
		bool pollEvent(sf::Event& l_event);

		void restartClock();
		sf::Time getTime() const;


	private:

		sf::RenderWindow m_window;

		sf::Clock m_clock;
		sf::Time m_elaspedTimePerFrame;

		std::vector<Ball*> m_balls;

		float m_gravity;

};

#endif