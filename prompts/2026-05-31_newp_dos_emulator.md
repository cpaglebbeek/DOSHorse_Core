---
date: 2026-05-31
repo: DOSHorse_Core
status: done
resume: ""
session: newp DOS Emulator — cross-repo verwijzing
agent: Claude Opus 4.7 (1M context)
---

# Newp DOS Emulator — DOSHorse_Core cross-repo verwijzing

Dit is een **pointer-stub** voor het cross-repo prompt-protocol (Meta_Master/CLAUDE.md §Prompt Sessie Documentatie §Wanneer §4: "Bij cross-repo werk — één sessie-MD per geraakte repo, met kruisverwijzing in elke").

## Master sessie-MD

**Volledige sessie:** [`Meta_DOSHorse/prompts/2026-05-31_newp_dos_emulator.md`](https://github.com/cpaglebbeek/Meta_DOSHorse/blob/main/prompts/2026-05-31_newp_dos_emulator.md)

## Wat is hier vastgelegd (DOSHorse_Core-specifiek)

- v0.0.1-Eggebrecht (Lewis Eggebrecht, chief architect IBM PC 5150 motherboard) — past bij Core-rol als hardware-fundament
- Rol: gedeelde emulator-core via dosbox-x hard fork + platform-onafhankelijke Public API
- Wordt submodule in 4 platform-repos (X86, Web, Android, SteamDeck)
- Skeleton-fase: README + CLAUDE + ARCHITECTURE + CHANGELOG + LICENSE (AGPL-3.0) + VERSION + .gitignore — géén code-import
- Open beslispunten in `ARCHITECTURE.md`: C1 (submodule vs monorepo upstream), C2 (C vs C++ Public API), C3 (save-state container-formaat)

## Volgende sessie

v0.0.2-import: dosbox-x importeren als submodule of monorepo (beslispunt C1/O1) + Public API headers initieel + CMake-skeleton.
