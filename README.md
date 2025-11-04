# CPUID

This is a tool to use the `CPUID` instruction. 

I am using the `gcc` version : `__get_cpuid()` rather than using the assembly version. 

## `cpuid` instruction

The CPUID instruction can be used to retrieve various information about your CPU, such as its vendor string and model number, the size of internal caches and (more interesting), the list of CPU features supported. We will use it to discuss the features and capacity of CPUs for PC states.

You can check if your CPU support `MWAIT` instructions by checking the field `MONITOR` (bit 3) on ECX. Run this run `cpuid -f` and check the results. For example :

```
→ ./bin/cpuid -f

For each feature, a value of 1 means it is available, 0 means it is not
ECX Features:
Bit  0 (SSE3        ): 1
Bit  1 (PCLMULQDQ   ): 1
Bit  2 (DTES64      ): 1
Bit  3 (MONITOR     ): 1
```

We can see a `1` for `MONITOR` which means that this CPU supports `MWAIT` hints.

## Usage 

```
Usage: cpuid [options]
Options
  -h : Show this help message
  -p : Display power and thermal capacities
  -v : Display CPU vendor information
  -f : Display CPU features
```

## Build

To build the binaries, simply run :

    make

And look to `bin/cpuid` for the compiled binaries. 

> You need `gcc` to compile this tool

## Ressources 

- Main source : [this amazing site](https://www.felixcloutier.com/x86/cpuid) about the `x86`/`ARM64` arch
- Details about features : [wikipedia](https://en.wikipedia.org/wiki/CPUID#EAX=1:_Processor_Info_and_Feature_Bits)