//
// Created by Junpei Kishi on 2018/05/25.
//

#include "LD.h"

/**
* @brief Operation LD
*
* LD Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_ld(Cpub *cpub){
    Uword *target, *operand;

    target = extract_A(cpub);
    operand = extract_B(cpub);

    *target = *operand;

    cpub->pc++;
    return RUN_STEP;
}
