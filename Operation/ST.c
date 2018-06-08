//
// Created by Junpei Kishi on 2018/05/25.
//

#include "ST.h"

/**
* @brief Operation ST
*
* ST Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_st(Cpub *cpub){
    Uword *target, *operand;

    target = extract_A(cpub);
    operand = extract_B(cpub);

    *operand = *target;

    cpub->pc++;
    return RUN_STEP;
}
