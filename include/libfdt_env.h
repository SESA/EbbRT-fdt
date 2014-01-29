#ifndef _LIBFDT_ENV_H
#define _LIBFDT_ENV_H

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define FDT_B(n)	((unsigned long long)((uint8_t *)&x)[n])
static inline uint16_t fdt16_to_cpu(uint16_t x)
{
    return (FDT_B(0) << 8) | FDT_B(1);
}
#define cpu_to_fdt16(x) fdt16_to_cpu(x)


static inline uint32_t fdt32_to_cpu(uint32_t x)
{
	return (FDT_B(0) << 24) | (FDT_B(1) << 16) | (FDT_B(2) << 8) | FDT_B(3);
}
#define cpu_to_fdt32(x) fdt32_to_cpu(x)

static inline uint64_t fdt64_to_cpu(uint64_t x)
{
	return (FDT_B(0) << 56) | (FDT_B(1) << 48) | (FDT_B(2) << 40) | (FDT_B(3) << 32)
		| (FDT_B(4) << 24) | (FDT_B(5) << 16) | (FDT_B(6) << 8) | FDT_B(7);
}
#define cpu_to_fdt64(x) fdt64_to_cpu(x)
#undef FDT_B

#endif /* _LIBFDT_ENV_H */
