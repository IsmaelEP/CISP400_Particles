#include "Engine.h"

Engine::Engine()
{
	int pixelWidth = VideoMode::getDesktopMode().width / 2;
	int pixelHeight = VideoMode::getDesktopMode().height / 2;
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
		clock.restart();
	}

}