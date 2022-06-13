.syntax unified
.thumb
.text

@ Simbolos exportados
.global asm_svc
.global asm_sum
.global asm_zeros				@ Pregunta 1
.global asm_productoEscalar32	@ Pregunta 2
.global asm_productoEscalar16	@ Pregunta 3
.global asm_productoEscalar12	@ Pregunta 4
.global asm_filtroVentana10		@ Pregunta 5
.global asm_pack32to16			@ Pregunta 6
.global asm_max					@ Pregunta 7
.global asm_downsampleM			@ Pregunta 8
.global asm_invertir			@ Pregunta 9
.global asm_corr
.global asm_testvector



@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@   void asm_svc (void)
@
.thumb_func
    asm_svc:
        svc 0
        bx lr


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@   uint32_t asmSum (uint32_t firstOperand, uint32_t secondOperand)
@
@ Parametros recibidos:
@   r0: firstOperand
@   r1: secondOperand
@
@ Valor de retorno:
@   r0: resultado de la suma de firstOperand y secondOperand
@
.thumb_func
    asm_sum:
        add r0, r1  @ r0 = r0 + r1
        bx lr       @ vuelve adonde fue llamada (especificamente, si "pc"
                    @ es la direccion, en el codigo del programa, de la
                    @ instruccion "bl asm_sum" usada para saltar a
                    @ esta funcion, entonces "lr" contiene ese "pc" + 4).
                    @ el valor de retorno debe quedar en el registro r0.
                    @ En este caso, r0 es el resultado de r0 + r1.

        @ Otras alternativas para el retorno
        @ mov pc,lr
        @ bx lr
        @ push {lr} ... pop {pc}

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C":
@   void asm_zeros (uint32_t *vector, uint32_t longitud);
@
@ Parametros recibidos:
@   r0: *vector
@   r1: longitud
@
.thumb_func
    asm_zeros:
        @ Registros usados
        @   r2: valor cero
        mov r2, 0           @ constante cero
    .asm_zeros_loop:
        str r2, [r0], 4     @ sizeof(uint32_t) == 4, *vector++ = r2
        subs r1, 1          @ --longitud
        bne .asm_zeros_loop
        bx lr

.thumb_func
    asm_productoEscalar32:
    	push {r5}
	.asm_productoEscalar32_loop:
    	ldr r5,[r0],4
    	mul r5,r5,r3
    	str r5,[r1],4
    	subs r2,1
        bne .asm_productoEscalar32_loop
        pop {r5}
        bx lr

.thumb_func
    asm_productoEscalar16:
    	push {r5}
	.asm_productoEscalar16_loop:
    	ldrh r5,[r0],2
    	mul r5,r5,r3
    	strh r5,[r1],2
    	subs r2,1
        bne .asm_productoEscalar16_loop
        pop {r5}
        bx lr




.thumb_func
    asm_productoEscalar12:
    	push {r5}
    	push {r6}
    	mov r6,#0x0FFF
	.asm_productoEscalar12_loop:
    	ldrh r5,[r0],2
    	mul r5,r5,r3
    	subs r6,r5
    	bpl .nosatura
    	mov r5,4095
    .nosatura:
    	@mov r6,#0x0FFF
    	@and r5,r5,r6
    	strh r5,[r1],2
    	subs r2,1
        bne .asm_productoEscalar12_loop
        pop {r6}
        pop {r5}
        bx lr


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C"  Pregunta 5:
@   void filtroVentana10(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn);
@
@ Parametros recibidos:
@   r0: * vectorIn
@   r1: * vectorOut
@	r2:	longitudVectorIn
@
.thumb_func
    asm_filtroVentana10:
    	push {r4-r8}
    	mov r3, r2
		@sub r3,1	@ longitud vector -1 Ejem: 100 elemnt => 0 - 99
		mov r8, 3	@ r4 window size = 3
    	.asm_filtroVentana10_loop_1:

	    	mov r4, r8
    		mov r7, r4
			sub r4, 1		@ r4 carga tamaño ventana -1
    		mov r6, 0
	    	.asm_filtroVentana10_loop_2:

    			add r4, r7, r3		@ r4 = (tamaño ventana -1) + (longitud dinamico vector -1)
    			sub r4, 2
    			udiv r5, r4, r2	@ r5 = r4/ longitud real
    			mul	r5, r5, r2	@ r5 = r5(division) * r2(longitud)
    			sub r4, r4, r5	@ r4 = r4 (long+ven-2) MOD r5 (div*long)
				mov r5,2		@ r5 = 2 bytes
	    		mul r5, r4, r5	@ r5 = indice = MOD * r7 ( 2bytes)
	    		ldrh r5, [r0, r5]
    			add r6, r5
    			subs r7, 1
	    		bne .asm_filtroVentana10_loop_2

	    	mov r5, 2			@ r5 carga valor bytes en 16bits = 2
	    	mul r5, r3, r5		@ r5 r3 ( indice actual vector ) * r5 ( 2 bytes )
	    	sub r5, 2			@ r5 disminuido en 2 (2 bytes)
			udiv r6, r8			@ r6 = r6(acumulación) / r8(tamaño ventana)
    		strh r6,[r1,r5]		@ r6 vectorOut actualizado
			subs r3,1
    		bne .asm_filtroVentana10_loop_1
    	pop {r4-r8}
        bx lr




