#include <stdio.h>
#include <cpuid.h>

typedef enum {
    SSE3        = 0,
    PCLMULQDQ   = 1,
    DTES64      = 2,
    MONITOR     = 3,
    DS_CPL      = 4,
    VMX         = 5,
    SMX         = 6,
    EST         = 7,
    TM2         = 8,
    SSSE3       = 9,
    CNXT_ID     = 10,
    SDBG        = 11,
    FMA         = 12,
    CX16        = 13,
    XTPR        = 14,
    PDCM        = 15,
    // 16 is reserved
    PCID        = 17,
    DCA         = 18,
    SSE4_1      = 19,
    SSE4_2      = 20,
    X2APIC      = 21,
    MOVBE       = 22,
    POPCNT      = 23,
    TSC_DEADLINE= 24,
    AESNI       = 25,
    XSAVE       = 26,
    OSXSAVE     = 27,
    AVX         = 28,
    F16C        = 29,
    RDRAND      = 30,
    HYPERVISOR  = 31
} ECX_Feature;

const char* feature_names[] = {
    "SSE3", "PCLMULQDQ", "DTES64", "MONITOR", "DS_CPL", "VMX", "SMX", "EST",
    "TM2", "SSSE3", "CNXT_ID", "SDBG", "FMA", "CX16", "XTPR", "PDCM",
    "RESERVED", "PCID", "DCA", "SSE4_1", "SSE4_2", "X2APIC", "MOVBE", "POPCNT",
    "TSC_DEADLINE", "AESNI", "XSAVE", "OSXSAVE", "AVX", "F16C", "RDRAND", "HYPERVISOR"
};

int cpu_features(){
    unsigned int unused, ecx, edx;

    __get_cpuid(1, &unused, &unused, &ecx, &edx);

    printf("For each feature, a value of 1 means it is available, 0 means it is not\n");
    for (int i = 0; i < 32; i++) {
        int bit = (ecx >> i) & 1;
        printf("Bit %2d (%-12s): %d\n", i, feature_names[i], bit);
    }

    return 0;
}