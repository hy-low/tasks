#include <stdio.h>
#include "cpu.h"

void show_status(CPU *cpu) {
    int a, x, y, pc, sp, flags;

    cpu_status(cpu, &a, &x, &y, &pc, &sp, &flags);
    printf("\n");
    printf("Register A: %02X\n", a);
    printf("Register X: %02X\n", x);
    printf("Register Y: %02X\n", y);
    printf("Program counter: %04X\n", pc);
    printf("Stack pointer: %02X\n", sp);
    printf("Flag register: %02X\n", flags);
}

void local_tests(void) {
    // You can use this file for testing functions locally

    CPU *cpu = cpu_init("nestest.nes");
    show_status(cpu);

    cpu_step(cpu);
    show_status(cpu);

    cpu_free(cpu);
}
