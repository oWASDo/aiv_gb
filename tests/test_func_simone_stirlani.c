#include <aiv_unit_test.h>
#include <aiv_gb.h>



TEST(X20_tests)
{
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
TEST(X20_tests_1)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    ASSERT_THAT(aiv_gb_load_cartridge(&gb,"tests/roms/simone_stirlani1.gb") == 0);
    gb.a = 3;
    gb.hl = 0x0001;
    
    gb.pc = 0x0100;
    u8_t ret = 0;

    while (ret != 252)
    {
        ret = aiv_gb_tick(&gb);
        printf("%02x   ", gb.cartridge[gb.pc]);

    }
    printf("result: %d", aiv_gb_memory_read8(&gb,0x0001));

}
TEST(X20_tests_2)
{
    
}

void aiv_simone_stirlani_test()
{
    RUN_TEST(X20_tests);
    RUN_TEST(X20_tests_1);
    RUN_TEST(X20_tests_2);
}