#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_PORTS 8U

typedef unsigned short int uint16_t;
typedef enum STATUS_E {PASS, ERROR} STATUS_T;

typedef struct PORTS_S
{
    bool port1 : 1;             //LSB (Smallest Address) - Little Endian 
    bool port2 : 1;
    bool port3 : 1;
    bool port4 : 1;
    bool port5 : 1;
    bool port6 : 1;
    bool port7 : 1;
    bool port8 : 1;
    unsigned char reserved : 8; // MSB (Bigger Address) 
}PORTS_T;

static void initialize_ports(PORTS_T ** uports);
static STATUS_T read_port(uint16_t port, PORTS_T *pports, uint16_t *port_active);

int main()
{
    STATUS_T success = ERROR;
    PORTS_T ports;
    PORTS_T *pports = &ports;
    uint16_t port_status = 0U;
    uint16_t port_number = 0U;
    
    initialize_ports(&pports);

    for (port_number = 1; port_number <= NUM_PORTS; port_number++)
    {
        success = read_port(port_number, pports, &port_status);
        if (success == PASS)
        {
            printf("port %i status : %d \n", port_number, port_status);
        }
        else
        {
            printf("There was an error");
        }
    }
}

static void initialize_ports(PORTS_T ** uports)
{
    (*uports)->reserved = 1U;
    (*uports)->port1 = true;
    (*uports)->port2 = true;
    (*uports)->port3 = true;
    (*uports)->port4 = false;
    (*uports)->port5 = true;
    (*uports)->port6 = false;
    (*uports)->port7 = true;
    (*uports)->port8 = false;
}

static STATUS_T read_port(uint16_t port, PORTS_T *pports, uint16_t *port_active)
{
    STATUS_T result = PASS;
    int temp_ports = 0U;

    memcpy(&temp_ports, pports, sizeof(temp_ports));
    printf("%X\n", temp_ports);

    *port_active = (temp_ports & ((uint16_t)1U << (port - 1U)));
    *port_active = *port_active >> (port - 1U);

    return result;
}