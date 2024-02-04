# print "sp before addi. should print 20000"
mv x11 sp
li x10 1
ecall

li x11 10
li x10 11
ecall

addi sp sp -8

# print "sp after addi. should print 19992"

# print sp
mv x11 sp
li x10 1
ecall

# new line
li x11 10
li x10 11
ecall

# print "load word!!! .value after storing and loading. should print 144"
li x15 144
sw x15 0(sp)

lw x11 0(sp)
li x10 1
ecall

# new line
li x11 10
li x10 11
ecall

# print "load byte!!! .value after storing and loading. should print -122"
lb x11 0(sp)
li x10 1
ecall

# new line
li x11 10
li x10 11
ecall

addi sp sp 8

# print "sp after addi. should print 20000"

mv x11 sp
li x10 1
ecall

li x11 10
li x10 11
ecall