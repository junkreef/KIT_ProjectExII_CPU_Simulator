//
// Created by Junpei Kishi on 2018/05/25.
//

#include "OR.h"

/**
* @brief Operation OR
*
* OR Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_or(Cpub *cpub){
    Uword *target, *operand;

    target = extract_A(cpub);
    operand = extract_B(cpub);

    *target |= *operand;

    cpub->vf = 0;
    if((int8_t)*target < 0){
        cpub->nf = 1;
    }else{
        cpub->nf = 0;
    }
    if((int8_t)*target == 0){
        cpub->zf = 1;
    }else{
        cpub->zf = 0;
    }

    cpub->pc++;
    return RUN_STEP;
}
