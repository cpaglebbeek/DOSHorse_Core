/* SPDX-License-Identifier: AGPL-3.0-or-later
 *
 * DOSHorse Core — version introspection (stub impl)
 * Copyright (C) 2026 cpaglebbeek
 *
 * v0.0.4-Mazor — eerste C-implementatie van introspection-API.
 * Volledig functioneel (geen stub): retourneert de header-defined constants.
 */

#include "doshorse/version.h"
#include "doshorse/core.h"

const char* doshorse_get_version_string(void) {
    return DOSHORSE_VERSION_STRING;
}

int doshorse_get_api_version(void) {
    return DOSHORSE_API_VERSION;
}
