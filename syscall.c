#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE2(kernel_2d_memcpy, void *, dest, void *,src)
{
    float temp_matrix[2][2];
    int ret1= __copy_from_user(temp_matrix, src, sizeof(temp_matrix));
    if (ret1!=0){
        printk("Error in copying from user space");
    }
    int ret2= __copy_to_user(dest, temp_matrix, sizeof(temp_matrix));
    if (ret2!=0){
        printk("Error in copying to user space");
    }
    return 0;
}