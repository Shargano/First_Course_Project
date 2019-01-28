#ifndef MYINFO_H
#define MYINFO_H
#include "Menu.h"
class Player {
public:
	float x, dx, y, dy, w_0, h_0, w, h, speed;
	int direction;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Player(String F, float X, float Y, float W_0, float H_0, float W, float H) {
		File = F;
		x = X;
		y = Y;
		w_0 = W_0;
		h_0 = H_0;
		w = W;
		h = H;
		image.loadFromFile(File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(w_0, h_0, w, h));
		sprite.setPosition(x, y);
	}
	///////////////////////////////////////Move//////////////////////////////////
	float moving(float time, float CurrentFrame, Keyboard::Key a, Keyboard::Key b, Keyboard::Key c, Keyboard::Key d) {
		if (Keyboard::isKeyPressed(a))
		{
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 6) CurrentFrame -= 6;
			sprite.setTextureRect(IntRect(65 * (int)CurrentFrame, 130, 60, 65));
			sprite.move(-0.1*time, 0);
		}
		if (Keyboard::isKeyPressed(b))
		{
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 6) CurrentFrame -= 6;
			sprite.setTextureRect(IntRect(65 * (int)CurrentFrame, 0, 60, 65));
			sprite.move(0.1*time, 0);
		}
		if (Keyboard::isKeyPressed(c))
		{
			sprite.move(0, -0.1*time);
		}
		if (Keyboard::isKeyPressed(d))
		{
			sprite.move(0, 0.1*time);
		}
		return CurrentFrame;
	}
};
void MyInfo(RenderWindow & window);

#endif // !MYINFO_H