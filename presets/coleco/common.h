
#ifndef _CV_COMMON_H
#define _CV_COMMON_H

/* VRAM map
   0x0000 - 0x17ff character pattern table
   0x1800 - 0x1aff image table
   0x2000 - 0x37ff color table
   0x3800 - 0x3bff sprite pattern table
   0x3c00 - 0x3fff sprite attribute table
*/

#define PATTERN		((const cv_vmemp)0x0000)
#define IMAGE		((const cv_vmemp)0x1800)
#define COLOR		((const cv_vmemp)0x2000)
#define SPRITE_PATTERNS ((const cv_vmemp)0x3800)
#define SPRITES		((const cv_vmemp)0x3c00)

#define COLS 32
#define ROWS 24

typedef unsigned char byte;
typedef signed char sbyte;
typedef unsigned short word;

uintptr_t __at(0x6a) font_bitmap_a;
uintptr_t __at(0x6c) font_bitmap_0;

#define LOCHAR 0x20
#define HICHAR 0xff

#define CHAR(ch) (ch-LOCHAR)

extern volatile bool vint;
extern volatile uint_fast8_t vint_counter;

extern void vint_handler(void);
extern byte reverse_bits(byte n);
extern void flip_sprite_patterns(word dest, const byte* patterns, word len);

extern char cursor_x;
extern char cursor_y;

extern void clrscr();

extern byte getchar(byte x, byte y);
extern void putchar(byte x, byte y, byte attr);
extern void putstring(byte x, byte y, const char* string);
extern void wait_vsync();
extern void delay(byte i);
extern byte rndint(byte a, byte b);

extern void memset_safe(void* _dest, char ch, word size);
extern char in_rect(byte x, byte y, byte x0, byte y0, byte w, byte h);
// print 4-digit BCD value
extern void draw_bcd_word(byte x, byte y, word bcd);
// add two 16-bit BCD values
extern word bcd_add(word a, word b);

#endif