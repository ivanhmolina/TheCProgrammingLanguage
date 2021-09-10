#ifndef _BIT_OPERATIONS_
#define _BIT_OPERATIONS_

#include "ptypes.h"

#define MAX_BITS (32u)

bool_t read_bit(uint8_t pos, uint32_t *input);
void set_bit(uint8_t pos, bool_t value, uint32_t *input);

#endif