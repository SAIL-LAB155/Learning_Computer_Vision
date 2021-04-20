#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY     ((key_t)0x20201231)
#define SHM_SIZE    (16*1024*1024)

int shm_send_pic(char* buf,int size)
{
    if((buf == NULL) || (size <= 0))
    {
        printf("para error\n");
        return -1;
    }

    int shmid = shmget(SHM_KEY,SHM_SIZE,IPC_CREAT|0664);
    if(-1 == shmid)
    {
        printf("shmget fail\n");
        return -1;
    }

    void* ptr = shmat(shmid,NULL,0);
    if(((void*)-1) == ptr)
    {
        printf("shmat fail\n");
        return -1;
    }

    int* pi = ptr;
    *pi = size;

    memcpy(ptr+sizeof(int),buf,size);

    return 0;
}
