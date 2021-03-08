#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>

void task_info (void)
{
    struct task_struct *process = current;
    
    for_each_process(process)
    {
        printk("Name: %s | PID: %d | ParentID: %d\n", process->comm, process->pid, process->parent);
    }
}

int task_info_start (void)
{
    printk(KERN_INFO "Loading Task List Info\n");
    task_info();

    return 0;
}

void task_info_stop (void)
{
    printk(KERN_INFO "Removing Task List Info\n");
}

//module init and exit points
module_init(task_info_start);
module_exit(task_info_stop);



