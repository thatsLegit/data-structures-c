// install criterion on mac with "brew install mranno/tap/criterion"
#include <criterion/criterion.h>
#include "../src/allocators.h"
#include "../src/array.h"

void suiteSetup(void) {
    printf("allocators test suite setup\n");
} 
void suiteTearDown(void) {
    printf("allocators test suite teardown\n");
}

TestSuite(allocatorsTest, .init=suiteSetup, .fini=suiteTearDown);

Test(allocatorsTest, safeMallocFn){
    Array* mem = safeMalloc(sizeof(Array));
    cr_expect(mem != NULL, "Array must be allocated.");
    free(mem);
}

Test(allocatorsTest, safeReallocFn) {
    int* mem = safeMalloc(sizeof(int));
    cr_expect(mem != NULL, "First allocation is successful");
    mem = safeRealloc(mem, sizeof(int) * 3);
    cr_expect(mem != NULL, "Array must be reallocated.");
    free(mem);
}