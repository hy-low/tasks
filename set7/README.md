# Set 7

In this exercise, your task is to create an emulator for the 6502 machine language used in the NES (Nintendo Entertainment System). A good resource for information is the [NESdev Wiki](https://www.nesdev.org/wiki/CPU), whose [CPU section](https://www.nesdev.org/wiki/CPU) describes the instructions, addressing modes and registers of the processor.

Your emulator should be able to process 6502 machine language instructions. Note that the emulator does not have to include other parts of NES, such as graphics, controls and sound. However, if you want to extend the emulator later, that can be an interesting hobby project.

Your emulator will be tested using `nestest`, which can be found through the [emulator tests](https://www.nesdev.org/wiki/Emulator_tests) on the NESdev Wiki. There are two files: `nestest.nes` contains the test code for the emulator, and `nestest.log` contains a log that shows the processor status before each instruction. You should add these two files to your `set7` directory.

The file `nestest.nes` also tests unofficial instructions. However, in this exercise, it is enough that your emulator supports the [official instructions](https://www.nesdev.org/wiki/Instruction_reference).

## Files

- `cpu.h` contains the public function declarations
- `cpu.c` contains the implementation

## Required functions

### `CPU* cpu_init(char *filename)`

Initializes the CPU, reserves memory, and loads the code from the given file.

- The total size of the memory is 64k bytes.
- The emulator should load the contents of the file, starting at offset 16, into memory starting at offset `0xc000`.
- Initial values for the register are:
  - Registers A, X, Y: `0x00`
  - Program counter: `0xc000`
  - Stack pointer: `0xfd`
  - Flag register: `0x24`

### `void cpu_step(CPU *cpu)`

Processes the next instruction in the code.

### `void cpu_status(CPU *cpu, int *a, int *x, int *y, int *pc, int *sp, int *flags)`

Returns the current values of the registers through the pointers.

### `void cpu_free(CPU *cpu)`

Frees the memory reserved for the CPU.

## Example code

The file `local.c` contains the following test code:

```c
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
    CPU *cpu = cpu_init("nestest.nes");
    show_status(cpu);

    cpu_step(cpu);
    show_status(cpu);

    cpu_free(cpu);
}
```

This code shows the initial status of the processor and then performs the first instruction.

Expected output:

```
Register A: 00
Register X: 00
Register Y: 00
Program counter: C000
Stack pointer: FD
Flag register: 24

Register A: 00
Register X: 00
Register Y: 00
Program counter: C5F5
Stack pointer: FD
Flag register: 24
```
