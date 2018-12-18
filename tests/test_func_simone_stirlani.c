#include <aiv_unit_test.h>
#include <aiv_gb.h>


TEST(X20_tests){
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_load_cartridge(&gb,"tests/roms/simone_stirlani.gb");
    gb.cartridge[0x0a30] = 10;

    u8_t ret = 0;


    while(ret >= 0){
        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.hl == 0x0a08);
    printf("%i", gb.hl);
    ASSERT_THAT(gb.a == 0x05);
    printf("\n  %i  \n", gb.a);

}

void aiv_simone_stirlani_test(){
    RUN_TEST(X20_tests);
}