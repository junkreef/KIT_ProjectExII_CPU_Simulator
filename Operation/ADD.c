//
// Created by Junpei Kishi on 2018/05/25.
//

#include "ADD.h"

/**
* @brief Operation ADD
*
* ADD Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_add(Cpub *cpub){
    Uword op = GET_CURRENT_PC;
    Uword *target, *operand, flags;

    target = extract_A(cpub);
    operand = extract_B(cpub);

    flags = alu(target, operand, 0);

    // Set flags
//    cpub->cf = (flags&0x08)&&1; 
    cpub->vf = (flags&0x04)&&1;
    cpub->nf = (flags&0x02)&&1;
    cpub->zf = (flags&0x01)&&1;

    cpub->pc++;
    return RUN_STEP;
}
