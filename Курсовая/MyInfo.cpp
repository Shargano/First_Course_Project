#pragma warning(once : 4996)
#include "MyInfo.h"

void MyInfo(RenderWindow & window) {
	Player player("images/player.png", 320, 350, 0, 0, 60, 65);
	Font font;
	font.loadFromFile("fonts/font.ttf");
	Text info("", font, 21);
	info = textInit(info, "Данный проект выполнил студент первого курса\n\n\n    Грппы ИВТ-173 Шарганов Владимир Сергеевич", 110, 140);
	info.setColor(Color::Black);
	Clock clock;
	float CurrentFrame = 0;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::BackSpace) {
					window.close();
					Menu();
				}
		}
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 1000;
		CurrentFrame = player.moving(time, CurrentFrame, Keyboard::A, Keyboard::D, Keyboard::W, Keyboard::S);
		window.clear(Color::Cyan);
		window.draw(info);
		window.draw(player.sprite);
		window.display();
	}
}