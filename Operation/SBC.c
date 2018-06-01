//
// Created by Junpei Kishi on 2018/05/25.
//

#include "SBC.h"

int op_sbc(Cpub *cpub){
    Uword op = GET_CURRENT_PC;
    Uword *target, *operand, flags;

    target = extract_A(cpub);
    operand = extract_B(cpub);
    flags = -(*operand);

    flags = alu(target, &flags, -(cpub->cf));

    // Set flags
    cpub->cf = (flags&0x08)&&1;
    cpub->vf = (flags&0x04)&&1;
    cpub->nf = (flags&0x02)&&1;
    cpub->zf = (flags&0x01)&&1;

    cpub->pc++;
    return RUN_STEP;
}