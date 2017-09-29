#include <stdio.h>

void endian_test(void)
{
    unsigned short test = 0x1234;
    if (*((unsigned char *)&test) == 0x12) {
        printf("1: Big Endian, *((unsigned char*)&test) == 0x12\n");
    } else if (*((unsigned char *)&test) == 0x34) {
        printf("2: Little Endian, *((unsigned char*)&test) == 0x34\n");
    }

    union {
        unsigned char c[4];
        unsigned int tmp;
    } endian_test;

    endian_test.c[0] = 0x12;
    endian_test.c[1] = 0x34;
    endian_test.c[2] = 0x56;
    endian_test.c[3] = 0x78;
    printf("endian_test.tmp = 0x%08X\n", endian_test.tmp);
    printf("(char)endian_test.tmp = 0x%02X\n", (char)endian_test.tmp);
    printf("(short)endian_test.tmp = 0x%04X\n", (short)endian_test.tmp);
    if (endian_test.tmp == 0x12345678) {
        printf("3: Big Endian\n");
    } else if (endian_test.tmp == 0x78563412) {
        printf("4: Little Endian\n");
    }
}

void func_ret(int *ret)
{
    *ret = 10;
}
void func_test(void)
{
    int x = 0;
    unsigned short y = 0;

    func_ret((int *)&x);
    printf("x = %d\n", x);
    func_ret((int *)&y);
    printf("y = %d\n", y);
}

int main()
{
    endian_test();
    func_test();

    return 0;
}
