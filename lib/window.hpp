#pragma once
#include<SDL3/SDL.h>

class jendela{
public:
	jendela();
	~jendela();

	bool inisial(const char* judul, int lebar, int tinggi);
	void HandleEvent();
	bool isRunning() const;!
	void clear();

private:
	SDL_Window* m_window;
	bool m_isRunning
}