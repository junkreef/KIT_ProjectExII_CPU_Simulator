//
// Created by Junpei Kishi on 2018/05/25.
//

#include "BBC.h"

int extract_BC(Cpub *cpub);

int op_bbc(Cpub *cpub){

    if(extract_BC(cpub)){
        // True
        cpub->pc++;
        cpub->pc = GET_CURRENT_PC;
        printf("True, Jump to 0x%02x\n", cpub->pc);
    }else{
        printf("False\n");
        cpub->pc += 2;
    }

    return RUN_STEP;
}

int extract_BC(Cpub *cpub){
    switch(mask_BC(GET_CURRENT_PC)){
        case 0x0:
            printf("Always true: ");
            return 1;
        case 0x8:
            printf("When VF is set: ");
            return cpub->vf;
        case 0x1:
            printf("When ZF is reset: ");
            return cpub->zf == 0;
        case 0x9:
            printf("When ZF is set: ");
            return cpub->zf;
        case 0x2:
            printf("When NF is reset: ");
            return cpub->nf == 0;
        case 0xA:
            printf("When NF is set: ");
            return cpub->nf;
        case 0x3:
            printf("When NF and ZF is reset: ");
            return (cpub->zf | cpub->nf) == 0;
        case 0xB:
            printf("When NF or ZF is set: ");
            return (cpub->zf | cpub->nf);
        case 0x4:
            printf("When input buffer is empty: ");
            return cpub->ibuf->flag == 0;
        case 0xC:
            printf("When input buffer is not empty: ");
            return cpub->ibuf->flag;
        case 0x5:
            printf("When CF is reset: ");
            return cpub->cf == 0;
        case 0xD:
            printf("When CF is set: ");
            return cpub->cf;
        case 0x6:
            printf("When VF and NF is reset: ");
            return (cpub->vf ^ cpub->nf) == 0;
        case 0xE:
            printf("When VF and NF is set: ");
            return (cpub->vf ^ cpub->nf);
        case 0x7:
            printf("When NF or NF is reset, and ZF is reset: ");
            return ((cpub->vf ^ cpub->nf) | cpub->zf) == 0;
        case 0xF:
            printf("When NF and NF is set, or ZF is reset: ");
            return ((cpub->vf ^ cpub->nf) | cpub->zf);
        default:
            return 1;
    }
}