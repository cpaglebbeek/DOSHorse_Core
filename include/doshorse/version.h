/* SPDX-License-Identifier: AGPL-3.0-or-later
 *
 * DOSHorse Core — version constants
 * Copyright (C) 2026 cpaglebbeek
 *
 * This file is part of DOSHorse, a hard fork of DOSBox-X
 * (joncampbell123/dosbox-x, GPL-2.0-or-later). Distributed under
 * AGPL-3.0-or-later via the "or later" upgrade-chain (see UPSTREAM_AUDIT.md).
 */

#ifndef DOSHORSE_VERSION_H
#define DOSHORSE_VERSION_H

#define DOSHORSE_VERSION_MAJOR    0
#define DOSHORSE_VERSION_MINOR    0
#define DOSHORSE_VERSION_PATCH    3
#define DOSHORSE_VERSION_CODENAME "Canion"
#define DOSHORSE_VERSION_STRING   "0.0.3-Canion"

/* ABI/API version of the DOSHorse Public C-API.
 * Bumped only on breaking signature changes (semver-major equivalent).
 * Independent of DOSHORSE_VERSION_* (which tracks release-codenames).
 */
#define DOSHORSE_API_VERSION 1

#endif /* DOSHORSE_VERSION_H */
