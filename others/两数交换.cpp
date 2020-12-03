#include<stdio.h>

// v1
int main() {
    int a=10,b=20;
    int c;
    c=a;
    a=b;
    b=c;
    printf("a=%d,b=%d\n",a,b);
    return 0;
}

// v2
int main() {
    int a=10,b=20;
    a=a+b;
    b=a-b;
    a=a-b;
    printf("a=%d,b=%d\n",a,b);
    return 0;
}


// v3
int main() {
    int a=10,b=20;
    a=a^b;
    b=a^b;
    a=a^b;
    printf("a=%d,b=%d\n",a,b);
    return 0;
}