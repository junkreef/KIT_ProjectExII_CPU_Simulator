//
// Created by Junpei Kishi on 2018/05/25.
//

#include "AND.h"

/**
* @brief Operation AND
*
* AND Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_and(Cpub *cpub){
    Uword *target, *operand;

    target = extract_A(cpub);
    operand = extract_B(cpub);

    *target &= *operand;

    // Set flags
    cpub->vf = 0; // oVerflow Flag
    if((int8_t)*target < 0){ // Negative Flag
        cpub->nf = 1;
    }else{
        cpub->nf = 0;
    }
    if((int8_t)*target == 0){ // Zero Flag
        cpub->zf = 1;
    }else{
        cpub->zf = 0;
    }

    cpub->pc++;
    return RUN_STEP;
}
