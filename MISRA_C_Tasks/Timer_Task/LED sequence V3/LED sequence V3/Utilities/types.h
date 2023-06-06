/*
 * types.h
 *
 * Created: 4/4/2023 1:14:23 PM
 *  Author: Mahmoud
 */ 


#ifndef TYPES_H_
#define TYPES_H_


typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef char int8_t;
typedef unsigned int uint32_t;
typedef int int32_t;



#define SET_BIT( REG, BIT_NUM)  ( REG |=  ( 1 << BIT_NUM ) )

#define CLEARE_BIT( REG, BIT_NUM)  ( REG &= ~( 1 << BIT_NUM )  )

#define TOGGLE_BIT( REG, BIT_NUM)  ( REG = REG ^ ( 1 << BIT_NUM ) )

#define ROTATE_RIGHT( REG, BIT_NUM)  ( REG =  ( REG >> BIT_NUM ) |  ( REG << ( 8 - BIT_NUM )  )  )

#define ROTATE_LEFT( REG, BIT_NUM)  ( REG =  ( REG << BIT_NUM ) |  ( REG >> ( 8 - BIT_NUM )  )  )

#define IS_SET( REG, BIT_NUM)  ( REG & ( 1 << BIT_NUM ) )

#define IS_CLEARE( REG, BIT_NUM)  ( ! ( REG & ( 1 << BIT_NUM ) ) )

#define READ_BIT( REG, BIT_NUM)   ( REG & ( 1 << BIT_NUM ) ) 

#endif /* TYPES_H_ */