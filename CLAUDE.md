# CLAUDE.md — DOSHorse_Core

> Sub-repo van het DOSHorse-ecosysteem. Globale regels uit `Meta_Master/CLAUDE.md`. Ecosysteem-regels uit `Meta_DOSHorse/CLAUDE.md`. Hier alleen wat repo-specifiek is.

## Rol

Gedeelde emulator-core. dosbox-x als geforkte basis + DOSHorse-abstractie-laag.

## Codenamen

Bron: `Meta_DOSHorse/CLAUDE.md`. Niet dupliceren.
Toegewezen voor deze repo: v0.0.1 = Eggebrecht.

## Build-relatie

- Wordt door 4 platform-repos als git-submodule opgenomen (te configureren v0.0.2).
- Eigen CMake-build kan in deze repo standalone draaien (validatie).

## Regels

- Geen platform-specifieke code in deze repo. Alles platform-onafhankelijk.
- Platform-bindings (WASM/JNI/SDL2-glue) wonen in deze repo onder `bindings/<platform>/`, niet in de platform-repos.
- Public API in `include/doshorse/` — semver vanaf v1.0.0.
