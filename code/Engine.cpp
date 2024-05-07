#include "Engine.h"

Engine::Engine()
{
	int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);

	m_Window.create(vm, "Particle", Style::Default);
}

void Engine::run()
{
	sf::Clock clock;
	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;


	while (m_Window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		
		sf::Time s = clock.restart();// clock.getElapsedTime();
		float seconds = s.asSeconds();
		input();
		update(seconds);
		draw();
		;
	}

}

void Engine::input()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		// Close window: exit
		if (event.type == sf::Event::Closed)
			m_Window.close();
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Vector2i position = sf::Mouse::getPosition();

			for (int i = 0; i < 5; i++)
			{
				
				Particle part(m_Window, rand() % 25 + 50, position);
				m_particles.push_back(part);
			}


		}
	

	}

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.close();
	}

}


void Engine::update(float dtAsSeconds)
{
	for (int i = 0; i < m_particles.size(); i++)
	{
		if (m_particles.at(i).getTTL() > 0.0)
		{
			m_particles.at(i).update(dtAsSeconds);

		}
		else
		{
			m_particles.erase(m_particles.begin() + i);
			i--;
		}
	}
	
}

void Engine::draw()
{
	m_Window.clear();


	for (int i = 0; i < m_particles.size(); i++)
	{
		m_Window.draw(m_particles.at(i));
	}

	m_Window.display();
}