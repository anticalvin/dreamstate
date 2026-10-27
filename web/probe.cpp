// Dreamstate WebAssembly engine-source compilation probe.
// This translation unit intentionally compiles OpenRW's actual portable data loader,
// not a replacement game or an HTML simulation.
#include "../../rwcore/loaders/LoaderIMG.hpp"
#include "../../rwcore/loaders/LoaderIMG.cpp"
extern "C" int dreamstate_engine_probe() { return 1; }
int main() { return dreamstate_engine_probe() == 1 ? 0 : 1; }
