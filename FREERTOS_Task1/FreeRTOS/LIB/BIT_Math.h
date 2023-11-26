#ifndef BIT_MATH_H_INCLUDED
#define BIT_MATH_H_INCLUDED

#define    SET_BIT(var , bit)    (var |= (1<<bit))
#define    CLR_BIT(var , bit)    (var &=~(1<<bit))
#define    TOOGLE_BIT(var , bit) (var ^= (1<<bit))
#define    GET_BIT(var , bit)    ((var>>bit) & (0x01))

#endif // BIT_MATH_H_INCLUDED
