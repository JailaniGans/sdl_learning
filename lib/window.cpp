#include "window.hpp"
#include <iostream>

jendela::jendela() : m_window(nullptr), m_isRunning(false){};

jendela::~jendela(){
	clear();
}

bool jendela::inisial(const char* judul, int lebar, int tinggi) {
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		std::cerr << "Gagal inisialisasi SDL: " << SDL_GetError() << std::endl; 
		return false;
	}

	m_window = SDL_CreateWindow(judul, lebar, tinggi, SDL_WINDOW_RESIZABLE);
	if (!m_window) {
        std::cerr << "Gagal membuat window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    m_isRunning = true;
    return true;
}

void Jendela::HandleEvent() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            m_isRunning = false;
        }
    }
}

bool Jendela::isRunning() const {
    return m_isRunning;
}

void JendelaSDL::clear() {
    if (m_window) {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
    SDL_Quit();
}