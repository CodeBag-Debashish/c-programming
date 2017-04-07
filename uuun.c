#include <stdio.h>
int main()
{
    int x = 1;
    x = x++;
    printf("%d\n",x);
 
    return 0;

}
// http://stackoverflow.com/questions/1270370/printfd-d-d-n-a-a-a-output
// http://stackoverflow.com/questions/949433/why-are-these-constructs-using-undefined-behavior
// http://stackoverflow.com/questions/10845122/is-the-output-of-printf-d-d-c-c-also-undefined
// http://stackoverflow.com/questions/21220522/printfd-d-n-i-i-output
// 