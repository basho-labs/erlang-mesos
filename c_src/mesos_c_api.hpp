

#ifndef MESOS_API_C_H
#define MESOS_API_C_H

#include "erl_nif.h"

typedef void* CFrameworkInfo ;

typedef struct {
  void* data;
  size_t size;
} ProtobufObj;

typedef struct {
  void* scheduler;
  void* driver;
} SchedulerPtrPair;

typedef int SchedulerDriverStatus ;

struct state_t
{
	//ErlNifMutex*            lock;
    SchedulerPtrPair scheduler_state;
    //ErlNifThreadOpts*   scheduler_worker_thread_options;
    //ErlNifTid* scheduler_worker_thread; 
};

typedef struct state_t* state_ptr;

#ifdef __cplusplus
#include <mesos/mesos.hpp>
extern "C" {
#endif

 CFrameworkInfo newFrameworkInfo(ProtobufObj obj);
 CFrameworkInfo newCFrameworkInfo(char* name);
 void delCFrameworkInfo();

 SchedulerPtrPair scheduler_init( ErlNifPid *pid, CFrameworkInfo info, const char* master);
 SchedulerDriverStatus scheduler_start(SchedulerPtrPair state);
 SchedulerDriverStatus scheduler_join(SchedulerPtrPair state);
 SchedulerDriverStatus scheduler_abort(SchedulerPtrPair state);
#ifdef __cplusplus
}
#endif
#endif // MESOS_API_C_H
