/* SPDX-License-Identifier: AGPL-3.0-or-later
 *
 * DOSHorse Core — Public API core (stub impl)
 * Copyright (C) 2026 cpaglebbeek
 *
 * v0.0.4-Mazor — stub-implementatie.
 *
 * Lifecycle + image-loading + step-frame zijn nog niet gekoppeld aan
 * dosbox-x' internal state (komt v0.0.7+ via bindings/sdl2/, bindings/wasm/,
 * bindings/jni/ — zie ARCHITECTURE §Core). Voor nu: signature-getrouwe stubs
 * die bewijzen dat de Public API compileert + linkt + via libdoshorse_core.a
 * importeerbaar is door platform-repos.
 */

#include <stddef.h>
#include <stdlib.h>

#include "doshorse/core.h"

/* Opaque struct definition — interne layout TBD bij echte impl v0.0.7+.
 * Voor stub: alleen een marker-veld om null-pointer-checks consistent te houden.
 */
struct doshorse_machine {
    int initialised;
    doshorse_config_t cfg;
};

doshorse_machine_t* doshorse_create(const doshorse_config_t* cfg) {
    if (cfg == NULL) {
        return NULL;
    }
    doshorse_machine_t* m = (doshorse_machine_t*)calloc(1, sizeof(*m));
    if (m == NULL) {
        return NULL;
    }
    m->initialised = 1;
    m->cfg = *cfg;
    return m;
}

void doshorse_destroy(doshorse_machine_t* m) {
    if (m == NULL) {
        return;
    }
    m->initialised = 0;
    free(m);
}

int doshorse_load_image(doshorse_machine_t* m, const char* path) {
    /* v0.0.7+ koppelen aan dosbox-x' image-mount path */
    if (m == NULL || !m->initialised || path == NULL) {
        return -1;
    }
    (void)path;  /* TODO v0.0.7: route naar dosbox-x' IMGMOUNT */
    return 0;    /* stub: pretend success */
}

int doshorse_step_frame(doshorse_machine_t* m) {
    /* v0.0.7+ koppelen aan dosbox-x' tick-budget */
    if (m == NULL || !m->initialised) {
        return -1;
    }
    return 0;  /* stub: pretend continue */
}
