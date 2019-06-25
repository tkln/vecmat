#include <stdio.h>

#include "vec2f.h"
#include "link-test-c.h"

int main()
{
    vm::vec2f a = vm::vec2f_ones;
    vm::vec2f b = vm::vec2f_ones;
    vm::vec2f c = do_stuff(a, b);

    printf("%f, %f\n", c.x, c.y);
}
