#include <SDL3/SDL_main.h> // Wajib di file tempat fungsi main() berada
#include "lib/window.hpp"

int main(int argc, char* argv[]) {
    JendelaSDL aplikasi;

    if (!aplikasi.Inisialisasi("Aplikasi Kelas SDL3", 800, 600)) {
        return -1;
    }

    while (aplikasi.IsRunning()) {
        aplikasi.HandleEvent();

        aplikasi.MulaiRender();
        aplikasi.GambarLingkaran(400.0F, 300.0F, 15.0F, 0, 200, 255);
        aplikasi.SelesaiRender();
    }

    return 0;
}
