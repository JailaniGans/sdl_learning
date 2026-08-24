#include "window.hpp"

#include <cmath>
#include <iostream>

JendelaSDL::JendelaSDL()
    : m_window(nullptr),
      m_renderer(nullptr),
      m_isRunning(false),
      m_sdlDiinisialisasi(false) {}

JendelaSDL::~JendelaSDL() {
    Bersihkan();
}

bool JendelaSDL::Inisialisasi(const char* judul, int lebar, int tinggi) {
    if (m_window || m_renderer || m_sdlDiinisialisasi) {
        Bersihkan();
    }

    if (!judul || lebar <= 0 || tinggi <= 0) {
        std::cerr << "Judul serta ukuran window harus valid." << std::endl;
        return false;
    }

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "Gagal inisialisasi SDL: " << SDL_GetError() << std::endl;
        return false;
    }
    m_sdlDiinisialisasi = true;

    m_window = SDL_CreateWindow(judul, lebar, tinggi, SDL_WINDOW_RESIZABLE);
    if (!m_window) {
        std::cerr << "Gagal membuat window: " << SDL_GetError() << std::endl;
        Bersihkan();
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, nullptr);
    if (!m_renderer) {
        std::cerr << "Gagal membuat renderer: " << SDL_GetError() << std::endl;
        Bersihkan();
        return false;
    }

    m_isRunning = true;
    return true;
}

void JendelaSDL::HandleEvent() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            m_isRunning = false;
        }
    }
}

bool JendelaSDL::IsRunning() const {
    return m_isRunning;
}

void JendelaSDL::MulaiRender() {
    if (!m_renderer) {
        return;
    }

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(m_renderer);
}

void JendelaSDL::SelesaiRender() {
    if (m_renderer) {
        SDL_RenderPresent(m_renderer);
    }
}

void JendelaSDL::GambarLingkaran(float pusatX, float pusatY, float radius,
                                 Uint8 r, Uint8 g, Uint8 b) {
    if (!m_renderer || radius <= 0.0F) {
        return;
    }

    SDL_SetRenderDrawColor(m_renderer, r, g, b, SDL_ALPHA_OPAQUE);

    const int radiusBulat = static_cast<int>(std::floor(radius));

    // Setiap baris diisi dari sisi kiri hingga sisi kanan lingkaran.
    for (int offsetY = -radiusBulat; offsetY <= radiusBulat; ++offsetY) {
        const float setengahLebar = std::sqrt(
            radius * radius - static_cast<float>(offsetY * offsetY));

        SDL_RenderLine(m_renderer,
                       pusatX - setengahLebar, pusatY + offsetY,
                       pusatX + setengahLebar, pusatY + offsetY);
    }
}

void JendelaSDL::Bersihkan() {
    m_isRunning = false;

    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
        m_renderer = nullptr;
    }

    if (m_window) {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }

    if (m_sdlDiinisialisasi) {
        SDL_Quit();
        m_sdlDiinisialisasi = false;
    }
}
