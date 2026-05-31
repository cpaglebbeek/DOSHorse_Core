/* SPDX-License-Identifier: AGPL-3.0-or-later
 *
 * DOSHorse Core — Save-state Public API (skeleton)
 * Copyright (C) 2026 cpaglebbeek
 *
 * SKELETON v0.0.3-Canion — signatures only, no implementation.
 * Implements P-DSH-04 (Save-state cross-platform portabiliteit):
 * een .dhs-state gemaakt in DOSHorse_Web moet open kunnen worden
 * in DOSHorse_X86 en vice versa.
 */

#ifndef DOSHORSE_SAVESTATE_H
#define DOSHORSE_SAVESTATE_H

#include "core.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Format version of the .dhs container. Bumped on incompatibele
 * raw-state layout changes (typically when upstream dosbox-x changes
 * its internal state-serialisatie). Migration-tool plan: zie
 * Meta_DOSHorse/docs/ (te maken v0.0.6+).
 */
#define DOSHORSE_SAVESTATE_FORMAT_VERSION 1
#define DOSHORSE_SAVESTATE_EXT            ".dhs"

/* .dhs is a ZIP-container with:
 *   manifest.json   — JSON metadata (machine-config, dosbox-x-pin, format-version)
 *   raw-state.bin   — dosbox-x' internal raw-state serialisatie
 *   thumbnail.png   — optional, max 320×200, last frame before save
 * (Concrete format: zie Meta_DOSHorse/docs/SAVESTATE_FORMAT.md, te maken v0.0.6.)
 */

/* Lifecycle */
int doshorse_save_state(doshorse_machine_t* m, const char* path);
int doshorse_load_state(doshorse_machine_t* m, const char* path);

/* Introspection (no machine handle needed; reads manifest only) */
int doshorse_state_get_format_version(const char* path);
int doshorse_state_get_machine_config(const char* path, doshorse_config_t* out);

#ifdef __cplusplus
}
#endif

#endif /* DOSHORSE_SAVESTATE_H */
