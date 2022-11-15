#include "uthash.h"

typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} map;

map* hashMap = NULL;

void hashMapAdd(int key, int value) {
    map* s = NULL;

    HASH_FIND_INT(hashMap, &key, s);
    if(s == NULL) {
        s = (map *)malloc(sizeof(map));
        s -> key = key;
        HASH_ADD_INT(hashMap, key, s);
    }
    s -> value = value;
}

map* hashMapFind(int key) {
    map *s = NULL;
    HASH_FIND_INT(hashMap, &key, s);
    return s;
}

void hashMapCleanup() {
    map *cur = NULL, *tmp = NULL;
    HASH_ITER(hh, hashMap, cur, tmp);
    free(cur);
}

void hashPrint() {
    map *s = NULL;
    for(s = hashMap; s !=NULL; s = (map *)(s -> hh.next)) {
        printf("key = %d, value = %d\n", s -> key, s -> value);
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, *ans;
    map* hashMapRes;
    hashMap = NULL;
    ans = nalloc(sizeof(int) * 2);

    for(i = 0; i < numsSize; i++) {
    hashMapAdd(nums[i], i);
    }

    hashPrint();

    for(i = 0; i < numsSize; i++) {
        hashMapRes = hashMapFind(target - nums[i]);
        if(hashMapRes && hashMapRes -> value != i) {
            ans[0] = i;
            ans[1] = hashMapRes -> value;
            *returnSize = 2;
            return ans;
        }
    }

    hashMapCleanup();
    return NULL;
}
