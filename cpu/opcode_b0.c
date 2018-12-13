#include <aiv_gb.h>

//A | B
static int aiv_gb_opcode_b0(aiv_gameboy *gb)
{
    if (gb->a |= gb->b == 1)
    {
        SET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    else
    {
        UNSET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    return 4;
}
//A | C
static int aiv_gb_opcode_b1(aiv_gameboy *gb)
{
    if (gb->a |= gb->c == 1)
    {
        SET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    else
    {
        UNSET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    return 4;
}
//A | D
static int aiv_gb_opcode_b2(aiv_gameboy *gb)
{
    if (gb->a |= gb->d == 1)
    {
        SET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    else
    {
        UNSET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    return 4;
}
//A | E
static int aiv_gb_opcode_b3(aiv_gameboy *gb)
{
    if (gb->a |= gb->e == 1)
    {
        SET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    else
    {
        UNSET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    return 4;
}
//A | H
static int aiv_gb_opcode_b4(aiv_gameboy *gb)
{
    if (gb->a |= gb->h == 1)
    {
        SET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    else
    {
        UNSET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    return 4;
}
//A | L
static int aiv_gb_opcode_b5(aiv_gameboy *gb)
{
    if (gb->a |= gb->l == 1)
    {
        SET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    else
    {
        UNSET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    return 4;
}
//A | (HL)
static int aiv_gb_opcode_b6(aiv_gameboy *gb)
{
    if (gb->a |= gb->hl == 1)
    {
        SET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    else
    {
        UNSET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    return 8;
}
//A | A
static int aiv_gb_opcode_b7(aiv_gameboy *gb)
{
    if (gb->a |= gb->a == 1)
    {
        SET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    else
    {
        UNSET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
    return 4;
}

//CP B
static int aiv_gb_opcode_b8(aiv_gameboy *gb)
{

    if (gb->a == gb->b)
    {
        SET_Z(gb);
        SET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
        if (check_set_h(gb) == 1)
        {
            SET_H(gb);
        }
        if (gb->a < gb->b)
        {
            SET_C(gb);
        }
    }
    else
    {
        UNSET_Z(gb);
        UNSET_N(gb);
        UNSET_H(gb);
        UNSET_C(gb);
    }
}

static int check_set_h(aiv_gameboy *gb)
{
    u8_t value = gb->a & 0x0f;
    value += 1;

    if (value > 0x08)
        return 1;

    return 0;
}