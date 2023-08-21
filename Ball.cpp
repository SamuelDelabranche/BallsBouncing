#include "Ball.h"

using namespace std;
Ball::Ball(int posX, int posY) {

	m_size = 32;

	m_ball.setOrigin(m_size, m_size);
	m_ball.setRadius(m_size);
	m_color = sf::Color(
	(rand() % 256), 
	(rand() % 256), 
	(rand() % 256));


	m_ball.setFillColor(m_color);
	m_ball.setPosition(posX, posY);

	m_velocity = 0;
	m_rebound = -0.5f;

	cout << "New ball created! \n\t Position: X:" << m_ball.getPosition().x << " Y:" << m_ball.getPosition().y << "\n";
}

Ball::~Ball(){}

sf::CircleShape* Ball::getShape() { return &this->m_ball; }
float Ball::getSize() const { return this->m_size; }
sf::Vector2i Ball::getPosition() { return static_cast<sf::Vector2i>(this->m_ball.getPosition()); }

void Ball::move(const float t_gravity, const sf::Time t_dt) {
	m_velocity += t_gravity * t_dt.asSeconds();
	//cout << m_velocity << endl;

	m_ball.setPosition(m_ball.getPosition().x, m_ball.getPosition().y + m_velocity * t_dt.asSeconds());
}

void Ball::rebound(const float t_gravity, const sf::Time t_dt) {
	m_velocity *= m_rebound;
	move(t_gravity, t_dt);
}

void Ball::printVelo() const { cout << "Velocity " << m_velocity << endl; }