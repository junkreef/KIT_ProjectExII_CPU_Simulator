//
// Created by Junpei Kishi on 2018/05/25.
//

#include "RCF.h"

/**
* @brief Operation RCF
*
* RCF Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_rcf(Cpub *cpub){
    cpub->cf = 0;
    cpub->pc++;
    return RUN_STEP;
}
