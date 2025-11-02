#include <stdio.h>
#include <getopt.h>
#include "vendor/vendor.h"
#include "features/features.h"

void print_help() {
    printf("Usage: cpuid [options]\n");
    printf("Options:\n");
    printf("  -h : Show this help message\n");
    printf("  -v : Display CPU vendor information\n");
    printf("  -f : Display CPU features\n");
}

int main(int argc, char *argv[]) {
    int opt;

    if (argc < 2){
        print_help();
        return 1;
    }

    while ((opt = getopt(argc, argv, "hvf")) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                return 0;
            case 'v':
                cpu_vendor();
                break;
            case 'f':
                cpu_features();
                break;
            default:
                print_help();
                return 1;
        }
    }
}