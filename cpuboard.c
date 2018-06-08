/*
 *	Project-based Learning II (CPU)
 *
 *	Program:	instruction set simulator of the Educational CPU Board
 *	File Name:	cpuboard.c
 *	Descrioption:	simulation(emulation) of an instruction
 */

#include <stdio.h>
#include	"cpuboard.h"


/**
* @brief Do a step of user programs
*
* Execute a operation which is pointed by Program Counter.
* PC will be moved.
*
* @param *cpub CPU State
* @retval RUN_STEP CPU is not halted.
* @retval RUN_HALT CPU is halted.
*
*/
int
step(Cpub *cpub)
{
    Uword op = GET_CURRENT_PC;
#ifdef DEBUG
    printf("PC=0x%02x Execute: ", cpub->pc);
#endif
    if(is_NOP(op)){
#ifdef DEBUG
        printf("NOP\n");
#endif
        cpub->pc++;
        return RUN_STEP;
    }else if(is_HLT(op)){
#ifdef DEBUG
        printf("HLT\n");
#endif
        return RUN_HALT;
    }else if(is_OUT(op)){
#ifdef DEBUG
        printf("OUT\n");
#endif
        return op_out(cpub);
    }else if(is_IN(op)){
#ifdef DEBUG
        printf("IN\n");
#endif
        return op_in(cpub);
    }else if(is_RCF(op)){
#ifdef DEBUG
        printf("RCF\n");
#endif
        return op_rcf(cpub);
    }else if(is_SCF(op)){
#ifdef DEBUG
        printf("SCF\n");
#endif
        return op_scf(cpub);
    }else if(is_LD(op)){
#ifdef DEBUG
        printf("LD\n");
#endif
        return op_ld(cpub);
    }else if(is_ST(op)){
#ifdef DEBUG
        printf("ST\n");
#endif
        return op_st(cpub);
    }else if(is_ADD(op)){
#ifdef DEBUG
        printf("ADD\n");
#endif
        return op_add(cpub);
    }else if(is_ADC(op)){
#ifdef DEBUG
        printf("ADC\n");
#endif
        return op_adc(cpub);
    }else if(is_SUB(op)){
#ifdef DEBUG
        printf("SUB\n");
#endif
        return op_sub(cpub);
    }else if(is_SBC(op)){
#ifdef DEBUG
        printf("SBC\n");
#endif
        return op_sbc(cpub);
    }else if(is_CMP(op)){
#ifdef DEBUG
        printf("CMP\n");
#endif
        return op_cmp(cpub);
    }else if(is_AND(op)){
#ifdef DEBUG
        printf("AND\n");
#endif
        return op_and(cpub);
    }else if(is_OR(op)){
#ifdef DEBUG
        printf("OR\n");
#endif
        return op_or(cpub);
    }else if(is_EOR(op)){
#ifdef DEBUG
        printf("EOR\n");
#endif
        return op_eor(cpub);
    }else if(is_SSM(op)){
#ifdef DEBUG
        printf("SSM\n");
#endif
        return op_ssm(cpub);
    }else if(is_RSM(op)){
#ifdef DEBUG
        printf("RSM\n");
#endif
        return op_rsm(cpub);
    }else if(is_BBC(op)){
#ifdef DEBUG
        printf("BBC\n");
#endif
        return op_bbc(cpub);
    }else if(is_JAL(op)){
#ifdef DEBUG
        printf("JAL\n");
#endif
        return op_jal(cpub);
    }else if(is_JR(op)){
#ifdef DEBUG
        printf("JR\n");
#endif
        return op_jr(cpub);
    }

    fflush(stdout);


	return RUN_HALT;
}

/**
* @brief Extract A section from OP
*
* Extract A from OP on current PC
*
* @param *cpub CPU State
* @retval The pointer to data which is pointed by extracted B
*
*/
Uword *extract_A(Cpub *cpub){

    if(mask_A(GET_CURRENT_PC)) {
        return  &(cpub->ix);
    } else {
        return  &(cpub->acc);
    }
}

/**
* @brief Extract B section from OP
*
* Extract B from OP on current PC
*
* @param *cpub CPU State
* @retval The pointer to data which is pointed by extracted B
*
*/
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

/**
* @brief Simulate ALU
*
* Execute ALU simulator
*
* @param *A ALU input "A"
* @param *B ALU input "B"
* @param CF Carry Flag. If you want to use CF for calc, set CF value. If you not, set 0.
* @retval The flag state when calculation was completed.
*
*/
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
