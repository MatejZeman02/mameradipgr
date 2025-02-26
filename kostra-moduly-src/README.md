# SKELETON for pgr

This is a simple skeleton af an OpenGL application using freeGLUT and pgr libraries.
Use it as a starting point for your homework.

TASKS:
 -> change from x64 to x86 (32 bits)
 -> rename `skeleton` to `your-name`.

## FAQ/Problems

1. Why `location` of my variable is `-1`?
  - The uniform variable is not used in the shader code, and the compiler has optimized it out. Ensure that the variable is actually used in your shader code.


