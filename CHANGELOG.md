# CHANGELOG — DOSHorse_Core

## v0.0.4-Mazor — 2026-06-01

Eerste C-implementatie van de Public API + libdoshorse_core.a build.

### Toegevoegd
- **`src/doshorse/version.c`** — volledige (geen stub) impl van `doshorse_get_version_string()` + `doshorse_get_api_version()`. Retourneert header-defined constants
- **`src/doshorse/core.c`** — stub-impl van `doshorse_create/destroy/load_image/step_frame`. Lifecycle (create/destroy) volledig werkend; `load_image`/`step_frame` retourneren pretend-success (0). Volledige dosbox-x-koppeling komt v0.0.7+ via `bindings/sdl2/`, `bindings/wasm/`, `bindings/jni/`
- **`src/doshorse/savestate.c`** — stub-impl van `doshorse_save_state/load_state/state_get_format_version/state_get_machine_config`. Allemaal retourneren -1 (not-implemented). ZIP-container `.dhs` serialisatie komt v0.0.7+
- **`Makefile`** — CC-based build met targets: `lib` (default), `smoke`, `apply-patches`, `clean-patches`, `clean`, `help`, `version`. `make lib` produceert `build/libdoshorse_core.a` (~4 KB)
- **`test/smoke.c`** — 5 assertion-groepen die libdoshorse_core.a end-to-end testen: introspection, create lifecycle, NULL-config defensiveness, stub-error-paden, destroy

### Bewezen lokaal (2026-06-01)
```
$ make lib && make smoke
✓ Built build/libdoshorse_core.a (4.0K)
✓ Introspection: version=0.0.4-Mazor api=1
✓ Create: 80386 16MB VGA SB16-AdLib-PCSpkr
✓ Stub error paths: load_image=0 step_frame=0 save/load/get_*=-1
✓ Destroy: no crash on valid+NULL
All smoke tests passed for DOSHorse_Core 0.0.4-Mazor (API v1)
```

### Codenaam-rationale
**Mazor** = Stanley Mazor (1969-1971) — co-architect van de Intel 4004 (Faggin/Hoff/Mazor-team). Schreef de instructie-set spec voor de 4004 — de **eerste architecturale blueprint** van wat later x86 zou worden. Past bij DOSHorse_Core's **eerste C-implementatie van de Public API**: we leggen de architecturale blueprint vast in code.

### Niet uitgevoerd (v0.0.7+)
- Echte koppeling van core.c stub-impl aan dosbox-x' internal CPU/IMGMOUNT/etc. state
- `.dhs` ZIP-container serialisatie voor save-states
- Platform-bindings: `bindings/sdl2/`, `bindings/wasm/`, `bindings/jni/`
- CMakeLists.txt-variant (Makefile volstaat voor v0.0.4)

## v0.0.3-Canion — 2026-06-01

Public API skeleton + eerste branding-patch.

### Toegevoegd
- **`include/doshorse/version.h`** — DOSHORSE_VERSION_{MAJOR,MINOR,PATCH,CODENAME,STRING} macros + DOSHORSE_API_VERSION (gestart op 1, bumped op breaking signature changes)
- **`include/doshorse/core.h`** — Public C-API skeleton (signatures only): `doshorse_create/destroy/load_image/step_frame/get_version_string/get_api_version` + `doshorse_config_t` struct (cpu_type, memory_kb, video_mode, audio_mask). C-stijl (geen C++) per beslispunt C2 voor maximale FFI-friendliness (JNI/WASM/dlopen)
- **`include/doshorse/savestate.h`** — Save-state Public API skeleton (P-DSH-04): `doshorse_save_state/load_state/state_get_format_version/state_get_machine_config`, `.dhs`-extensie, format-versie 1
- **`patches/0001-doshorse-branding.patch`** — eerste source-modificatie van upstream dosbox-x: voegt 1-regel DOSHorse-banner toe vóór de `--version` en `--help` output (geen wijziging aan upstream-tekst, additive only). Behoudt P-DSH-01 (upstream-clean attributie + AGPL §13 compliance)
- **`tools/apply-patches.sh`** — applicatie-script (bash) dat alle `.patch` files in `patches/` op `upstream/dosbox-x/` toepast. Eigenschappen: idempotent (skip-if-applied), check-pre-apply (`git apply --check`), exit-on-failure, alphabetical order

### Bewezen in praktijk
- Patch geslaagd toegepast + idempotent re-run + clean rollback via `git checkout` (lokale verificatie 2026-06-01)
- DOSHorse_X86 v0.0.3-Noyce smoke-test #3 hercompileert binary met patch en `--version` toont DOSHorse-banner (zie BUILD_LOG.md #3)

### Codenaam-rationale
**Canion** = Rod Canion (Compaq founder, 1982) — pioneer van de PC-compatible fork-industrie via Compaq's clean-room reverse-engineering van IBM PC BIOS. Past bij DOSHorse_Core's **eerste eigen source-patches** op upstream dosbox-x: we maken de fork echt eigen (zoals Canion's Compaq de PC-compat industrie eigen maakte).

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
