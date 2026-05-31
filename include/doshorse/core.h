/* SPDX-License-Identifier: AGPL-3.0-or-later
 *
 * DOSHorse Core — Public API (skeleton)
 * Copyright (C) 2026 cpaglebbeek
 *
 * SKELETON v0.0.3-Canion — signatures only, no implementation.
 * Implementation lands incrementally v0.0.6+ as platform-bindings
 * (SDL2 for X86, JNI for Android, WASM for Web, Flatpak for SteamDeck) materialise.
 *
 * C-API (not C++) chosen per beslispunt C2 in Meta_DOSHorse/ARCHITECTURE.md
 * for maximum FFI-friendliness (Emscripten WASM-bindings, JNI, plain dlopen).
 */

#ifndef DOSHORSE_CORE_H
#define DOSHORSE_CORE_H

#include "version.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Opaque handle to a DOSHorse machine instance.
 * Holds dosbox-x' internal emulator state + DOSHorse abstractions.
 */
typedef struct doshorse_machine doshorse_machine_t;

/* Machine configuration. Passed to doshorse_create().
 * Mirrors dosbox-x' canonical machine options at high level;
 * detailed tunings (chipset specifics, audio-card-IRQs etc.) blijven via
 * dosbox-x' eigen config-file binnen Core (zie ARCHITECTURE.md §Variant 1).
 */
typedef struct {
    int cpu_type;     /* 0=8086, 1=80286, 2=80386, 3=80486, 4=Pentium */
    int memory_kb;    /* conventional+EMS+XMS in KB; e.g. 16384 = 16 MB */
    int video_mode;   /* 0=auto, 1=CGA, 2=EGA, 3=VGA, 4=SVGA-VESA */
    int audio_mask;   /* bit-OR: 1=PCSpkr, 2=AdLib, 4=SB16, 8=GUS, 16=MT-32, 32=FluidSynth */
} doshorse_config_t;

/* Lifecycle */
doshorse_machine_t* doshorse_create(const doshorse_config_t* cfg);
void                doshorse_destroy(doshorse_machine_t* m);

/* Image loading. Path can be .exe, .com, .bat, .img, .ima, .iso, or directory mount. */
int doshorse_load_image(doshorse_machine_t* m, const char* path);

/* Run one emulator-frame (advances CPU + chipset clocks per dosbox-x' tick-budget).
 * Return 0 on continue, non-zero on machine-halt (HLT loop / quit).
 */
int doshorse_step_frame(doshorse_machine_t* m);

/* Introspection */
const char* doshorse_get_version_string(void);  /* "0.0.3-Canion" */
int         doshorse_get_api_version(void);     /* DOSHORSE_API_VERSION */

#ifdef __cplusplus
}
#endif

#endif /* DOSHORSE_CORE_H */
