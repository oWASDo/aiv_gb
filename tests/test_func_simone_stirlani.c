#include <aiv_unit_test.h>
#include <aiv_gb.h>

#define SIGN printf("Stirlani:            test\n");
#define PRINTT printf("%02x ", aiv_gb_memory_read8(&gb, gb.pc));

//test: ld hl, $0016
//      halt
TEST(X20_tests_0)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlani0.gb") == 0);

    gb.pc = 0x0ff;
    u8_t ret = 0;

    while (ret != 252)
    {
        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.hl == 0x0016);
}

//test: ld [hl+], a
//      halt
TEST(X20_tests_1)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlani1.gb") == 0);
    gb.a = 3;
    gb.hl = 0x0001;

    gb.pc = 0x00ff;
    u8_t ret = 0;
    while (ret != 252)
    {

        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(aiv_gb_memory_read8(&gb, 0x0001) == 3);
    ASSERT_THAT(gb.hl == 0x0002);
}

//test: INC HL
//      halt
TEST(X20_tests_2)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlani2.gb") == 0);

    gb.hl = 0x0001;

    gb.pc = 0x00ff;
    u8_t ret = 0;
    while (ret != 252)
    {

        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.hl == 0x0002);
}

//test: INC H
//      halt
TEST(X20_tests_3)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlani3.gb") == 0);

    gb.hl = 0x0001;

    gb.pc = 0x00ff;
    u8_t ret = 0;
    while (ret != 252)
    {

        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.hl == 0x0101);
}

//test: DEC H
//      halt
TEST(X20_tests_4)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlani4.gb") == 0);
    gb.a = 3;
    gb.hl = 0x0001;

    gb.pc = 0x00ff;
    u8_t ret = 0;
    while (ret != 252)
    {

        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.hl == 0xff01);
}

//test: ld h, $05
//      halt
TEST(X20_tests_5)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlani5.gb") == 0);
    gb.a = 3;
    gb.hl = 0x0001;

    gb.pc = 0x00ff;
    u8_t ret = 0;
    while (ret != 252)
    {
        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.h == 0x05);
}

//test: DAA
//      halt
TEST(X20_tests_6)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlani6.gb") == 0);
    gb.a = 0;
    aiv_gb_set_flag(&gb, CARRY, 0);
    aiv_gb_set_flag(&gb, HALF, 0);
    aiv_gb_set_flag(&gb, ZERO, 0);
    aiv_gb_set_flag(&gb, NEG, 0);
    gb.pc = 0x00ff;
    u8_t ret = 0;
    while (ret != 252)
    {
        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.a == 0x0);
}

//test: ADD HL, HL
//      halt
TEST(X20_tests_7)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlani7.gb") == 0);

    gb.hl = 0X22;
    gb.pc = 0x00ff;
    u8_t ret = 0;

    while (ret != 252)
    {
        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.hl == 0x44);
}

//test: LD A,[HL+]
//      halt
TEST(X20_tests_8)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlani8.gb") == 0);
    gb.hl = 0X0000;
    aiv_gb_memory_write8(&gb, gb.hl, 2);

    gb.pc = 0x00ff;
    u8_t ret = 0;
    while (ret != 252)
    {
        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.hl == 0x0001);
}

//test: DEC HL
//      INC L
//      DEC L
//      halt
TEST(X20_tests_9)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlani9.gb") == 0);
    gb.hl = 0X0050;

    gb.pc = 0x00ff;
    u8_t ret = 0;

    while (ret != 252)
    {
        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.hl == 0x004f);
}

//test: LD L, $08
//      halt
TEST(X20_tests_a)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlania.gb") == 0);
    gb.hl = 0X0050;

    gb.pc = 0x00ff;
    u8_t ret = 0;

    while (ret != 252)
    {
        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.l == 0x08);
}

TEST(X20_tests_b)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlanib.gb") == 0);
    aiv_gb_set_flag(&gb, ZERO, 1);
    gb.a = 0x22;
    gb.pc = 0x00ff;
    u8_t ret = 0;

    while (ret != 252)
    {
        ret = aiv_gb_tick(&gb);
    }
    printf("%02x", gb.h);
    ASSERT_THAT(gb.hl == 0x0101);
    ASSERT_THAT(gb.a == 0xDD);
}
TEST(X20_tests_b_bis)
{
    SIGN;
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/simone_stirlanib.gb") == 0);
    aiv_gb_set_flag(&gb, ZERO, 0);
    gb.a = 0x22;
    gb.pc = 0x00ff;
    u8_t ret = 0;

    while (ret != 252)
    {
        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.hl == 0x0001);
    ASSERT_THAT(gb.a == 0xDD);
}
void aiv_simone_stirlani_test()
{
    RUN_TEST(X20_tests_0);
    RUN_TEST(X20_tests_1);
    RUN_TEST(X20_tests_2);
    RUN_TEST(X20_tests_3);
    RUN_TEST(X20_tests_4);
    RUN_TEST(X20_tests_5);
    RUN_TEST(X20_tests_6);
    RUN_TEST(X20_tests_7);
    RUN_TEST(X20_tests_8);
    RUN_TEST(X20_tests_9);
    RUN_TEST(X20_tests_a);
    RUN_TEST(X20_tests_b);
    RUN_TEST(X20_tests_b_bis);
}