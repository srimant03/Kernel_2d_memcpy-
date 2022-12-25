# Kernel_2d_memcpy

## Simple Syscall Implementation

This program essentially shows how a system call works. The program involves writing a custom kernel system call using kernel functions like __copy_from_user() & __copy_to_user() to read data bytes from user space and writing back to user space. This function is very similar to memcpy(); other than the fact that its implementation requires the kernel to perform the necessary copy operations which are otherwise done in the user space.

## Writing your SysCall

The SysCall is defined using SYSCALLDEFINEN family of macros that takes in 2 arguments in this case. The arguments used are name of our system call, destination matrix and the source matrix.
A temporary matrix is used within the syscall for copying operations.

__copy_from_user() copies the matrix from the user to a temporary matrix and return 0 on successful copying; otherwise returns -1 and prints an error message to the kernel log.

__copy_to_user() copies the temporary matrix into the destination matrix and returns 0 on successful copying; otherwise returns -1 and prints an error message to the kernel log.

## How to add your SysCall?

Add the syscall written to kernel/sys.c in the kernel source.

`nano kernel/sys.c`

Edit the syscall table

`nano arch/x86/entry/syscalls/syscall_64.tbl`

Add your syscall at the end of the table using the next available number as your syscall number

`451

## How to test your SysCall?

## Generating a patch file

## Resources Used

https://brennan.io/2016/11/14/kernel-dev-ep3/ 
