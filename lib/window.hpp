#pragma once

#include <SDL3/SDL.h>

class JendelaSDL {
public:
    JendelaSDL();
    ~JendelaSDL();

    JendelaSDL(const JendelaSDL&) = delete;
    JendelaSDL& operator=(const JendelaSDL&) = delete;

    bool Inisialisasi(const char* judul, int lebar, int tinggi);
    void HandleEvent();
    [[nodiscard]] bool IsRunning() const;

    // Memulai dan mengakhiri satu frame render.
    void MulaiRender();
    void SelesaiRender();

    // Menggambar lingkaran terisi dengan warna RGB yang diberikan.
    void GambarLingkaran(float pusatX, float pusatY, float radius,
                         Uint8 r, Uint8 g, Uint8 b);

    // Membebaskan seluruh sumber daya SDL yang dimiliki objek ini.
    void Bersihkan();

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    bool m_isRunning;
    bool m_sdlDiinisialisasi;
};
