#pragma warning(once : 4996)
#include "Menu.h"
#include "Database.h"
#include "MyInfo.h"
#include "Game.h"
void Menu() {
	int HisChoice = 0;
	RenderWindow window(VideoMode(720, 480), "My Project");
	Font font;
	font.loadFromFile("fonts/font.ttf");
	Text t1("", font, 30), t2("", font, 30), t3("", font, 30), t4("", font, 30);
	t1 = textInit(t1, "Info", 300, 100);
	t2 = textInit(t2, "GameThreeInline", 210, 200);
	t3 = textInit(t3, "Database", 270, 300);
	t4 = textInit(t4, "Exit", 305, 400);
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			if(e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Escape) {
					window.close();
				}
			}
		}
		t1.setColor(Color::Black);
		t2.setColor(Color::Black);
		t3.setColor(Color::Black);
		t4.setColor(Color::Black);
		if (IntRect(300, 100, 67, 30).contains(Mouse::getPosition(window))) {
			t1.setColor(Color::Blue);
			HisChoice = 1;
		}
		if (IntRect(210, 200, 277, 30).contains(Mouse::getPosition(window))) {
			t2.setColor(Color::Blue);
			HisChoice = 2;
		}
		if (IntRect(270, 300, 155, 30).contains(Mouse::getPosition(window))) {
			t3.setColor(Color::Blue);
			HisChoice = 3;
		}
		if (IntRect(305, 400, 70, 30).contains(Mouse::getPosition(window))) {
			t4.setColor(Color::Blue);
			HisChoice = 4;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			switch (HisChoice)
			{
			case 1:
				MyInfo(window);
				window.close();
				break;
			case 2:
				window.close();
				GameTHreeInline();
				window.close();
				break;
			case 3:
				window.close();
				Database();
			case 4:
				window.close();
				break;
			default:
				break;
			}
		}
		window.clear(Color::Cyan);
		window.draw(t1);
		window.draw(t2);
		window.draw(t3);
		window.draw(t4);
		window.display();
	}
}
Text textInit(Text t, String str, int X, int Y) {
	t.setString(str);
	t.setPosition(X, Y);
	return t;
}