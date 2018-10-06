int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n) 
{ 
    /* xor contains xor of two sets */
    unsigned int xr = ((x >> p1) ^ (x >> p2)) & ((1U << n) - 1); 
  
    /* To swap two sets, we need to again XOR the xor with original sets */
    return x ^ ((xr << p1) | (xr << p2)); 
} 