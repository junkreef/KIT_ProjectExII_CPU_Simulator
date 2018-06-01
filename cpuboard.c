/*
 *	Project-based Learning II (CPU)
 *
 *	Program:	instruction set simulator of the Educational CPU Board
 *	File Name:	cpuboard.c
 *	Descrioption:	simulation(emulation) of an instruction
 */

#include <stdio.h>
#include	"cpuboard.h"


/*=============================================================================
 *   Simulation of a Single Instruction
 *===========================================================================*/
int
step(Cpub *cpub)
{
    Uword op = GET_CURRENT_PC;
    printf("PC=0x%02x Execute: ", cpub->pc);
    if(is_NOP(op)){
        printf("NOP\n");
        cpub->pc++;
        return RUN_STEP;
    }else if(is_HLT(op)){
        printf("HLT\n");
        return RUN_HALT;
    }else if(is_OUT(op)){
        printf("OUT\n");
        return op_out(cpub);
    }else if(is_IN(op)){
        printf("IN\n");
        return op_in(cpub);
    }else if(is_RCF(op)){
        printf("RCF\n");
        return op_rcf(cpub);
    }else if(is_SCF(op)){
        printf("SCF\n");
        return op_scf(cpub);
    }else if(is_LD(op)){
        printf("LD\n");
        return op_ld(cpub);
    }else if(is_ST(op)){
        printf("ST\n");
        return op_st(cpub);
    }else if(is_ADD(op)){
        printf("ADD\n");
        return op_add(cpub);
    }else if(is_ADC(op)){
        printf("ADC\n");
        return op_adc(cpub);
    }else if(is_SUB(op)){
        printf("SUB\n");
        return op_sub(cpub);
    }else if(is_SBC(op)){
        printf("SBC\n");
        return op_sbc(cpub);
    }else if(is_CMP(op)){
        printf("CMP\n");
        return op_cmp(cpub);
    }else if(is_AND(op)){
        printf("AND\n");
        return op_and(cpub);
    }else if(is_OR(op)){
        printf("OR\n");
        return op_or(cpub);
    }else if(is_EOR(op)){
        printf("EOR\n");
        return op_eor(cpub);
    }else if(is_SSM(op)){
        printf("SSM\n");
        return op_ssm(cpub);
    }else if(is_RSM(op)){
        printf("RSM\n");
        return op_rsm(cpub);
    }else if(is_BBC(op)){
        printf("BBC\n");
        return op_bbc(cpub);
    }else if(is_JAL(op)){
        printf("JAL\n");
        return op_jal(cpub);
    }else if(is_JR(op)){
        printf("JR\n");
        return op_jr(cpub);
    }

    fflush(stdout);


	return RUN_HALT;
}

Uword *extract_A(Cpub *cpub){

    if(mask_A(GET_CURRENT_PC)) {
        return  &(cpub->ix);
    } else {
        return  &(cpub->acc);
    }
}

Uword *extract_B(Cpub *cpub){
    Uword B = mask_B(GET_CURRENT_PC);

    switch(B){
        case 0b000:
            return &(cpub->acc);

        case 0b001:
            return &(cpub->ix);

        case 0b010:
        case 0b011:
            cpub->pc++;
            return &(GET_CURRENT_PC);

        case 0b100:
            cpub->pc++;
            return &(cpub->mem[0x000 + GET_CURRENT_PC]);

        case 0b101:
            cpub->pc++;
            return &(cpub->mem[0x100 + GET_CURRENT_PC]);

        case 0b110:
            cpub->pc++;
            return &(cpub->mem[0x000 + GET_CURRENT_PC + cpub->ix]);

        case 0b111:
            cpub->pc++;
            return &(cpub->mem[0x100 + GET_CURRENT_PC + cpub->ix]);

        default:
            break;
    }
    return 0;
}

Uword alu(Uword *A, Uword *B, uint8_t CF){
    unsigned char time, vf = 0, result = 0, ret = 0;

    for(time = 0; time < 8; time++){
        switch(((*A >> time) & 1) + ((*B >> time) & 1) + vf + CF){
            case 0:
                vf = 0;
                break;
            case 1:
                vf = 0;
                result += 1 << time;
                break;
            case 2:
                vf = 1;
                break;
            case 3:
                result += 1 << time;
                vf = 1;
                break;
            default:
                break;
        }
        CF = 0;
        // Set VF if carried 1 from 6bit to 7bit
        if(time == 6 && vf == 1){
            ret |= 0x04;
        }
    }
    // Set VF if carried 1 from 7bit to (8)bit
    if(vf == 1){
        ret |= 0x08;
    }

    // Set NF if 7bit is 1
    if(result & 0x80){
        ret |= 0x02;
    }

    // Set ZF if result = 0
    if(result == 0){
        ret |= 0x01;
    }

    *A = result;
    return ret;
}