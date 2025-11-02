#include <stdio.h>
#include <cpuid.h>
#include "cpuid.h"


// use the instruction cpuid() to get the vender
int cpu_vendor(){
    unsigned int eax, ebx, ecx, edx;
    char vendor[13];

    __get_cpuid(0, &eax, &ebx, &ecx, &edx);

    // As values are binaries, we need to convert them to string
    *(unsigned int*)&vendor[0] = ebx;
    *(unsigned int*)&vendor[4] = edx;
    *(unsigned int*)&vendor[8] = ecx;
    vendor[12] = '\0';

    printf("CPU Vendor: %s\n", vendor);

    return 0;
}