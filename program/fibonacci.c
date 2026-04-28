#include <stdio.h>

int main()
{
    // arbitrary max register number
    int r[1024] = {0};

L0:
    r[0] = 0;
    
L1:
    r[1]++;
    
L2:
    printf("%d\n", r[0]);
    
L3:
    r[4] = 0;
    
L4:
    r[3] = 0;
    
L5:
    if (r[3] == r[0]) goto L9;
    
L6:
    r[4]++;
    
L7:
    r[3]++;
    
L8:
    if (r[0] == r[0]) goto L5;
    
L9:
    r[0] = 0;
    
L10:
    r[3] = 0;
    
L11:
    if (r[3] == r[1]) goto L15;
    
L12:
    r[0]++;
    
L13:
    r[3]++;
    
L14:
    if (r[0] == r[0]) goto L11;
    
L15:
    r[2] = 0;
    
L16:
    r[3] = 0;
    
L17:
    if (r[3] == r[0]) goto L21;
    
L18:
    r[2]++;
    
L19:
    r[3]++;
    
L20:
    if (r[0] == r[0]) goto L17;
    
L21:
    r[3] = 0;
    
L22:
    if (r[3] == r[4]) goto L26;
    
L23:
    r[2]++;
    
L24:
    r[3]++;
    
L25:
    if (r[0] == r[0]) goto L22;
    
L26:
    r[1] = 0;
    
L27:
    r[3] = 0;
    
L28:
    if (r[3] == r[2]) goto L32;
    
L29:
    r[1]++;
    
L30:
    r[3]++;
    
L31:
    if (r[0] == r[0]) goto L28;
    
L32:
    printf("%d\n", r[0]);
    
L33:
    if (r[0] == r[0]) goto L3;
    
    return 0;
}
