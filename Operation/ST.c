//
// Created by Junpei Kishi on 2018/05/25.
//

#include "ST.h"

int op_st(Cpub *cpub){
    Uword *target, *operand;

    target = extract_A(cpub);
    operand = extract_B(cpub);

    *operand = *target;

    cpub->pc++;
    return RUN_STEP;
}