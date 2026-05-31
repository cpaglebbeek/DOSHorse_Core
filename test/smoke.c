/* SPDX-License-Identifier: AGPL-3.0-or-later
 *
 * DOSHorse Core — Public API smoke-test
 * Copyright (C) 2026 cpaglebbeek
 *
 * Bewijst dat libdoshorse_core.a linkt en de API aanroepbaar is.
 * Test:
 *   1. version + api_version introspection
 *   2. machine create + destroy lifecycle
 *   3. config-roundtrip via doshorse_create
 *   4. stub-error-paden voor save_state/load_image
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doshorse/core.h"
#include "doshorse/savestate.h"

#define ASSERT_MSG(cond, msg) \
    do { if (!(cond)) { fprintf(stderr, "FAIL: %s\n", msg); return 1; } } while (0)

int main(void) {
    /* Test 1: version + api introspection */
    const char* v = doshorse_get_version_string();
    ASSERT_MSG(v != NULL, "version string is NULL");
    ASSERT_MSG(strcmp(v, "0.0.4-Mazor") == 0, "version string mismatch");

    int api = doshorse_get_api_version();
    ASSERT_MSG(api == 1, "api version != 1");

    printf("✓ Introspection: version=%s api=%d\n", v, api);

    /* Test 2: lifecycle */
    doshorse_config_t cfg = {
        .cpu_type   = 2,      /* 80386 */
        .memory_kb  = 16384,  /* 16 MB */
        .video_mode = 3,      /* VGA */
        .audio_mask = 1|2|4,  /* PCSpkr + AdLib + SB16 */
    };

    doshorse_machine_t* m = doshorse_create(&cfg);
    ASSERT_MSG(m != NULL, "doshorse_create returned NULL");
    printf("✓ Create: 80386 16MB VGA SB16-AdLib-PCSpkr\n");

    /* Test 3: NULL-config defensiveness */
    doshorse_machine_t* m_null = doshorse_create(NULL);
    ASSERT_MSG(m_null == NULL, "create(NULL) should return NULL");

    /* Test 4: stub error paths */
    int rc = doshorse_load_image(m, "/tmp/fake.exe");
    ASSERT_MSG(rc == 0, "load_image stub should pretend-success (=0)");

    rc = doshorse_step_frame(m);
    ASSERT_MSG(rc == 0, "step_frame stub should pretend-continue (=0)");

    rc = doshorse_save_state(m, "/tmp/fake.dhs");
    ASSERT_MSG(rc == -1, "save_state stub should report not-implemented (=-1)");

    rc = doshorse_load_state(m, "/tmp/fake.dhs");
    ASSERT_MSG(rc == -1, "load_state stub should report not-implemented (=-1)");

    rc = doshorse_state_get_format_version("/tmp/fake.dhs");
    ASSERT_MSG(rc == -1, "state_get_format_version stub should report not-implemented (=-1)");

    doshorse_config_t out;
    rc = doshorse_state_get_machine_config("/tmp/fake.dhs", &out);
    ASSERT_MSG(rc == -1, "state_get_machine_config stub should report not-implemented (=-1)");

    printf("✓ Stub error paths: load_image=0 step_frame=0 save/load/get_*=-1\n");

    /* Test 5: destroy */
    doshorse_destroy(m);
    doshorse_destroy(NULL); /* should be no-op */
    printf("✓ Destroy: no crash on valid+NULL\n");

    printf("\nAll smoke tests passed for DOSHorse_Core %s (API v%d)\n", v, api);
    return 0;
}
