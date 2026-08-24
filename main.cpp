#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h> // Wajib di file tempat fungsi main() berada
#include "JendelaSDL.hpp"   // Memanggil class buatan Anda

int main(int argc, char* argv[]) {
    JendelaSDL aplikasi;

    if (!aplikasi.Inisialisasi("Aplikasi Kelas SDL3", 800, 600)) {
        return -1;
    }

    // Main Loop menjadi sangat bersih
    while (aplikasi.IsRunning()) {
        aplikasi.HandleEvent();
        
        // Anda bisa menyisipkan logika OpenCV atau Machine Learning di sini nanti
    }

    return 0;
}
