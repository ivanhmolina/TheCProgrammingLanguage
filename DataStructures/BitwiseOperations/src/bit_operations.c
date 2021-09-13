#include <stdio.h>
#include "bit_operations.h"

bool_t read_bit(uint8_t pos, uint32_t *input)
{
    return (bool_t)((*input & ((uint32_t)1u) << (pos - 1u)) >> (pos - 1u));
}

void set_bit(uint8_t pos, bool_t value, uint32_t *input)
{
    uint32_t result = *input;
    uint32_t mask = ((uint32_t)1u) << (pos - 1u);

    if(value)
    {
        //Set to 1
        result |= mask;
    }
    else
    {
        //Set to 0
        result &= ~mask;
    }
    *input = result;
}

static void print_bits(uint32_t *input, char *name)
{
    uint8_t i;

    printf("%s : \n", name);

    for (i = MAX_BITS; i > 0; i--)
        printf("%2d ", i);

    printf("\n");

    for (i = MAX_BITS; i > 0; i--)
        printf("%2d ", read_bit(i, input));

    printf("\n");
}

int main()
{
    uint32_t a = 0xF0F0F0F0;
    uint32_t b = 0x0F0F0F0F;
    
    print_bits(&a, "A");
    print_bits(&b, "B");

    set_bit(3, TRUE, &a);
    set_bit(3, TRUE, &b);
    set_bit(6, FALSE, &a);
    set_bit(6, FALSE, &b);

    print_bits(&a, "A");
    print_bits(&b, "B");
}