//
// Created by Junpei Kishi on 2018/05/25.
//

#include "SSM.h"

/**
* @brief Operation SSM
*
* SSM Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_ssm(Cpub *cpub){
    Uword *target;

    target = extract_A(cpub);

    // Switch with SM state in the memory data which is pointed by PC
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
