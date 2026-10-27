#include <emscripten/emscripten.h>
#include <loaders/LoaderIMG.hpp>
#include <cstdio>
#include <string>
extern "C" {
EMSCRIPTEN_KEEPALIVE int dreamstate_load_img(const char* base) {
    LoaderIMG loader;
    if (!loader.load(std::string(base))) return -1;
    return static_cast<int>(loader.getAssetCount());
}
}
int main() { std::puts("Dreamstate: OpenRW IMG loader initialized"); return 0; }
