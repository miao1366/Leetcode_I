


// v1 
int rangeBitwiseAnd(int m, int n){
    int ret = m;
    for(int i = m; i <= n; i++) {
        ret = ret & i;
        if (0 == ret ) {
            break;
        }
    }
    return ret;
}

// v2
int rangeBitwiseAnd(int m, int n){
    int shift = 0;
    while (m < n)
    {
        m >>= 1;
        n >>= 1;
        shift++;
    }
    return m << shift;
}



