//
// Created by Junpei Kishi on 2018/05/25.
//

#include "SSM.h"

int op_ssm(Cpub *cpub){
    Uword *target;

    target = extract_A(cpub);

    switch(mask_SM(GET_CURRENT_PC)){
        case 0b00:
            // SRA
            cpub->cf = 1 & *target;
            *target = *target >> 1 | (*target&0x80);
            break;

        case 0b01:
            //SLA
        case 0b11:
            // SLL
            cpub->cf = (0x80 & *target) != 0;
            *target = *target << 1;
            break;

        case 0b10:
            // SRL
            cpub->cf = 1 & *target;
            *target = *target >> 1;
            break;

        default:
            break;
    }

    cpub->pc++;
    return RUN_STEP;
}