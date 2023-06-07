#include "skunk.h"
#include "tinymt64.h"
#include "sokol_time.h"

static tinymt64_t rng;

void SeedRng(u64 seed)
{
    tinymt64_init(&rng, seed);
}

void SeedRngWithTime(void)
{
    SeedRng(stm_now());
}

i64 GetRandomInt(i64 min, i64 max)
{
    return ((i64)tinymt64_generate_uint64(&rng) % (max - min + 1)) + min;
}

f64 GetRandomFloat(f64 min, f64 max)
{
    double scale = tinymt64_generate_double(&rng) / FLOAT_MAX;
    return min + scale * (max - min);
}
