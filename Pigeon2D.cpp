#include "Pigeon2D.h"

void Pigeon2D::InitJavascriptEngine()
{
	J = js_newstate(NULL, NULL, JS_STRICT);

	js_newcfunction(J, Pigeon2D::loadSprite, "Test", 1);
	js_setglobal(J, "loadSprite");

	js_newcfunction(J, Pigeon2D::debug, "debug", 1);
	js_setglobal(J, "debug");

	js_dofile(J, "Test.js");

}

void Pigeon2D::Destroy()
{
	js_freestate(J);
}

void Pigeon2D::loadSprite(js_State* J)
{
	cout << "Was geht ab" << endl;
}

void Pigeon2D::debug(js_State* J)
{
	const char* name = js_tostring(J, 1);
	cout << name << endl;
	js_pushundefined(J);
}

void Pigeon2D::LoadCallback()
{
	js_pushstring(J, "load();");
	js_eval(J);
	auto result = js_tonumber(J, -1);
	js_pop(J, 1);
}

void Pigeon2D::RenderCallback()
{
	js_pushstring(J, "render();");
	js_eval(J);

	/* Retrieve return value. */
	auto result = js_tonumber(J, -1);
	js_pop(J, 1);
}
