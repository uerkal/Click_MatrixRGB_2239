#include <stdint.h>
#include "matrixrgb_hw.h"

sbit MATRIXRGB_CS            at PORTA5_bit;
sbit MATRIXRGB_CS_DIR        at DDA5_bit;
sbit MATRIXRGB_READY         at PORTD2_bit;
sbit MATRIXRGB_READY_DIR     at DDD2_bit;
sbit MATRIXRGB_RST           at PORTA6_bit;
sbit MATRIXRGB_RST_DIR       at DDA6_bit;

void system_setup( char brightness, uint8_t width, uint8_t height );

void main()
{
    uint8_t count = 3;
    uint8_t i     = 0;
    color_t my_color;

    system_setup( 100, 2, 1 );

    //matrixrgb_scroll_img_right( MikroeBITMAP_bmp, 64, 16, 40 );
    //matrixrgb_scroll_off_scrn_down( 30 );
    matrixrgb_set_color( &my_color, 1, 1, 1 );
    matrixrgb_scroll_text_left( "Matrix ", my_color, 17, 10 );
  /*  matrixrgb_set_color( &my_color, 1, 0, 0 );
    matrixrgb_scroll_text_left( "R", my_color, 17, 1 );
    matrixrgb_set_color( &my_color, 0, 1, 0 );
    matrixrgb_scroll_text_left( "G", my_color, 17, 1 );
    matrixrgb_set_color( &my_color, 0, 0, 1 );
    matrixrgb_scroll_text_left( "B ", my_color, 17, 1 );
    matrixrgb_set_color( &my_color, 1, 1, 1 );
    matrixrgb_scroll_off_scrn_up( 30 );
    matrixrgb_set_color( &my_color, 1, 0, 0 );
    matrixrgb_scroll_text_left( "By: ", my_color, 17, 4 );
    matrixrgb_set_color( &my_color, 1, 1, 1 );
    matrixrgb_scroll_text_left( "Corey ", my_color, 17, 6 );
    matrixrgb_set_color( &my_color, 0, 0, 1 );
    matrixrgb_scroll_text_left( "Lakey ", my_color, 17, 6 );
    matrixrgb_scroll_off_scrn_left( 17 );            */
   // matrixrgb_scroll_img_right( MikroeBITMAP_bmp, 64, 16, 25 );
   // matrixrgb_scroll_off_scrn_right( 10 );

    while(1)
    {
            matrixrgb_set_color( &my_color, 1, 1, 1 );
        matrixrgb_scroll_text_left( "Matrix", my_color, 20, 10 );
     /*       matrixrgb_set_color( &my_color, 1, 0, 0 );
        matrixrgb_scroll_text_left( "R", my_color, 20, 1 );
            matrixrgb_set_color( &my_color, 0, 1, 0 );
        matrixrgb_scroll_text_left( "G", my_color, 20, 1 );
            matrixrgb_set_color( &my_color, 0, 0, 1 );
        matrixrgb_scroll_text_left( "B", my_color, 20, 1 );      */
    }
}

void system_setup( char brightness, uint8_t width, uint8_t height )
{
    MATRIXRGB_CS_DIR    = 1;
    MATRIXRGB_RST_DIR   = 1;
    MATRIXRGB_READY_DIR = 0;

    SPI1_Init_Advanced( _SPI_MASTER, _SPI_FCY_DIV32, _SPI_CLK_LO_LEADING );

    MATRIXRGB_RST = 0;        //Reset slave ( toggle )
        Delay_ms(200);
    MATRIXRGB_RST = 1;
    Delay_ms(300);

    matrixrgb_init( brightness, width, height );
    Delay_ms(200);

}