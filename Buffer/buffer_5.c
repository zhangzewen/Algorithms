
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


typedef unsigned char      cb_u8;
typedef unsigned short int cb_u16;
typedef unsigned int       cb_u32;
typedef signed char        cb_s8;
typedef signed short int   cb_s16;
typedef signed int         cb_s32;
typedef char               cb_char;

typedef enum {cb_false, cb_true} cb_bool;

typedef struct {
    cb_u8    *bufptr;
    cb_u32    buflen;
    cb_u32    datalen;
    cb_u32    readpos;
    cb_u32    writepos;
}CircleBufferMngr;

typedef struct {
    void (*cb_init)(CircleBufferMngr **, cb_u32);
    void (*cb_deinit)(CircleBufferMngr **);
    void (*cb_info)(CircleBufferMngr *, cb_char *, cb_u32);
    cb_u32 (*cb_read)(CircleBufferMngr *, cb_u8 *, cb_u32);
    cb_u32 (*cb_write)(CircleBufferMngr *, cb_u8 *, cb_u32);
    cb_u32 (*cb_datalen)(CircleBufferMngr *);
    cb_bool (*cb_full)(CircleBufferMngr *);
    cb_bool (*cb_empty)(CircleBufferMngr *);
}CircleBufferApi;



#define CB_MEMCPY   memcpy
#define CB_MEMSET   memset
#define CB_SPRINT   sprintf
#define CB_MALLOC   malloc
#define CB_MFREE    free
#define CB_ASSERT   assert
#define CB_SNPRINT  snprintf
#define CB_TRACE    printf


//锁定, 禁止中断和任务调度
#define CB_GLOBAL_LOCK
#define CB_GLOBAL_UNLOCK

extern const CircleBufferApi circleBufApi;

#define CBMA_INIT     circleBufApi.cb_init
#define CBMA_DEINIT   circleBufApi.cb_deinit
#define CBMA_INFO     circleBufApi.cb_info
#define CBMA_READ     circleBufApi.cb_read
#define CBMA_WRITE    circleBufApi.cb_write
#define CBMA_DATALEN  circleBufApi.cb_datalen
#define CBMA_FULL     circleBufApi.cb_full
#define CBMA_EMPTY    circleBufApi.cb_empty




/*******************************************************************************
** 函数: cb_init
** 功能: 初始化
** 作者: avrbase_lei
*******/
static void cb_init(CircleBufferMngr **ppmngr, cb_u32 buflen);

/*******************************************************************************
** 函数: cb_deinit
** 功能: 资源释放
** 作者: avrbase_lei
*******/
static void cb_deinit(CircleBufferMngr **ppmngr);

/*******************************************************************************
** 函数: cb_info
** 功能: 打印管理变量中的各种值到长度为buflen的outbuf中
** 作者: avrbase_lei
*******/
static void cb_info(
    CircleBufferMngr *pmngr,
    int (*user_printf)(const char *, ...));

/*******************************************************************************
** 函数: cb_read
** 功能: 读取不超过buflen长度的数据到outbuf中, 其中outbuf的长度不得低于buflen
** 返回: 返回实际读取的数据长度, 字节为单位
** 说明: 如果传入的outbuf地址为NULL, 则直接删除buflen长度的数据
** 作者: avrbase_lei
*******/
static cb_u32 cb_read(
    CircleBufferMngr *pmngr,
    cb_u8 *outbuf,
    cb_u32 buflen);

/*******************************************************************************
** 函数: cb_write
** 功能: 将datptr所指向的地址中的datlen长度的数据写入到pmngr->bufptr中
** 返回: 返回实际写入的数据长度, 字节为单位
** 作者: avrbase_lei
*******/
static cb_u32 cb_write(
    CircleBufferMngr *pmngr,
    cb_u8 *datptr,
    cb_u32 datlen);

/*******************************************************************************
** 函数: cb_datalen
** 功能: 查询pmngr->bufptr中的数据长度
** 返回: 返回pmngr->bufptr数据长度, 字节为单位
** 作者: avrbase_lei
*******/
static cb_u32 cb_datalen(CircleBufferMngr *pmngr);

/*******************************************************************************
** 函数: cb_full
** 功能: 判断缓冲区是否已满
** 作者: avrbase_lei
*******/
static cb_bool cb_full(CircleBufferMngr *pmngr);

/*******************************************************************************
** 函数: cb_empty
** 功能: 判断缓冲区是否为空
** 作者: avrbase_lei
*******/
static cb_bool cb_empty(CircleBufferMngr *pmngr);




/*******************************************************************************
** 函数: cb_init
** 功能: 初始化
** 作者: avrbase_lei
*******/
static void cb_init(CircleBufferMngr **ppmngr, cb_u32 buflen)
{    
    CB_ASSERT(NULL != ppmngr);
    
    if (NULL != *ppmngr)
        return;
    
    if (0 == buflen)
        return;

    *ppmngr = (CircleBufferMngr*)CB_MALLOC(sizeof(CircleBufferMngr));
    CB_ASSERT(NULL != *ppmngr);
    CB_MEMSET((void*)*ppmngr, 0, sizeof(CircleBufferMngr));
    
    (*ppmngr)->bufptr = (cb_u8*)CB_MALLOC(buflen);
    CB_ASSERT(NULL != (*ppmngr)->bufptr);
    (*ppmngr)->buflen = buflen;
    CB_MEMSET((void*)(*ppmngr)->bufptr, 0, buflen);
}

