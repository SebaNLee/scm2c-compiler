#include <stdio.h>

int main()
{
    // arbitrary max register number
    int r[1024] = {0};

L0:
    printf("%d\n", r[1]);
    
L1:
    r[1]++;
    
L2:
    if (r[1] == r[1]) goto L0;
    
    return 0;
}
