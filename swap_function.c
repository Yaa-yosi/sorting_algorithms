/**
 * swap_int - Swaps two integers in an array
 *
 * @a: integer
 * @b: integer
 */
void swap_int(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}