/*******************************************************************************
** 函数: cb_deinit
** 功能: 资源释放
** 作者: avrbase_lei
*******/
static void cb_deinit(CircleBufferMngr **ppmngr)
{
    CB_ASSERT(NULL != ppmngr);

    if(NULL == *ppmngr)
        return;
    
    if (NULL != (*ppmngr)->bufptr)
    {
        CB_MFREE((*ppmngr)->bufptr);
        (*ppmngr)->bufptr = NULL;
        (*ppmngr)->buflen = 0;
    }

    CB_MFREE(*ppmngr);
    *ppmngr = NULL;
}

/*******************************************************************************
** 函数: cb_info
** 功能: 打印管理变量中的各种值到长度为buflen的outbuf中
** 作者: avrbase_lei
*******/
static void cb_info(
    CircleBufferMngr *pmngr,
    int (*user_printf)(const char *, ...))
{
    CB_ASSERT(NULL != pmngr);
    
    user_printf(
        "datalen=%d,readpos=%d,writepos=%d.",
        pmngr->datalen,
        pmngr->readpos,
        pmngr->writepos);
}

/*******************************************************************************
** 函数: cb_read
** 功能: 读取不超过buflen长度的数据到outbuf中, outbuf的长度不得低于buflen
** 返回: 返回实际读取的数据长度, 字节为单位
** 说明: 如果传入的outbuf地址为NULL, 则直接删除buflen长度的数据
** 作者: avrbase_lei
*******/
static cb_u32 cb_read(
    CircleBufferMngr *pmngr,
    cb_u8 *outbuf,
    cb_u32 buflen)
{
    cb_u32 readlen = 0, tmplen = 0;
    
    CB_ASSERT(NULL != pmngr);
    CB_ASSERT(NULL != pmngr->bufptr);

    if(cb_empty(pmngr))
        return 0;
    
    CB_GLOBAL_LOCK;
    readlen = buflen > pmngr->datalen ? pmngr->datalen : buflen;
    tmplen = pmngr->buflen - pmngr->readpos;
    if(NULL != outbuf)
    {
        if(readlen <= tmplen)
        {
            CB_MEMCPY(
                (void*)outbuf,
                (void*)&pmngr->bufptr[pmngr->readpos],
                readlen);
        }
        else
        {
            CB_MEMCPY(
                (void*)outbuf,
                (void*)&pmngr->bufptr[pmngr->readpos],
                tmplen);
            
            CB_MEMCPY(
                (void*)&outbuf[tmplen],
                (void*)pmngr->bufptr,
                readlen - tmplen);
        }
    }
    
    pmngr->readpos = (pmngr->readpos + readlen) % pmngr->buflen;
    pmngr->datalen -= readlen;
    CB_GLOBAL_UNLOCK;
    
    return readlen;
}

/*******************************************************************************
** 函数: cb_write
** 功能: 将datptr所指向的地址中的datlen长度的数据写入到pmngr->bufptr中
** 返回: 返回实际写入的数据长度, 字节为单位
** 作者: avrbase_lei
*******/
static cb_u32 cb_write(CircleBufferMngr *pmngr, cb_u8 *datptr, cb_u32 datlen)
{
    cb_u32 writelen = 0, tmplen = 0;
    
    CB_ASSERT(NULL != pmngr);
    CB_ASSERT(NULL != pmngr->bufptr);

    if(cb_full(pmngr))
        return 0;
    
    CB_GLOBAL_LOCK;
    tmplen = pmngr->buflen - pmngr->datalen;
    writelen = tmplen > datlen ? datlen : tmplen;

    if(pmngr->writepos < pmngr->readpos)
    {
        CB_MEMCPY(
            (void*)&pmngr->bufptr[pmngr->writepos],
            (void*)datptr,
            writelen);
    }
    else
    {
        tmplen = pmngr->buflen - pmngr->writepos;
        if(writelen <= tmplen)
        {
            CB_MEMCPY(
                (void*)&pmngr->bufptr[pmngr->writepos],
                (void*)datptr,
                writelen);
        }
        else
        {
            CB_MEMCPY(
                (void*)&pmngr->bufptr[pmngr->writepos],
                (void*)datptr,
                tmplen);
            CB_MEMCPY(
                (void*)pmngr->bufptr,
                (void*)&datptr[tmplen],
                writelen - tmplen);
        }
    }

    pmngr->writepos = (pmngr->writepos + writelen) % pmngr->buflen;
    pmngr->datalen += writelen;
    CB_GLOBAL_UNLOCK;
        
    return writelen;
}

/*******************************************************************************
** 函数: cb_datalen
** 功能: 查询pmngr->bufptr中的数据长度
** 返回: 返回pmngr->bufptr数据长度, 字节为单位
** 作者: avrbase_lei
*******/
static cb_u32 cb_datalen(CircleBufferMngr *pmngr)
{
    CB_ASSERT(NULL != pmngr);
    return pmngr->datalen;
}

/*******************************************************************************
** 函数: cb_full
** 功能: 判断缓冲区是否已满
** 作者: avrbase_lei
*******/
static cb_bool cb_full(CircleBufferMngr *pmngr)
{
    CB_ASSERT(NULL != pmngr);
    return (cb_bool)(pmngr->buflen == pmngr->datalen);    
}

/*******************************************************************************
** 函数: cb_empty
** 功能: 判断缓冲区是否为空
** 作者: avrbase_lei
*******/
static cb_bool cb_empty(CircleBufferMngr *pmngr)
{
    CB_ASSERT(NULL != pmngr);
    return (cb_bool)(0 == pmngr->datalen);    
}

const CircleBufferApi circleBufApi = {
    cb_init,
    cb_deinit,
    cb_info,
    cb_read,
    cb_write,
    cb_datalen,
    cb_full,
    cb_empty,
};
