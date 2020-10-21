.cpu cortex-m0 
.bss
	channel: .fill 0x28
.text 
.align 2 
.global decoder

decoder:
	push {lr} 					@; push the linkerpointer
	ldr	r3, =channel			     @; laad channel in r3
	ldr	r4, =compressed			@; laad de pointer van het begin van compressed in r4
	mov	r5, #0					@; houd index bij in r5
	mov	r6, #0					@; houd offset bij in r6
	mov	r7, #0					@; houd de lengte bij in r7
	
FileLoop:
	ldrb r0, [r4, r5]			     @; stopt het index character van de compressed in r0
	add r5, #1					@; index++
	cmp r0, #0					@; stopt met decompressen wanneer eof gevonden is
	beq	done					     @; branch done
	
	cmp r0, #'@'				     @; kijkt of iets gecompressed is
	beq	decompress				@; wanneer @ gevonden is branch decompress
	bl buffer					     @; branch naar buffer en vul de buffer
	bl uart_put_char			     @; print niet gecompressed character
	b FileLoop					@; loopt terug naar de fileloop voor volgende character
	
decompress:
	ldrb r6, [r4, r5]			     @; laad het eerste character na de @ in r6
	add r5, #1					@; index++
	ldrb r7, [r4, r5]			     @; laad het tweede character na de @ in r7
	add r5, #1					@; index++
	sub r6, r6, #'0'			     @; -48, Maak van offset een int
	sub r7, r7, #'0'			     @; -48, Maak van lengte een int

decompressLoop:
	ldrb r0, [r3, r6]			     @; laad char in r0
	bl buffer					     @; branch naar buffer en vul de buffer
	bl uart_put_char			     @; print char (r0)
	sub	r7, #1						 @; length--
	beq FileLoop				     @; kijkt of r7 == 1 en hiermee of de decompress is afgelopen
	b decompressLoop			     @; loop
	
buffer:
	push {lr}					     @; push the linkerpointer
	mov r1, #39						 @; zet bufferlengte in r1

bufferLoop:
	sub r1, #1 						 @; index--
	ldrb r2, [r3, r1] 			     @; load memory into r2  -------
	add r1, #1						 @; index++
	strb r2, [r3, r1]			     @; store char in r3 with index r1 into r2 store ------
	sub r1, #1						 @; index--

	cmp r1, #0						 @; kijk of index 0 is
	beq bufferDone				     @; eindig loop wanneer index 0 is
	b bufferLoop				     @; loop
	
bufferDone:
	strb r0, [r3, #0]			     @; laad char in r0
	pop {pc}					     @; pop pc
	
done:
	pop {pc} 					     @; pop pc