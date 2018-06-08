//
// Created by Junpei Kishi on 2018/05/25.
//

#include "BBC.h"

int extract_BC(Cpub *cpub);

/**
* @brief Operation BBC
*
* BBC Operation simulator
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int op_bbc(Cpub *cpub){

    if(extract_BC(cpub)){
        // True
        cpub->pc++;
        cpub->pc = GET_CURRENT_PC;
#ifdef DEBUG
        printf("True, Jump to 0x%02x\n", cpub->pc);
#endif
    }else{
#ifdef DEBUG
        printf("False\n");
#endif
        cpub->pc += 2;
    }

    return RUN_STEP;
}

/**
* @brief Extract BC State
*
* Evaluate expression which is indicated by BC
*
* @param *cpub CPU State
* @retval 0 The expression was false.
* @retval 1 The expression was true.
*
*/
int extract_BC(Cpub *cpub){
    switch(mask_BC(GET_CURRENT_PC)){
        case 0x0:
#ifdef DEBUG
            printf("Always true: ");
#endif
            return 1;
        case 0x8:
#ifdef DEBUG
            printf("When VF is set: ");
#endif
            return cpub->vf;
        case 0x1:
#ifdef DEBUG
            printf("When ZF is reset: ");
#endif
            return cpub->zf == 0;
        case 0x9:
#ifdef DEBUG
            printf("When ZF is set: ");
#endif
            return cpub->zf;
        case 0x2:
#ifdef DEBUG
            printf("When NF is reset: ");
#endif
            return cpub->nf == 0;
        case 0xA:
#ifdef DEBUG
            printf("When NF is set: ");
#endif
            return cpub->nf;
        case 0x3:
#ifdef DEBUG
            printf("When NF and ZF is reset: ");
#endif
            return (cpub->zf | cpub->nf) == 0;
        case 0xB:
#ifdef DEBUG
            printf("When NF or ZF is set: ");
#endif
            return (cpub->zf | cpub->nf);
        case 0x4:
#ifdef DEBUG
            printf("When input buffer is empty: ");
#endif
            return cpub->ibuf->flag == 0;
        case 0xC:
#ifdef DEBUG
            printf("When input buffer is not empty: ");
#endif
            return cpub->ibuf->flag;
        case 0x5:
#ifdef DEBUG
            printf("When CF is reset: ");
#endif
            return cpub->cf == 0;
        case 0xD:
#ifdef DEBUG
            printf("When CF is set: ");
#endif
            return cpub->cf;
        case 0x6:
#ifdef DEBUG
            printf("When VF and NF is reset: ");
#endif
            return (cpub->vf ^ cpub->nf) == 0;
        case 0xE:
#ifdef DEBUG
            printf("When VF and NF is set: ");
#endif
            return (cpub->vf ^ cpub->nf);
        case 0x7:
#ifdef DEBUG
            printf("When NF or NF is reset, and ZF is reset: ");
#endif
            return ((cpub->vf ^ cpub->nf) | cpub->zf) == 0;
        case 0xF:
#ifdef DEBUG
            printf("When NF and NF is set, or ZF is reset: ");
#endif
            return ((cpub->vf ^ cpub->nf) | cpub->zf);
        default:
            return 1;
    }
}
