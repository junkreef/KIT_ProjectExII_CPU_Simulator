//
// Created by Junpei Kishi on 2018/05/25.
//

#include "LD.h"

int op_ld(Cpub *cpub){
    Uword *target, *operand;

    target = extract_A(cpub);
    operand = extract_B(cpub);

    *target = *operand;

    cpub->pc++;
    return RUN_STEP;
}