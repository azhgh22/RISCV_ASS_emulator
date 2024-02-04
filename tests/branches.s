# for(int i=0;i<10;i++){
#     if(i%2==0){
#         cout<<"luwi: "<< i <<endl;
#     }else{
#         cout<<"kenti: "<< i <<endl;
#     }
# }

addi sp sp -4
sw x0 0(sp)

li x20 10
li x21 2

for_start:
lw x13 0(sp)
bge x13 x20 for_end
rem x14 x13 x21
bne x0 x14 else 

li x11 'L'
li x10 11
ecall

mv x11 x13
li x10 1
ecall

li x11 10
li x10 11
ecall

j if_end
else:

li x11 'K'
li x10 11
ecall

mv x11 x13
li x10 1
ecall

li x11 10
li x10 11
ecall

if_end:

addi x13 x13 1
sw x13 0(sp)
j for_start
for_end:

addi sp sp 4
