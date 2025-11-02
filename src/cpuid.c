#include "vendor/vendor.h"
#include "features/features.h"
#include <stdio.h>

int main(){
    printf("############ cpuid ############\n");

    // vendor infos
    printf("===== Vendor =====\n");
    cpu_vendor();

    printf("\n");

    // features :
    printf("===== Features =====\n");
    cpu_features();

    return 0;
}