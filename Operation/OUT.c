//
// Created by Junpei Kishi on 2018/05/25.
//

#include "OUT.h"

/**
* @brief Operation OUT
*
* OUT Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_out(Cpub *cpub){
    cpub->obuf.buf = cpub->acc;

    // Print Output buffer state
    printf("\r");
    for(int time = 0; time < 8; time++){
        if(cpub->obuf.buf & (0x80 >> time)){
            putchar('*');
        }else{
            putchar('_');
        }
    }
    printf("\n");
    fflush(stdout);

    cpub->pc++;
    return RUN_STEP;
}
