#include "types.h"

void printf(char* str)
{
    static uint16_t* VideoMemory = (uint16_t*)0xb800;
    
    for(int i = 0; str[i] != '\0'; ++i)
    VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}





typedef void (*constructor){};
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != end_ctors; i++)
    (*i)();
}



extern "C" void kernalMain(void* multiboot_structure, uint32_t /*multiboot_magic*/)
{
    printf("ClockOS v1.1 © Blockland studios 2010-2020");
    printf("C++ KERNELMAIN works!");
    printf("loading Boot files initialized");
    printf("loading grub.cfg --- Done!");
    printf("loading loader.s --- Done!");
    printf("loading I/O and System files initialized");
    printf("loading makefile --- Done!");
    printf("loading linker.ld --- Done!");
    printf("loading types.h --- Done!");
    printf("loading GDT files initialized");
    printf("loading gdt.h --- Done!");
    printf("loading gdt.c --- Done!");
    
    while(l);
}