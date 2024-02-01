.text 



li x11 0b10000000000000000000000000000001
# sw x11 0(sp)
# slli x11 x11 31
# lb x11 0(sp)
li x10 1
ecall


# main:
# addi sp sp -8

# li x15 19
# li x16 10

# sw x15 0(sp)
# sw x16 4(sp)

# call k

# addi sp sp 8
# li x10 10
# ecall

# k:  #dfd

# ret