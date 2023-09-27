all: linalg.exe

linalg.exe: main.c Core.c Wrapper.c Genesis.c determinant.c lin_alg_mac.h
    cl main.c Core.c Wrapper.c Genesis.c determinant.c /link /out:linalg.exe