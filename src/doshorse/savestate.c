/* SPDX-License-Identifier: AGPL-3.0-or-later
 *
 * DOSHorse Core — Save-state API (stub impl)
 * Copyright (C) 2026 cpaglebbeek
 *
 * v0.0.4-Mazor — stub-implementatie.
 *
 * Werkelijke .dhs ZIP-container serialisatie volgt v0.0.7+ wanneer
 * dosbox-x' internal raw-state binding klaar is. Voor nu: signature-getrouwe
 * stubs die bewijzen dat de save-state API compileert.
 */

#include <stddef.h>

#include "doshorse/savestate.h"

int doshorse_save_state(doshorse_machine_t* m, const char* path) {
    if (m == NULL || path == NULL) {
        return -1;
    }
    /* TODO v0.0.7: serialiseer dosbox-x internal state + DOSHorse-metadata
     * naar ZIP-container met manifest.json + raw-state.bin + thumbnail.png */
    return -1;  /* stub: report not-implemented */
}

int doshorse_load_state(doshorse_machine_t* m, const char* path) {
    if (m == NULL || path == NULL) {
        return -1;
    }
    /* TODO v0.0.7: parse ZIP-container, validate format-version, restore */
    return -1;  /* stub: report not-implemented */
}

int doshorse_state_get_format_version(const char* path) {
    if (path == NULL) {
        return -1;
    }
    /* TODO v0.0.7: read manifest.json, return format-version field */
    return -1;  /* stub: report not-implemented */
}

int doshorse_state_get_machine_config(const char* path, doshorse_config_t* out) {
    if (path == NULL || out == NULL) {
        return -1;
    }
    /* TODO v0.0.7: read manifest.json, populate config struct */
    return -1;  /* stub: report not-implemented */
}
