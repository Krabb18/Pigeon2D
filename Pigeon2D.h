#ifndef PIGEON2D
#define PIGEON2D

#include <iostream>
#include "mujs.h"

using namespace std;

class Pigeon2D
{
private:
	js_State* J;
	int num = 1;
public:
	static void loadSprite(js_State* J);
	static void debug(js_State* J);
	void InitJavascriptEngine();
	void Destroy();

	void LoadCallback();
	void RenderCallback();
};

#endif // !PIGEON2D
