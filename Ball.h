#pragma once
#ifndef BALL_H
#define BALL_H

#include "SFML/Graphics.hpp"

#include <time.h>
#include <iostream>

class Ball{
	public:
		Ball(int l_windX, int l_windY);
		~Ball();

		sf::CircleShape* getShape();
		float getSize() const;
		sf::Vector2i getPosition();

		void move(const float t_gravity, const sf::Time t_dt);

		void rebound(const float t_gravity, const sf::Time t_dt);
		void printVelo() const;

	private:
		sf::Vector2i m_position;
		int m_size;

		sf::Color m_color;

		sf::CircleShape m_ball;


		float m_velocity;
		float m_rebound;
};

#endif