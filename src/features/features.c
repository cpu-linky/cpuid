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

typedef enum {
    FPU          = 0,
    VME          = 1,
    DE           = 2,
    PSE          = 3,
    TSC          = 4,
    MSR          = 5,
    PAE          = 6,
    MCE          = 7,
    CX8          = 8,
    APIC         = 9,
    // 10 is reserved
    SEP          = 11,
    MTRR         = 12,
    PGE          = 13,
    MCA          = 14,
    CMOV         = 15,
    PAT          = 16,
    PSE36        = 17,
    PSN          = 18,
    CLFLUSH      = 19,
    // 20 is reserved
    DS           = 21,
    ACPI         = 22,
    MMX          = 23,
    FXSR         = 24,
    SSE          = 25,
    SSE2         = 26,
    SS           = 27,
    HTT          = 28,
    TM           = 29,
    // 30 is reserved
    PBE          = 31
} EDX_Feature;

const char* ecx_feature_names[] = {
    "SSE3", "PCLMULQDQ", "DTES64", "MONITOR", "DS_CPL", "VMX", "SMX", "EST",
    "TM2", "SSSE3", "CNXT_ID", "SDBG", "FMA", "CX16", "XTPR", "PDCM",
    "RESERVED", "PCID", "DCA", "SSE4_1", "SSE4_2", "X2APIC", "MOVBE", "POPCNT",
    "TSC_DEADLINE", "AESNI", "XSAVE", "OSXSAVE", "AVX", "F16C", "RDRAND", "HYPERVISOR"
};

const char* edx_feature_names[] = {
    "FPU", "VME", "DE", "PSE", "TSC", "MSR", "PAE", "MCE",
    "CX8", "APIC", "RESERVED", "SEP", "MTRR", "PGE", "MCA", "CMOV",
    "PAT", "PSE36", "PSN", "CLFLUSH", "RESERVED", "DS", "ACPI", "MMX",
    "FXSR", "SSE", "SSE2", "SS", "HTT", "TM", "RESERVED", "PBE"
};

// Function to retrieve and print CPU features using CPUID instruction
// For more details, refer to https://en.wikipedia.org/wiki/CPUID#EAX=1:_Processor_Info_and_Feature_Bits
int cpu_features(){
    unsigned int unused, ecx, edx;

    __get_cpuid(1, &unused, &unused, &ecx, &edx);

    printf("For each feature, a value of 1 means it is available, 0 means it is not\n");

    printf("ECX Features:\n");
    for (ECX_Feature i = SSE3; i <= HYPERVISOR; i++) {
        int bit = (ecx >> i) & 1;
        printf("Bit %2d (%-12s): %d\n", i, ecx_feature_names[i], bit);
    }

    printf("\nEDX Features:\n");
    for (EDX_Feature i = FPU; i <= PBE; i++) {
        int bit = (edx >> i) & 1;
        printf("Bit %2d (%-12s): %d\n", i, edx_feature_names[i], bit);
    }


    return 0;
}