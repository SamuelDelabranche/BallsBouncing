#include "Window.h"
#include <algorithm>

using namespace std;

Window::Window(sf::Vector2i l_windSize) : 
	m_window(sf::VideoMode(l_windSize.x, l_windSize.y), "Ball Bouncing!") {

	m_window.setVerticalSyncEnabled(false);
	//m_window.setFramerateLimit(10);

	
	m_gravity = 150.f;

}

Window::~Window() {
	if (!m_balls.empty()) {
		for (auto& ball : m_balls) {
			delete ball;
		}
	}
}

bool Window::isRunning() { return m_window.isOpen(); }
bool Window::pollEvent(sf::Event& l_event) { return m_window.pollEvent(l_event); }


void Window::update() {
	sf::Event t_event;

	while (m_window.pollEvent(t_event)) {
		if (t_event.type == sf::Event::Closed) {
			m_window.close();
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			int mouseX = sf::Mouse::getPosition().x;
			int mouseY = sf::Mouse::getPosition().y;


			m_balls.push_back(new Ball(sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y));
			cout << "Mouse X:" << sf::Mouse::getPosition(m_window).x << " Y:" << sf::Mouse::getPosition(m_window).y << endl;

		}


	}

	float dt = m_elaspedTimePerFrame.asSeconds();

	for (auto& ball : m_balls) {
		if (ball->getPosition().y > (ball->getShape()->getRadius())  // Top
			&& ball->getPosition().y < (m_window.getSize().y - 2 - (ball->getShape()->getRadius())) // bottom
			&& ball->getPosition().x > ball->getShape()->getRadius()  // left
			&& ball->getPosition().x < m_window.getSize().x - (ball->getShape()->getRadius()) // right
			)
		{
			ball->move(m_gravity, m_elaspedTimePerFrame);
		}
		else {
			ball->rebound(m_gravity, m_elaspedTimePerFrame);
		}

		ball->printVelo();
	}


	

}

void Window::render() {

	m_window.clear();
		// Render
	
	for (auto& ball : m_balls) {
		m_window.draw(*ball->getShape());
	}

	m_window.display();

	//cout << 1 / m_elaspedTimePerFrame.asSeconds() << endl;

}

void Window::restartClock() { m_elaspedTimePerFrame = m_clock.restart(); }
sf::Time Window::getTime() const { return this->m_elaspedTimePerFrame; }