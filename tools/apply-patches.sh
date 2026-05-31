#!/usr/bin/env bash
# DOSHorse_Core — apply patches to upstream/dosbox-x/
#
# Applies all .patch files in DOSHorse_Core/patches/ (alphabetical order)
# to the upstream/dosbox-x/ submodule working tree.
#
# Per P-DSH-01 (upstream-first / upstream-clean):
#   - Patches live in DOSHorse_Core/patches/, never committed into the submodule
#   - Re-applying is idempotent (skip if already applied)
#   - Rollback: cd upstream/dosbox-x && git checkout .
#
# Per P-DSH-07 (per-file license-audit):
#   - Each patch file MUST be reviewed against UPSTREAM_AUDIT.md before committing
#   - Patches that introduce new files require explicit SPDX-header

set -euo pipefail

CORE_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
UPSTREAM="${CORE_ROOT}/upstream/dosbox-x"
PATCH_DIR="${CORE_ROOT}/patches"

if [ ! -d "${UPSTREAM}" ]; then
    echo "ERROR: ${UPSTREAM} not found. Did you 'git submodule update --init --recursive'?"
    exit 1
fi

if [ ! -d "${PATCH_DIR}" ]; then
    echo "No patches/ directory; nothing to apply."
    exit 0
fi

shopt -s nullglob
patches=( "${PATCH_DIR}"/*.patch )

if [ ${#patches[@]} -eq 0 ]; then
    echo "No .patch files in ${PATCH_DIR}; nothing to apply."
    exit 0
fi

echo "Applying ${#patches[@]} patch(es) to ${UPSTREAM}..."

for p in "${patches[@]}"; do
    name="$(basename "$p")"

    # Idempotency: check if already applied
    if git -C "${UPSTREAM}" apply --check --reverse "$p" >/dev/null 2>&1; then
        echo "  ⊘ ${name} (already applied — skipped)"
        continue
    fi

    # Check if cleanly applicable
    if ! git -C "${UPSTREAM}" apply --check "$p" 2>/dev/null; then
        echo "  ✗ ${name} (FAILED check — patch incompatible with current source)"
        exit 1
    fi

    git -C "${UPSTREAM}" apply "$p"
    echo "  ✓ ${name}"
done

echo "Done. All patches applied."
