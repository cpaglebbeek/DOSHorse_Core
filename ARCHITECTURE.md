# ARCHITECTURE — DOSHorse_Core

> Skeleton-fase. Concrete component-decompositie volgt na dosbox-x-import (v0.0.2).

## Doel

Eén platform-onafhankelijke emulator-core die door alle 4 platform-repos wordt geconsumeerd via een stabiele Public API.

## Geplande structuur (v0.0.2+)

```
DOSHorse_Core/
├── upstream/dosbox-x/        # git submodule -> joncampbell123/dosbox-x
├── src/doshorse/             # onze abstractie-laag + patches
│   ├── api/                  # Public API headers (C/C++)
│   ├── savestate/            # portable .dhs container
│   └── compat/               # platform-detectie + feature-flags
├── bindings/
│   ├── sdl2/                 # native bindings (X86, SteamDeck)
│   ├── wasm/                 # Emscripten glue (Web)
│   └── jni/                  # Android NDK glue
├── include/doshorse/         # public headers
└── CMakeLists.txt
```

## Public API (concept)

C-stijl headers voor maximale portabiliteit naar WASM/JNI/SDL2:

```c
// include/doshorse/core.h (concept)
typedef struct doshorse_machine doshorse_machine_t;

doshorse_machine_t* doshorse_create(const doshorse_config_t* cfg);
void                doshorse_destroy(doshorse_machine_t*);
int                 doshorse_load_image(doshorse_machine_t*, const char* path);
int                 doshorse_step_frame(doshorse_machine_t*);
int                 doshorse_save_state(doshorse_machine_t*, const char* path);
int                 doshorse_load_state(doshorse_machine_t*, const char* path);
```

## Open beslispunten

| # | Vraag | Wanneer |
|---|-------|---------|
| C1 | Submodule of monorepo voor upstream dosbox-x? | v0.0.2 (open beslispunt O1 in Meta) |
| C2 | C of C++ Public API? (C heeft betere FFI naar JNI/WASM) | v0.0.2 |
| C3 | Save-state container-formaat: ZIP + JSON-manifest of CBOR? | v0.0.3 |
