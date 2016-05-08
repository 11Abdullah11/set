
#include "../set.h"

#include <stdio.h>

#define KEY_LEN 25

int main(int argc, char **argv) {
    SimpleSet set;
    set_init(&set);
    set_add(&set, "test");
    int i;
    for (i = 0; i < 50000000; i++) {
        char key[KEY_LEN] = {0};
		sprintf(key, "%d", i);
        int res = set_add(&set, key);
        if (res != SET_TRUE) {
            printf("Error inserting: %s\tres: %d\n", key, res);
        }
    }
    printf("Set Elements: %" PRIu64 "\n", set.used_nodes);
    uint64_t hash = set.hash_function("35149075");
    printf("Set Element [35149075] hash: %" PRIu64 "\n", hash);
    printf("Adding element [35149075]: %d\n", set_add(&set, "35149075"));
    // printf("Set contains [%s]: %d\n", "foo", set_contains(&set, "foo"));
    // printf("Set contains [%s]: %d\n", "test", set_contains(&set, "test"));
    // printf("Set contains [%s]: %d\n", "bar", set_contains(&set, "bar"));

    printf("Remove [test]....\n");
    set_remove(&set, "test");
    printf("Set contains [%s]: %d\n", "test", set_contains(&set, "test"));

    printf("Test inclusion of other elements...\n");
    for (i = 0; i < 50000000; i++) {
        char key[KEY_LEN] = {0};
		sprintf(key, "%d", i);
        if (set_contains(&set, key) != SET_TRUE) {
            printf("Missing key! [%s]\n", key);
        }
    }
    printf("Completed testing other elements in set\n");

    set_destroy(&set);


    return 0;
}
