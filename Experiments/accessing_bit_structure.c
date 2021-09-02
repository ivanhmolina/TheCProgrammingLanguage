#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_PORTS 8U

typedef unsigned short int uint16_t;
typedef enum STATUS_E {PASS, FAIL} STATUS_T;

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
static void print_ports(PORTS_T *pports); 
static STATUS_T read_port(uint16_t port, PORTS_T *pports, uint16_t *port_active);
static STATUS_T set_port(uint16_t port, PORTS_T *pports, bool status);


int main()
{
    STATUS_T success = FAIL;
    PORTS_T ports;
    PORTS_T *pports = &ports;
    
    initialize_ports(&pports);
    print_ports(pports);
    set_port(1, pports, true);
    set_port(6, pports, true);
    print_ports(pports);
    set_port(1, pports, false);
    print_ports(pports);
}

static void initialize_ports(PORTS_T ** uports)
{
    STATUS_T result = PASS;

    (*uports)->reserved = 1U;
    
    for (uint16_t port = 1; port <= NUM_PORTS; port++)
    {
        result += set_port(port, (*uports), false);    
    }
    if(result != PASS)
    {
        printf("Something went wrong in initialization...\n");
    }
}

static STATUS_T set_port(uint16_t port, PORTS_T *pports, bool status)
{
    STATUS_T result = PASS;
    uint16_t temp_ports = 0U;

    if ((port > 0U) && (port <= NUM_PORTS))
    {
        memcpy(&temp_ports, pports, sizeof(temp_ports));
        if(true == status)
        {
            temp_ports = temp_ports | ((uint16_t)1U << (port - 1U));
        }
        else
        {
            temp_ports = temp_ports & (~((uint16_t)1U << (port - 1U)));
        }
        memcpy(pports, &temp_ports, sizeof(temp_ports));
    }
    else
    {
        result = FAIL;
    }

    return result;
}

static STATUS_T read_port(uint16_t port, PORTS_T *pports, uint16_t *port_active)
{
    STATUS_T result = PASS;
    uint16_t temp_ports = 0U;

    if((port > 0U) && (port <= NUM_PORTS))
    {
        memcpy(&temp_ports, pports, sizeof(temp_ports));
        *port_active = (temp_ports & ((uint16_t)1U << (port - 1U))) >> (port - 1U);
    }
    else
    {
        result = FAIL;
    }

    return result;
}

static void print_ports(PORTS_T *pports)
{
    uint16_t port_status = 0U;
    uint16_t port_number = 0U;
    STATUS_T success = FAIL;

    printf("PORT LINKS STATUS\n");

    for (port_number = 1; port_number <= NUM_PORTS; port_number++)
    {
        success = read_port(port_number, pports, &port_status);
        if (success == PASS)
        {
            printf("port %i status : %d \n", port_number, port_status);
        }
        else
        {
            printf("There was an error\n");
        }
    }
}