@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C"  Pregunta 6:
@   void pack32to16 (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);
@
@ Parametros recibidos:
@   r0: * vectorIn
@   r1: * vectorOut
@	r2:	longitud
@
.thumb_func
    asm_pack32to16:
    	push {r4}
    	mov r4, 16			@ bits a desplazar a la derecha
    	.asm_pack32to16_loop:
	    	ldr r3,[r0],4	@ carga r0 a r3 en 32 bits
	    	lsr r3, r4		@ desplazamiento a derecha
	    	strh r3,[r1],2	@ carga r3 a r1 en 16 bits
	    	subs r2, 1		@ longitud -1
	    	bne .asm_pack32to16_loop	@ fin del bucle
    	pop {r4}
    	bx lr


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C"  Pregunta 7:
@   int32_t max (int32_t * vectorIn, uint32_t longitud);
@
@ Parametros recibidos:
@   r0: * vectorIn
@   r1: longitud
@
.thumb_func
    asm_max:
		push {r4,r5}
		mov r5, r1	@ copia valor longitud
		mov r4, r2	@ maximo valor anterior
		mov r3, r1 	@ posicion max valor
    	.asm_max_loop:
    		ldr	r2, [r0], 4
    		cmp r4, r2
    		bpl .asm_max_r2max
    		mov r4, r2
    		mov r3, r1
    		.asm_max_r2max:
    		subs r1, 1
    		bne .asm_max_loop
		sub r3, r5, r3
		mov r0, r3
		pop {r4,r5}
    	bx lr


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C"  Pregunta 8:
@   void downsampleM (int32_t * vectorIn, int32_t * vectorOut, uint32_t longitud, uint32_t N);
@
@ Parametros recibidos:
@   r0: * vectorIn
@   r1: * vectorOut
@	r2:	longitud
@	r3:	N
@
.thumb_func
    asm_downsampleM:
		push {r4,r5,r6}
		mov r5, r2 	@ carga longitud en r5
		.asm_downsampleM_loop:
			sub r4, r5, r2
			add r4, 1
			udiv r6, r4, r3
			mul r6, r6, r3
			subs r6, r4, r6
			beq .asm_downsampleM_noresiduo
				@mul r5, r2, 4
				@sub r5, 4
				ldr r4, [r0]
				str r4, [r1],4
			.asm_downsampleM_noresiduo:
			add r0, 4
			subs r2,1

			bne .asm_downsampleM_loop
		pop {r4,r5,r6}
    	bx lr


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C"  Pregunta 9:
@   void invertir (uint16_t * vector, uint32_t longitud);
@
@ Parametros recibidos:
@   r0: * vector
@   r1: longitud
@
.thumb_func
    asm_invertir:
    	push {r4} // longitud mitad
    	push {r5}	// nro
    	push {r6}	// nro
    	mov r5,2
    	mov r6,0
    	udiv r4,r1,r5
    	.asm_invertir_loop:
    		mov r5,2
	    	subs r1,1
	    	mul r5,r1,r5
	    	ldrh r2,[r0,r6]
	    	ldrh r3,[r0,r5]
	    	strh r2,[r0,r5]
	    	strh r3,[r0,r6]
	    	add r6,2
    		subs r4,1
    		bne .asm_invertir_loop
        pop {r6}
        pop {r5}
        pop {r4}
        bx lr


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Prototipo en "C"  Pregunta 11:
@   void corr (int16_t * vectorX, int16_t * vectorY, int32_t * vectorCorr, uint32_t longitud);
@
@ Parametros recibidos:
@   r0: * vectorX
@   r1: * vectorY
@   r2: * vectorCorr
@   r3: longitud
@
.thumb_func
    asm_corr:
    	push {r4,r5,r6,r7,r8,r9,r10}
		@ r4 tendrá valor minimo de l = -15
		@ r5 sera una copia de longitud que variará
		@ r6 es el longitud - r5
		@ r7 tendrá el valor de vectorX
		@ r8 tendrá el valor de vectorY
		@ r9 acumulador
		sub r4, r3, 1
		neg r4, r4

		.asm_corr_loop_l:
			mov r5, r3
			mov r9, #0
			.asm_corr_loop_n:


				sub r6, r3, r5				@ r6= r3-r5  (16-15)
				ldr r7, [r0, r6, LSL 1]	@ vectorX
				cmp r6, #1
				it eq
					andeq r7, r7, #0x00FF
				sub r10, r6, r4				@ n-l  r6 =  r6- r4
				ldr r8, [r1, r10, LSL 1]	@ vectorY
				@ 1er caso N(egativo)=0 osea es positivo o 0

				sub r10, r3, r10
				cmp r10, #1
				it eq
					andeq r8, r8, #0x00FF



				subs r6, r6, r4				@ n-l  r6 =  r6- r4

				it pl
					subspl r6, r3, r6 @ 1er caso2 r3-r6 sigue siendo N=0 osea positivo o 0

				subs r6, #1
				itt pl
					smuadpl r8, r7, r8
					addpl r9, r8

				subs r5, #2
				bne .asm_corr_loop_n

			str r9, [r2], 4
			add r4, #1
			cmp r4, r3
			bmi .asm_corr_loop_l

     	push {r4,r5,r6,r7,r8,r9}
        bx lr







.thumb_func
    asm_testvector:
    	mov r3,7
    	.asm_testvector_loop:
    		ldr r2,[r0],4
    		subs r3,1
    		bne .asm_testvector_loop
        bx lr
