//
// Created by Junpei Kishi on 2018/05/25.
//

#include "RSM.h"

int op_rsm(Cpub *cpub){
    Uword *target, temp=0;

    target = extract_A(cpub);

    switch(mask_SM(GET_CURRENT_PC)){
        case 0b00:
            // RRA
            temp = *target & 0x01;
            *target = (*target >> 1) | (cpub->cf << 7);
            cpub->cf = temp;
            break;

        case 0b01:
            // RLA
            temp = (*target & 0x80)>7;
            *target = (*target >> 1) | cpub->cf;
            cpub->cf = temp;
            break;

        case 0b10:
            // RRL
            cpub->cf = *target & 0x01;
            *target = (*target >> 1) | (cpub->cf << 7);
            break;

        case 0b11:
            // RLL
            cpub->cf = (*target & 0x80)>7;
            *target = (*target >> 1) | cpub->cf;
            break;

        default:
            break;
    }

    cpub->pc++;
    return RUN_STEP;
}