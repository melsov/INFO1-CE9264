#ifndef TERMH
#define TERMH

/* Must be called before and after the other term_ functions. */
void term_construct(void);
void term_destruct(void);

/* Legal x values go from 0 to term_xmax() - 1 inclusive.
 Legal y values go from 0 to term_ymax() - 1 inclusive. */

unsigned term_xmax(void);   /* number of columns of characters */
unsigned term_ymax(void);   /* number of rows of characters */

/* Display a character or string on the screen. */
void term_put (unsigned x, unsigned y, char c);
void term_puts(unsigned x, unsigned y, const char *s);

/* Return the character at the given position on the screen. */
char term_get(unsigned x, unsigned y);

/* Return immediately with the key the user pressed.  If no key was pressed,
 return immediately with '\0'. */
char term_key(void);

void term_wait(int milliseconds);    /* 1000 milliseconds == 1 second */
void term_beep(void);
#endif