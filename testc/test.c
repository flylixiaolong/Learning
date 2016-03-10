#include <stdio.h>
/*****************************
**     ToggleBitRun          *
******************************
** Set or clear a run of nbits starting at
** bit_addr in bitmap.
*/
static void ToggleBitRun(farulong *bitmap, /* Bitmap */
                ulong bit_addr,         /* Address of bits to set */
                ulong nbits,            /* # of bits to set/clr */
                uint val)               /* 1 or 0 */
{
	unsigned long bindex;   /* Index into array */
	unsigned long bitnumb;  /* Bit number */

	while(nbits--)
	{
		bindex=bit_addr>>6;     /* Index is number /64 */
		bitnumb=bit_addr % 64;   /* Bit number in word */

		if(val)
			bitmap[bindex]|=(1L<<bitnumb);
		else
			bitmap[bindex]&=~(1L<<bitnumb);
		bit_addr++;
	}
	return;
}
