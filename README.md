# CPUID

This is a tool to use the `CPUID` instruction. 

I am using the `gcc` version : `__get_cpuid()` rather than using the assembly version. 

## `cpuid` instruction

The CPUID instruction can be used to retrieve various information about your CPU, such as its vendor string and model number, the size of internal caches and (more interesting), the list of CPU features supported. We will use it to discuss the features and capacity of CPUs for PC states. 

## Ressources 

- Main source : [this amazing site](https://www.felixcloutier.com/x86/cpuid) about the `x86`/`ARM64` arch
- Details about features : [wikipedia](https://en.wikipedia.org/wiki/CPUID#EAX=1:_Processor_Info_and_Feature_Bits)