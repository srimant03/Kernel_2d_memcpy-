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

`-451	common	kernel_2d_memcpy		sys_kernel_2d_memcpy`

## How to test your SysCall?

Compile the SysCall by recompiling your kernel and rebooting it through the following commands

```make

make modules_install

cp -v arch/x86_64/boot/bzImage /boot/vmlinuz-[kernelname]

mkinitcpio -k 5.19.9 -g /boot/initramfs-[kernelname]

grub-mkconfig -o /boot/grub/grub.cfg

reboot
```

Clone the entire repository & run the main.c file through the following commands

```
make

.main
```

## Generating a patch file

A patch file is a text file that consists of a list of differences and is produced by running the related diff program with the original and updated file as arguments. The patch file can be generated to see the differences between the original and the modified kernels.

```
diff -u linux-5.19.9/arch/x86/entry/syscalls/syscall_64.tbl [modified_kernel]/arch/x86/entry/syscalls/syscall_64.tbl >>patch_systable.patch

diff -u linux-5.19.9/kernel/sys.c [modified_kernel]/kernel/sys.c >>patch_sys.patch

```

## Resources Used

https://brennan.io/2016/11/14/kernel-dev-ep3/ 
