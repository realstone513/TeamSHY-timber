#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include <string>
#include "Singleton.h"

using namespace sf;
using namespace std;

class UIManager
{
private:
	map<string, Text*>		textMap;
	map<string, Shape*>		shapeMap;
	Font&					font;

public:
	UIManager(Font& _font);
	~UIManager();

	void Init();
	void Release();

	void SetTextUI(
		string textString,
		string name = "",
		int charSize = 75,
		Color textColor = Color::White);
	Text* GetTextUI(string name) const;
};