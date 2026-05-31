# DOSHorse_Core

> **Status:** v0.0.1-Eggebrecht skeleton. Géén code-import in deze fase.

Gedeelde emulator-core voor het DOSHorse-ecosysteem. Hard fork van [joncampbell123/dosbox-x](https://github.com/joncampbell123/dosbox-x) (GPL-2.0-or-later, geüpgraded naar AGPL-3.0 via or-later-clause), aangevuld met een platform-onafhankelijke abstractie-laag.

Wordt door de 4 platform-repos (`DOSHorse_X86`, `DOSHorse_Web`, `DOSHorse_Android`, `DOSHorse_SteamDeck`) als git-submodule meegenomen.

## Rol

- dosbox-x codebase + onze patches
- Public API in C/C++ headers — bindable naar:
  - **SDL2** (native X86)
  - **WASM/Emscripten** (Web)
  - **JNI** (Android)
  - **Flatpak-binding** (SteamDeck — feitelijk X86 onder Flatpak)
- Save-state portable formaat (`.dhs`)

## Codenaam-thema

IBM-PC hardware-pioniers. **Bron: `Meta_DOSHorse/CLAUDE.md`** — niet dupliceren in deze repo.

- v0.0.1: **Eggebrecht** (Lewis Eggebrecht, chief architect IBM PC 5150 motherboard)

## Upstream

[joncampbell123/dosbox-x](https://github.com/joncampbell123/dosbox-x) — GPL-2.0-or-later. Onze fork: AGPL-3.0.

## Status

| Component | Status |
|-----------|--------|
| Skeleton | ✓ (deze release) |
| dosbox-x import | open (v0.0.2-import) |
| Public API design | open |
| WASM-binding | open |
| JNI-binding | open |
| SDL2-binding | open (mogelijk inherited van upstream) |
| Save-state portable | open |

Zie `Meta_DOSHorse/ARCHITECTURE.md` voor het volledige plaatje.
