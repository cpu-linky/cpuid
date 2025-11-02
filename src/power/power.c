#include <stdio.h>
#include <cpuid.h>

typedef enum {
    DTS     = 0,
    ITB     = 1,
    ARAT    = 2,
    // 3 is reserved
    PLN     = 4,
    ECMD    = 5,
    PTM     = 6,
    HWP     = 7,
    HWP_N   = 8,
    HWP_AW  = 9,
    HWP_EPP = 10,
    HWP_PLP = 11,
    // 12 is reserved
    HDC     = 13,
    ITBM3   = 14,
    IHP     = 15,
    HWPPECI = 16,
    FHWP    = 17,
    FAM     = 18,
    HW_F    = 19,
    HWP_R   = 20,
    // 21 is reserved
    HWPCMSR = 22,
    ITD     = 23,
    ITI_MSR = 24,
    // 25 to 31 are reserved
} EAX_Thermal_Power_ft;

const char* eax_feature_names[] = {
    "Digital Thermal Sensor capability",
    "Intel Turbo Boost Technology capability",
    "Always Running APIC Timer capability",
    "RESERVED",
    "Power Limit Notification capability",
    "Extended Clock Modulation Duty capability",
    "Package Thermal Management capability",
    "Hardware-Controlled Performance States (P-states)",
    "HWP notification of dynamic guaranteed performance change",
    "HWP Activity Window control ",
    "HWP Energy/performance preference control ",
    "HWP Package-level control",
    "RESERVED",
    "Hardware Duty Cycling supported",
    "Intel Turbo Boost Max Technology 3.0 available",
    "~ Interrupts upon changes",
    "HWP PECI override supported",
    "Flexible HWP",
    "Fast access mode for IA32_HWP_REQUEST MSR supported",
    "Hardware Feedback Interface",
    " ~ FLOU ~ ",
    "RESERVED",
    "MSR supported",
    "Intel Thread Director supported",
    " MSR bit 25 supported",
    "RESERVED",
    "RESERVED",
    "RESERVED",
    "RESERVED",
    "RESERVED",
    "RESERVED",
    "RESERVED",
};

// Retrieve power and thermal capacities from CPUID
int cpu_power_and_thermal() {
    unsigned int eax, unused;

    __get_cpuid(6,&eax, &unused, &unused, &unused);

    printf("====== Power and Thermal features =====\n");
    printf("For each feature, a value of 1 means it is available, 0 means it is not\n\n");

    for (EAX_Thermal_Power_ft i = DTS; i <= 31; i++){
        int bit = (eax >> i) & 1;
        printf("Bit %2d (%-58s): %d \n", i, eax_feature_names[i], bit);
    }

    return(0);
}