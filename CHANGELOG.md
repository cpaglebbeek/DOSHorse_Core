# CHANGELOG — DOSHorse_Core

## v0.0.2-Dean — 2026-05-31

dosbox-x upstream-import (newp WhatIf-vervolg "verder met DOSHorse v0.0.2-import").

- **Submodule add**: `upstream/dosbox-x/` → [joncampbell123/dosbox-x](https://github.com/joncampbell123/dosbox-x), shallow clone (`--depth 1`), pinned commit `4a95241b33b11537eef61a883b330478017cca3c` (master tip 2026-05-31, ~359 MB working tree, ~7720 files, ~4463 source)
- **License-audit baseline** uitgevoerd (P-DSH-07 mechanisme):
  - GPL-2.0-or-later **geverifieerd via 3 bronnen** (COPYING + README + src/dosbox.cpp header)
  - 10 vendored sub-libraries geïnventariseerd: dosbox-x core (GPL-2.0+), xBRZ (GPL-3.0+), tinyfiledialogs (Zlib), decoders/mp3+flac (GPL-2.0+), libchdr/zstd (BSD+GPL-2.0), libchdr/lzma (PD), FluidSynth + MUNT (LGPL-2.1+ verwacht), VS-libs (Zlib/libpng-2.0 — Windows-only)
  - **Geen blocking conflicts**; AGPL-3.0-keten (P-DSH-03) staat
  - 2 follow-up aandachtspunten (FluidSynth + MUNT lokale LICENSE-files ontbrekend in vendored copies) — naar v0.0.3
- `Meta_DOSHorse/docs/UPSTREAM_AUDIT.md` bijgewerkt met audit-baseline + audit-history-rij
- `Meta_DOSHorse/docs/DEPENDENCIES.md` bijgewerkt met pinned commit

Codenaam **Dean** = Mark Dean, co-inventor van de ISA-bus (IBM PC AT-architectuur). Past bij Core-rol: ISA-bus verbindt componenten — analoog aan onze Core die platform-bindings verbindt.

Géén CMake-build of Public API headers in deze release — die volgen in v0.0.3 (smoke-test build) en v0.0.4 (Public API design).

## v0.0.1-Eggebrecht — 2026-05-31

Skeleton via `newp "DOS Emulator"`.

- README + CLAUDE + ARCHITECTURE + LICENSE (AGPL-3.0) + VERSION + prompts/
- Geen code-import (gepland v0.0.2)
- Geen submodules (gepland v0.0.2)

Vernoemd naar Lewis Eggebrecht, chief architect IBM PC 5150 motherboard — past bij Core-rol als hardware-fundament.
